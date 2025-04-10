/*
** EPITECH PROJECT, 2024
** test_edge_cases.c
** File description:
** Tests edge cases and complex scenarios for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <limits.h>
#include <float.h>
#include "my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, test_extreme_width, .init = redirect_all_std)
{
    my_printf("[%50d]", 12345);
    // Check that we have 45 spaces followed by 12345
    char expected[52] = {0};
    expected[0] = '[';
    for (int i = 1; i <= 45; i++)
        expected[i] = ' ';
    expected[46] = '1';
    expected[47] = '2';
    expected[48] = '3';
    expected[49] = '4';
    expected[50] = '5';
    expected[51] = ']';
    cr_assert_stdout_eq_str(expected);
}

Test(my_printf, test_multiple_formats, .init = redirect_all_std)
{
    my_printf("Int: %d, String: %s, Char: %c", 42, "test", 'X');
    cr_assert_stdout_eq_str("Int: 42, String: test, Char: X");
}

Test(my_printf, test_multiple_formats_with_flags, .init = redirect_all_std)
{
    my_printf("[%5d] [%-10s] [%+d] [%#x]", 123, "test", 456, 789);
    cr_assert_stdout_eq_str("[  123] [test      ] [+456] [0x315]");
}

Test(my_printf, test_undefined_behavior_null_string, .init = redirect_all_std)
{
    my_printf("%s", NULL);
    cr_assert_stdout_eq_str("(null)");
}

Test(my_printf, test_long_string, .init = redirect_all_std)
{
    char long_string[1000];
    for (int i = 0; i < 999; i++)
        long_string[i] = 'A' + (i % 26);
    long_string[999] = '\0';
    
    my_printf("%.50s", long_string);
    
    char expected[51] = {0};
    for (int i = 0; i < 50; i++)
        expected[i] = 'A' + (i % 26);
    
    cr_assert_stdout_eq_str(expected);
}

Test(my_printf, test_float_large_precision, .init = redirect_all_std)
{
    my_printf("%.12f", 12.34);
    cr_assert_stdout_eq_str("12.340000000000");
}

Test(my_printf, test_float_small_values, .init = redirect_all_std)
{
    my_printf("%.10f", 0.0000001);
    cr_assert_stdout_eq_str("0.0000001000");
}

Test(my_printf, test_float_large_values, .init = redirect_all_std)
{
    my_printf("%.1f", 1234567.89);
    cr_assert_stdout_eq_str("1234567.9");
}

Test(my_printf, test_float_very_small, .init = redirect_all_std)
{
    my_printf("%.20f", DBL_MIN);
    // Not asserting exact output as it's platform dependent
    // Just make sure it doesn't crash
}

Test(my_printf, test_float_very_large, .init = redirect_all_std)
{
    my_printf("%.2f", DBL_MAX);
    // Not asserting exact output as it's platform dependent
    // Just make sure it doesn't crash
}

Test(my_printf, test_consecutive_percent, .init = redirect_all_std)
{
    my_printf("%%%%%%%%%%");
    cr_assert_stdout_eq_str("%%%%%");
}

Test(my_printf, test_mixed_length_modifiers, .init = redirect_all_std)
{
    long l_val = LONG_MAX;
    short s_val = SHRT_MAX;
    
    my_printf("long: %ld, short: %hd", l_val, s_val);
    cr_assert_stdout_eq_str("long: 9223372036854775807, short: 32767");
}
