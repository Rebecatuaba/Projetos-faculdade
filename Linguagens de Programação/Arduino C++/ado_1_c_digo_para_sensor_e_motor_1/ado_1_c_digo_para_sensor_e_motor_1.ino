#define trig 3
#define echo 2

// Motores 
#define motorE1 5
#define motorE2 6
#define motorD1 9
#define motorD2 10

long duracao;
int distancia;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(motorE1, OUTPUT);
  pinMode(motorE2, OUTPUT);
  pinMode(motorD1, OUTPUT);
  pinMode(motorD2, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  if (distancia > 15 || distancia <= 0) {
    frente();
    Serial.println("O Veiculo esta andando para Frente: ");
    distancia = Distsensor();
  	Serial.print("Distancia: ");
  	Serial.print(distancia);
  	Serial.println(" cm");
    delay(1000);
    
  } else {
    tras();
    Serial.println("O Veiculo esta andando para Tras: ");
    distancia = Distsensor();
  	Serial.print("Distancia: ");
  	Serial.print(distancia);
  	Serial.println(" cm");
    delay(1000);
  }
}

int Distsensor(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duracao = pulseIn(echo, HIGH, 30000); 
  int distancia = duracao * 0.034 / 2;
  return distancia;
}

void frente() {
  digitalWrite(motorE1, HIGH);
  digitalWrite(motorE2, LOW);
  digitalWrite(motorD1, HIGH);
  digitalWrite(motorD2, LOW);
}

void tras() {
  digitalWrite(motorE1, LOW);
  digitalWrite(motorE2, HIGH);
  digitalWrite(motorD1, LOW);
  digitalWrite(motorD2, HIGH);
}
