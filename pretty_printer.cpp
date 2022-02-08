#include "pretty_printer.h"

void printBits(byte value) {
  for (int i = 7; i >= 0; i--) {
    bool b = bitRead(value, i);
    Serial.print(b);
  }
}
