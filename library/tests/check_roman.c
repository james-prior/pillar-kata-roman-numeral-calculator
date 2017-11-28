#include <stdlib.h>
#include <check.h>
#include "../src/roman.h"

#define ARRAY_LENGTH(x) ((int)(sizeof(x) / sizeof(*(x))))

struct add_good_example_struct {
    // all are Roman numerals.
    char *addend1;
    char *addend2;
    char *expected_sum;
};
static const struct add_good_example_struct add_good_examples[] = {
    {"I", "I", "II"},
    {"I", "II", "III"},
    {"II", "III", "V"},
    {"III", "V", "VIII"},
    {"V", "VIII", "XIII"},
    {"VIII", "XIII", "XXI"},
    {"XIII", "XXI", "XXXIV"},
    {"XXI", "XXXIV", "LV"},
    {"XXXIV", "LV", "LXXXIX"},
    {"LV", "LXXXIX", "CXLIV"},
    {"LXXXIX", "CXLIV", "CCXXXIII"},
    {"CXLIV", "CCXXXIII", "CCCLXXVII"},
    {"CCXXXIII", "CCCLXXVII", "DCX"},
    {"CCCLXXVII", "DCX", "CMLXXXVII"},
    {"DCX", "CMLXXXVII", "MDXCVII"},
    {"CMLXXXVII", "MDXCVII", "MMDLXXXIV"},
    {"MMMCMXCVIII", "I", "MMMCMXCIX"},
    // Trying to test all roman digits.
    {"CXXIII", "CXI", "CCXXXIV"},
    {"CXI", "CCXXXIV", "CCCXLV"},
    {"CCCXLV", "CXI", "CDLVI"},
    {"CXI", "CDLVI", "DLXVII"},
    {"DLXVII", "CXI", "DCLXXVIII"},
    {"CXI", "DCLXXVIII", "DCCLXXXIX"},
    {"DCCLXXXIX", "CI", "DCCCXC"},
    {"DCCCXC", "XI", "CMI"},
    {"CMI", "CXI", "MXII"},
    {"MXII", "MCXI", "MMCXXIII"},
    {"MCXI", "MMCXXIII", "MMMCCXXXIV"},
    // Test many roman numerals (math is trivial).
    {"I", "I", "II"},
    {"II", "I", "III"},
    {"III", "I", "IV"},
    {"IV", "I", "V"},
    {"V", "I", "VI"},
    {"VI", "I", "VII"},
    {"VII", "I", "VIII"},
    {"VIII", "I", "IX"},
    {"IX", "I", "X"},
    {"X", "I", "XI"},
    {"XI", "I", "XII"},
    {"XII", "I", "XIII"},
    {"XIII", "I", "XIV"},
    {"XIV", "I", "XV"},
    {"XV", "I", "XVI"},
    {"XVI", "I", "XVII"},
    {"XVII", "I", "XVIII"},
    {"XVIII", "I", "XIX"},
    {"XIX", "I", "XX"},
    {"XX", "I", "XXI"},
    {"XXIX", "I", "XXX"},
    {"XXX", "I", "XXXI"},
    {"XXXVIII", "I", "XXXIX"},
    {"XL", "I", "XLI"},
    {"XLI", "I", "XLII"},
    {"XLIV", "I", "XLV"},
    {"XLIX", "I", "L"},
    {"L", "I", "LI"},
    {"LVI", "I", "LVII"},
    {"LXV", "I", "LXVI"},
    {"LXVIII", "I", "LXIX"},
    {"LXXIV", "I", "LXXV"},
    {"LXXXIII", "I", "LXXXIV"},
    {"LXXXIX", "I", "XC"},
    {"XCII", "I", "XCIII"},
    {"XCIX", "I", "C"},
    {"C", "I", "CI"},
    {"CXXIII", "I", "CXXIV"},
    {"CXCIX", "I", "CC"},
    {"CC", "I", "CCI"},
    {"CCXXXIV", "I", "CCXXXV"},
    {"CCC", "I", "CCCI"},
    {"CCCXLV", "I", "CCCXLVI"},
    {"CCCLXXXIII", "I", "CCCLXXXIV"},
    {"CDLVI", "I", "CDLVII"},
    {"CDXCIX", "I", "D"},
    {"D", "I", "DI"},
    {"DLXVII", "I", "DLXVIII"},
    {"DCLXXVIII", "I", "DCLXXIX"},
    {"DCCLXXXIX", "I", "DCCXC"},
    {"DCCCLXXXVIII", "I", "DCCCLXXXIX"},
    {"DCCCXC", "I", "DCCCXCI"},
    {"CMI", "I", "CMII"},
    {"CMXCIX", "I", "M"},
    {"M", "I", "MI"},
    {"MXCVIII", "I", "MXCIX"},
    {"MDCCCLXXXIII", "I", "MDCCCLXXXIV"},
    {"MM", "I", "MMI"},
    {"MMCIX", "I", "MMCX"},
    {"MMM", "I", "MMMI"},
    {"MMMCCX", "I", "MMMCCXI"},
    {"MMMDCCCLXXXIII", "I", "MMMDCCCLXXXIV"},
    // Test sum roman numerals. (focus is on rendering result)
    // {"I", "I", "I"},
    {"I", "I", "II"},
    {"II", "I", "III"},
    {"III", "I", "IV"},
    {"IV", "I", "V"},
    {"V", "I", "VI"},
    {"VI", "I", "VII"},
    {"VII", "I", "VIII"},
    {"VIII", "I", "IX"},
    {"IX", "I", "X"},
    {"X", "I", "XI"},
    {"XI", "I", "XII"},
    {"XII", "I", "XIII"},
    {"XIII", "I", "XIV"},
    {"XIV", "I", "XV"},
    {"XV", "I", "XVI"},
    {"XVI", "I", "XVII"},
    {"XVII", "I", "XVIII"},
    {"XVIII", "I", "XIX"},
    {"XIX", "I", "XX"},
    {"XXVIII", "I", "XXIX"},
    {"XXIX", "I", "XXX"},
    {"XXXVII", "I", "XXXVIII"},
    {"XXXIX", "I", "XL"},
    {"XL", "I", "XLI"},
    {"XLIII", "I", "XLIV"},
    {"XLVIII", "I", "XLIX"},
    {"XLIX", "I", "L"},
    {"LV", "I", "LVI"},
    {"LXIV", "I", "LXV"},
    {"LXVII", "I", "LXVIII"},
    {"LXXIII", "I", "LXXIV"},
    {"LXXXII", "I", "LXXXIII"},
    {"LXXXVIII", "I", "LXXXIX"},
    {"XCI", "I", "XCII"},
    {"XCVIII", "I", "XCIX"},
    {"XCIX", "I", "C"},
    {"CXXII", "I", "CXXIII"},
    {"CXCVIII", "I", "CXCIX"},
    {"CXCIX", "I", "CC"},
    {"CCXXXIII", "I", "CCXXXIV"},
    {"CCXCIX", "I", "CCC"},
    {"CCCXLIV", "I", "CCCXLV"},
    {"CCCLXXXII", "I", "CCCLXXXIII"},
    {"CDLV", "I", "CDLVI"},
    {"CDXCVIII", "I", "CDXCIX"},
    {"CDXCIX", "I", "D"},
    {"DLXVI", "I", "DLXVII"},
    {"DCLXXVII", "I", "DCLXXVIII"},
    {"DCCLXXXVIII", "I", "DCCLXXXIX"},
    {"DCCCLXXXVII", "I", "DCCCLXXXVIII"},
    {"DCCCLXXXIX", "I", "DCCCXC"},
    {"CM", "I", "CMI"},
    {"CMXCVIII", "I", "CMXCIX"},
    {"CMXCIX", "I", "M"},
    {"MXCVII", "I", "MXCVIII"},
    {"MDCCCLXXXII", "I", "MDCCCLXXXIII"},
    {"MCMXCIX", "I", "MM"},
    {"MMCVIII", "I", "MMCIX"},
    {"MMCMXCIX", "I", "MMM"},
    {"MMMCCIX", "I", "MMMCCX"},
    {"MMMDCCCLXXXII", "I", "MMMDCCCLXXXIII"},
    {"MMMCMXCVIII", "I", "MMMCMXCIX"},
};
START_TEST(test_add_roman_numerals)
{
    const struct add_good_example_struct *p;
    char *result;

    p = &add_good_examples[_i];

    result = add_roman_numerals(p->addend1, p->addend2);
    ck_assert_str_eq(result, p->expected_sum);
}
END_TEST

struct sub_good_example_struct {
    // all are Roman numerals.
    char *minuend;
    char *subtrahend;
    char *expected_difference;
};
static const struct sub_good_example_struct sub_good_examples[] = {
    {"II", "I", "I"},
    {"III", "II", "I"},
    {"V", "III", "II"},
    {"VIII", "V", "III"},
    {"XIII", "VIII", "V"},
    {"XXI", "XIII", "VIII"},
    {"XXXIV", "XXI", "XIII"},
    {"LV", "XXXIV", "XXI"},
    {"LXXXIX", "LV", "XXXIV"},
    {"CXLIV", "LXXXIX", "LV"},
    {"CCXXXIII", "CXLIV", "LXXXIX"},
    {"CCCLXXVII", "CCXXXIII", "CXLIV"},
    {"DCX", "CCCLXXVII", "CCXXXIII"},
    {"CMLXXXVII", "DCX", "CCCLXXVII"},
    {"MDXCVII", "CMLXXXVII", "DCX"},
    {"MMDLXXXIV", "MDXCVII", "CMLXXXVII"},
    {"MMMCMXCIX", "I", "MMMCMXCVIII"},
};
START_TEST(test_subtract_roman_numerals)
{
    const struct sub_good_example_struct *p;
    char *result;

    p = &sub_good_examples[_i];

    result = subtract_roman_numerals(p->minuend, p->subtrahend);
    ck_assert_str_eq(result, p->expected_difference);
}
END_TEST

// struct add_bad_example_struct {
//     // all are Roman numerals.
//     char *addend1;
//     char *addend2;
// };
// static const struct add_bad_example_struct add_bad_examples[] = {
//     // Sum is too big even though addends are valid roman numerals.
//     {"MM", "MM"},
//     {"MMMCMXCIX", "I"},
//     {"I", "MMMCMXCIX"},
//     {"MMMCMXCIX", "MMMCMXCIX"},
//     // empty string
//     {"", ""},
//     // Roman letter repeated too many times consecutively.
//     {"IIII", "IIII"},
//     {"IIIII", "IIIII"},
//     {"VV", "VV"},
//     {"CCCC", "CCCC"},
//     {"DD", "DD"},
//     // Subtractive roman letter repeated too many times consecutively.
//     {"IIV", "IIV"},
//     {"IIIV", "IIIV"},
//     {"IIIIV", "IIIIV"},
//     {"IIX", "IIX"},
//     {"XXL", "XXL"},
//     {"XXC", "XXC"},
//     {"CCD", "CCD"},
//     {"CCM", "CCM"},
//     // invalid subtractive combinations
//     {"VX", "VX"},
//     {"IL", "IL"},
//     {"VL", "VL"},
//     {"IC", "IC"},
//     {"VC", "VC"},
//     {"LC", "LC"},
//     {"ID", "ID"},
//     {"VD", "VD"},
//     {"XD", "XD"},
//     {"LD", "LD"},
//     {"IM", "IM"},
//     {"VM", "VM"},
//     {"XM", "XM"},
//     {"LM", "LM"},
//     {"DM", "DM"},
//     // invalid letters
//     {"HELLO", "WORLD"},
//     {"i", "i"}, // lowercase
//     // Number is too large.
//     {"MMMM", "MMMM"},
// };
// START_TEST(test_bad_addition_roman_numerals)
// {
//     const struct add_bad_example_struct *p;
//     roman_numeral sum;
//     roman_numeral *result;
// 
//     p = &add_bad_examples[_i];
// 
//     result = add_roman_numerals(&sum, p->addend1, p->addend2);
//     ck_assert_ptr_eq((char *)result, NULL);
// }
// END_TEST
// 
// struct bad_sub_example_struct {
//     // all are Roman numerals.
//     char *minuend;
//     char *subtrahend;
// };
// static const struct bad_sub_example_struct sub_bad_examples[] = {
//     {"I", "I"},
//     {"I", "II"},
//     {"M", "MM"},
//     {"MMMCMXCVIII", "MMMCMXCIX"},
//     {"MMMCMXCIX", "MMMCMXCIX"},
// };
// START_TEST(test_bad_subtract_roman_numerals)
// {
//     const struct bad_sub_example_struct *p;
//     roman_numeral difference;
//     roman_numeral *result;
// 
//     p = &sub_bad_examples[_i];
// 
//     result = subtract_roman_numerals(&difference, p->minuend, p->subtrahend);
//     ck_assert_ptr_eq((char *)result, NULL);
// }
// END_TEST

Suite *roman_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman");

    tc_core = tcase_create("create");

    tcase_add_loop_test(
        tc_core, test_add_roman_numerals,
        0, ARRAY_LENGTH(add_good_examples)
    );
    tcase_add_loop_test(
        tc_core, test_subtract_roman_numerals,
        0, ARRAY_LENGTH(sub_good_examples)
    );
    // tcase_add_loop_test(
    //     tc_core, test_bad_addition_roman_numerals,
    //     0, ARRAY_LENGTH(add_bad_examples));
    // tcase_add_loop_test(
    //     tc_core, test_bad_subtract_roman_numerals,
    //     0, ARRAY_LENGTH(sub_bad_examples)
    // );
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
