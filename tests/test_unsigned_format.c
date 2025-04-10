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

Test(my_printf, test_unsigned_zero, .init = redirect_all_std)
{
    my_printf("Hello, %u!\n", 0);
    cr_assert_stdout_eq_str("Hello, 0!\n");
}

Test(my_printf, test_unsigned, .init = redirect_all_std)
{
    my_printf("Hello, %u!\n", 42);
    cr_assert_stdout_eq_str("Hello, 42!\n");
}

Test(my_printf, test_unsigned_uint_max, .init = redirect_all_std)
{
    my_printf("Hello, %u!\n", UINT_MAX);
    cr_assert_stdout_eq_str("Hello, 4294967295!\n");
}

Test(my_printf, test_unsigned_uchar_max, .init = redirect_all_std)
{
    my_printf("Hello, %u!\n", UCHAR_MAX);
    cr_assert_stdout_eq_str("Hello, 255!\n");
}