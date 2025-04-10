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

Test(my_printf, test_ptr_zero, .init = redirect_all_std)
{
    my_printf("Hello, %p!\n", 0);
    cr_assert_stdout_eq_str("Hello, (nil)!\n");
}

Test(my_printf, test_ptr, .init = redirect_all_std)
{
    my_printf("Hello, %p!\n", 42);
    cr_assert_stdout_eq_str("Hello, 0x2a!\n");
}

Test(my_printf, test_ptr_into_int, .init = redirect_all_std)
{
    int nb;

    my_printf("Hello, %n!\n", &nb);
    cr_assert_eq(nb, 7);
}
