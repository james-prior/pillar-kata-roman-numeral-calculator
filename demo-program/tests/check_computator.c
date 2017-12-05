#include <stdlib.h>
#include <check.h>
#include "../src/computator.h"

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(*(x)))

struct example_struct {
    int argc;
    char **argv;
    int expected_exit_status;
    char *expected_string;
};
char *hello_argv[] = {"hello"};
char *world_i_argv[] = {"world", "I"};
char *world_hello_argv[] = {"world", "HELLO"};
char *computator_i_i_argv[] = {"computator", "I", "I"};
char *computator_ii_iii_vi_argv[] = {"computator", "II", "III", "VI"};
char *computator_3998_1_argv[] = {"computator", "MMMCMXCVIII", "I"};
char *computator_mm_mm_mmm_argv[] = {"computator", "MM", "MM", "MMM"};
char *computator___argv[] = {"computator", "", ""};
char *computator_hello_i_argv[] = {"computator", "hello", "I"};
char *computator_i_robot_argv[] = {"computator", "I", "ROBOT"};
char *computator_mm_ni_argv[] = {"computator", "M", "-I"};
char *computator_3999_ni_argv[] = {"computator", "MMMCMXCIX", "-I"};
char *computator_i_ni_argv[] = {"computator", "I", "-I"};
char *computator_i_nm_argv[] = {"computator", "I", "-M"};
char *computator_add_and_sub_argv[] = {
    "computator",
    "M", "-D", "C", "-L", "X", "-V", "I", "-DL", "-V", "MCMXCVIII", "MM", "I"
};
char *computator_i_iiiii_i_argv[] = {
    "computator",
    "I",
    "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII"
    "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII",
    "I"
};
static const struct example_struct examples[] = {
    // Test usage.
    {ARRAY_LENGTH(hello_argv), hello_argv,
        EXIT_FAILURE, (
            "USAGE:\n"
            "    hello ROMAN_NUMERAL [[-]ROMAN_NUMERAL]...\n"
            "\n"
            "DESCRIPTION:\n"
            "    Adds roman numerals, showing intermediate sums.\n"
            "    Roman numerals prefixed with a '-' are subtracted.\n"
    )},
    // Test single argument.
    {ARRAY_LENGTH(world_i_argv), world_i_argv,
        EXIT_SUCCESS, (
            "I I\n"
    )},
    {ARRAY_LENGTH(world_hello_argv), world_hello_argv,
        EXIT_FAILURE, (
            "HELLO ERRATUM\n"
    )},
    // Test addition.
    {ARRAY_LENGTH(computator_i_i_argv), computator_i_i_argv,
        EXIT_SUCCESS, (
            "I I\n"
            "I II\n"
    )},
    {ARRAY_LENGTH(computator_ii_iii_vi_argv), computator_ii_iii_vi_argv,
        EXIT_SUCCESS, (
            "II II\n"
            "III V\n"
            "VI XI\n"
    )},
    {ARRAY_LENGTH(computator_3998_1_argv), computator_3998_1_argv,
        EXIT_SUCCESS, (
            "MMMCMXCVIII MMMCMXCVIII\n"
            "I MMMCMXCIX\n"
    )},
    // Test overflow with valid roman numerals.
    {ARRAY_LENGTH(computator_mm_mm_mmm_argv), computator_mm_mm_mmm_argv,
        EXIT_FAILURE, (
            "MM MM\n"
            "MM ERRATUM\n"
    )},
    // Test invalid roman numerals.
    {ARRAY_LENGTH(computator___argv), computator___argv,
        EXIT_FAILURE, (
            " ERRATUM\n"
    )},
    {ARRAY_LENGTH(computator_hello_i_argv), computator_hello_i_argv,
        EXIT_FAILURE, (
            "hello ERRATUM\n"
    )},
    {ARRAY_LENGTH(computator_i_robot_argv), computator_i_robot_argv,
        EXIT_FAILURE, (
            "I I\n"
            "ROBOT ERRATUM\n"
    )},
    // Test subtraction.
    {ARRAY_LENGTH(computator_mm_ni_argv), computator_mm_ni_argv,
        EXIT_SUCCESS, (
            "M M\n"
            "-I CMXCIX\n"
    )},
    {ARRAY_LENGTH(computator_3999_ni_argv), computator_3999_ni_argv,
        EXIT_SUCCESS, (
            "MMMCMXCIX MMMCMXCIX\n"
            "-I MMMCMXCVIII\n"
    )},
    // Test bad subtraction.
    {ARRAY_LENGTH(computator_i_ni_argv), computator_i_ni_argv,
        EXIT_FAILURE, (
            "I I\n"
            "-I ERRATUM\n"
    )},
    {ARRAY_LENGTH(computator_i_nm_argv), computator_i_nm_argv,
        EXIT_FAILURE, (
            "I I\n"
            "-M ERRATUM\n"
    )},
    // Test addition and subtraction.
    {ARRAY_LENGTH(computator_add_and_sub_argv), computator_add_and_sub_argv,
        EXIT_FAILURE, (
            "M M\n"
            "-D D\n"
            "C DC\n"
            "-L DL\n"
            "X DLX\n"
            "-V DLV\n"
            "I DLVI\n"
            "-DL VI\n"
            "-V I\n"
            "MCMXCVIII MCMXCIX\n"
            "MM MMMCMXCIX\n"
            "I ERRATUM\n"
    )},
    // Test long argument.
    {ARRAY_LENGTH(computator_i_iiiii_i_argv), computator_i_iiiii_i_argv,
        EXIT_FAILURE, (
            "I I\n"
            "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII"
            "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII"
    )},
};
START_TEST(test_roman_numeral_calculator)
{
    const struct example_struct *p;
    struct main_return_struct *r;

    p = &examples[_i];
    r = kinda_main(p->argc, p->argv);
    ck_assert_int_eq(r->exit_status, p->expected_exit_status);
    ck_assert_str_eq(r->stdout, p->expected_string);
}
END_TEST

Suite *roman_numeral_calculator_suite(void)
{
    Suite *s;
    TCase *tc_math;

    s = suite_create("Roman Numeral Calculator");

    tc_math = tcase_create("calculator");

    tcase_add_loop_test(
        tc_math, test_roman_numeral_calculator,
        0, ARRAY_LENGTH(examples)
    );

    suite_add_tcase(s, tc_math);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = roman_numeral_calculator_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
