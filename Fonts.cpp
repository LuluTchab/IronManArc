/*
  Digits data objects
*/

#include "Fonts.h"
#include "AvengersDigits.h"
#include "CrystalDigits.h"
#include "StarkDigits.h"
#include "ThunderboltDigits.h"
#include "AquireDigits.h"

FontInfos allFonts[NB_FONTS] = {
  {"Avengers", allAvengerDigits, avengersColonOrNot},
  {"Crystal", allCrystalDigits, crystalColonOrNot},
  {"Stark", allStarkDigits, starkColonOrNot},
  {"Thunderbolt", allThunderboltDigits, thunderboltColonOrNot},
  {"Aquire", allAquireDigits, aquireColonOrNot}
};