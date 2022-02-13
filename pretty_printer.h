#ifndef PRETTY_PRINTER_H
#define PRETTY_PRINTER_H
#include <Arduino.h>

void printBits(byte value);
void printBuses(unsigned int address, byte data, byte readWrite);

#endif
