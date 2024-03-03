/*
  Digits data definition
*/

#ifndef Fonts_h
#define Fonts_h

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
extern FontInfo allFonts[NB_FONTS];

#endif
