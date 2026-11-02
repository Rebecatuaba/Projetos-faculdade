#include <AFMotor.h> //inclui a biblioteca do Motor Shield

AF_DCMotor motor1(1); //define em quais portas do shield cada motor está ligado
AF_DCMotor motor2(3);

int vel = 250; //variavel para o controle da velocidade
int PinTrigger = A5; // Pino usado para disparar os pulsos do sensor
int PinEcho = A3; // pino usado para ler a saida do sensor
float TempoEcho = 0;
const float VelocidadeSom_mporus = 0.000340;


// Funçao para enviar o pulso de trigger
void DisparaPulsoUltrassonico(){
  digitalWrite(PinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(PinTrigger, LOW);
  }

// Função para calcular a distancia em metros
float CalculaDistancia(float tempo_us){
  return((tempo_us*VelocidadeSom_mporus)/2);
}

void setup() {
 pinMode(PinTrigger, OUTPUT); //configura o Trigger como saída
 digitalWrite(PinTrigger, LOW);
 pinMode(PinEcho, INPUT); // configura pino ECHO como entrada
 Serial.begin(9600);
}

void loop() {
 // Envia pulso para o disparar o sensor
 DisparaPulsoUltrassonico();
  
  // Mede o tempo de duração do sinal no pino de leitura(us)
 TempoEcho = pulseIn(PinEcho, HIGH);

delay(2000);
 if((CalculaDistancia(TempoEcho)*100) > 15){ // se a distância calculada em cm for maior que 15cm, o robô anda para frente
   motor1.run(FORWARD);
   motor2.run(FORWARD);
   motor1.setSpeed(vel);
   motor2.setSpeed(vel);
   Serial.println("Robo anda pra pra frente");
 }
 else if ((CalculaDistancia(TempoEcho)*100) <15) {                   //se a distância não for maior que 15cm, o robô vira para a direita
   motor1.run(FORWARD);
   motor2.run(BACKWARD);
   motor1.setSpeed(vel);
   motor2.setSpeed(vel);
   delay(300);
   Serial.println("Robo vira pra direita");
 }
Serial.println("distancia: "); 
Serial.println(CalculaDistancia(TempoEcho)*100);
delay(2000);
}
