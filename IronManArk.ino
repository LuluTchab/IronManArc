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
#include "NTPClient.h"
#include "WiFiManager.h"

// Wifi Configuration
#include "wifiConfig.h"

//========================USEFUL VARIABLES=============================
int UTC = 1; // UTC = value in hour (SUMMER TIME) [For example: Paris UTC+2 => UTC=2]




const long utcOffsetInSeconds = 3600; // UTC + 1H / Offset in second

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds*UTC);

// ==============================================================================

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


#define LOGO_HEIGHT   32
#define LOGO_WIDTH    128

// Digits et :
#define DIGIT_WIDTH 29
#define COLON_WIDTH 12

int hours, minutes, seconds, previousSeconds;
bool colonDisplayed;


void setup() {
  Serial.begin(115200);
  Serial.println("\n Starting");
  
  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  Serial.println("\nConnected!");

  timeClient.begin();

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Logo display
  displayStartupLogo();    


  // Init
  colonDisplayed=true;

}

void loop() 
{
  // Update the time
  timeClient.update();
  updateClock();
  delay(200);
  
}

// Prints Wifi networks
void printWifiNetworks()
{
  int numSsid = WiFi.scanNetworks();
  
  String ssid;
  uint8_t encryptionType;
  int32_t RSSI;
  uint8_t* BSSID;
  int32_t channel;

  Serial.printf("%d network(s) found\n", numSsid);
  for (int i = 0; i < numSsid; i++)
  {
    WiFi.getNetworkInfo(i, ssid, encryptionType, RSSI, BSSID, channel);
    Serial.printf("%d: %s, Ch:%d (%ddBm)\n", i + 1, ssid.c_str(), channel, RSSI);
  }
}

/*
  Display time from string ('hh:mm' or 'hh mm') using text functionality
*/
void displayTimeStr(String timeStr)
{
  for(int i=0; i < timeStr.length(); i++)
  {
    display.write(char(timeStr[i]));
  }
}


/*
  Display time from string ('hh:mm' or 'hh mm') using bitmaps
*/
void displayTimeImg(String timeStr)
{
  int nextCharOffset = 0;  // offset for next character to draw
  int curOffset; // x Offset to draw bitmaps
  char curChar; // current character to draw
  
  // Looping through characters composing time to display
  for(int i=0; i < timeStr.length(); i++)
  {
    curChar = timeStr[i];
    curOffset = nextCharOffset;
    
    // If we have to display char between hours and minutes
    if(curChar == ':' || curChar==' ')
    {
      nextCharOffset += COLON_WIDTH;
      display.drawBitmap(curOffset, 0, avengerColonOrNot[(curChar==' ')?0:1], COLON_WIDTH, SCREEN_HEIGHT, 1);
    }
    else // we have to display a digit
    {
      nextCharOffset += DIGIT_WIDTH;
      // Displaying digit by pointing on it in 'all digits bitmap array' by it index (corresponding to the number we have to display. number 0 => index 0 in array)
      display.drawBitmap(curOffset, 0, allAvengerDigits[String(timeStr[i]).toInt()], DIGIT_WIDTH, SCREEN_HEIGHT, 1);
    }
  }
}


void updateClock()
{
  hours = timeClient.getHours();
  minutes = timeClient.getMinutes();
  seconds = timeClient.getSeconds();

  // For colon anim between hours and minutes
  if(seconds != previousSeconds)
  {
    previousSeconds = seconds;
    colonDisplayed =! colonDisplayed;
  }

  String timeStr = "";
  if(hours<10) timeStr +="0";
  timeStr += String(hours);
  timeStr += (colonDisplayed)?":":" ";
  // Minutes
  if(minutes<10) timeStr +="0";
  timeStr += String(minutes);

  // Displaying time
  //displayTimeStr(timeStr);

  display.clearDisplay();
  displayTimeImg(timeStr);


  display.display();      // Show initial text

}

/*
  Displays startup logo
*/
void displayStartupLogo() {
  display.clearDisplay();

  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    starkIndustriesLogo, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(2000);
}

