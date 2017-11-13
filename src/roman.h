#if !defined(ROMAN_H)
#define ROMAN_H

struct roman_struct {
    unsigned value;
};

struct roman_struct *new_roman(char *roman_numeral);
struct roman_struct *new_roman_from_uint(uint value);
unsigned get_roman_value(struct roman_struct *roman);
void free_roman(struct roman_struct *m);

#endif
