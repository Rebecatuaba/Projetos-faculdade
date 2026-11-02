#include <AFMotor.h>
#include <NewPing.h>

// Sensores
#define trigF A3
#define echoF A2

#define trigD A0
#define echoD A1

#define trigE A4
#define echoE A5

#define MAX_DISTANCE 250

AF_DCMotor m1(2);
AF_DCMotor m3(3);

int speedLeft = 76;
int speedRight = 180;

NewPing sonarF(trigF, echoF, MAX_DISTANCE);
NewPing sonarD(trigD, echoD, MAX_DISTANCE);
NewPing sonarE(trigE, echoE, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  m1.setSpeed(speedLeft);
  m3.setSpeed(speedRight);
}

// ================================================================
// LOOP PRINCIPAL: DANÇA + DESVIO DE OBSTÁCULOS
// ================================================================
void loop() {

  if (perigo()) {
    desviar();
    return;
  }

  dancaPasso1();
  if (perigo()) return;

  dancaPasso2();
  if (perigo()) return;

  gira180();
  if (perigo()) return;

  dancaPasso1();
  if (perigo()) return;

  dancaPasso2();
  if (perigo()) return;
}

// ================================================================
// FUNÇÃO DE DETECÇÃO DE PERIGO
// ================================================================
bool perigo() {
  int F = sensorF();
  int D = sensorD();
  int E = sensorE();

  return (F <= 18 || D <= 15 || E <= 15);
}

// ================================================================
// DANÇA
// ================================================================
void dancaPasso1() {
  Serial.println("Danca passo 1: balanco pra esquerda");
  esquerda();
  delay(200);
  frente();
  delay(150);
}

void dancaPasso2() {
  Serial.println("Danca passo 2: balanco pra direita");
  direita();
  delay(200);
  frente();
  delay(150);
}

void gira180() {
  Serial.println("Girando 180");
  // gira para esquerda mantendo m3 andando
  m1.run(RELEASE);
  m3.run(FORWARD);
  delay(600);  // ajuste se quiser girar mais ou menos
  parar();
  delay(150);
}

// ================================================================
// DESVIO DE OBSTÁCULOS DURANTE A DANÇA
// ================================================================
void desviar() {
  int F = sensorF();
  int D = sensorD();
  int E = sensorE();

  Serial.println("Obstaculo detectado durante a dança - ajustando rota...");

  if (F <= 18) {
    re();
    delay(200);
    parar();
    delay(80);

    if (E > D) esquerda();
    else direita();

    delay(220);
    return;
  }

  if (D <= 15) {
    esquerda();
    delay(200);
    return;
  }

  if (E <= 15) {
    direita();
    delay(200);
    return;
  }
}

// ================================================================
// SENSORES
// ================================================================
int sensorD() {
  int cm = sonarD.ping_cm();
  if (cm == 0) cm = MAX_DISTANCE;
  return cm;
}

int sensorF() {
  int cm = sonarF.ping_cm();
  if (cm == 0) cm = MAX_DISTANCE;
  return cm;
}

int sensorE() {
  int cm = sonarE.ping_cm();
  if (cm == 0) cm = MAX_DISTANCE;
  return cm;  
}

// ================================================================
// MOTORES
// ================================================================
void frente() {
  m1.run(FORWARD);
  m3.run(FORWARD);
}

void esquerda() {
  m1.run(RELEASE);
  m3.run(FORWARD);
}

void direita() {
  m1.run(FORWARD);
  m3.run(RELEASE);
}

void parar() {
  m1.run(RELEASE);
  m3.run(RELEASE);
}

void re() {
  m1.run(BACKWARD);
  m3.run(BACKWARD);
}
