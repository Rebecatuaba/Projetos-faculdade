#include <Wire.h>

#define ADXL345 0x53

void setup() {
  Wire.begin();
  Serial.begin(9600);

  // Coloca o ADXL345 no modo de medição
  Wire.beginTransmission(ADXL345);
  Wire.write(0x2D);  // POWER_CTL
  Wire.write(0x08);  // Measurement Mode
  Wire.endTransmission();

  // Define faixa de medição para +/- 2g
  Wire.beginTransmission(ADXL345);
  Wire.write(0x31);  // DATA_FORMAT
  Wire.write(0x08);  // Full resolution, +/- 2g
  Wire.endTransmission();

  Serial.println("ADXL345 iniciado!");
}

void loop() {
  int16_t x, y, z;

  // Começa a leitura nos registradores de X
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32);
  Wire.endTransmission(false);

  Wire.requestFrom(ADXL345, 6);

  if (Wire.available() == 6) {
    x = Wire.read() | (Wire.read() << 8);
    y = Wire.read() | (Wire.read() << 8);
    z = Wire.read() | (Wire.read() << 8);

    // No modo +/-2g, cada unidade corresponde aproximadamente a 0,0039 g
    float Xg = x * 0.0039;
    float Yg = y * 0.0039;
    float Zg = z * 0.0039;

    Serial.print("X: ");
    Serial.print(Xg, 2);
    Serial.print(" g | Y: ");
    Serial.print(Yg, 2);
    Serial.print(" g | Z: ");
    Serial.print(Zg, 2);
    Serial.println(" g");
  }

  delay(500);
}