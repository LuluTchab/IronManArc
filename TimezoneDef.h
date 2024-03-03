
#ifndef TimezoneDef_h
#define TimezoneDef_h

// https://github.com/JChristensen/Timezone
#include <Timezone.h>

struct TimezoneInfos
{
  char name[100];
  Timezone timezone;
};

#define NB_TIMEZONES 10

// Defines timezone list
extern TimezoneInfos timezoneList[NB_TIMEZONES];

#endif
