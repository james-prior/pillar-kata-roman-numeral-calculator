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
            "    %s ROMAN_NUMERAL [[-]ROMAN_NUMERAL]...\n"
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
static char *pass_good_roman_numeral(char *roman_numeral)
{
    char *result;

    if (roman_numeral[0] != 'M')
        result = add_roman_numerals(roman_numeral, "I");
    else
        result = subtract_roman_numerals(roman_numeral, "I");

    return (result != NULL) ? roman_numeral : NULL;
}

struct main_return_struct *kinda_main(int argc, char *argv[])
{
    int i;
    char *buf;
    char sum[MAX_ROMAN_NUMERAL_LENGTH];
    char *result;
    static struct main_return_struct r;

    r.stderr = "";
    r.stdout = "";
    if (argc < 2) {
        r.stderr = get_usage(argc, argv);
        r.exit_status = EXIT_FAILURE;
        return &r;
    }
    r.exit_status = EXIT_SUCCESS; // Innocent until found otherwise.

    buf = malloc(argc * MAX_LINE_LENGTH);
    buf[0] = '\0';
    for (i = 1; i < argc; i++) {
        char *operand = argv[i];

        if (i == 1) {
            result = pass_good_roman_numeral(operand);
        } else {
            if (operand[0] == '-')
                result = subtract_roman_numerals(sum, operand+1);
            else
                result = add_roman_numerals(sum, operand);
        }
        strcpy(
            sum,
            ((result != NULL) ? result : "ERRATUM")
        );
        snprintf(buf + strlen(buf), MAX_LINE_LENGTH, "%s %s\n", argv[i], sum);
        if (result == NULL) {
            r.exit_status = EXIT_FAILURE;
            break;
        }
    }

    r.stdout = buf;
    return &r;
}

int MAIN_FUNCTION(int argc, char *argv[])
{
    struct main_return_struct *r;

    r = kinda_main(argc, argv);
    if (*r->stdout != '\0')
        printf("%s", r->stdout);
    if (*r->stderr != '\0')
        fprintf(stderr, "%s", r->stderr);

    exit(r->exit_status);
}
