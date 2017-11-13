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
        {"X", 10},
        {"XX", 20},
        {"XXX", 30},
        {"L", 50},
        {"C", 100},
        {"CC", 200},
        {"CCC", 300},
        {"D", 500},
        {"M", 1000},
        {"MM", 2000},
        {"MMM", 3000},
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
