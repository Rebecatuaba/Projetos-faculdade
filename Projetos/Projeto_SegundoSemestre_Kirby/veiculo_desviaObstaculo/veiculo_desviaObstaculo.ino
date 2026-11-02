#include <AFMotor.h>
#include <NewPing.h>

//sensor frente
#define trigF A2 // roxo
#define echoF A3 //branco

//sensor direita
#define trigD A5 //amarelo
#define echoD A4 //azul

//sensor esquerda
#define trigE A1 // verde
#define echoE A0 // marrom

#define MAX_DISTANCE 200
#define Speed 160 //velocidade dos motores

AF_DCMotor m1(1);//esquerda
AF_DCMotor m3(3);//direita

NewPing sonarF(trigF, echoF, MAX_DISTANCE);
NewPing sonarD(trigD, echoD, MAX_DISTANCE);
NewPing sonarE(trigE, echoE, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  m1.setSpeed(Speed);
  m3.setSpeed(Speed);
}

void loop() {
  int sensorD = sensor1();
  int sensorF = sensor2();
  int sensorE = sensor3();

  if (sensorF <= 8) {
    parar();
    Serial.println("Pare");
    delay(1000);
    if (sensorE > sensorD) {
      esquerda();
      Serial.println("Esquerda");
      delay(500);
    } else {
      direita();
      Serial.println("Direita");
      delay(500);
    }
  }
  Serial.println("Frente");
  frente();
}

// Funções de sensores usando NewPing
int sensor1() { // direita
  int cm = sonarD.ping_cm();
  if (cm == 0) cm = MAX_DISTANCE;
  return cm;
}

int sensor2() { // frente
  int cm = sonarF.ping_cm();
  if (cm == 0) cm = MAX_DISTANCE;
  return cm;
}

int sensor3() { // esquerda
  int cm = sonarE.ping_cm();
  if (cm == 0) cm = MAX_DISTANCE;
  return cm;
}

// Controle de motores
void frente() {
  m1.run(FORWARD);
  m3.run(FORWARD);
}

void esquerda() {
  m1.run(BACKWARD);
  m3.run(FORWARD);
}

void direita() {
  m1.run(FORWARD);
  m3.run(BACKWARD);
}

void parar() {
  m1.run(RELEASE);
  m3.run(RELEASE);
}
