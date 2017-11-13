#include <stdlib.h>
#include "roman.h"

static unsigned get_value_of_roman_letter(int roman_letter)
{
    switch (roman_letter) {
    case 'I': return    1U; break;
    case 'V': return    5U; break;
    case 'X': return   10U; break;
    case 'L': return   50U; break;
    case 'C': return  100U; break;
    case 'D': return  500U; break;
    case 'M': return 1000U; break;
    default:  return    0U; break;
    }
}

static unsigned get_value_of_roman_numeral(char *roman_numeral)
{
    unsigned sum;
    unsigned x;
    unsigned next_x;

    sum = 0U;

    for ( ; *roman_numeral != '\0'; roman_numeral++) {
        x = get_value_of_roman_letter(*roman_numeral);
        next_x = get_value_of_roman_letter(*(roman_numeral+1));
        if (x == 0U)
            return 0U;
        if (x < next_x)
            sum -= x;
        else
            sum += x;
    }

    return sum;
}

struct roman_struct *new_roman(char *roman_numeral)
{
    struct roman_struct *r;

    r = malloc(sizeof(struct roman_struct));
    if (r == NULL)
        return NULL;

    r->value = get_value_of_roman_numeral(roman_numeral);
    if (r->value <= 0)
        return NULL;

    return r;
}

unsigned get_roman_value(struct roman_struct *r)
{
    return r->value;
}

void free_roman(struct roman_struct *r)
{
    free(r);
}

