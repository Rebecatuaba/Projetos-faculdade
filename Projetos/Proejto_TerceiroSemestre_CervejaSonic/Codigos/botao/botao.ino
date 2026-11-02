int botao1 = 14;
//int botao2 = 32;

void setup() {
  pinMode(botao1, INPUT_PULLUP);
 // pinMode(botao2, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  if (digitalRead(botao1) == LOW) {
    Serial.println("Botao 1 pressionado");
  } else {
    Serial.println("Botao 1 solto");
  }
  /*if (digitalRead(botao2) == LOW) {
    Serial.println("Botao 2 pressionado");
  } else {
    Serial.println("Botao 2 solto");
  }*/

  delay(1000);
}