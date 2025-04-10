/*
** EPITECH PROJECT, 2024
** test_format_combinations.c
** File description:
** Tests for combined format flags in my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, test_width_precision_int, .init = redirect_all_std)
{
    my_printf("[%5.2d]", 42);
    cr_assert_stdout_eq_str("[   42]");
}

Test(my_printf, test_width_precision_string, .init = redirect_all_std)
{
    my_printf("[%8.3s]", "hello");
    cr_assert_stdout_eq_str("[     hel]");
}

Test(my_printf, test_left_justify_width, .init = redirect_all_std)
{
    my_printf("[%-5d]", 42);
    cr_assert_stdout_eq_str("[42   ]");
}

Test(my_printf, test_zero_padding_width, .init = redirect_all_std)
{
    my_printf("[%05d]", 42);
    cr_assert_stdout_eq_str("[00042]");
}

Test(my_printf, test_plus_flag, .init = redirect_all_std)
{
    my_printf("[%+d]", 42);
    cr_assert_stdout_eq_str("[+42]");
}

Test(my_printf, test_space_flag, .init = redirect_all_std)
{
    my_printf("[% d]", 42);
    cr_assert_stdout_eq_str("[ 42]");
}

Test(my_printf, test_zero_plus_width, .init = redirect_all_std)
{
    my_printf("[%+05d]", 42);
    cr_assert_stdout_eq_str("[+0042]");
}

Test(my_printf, test_hash_with_octal, .init = redirect_all_std)
{
    my_printf("[%#o]", 42);
    cr_assert_stdout_eq_str("[052]");
}

Test(my_printf, test_hash_with_hex, .init = redirect_all_std)
{
    my_printf("[%#x]", 42);
    cr_assert_stdout_eq_str("[0x2a]");
}

Test(my_printf, test_hash_with_hex_maj, .init = redirect_all_std)
{
    my_printf("[%#X]", 42);
    cr_assert_stdout_eq_str("[0x2A]");
}

Test(my_printf, test_width_with_negative, .init = redirect_all_std)
{
    my_printf("[%5d]", -42);
    cr_assert_stdout_eq_str("[  -42]");
}
