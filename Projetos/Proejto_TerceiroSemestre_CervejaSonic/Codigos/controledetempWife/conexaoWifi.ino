#include <WiFi.h>
#include <HTTPClient.h>

#include <time.h>

extern const char* ssid;
extern const char* password;
extern const char* googleScriptURL;

extern unsigned long tempoUltimoEnvio;
extern int intervaloEnvio;


void conectarWifi() {

  WiFi.begin(ssid, password);

  Serial.print("Conectando ao WiFi");

  unsigned long start = millis();

  while (WiFi.status() != WL_CONNECTED && millis() - start < 10000) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi conectado!");
  } else {
    Serial.println("\nFalha ao conectar no WiFi");
  }
}

void enviarDadosGoogle(String hora_esp, float temperatura, float temperaturaDesejada, float temperaturaMinima, float temperaturaMaxima, String status, bool rele){
  
   // RECONEXÃO AUTOMÁTICA DO WIFI 
  if(WiFi.status() != WL_CONNECTED){
    WiFi.begin(ssid, password);
  }
  // Envio de dados para o servidor/BD
  if(WiFi.status() == WL_CONNECTED){// se estiver conectado a internet faça...

    // CONTROLE DE TEMPO DE ENVIO
  if(millis() - tempoUltimoEnvio >= intervaloEnvio){
    HTTPClient http; // Cria uma ferramenta pra fazer requisições HTTP (tipo navegador)

    hora_esp.replace(" ", "%20"); 
    String url = String(googleScriptURL) + "?hora_esp=" + hora_esp;
    url += "&temperatura=" + String(temperatura);
    url += "&temperatura_desejada=" + String(temperaturaDesejada);
    url += "&temperatura_min=" + String(temperaturaMinima);
    url += "&temperatura_max=" + String(temperaturaMaxima);
    url += "&status=" + status;
    url += "&rele=" + String(rele);
    url += "&origem_do_dado=esp32";


    http.begin(url); // AGORA SIM correto
    int httpResponseCode = http.GET(); //esta pegando 
    Serial.print("HTTP Response: ");
    Serial.println(httpResponseCode);

    http.end();

    tempoUltimoEnvio = millis(); // atualiza tempo
  }
  }

}