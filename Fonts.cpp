/*
  Digits data objects
*/

#include "Fonts.h"
#include "AvengersDigits.h"
#include "CrystalDigits.h"
#include "StarkDigits.h"

FontInfos allFonts[NB_FONTS] = {
  {"Avengers", allAvengerDigits, avengersColonOrNot},
  {"Crystal", allCrystalDigits, crystalColonOrNot},
  {"Stark", allStarkDigits, starkColonOrNot}
};