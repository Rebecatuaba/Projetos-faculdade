// ===== BIBLIOTECAS =====
#include <WiFi.h>
#include <HTTPClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <time.h>

// ===== WIFI =====
const char* ssid = "ESP32_TEST_WLAN"; //ESP32_TEST_WLAN
const char* password = "Senac@1234"; //Senac@1234

// ===== GOOGLE SCRIPT =====
const char* googleScriptURL = "https://script.google.com/macros/s/AKfycbwaBRNQ4jev5CPodKXx_OezrCQ8roYxd3PLFiV3CVjPrRNaPpY8UYx9_Wnl75ADOjZC/exec";

// ===== CONTROLE DE ENVIO =====
unsigned long tempoUltimoEnvio = 0;
int intervaloEnvio = 5000;

// ===== SENSOR =====
#define PINO_SENSOR 23
OneWire oneWire(PINO_SENSOR);
DallasTemperature sensors(&oneWire);

// ===== TEMPERATURA =====
float temperaturaAtual = 0.0;
float temperaturaDesejada = 18.0;

// ===== TEMPO (FERMENTAÇÃO) =====
time_t tempoInicio;
bool iniciou = false;

void conectarWifi() {
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void enviarDadosGoogle(String timestamp_esp, float temperatura, float temperaturaDesejada, String status){

  if(WiFi.status() == WL_CONNECTED){

    if(millis() - tempoUltimoEnvio >= intervaloEnvio){

      HTTPClient http;

      timestamp_esp.replace(" ", "%20");

      String url = String(googleScriptURL) + "?";
      url += "timestamp_esp=" + timestamp_esp;
      url += "&temperatura=" + String(temperatura);
      url += "&temperatura_desejada=" + String(temperaturaDesejada);
      url += "&status=" + status;
      url += "&origem_do_dado=esp32";

      http.begin(url);
      int httpResponseCode = http.GET();

      Serial.println(httpResponseCode);

      http.end();

      tempoUltimoEnvio = millis();
    }
  }
}

void setup() {

  Serial.begin(115200);
  sensors.begin();
  conectarWifi();
  configTime(-3 * 3600, 0, "pool.ntp.org");

  struct tm timeinfo;
  while(!getLocalTime(&timeinfo)){
    delay(500);
  }

  tempoInicio = time(NULL);
  iniciou = true;

  }

void loop() {

  sensors.requestTemperatures();
  temperaturaAtual = sensors.getTempCByIndex(0);

  // TEMPO
  time_t agora = time(NULL);
  int diasPassados = (agora - tempoInicio) / 86400;

  // CONTROLE DE FASES
  if(diasPassados <= 10){
    temperaturaDesejada = 18.0;
  }
  else if(diasPassados <= 14){
    temperaturaDesejada = 20.0;
  }
  else{
    temperaturaDesejada = 10.0;
  }

  // STATUS
  String status = "normal";

  if(temperaturaAtual < temperaturaDesejada - 1){
    status = "baixa";
  }
  else if(temperaturaAtual > temperaturaDesejada + 1){
    status = "alta";
  }

  // HORA
  struct tm timeinfo;
  char horaFormatada[30];

  if(!getLocalTime(&timeinfo)){
    return;
  }

  strftime(horaFormatada, sizeof(horaFormatada), "%d/%m/%Y %H:%M:%S", &timeinfo);

  // ENVIO
  enviarDadosGoogle(
    String(horaFormatada),
    temperaturaAtual,
    temperaturaDesejada,
    status
  );

  delay(2000);
}
