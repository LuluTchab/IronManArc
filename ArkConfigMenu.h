#ifndef ArkConfigMenu_h
#define ArkConfigMenu_h

// https://iotcircuithub.com/esp32-preferences-library-tutorial/
#include <Preferences.h>
#include "Arduino.h"
// https://github.com/arduino-libraries/WiFi/tree/master
#include "WiFi.h"

#include "Fonts.h"
#include "TimezoneDef.h"


#define ARK_CONFIG_VERSION 2

// Root menu
#define ROOT_MENU_SIZE 3
#define ROOT_MENU_INDEX__WIFI_CONFIG 0
#define ROOT_MENU_INDEX__TIME_CONFIG 1
#define ROOT_MENU_INDEX__FONT_CONFIG 2

// Sub menus
#define SUB_MENU_SIZE__WIFI 4
#define SUB_MENU_SIZE__TIME 3
#define SUB_MENU_SIZE__FONT 4
#define SUB_MENU__BACK 0
// Wifi Config
#define SUB_MENU__WIFI_CONFIG__VIEW 1
#define SUB_MENU__WIFI_CONFIG__LIST_NETWORKS 2
#define SUB_MENU__WIFI_CONFIG__SET 3
// Time Config
#define SUB_MENU__TIME_CONFIG__VIEW 11
#define SUB_MENU__TIME_CONFIG__SET 12
// Font Config
#define SUB_MENU__FONT_CONFIG__VIEW 21
#define SUB_MENU__FONT_CONFIG__TOGGLE_BLINK 22
#define SUB_MENU__FONT_CONFIG__SET_FONT 23


#define INT_UNINITIALIZED -1
#define STRING_UNINITIALIZED "?no value?"

#define INPUT_PROMPT__CHOICE "Choice"

// Types for user inputs
#define EXPECTED_INPUT_TYPE_PROMPT__STRING '>'
#define EXPECTED_INPUT_TYPE_PROMPT__PASSWORD '*'
#define EXPECTED_INPUT_TYPE_PROMPT__INT '#'
#define EXPECTED_INPUT_TYPE_PROMPT__BOOL '&'

// Identifiers for preferences. Max 15 chars
#define CONFIG_NAMESPACE "ArkConfig"
#define CONFIG_OPTION__CONFIG_VERSION "configVersion"
#define CONFIG_OPTION__WIFI__TYPE "wifiType"
#define CONFIG_OPTION__WIFI__SSID "wifiSSID"
#define CONFIG_OPTION__WIFI__PASSWORD "wifiPassword"
#define CONFIG_OPTION__WIFI__USERNAME "wifiUser" // needed for "Enterprise" wifi
#define CONFIG_OPTION__TIME__TIMEZONE "timeZone"
#define CONFIG_OPTION__FONT__BLINKING_COLON "fontBlkColon"
#define CONFIG_OPTION__FONT__NO "fontNo"

#define WIFI_TYPE__HOME 0
#define WIFI_TYPE__ENTERPRISE 1


// To store Wifi Configuration
struct ArkWifiConfig
{
  short type; 
  char ssid[30];
  char password[50];
  char username[50];
};

// To store time configuration
struct ArkTimeConfig
{
    short timezone;
};

// To store Font configuration
struct ArkFontConfig
{
  bool colonBlink;
  short fontNo;
};

// Structure to store whole ARK Clock configuration
struct ArkConfig 
{
  short version;
  ArkWifiConfig wifi;
  ArkTimeConfig time;
  ArkFontConfig font;
};

// ---------------------------------------
// Class definition
class ArkConfigMenu
{
  public:
    ArkConfigMenu();

    void begin(WiFiClass wifiAdapter, FontInfos fontList[], TimezoneInfos timezoneList[]);

    short handleInput();

    bool isConfigFormatValid();

    short getWifiType();
    char* getWifiSSID();
    char* getWifiUsername();
    char* getWifiPassword();
    
    TimezoneInfos getTimezoneInfos();
    FontInfos getFontInfos();
    bool doesColonHaveToBlink();

    void toggleFont();

  protected:
    short _currentMenuIndex, _currentSubMenuIndex;
    bool _displayPrompt;
    short _userInputStep; // What input we are expecting
    bool _configFormatIsValid;
    FontInfos* _fontList;
    TimezoneInfos* _timezoneList;
    WiFiClass _wifiAdapter;

    // To store configuration
    ArkConfig _config;

    String _nextInputPrompt;
    char _nextExpectedInputTypePrompt;

    char* _menu[ROOT_MENU_SIZE];
    char* _subMenu[ROOT_MENU_SIZE][SUB_MENU_SIZE__WIFI];

    // Utilities
    void convertStringToCharArray(String text, char* output);

    void printCurrentMenu();
    void setNextInputPrompt(String txt, char type=EXPECTED_INPUT_TYPE_PROMPT__STRING);
    void printNextInputPrompt();
    short handleSubMenu(String lastUserInput);
    void printInvalidConfigMessage();

    short getSubMenuIndexFromId(short rootMenuIndex, short subMenuId);
    short getSubMenuIdFromIndex(short rootMenuIndex, short subMenuIndex);

    short getCurrentSubMenuSize();

    void loadConfig();
    void saveConfig();
};


#endif