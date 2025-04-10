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

Test(my_printf, test_long_zero, .init = redirect_all_std)
{
    my_printf("Hello, %ld!\n", 0);
    cr_assert_stdout_eq_str("Hello, 0!\n");
}

Test(my_printf, test_long, .init = redirect_all_std)
{
    my_printf("Hello, %ld!\n", 42);
    cr_assert_stdout_eq_str("Hello, 42!\n");
}

Test(my_printf, test_long_max, .init = redirect_all_std)
{
    my_printf("Hello, %ld!\n", LONG_MAX);
    cr_assert_stdout_eq_str("Hello, 9223372036854775807!\n");
}

Test(my_printf, test_long_min, .init = redirect_all_std)
{
    my_printf("Hello, %ld!\n", LONG_MIN);
    cr_assert_stdout_eq_str("Hello, -9223372036854775808!\n");
}

Test(my_printf, test_long_negative, .init = redirect_all_std)
{
    my_printf("Hello, %ld!\n", -1234567890L);
    cr_assert_stdout_eq_str("Hello, -1234567890!\n");
}

Test(my_printf, test_unsigned_long_zero, .init = redirect_all_std)
{
    my_printf("Hello, %lu!\n", 0);
    cr_assert_stdout_eq_str("Hello, 0!\n");
}

Test(my_printf, test_unsigned_long, .init = redirect_all_std)
{
    my_printf("Hello, %lu!\n", 42);
    cr_assert_stdout_eq_str("Hello, 42!\n");
}

Test(my_printf, test_unsigned_long_max, .init = redirect_all_std)
{
    my_printf("Hello, %lu!\n", ULONG_MAX);
    cr_assert_stdout_eq_str("Hello, 18446744073709551615!\n");
}

Test(my_printf, test_long_long_zero, .init = redirect_all_std)
{
    my_printf("Hello, %lld!\n", 0);
    cr_assert_stdout_eq_str("Hello, 0!\n");
}

Test(my_printf, test_long_long, .init = redirect_all_std)
{
    my_printf("Hello, %lld!\n", 42);
    cr_assert_stdout_eq_str("Hello, 42!\n");
}

Test(my_printf, test_long_long_max, .init = redirect_all_std)
{
    my_printf("Hello, %lld!\n", LLONG_MAX);
    cr_assert_stdout_eq_str("Hello, 9223372036854775807!\n");
}

Test(my_printf, test_long_long_min, .init = redirect_all_std)
{
    my_printf("Hello, %lld!\n", LLONG_MIN);
    cr_assert_stdout_eq_str("Hello, -9223372036854775808!\n");
}

Test(my_printf, test_long_long_negative, .init = redirect_all_std)
{
    my_printf("Hello, %lld!\n", -1234567890123456789LL);
    cr_assert_stdout_eq_str("Hello, -1234567890123456789!\n");
}

Test(my_printf, test_unsigned_long_long_zero, .init = redirect_all_std)
{
    my_printf("Hello, %llu!\n", 0);
    cr_assert_stdout_eq_str("Hello, 0!\n");
}

Test(my_printf, test_unsigned_long_long, .init = redirect_all_std)
{
    my_printf("Hello, %llu!\n", 42);
    cr_assert_stdout_eq_str("Hello, 42!\n");
}

Test(my_printf, test_unsigned_long_long_max, .init = redirect_all_std)
{
    my_printf("Hello, %llu!\n", ULLONG_MAX);
    cr_assert_stdout_eq_str("Hello, 18446744073709551615!\n");
}
