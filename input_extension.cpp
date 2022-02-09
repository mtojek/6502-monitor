#include "input_extension.h"

static byte InputExtension::pinMap[] = {3, 0, 1, 2, 5, 7, 6, 4};

InputExtension::InputExtension(int a, int b, int c, int firstOut, int firstInh, int secondOut, int secondInh, int thirdOut, int thirdInh) {
  this->pinA = a;
  this->pinB = b;
  this->pinC = c;

  this->pinFirstOut = firstOut;
  this->pinFirstInh = firstInh;
  this->pinSecondOut = secondOut;
  this->pinSecondInh = secondInh;
  this->pinThirdOut = thirdOut;
  this->pinThirdInh = thirdInh;
}

void InputExtension::setup() {
  pinMode(this->pinA, OUTPUT);
  pinMode(this->pinB, OUTPUT);
  pinMode(this->pinC, OUTPUT);
  pinMode(this->pinFirstInh, OUTPUT);
  pinMode(this->pinFirstOut, INPUT);
  pinMode(this->pinSecondInh, OUTPUT);
  pinMode(this->pinSecondOut, INPUT);
  pinMode(this->pinThirdInh, OUTPUT);
  pinMode(this->pinThirdOut, INPUT);

  digitalWrite(this->pinFirstInh, HIGH);
  digitalWrite(this->pinSecondInh, HIGH);
  digitalWrite(this->pinThirdInh, HIGH);
}

byte InputExtension::readPinsOrdered(byte uc) {
  byte pins = this->readPins(uc);

  // Mapping bit numbers to match PCB order
  byte ordered = 0, value;
  for (int i = 0; i < 8; i++) {
    value = bitRead(pins, InputExtension::pinMap[i]);
    bitWrite(ordered, i, value);
  }
  return ordered;
}

byte InputExtension::readPins(byte uc) {
  int pinOut, pinInh;

  switch (uc) {
    case INPUT_EXTENSION_UC1:
      pinOut = this->pinFirstOut;
      pinInh = this->pinFirstInh;
      break;
    case INPUT_EXTENSION_UC2:
      pinOut = this->pinSecondOut;
      pinInh = this->pinSecondInh;
      break;
    case INPUT_EXTENSION_UC3:
      pinOut = this->pinThirdOut;
      pinInh = this->pinThirdInh;
      break;
    default:
      return 0;
  }

  return this->readSelectedPins(pinOut, pinInh);
}

byte InputExtension::readSelectedPins(int pinOut, int pinInh) {
  digitalWrite(pinInh, LOW);

  unsigned int a, b, c, out, state = 0;
  for (unsigned int i = 0; i < 8; i++) {
    state = state << 1;

    a = i % 2;
    b = (i / 2) % 2;
    c = (i / 4) % 2;

    digitalWrite(this->pinA, a);
    digitalWrite(this->pinB, b);
    digitalWrite(this->pinC, c);
    delay(10);
    out = digitalRead(pinOut);
    state += out;
  }

  digitalWrite(pinInh, HIGH);
  return state;
}
