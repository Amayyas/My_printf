/*
** EPITECH PROJECT, 2024
** my_put_float.c
** File description:
** Put float
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, test_null, .init = redirect_all_std)
{
    my_printf("");
    cr_assert_stdout_eq_str("");
}

Test(my_printf, test_no_format, .init = redirect_all_std)
{
    my_printf("Hello, !\n", "world");
    cr_assert_stdout_eq_str("Hello, !\n");
}

Test(my_printf, test_string, .init = redirect_all_std)
{
    my_printf("Hello, %s!\n", "world");
    cr_assert_stdout_eq_str("Hello, world!\n");
}

Test(my_printf, test_string_empty, .init = redirect_all_std)
{
    my_printf("Hello, %s!\n", "");
    cr_assert_stdout_eq_str("Hello, !\n");
}

Test(my_printf, test_int_d_zero, .init = redirect_all_std)
{
    my_printf("Hello, %d!\n", 0);
    cr_assert_stdout_eq_str("Hello, 0!\n");
}

Test(my_printf, test_int_d, .init = redirect_all_std)
{
    my_printf("Hello, %d!\n", 42);
    cr_assert_stdout_eq_str("Hello, 42!\n");
}

Test(my_printf, test_int_d_max, .init = redirect_all_std)
{
    my_printf("Hello, %d!\n", INT_MAX);
    cr_assert_stdout_eq_str("Hello, 2147483647!\n");
}

Test(my_printf, test_int_d_bit, .init = redirect_all_std)
{
    my_printf("Hello, %d!\n", CHAR_BIT);
    cr_assert_stdout_eq_str("Hello, 8!\n");
}

Test(my_printf, test_int_d_schar_min, .init = redirect_all_std)
{
    my_printf("Hello, %d!\n", SCHAR_MIN);
    cr_assert_stdout_eq_str("Hello, -128!\n");
}

Test(my_printf, test_int_d_schar_max, .init = redirect_all_std)
{
    my_printf("Hello, %d!\n", SCHAR_MAX);
    cr_assert_stdout_eq_str("Hello, 127!\n");
}

Test(my_printf, test_int_d_mb_len_max, .init = redirect_all_std)
{
    my_printf("Hello, %d!\n", MB_LEN_MAX);
    cr_assert_stdout_eq_str("Hello, 16!\n");
}

Test(my_printf, test_int_i_zero, .init = redirect_all_std)
{
    my_printf("Hello, %i!\n", 0);
    cr_assert_stdout_eq_str("Hello, 0!\n");
}

Test(my_printf, test_int_i, .init = redirect_all_std)
{
    my_printf("Hello, %i!\n", 42);
    cr_assert_stdout_eq_str("Hello, 42!\n");
}

Test(my_printf, test_int_i_max, .init = redirect_all_std)
{
    my_printf("Hello, %i!\n", INT_MAX);
    cr_assert_stdout_eq_str("Hello, 2147483647!\n");
}

Test(my_printf, test_int_i_bit, .init = redirect_all_std)
{
    my_printf("Hello, %i!\n", CHAR_BIT);
    cr_assert_stdout_eq_str("Hello, 8!\n");
}

Test(my_printf, test_int_i_schar_min, .init = redirect_all_std)
{
    my_printf("Hello, %i!\n", SCHAR_MIN);
    cr_assert_stdout_eq_str("Hello, -128!\n");
}

Test(my_printf, test_int_i_schar_max, .init = redirect_all_std)
{
    my_printf("Hello, %i!\n", SCHAR_MAX);
    cr_assert_stdout_eq_str("Hello, 127!\n");
}

Test(my_printf, test_int_i_mb_len_max, .init = redirect_all_std)
{
    my_printf("Hello, %i!\n", MB_LEN_MAX);
    cr_assert_stdout_eq_str("Hello, 16!\n");
}

Test(my_printf, test_char, .init = redirect_all_std)
{
    my_printf("Hello, %c!\n", 'c');
    cr_assert_stdout_eq_str("Hello, c!\n");
}

Test(my_printf, test_char_uppercase, .init = redirect_all_std)
{
    my_printf("Hello, %c!\n", 'C');
    cr_assert_stdout_eq_str("Hello, C!\n");
}

Test(my_printf, test_char_digit_zero, .init = redirect_all_std)
{
    my_printf("Hello, %c!\n", '0');
    cr_assert_stdout_eq_str("Hello, 0!\n");
}

Test(my_printf, test_char_digit, .init = redirect_all_std)
{
    my_printf("Hello, %c!\n", '7');
    cr_assert_stdout_eq_str("Hello, 7!\n");
}

Test(my_printf, test_char_special, .init = redirect_all_std)
{
    my_printf("Hello, %c!\n", '@');
    cr_assert_stdout_eq_str("Hello, @!\n");
}

Test(my_printf, test_char_newline, .init = redirect_all_std)
{
    my_printf("Hello, %c!\n", '\n');
    cr_assert_stdout_eq_str("Hello, \n!\n");
}

Test(my_printf, test_char_tab, .init = redirect_all_std)
{
    my_printf("Hello, %c!\n", '\t');
    cr_assert_stdout_eq_str("Hello, \t!\n");
}

Test(my_printf, test_normal_percentage, .init = redirect_all_std)
{
    my_printf("Hello, %%!\n");
    cr_assert_stdout_eq_str("Hello, %!\n");
}

Test(my_printf, test_invalid_percentage, .init = redirect_all_std)
{
    my_printf("Hello, %ladada!\n");
    cr_assert_stdout_eq_str("Hello, %ladada!\n");
}

Test(my_printf, test_invalid_format_z, .init = redirect_all_std)
{
    my_printf("Hello, %z!\n");
    cr_assert_stdout_eq_str("Hello, %z!\n");
}

Test(my_printf, test_invalid_format_lx, .init = redirect_all_std)
{
    my_printf("Hello, %lx!\n");
    cr_assert_stdout_eq_str("Hello, %lx!\n");
}

Test(my_printf, test_invalid_format_hf, .init = redirect_all_std)
{
    my_printf("Hello, %hf!\n");
    cr_assert_stdout_eq_str("Hello, %hf!\n");
}

Test(my_printf, test_invalid_format_lh, .init = redirect_all_std)
{
    my_printf("Hello, %lh!\n");
    cr_assert_stdout_eq_str("Hello, %lh!\n");
}

Test(my_printf, test_printf_empty_string, .init = redirect_all_std)
{
    my_printf("Hello, %s!\n", "");
    cr_assert_stdout_eq_str("Hello, !\n");
}
