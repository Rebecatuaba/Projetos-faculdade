#include <AFMotor.h>
#include <NewPing.h>

#define trigF A3
#define echoF A2

#define trigD A0
#define echoD A1

#define trigE A4
#define echoE A5

#define MAX_DISTANCE 250
#define SPEED_LEFT 100
#define SPEED_RIGHT 250

AF_DCMotor m1(2)
AF_DCMotor m3(3)

NewPing sonarF(trigF, echoF, MAX_DISTANCE)
NewPing sonarD(trigD, echoD, MAX_DISTANCE)
NewPing sonarE(trigE, echoE, MAX_DISTANCE)

int lastF = 100
int lastD = 100
int lastE = 100

unsigned long lastTurnTime = 0
const unsigned long turnCooldown = 200 // evita viradas duplas que causam meia volta

int leituraSegura(NewPing &sensor, int lastValue) {
int cm = sensor.ping_cm()
if (cm == 0) {
cm = sensor.ping_cm()
if (cm == 0) cm = lastValue
}
if (cm > MAX_DISTANCE) cm = MAX_DISTANCE
return cm
}

int filtraHisterese(int atual, int anterior) {
int dif = atual - anterior
if (dif > 40) return anterior + 20
if (dif < -40) return anterior - 20
return atual
}

void setup() {
Serial.begin(9600)
m1.setSpeed(SPEED_LEFT)
m3.setSpeed(SPEED_RIGHT)
}

void loop() {
int sensorF = leituraSegura(sonarF, lastF)
int sensorD = leituraSegura(sonarD, lastD)
int sensorE = leituraSegura(sonarE, lastE)

sensorF = filtraHisterese(sensorF, lastF)
sensorD = filtraHisterese(sensorD, lastD)
sensorE = filtraHisterese(sensorE, lastE)

lastF = sensorF
lastD = sensorD
lastE = sensorE

Serial.print("D: ")
Serial.print(sensorD)
Serial.print(" F: ")
Serial.print(sensorF)
Serial.print(" E: ")
Serial.println(sensorE)

if (sensorF > 120 && sensorD < 15 && sensorE < 15) {
sensorF = 10
}

if (sensorF < 12 && sensorD < 12 && sensorE < 12) {
re()
delay(250)
return
}

if (sensorF < 12) {
unsigned long t = millis()
re()
delay(150)
if (t - lastTurnTime > turnCooldown) {
if (sensorE > sensorD) esquerda()
else direita()
delay(180)
lastTurnTime = millis()
}
return
}

if (sensorD < 10) {
unsigned long t = millis()
if (t - lastTurnTime > turnCooldown) {
esquerda()
delay(130)
lastTurnTime = millis()
}
return
}

if (sensorE < 10) {
unsigned long t = millis()
if (t - lastTurnTime > turnCooldown) {
direita()
delay(130)
lastTurnTime = millis()
}
return
}

if (sensorF > 15 && sensorD > 12 && sensorE > 12) {
frente()
return
}

frente()
}

void frente() {
m1.run(FORWARD)
m3.run(FORWARD)
}

void esquerda() {
m1.run(RELEASE)
m3.run(FORWARD)
}

void direita() {
m1.run(FORWARD)
m3.run(RELEASE)
}

void re() {
m1.run(BACKWARD)
m3.run(BACKWARD)
}

void parar() {
m1.run(RELEASE)
m3.run(RELEASE)
}