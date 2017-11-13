#include <stdlib.h>
#include "roman.h"

#define FALSE (0)
#define TRUE (!FALSE)

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

static int get_max_run_length_of_roman_letter(int roman_letter)
{
    switch (roman_letter) {
    case 'I': return 3; break;
    case 'V': return 1; break;
    case 'X': return 3; break;
    case 'L': return 1; break;
    case 'C': return 3; break;
    case 'D': return 1; break;
    case 'M': return 3; break;
    default:  return 0; break;
    }
}

static int is_valid_subtractive_combination_of_roman_letters(
    int subtractive_roman_letter,
    int additive_roman_letter)
{
    switch (subtractive_roman_letter) {
    case 'I':
        switch (additive_roman_letter) {
        case 'V': return  TRUE; break;
        case 'X': return  TRUE; break;
        default:  return FALSE; break;
        }
        break;
    case 'X':
        switch (additive_roman_letter) {
        case 'L': return  TRUE; break;
        case 'C': return  TRUE; break;
        default:  return FALSE; break;
        }
        break;
    case 'C':
        switch (additive_roman_letter) {
        case 'D': return  TRUE; break;
        case 'M': return  TRUE; break;
        default:  return FALSE; break;
        }
        break;
    default:  return FALSE; break;
    }
}

static unsigned get_value_of_roman_numeral(char *roman_numeral)
{
    unsigned sum;
    unsigned old_x;
    unsigned x;
    unsigned next_x;
    int n;

    sum = 0U;

    old_x = 0U; /* deliberately does not match any roman letter value */
    n = 0;
    for ( ; *roman_numeral != '\0'; roman_numeral++) {
        x = get_value_of_roman_letter(roman_numeral[0]);
        next_x = get_value_of_roman_letter(roman_numeral[1]);

        if (x != old_x) {
            n = 0;
            old_x = x;
        }
        n++;
        if (n > get_max_run_length_of_roman_letter(roman_numeral[0]))
            return 0U;
        if (n > 1 && x < next_x)
            // Too many subtractive letters consecutively.
            return 0U;

        if (x == 0U)
            return 0U;
        if (x < next_x) {
            if (!is_valid_subtractive_combination_of_roman_letters(
                    roman_numeral[0], roman_numeral[1]))
                return 0U;
            sum -= x;
        } else {
            sum += x;
        }

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
    if (r->value <= 0) {
        free_roman(r);
        return NULL;
    }

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

