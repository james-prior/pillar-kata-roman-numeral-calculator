#include <stdlib.h>
#include <string.h>
#include "roman.h"

struct roman_struct *new_roman(char *roman_numeral)
{
    struct roman_struct *r;

    r = malloc(sizeof(struct roman_struct));
    if (r == NULL)
        return NULL;

    if (strcmp(roman_numeral, "I") == 0) {
        r->value = 1;
    } else {
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

