#include "ArkConfigMenu.h"


// Class constructor
ArkConfigMenu::ArkConfigMenu()
{
  // Set as "no menu selected"
  _currentMenuIndex = INT_UNINITIALIZED;
  _currentSubMenuIndex = INT_UNINITIALIZED;
  _userInputStep = 0;

  _displayPrompt = true;
  _configFormatIsValid = false;

  // - Wifi
  _menu[ROOT_MENU_INDEX__WIFI_CONFIG] = "Wifi config";
  _subMenu[ROOT_MENU_INDEX__WIFI_CONFIG][SUB_MENU__BACK] = "Back";
  _subMenu[ROOT_MENU_INDEX__WIFI_CONFIG][getSubMenuIndexFromId(ROOT_MENU_INDEX__WIFI_CONFIG, SUB_MENU__WIFI_CONFIG__VIEW)] = "View current config";
  _subMenu[ROOT_MENU_INDEX__WIFI_CONFIG][getSubMenuIndexFromId(ROOT_MENU_INDEX__WIFI_CONFIG, SUB_MENU__WIFI_CONFIG__LIST_NETWORKS)] = "List available networks";
  _subMenu[ROOT_MENU_INDEX__WIFI_CONFIG][getSubMenuIndexFromId(ROOT_MENU_INDEX__WIFI_CONFIG, SUB_MENU__WIFI_CONFIG__SET)] = "Set SSID/Password";
  
  // - Time
  _menu[ROOT_MENU_INDEX__TIME_CONFIG] = "Time config";
  _subMenu[ROOT_MENU_INDEX__TIME_CONFIG][SUB_MENU__BACK] = "Back";
  _subMenu[ROOT_MENU_INDEX__TIME_CONFIG][getSubMenuIndexFromId(ROOT_MENU_INDEX__TIME_CONFIG, SUB_MENU__TIME_CONFIG__VIEW)] = "View current config";
  _subMenu[ROOT_MENU_INDEX__TIME_CONFIG][getSubMenuIndexFromId(ROOT_MENU_INDEX__TIME_CONFIG, SUB_MENU__TIME_CONFIG__SET)] = "Set timezone";

  // - Font
  _menu[ROOT_MENU_INDEX__FONT_CONFIG] = "Font config";
  _subMenu[ROOT_MENU_INDEX__FONT_CONFIG][SUB_MENU__BACK] = "Back";
  _subMenu[ROOT_MENU_INDEX__FONT_CONFIG][getSubMenuIndexFromId(ROOT_MENU_INDEX__FONT_CONFIG, SUB_MENU__FONT_CONFIG__VIEW)] = "View current config";
  _subMenu[ROOT_MENU_INDEX__FONT_CONFIG][getSubMenuIndexFromId(ROOT_MENU_INDEX__FONT_CONFIG, SUB_MENU__FONT_CONFIG__TOGGLE_BLINK)] = "Toggle blinking colon";
  _subMenu[ROOT_MENU_INDEX__FONT_CONFIG][getSubMenuIndexFromId(ROOT_MENU_INDEX__FONT_CONFIG, SUB_MENU__FONT_CONFIG__SET_FONT)] = "Set font";
  
}

// ------------------------------------------------------------
// Start the configuration
// NOTE: we cannot do this inside class constructor because it won't be
// able to correcly load configuration from Preferences
void ArkConfigMenu::begin(FontInfo fontList[])
{
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }

  loadConfig();
  
  // At beginning, we expect for INT to navigate into menu
  _nextExpectedInputTypePrompt = EXPECTED_INPUT_TYPE_PROMPT__INT;
  _nextInputPrompt = INPUT_PROMPT__CHOICE;

  _fontList = fontList;

  // We start by displaying the menu
  printCurrentMenu();

  Serial.setTimeout(10);
}

// ------------------------------------------------------------
// To tell if configuration format is valid
bool ArkConfigMenu::isConfigFormatValid() { return _configFormatIsValid; }


// ------------------------------------------------------------
// Handle menu inputs
short ArkConfigMenu::handleInput()
{
  // Id of action to return to caller, in case of something has to be handled on caller side
  short actionToReturn = INT_UNINITIALIZED;

  if(_displayPrompt)
  {
    _displayPrompt = false;
    printNextInputPrompt();
    
  }
  else
  {
    if (Serial.available() > 0)
    {
      String userInput = Serial.readString();
      userInput.trim();

      // Help is requested (we print current menu)
      if(userInput == "?")
      {
        printCurrentMenu();
      }
      else // Help wasn't requested
      {

        // if we are navigating into menus
        if(_currentMenuIndex==INT_UNINITIALIZED || _currentSubMenuIndex==INT_UNINITIALIZED)
        {
          int requestedMenuIndex = userInput.toInt();

          // if root menu is displayed but nothing is selected
          if(_currentMenuIndex == INT_UNINITIALIZED)
          {
            // If we are in range, we select menu
            if(requestedMenuIndex < ROOT_MENU_SIZE) _currentMenuIndex = requestedMenuIndex;

            printCurrentMenu();
          }
          // if submenu is displayed but nothing selected
          else if(_currentSubMenuIndex==INT_UNINITIALIZED)
          {
            // If we are in range, we select menu
            if(requestedMenuIndex < getCurrentSubMenuSize())
            {
              // If we asked for 'Back'
              if(requestedMenuIndex == SUB_MENU__BACK)
              {
                // We go back to root menu
                _currentMenuIndex = INT_UNINITIALIZED;
                printCurrentMenu();
              }
              else // Another menu entry was selected
              {
                _currentSubMenuIndex = requestedMenuIndex;
                actionToReturn = handleSubMenu(userInput);
              }
              
            }
            else // selected sub-menu is out of range
            {
              printCurrentMenu();
            }
          }
          
        }// END if we are navigating into menus        
        else // We've selected an entry in sub-menu
        {
          actionToReturn = handleSubMenu(userInput);
        }
      }// END if help wasn't requested
      
      _displayPrompt = true;

    }// END if serial is avaiable
  }// END if we are waiting for user input

  return actionToReturn;
}


// ------------------------------------------------------------
// Set next input prompt text and expected type
void ArkConfigMenu::setNextInputPrompt(String txt, char type)
{
  _nextInputPrompt = txt;
  _nextExpectedInputTypePrompt = type;
  // To display prompt at next occurrence
  _displayPrompt = true;
}


// ------------------------------------------------------------
// Displays next user input prompt, with char to identify type
void ArkConfigMenu::printNextInputPrompt()
{
  Serial.print(_nextInputPrompt);
  Serial.println(_nextExpectedInputTypePrompt);
}


// ------------------------------------------------------------
// Returns Configuration information
char* ArkConfigMenu::getWifiSSID() { return _config.wifi.ssid; }
char* ArkConfigMenu::getWifiPassword() { return _config.wifi.password; }
short ArkConfigMenu::getTimezone() { return _config.time.timezone; }
short ArkConfigMenu::getFontNo() { return _config.font.fontNo; }
bool ArkConfigMenu::doesColonHaveToBlink() { return _config.font.colonBlink; }


// ------------------------------------------------------------
// Converts String into char*
void ArkConfigMenu::convertStringToCharArray(String text, char* output)
{
  text.toCharArray(output, text.length()+1);
}


// ------------------------------------------------------------
// Display menu for user
void ArkConfigMenu::printCurrentMenu()
{
  // If we have to display Root menu
  if(_currentMenuIndex == INT_UNINITIALIZED)
  {
    Serial.println("");
    Serial.println("= Select option =");
    for(short i=0; i<ROOT_MENU_SIZE; i++)
    {
      Serial.print("["); Serial.print(i); Serial.print("] "); Serial.println(_menu[i]);
    }
    Serial.println("");
  }
  // We have to display one of the sub menus
  else if(_currentSubMenuIndex == INT_UNINITIALIZED)
  {
    Serial.println("");
    // First we display root menu name
    Serial.print("= "); Serial.print(_menu[_currentMenuIndex]); Serial.println(" =");
    for(short i=0; i< getCurrentSubMenuSize() ; i++)
    {
      Serial.print("["); Serial.print(i); Serial.print("] "); Serial.println(_subMenu[_currentMenuIndex][i]);
    }
    Serial.println("");
  }

  // Initializing
  setNextInputPrompt(INPUT_PROMPT__CHOICE, EXPECTED_INPUT_TYPE_PROMPT__INT);

}


// ------------------------------------------------------------
// Handle sub-menu selection
short ArkConfigMenu::handleSubMenu(String lastUserInput)
{
  // Id of action to return to caller, in case of something has to be handled on caller side
  short actionToReturn = INT_UNINITIALIZED;

  // Depending sub-menu that was selected
  switch(getSubMenuIdFromIndex(_currentMenuIndex, _currentSubMenuIndex))
  {

    // ------------------------------------------------------------------------------------------------

    // --------------------
    // Wifi - View Config
    case SUB_MENU__WIFI_CONFIG__VIEW:
    {
      if(_configFormatIsValid)
      {
        Serial.println("== Wifi config ==");
        Serial.print(" SSID: "); Serial.println(getWifiSSID());
      }
      else
      {
        printInvalidConfigMessage();
      }
      // To display sub-menu again
      _currentSubMenuIndex = INT_UNINITIALIZED;
      break;
    }

    // --------------------
    // Wifi - list networks
    case SUB_MENU__WIFI_CONFIG__LIST_NETWORKS:
    {
      // We gave back to caller the action that was selected
      actionToReturn = SUB_MENU__WIFI_CONFIG__LIST_NETWORKS;
      // To display sub-menu again
      _currentSubMenuIndex = INT_UNINITIALIZED;
      break;
    }

    // --------------------
    // Wifi - Set Config
    case SUB_MENU__WIFI_CONFIG__SET:
    {
      switch(_userInputStep)
      {
        // We have to ask for Wifi SSID
        case 0:
        {
          setNextInputPrompt("Enter Wifi SSID", EXPECTED_INPUT_TYPE_PROMPT__STRING);
          break;
        }
        // We have to ask for Wifi Password
        case 1:
        {
          // Saving Wifi SSID that was just given
          lastUserInput.toCharArray(_config.wifi.ssid, lastUserInput.length()+1);
          setNextInputPrompt("Enter Wifi Password", EXPECTED_INPUT_TYPE_PROMPT__PASSWORD);
          break;
        }
        // Both SSID and password were given
        case 2:
        {
          // Saving Wifi Password that was just given
          lastUserInput.toCharArray(_config.wifi.password, lastUserInput.length()+1);
          // Saving configuration into EEPROM
          saveConfig();
          Serial.println("");
          Serial.println("Wifi updated. Ark reactor will restart in 2 seconds...");
          delay(2000);
          ESP.restart();
          // To display sub-menu again
          _currentSubMenuIndex = INT_UNINITIALIZED;
          break;
        }
      }
      break;
    }


    // ------------------------------------------------------------------------------------------------


    // --------------------
    // Time - View Config
    case SUB_MENU__TIME_CONFIG__VIEW:
    {
      Serial.println("== Time config ==");
      // Make caller to display timezone name
      actionToReturn = SUB_MENU__TIME_CONFIG__VIEW;
      // To display sub-menu again
      _currentSubMenuIndex = INT_UNINITIALIZED;
      break;
    }

    // --------------------
    // Time - Set config
    case SUB_MENU__TIME_CONFIG__SET:
    {
      switch(_userInputStep)
      {
        // We have to ask for a timezone
        case 0:
        {
          // To make caller display timezone list
          actionToReturn = SUB_MENU__TIME_CONFIG__SET;
          setNextInputPrompt("Select Timezone:", EXPECTED_INPUT_TYPE_PROMPT__INT);
          break;
        }
        // Info about timezone has been given
        case 1:
        {
          _config.time.timezone = lastUserInput.toInt();
          saveConfig();
          // To display sub-menu again
          _currentSubMenuIndex = INT_UNINITIALIZED;
          break;
        }
      }
      break;
    }
  

    // ------------------------------------------------------------------------------------------------


    // --------------------
    // Font - View Config
    case SUB_MENU__FONT_CONFIG__VIEW:
    {
      Serial.println("== Font config ==");
      Serial.print(" Is colon blinking? "); Serial.println((doesColonHaveToBlink())?"Yes":"No");
      Serial.print(" Current font: "); Serial.println(_fontList[getFontNo()].name);
      Serial.println("");
      // To display sub-menu again
      _currentSubMenuIndex = INT_UNINITIALIZED;
      break;
    }

    // --------------------
    // Font - Toggle blink
    case SUB_MENU__FONT_CONFIG__TOGGLE_BLINK:
    {
      switch(_userInputStep)
      {
        // We have to ask for Colon blinking or not
        case 0:
        {
          setNextInputPrompt("Colon blinking enabled [y/n]", EXPECTED_INPUT_TYPE_PROMPT__BOOL);
          break;
        }
        // Info about colon blinking has been given
        case 1:
        {
          lastUserInput.toLowerCase();
          _config.font.colonBlink = (lastUserInput == "y");
          saveConfig();
          // To display sub-menu again
          _currentSubMenuIndex = INT_UNINITIALIZED;
          break;
        }
      }
      break;
    }

    // --------------------
    // Font - Set font
    case SUB_MENU__FONT_CONFIG__SET_FONT:
    {
      switch(_userInputStep)
      {
        // We have to ask for a Font
        case 0:
        {
          // To make caller display font list
          actionToReturn = SUB_MENU__FONT_CONFIG__SET_FONT;
          setNextInputPrompt("Select font:", EXPECTED_INPUT_TYPE_PROMPT__INT);
          break;
        }
        // Info about font has been given
        case 1:
        {
          _config.font.fontNo = lastUserInput.toInt();
          saveConfig();
          // To display sub-menu again
          _currentSubMenuIndex = INT_UNINITIALIZED;
          break;
        }
      }
      break;
    }

  }

  // to go to next input step if needed
  if(_currentSubMenuIndex != INT_UNINITIALIZED)
  {
    _userInputStep++;
  }
  else
  {
    _userInputStep = 0;
  }

  // Display menu if needed
  if(_currentSubMenuIndex == INT_UNINITIALIZED) printCurrentMenu();

  return actionToReturn;
}


// ------------------------------------------------------------
void ArkConfigMenu::printInvalidConfigMessage()
{
  Serial.println("!! Configuration is invalid, please update it !!");
}


// ------------------------------------------------------------
// Returns array index in which menu with ID menuIndex is located
// rootMenuIndex can be ROOT_MENU_INDEX__WIFI_CONFIG or ROOT_MENU_INDEX__FONT_CONFIG
// subMenuId can be value of SUB_MENU__*, except SUB_MENU__BACK
short ArkConfigMenu::getSubMenuIndexFromId(short rootMenuIndex, short subMenuId)
{
  return subMenuId - (rootMenuIndex*10);
}

// ------------------------------------------------------------
// Returns menu ID (value of SUB_MENU__*, except SUB_MENU__BACK) for given menu index
// rootMenuIndex can be ROOT_MENU_INDEX__WIFI_CONFIG or ROOT_MENU_INDEX__FONT_CONFIG
// subMenuIndex, from 0 to  <ROOT_MENU_SIZE
short ArkConfigMenu::getSubMenuIdFromIndex(short rootMenuIndex, short subMenuIndex)
{
  return subMenuIndex + (rootMenuIndex*10);
}


// ------------------------------------------------------------
// Returns current submenu size
short ArkConfigMenu::getCurrentSubMenuSize()
{
  switch(_currentMenuIndex)
  {
    case ROOT_MENU_INDEX__WIFI_CONFIG: { return SUB_MENU_SIZE__WIFI; }
    case ROOT_MENU_INDEX__TIME_CONFIG: { return SUB_MENU_SIZE__TIME; }
    case ROOT_MENU_INDEX__FONT_CONFIG: { return SUB_MENU_SIZE__FONT; }
  }
}


// ------------------------------------------------------------
// Load configuration from Preferences
void ArkConfigMenu::loadConfig()
{
  Preferences prefs;
  String tmp;
  prefs.begin(CONFIG_NAMESPACE, true);
  _config.version = prefs.getShort(CONFIG_OPTION__CONFIG_VERSION, INT_UNINITIALIZED);
  // Wifi
  convertStringToCharArray(prefs.getString(CONFIG_OPTION__WIFI__SSID, STRING_UNINITIALIZED), _config.wifi.ssid);
  convertStringToCharArray(prefs.getString(CONFIG_OPTION__WIFI__PASSWORD, STRING_UNINITIALIZED), _config.wifi.password);
  
  // Time
  _config.time.timezone = prefs.getShort(CONFIG_OPTION__TIME__TIMEZONE);

  // Font
  _config.font.colonBlink = prefs.getBool(CONFIG_OPTION__FONT__BLINKING_COLON);
  prefs.end();

  _configFormatIsValid = true;
  // If equals to 0, it means that we don't have information about that
  if(_config.version == INT_UNINITIALIZED)
  {
    _configFormatIsValid = false;
  }

  // If stored configuration version is different than the current one
  if(_config.version != ARK_CONFIG_VERSION)
  {
    // TODO: handle in the future
    _configFormatIsValid = false;
  }
}


// ------------------------------------------------------------
// Saves configuration into Preferences
void ArkConfigMenu::saveConfig()
{
  Preferences prefs;
  prefs.begin(CONFIG_NAMESPACE, false);

  prefs.putShort(CONFIG_OPTION__CONFIG_VERSION, ARK_CONFIG_VERSION);
  // Wifi
  prefs.putString(CONFIG_OPTION__WIFI__SSID, _config.wifi.ssid);
  prefs.putString(CONFIG_OPTION__WIFI__PASSWORD, _config.wifi.password);
  // Time
  prefs.putShort(CONFIG_OPTION__TIME__TIMEZONE, _config.time.timezone);
  // Font
  prefs.putBool(CONFIG_OPTION__FONT__BLINKING_COLON, _config.font.colonBlink);
  prefs.end();
  // Because we saved it, config format is now valid again
  _configFormatIsValid = true;
}



