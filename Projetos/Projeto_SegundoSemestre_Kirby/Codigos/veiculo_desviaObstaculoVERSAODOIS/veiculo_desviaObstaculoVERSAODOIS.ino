#include <AFMotor.h>
#include <NewPing.h>

// Sensor frente
#define trigF A3 // roxo
#define echoF A2 // branco

// Sensor direita
#define trigD A0 // amarelo
#define echoD A1 // azul

// Sensor esquerda
#define trigE A4 // verde
#define echoE A5 // marrom

#define MAX_DISTANCE 200
#define Speed 160 // velocidade dos motores

AF_DCMotor m1(2); // esquerda
AF_DCMotor m3(3); // direita

NewPing sonarF(trigF, echoF, MAX_DISTANCE);
NewPing sonarD(trigD, echoD, MAX_DISTANCE);
NewPing sonarE(trigE, echoE, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  m1.setSpeed(Speed);
  m3.setSpeed(Speed);
}

void loop() {
  int sensorD = sensor1(); // direita
  int sensorF = sensor2(); // frente
  int sensorE = sensor3(); // esquerda

  Serial.print("D: "); Serial.print(sensorD);
  Serial.print(" | F: "); Serial.print(sensorF);
  Serial.print(" | E: "); Serial.println(sensorE);


  // obstáculo FRENTE E ESQUERDA
  if (sensorF <= 10 && sensorD <= 15) { 
    Serial.println("Obstáculo à frente — analisando...");
    parar();
    delay(1000);
    esquerda();
  }

    // obstáculo FRENTE E DIREITA
  if (sensorF <= 10 && sensorE <= 15) { 
    Serial.println("Obstáculo à frente — analisando...");
    parar();
    delay(1000);
    direita();
  }


// cercado

    if (sensorD <= 12 && sensorE <= 12) {
      Serial.println("Sem saída lateral — dando ré");
      re();
      delay(1000);
      return;
    }

    // Virar para o lado com mais espaço
    if (sensorE > sensorD) {
      Serial.println("Mais espaço à esquerda — virando esquerda");
      esquerda();
      delay(1000);

    } else {
      Serial.println("Mais espaço à direita — virando direita");
      direita();
      delay(1000);
    }
    return;
  }

    // muito perto da direita
    if (sensorD <= 10) {
    Serial.println("Muito perto da direita — virando esquerda");
    esquerda(); 
    delay(1000);
    return;
  }

    //muito perto da esquerda
    if (sensorE <= 10) {
    Serial.println("Muito perto da esquerda — virando direita");
    direita();
    delay(1000);
    return;
  }

    //sem obstaculos - seguir em frente
    Serial.println("Caminho livre — indo em frente");
    frente();
    delay(1000);
  }

// ===== Funções dos sensores =====
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

// ===== Controle de motores =====
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

void re() {
  m1.run(BACKWARD);
  m3.run(BACKWARD);
}
