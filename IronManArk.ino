/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x32 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "StartupLogo.h"
#include "AvengersDigits.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

// Logo de démarrage
#define LOGO_HEIGHT   32
#define LOGO_WIDTH    128

// Digits et :
#define DIGIT_WIDTH 29
#define COLON_WIDTH 12

int hour, minute, second;
bool colonDisplayed;


void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }


  startupLogo();    // Draw a small bitmap image



  colonDisplayed=true;
  hour = 21;
  minute = 35;
  second = 45;

}

void loop() 
{
  displayTime();
  delay(1000);
  
  second++;
  if(second==60)
  {
    second=0;
    minute++;
    if(minute==60)
    {
      minute=0;
      hour++;
      if(hour==24)
      {
        hour=0;
      }
    }
  }
  colonDisplayed=!colonDisplayed;
}


void displayTimeStr(String timeStr)
{
  for(int i=0; i < timeStr.length(); i++)
  {
    display.write(char(timeStr[i]));
  }
}

void displayTimeImg(String timeStr)
{
  int xOffset = 0;
  int curOffset;
  
  for(int i=0; i < timeStr.length(); i++)
  {
    curOffset = xOffset;
    
    xOffset += (timeStr[i] == ':' || timeStr[i]==' ')? COLON_WIDTH : DIGIT_WIDTH;
    
    switch(timeStr[i])
    {
      case ':'  : { display.drawBitmap(curOffset, 0, digit_colon, COLON_WIDTH, SCREEN_HEIGHT, 1);     break; }
      case ' '  : { display.drawBitmap(curOffset, 0, digit_no_colon, COLON_WIDTH, SCREEN_HEIGHT, 1);  break; }
      case '1'  : { display.drawBitmap(curOffset, 0, digit_1, DIGIT_WIDTH, SCREEN_HEIGHT, 1);         break; }
      case '2'  : { display.drawBitmap(curOffset, 0, digit_2, DIGIT_WIDTH, SCREEN_HEIGHT, 1);         break; }
      case '3'  : { display.drawBitmap(curOffset, 0, digit_3, DIGIT_WIDTH, SCREEN_HEIGHT, 1);         break; }
      case '4'  : { display.drawBitmap(curOffset, 0, digit_4, DIGIT_WIDTH, SCREEN_HEIGHT, 1);         break; }
      case '5'  : { display.drawBitmap(curOffset, 0, digit_5, DIGIT_WIDTH, SCREEN_HEIGHT, 1);         break; }
      case '6'  : { display.drawBitmap(curOffset, 0, digit_6, DIGIT_WIDTH, SCREEN_HEIGHT, 1);         break; }
      case '7'  : { display.drawBitmap(curOffset, 0, digit_7, DIGIT_WIDTH, SCREEN_HEIGHT, 1);         break; }
      case '8'  : { display.drawBitmap(curOffset, 0, digit_8, DIGIT_WIDTH, SCREEN_HEIGHT, 1);         break; }
      case '9'  : { display.drawBitmap(curOffset, 0, digit_9, DIGIT_WIDTH, SCREEN_HEIGHT, 1);         break; }
      case '0'  : { display.drawBitmap(curOffset, 0, digit_0, DIGIT_WIDTH, SCREEN_HEIGHT, 1);         break; }

    }

    //display.drawBitmap(curOffset, 0, bitmap, bitmapWidth, SCREEN_HEIGHT, 1);
  }
}

void displayTime()
{
  display.clearDisplay(); // Clear display buffer
  display.setTextSize(4); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  
  String timeStr = "";
  if(hour<10) timeStr +="0";
  timeStr += String(hour);
  timeStr += (colonDisplayed)?":":" ";
  // Minutes
  if(minute<10) timeStr +="0";
  timeStr += String(minute);

  // Affichage des digits
  //displayTimeStr(timeStr);
  displayTimeImg(timeStr);


  display.display();      // Show initial text

  // -- Serial
  Serial.print(timeStr);
  Serial.print(" ");
  Serial.println(second);
}


void startupLogo(void) {
  display.clearDisplay();

  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    starkIndustriesLogo, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(2000);
}

