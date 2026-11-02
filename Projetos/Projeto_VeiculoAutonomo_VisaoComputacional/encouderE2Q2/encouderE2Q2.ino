const int pinEncoderA = A4; // Canal A do encoder
const int pinEncoderB = A5; // Canal B do encoder

long contador = 0;
int estadoAAnterior = LOW; // variável para armazenar o estado anterior do canal A

void setup() {
  Serial.begin(9600);
  pinMode(pinEncoderA, INPUT_PULLUP);
  pinMode(pinEncoderB, INPUT_PULLUP);

  estadoAAnterior = digitalRead(pinEncoderA);
}

void loop() {
  int estadoAtual = digitalRead(pinEncoderA);

  // Detecta borda de subida do canal A
  if (estadoAAnterior == LOW && estadoAtual == HIGH) {
    if (digitalRead(pinEncoderB) == HIGH) {
      contador++;
    } else {
      contador--;
    }
  }

  estadoAAnterior = estadoAtual; // atualiza o estado anterior

  Serial.println(contador);
  delay(50); // Pequeno delay para não travar o monitor serial
}
