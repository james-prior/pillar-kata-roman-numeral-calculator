#if !defined(ROMAN_H)
#define ROMAN_H

typedef char roman_numeral[21];
roman_numeral *add_roman_numerals(
    roman_numeral *sum, char *addend1, char *addend2);
roman_numeral *subtract_roman_numerals(
    roman_numeral *difference, char *minuend, char *subtrahend);

#endif
