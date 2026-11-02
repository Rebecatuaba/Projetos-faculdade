int motorPin1 = 11;
int motorPin2 = 10;

void setup()
{
  Serial.begin(9600);

 pinMode(motorPin1, OUTPUT);
 pinMode(motorPin2, OUTPUT);

  digitalWrite(motorPin1, 0); // Motor Deslig.
  digitalWrite(motorPin2, 0);
}

void loop(){
  char c = Serial.read();

  if (c == '1'){
    parar();
    esquerda();
  }
  if (c == '2'){
    parar();
    direita();
  }
  if(c == '3'){
    parar();
  }
}

void esquerda(){
 digitalWrite(motorPin1, 1);   // Motor para a esquerda
 digitalWrite(motorPin2, 0);   //
}
 
void direita(){
 digitalWrite(motorPin1, 0);   // Motor para a direita
 digitalWrite(motorPin2, 1);   //
}
 
void parar(){
 digitalWrite(motorPin1, 0);   // para o motor
 digitalWrite(motorPin2, 0);   //
}