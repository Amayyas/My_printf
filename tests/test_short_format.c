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

Test(my_printf, test_short_zero, .init = redirect_all_std)
{
    my_printf("Hello, %hd!\n", 0);
    cr_assert_stdout_eq_str("Hello, 0!\n");
}

Test(my_printf, test_short, .init = redirect_all_std)
{
    my_printf("Hello, %hd!\n", 42);
    cr_assert_stdout_eq_str("Hello, 42!\n");
}

Test(my_printf, test_short_max, .init = redirect_all_std)
{
    my_printf("Hello, %hd!\n", SHRT_MAX);
    cr_assert_stdout_eq_str("Hello, 32767!\n");
}

Test(my_printf, test_short_min, .init = redirect_all_std)
{
    my_printf("Hello, %hd!\n", SHRT_MIN);
    cr_assert_stdout_eq_str("Hello, -32768!\n");
}

Test(my_printf, test_short_neg, .init = redirect_all_std)
{
    my_printf("Hello, %hd!\n", -20);
    cr_assert_stdout_eq_str("Hello, -20!\n");
}

Test(my_printf, test_unsigned_short_zero, .init = redirect_all_std)
{
    my_printf("Hello, %hu!\n", 0);
    cr_assert_stdout_eq_str("Hello, 0!\n");
}

Test(my_printf, test_unsigned_short, .init = redirect_all_std)
{
    my_printf("Hello, %hu!\n", 42);
    cr_assert_stdout_eq_str("Hello, 42!\n");
}

Test(my_printf, test_unsigned_short_max, .init = redirect_all_std)
{
    my_printf("Hello, %hu!\n", USHRT_MAX);
    cr_assert_stdout_eq_str("Hello, 65535!\n");
}
