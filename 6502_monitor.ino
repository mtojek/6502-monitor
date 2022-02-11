#include "input_extension.h"
#include "pretty_printer.h"

/* Pin configuration */

#define PIN_CLOCK 2

#define PIN_A 3
#define PIN_B 4
#define PIN_C 5

#define PIN_FIRST_OUT A0
#define PIN_FIRST_INH A1
#define PIN_SECOND_OUT A2
#define PIN_SECOND_INH A3
#define PIN_THIRD_OUT A4
#define PIN_THIRD_INH A5

InputExtension inputExt(PIN_A, PIN_B, PIN_C,
                        PIN_FIRST_OUT, PIN_FIRST_INH,
                        PIN_SECOND_OUT, PIN_SECOND_INH,
                        PIN_THIRD_OUT, PIN_THIRD_INH);

void setup() {
  Serial.begin(9600);

  inputExt.setup();

  pinMode(PIN_CLOCK, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_CLOCK), onClock, CHANGE);
}



void onClock() {
  byte addrHi = inputExt.readPinsOrdered(INPUT_EXTENSION_UC1);
  byte addrLo = inputExt.readPinsOrdered(INPUT_EXTENSION_UC2);
  byte data = inputExt.readPinsOrdered(INPUT_EXTENSION_UC3);


  printBits(addrHi);
  Serial.print(' ');
  printBits(addrLo);
  Serial.print(' ');
  printBits(data);
  Serial.println();
}

void loop() {
}
