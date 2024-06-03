# IronManArc

## Prerequisite

### Needed librairies
- Timezone (Jack Christensen)
- Adafruit SSD1306
- Adafruit NeoPixel
- NTPClient

### Needed Board Manager
- esp32 (Espressif Systems) **version 2.0.17**

## Compile options
You can comment/uncomment following line in `IronManArc.ino` to specify if your Arc reactor uses standard or WS2812 LEDs for middle part.
```cpp
#define USE_BASIC_LEDS
```

## Compile/Upload

1. Select board **WEMOS D1 MINI ESP32**
2. Select right port
3. Click on the arrow to compile and upload


Convert image to CPP: https://diyusthad.com/image2cpp