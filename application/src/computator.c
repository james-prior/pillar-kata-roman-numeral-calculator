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
            result = argv[i];
        } else {
            result = add_roman_numerals(sum, argv[i]);
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
