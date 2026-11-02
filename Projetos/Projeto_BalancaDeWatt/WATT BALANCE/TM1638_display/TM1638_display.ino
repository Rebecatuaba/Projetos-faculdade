#include <TM1638.h>

// Letras em display de 7 segmentos
#define A 0b01110111
#define B 0b01111100
#define C 0b00111001
#define D 0b01011110
#define E 0b01111001
#define F 0b01110001
#define G 0b00111101
#define H 0b01110110
#define I 0b00000110
#define J 0b00011110
#define L 0b00111000
#define N 0b01010100
#define O 0b00111111
#define P 0b01110011
#define R 0b01010000
#define S 0b01101101
#define T 0b01111000
#define U 0b00111110
#define Y 0b01101110

const int stb = 9;
const int clk = 8; 
const int dio = 10;

TM1638 display(clk, dio, stb);

void setup() {
  Serial.begin(9600);

  // Limpa tudo
  display.reset();

  // Brilho máximo
  display.displaySetBrightness(PULSE14_16);

  //display para letras sem ser hexadecimal
  display.displayDig(3, O);
  display.displayDig(4, L);
  display.displayDig(5, L);
  display.displayDig(6, E);
  display.displayDig(7, H);

  // Display para numeros e letras hexadecimal
  /*display.displayVal(0, 0);
  display.displayVal(1, 25);
  display.displayVal(2, 1);
  display.displayVal(3, 7);
  display.displayVal(4, 0);
  display.displayVal(5, 21);
  display.displayVal(6, 14);
  display.displayVal(7, 19);*/

  // Acende os 8 LEDs
  display.writeLeds(0b11111111);

  Serial.println("TM1638 iniciado!");
  Serial.println("Displays: 12345678");
  Serial.println("LEDs: todos acesos");
  Serial.println("Pressione os botoes...");
}

void loop() {

  // Lê os 8 botões
  uint8_t botoes = display.getButtons();

  if (botoes != 0) {

    Serial.print("Botoes pressionados: ");

    for (int i = 0; i < 8; i++) {
      if (botoes & (1 << i)) {
        Serial.print("S");
        Serial.print(i + 1);
        Serial.print(" ");
      }
    }

    Serial.println();
  }

  delay(100);
}