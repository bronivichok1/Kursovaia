#include <SD.h>
#include <EEPROM.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#include <SPI.h>

const int SSPin = PORTG2;
const byte READ = 0000000000000011;
const byte FDDR0 = 0;
const byte FDDR1 = 0;
const byte FDDR2 = 0;
const byte FDDR3 = 0;
const byte FDDR4 = 0;
const byte FDDR5 = 0;
const byte FDDR6 = 0;
const byte FDDR7 = 0;
const byte CDDR0 = 0;
const byte CDDR1 = 0;
const byte CDDR2 = 0;
const byte CDDR3 = 0;
const byte CDDR4 = 0;
const byte CDDR5 = 0;
const byte CDDR6 = 0;
const byte CDDR7 = 0;
const byte GDDR0 = 0;

void setup() {
Serial.begin(9600);
Serial.setTimeout(1000);

pinMode(SSPin, OUTPUT);
  SPI.begin(); 
  /*    DDRL = B11111111;
    DDRC = B00000000;
    DDRF = B00000000;
DDRG=B011;
*/
}

void loop() {
  SPISettings mySettings(100000, MSBFIRST, SPI_MODE0);
  SPI.beginTransaction(mySettings);
  digitalWrite(SSPin, LOW);
  SPI.transfer(READ);
  SPI.transfer(CDDR0);
  SPI.transfer(CDDR1);
  SPI.transfer(CDDR2);
  SPI.transfer(CDDR7);
  SPI.transfer(CDDR7);
  SPI.transfer(CDDR7);
  SPI.transfer(CDDR7);
  SPI.transfer(CDDR7);
  SPI.transfer(FDDR0); 
  SPI.transfer(FDDR1);
  SPI.transfer(FDDR2);
  SPI.transfer(FDDR3);
  SPI.transfer(FDDR4);
  SPI.transfer(FDDR5);
  SPI.transfer(FDDR6);
  SPI.transfer(FDDR7);
  SPI.transfer(GDDR0);
  for (int i=0; i<16; i++) {
    byte data = SPI.transfer(0);
    Serial.print((char)data);
  }
  Serial.println();
  digitalWrite(SSPin, HIGH);
  SPI.endTransaction();
  delay(1000); // повторяем чтение каждую секунду
/*    DDRL = B11111111;
    DDRC = B00000000;
    DDRF = B00000000;
DDRG=B011;
PORTG=B111;
PORTC=B11111111;
PORTF=B11111111;
int count = Serial.available();
Serial.print(PORTL,BIN);
delay(500);
*/


}
