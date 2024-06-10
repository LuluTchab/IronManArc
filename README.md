# IronManArc

## Prerequisite
Here are the librairies dans board manager needed to compile the project. Note that recommanded working versions were put. More recent version could work but without any guarantee.

### Needed librairies
- [Timezone (Jack Christensen)](https://github.com/JChristensen/Timezone) **version 1.2.4**
- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306) **version 2.5.10**
- [Adafruit NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) **version 1.12.2**
- [NTPClient](https://github.com/arduino-libraries/NTPClient) **version 3.2.1**

### Needed Board Manager
- [esp32 (Espressif Systems)](https://github.com/espressif/arduino-esp32) **version 2.0.15**

## Compile options
You can comment/uncomment following line in `IronManArc.ino` to specify if your Arc reactor uses standard or WS2812 LEDs for middle part.
```cpp
#define USE_BASIC_LEDS
```

## Compile/Upload

1. Select board **WEMOS D1 MINI ESP32**
2. Select right port
3. Click on the arrow to compile and upload


# Add your own font to display time
Convert image to CPP: https://diyusthad.com/image2cpp