void setup() {
  pinMode(18, OUTPUT); // Define o pino 8 como saída
}

void loop() {
  digitalWrite(18, LOW); // Liga o relé (em módulos Low Level)
  delay(2000);          // Espera 2 segundos
  digitalWrite(18, HIGH); // Desliga o relé
  delay(2000);
}