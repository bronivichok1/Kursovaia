#include <SPI.h>

const int SSPin = PORTG2;
const byte WREN = 0000000000000110;
const byte WRDI = 0000000000000100;
const byte READ = 0000000000000011;
const byte PP = 0000000000000010;
const byte SER = 0000000000100000;
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
  pinMode(SSPin, OUTPUT);
  SPI.begin();

  SPISettings mySet(100000, MSBFIRST, SPI_MODE0);
  
  // Выставление разрешения записи:
  SPI.beginTransaction(mySet);
  digitalWrite(SSPin, LOW);
  SPI.transfer(WREN);
  digitalWrite(SSPin, HIGH);
  SPI.endTransaction();

  // Очистка сектора:
  SPI.beginTransaction(mySet);
  digitalWrite(SSPin, LOW);
  SPI.transfer(SER);
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
  digitalWrite(SSPin, HIGH);
  SPI.endTransaction();
 
  // Выставление запрета записи:
  SPI.beginTransaction(mySet);
  digitalWrite(SSPin, LOW);
  SPI.transfer(WRDI);
  digitalWrite(SSPin, HIGH);
  SPI.endTransaction();
}

void loop() {
  // ничего не делаем в цикле
}
