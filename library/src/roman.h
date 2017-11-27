#if !defined(ROMAN_H)
#define ROMAN_H

#define MAX_ROMAN_NUMERAL_LENGTH (4+4+4+3+1)

typedef char roman_numeral[MAX_ROMAN_NUMERAL_LENGTH];
// The following return NULL for any error.
roman_numeral *add_roman_numerals(
    roman_numeral *sum, char *addend1, char *addend2);
roman_numeral *subtract_roman_numerals(
    roman_numeral *difference, char *minuend, char *subtrahend);

#endif
