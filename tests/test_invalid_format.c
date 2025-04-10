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

Test(my_printf, test_invalid_format, .init = redirect_all_std)
{
    my_printf("Hello, %z!\n");
    cr_assert_stdout_eq_str("Hello, %z!\n");
}

Test(my_printf, test_invalid_format_2, .init = redirect_all_std)
{
    my_printf("Hello, %zz!\n", "world");
    cr_assert_stdout_eq_str("Hello, %zz!\n");
}

Test(my_printf, test_invalid_format_3, .init = redirect_all_std)
{
    my_printf("Hello, %zzz!\n", "world");
    cr_assert_stdout_eq_str("Hello, %zzz!\n");
}

Test(my_printf, test_invalid_format_4, .init = redirect_all_std)
{
    my_printf("Hello, %zzzz!\n", "world");
    cr_assert_stdout_eq_str("Hello, %zzzz!\n");
}
