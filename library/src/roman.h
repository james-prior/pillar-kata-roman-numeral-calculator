#if !defined(ROMAN_H)
#define ROMAN_H

#define MAX_ROMAN_NUMERAL_LENGTH (4+4+4+3+1)

// The following return NULL for any error.
// Otherwise return pointer to static buffers.
char *add_roman_numerals(char *addend1, char *addend2);
char *subtract_roman_numerals(char *minuend, char *subtrahend);

#endif
