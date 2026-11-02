#include <AFMotor.h>

//sensor frente
#define trigF A0
#define echoF A1

//sensor direita
#define trigD A2
#define echoD A3

//sensor esquerda
#define trigE A4
#define echoE A5

#define Speed 160 //velocidade dos motores

AF_DCMotor m1(1);//esquerda
AF_DCMotor m2(2);//direita

void setup() {
  Serial.begin(9600);
  pinMode (trigF, OUTPUT);
  pinMode (trigD, OUTPUT);
  pinMode (trigE, OUTPUT);
  pinMode (echoF, INPUT);
  pinMode (echoE, INPUT);
  pinMode (echoD, INPUT);

  m1.setSpeed(Speed);
  m2.setSpeed(Speed);
}

void loop() {
  int sensorD = sensor1();
  int sensorF = sensor2();
  int sensorE = sensor3();

  if (8 >= sensorF){
    parar();
    Serial.println("Pare");
    delay(1000);
    if (sensorE > sensorD){
      esquerda();
      Serial.println("Esquerda");
      delay(500);
    }else{
      direita();
      Serial.println("Direita");
      delay(500);
    }
  }
Serial.println("Frente");
frente();
}

//metodos que usamos no loop:
//pergar os valores dos sensores 
//sensor1 -> sensor direito
int sensor1(){
 digitalWrite(trigD, LOW);
 delayMicroseconds(4);
 digitalWrite(trigD, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigD, LOW);

 long t = pulseIn(echoD, HIGH);
 int cm = t / 29 / 2;
 return cm;
}

//sensor2 -> sensor frente
int sensor2(){
 digitalWrite(trigF, LOW);
 delayMicroseconds(4);
 digitalWrite(trigF, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigF, LOW);

 long t = pulseIn(echoF, HIGH);
 int cm = t / 29 / 2;
 return cm;
}

//sensor3 -> sensor esquerda
int sensor3(){
 digitalWrite(trigE, LOW);
 delayMicroseconds(4);
 digitalWrite(trigE, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigE, LOW);

 long t = pulseIn(echoE, HIGH);
 int cm = t / 29 / 2;
 return cm;
}

void frente(){
  m1.run(FORWARD);
  m2.run(FORWARD);
}

void esquerda(){
  m1.run(BACKWARD);
  m2.run(FORWARD);
}

void direita(){
  m1.run(FORWARD);
  m2.run(BACKWARD);
}

void parar(){
  m1.run(RELEASE);
  m2.run(RELEASE);
}
