#if !defined(ROMAN_H)
#define ROMAN_H

typedef char roman_numeral[21];
roman_numeral *add_roman_numerals(
    roman_numeral *sum, char *addend1, char *addend2);
// struct roman_struct {
//     unsigned value;
// };
// 
// struct roman_struct *new_roman(char *roman_numeral);
// struct roman_struct *new_roman_from_uint(unsigned value);
// char *print_roman(struct roman_struct *roman_numeral);
// struct roman_struct *add_roman(
//     struct roman_struct *,
//     struct roman_struct *
// );
// struct roman_struct *subtract_roman(
//     struct roman_struct *minuend,
//     struct roman_struct *subtrahend
// );
// unsigned get_roman_value(struct roman_struct *roman);
// void free_roman(struct roman_struct *m);

#endif
