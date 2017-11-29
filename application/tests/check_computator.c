#include <stdlib.h>
#include <check.h>
#include "../src/computator.h"

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(*(x)))

struct add_good_example_struct {
    int argc;
    char **argv;
    char *expected_string;
};
char *hello_argv[] = {"hello"};
char *world_i_argv[] = {"world", "I"};
char *computator_i_i_argv[] = {"computator", "I", "I"};
char *computator_ii_iii_vi_argv[] = {"computator", "II", "III", "VI"};
char *computator_3998_1_argv[] = {"computator", "MMMCMXCVIII", "I"};
char *computator_mm_mm_mmm_argv[] = {"computator", "MM", "MM", "MMM"};
static const struct add_good_example_struct add_good_examples[] = {
    {ARRAY_LENGTH(hello_argv), hello_argv, (
        "USAGE:\n"
        "    hello ROMAN_NUMERAL [-]ROMAN_NUMERAL [[-]ROMAN_NUMERAL]...\n"
        "\n"
        "DESCRIPTION:\n"
        "    Adds roman numerals, showing intermediate sums.\n"
        "    Roman numerals prefixed with a '-' are subtracted.\n"
    )},
    {ARRAY_LENGTH(world_i_argv), world_i_argv, (
        "USAGE:\n"
        "    world ROMAN_NUMERAL [-]ROMAN_NUMERAL [[-]ROMAN_NUMERAL]...\n"
        "\n"
        "DESCRIPTION:\n"
        "    Adds roman numerals, showing intermediate sums.\n"
        "    Roman numerals prefixed with a '-' are subtracted.\n"
    )},
    {ARRAY_LENGTH(computator_i_i_argv), computator_i_i_argv, (
        "I I\n"
        "I II\n"
    )},
    {ARRAY_LENGTH(computator_ii_iii_vi_argv), computator_ii_iii_vi_argv, (
        "II II\n"
        "III V\n"
        "VI XI\n"
    )},
    {ARRAY_LENGTH(computator_3998_1_argv), computator_3998_1_argv, (
        "MMMCMXCVIII MMMCMXCVIII\n"
        "I MMMCMXCIX\n"
    )},
    {ARRAY_LENGTH(computator_mm_mm_mmm_argv), computator_mm_mm_mmm_argv, (
        "MM MM\n"
        "MM ERRATUM\n"
    )},
};
START_TEST(test_add_roman_numerals)
{
    const struct add_good_example_struct *p;

    p = &add_good_examples[_i];
    ck_assert_str_eq(meat(p->argc, p->argv), p->expected_string);
}
END_TEST

Suite *roman_suite(void)
{
    Suite *s;
    TCase *tc_math;

    s = suite_create("Roman");

    /* do roman numeral arithment */
    tc_math = tcase_create("arithmetic");

    tcase_add_loop_test(
        tc_math, test_add_roman_numerals,
        0, ARRAY_LENGTH(add_good_examples)
    );

    suite_add_tcase(s, tc_math);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = roman_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
