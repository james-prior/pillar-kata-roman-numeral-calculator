#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <roman.h>
#include "computator.h"

#define MAX_LINE_LENGTH (81)

static char *get_usage(int argc, char *argv[])
{
    static char buf[1000];

    sprintf(
        buf,
        (
            "USAGE:\n"
            "    %s ROMAN_NUMERAL [-]ROMAN_NUMERAL [[-]ROMAN_NUMERAL]...\n"
            "\n"
            "DESCRIPTION:\n"
            "    Adds roman numerals, showing intermediate sums.\n"
            "    Roman numerals prefixed with a '-' are subtracted.\n"
        ),
        argv[0]
    );
    return buf;
}

/* Returns roman_numeral if it is a vaild roman numeral.
*  Otherwise returns NULL. */
static char *good_roman_numeral(char *roman_numeral)
{
    char *result;

    if (roman_numeral[0] != 'M')
        result = add_roman_numerals(roman_numeral, "I");
    else
        result = subtract_roman_numerals(roman_numeral, "I");

    return (result != NULL) ? roman_numeral : NULL;
}

char *meat(int argc, char *argv[])
{
    int i;
    char *buf;
    char line[MAX_LINE_LENGTH];
    char sum[MAX_ROMAN_NUMERAL_LENGTH];
    char *result;

    if (argc < 3)
        return get_usage(argc, argv);

    buf = malloc(argc * MAX_LINE_LENGTH);
    buf[0] = '\0';
    for (i = 1; i < argc; i++) {
        if (i == 1) {
            result = good_roman_numeral(argv[i]);
        } else {
            char *operand2 = argv[i];
            char *(*operator)(char *, char *);

            if (operand2[0] == '-') {
                operand2++;
                operator = subtract_roman_numerals;
            } else {
                operator = add_roman_numerals;
            }
            result = operator(sum, operand2);
        }
        if (result != NULL)
            strcpy(sum, result);
        snprintf(
            line,
            MAX_LINE_LENGTH,
            "%s %s\n",
            argv[i],
            ((result != NULL) ? result : "ERRATUM")
        );
        strcat(buf, line);
        if (result == NULL)
            break;
    }

    return buf;
}

int MAIN_FUNCTION(int argc, char *argv[])
{
    printf("%s", meat(argc, argv));

    exit(EXIT_SUCCESS);
}
