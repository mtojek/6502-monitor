#ifndef INPUT_EXTENSION_H
#define INPUT_EXTENSION_H
#include <Arduino.h>

/* Library defines */

#define INPUT_EXTENSION_UC1 0
#define INPUT_EXTENSION_UC2 1
#define INPUT_EXTENSION_UC3 2

class InputExtension {
  private:
    // Pins A, B, C
    int a, b, c;
    // OUT and INH pins for UCn (n = 1,2,3)
    int firstOut, firstInh, secondOut, secondInh, thirdOut, thirdInh;
  public:
    InputExtension(int a, int b, int c, int firstOut, int firstInh, int secondOut, int secondInh, int thirdOut, int thirdInh);
    byte digitalReadExt(byte  uc);
};

#endif
