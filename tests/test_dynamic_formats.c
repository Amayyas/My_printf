/*
** EPITECH PROJECT, 2024
** test_dynamic_formats.c
** File description:
** Tests for dynamic formats using * and complex argument combinations
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, test_dynamic_width, .init = redirect_all_std)
{
    my_printf("[%*d]", 5, 42);
    cr_assert_stdout_eq_str("[   42]");
}

Test(my_printf, test_dynamic_precision, .init = redirect_all_std)
{
    my_printf("[%.*f]", 2, 12.345);
    cr_assert_stdout_eq_str("[12.35]");
}

Test(my_printf, test_star_with_multiple_args, .init = redirect_all_std)
{
    my_printf("%*d %*s %*c", 5, 42, 7, "test", 3, 'X');
    cr_assert_stdout_eq_str("   42    test   X");
}

Test(my_printf, test_zero_star_value, .init = redirect_all_std)
{
    my_printf("[%*d]", 0, 42);
    cr_assert_stdout_eq_str("[42]");
}

Test(my_printf, test_large_star_value, .init = redirect_all_std)
{
    my_printf("[%*c]", 20, 'X');
    
    char expected[22] = {0};
    expected[0] = '[';
    for (int i = 1; i <= 19; i++)
        expected[i] = ' ';
    expected[20] = 'X';
    expected[21] = ']';
    
    cr_assert_stdout_eq_str(expected);
}
