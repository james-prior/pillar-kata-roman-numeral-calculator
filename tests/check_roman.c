#include <stdlib.h>
#include <check.h>
#include "../src/roman.h"

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(*(x)))

START_TEST(test_new_roman)
{
    struct example_struct {
        char *roman_numeral;
        unsigned value;
    };
    struct example_struct good_examples[] = {
        {"I", 1},
        {"II", 2},
        {"III", 3},
        {"V", 5},
        {"VI", 6},
        {"VII", 7},
        {"VIII", 8},
        {"X", 10},
        {"XI", 11},
        {"XII", 12},
        {"XIII", 13},
        {"XV", 15},
        {"XVI", 16},
        {"XVII", 17},
        {"XVIII", 18},
        {"XX", 20},
        {"XXX", 30},
        {"XXXVIII", 38},
        {"L", 50},
        {"LVI", 56},
        {"LXV", 65},
        {"LXVIII", 68},
        {"LXXXIII", 83},
        {"C", 100},
        {"CXXIII", 123},
        {"CC", 200},
        {"CCC", 300},
        {"CCCLXXXIII", 383},
        {"D", 500},
        {"DLXVII", 567},
        {"DCLXXVIII", 678},
        {"DCCCLXXXVIII", 888},
        {"M", 1000},
        {"MDCCCLXXXIII", 1883},
        {"MM", 2000},
        {"MMM", 3000},
        {"MMMCCX", 3210},
        {"MMMDCCCLXXXIII", 3883},
    };
    int i;

    struct example_struct *p;
    struct roman_struct *r;

    for (i = 0; i < ARRAY_LENGTH(good_examples); i++) {
        p = &good_examples[i];

        r = new_roman(p->roman_numeral);
        ck_assert_int_eq(get_roman_value(r), p->value);
        free_roman(r);
    }
}
END_TEST

Suite *roman_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_new_roman);
    suite_add_tcase(s, tc_core);

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
