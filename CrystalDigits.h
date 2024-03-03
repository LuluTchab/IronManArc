/*
  Resources to display time.
  Theme: Crystal
*/

#ifndef CrystalDigits_h
#define CrystalDigits_h

#include "Arduino.h"

// 'digit_0', 29x32px
const unsigned char crystalDigit0 [] PROGMEM = {
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0xff, 0xff, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xf8, 0x00
};


// 'digit_1', 29x32px
const unsigned char crystalDigit1 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'digit_2', 29x32px
const unsigned char crystalDigit2 [] PROGMEM = {
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x7d, 0xff, 0x00, 0x00, 0xff, 0xfc, 0x00, 
	0x00, 0xff, 0xfc, 0x00, 0x03, 0xfd, 0xf8, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 
	0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 
	0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 
	0x03, 0xff, 0xf8, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xf8, 0x00
};
// 'digit_3', 29x32px
const unsigned char crystalDigit3 [] PROGMEM = {
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x7e, 0xff, 0x00, 0x00, 0xff, 0xfc, 0x00, 
	0x00, 0xff, 0xfc, 0x00, 0x00, 0x7e, 0xff, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x7f, 0xff, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xf8, 0x00
};
// 'digit_4', 29x32px
const unsigned char crystalDigit4 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x06, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0xfd, 0xff, 0x00, 0x03, 0xff, 0xff, 0x00, 
	0x00, 0xff, 0xfc, 0x00, 0x00, 0x7d, 0xff, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'digit_5', 29x32px
const unsigned char crystalDigit5 [] PROGMEM = {
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xf8, 0x00, 
	0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 
	0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 
	0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0xfd, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 
	0x00, 0xff, 0xfc, 0x00, 0x00, 0x7d, 0xff, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x7f, 0xff, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xf8, 0x00
};
// 'digit_6', 29x32px
const unsigned char crystalDigit6 [] PROGMEM = {
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xf8, 0x00, 
	0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 
	0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 
	0x03, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0xfd, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 
	0x00, 0xff, 0xfc, 0x00, 0x03, 0xfd, 0xff, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0xff, 0xff, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xf8, 0x00
};
// 'digit_7', 29x32px
const unsigned char crystalDigit7 [] PROGMEM = {
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'digit_8', 29x32px
const unsigned char crystalDigit8 [] PROGMEM = {
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0xfd, 0xff, 0x00, 0x00, 0xff, 0xfc, 0x00, 
	0x00, 0xff, 0xfc, 0x00, 0x03, 0xfd, 0xff, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0xff, 0xff, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xf8, 0x00
};
// 'digit_9', 29x32px
const unsigned char crystalDigit9 [] PROGMEM = {
	0x00, 0x7f, 0xf8, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 
	0x03, 0x80, 0x07, 0x00, 0x03, 0x80, 0x07, 0x00, 0x03, 0xfd, 0xff, 0x00, 0x00, 0xff, 0xfc, 0x00, 
	0x00, 0xff, 0xfc, 0x00, 0x00, 0x7d, 0xff, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 
	0x00, 0x7f, 0xff, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xf8, 0x00
};

// Array with all digits
const unsigned char * allCrystalDigits [] = {
  crystalDigit0,
  crystalDigit1,
  crystalDigit2,
  crystalDigit3,
  crystalDigit4,
  crystalDigit5,
  crystalDigit6,
  crystalDigit7,
  crystalDigit8,
  crystalDigit9
};

// 'digit_colon', 12x32px
const unsigned char crystalColon [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x06, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x06, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


// 'digit_no_colon', 12x32px
const unsigned char crystalNoColon [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char * crystalColonOrNot [] = {
  crystalNoColon,  // index 0 => bool(false) => pas de colon (:)
  crystalColon
};

#endif