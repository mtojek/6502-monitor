#ifndef INPUT_EXTENSION_H
#define INPUT_EXTENSION_H
#include <Arduino.h>

#define INPUT_EXTENSION_UC1 0
#define INPUT_EXTENSION_UC2 1
#define INPUT_EXTENSION_UC3 2

class InputExtension {
  private:
    // Pin map representing real pin order on PCB
    static byte pinMap[];

    // Pins A, B, C
    int pinA, pinB, pinC;
    // OUT and INH pins for UCn (n = 1,2,3)
    int pinFirstOut, pinFirstInh, pinSecondOut, pinSecondInh, pinThirdOut, pinThirdInh;

    byte InputExtension::readSelectedPins(int outPin, int inhPin);
  public:
    InputExtension(int a, int b, int c, int firstOut, int firstInh, int secondOut, int secondInh, int thirdOut, int thirdInh);

    void setup();
    byte readPinsOrdered(byte uc);
    byte readPins(byte  uc);
};

#endif
