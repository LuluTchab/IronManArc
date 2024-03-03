/**************************************************************************

 **************************************************************************/
#include <typeinfo>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
// https://github.com/adafruit/Adafruit_SSD1306
#include <Adafruit_SSD1306.h>
#include "StartupLogo.h"
#include "NTPClient.h"
#include "WiFiManager.h"

// Wifi Configuration
#include "ArkConfigMenu.h"


// Define NTP Client to get time
WiFiUDP ntpUDP;
// https://github.com/arduino-libraries/NTPClient
NTPClient timeClient(ntpUDP, "pool.ntp.org");

// ==============================================================================

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 32  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define LOGO_HEIGHT 32
#define LOGO_WIDTH 128

// Digits et :
#define DIGIT_WIDTH 29
#define COLON_WIDTH 12

int previousSeconds;
bool colonDisplayed;

// Configuration menu
ArkConfigMenu configMenu;

void setup()
{
  Serial.begin(115200);

  // Init configuration menu
  configMenu.begin(WiFi, allFonts, timezoneList);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) 
  {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;)
      ;  // Don't proceed, loop forever
  }

  // Logo display
  displayStartupLogo();

  // If configuration is not valid
  if (!configMenu.isConfigFormatValid()) 
  {
    displayTextOnOLED("Invalid config\nUse Serial port\nhttps://t.ly/sFklh");
  }
  else  // Configuration is valid
  {

    WiFi.begin(configMenu.getWifiSSID(), configMenu.getWifiPassword());
    int nbMsLeftToTry = 3000;
    const int nbMsBetweenChecks = 500;

    // We try to connect for a nbMsLeftToTry milliseconds
    while((WiFi.status() != WL_CONNECTED) && (nbMsLeftToTry > 0))
    {
      delay(nbMsBetweenChecks);
      nbMsLeftToTry -= nbMsBetweenChecks;
    }

    // If we were able to connect on Wifi
    if(nbMsLeftToTry > 0)
    {
      timeClient.begin();
    }
    else
    {
      displayTextOnOLED("Wifi connect error\nUse Serial port\nhttps://t.ly/sFklh");
    }
  }

  // Init
  colonDisplayed = true;
}

void loop() 
{

  short actionToDo = configMenu.handleInput();

  // If wifi is connected
  if(WiFi.status() == WL_CONNECTED) 
  {
    // Update the time
    timeClient.update();

    updateOLEDClockDisplay();

    delay(200);
  }
}


// Update clock display on OLED
void updateOLEDClockDisplay() 
{
  char timeStr[5];
  // Get time in current defined timezone
  time_t currentTime = configMenu.getTimezoneInfos().timezone.toLocal(timeClient.getEpochTime());

  int nextCharOffset = 0;  // offset for next character to draw
  int curOffset;           // x Offset to draw bitmaps
  char curChar;            // current character to draw

  // For colon anim between hours and minutes
  if(second(currentTime) != previousSeconds) 
  {
    previousSeconds = second(currentTime);
    if(configMenu.doesColonHaveToBlink()) 
    {
      colonDisplayed = !colonDisplayed;
    }
    else 
    {
      // We do this in case of option is changed while colon is hidden, to make it appears again and stay
      colonDisplayed = true;
    }
  }
  // defining string to display
  sprintf(timeStr, "%.2d%s%.2d", hour(currentTime), ((colonDisplayed) ? ":" : " "), minute(currentTime));

  // Displaying time
  display.clearDisplay();
  
  // Looping through characters composing time to display
  for(int i = 0; i < 5; i++) 
  {
    curChar = timeStr[i];
    curOffset = nextCharOffset;

    // If we have to display char between hours and minutes
    if(curChar == ':' || curChar == ' ') 
    {
      nextCharOffset += COLON_WIDTH;
      display.drawBitmap(curOffset, 0, configMenu.getFontInfos().colonOrNot[(curChar == ' ') ? withoutColon : withColon], COLON_WIDTH, SCREEN_HEIGHT, 1);
    } 
    else  // we have to display a digit
    {
      nextCharOffset += DIGIT_WIDTH;
      // Displaying digit by pointing on it in 'all digits bitmap array' by it index (corresponding to the number we have to display. number 0 => index 0 in array)
      //display.drawBitmap(curOffset, 0, allAvengerDigits[String(timeStr[i]).toInt()], DIGIT_WIDTH, SCREEN_HEIGHT, 1);
      display.drawBitmap(curOffset, 0, configMenu.getFontInfos().allDigits[String(timeStr[i]).toInt()], DIGIT_WIDTH, SCREEN_HEIGHT, 1);
      
    }
  }

  display.display();
}

/*
  Displays startup logo
*/
void displayStartupLogo() 
{
  display.clearDisplay();

  display.drawBitmap(
    (display.width() - LOGO_WIDTH) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    starkIndustriesLogo, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(2000);
}


/*
  Displays given text on OLED screen
*/
void displayTextOnOLED(String text) 
{
  display.clearDisplay();
  display.setTextSize(1);               // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);  // Draw white text
  display.setCursor(0, 0);              // Start at top-left corner
  for (int i = 0; i < text.length(); i++) 
  {
    display.write(char(text[i]));
  }
  display.display();  // Show initial text
}

