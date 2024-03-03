#include "TimezoneDef.h"
// https://github.com/JChristensen/Timezone
#include <Timezone.h>

// Australia Eastern Time Zone (Sydney, Melbourne)
TimeChangeRule aEDT = {"AEDT", First, Sun, Oct, 2, 660};    // UTC + 11 hours
TimeChangeRule aEST = {"AEST", First, Sun, Apr, 3, 600};    // UTC + 10 hours
Timezone tzAusET(aEDT, aEST);

// Moscow Standard Time (MSK, does not observe DST)
TimeChangeRule msk = {"MSK", Last, Sun, Mar, 1, 180};
Timezone tzMSK(msk);

// Central European Time (Frankfurt, Paris)
TimeChangeRule CEST = {"CEST", Last, Sun, Mar, 2, 120};     // Central European Summer Time
TimeChangeRule CET = {"CET ", Last, Sun, Oct, 3, 60};       // Central European Standard Time
Timezone tzCE(CEST, CET);

// United Kingdom (London, Belfast)
TimeChangeRule BST = {"BST", Last, Sun, Mar, 1, 60};        // British Summer Time
TimeChangeRule GMT = {"GMT", Last, Sun, Oct, 2, 0};         // Standard Time
Timezone tzUK(BST, GMT);

// UTC
TimeChangeRule utcRule = {"UTC", Last, Sun, Mar, 1, 0};     // UTC
Timezone tzUTC(utcRule);

// US Eastern Time Zone (New York, Detroit)
TimeChangeRule usEDT = {"EDT", Second, Sun, Mar, 2, -240};  // Eastern Daylight Time = UTC - 4 hours
TimeChangeRule usEST = {"EST", First, Sun, Nov, 2, -300};   // Eastern Standard Time = UTC - 5 hours
Timezone tzUsET(usEDT, usEST);

// US Central Time Zone (Chicago, Houston)
TimeChangeRule usCDT = {"CDT", Second, Sun, Mar, 2, -300};
TimeChangeRule usCST = {"CST", First, Sun, Nov, 2, -360};
Timezone tzUsCT(usCDT, usCST);

// US Mountain Time Zone (Denver, Salt Lake City)
TimeChangeRule usMDT = {"MDT", Second, Sun, Mar, 2, -360};
TimeChangeRule usMST = {"MST", First, Sun, Nov, 2, -420};
Timezone tzUsMT(usMDT, usMST);

// Arizona is US Mountain Time Zone but does not use DST
Timezone tzUsAZ(usMST);

// US Pacific Time Zone (Las Vegas, Los Angeles)
TimeChangeRule usPDT = {"PDT", Second, Sun, Mar, 2, -420};
TimeChangeRule usPST = {"PST", First, Sun, Nov, 2, -480};
Timezone tzUsPT(usPDT, usPST);

TZDefinition timezoneList[] = {
  {"Australia Eastern Time Zone (Sydney, Melbourne)", tzAusET},
  {"Moscow Standard Time", tzMSK},
  {"Central European Time (Frankfurt, Paris)", tzCE},
  {"United Kingdom (London, Belfast)", tzUK},
  {"UTC", tzUTC},
  {"US Eastern Time Zone (New York, Detroit)", tzUsET},
  {"US Central Time Zone (Chicago, Houston)", tzUsCT},
  {"US Mountain Time Zone (Denver, Salt Lake City)", tzUsMT},
  {"Arizona is US Mountain Time Zone", tzUsAZ},
  {"US Pacific Time Zone (Las Vegas, Los Angeles)", tzUsPT}
};