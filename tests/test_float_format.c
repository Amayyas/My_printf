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

Test(my_printf, test_float_zero, .init = redirect_all_std)
{
    my_printf("Hello, %f!\n", 0.);
    cr_assert_stdout_eq_str("Hello, 0.000000!\n");
}

Test(my_printf, test_float, .init = redirect_all_std)
{
    my_printf("Hello, %f!\n", 42.42);
    cr_assert_stdout_eq_str("Hello, 42.420000!\n");
}

Test(my_printf, test_float_without_decimal, .init = redirect_all_std)
{
    my_printf("Hello, %f!\n", 42.);
    cr_assert_stdout_eq_str("Hello, 42.000000!\n");
}

Test(my_printf, test_float_maj, .init = redirect_all_std)
{
    my_printf("Hello, %F!\n", 42.42);
    cr_assert_stdout_eq_str("Hello, 42.420000!\n");
}

Test(my_printf, test_float_maj_without_decimal, .init = redirect_all_std)
{
    my_printf("Hello, %F!\n", 42.);
    cr_assert_stdout_eq_str("Hello, 42.000000!\n");
}

Test(my_printf, test_float_negative, .init = redirect_all_std)
{
    my_printf("Hello, %f!\n", -42.42);
    cr_assert_stdout_eq_str("Hello, -42.420000!\n");
}

Test(my_printf, test_float_negative_without_decimal, .init = redirect_all_std)
{
    my_printf("Hello, %f!\n", -42.);
    cr_assert_stdout_eq_str("Hello, -42.000000!\n");
}

Test(my_printf, test_float_negative_zero, .init = redirect_all_std)
{
    my_printf("Hello, %f!\n", -0.);
    cr_assert_stdout_eq_str("Hello, -0.000000!\n");
}

Test(my_printf, test_float_rounding_edge_case, .init = redirect_all_std)
{
    my_printf("Hello, %f!\n", 1.9999999);
    cr_assert_stdout_eq_str("Hello, 2.000000!\n");
}
