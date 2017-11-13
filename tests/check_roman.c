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
        {"I", 1U},
        {"II", 2U},
        {"III", 3U},
        {"IV", 4U},
        {"V", 5U},
        {"VI", 6U},
        {"VII", 7U},
        {"VIII", 8U},
        {"IX", 9U},
        {"X", 10U},
        {"XI", 11U},
        {"XII", 12U},
        {"XIII", 13U},
        {"XIV", 14U},
        {"XV", 15U},
        {"XVI", 16U},
        {"XVII", 17U},
        {"XVIII", 18U},
        {"XIX", 19U},
        {"XX", 20U},
        {"XXIX", 29U},
        {"XXX", 30U},
        {"XXXVIII", 38U},
        {"XL", 40U},
        {"XLI", 41U},
        {"XLIV", 44U},
        {"XLIX", 49U},
        {"L", 50U},
        {"LVI", 56U},
        {"LXV", 65U},
        {"LXVIII", 68U},
        {"LXXIV", 74U},
        {"LXXXIII", 83U},
        {"LXXXIX", 89U},
        {"XCII", 92U},
        {"XCIX", 99U},
        {"C", 100U},
        {"CXXIII", 123U},
        {"CXCIX", 199U},
        {"CC", 200U},
        {"CCXXXIV", 234U},
        {"CCC", 300U},
        {"CCCXLV", 345U},
        {"CCCLXXXIII", 383U},
        {"CDLVI", 456U},
        {"CDXCIX", 499U},
        {"D", 500U},
        {"DLXVII", 567U},
        {"DCLXXVIII", 678U},
        {"DCCLXXXIX", 789U},
        {"DCCCLXXXVIII", 888U},
        {"DCCCXC", 890U},
        {"CMI", 901U},
        {"CMXCIX", 999U},
        {"M", 1000U},
        {"MXCVIII", 1098U},
        {"MDCCCLXXXIII", 1883U},
        {"MM", 2000U},
        {"MMCIX", 2109U},
        {"MMM", 3000U},
        {"MMMCCX", 3210U},
        {"MMMDCCCLXXXIII", 3883U},
        {"MMMCMXCIX", 3999U},
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
