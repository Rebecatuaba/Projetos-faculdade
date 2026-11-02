#include <AFMotor.h>

const int pinEncoderA = A4; // Canal A do encoder
const int pinEncoderB = A5; // Canal B do encoder

long contador = 0;
int estadoAAnterior = LOW; // variável para armazenar o estado anterior do canal A

AF_DCMotor m1(1); // Motor M1 da Shield

void setup() {
  Serial.begin(9600);

  // Configura os pinos do encoder
  pinMode(pinEncoderA, INPUT_PULLUP);
  pinMode(pinEncoderB, INPUT_PULLUP);
  estadoAAnterior = digitalRead(pinEncoderA);

  // Configura o motor
  m1.setSpeed(200); // Velocidade de 0 a 255
  m1.run(FORWARD);  // Gira para frente
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
