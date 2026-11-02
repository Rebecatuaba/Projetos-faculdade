// Código ESP32 com sensor PIR

#define PIR_PIN 14  

void setup() {
  pinMode(PIR_PIN, INPUT);
  Serial.begin(115200);
  Serial.println("Iniciando sensor PIR no ESP32...");
}

void loop() {
  int movimento = digitalRead(PIR_PIN);

  if (movimento == HIGH) {
    Serial.println("Movimento detectado!");
  } else {
    Serial.println("Nenhum Movimento detectado!");
  }

  delay(200); 
}
