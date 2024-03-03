
#ifndef TimezoneDef_h
#define TimezoneDef_h

// https://github.com/JChristensen/Timezone
#include <Timezone.h>

enum TIMEZONE_IDX {TIMEZONE_AEDT_AEST=0, TIMEZONE_MSK, TIMEZONE_CET_CEST, TIMEZONE_BST_GMT, TIMEZONE_UTC, TIMEZONE_EDT_EST, TIMEZONE_CDT_CST, TIMEZONE_MDT_MST, TIMEZONE_MST, TIMEZONE_PDT_PST};

struct TZDefinition
{
  char name[100];
  Timezone tz;
};

#define NB_TIMEZONES 10

// Defines timezone list
extern TZDefinition timezoneList[NB_TIMEZONES];

#endif
