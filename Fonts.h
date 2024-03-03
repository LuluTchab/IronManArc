/*
  Digits data
*/

#include "AvengersDigits.h"
#include "CrystalDigits.h"

enum WithColonOrNot {withoutColon=0, withColon};

// To save font data
struct FontInfo
{
  char name[20];
  const unsigned char** allDigits;
  const unsigned char** colonOrNot;
};

#define NB_FONTS 2

// Liste of available fonts
FontInfo allFonts[NB_FONTS] = {
  {"Avengers", allAvengerDigits, avengersColonOrNot},
  {"Crystal", allCrystalDigits, crystalColonOrNot}
};


