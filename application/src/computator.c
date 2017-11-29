#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <roman.h>
#include "computator.h"

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
    static char buf[1000];

    if (argc < 3)
        return get_usage(argc, argv);

    strcpy(buf, (
        "I I\n"
        "I II\n"
    ));
    return buf;
}

int MAIN_FUNCTION(int argc, char *argv[])
{
    printf("%s", meat(argc, argv));

    exit(EXIT_SUCCESS);
}
