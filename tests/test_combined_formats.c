/*
** EPITECH PROJECT, 2024
** test_combined_formats.c
** File description:
** Tests for complex combinations of formats and multiple specifiers
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, test_multiple_specifiers_mixture, .init = redirect_all_std)
{
    my_printf("%d %s %c %x %o %p %f", 42, "hello", 'X', 255, 64, (void*)0x1234, 3.14159);
    cr_assert_stdout_eq_str("42 hello X ff 100 0x1234 3.141590");
}

Test(my_printf, test_format_chaining, .init = redirect_all_std)
{
    my_printf("Decimal: %d, Hex: %x, Octal: %o", 42, 42, 42);
    cr_assert_stdout_eq_str("Decimal: 42, Hex: 2a, Octal: 52");
}

Test(my_printf, test_mixed_size_modifiers, .init = redirect_all_std)
{
    my_printf("Short: %hd, Long: %ld, Regular: %d", (short)123, 123456789L, 42);
    cr_assert_stdout_eq_str("Short: 123, Long: 123456789, Regular: 42");
}

Test(my_printf, test_mixed_flags, .init = redirect_all_std)
{
    my_printf("[%+d] [%#x] [%-10s]", 42, 42, "hello");
    cr_assert_stdout_eq_str("[+42] [0x2a] [hello     ]");
}

Test(my_printf, test_nested_percent, .init = redirect_all_std)
{
    my_printf("100%% complete: %d%%", 50);
    cr_assert_stdout_eq_str("100% complete: 50%");
}

Test(my_printf, test_format_with_repeated_specifiers, .init = redirect_all_std)
{
    my_printf("%d %d %d", 1, 2, 3);
    cr_assert_stdout_eq_str("1 2 3");
}

Test(my_printf, test_complex_number_format, .init = redirect_all_std)
{
    my_printf("Hex: 0x%x, Octal: 0%o, Decimal: %d", 255, 255, 255);
    cr_assert_stdout_eq_str("Hex: 0xff, Octal: 0377, Decimal: 255");
}

Test(my_printf, test_various_int_formats, .init = redirect_all_std)
{
    my_printf("%d %i %u", -42, -42, -42);
    cr_assert_stdout_eq_str("-42 -42 4294967254");
}

Test(my_printf, test_format_with_specifiers_and_literals, .init = redirect_all_std)
{
    my_printf("Value: %d, Rate: %f%%", 100, 99.9);
    cr_assert_stdout_eq_str("Value: 100, Rate: 99.900000%");
}

Test(my_printf, test_format_with_escape_sequences, .init = redirect_all_std)
{
    my_printf("Line1: %s\nLine2: %s", "Hello", "World");
    cr_assert_stdout_eq_str("Line1: Hello\nLine2: World");
}

Test(my_printf, test_hex_with_various_flags, .init = redirect_all_std)
{
    my_printf("[%x] [%#x] [%8x] [%08x] [%-8x]", 42, 42, 42, 42, 42);
    cr_assert_stdout_eq_str("[2a] [0x2a] [      2a] [0000002a] [2a      ]");
}

Test(my_printf, test_chars_and_strings_mix, .init = redirect_all_std)
{
    my_printf("Chars: %c%c%c, String: %s", 'A', 'B', 'C', "DEF");
    cr_assert_stdout_eq_str("Chars: ABC, String: DEF");
}

Test(my_printf, test_combined_integer_bases, .init = redirect_all_std)
{
    int num = 42;
    my_printf("Dec: %d, Hex: %x, Oct: %o, Binary: %b", num, num, num, num);
    cr_assert_stdout_eq_str("Dec: 42, Hex: 2a, Oct: 52, Binary: 101010");
}