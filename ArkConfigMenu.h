#ifndef ArkConfigMenu_h
#define ArkConfigMenu_h

// https://iotcircuithub.com/esp32-preferences-library-tutorial/
#include <Preferences.h>
#include "Arduino.h"

#define ARK_CONFIG_VERSION 1

// Root menu
#define ROOT_MENU_SIZE 2
#define ROOT_MENU_INDEX__WIFI_CONFIG 0
#define ROOT_MENU_INDEX__FONT_CONFIG 1

// Sub menus
#define SUB_MENU_SIZE 4
#define SUB_MENU__BACK 0
// Wifi Config
#define SUB_MENU__WIFI_CONFIG__VIEW 1
#define SUB_MENU__WIFI_CONFIG__LIST_NETWORKS 2
#define SUB_MENU__WIFI_CONFIG__SET 3
// Font Config
#define SUB_MENU__FONT_CONFIG__VIEW 11
#define SUB_MENU__FONT_CONFIG__TOGGLE_BLINK 12

#define INT_UNINITIALIZED -1
#define STRING_UNINITIALIZED "?no value?"

#define INPUT_PROMPT__CHOICE "Choice"

// Types for user inputs
#define EXPECTED_INPUT_TYPE_PROMPT__STRING '>'
#define EXPECTED_INPUT_TYPE_PROMPT__PASSWORD '*'
#define EXPECTED_INPUT_TYPE_PROMPT__INT '#'
#define EXPECTED_INPUT_TYPE_PROMPT__BOOL '&'

#define CONFIG_NAMESPACE "ArkConfig"
#define CONFIG_OPTION__CONFIG_VERSION "configVersion"
#define CONFIG_OPTION__WIFI__SSID "wifiSSID"
#define CONFIG_OPTION__WIFI__PASSWORD "wifiPassword"
#define CONFIG_OPTION__FONT__BLINKING_COLON "fontBlinkingColon"


// To store Wifi Configuration
struct ArkWifiConfig
{
  char ssid[30];
  char password[30];
};

// To store Font configuration
struct ArkFontConfig
{
  bool colonBlink;
};

// Structure to store whole ARK Clock configuration
struct ArkConfig 
{
  short version;
  ArkWifiConfig wifi;
  ArkFontConfig font;
};

// ---------------------------------------
// Class definition
class ArkConfigMenu
{
  public:
    ArkConfigMenu();

    void begin();

    short handleInput();

    bool isConfigFormatValid();

    char* getWifiSSID();
    char* getWifiPassword();
    bool doesColonHaveToBlink();

  protected:
    short _currentMenuIndex, _currentSubMenuIndex;
    bool _displayPrompt;
    short _userInputStep; // What input we are expecting
    bool _configFormatIsValid;

    // To store configuration
    ArkConfig _config;

    String _nextInputPrompt;
    char _nextExpectedInputTypePrompt;

    char* _menu[ROOT_MENU_SIZE];
    char* _subMenu[ROOT_MENU_SIZE][SUB_MENU_SIZE];

    // Utilities
    short convertCharToInt(char c);
    char* convertStringToCharArray(String text);

    void printCurrentMenu();
    void setNextInputPrompt(String txt, char type=EXPECTED_INPUT_TYPE_PROMPT__STRING);
    void displayNextInputPrompt();
    short handleSubMenu(String lastUserInput);
    void displayInvalidConfigMessage();

    short getSubMenuIndexFromId(short rootMenuIndex, short subMenuId);
    short getSubMenuIdFromIndex(short rootMenuIndex, short subMenuIndex);

    void loadConfig();
    void saveConfig();
};


#endif