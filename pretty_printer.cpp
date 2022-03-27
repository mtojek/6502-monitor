#include "pretty_printer.h"

void printBits(byte value) {
  for (int i = 7; i >= 0; i--) {
    bool b = bitRead(value, i);
    Serial.print(b);
  }
}

void printBuses(unsigned int address, byte data, byte readWrite) {
  char strBuffer[80];

  sprintf(strBuffer, "%04x %c %02x", address, readWrite ? 'R' : 'W', data);
  Serial.print(strBuffer);
}
