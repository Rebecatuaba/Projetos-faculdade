#include <Adafruit_BMP280.h>
#include <LittleFS.h>
#include <Wire.h>

// ========== PINOS ==========
#define BUZZER 25
// SERVO_PIN removido: não há mais separação de estágio nem
// acionamento de paraquedas pelo ESP32 (ejeção agora é mecânica/independente)

// ========== MELODIA (Super Mario) ==========
int notas[] = {
  660, 660, 0, 660, 0, 520, 660, 0,
  784, 0, 392, 0
};
int duracoes[] = {
  150, 150, 150, 150, 150, 150, 150, 150,
  300, 300, 300, 300
};

// ========== OBJETOS ==========
Adafruit_BMP280 bmp;
File arquivo;

// ========== VARIÁVEIS DE VOO ==========
float pressaoReferencia = 1013.25;   // será atualizada no setup com a pressão real
float altitudeBase = 0;
float altitudeAtual = 0;
float altitudeAnterior = 0;
float altitudeMaxima = 0;
int contadorQueda = 0;
const int QUEDAS_PARA_APOGEU = 3;
const float DELTA_APOGEU = 1.0;       // 1 metro de queda para considerar
bool apogeuDetectado = false;
bool pousou = false;
unsigned long tempoInicio = 0;
int numeroVoo = 0;                    // para gerar nome único do arquivo

// ========== DETECÇÃO DE DECOLAGEM ==========
// Serve para marcar no CSV onde termina a espera (chave ligada, foguete
// ainda na base) e começa o voo de fato (depois de puxar a cordinha).
bool decolagemDetectada = false;
int contadorSubida = 0;
const int SUBIDAS_PARA_DECOLAGEM = 3;     // leituras seguidas confirmando subida
const float DELTA_DECOLAGEM = 1.5;        // metros de subida em relação à base para considerar decolagem

// ========== FUNÇÃO PARA TOCAR MELODIA ==========
void tocarMelodia() {
  int totalNotas = sizeof(notas) / sizeof(notas[0]);
  for (int i = 0; i < totalNotas; i++) {
    if (notas[i] == 0) {
      noTone(BUZZER);
    } else {
      tone(BUZZER, notas[i], duracoes[i]);
    }
    delay(duracoes[i] + 30);
    noTone(BUZZER);
  }
}

// ========== SETUP ==========
void setup() {
  Serial.begin(115200);
  delay(3000);

  pinMode(BUZZER, OUTPUT);
  // Servo removido: nada para anexar/posicionar aqui

  Wire.begin(21, 22);

  // Inicializa BMP280
  Serial.println("Iniciando BMP280...");
  if (!bmp.begin(0x77)) {
    Serial.println("BMP280 NAO encontrado! Verifique a ligacao.");
    while (1);
  }
  Serial.println("BMP280 OK!");

  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                  Adafruit_BMP280::SAMPLING_X1,
                  Adafruit_BMP280::SAMPLING_X1,
                  Adafruit_BMP280::FILTER_OFF,
                  Adafruit_BMP280::STANDBY_MS_500);

  // Inicializa LittleFS
  if (!LittleFS.begin(true)) {
    Serial.println("Erro ao iniciar LittleFS!");
    while (1);
  }
  Serial.println("LittleFS OK!");

  // Gera nome único para o arquivo (voo_0.csv, voo_1.csv, ...)
  // Lê o último número usado de um arquivo de controle
  File controle = LittleFS.open("/contador.txt", "r");
  if (controle) {
    numeroVoo = controle.parseInt();
    controle.close();
  }
  numeroVoo++;
  controle = LittleFS.open("/contador.txt", "w");
  if (controle) {
    controle.println(numeroVoo);
    controle.close();
  }

  String nomeArquivo = "/voo_" + String(numeroVoo) + ".csv";
  arquivo = LittleFS.open(nomeArquivo.c_str(), "w");
  if (arquivo) {
    arquivo.println("tempo_ms,altitude_m,temperatura_c,pressao_hpa,status");
    Serial.print("Arquivo criado: ");
    Serial.println(nomeArquivo);
  } else {
    Serial.println("Erro ao criar arquivo de log!");
  }

  // ===== CALIBRAÇÃO USANDO PRESSÃO REAL =====
  Serial.println("Calibrando altitude do solo...");
  delay(2000);

  // 1) Mede a pressão ambiente real (média de 10 leituras)
  float somaPressao = 0;
  for (int i = 0; i < 10; i++) {
    somaPressao += bmp.readPressure() / 100.0F;
    delay(100);
  }
  pressaoReferencia = somaPressao / 10.0;
  Serial.print("Pressão de referência (hPa): ");
  Serial.println(pressaoReferencia);

  // 2) Calcula a altitude base (altitude do solo) usando essa pressão real
  float somaBase = 0;
  for (int i = 0; i < 10; i++) {
    somaBase += bmp.readAltitude(pressaoReferencia);
    delay(100);
  }
  altitudeBase = somaBase / 10.0;
  altitudeAnterior = 0;
  altitudeMaxima = 0;
  Serial.print("Altitude base (m): ");
  Serial.println(altitudeBase);

  // Sinal sonoro de pronto
  tone(BUZZER, 1000, 300);
  delay(500);
  tone(BUZZER, 1000, 300);

  Serial.println("Sistema pronto! Aguardando lancamento...");
  tempoInicio = millis();
}

// ========== LOOP PRINCIPAL ==========
void loop() {
  if (pousou) return;  // já pousou, não faz mais nada

  // --- LEITURA DO SENSOR COM VERIFICAÇÃO DE ERRO ---
  float pressao = bmp.readPressure() / 100.0F;   // hPa
  float temperatura = bmp.readTemperature();     // °C
  float rawAltitude = bmp.readAltitude(pressaoReferencia);  // altitude absoluta

  // Se qualquer leitura for inválida, pula este ciclo
  if (isnan(rawAltitude) || isnan(temperatura) || isnan(pressao)) {
    Serial.println("ERRO: Leitura inválida do sensor! Ignorando...");
    delay(100);
    return;
  }

  altitudeAtual = rawAltitude - altitudeBase;   // altitude relativa ao solo
  unsigned long tempoAtual = millis() - tempoInicio;

  // Suavização com média móvel simples (filtro de 2 pontos)
  float mediaAtual = (altitudeAtual + altitudeAnterior) / 2.0;

  // --- DETECÇÃO DE DECOLAGEM ---
  // Enquanto o foguete está parado na base (chave ligada, aguardando a
  // cordinha), a altitude fica oscilando perto de 0. Quando subir de forma
  // consistente, marcamos a decolagem para diferenciar "espera" de "voo".
  if (!decolagemDetectada) {
    if (mediaAtual > DELTA_DECOLAGEM) {
      contadorSubida++;
      if (contadorSubida >= SUBIDAS_PARA_DECOLAGEM) {
        decolagemDetectada = true;
        Serial.println("DECOLAGEM DETECTADA!");
        tone(BUZZER, 1500, 200);   // bipe curto avisando que o voo começou
      }
    } else {
      contadorSubida = 0;   // reset se foi só ruído, não subida real
    }
  }

  // --- DEFINE O STATUS DESTA LINHA PARA O CSV ---
  String status;
  if (pousou) {
    status = "POUSO";
  } else if (apogeuDetectado) {
    status = "VOO";
  } else if (decolagemDetectada && contadorSubida == SUBIDAS_PARA_DECOLAGEM) {
    status = "DECOLAGEM";   // marca só a linha exata em que foi confirmada
  } else if (decolagemDetectada) {
    status = "VOO";
  } else {
    status = "AGUARDANDO";  // ainda na base, esperando a cordinha
  }

  // --- SALVA DADOS NO ARQUIVO (COM FLUSH) ---
  if (arquivo) {
    arquivo.print(tempoAtual);    arquivo.print(",");
    arquivo.print(altitudeAtual); arquivo.print(",");
    arquivo.print(temperatura);   arquivo.print(",");
    arquivo.print(pressao);       arquivo.print(",");
    arquivo.println(status);
    arquivo.flush();   // grava fisicamente no flash a cada leitura
  }

  // --- MONITOR SERIAL (DEBUG) ---
  Serial.print("Tempo: ");      Serial.print(tempoAtual);
  Serial.print(" ms | Alt: ");  Serial.print(altitudeAtual);
  Serial.print(" m | Temp: ");  Serial.print(temperatura);
  Serial.print(" °C | Pressão: "); Serial.println(pressao);

  // --- DETECÇÃO DE APOGEU (robusta) ---
  if (mediaAtual > altitudeMaxima) altitudeMaxima = mediaAtual;

  if (!apogeuDetectado) {
    if (mediaAtual < altitudeMaxima - DELTA_APOGEU) {
      contadorQueda++;
      if (contadorQueda >= QUEDAS_PARA_APOGEU) {
        apogeuDetectado = true;
        Serial.println("APOGEU DETECTADO!");
        // Servo removido: a ejeção do paraquedas agora é mecânica/independente
        // do ESP32. Aqui só registramos o evento e damos o bipe sonoro.
        tone(BUZZER, 2000, 500);       // bipe de confirmação
      }
    } else {
      contadorQueda = 0;   // reset se ainda não caiu de fato
    }
  }

  altitudeAnterior = mediaAtual;

  // --- DETECÇÃO DE POUSO ---
  if (apogeuDetectado && altitudeAtual < 1.0) {
    pousou = true;
    unsigned long tempoTotal = millis() - tempoInicio;
    float tempoSegundos = tempoTotal / 1000.0;
    Serial.print("Tempo total de voo: ");
    Serial.print(tempoSegundos);
    Serial.println(" segundos");

    // Registra o tempo total de voo no arquivo
    if (arquivo) {
      arquivo.print("Tempo total de voo (s):,");
      arquivo.println(tempoSegundos);
      arquivo.close();   // fecha o arquivo definitivamente
    }

    tocarMelodia();   // comemora com o Mario
  }

  delay(100);   // 10 Hz – suficiente para foguetes de pequeno porte
}
