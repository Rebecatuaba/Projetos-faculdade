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

#define MAX_DISTANCE 250
#define Speed 160 // velocidade dos motores

AF_DCMotor m1(2); // esquerda
AF_DCMotor m3(3); // direita

int speedLeft = 100;  // Velocidade motor esquerdo
int speedRight = 250;




NewPing sonarF(trigF, echoF, MAX_DISTANCE);
NewPing sonarD(trigD, echoD, MAX_DISTANCE);
NewPing sonarE(trigE, echoE, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
 m1.setSpeed(speedLeft);
m3.setSpeed(speedRight);
}

void loop() {
  int sensorD = sensor1(); // direita
  int sensorF = sensor2(); // frente
  int sensorE = sensor3(); // esquerda

  Serial.print("D: "); Serial.print(sensorD);
  Serial.print(" | F: "); Serial.print(sensorF);
  Serial.print(" | E: "); Serial.println(sensorE);

  if (sensorF <= 21 && sensorE <= 30) { 
    Serial.println("Obstáculo à frente — dando ré e indo para direita");
    re();
    delay(125);
    direita();


    if (sensorF <= 21 && sensorD <= 30) { 
    Serial.println("Obstáculo à frente — dando ré e virando para esquerda");
    re();
    delay(125);
    esquerda();
    }

    if (sensorE <= 30 && sensorD <= 30) {
    Serial.println("Obstáculo nas laterais — andando reto");
    frente();
    delay(125);
    return;
    }

    // robo cercado → ré
   if (sensorD <= 30 && sensorE <= 30 && sensorF <= 21) { 
      Serial.println("Sem saída — dando ré");
      re();
      delay(250);
      return;
    }

    // Virar para o lado com mais espaço
    if (sensorE > sensorD) {
      Serial.println("Mais espaço à esquerda — virando esquerda");
      esquerda();
      delay(125);

    } else {
      Serial.println("Mais espaço à direita — virando direita");
      direita();
      delay(125);
    }
    return;
  }

    // muito perto da direita
    if (sensorD <= 30) {
    Serial.println("Muito perto da direita — virando esquerda");
    esquerda(); 
    delay(125);
    return;
  }

    //muito perto da esquerda
    if (sensorE <= 30) {
    Serial.println("Muito perto da esquerda — virando direita");
    direita();
    delay(125);
    return;
  }

    //sem obstaculos - seguir em frente
    if (sensorD > 30 && sensorE && sensorF > 21) {
      Serial.println("Caminho livre — indo em frente");
      frente();
      delay(125);
   }

   if (sensorF <= 21) {
      Serial.println("Caminho frontal bloqueaedo — rezita");
      re();
      delay(125);
   }
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
