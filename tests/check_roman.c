#include <stdlib.h>
#include <check.h>
#include "../src/roman.h"

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(*(x)))

START_TEST(test_new_roman)
{
    struct example_struct {
        char *roman_numeral;
        unsigned expected_value;
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
        ck_assert_uint_eq(get_roman_value(r), p->expected_value);
        free_roman(r);
    }
}
END_TEST

START_TEST(test_new_roman_from_uint)
{
    struct example_struct {
        unsigned value; // Both input and expected output
    };
    struct example_struct examples[] = {
        {1U},
        {2U},
        {3998U},
        {3999U},
    };
    int i;

    struct example_struct *p;
    struct roman_struct *r;

    for (i = 0; i < ARRAY_LENGTH(examples); i++) {
        p = &examples[i];

        r = new_roman_from_uint(p->value);
        ck_assert_uint_eq(get_roman_value(r), p->value);
        free_roman(r);
    }
}
END_TEST

START_TEST(test_new_bad_roman)
{
    struct bad_example_struct {
        char *bad_roman_numeral;
    };
    struct bad_example_struct bad_examples[] = {
        // empty string
        {""},
        /* roman letter repeated too many times consecutively */
        {"IIII"},
        {"IIIII"},
        {"VV"},
        {"CCCC"},
        {"DD"},
        /* subtractive roman letter repeated too many times
        *  consecutively */
        {"IIV"},
        {"IIIV"},
        {"IIIIV"},
        {"IIX"},
        {"XXL"},
        {"XXC"},
        {"CCD"},
        {"CCM"},
        /* invalid subtractive combinations */
        {"VX"},
        {"IL"},
        {"VL"},
        {"IC"},
        {"VC"},
        {"LC"},
        {"ID"},
        {"VD"},
        {"XD"},
        {"LD"},
        {"LD"},
        {"IM"},
        {"VM"},
        {"XM"},
        {"LM"},
        {"DM"},
        // Invalid letters
        {"HELLO"},
        // number that is too large
        // {"MMMM"},
    };
    int i;

    struct bad_example_struct *p;
    struct roman_struct *r;

    for (i = 0; i < ARRAY_LENGTH(bad_examples); i++) {
        p = &bad_examples[i];

        r = new_roman(p->bad_roman_numeral);
        ck_assert_ptr_eq(r, NULL);
        if (r != NULL)
            free_roman(r);
    }
}
END_TEST

START_TEST(test_new_bad_roman_from_uint)
{
    struct example_struct {
        unsigned value; // Both input and expected output
    };
    struct example_struct bad_examples[] = {
        {0U},
        {4000U},
        {4001U},
        {(unsigned)-1},
    };
    int i;

    struct example_struct *p;
    struct roman_struct *r;

    for (i = 0; i < ARRAY_LENGTH(bad_examples); i++) {
        p = &bad_examples[i];

        r = new_roman_from_uint(p->value);
        ck_assert_ptr_eq(r, NULL);
        if (r != NULL)
            free_roman(r);
    }
}
END_TEST

START_TEST(test_print_roman)
{
    struct example_struct {
        unsigned value;
        char *expected_roman_numeral;
    };
    struct example_struct good_examples[] = {
        {1U, "I"},
        {2U, "II"},
        {3U, "III"},
        {4U, "IV"},
        {5U, "V"},
        {6U, "VI"},
        {7U, "VII"},
        {8U, "VIII"},
        {9U, "IX"},
        {10U, "X"},
        {11U, "XI"},
        {12U, "XII"},
        {13U, "XIII"},
        {14U, "XIV"},
        {15U, "XV"},
        {16U, "XVI"},
        {17U, "XVII"},
        {18U, "XVIII"},
        {19U, "XIX"},
        {20U, "XX"},
        {29U, "XXIX"},
        {30U, "XXX"},
        {38U, "XXXVIII"},
        {40U, "XL"},
        {41U, "XLI"},
        {44U, "XLIV"},
        {49U, "XLIX"},
        {50U, "L"},
        {56U, "LVI"},
        {65U, "LXV"},
        {68U, "LXVIII"},
        {74U, "LXXIV"},
        {83U, "LXXXIII"},
        {89U, "LXXXIX"},
        {92U, "XCII"},
        {99U, "XCIX"},
        {100U, "C"},
        {123U, "CXXIII"},
        {199U, "CXCIX"},
        {200U, "CC"},
        {234U, "CCXXXIV"},
        {300U, "CCC"},
        {345U, "CCCXLV"},
        {383U, "CCCLXXXIII"},
        {456U, "CDLVI"},
        {499U, "CDXCIX"},
        {500U, "D"},
        {567U, "DLXVII"},
        {678U, "DCLXXVIII"},
        {789U, "DCCLXXXIX"},
        {888U, "DCCCLXXXVIII"},
        {890U, "DCCCXC"},
        {901U, "CMI"},
        {999U, "CMXCIX"},
        {1000U, "M"},
        {1098U, "MXCVIII"},
        {1883U, "MDCCCLXXXIII"},
        {2000U, "MM"},
        {2109U, "MMCIX"},
        {3000U, "MMM"},
        {3210U, "MMMCCX"},
        {3883U, "MMMDCCCLXXXIII"},
        {3999U, "MMMCMXCIX"},
    };
    int i;

    struct example_struct *p;
    struct roman_struct *r;
    char *s;

    for (i = 0; i < ARRAY_LENGTH(good_examples); i++) {
        p = &good_examples[i];

        r = new_roman_from_uint(p->value);
        ck_assert_ptr_ne(r, NULL);
        s = print_roman(r);
        ck_assert_str_eq(s, p->expected_roman_numeral);
        free_roman(r);
    }
}
END_TEST

Suite *roman_suite(void)
{
    Suite *s;
    TCase *tc_core;
    TCase *tc_bad;
    TCase *tc_print;

    s = suite_create("Roman");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_new_roman);
    tcase_add_test(tc_core, test_new_roman_from_uint);
    suite_add_tcase(s, tc_core);

    /* print roman numerals */
    tc_print = tcase_create("print");

    tcase_add_test(tc_core, test_print_roman);
    suite_add_tcase(s, tc_print);

    /* bad test cases */
    tc_bad = tcase_create("bad");

    tcase_add_test(tc_bad, test_new_bad_roman);
    tcase_add_test(tc_bad, test_new_bad_roman_from_uint);
    suite_add_tcase(s, tc_bad);

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
