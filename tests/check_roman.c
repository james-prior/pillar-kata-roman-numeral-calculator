#include <stdlib.h>
#include <check.h>
#include "../src/roman.h"

START_TEST(test_new_roman)
{
    struct roman_struct *r;

    r = new_roman("I");
    ck_assert_int_eq(get_roman_value(r), 1);
    free_roman(r);
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
