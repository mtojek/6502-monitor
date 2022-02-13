# Monitor 6502 microprocessor with Arduino UNO R3 and custom input extension

This repository contains Kicad schematics and .ino source files to extend your Arduino UNO R3 with additional inputs. If you are following the Ben's Eater course to [build a 6502 computer](https://eater.net/6502), you will see that Ben operates on Arduino MEGA. Use schematics and source code from this repository to continue the Ben's course with Arduino UNO.

The 6502 monitor is programmed to observe address and data buses, and the read/write mode. For debugging and learning purposes, it's advised to use the external clock signal.

## Sample output

Check Arduino serial monitor to preview buses:

```
<address> <data> <address_hex> <Read/Write mode> <data_hex>
0000000110010110 00000000    0196 R 00
1111111111111100 00000000    fffc R 00
1111111111111101 00000000    fffd R 00
0000000000000000 00000000    0000 R 00
0000000000000001 00000000    0001 R 00
0000000110010101 00000000    0195 W 00
0000000110010100 00000010    0194 W 02
0000000110010011 00000110    0193 W 06
1111111111111110 00000000    fffe R 00
1111111111111111 00000000    ffff R 00
0011000000110000 00000000    3030 R 00
0011000000110001 00000000    3031 R 00
0011000000110010 00000000    3032 R 00
0011000000110011 00000000    3033 R 00
0011000000110100 00000000    3034 R 00
0011000000110101 00000000    3035 R 00
```

## Kicad preview

<p float="left">
  <img src="/screenshots/pcb-3d-viewer.png?raw=true" height="400px">
  <img src="/screenshots/pcb-layout.png?raw=true" height="400px">
</p>

## Photos

<p float="left">
  <img src="/photos/1.jpg?raw=true" width="333px">
  <img src="/photos/2.jpg?raw=true" width="333px">
  <img src="/photos/3.jpg?raw=true" width="333px">
</p>
