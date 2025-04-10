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

Test(my_printf, test_hex_zero, .init = redirect_all_std)
{
    my_printf("Hello, %x!\n", 0);
    cr_assert_stdout_eq_str("Hello, 0!\n");
}

Test(my_printf, test_hex, .init = redirect_all_std)
{
    my_printf("Hello, %x!\n", 42);
    cr_assert_stdout_eq_str("Hello, 2a!\n");
}

Test(my_printf, test_hexmaj_zero, .init = redirect_all_std)
{
    my_printf("Hello, %X!\n", 0);
    cr_assert_stdout_eq_str("Hello, 0!\n");
}

Test(my_printf, test_hexmaj, .init = redirect_all_std)
{
    my_printf("Hello, %X!\n", 42);
    cr_assert_stdout_eq_str("Hello, 2A!\n");
}

Test(my_printf, test_octal_zero, .init = redirect_all_std)
{
    my_printf("Hello, %o!\n", 0);
    cr_assert_stdout_eq_str("Hello, 0!\n");
}

Test(my_printf, test_octal, .init = redirect_all_std)
{
    my_printf("Hello, %o!\n", 42);
    cr_assert_stdout_eq_str("Hello, 52!\n");
}

Test(my_printf, test_binary_zero, .init = redirect_all_std)
{
    my_printf("Hello, %b!\n", 0);
    cr_assert_stdout_eq_str("Hello, 0!\n");
}

Test(my_printf, test_binary, .init = redirect_all_std)
{
    my_printf("Hello, %b!\n", 42);
    cr_assert_stdout_eq_str("Hello, 101010!\n");
}
