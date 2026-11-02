#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h> 
#include <WiFi.h>
#include <HTTPClient.h>

#include <time.h>

// informações do wifi e ip
const char* ssid = "ESP32_TEST_WLAN"; //ESP32_TEST_WLAN
const char* password = "Senac@1234"; //Senac@1234

const char* googleScriptURL = "https://script.google.com/macros/s/AKfycbzrBQvH8eDB2Md7GLmaPld22TOLEsGu02TKtRWxqXPmnSR2VOpIJF7mifgIN8rbNk9-/exec";

unsigned long tempoUltimoEnvio = 0; // controle de envio
int intervaloEnvio = 5000; // 5 segundos

//Definindo pinos do sensor de temp
#define PINO_SENSOR 23 //Mudar se colocamos em outro pino

// BOTÕES
const int botaoAumenta = 14;  //NÃO USAR AS PORTAS 12 E 13
const int botaoDiminui = 13; 

//RELÉ
const int pinoRele = 18;

//
LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD I2C endereço 0x27
OneWire oneWire(PINO_SENSOR);         // Comunicação com sensor no pino 4
DallasTemperature sensors(&oneWire);  // Leitura da temperatura

// TEMPERATURAS
float temperaturaAtual = 0.0; // Sensor vai medir
float temperaturaDesejada = 65.0; // Temperatura ideal da CERVEJA
float temperaturaMinima = 60.0; //Limite inferior
float temperaturaMaxima = 76.0; //Limite superior

//Inércia Térmica(desligar 5°C antes, prof Wagner falou)
float inercia = 3.0; //mudamos pra 3º C
float temperaturaDesligar = temperaturaDesejada -inercia; // 65°C

//Estado do relé
bool releligado = false;

unsigned long tempoUltimoBotao = 0; // Guarda quando foi o último aperto
int debounceDelay = 100;
/*Explicação: Quando você aperta um botão uma vez, ele vibra e o ESP32
 pode entender que foi apertado várias vezes (tipo uns 10 apertos em 1 segundo).
 O debounce resolve isso fazendo o ESP32 esperar 200ms antes de ler o próximo aperto.

 Funciona assim: 
- Quando aperta, guarda o tempo (millis())
 - Só aceita o próximo aperto depois de 200ms
 Resultado: 1 aperto = 1 leitura */

void setup() {
  Serial.begin(115200);
  pinMode(botaoAumenta, INPUT_PULLUP);
  pinMode(botaoDiminui, INPUT_PULLUP);
  pinMode(pinoRele, OUTPUT);
  digitalWrite(pinoRele, LOW);
  
  sensors.begin();//Liga o sensor de temperatura e prepara ele para começar a medir. Sem ele, o sensor não funciona. É como apertar o botão "ligar" do sensor.
  Wire.begin(25, 32); 

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Sonic Boom Bar");
  lcd.setCursor(0,1); 
  lcd.print("Iniciando");
  delay(2000);
  lcd.clear();

  conectarWifi();
  configTime(-3 * 3600, 0, "pool.ntp.org"); //pegando a hora no Brasil
}

void loop() {
  sensors.requestTemperatures(); // Pede para o sensor medir
  temperaturaAtual = sensors.getTempCByIndex(0); //Pega a temperatura em °C

  String status = "normal"; // status temperatura para BD e deshborad 
  if(temperaturaAtual < temperaturaMinima){ 
    status = "baixa"; 
    } else if(temperaturaAtual > temperaturaMaxima){ 
      status = "alta"; 
      }

//Verificar se o sensor está funcionando
  if(temperaturaAtual == -127.0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ERRO SENSOR");
    lcd.setCursor(0,1);
    lcd.print("Verifique os fios");
    delay(1000);
    return;
  }

//Ler os botões(com debounce)
//Botão Aumentar
if(digitalRead(botaoAumenta) == LOW){
  if(millis() - tempoUltimoBotao > debounceDelay){
    temperaturaDesejada = temperaturaDesejada + 0.5;
    if(temperaturaDesejada > temperaturaMaxima){
      temperaturaDesejada = temperaturaMaxima;
    }
    temperaturaDesligar = temperaturaDesejada - inercia;
    tempoUltimoBotao = millis();
  }
}

//Botão Diminuir
if(digitalRead(botaoDiminui) == LOW){
  if(millis() - tempoUltimoBotao > debounceDelay){
    temperaturaDesejada = temperaturaDesejada - 0.5;
    if(temperaturaDesejada < temperaturaMinima){
      temperaturaDesejada = temperaturaMinima;
    }
    temperaturaDesligar = temperaturaDesejada - inercia;
    tempoUltimoBotao = millis();
  }
}
//Controlar o rele(con inércia térmica
if(temperaturaAtual < temperaturaDesligar){
  releligado = true;
  digitalWrite(pinoRele, HIGH);
}
else{
  releligado = false;
  digitalWrite(pinoRele, LOW);
}

lcd.clear();
//Temperatura Atual
lcd.setCursor(0,0);
lcd.print("Atual: ");
lcd.print(temperaturaAtual, 1);
lcd.print(" C");

//Temperatura Desejada
lcd.setCursor(0,1);
lcd.print("Desejada: ");
lcd.print(temperaturaDesejada, 1);
lcd.print(" C");

//Indicar se está aquecendo ou não
if(releligado){
  lcd.setCursor(13,1);
  lcd.print("AQ"); //AQUECENDO
}
else{
  lcd.setCursor(13,1);
  lcd.print("---"); //PARADO
}

struct tm timeinfo;
char horaFormatada[30];

if(!getLocalTime(&timeinfo)){
  Serial.println("Erro ao obter hora");
  return; // NÃO envia dados ruins
}

strftime(horaFormatada, sizeof(horaFormatada), "%d/%m/%Y %H:%M:%S", &timeinfo);

//eviando dados pro BD
  enviarDadosGoogle(String(horaFormatada), temperaturaAtual, temperaturaDesejada, temperaturaMinima, temperaturaMaxima, status, releligado);
  
delay(500);
}
