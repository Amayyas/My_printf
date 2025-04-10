/*
** EPITECH PROJECT, 2024
** test_lib.c
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_abs, test1, .init = redirect_all_std)
{
    int nb = my_abs(-10);

    cr_assert_eq(nb, 10);
}

Test(my_abs, test2, .init = redirect_all_std)
{
    int nb = my_abs(10);

    cr_assert_eq(nb, 10);
}

Test(my_compute_power_rec, test3, .init = redirect_all_std)
{
    int nb = 10;
    int p = -3;
    int result = my_compute_power_rec(nb, p);

    cr_assert_eq(result, 0);
}

Test(my_compute_power_rec, test4, .init = redirect_all_std)
{
    int nb = 10;
    int p = 0;
    int result = my_compute_power_rec(nb, p);

    cr_assert_eq(result, 1);
}

Test(my_compute_power_rec, test5, .init = redirect_all_std)
{
    int nb = 10;
    int p = 2;
    int result = my_compute_power_rec(nb, p);

    cr_assert_eq(result, 100);
}

Test(my_compute_square_root, test6, .init = redirect_all_std)
{
    int nb = my_compute_square_root(-3);

    cr_assert_eq(nb, 0);
}

Test(my_compute_square_root, test7, .init = redirect_all_std)
{
    int nb = my_compute_square_root(100);

    cr_assert_eq(nb, 10);
}

Test(my_compute_square_root, test8, .init = redirect_all_std)
{
    int nb = my_compute_square_root(3);

    cr_assert_eq(nb, 0);
}

Test(my_find_prime_sup, test9, .init = redirect_all_std)
{
    int nb = my_find_prime_sup(10);

    cr_assert_eq(nb, 11);
}

Test(my_getnbr, test10, .init = redirect_all_std)
{
    int nb = my_getnbr("10");

    cr_assert_eq(nb, 10);
}

Test(my_getnbr, test11, .init = redirect_all_std)
{
    int nb = my_getnbr("2147483647");

    cr_assert_eq(nb, 2147483647);
}

Test(my_getnbr, test12, .init = redirect_all_std)
{
    int nb = my_getnbr("2147483649");

    cr_assert_eq(nb, 0);
}

Test(my_getnbr, test13, .init = redirect_all_std)
{
    int nb = my_getnbr("-dadad--e++adadad--2147483649");

    cr_assert_eq(nb, 0);
}

Test(my_getnbr, test14, .init = redirect_all_std)
{
    int nb = my_getnbr("-dadad--e++adadad--+");

    cr_assert_eq(nb, 0);
}

Test(my_getnbr, test15, .init = redirect_all_std)
{
    int nb = my_getnbr("abc123");

    cr_assert_eq(nb, 123);
}

Test(my_getnbr, test16, .init = redirect_all_std)
{
    int nb = my_getnbr("123abc");

    cr_assert_eq(nb, 123);
}

Test(my_getnbr, test17, .init = redirect_all_std)
{
    int nb = my_getnbr("--123");

    cr_assert_eq(nb, 123);
}

Test(my_getnbr, test18, .init = redirect_all_std)
{
    int nb = my_getnbr("2147483648");

    cr_assert_eq(nb, 0);
}

Test(my_getnbr, test19, .init = redirect_all_std)
{
    int nb = my_getnbr("-2147483649");

    cr_assert_eq(nb, 0);
}

Test(my_is_prime, test20, .init = redirect_all_std)
{
    int nb = my_is_prime(0);

    cr_assert_eq(nb, 0);
}

Test(my_is_prime, test21, .init = redirect_all_std)
{
    int nb = my_is_prime(1);

    cr_assert_eq(nb, 0);
}

Test(my_is_prime, test22, .init = redirect_all_std)
{
    int nb = my_is_prime(-1);

    cr_assert_eq(nb, 0);
}

Test(my_isneg, test23, .init = redirect_all_std)
{
    my_isneg(-1);
    cr_assert_stdout_eq_str("N");
}

Test(my_isneg, test24, .init = redirect_all_std)
{
    my_isneg(1);
    cr_assert_stdout_eq_str("P");
}

Test(my_swap, test100, .init = redirect_all_std)
{
    int a = 0;
    int b = 1;

    my_swap(&a, &b);
    cr_assert_eq(a, 1);
    cr_assert_eq(b, 0);
}

Test(my_strupcase, test101, .init = redirect_all_std)
{
    char str[] = "Hello";

    cr_assert_str_eq(my_strupcase(str), "HELLO");
}

Test(my_strupcase, test102, .init = redirect_all_std)
{
    char str[] = "hello";

    cr_assert_str_eq(my_strupcase(str), "HELLO");
}

Test(my_strupcase, test103, .init = redirect_all_std)
{
    char str[] = "HELLO";

    cr_assert_str_eq(my_strupcase(str), "HELLO");
}

Test(my_strupcase, test104, .init = redirect_all_std)
{
    char str[] = "HeLLo";

    cr_assert_str_eq(my_strupcase(str), "HELLO");
}

Test(my_strupcase, test105, .init = redirect_all_std)
{
    char str[] = "";

    cr_assert_str_eq(my_strupcase(str), "");
}

Test(my_strupcase, test106, .init = redirect_all_std)
{
    char str[] = "1234";

    cr_assert_str_eq(my_strupcase(str), "1234");
}

Test(my_strupcase, test107, .init = redirect_all_std)
{
    char str[] = "hello, world!";

    cr_assert_str_eq(my_strupcase(str), "HELLO, WORLD!");
}

Test(my_strupcase, test108, .init = redirect_all_std)
{
    char str[] = "{ello";

    cr_assert_str_eq(my_strupcase(str), "{ELLO");
}

Test(my_strupcase, test109, .init = redirect_all_std)
{
    char str[] = "`ello";

    cr_assert_str_eq(my_strupcase(str), "`ELLO");
}

Test(my_strstr, test108, .init = redirect_all_std)
{
    char str[] = "Hello, World!";
    char to_find[] = "World";

    cr_assert_str_eq(my_strstr(str, to_find), "World!");
}

Test(my_strstr, test109, .init = redirect_all_std)
{
    char str[] = "Hello, World!";
    char to_find[] = "Hello";

    cr_assert_str_eq(my_strstr(str, to_find), "Hello, World!");
}

Test(my_strstr, test110, .init = redirect_all_std)
{
    char str[] = "Hello, World!";
    char to_find[] = "Hello, World!";

    cr_assert_str_eq(my_strstr(str, to_find), "Hello, World!");
}

Test(my_strstr, test111, .init = redirect_all_std)
{
    char str[] = "Hello, World!";
    char to_find[] = "";

    cr_assert_str_eq(my_strstr(str, to_find), "Hello, World!");
}

Test(my_strstr, test112, .init = redirect_all_std)
{
    char str[] = "Hello, World!";
    char to_find[] = "Hello, World! ";

    cr_assert_eq(my_strstr(str, to_find), NULL);
}

Test(my_strncpy, test113, .init = redirect_all_std)
{
    char dest[100] = "Hello";
    char src[] = "World";

    cr_assert_str_eq(my_strncpy(dest, src, 5), "World");
}

Test(my_strncpy, test114, .init = redirect_all_std)
{
    char dest[1] = "";
    char src[] = "World";

    cr_assert_str_eq(my_strncpy(dest, src, 0), "");
}

Test(my_strncpy, test115, .init = redirect_all_std)
{
    char dest[1] = "";
    char src[] = "";

    cr_assert_str_eq(my_strncpy(dest, src, 1), "");
}

Test(my_strncat, test116, .init = redirect_all_std)
{
    char dest[100] = "Hello";
    char src[] = "World";

    cr_assert_str_eq(my_strncat(dest, src, 5), "HelloWorld");
}

Test(my_strncat, test117, .init = redirect_all_std)
{
    char dest[100] = "Hello";
    char src[] = "World";

    cr_assert_str_eq(my_strncat(dest, src, 0), "Hello");
}

Test(my_strncat, test1174, .init = redirect_all_std)
{
    char dest[100] = "Hello";
    char src[] = "";

    cr_assert_str_eq(my_strncat(dest, src, 5), "Hello");
}

Test(my_strlowcase, test118, .init = redirect_all_std)
{
    char str[] = "HELLO";

    cr_assert_str_eq(my_strlowcase(str), "hello");
}

Test(my_strcpy, test119, .init = redirect_all_std)
{
    char dest[100] = "Hello";
    char src[] = "World";

    cr_assert_str_eq(my_strcpy(dest, src), "World");
}

Test(my_strcmp, test120, .init = redirect_all_std)
{
    char str1[] = "Hello";
    char str2[] = "Hello";

    cr_assert_eq(my_strcmp(str1, str2), 0);
}

Test(my_strcmp, test121, .init = redirect_all_std)
{
    char str1[] = "Hello";
    char str2[] = "World";

    cr_assert_eq(my_strcmp(str1, str2), -15);
}

Test(my_strcat, test122, .init = redirect_all_std)
{
    char dest[100] = "Hello";
    char src[] = "World";

    cr_assert_str_eq(my_strcat(dest, src), "HelloWorld");
}

Test(my_str_isupper, test123, .init = redirect_all_std)
{
    char str[] = "HELLO";

    cr_assert_eq(my_str_isupper(str), 1);
}

Test(my_strcapitalize, test124, .init = redirect_all_std)
{
    char str[] = "hello, world!";

    cr_assert_str_eq(my_strcapitalize(str), "Hello, World!");
}

Test(my_strcapitalize, test1244, .init = redirect_all_std)
{
    char str[] = "hello, world!0";

    cr_assert_str_eq(my_strcapitalize(str), "Hello, World!0");
}

Test(my_strcapitalize, test1245, .init = redirect_all_std)
{
    char str[] = "{hello, world!{";

    cr_assert_str_eq(my_strcapitalize(str), "{hello, World!{");
}

Test(my_strcapitalize, test1246, .init = redirect_all_std)
{
    char str[] = "`hello, world!{";

    cr_assert_str_eq(my_strcapitalize(str), "`hello, World!{");
}

Test(my_str_isupper, test125, .init = redirect_all_std)
{
    char str[] = "hello";

    cr_assert_eq(my_str_isupper(str), 0);
}

Test(my_str_isprintable, test126, .init = redirect_all_std)
{
    char str[] = "Hello";

    cr_assert_eq(my_str_isprintable(str), 1);
}

Test(my_str_isprintable, test127, .init = redirect_all_std)
{
    char str[] = "Hello\n";

    cr_assert_eq(my_str_isprintable(str), 0);
}

Test(my_str_isnum, test128, .init = redirect_all_std)
{
    char str[] = "1234";

    cr_assert_eq(my_str_isnum(str), 1);
}

Test(my_str_isnum, test129, .init = redirect_all_std)
{
    char str[] = "1234a";

    cr_assert_eq(my_str_isnum(str), 0);
}

Test(my_str_islower, test130, .init = redirect_all_std)
{
    char str[] = "hello";

    cr_assert_eq(my_str_islower(str), 1);
}

Test(my_str_islower, test131, .init = redirect_all_std)
{
    char str[] = "Hello";

    cr_assert_eq(my_str_islower(str), 0);
}

Test(my_str_isalpha, test132, .init = redirect_all_std)
{
    char str[] = "Hello";

    cr_assert_eq(my_str_isalpha(str), 1);
}

Test(my_str_isalpha, test133, .init = redirect_all_std)
{
    char str[] = "Hello123";

    cr_assert_eq(my_str_isalpha(str), 0);
}

Test(my_sort_int_array, test134, .init = redirect_all_std)
{
    int array[5] = {5, 4, 3, 2, 1};
    int size = 5;

    my_sort_int_array(array, size);
    cr_assert_eq(array[0], 1);
    cr_assert_eq(array[1], 2);
    cr_assert_eq(array[2], 3);
    cr_assert_eq(array[3], 4);
    cr_assert_eq(array[4], 5);
}

Test(my_sort_int_array, test135, .init = redirect_all_std)
{
    int array[0] = {};
    int size = 0;

    my_sort_int_array(array, size);
    cr_assert_eq(array[0], 0);
}

Test(my_showstr, test136, .init = redirect_all_std)
{
    char str[] = "Hello";

    my_showstr(str);
}

Test(my_showstr, test137, .init = redirect_all_std)
{
    char str[] = "Hello\n";

    my_showstr(str);
}

Test(my_strlen, test138, .init = redirect_all_std)
{
    char str[] = "Hello";

    cr_assert_eq(my_strlen(str), 5);
}

Test(my_nbr_base_len, test139, .init = redirect_all_std)
{
    int nbr = 255;

    cr_assert_eq(my_nbr_base_len(nbr, HEX_CHARS), 2);
}

Test(my_nbr_base_len, test140, .init = redirect_all_std)
{
    int nbr = -255;

    cr_assert_eq(my_nbr_base_len(nbr, HEX_CHARS), 3);
}

Test(my_showmem, test139, .init = redirect_all_std)
{
    char str[] = "Hello";

    my_showmem(str, 5);
}

Test(my_revstr, test140, .init = redirect_all_std)
{
    char str[] = "Hello";

    cr_assert_str_eq(my_revstr(str), "olleH");
}

Test(my_putstr, test141, .init = redirect_all_std)
{
    char str[] = "Hello";

    my_putstr(str);
}

Test(my_putstr, test142, .init = redirect_all_std)
{
    char str[] = "Hello\n";

    my_putstr(str);
}

Test(my_putstr, test143, .init = redirect_all_std)
{
    char str[] = "";

    my_putstr(str);
}

Test(my_putchar_plus, test200, .init = redirect_all_std)
{
    my_putchar_plus(1, 'c');
    cr_assert_stdout_eq_str("c");
}

Test(my_puterr, test201, .init = redirect_all_std)
{
    my_puterr("CACA");
    cr_assert_stderr_eq_str("CACA");
}

Test(my_putnbr_base, test202, .init = redirect_all_std)
{
    int counter = 0;

    my_putnbr_base(-10, HEX_CHARS, &counter);
    cr_assert_stdout_eq_str("-a");
}

Test(my_strncmp, test203, .init = redirect_all_std)
{
    int cmp = my_strncmp("", "", 5);

    cr_assert_eq(cmp, 0);
}

Test(my_strncmp, test204, .init = redirect_all_std)
{
    int cmp = my_strncmp("World", "World", 5);

    cr_assert_eq(cmp, 0);
}

Test(my_strncmp, test205, .init = redirect_all_std)
{
    int cmp = my_strncmp("Hello", "Hello", 0);

    cr_assert_eq(cmp, 0);
}

Test(my_strncmp, test206, .init = redirect_all_std)
{
    int cmp = my_strncmp("", "", 0);

    cr_assert_eq(cmp, 0);
}

Test(my_strncmp, test207, .init = redirect_all_std)
{
    int cmp = my_strncmp("", "", 5);

    cr_assert_eq(cmp, 0);
}

Test(my_isnum, test208, .init = redirect_all_std)
{
    int isnum = my_isnum('0');

    cr_assert_eq(isnum, 1);
}

Test(my_isnum, test209, .init = redirect_all_std)
{
    int isnum = my_isnum('9');

    cr_assert_eq(isnum, 1);
}

Test(my_isnum, test210, .init = redirect_all_std)
{
    int isnum = my_isnum('a');

    cr_assert_eq(isnum, 0);
}

Test(my_isnum, test211, .init = redirect_all_std)
{
    int isnum = my_isnum('z');

    cr_assert_eq(isnum, 0);
}

Test(my_isnum, test212, .init = redirect_all_std)
{
    int isnum = my_isnum('A');

    cr_assert_eq(isnum, 0);
}


Test(my_isnum, test214, .init = redirect_all_std)
{
    int isnum = my_isalpha('{');

    cr_assert_eq(isnum, 0);
}

Test(my_isnum, test213, .init = redirect_all_std)
{
    int isnum = my_isalpha('`');

    cr_assert_eq(isnum, 0);
}

Test(my_isalpha, test208, .init = redirect_all_std)
{
    int isalpha = my_isalpha('a');

    cr_assert_eq(isalpha, 1);
}

Test(my_isalpha, test209, .init = redirect_all_std)
{
    int isalpha = my_isalpha('z');

    cr_assert_eq(isalpha, 1);
}

Test(my_isalpha, test210, .init = redirect_all_std)
{
    int isalpha = my_isalpha('A');

    cr_assert_eq(isalpha, 1);
}

Test(my_isalpha, test211, .init = redirect_all_std)
{
    int isalpha = my_isalpha('a');

    cr_assert_eq(isalpha, 1);
}

Test(my_isalpha, test212, .init = redirect_all_std)
{
    int isalpha = my_isalpha('{');

    cr_assert_eq(isalpha, 0);
}

Test(my_isalpha, test213, .init = redirect_all_std)
{
    int isalpha = my_isalpha('`');

    cr_assert_eq(isalpha, 0);
}

Test(my_printf, test_my_printf1, .init = redirect_all_std)
{
    int counter = 0;
    my_printf("%d", 42, &counter);
    cr_assert_stdout_eq_str("42");
}

Test(my_printf, test_my_printf2, .init = redirect_all_std)
{
    int counter = 0;
    my_printf("%s", "Hello, World!", &counter);
    cr_assert_stdout_eq_str("Hello, World!");
}

Test(my_printf, test_my_printf3, .init = redirect_all_std)
{
    int counter = 0;
    my_printf("%c", 'A', &counter);
    cr_assert_stdout_eq_str("A");
}

Test(my_printf, test_my_printf4, .init = redirect_all_std)
{
    int counter = 0;
    my_printf("%x", 255, &counter);
    cr_assert_stdout_eq_str("ff");
}

Test(my_printf, test_my_printf5, .init = redirect_all_std)
{
    int counter = 0;
    my_printf("%X", 255, &counter);
    cr_assert_stdout_eq_str("FF");
}

Test(my_printf, test_my_printf6, .init = redirect_all_std)
{
    int counter = 0;
    my_printf("%o", 255, &counter);
    cr_assert_stdout_eq_str("377");
}

Test(my_printf, test_my_printf7, .init = redirect_all_std)
{
    int counter = 0;
    my_printf("%u", 4294967295, &counter);
    cr_assert_stdout_eq_str("4294967295");
}

Test(my_printf, test_my_printf8, .init = redirect_all_std)
{
    int counter = 0;
    my_printf("%p", (void*)0x12345678, &counter);
    cr_assert_stdout_eq_str("0x12345678");
}

Test(my_printf, test_my_printf9, .init = redirect_all_std)
{
    int counter = 0;
    my_printf("%%", &counter);
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, test_my_printf10, .init = redirect_all_std)
{
    int counter = 0;
    my_printf("%+d", 42, &counter);
    cr_assert_stdout_eq_str("+42");
}

Test(my_strlen, test139, .init = redirect_all_std)
{
    char str[] = "Hello, World!";
    int len = my_strlen(str);

    cr_assert_eq(len, 13);
}

Test(my_nbr_len, test140, .init = redirect_all_std)
{
    int number = 12345;
    int len = my_nbr_len(number);

    cr_assert_eq(len, 5);
}

Test(my_nbr_len, test141, .init = redirect_all_std)
{
    int number = -12345;
    int len = my_nbr_len(number);

    cr_assert_eq(len, 6);
}

Test(my_nbr_len, test142, .init = redirect_all_std)
{
    int number = 0;
    int len = my_nbr_len(number);

    cr_assert_eq(len, 1);
}

Test(handle_format_width, test_my_handle_format_width, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "5";

    handle_format_width(str, &element);
    cr_assert_eq(element.width, 5);
}

Test(handle_format_precision, test_my_handle_format_precision, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = ".5";

    handle_format_precision(str, &element);
    cr_assert_eq(element.precision, 5);
}

Test(handle_minus_flag, test_my_handle_minus_flag, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "-";

    handle_minus_flag(str, &element);
    cr_assert_eq(element.minus_flag, true);
}

Test(handle_zero_flag, test_my_handle_zero_flag, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "0";

    handle_zero_flag(str, &element);
    cr_assert_eq(element.zero_flag, true);
}

Test(my_put_space, test_my_put_space1, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .space_flag = true, .plus_flag = false };
    int counter = 0;
    my_put_space(&element, 42, &counter);
    cr_assert_stdout_eq_str(" ");
    cr_assert_eq(counter, 1);
}

Test(my_put_space, test_my_put_space2, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .space_flag = true, .plus_flag = true };
    int counter = 0;
    my_put_space(&element, 42, &counter);
    cr_assert_stdout_eq_str("");
    cr_assert_eq(counter, 0);
}

Test(my_put_plus, test_my_put_plus1, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .plus_flag = true };
    int counter = 0;
    my_put_plus(&element, 42, &counter);
    cr_assert_stdout_eq_str("+");
    cr_assert_eq(counter, 1);
}

Test(my_put_plus, test_my_put_plus2, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .plus_flag = false };
    int counter = 0;
    my_put_plus(&element, 42, &counter);
    cr_assert_stdout_eq_str("");
    cr_assert_eq(counter, 0);
}

Test(my_put_hash, test_my_put_hash1, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .hash_flag = true };
    int counter = 0;
    my_put_hash(&element, HEX_CHARS, &counter);
    cr_assert_stdout_eq_str("0x");
    cr_assert_eq(counter, 2);
}

Test(my_put_hash, test_my_put_hash2, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .hash_flag = true };
    int counter = 0;
    my_put_hash(&element, OCTAL_CHARS, &counter);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(counter, 1);
}

Test(my_put_zero, test_my_put_zero1, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .zero_flag = true, .width = 5 };
    int counter = 0;
    my_put_zero(&element, 42, &counter);
    cr_assert_stdout_eq_str("000");
    cr_assert_eq(counter, 3);
}

Test(my_put_zero, test_my_put_zero2, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .zero_flag = true, .width = 2 };
    int counter = 0;
    my_put_zero(&element, 42, &counter);
    cr_assert_stdout_eq_str("");
    cr_assert_eq(counter, 0);
}

Test(my_put_width, test_my_put_width1, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .padding_flag = true, .width = 5 };
    int counter = 0;
    my_put_width(&element, 2, &counter);
    cr_assert_stdout_eq_str("   ");
    cr_assert_eq(counter, 3);
}

Test(my_put_width, test_my_put_width2, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .padding_flag = true, .width = 2 };
    int counter = 0;
    my_put_width(&element, 2, &counter);
    cr_assert_stdout_eq_str("");
    cr_assert_eq(counter, 0);
}

Test(my_put_width, test_my_put_width3, .init = redirect_all_std)
{
    element_t element = { .is_format = false, .padding_flag = true, .width = 5 };
    int counter = 0;
    my_put_width(&element, 2, &counter);
    cr_assert_stdout_eq_str("");
    cr_assert_eq(counter, 0);
}

Test(my_put_width, test_my_put_width4, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .padding_flag = false, .minus_flag = false, .star_flag = false, .width = 5 };
    int counter = 0;
    my_put_width(&element, 2, &counter);
    cr_assert_stdout_eq_str("");
    cr_assert_eq(counter, 0);
}

Test(my_put_width, test_my_put_width5, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .padding_flag = true, .minus_flag = false, .star_flag = false, .width = 2 };
    int counter = 0;
    my_put_width(&element, 5, &counter);
    cr_assert_stdout_eq_str("");
    cr_assert_eq(counter, 0);
}

Test(my_put_width, test_my_put_width6, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .padding_flag = true, .minus_flag = false, .star_flag = false, .width = 5 };
    int counter = 0;
    my_put_width(&element, 2, &counter);
    cr_assert_stdout_eq_str("   ");
    cr_assert_eq(counter, 3);
}

Test(my_put_width, test_my_put_width7, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .padding_flag = true, .minus_flag = true, .star_flag = false, .width = 5 };
    int counter = 0;
    my_put_width(&element, 2, &counter);
    cr_assert_stdout_eq_str("   ");
    cr_assert_eq(counter, 3);
}

Test(my_put_width, test_my_put_width8, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .padding_flag = true, .minus_flag = false, .star_flag = true, .width = 5 };
    int counter = 0;
    my_put_width(&element, 2, &counter);
    cr_assert_stdout_eq_str("   ");
    cr_assert_eq(counter, 3);
}

Test(my_str_len_prec, test_my_str_len_prec1, .init = redirect_all_std)
{
    char str[] = "Hello, World!";
    int len = my_str_len_prec(str, 5);

    cr_assert_eq(len, 5);
}

Test(find_and_compute_format, test1, .init = redirect_all_std)
{
    element_t element = { .is_format = true };
    int char_count = 0;
    int result = find_and_compute_format("%d", &element, 2, &char_count);

    cr_assert_eq(result, 1);
    cr_assert_eq(char_count, 1);
}

Test(find_and_compute_format, test3, .init = redirect_all_std)
{
    element_t element = { .is_format = true };
    int char_count = 0;
    int result = find_and_compute_format("%x", &element, 2, &char_count);

    cr_assert_eq(result, 1);
    cr_assert_eq(char_count, 1);
}

Test(find_and_compute_format, test6, .init = redirect_all_std)
{
    element_t element = { .is_format = false };
    int char_count = 0;
    int result = find_and_compute_format("%z", &element, 2, &char_count);

    cr_assert_eq(result, 0);
    cr_assert_eq(char_count, 0);
}

Test(handle_hash_flag, test_handle_hash_flag1, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "#";

    int result = handle_hash_flag(str, &element);
    cr_assert_eq(result, 1);
    cr_assert_eq(element.hash_flag, true);
}


Test(handle_hash_flag, test_handle_hash_flag3, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "#5";

    int result = handle_hash_flag(str, &element);
    cr_assert_eq(result, 2);
    cr_assert_eq(element.hash_flag, true);
    cr_assert_eq(element.width, 5);
}

Test(handle_hash_flag, test_handle_hash_flag4, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "#10";

    int result = handle_hash_flag(str, &element);
    cr_assert_eq(result, 3);
    cr_assert_eq(element.hash_flag, true);
    cr_assert_eq(element.width, 10);
}

Test(handle_hash_flag, test_handle_hash_flag5, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "#0";

    int result = handle_hash_flag(str, &element);
    cr_assert_eq(result, 2);
    cr_assert_eq(element.hash_flag, true);
    cr_assert_eq(element.width, 0);
}

Test(my_str_len_prec, test_my_str_len_prec2, .init = redirect_all_std)
{
    char str[] = "Hello, World!";
    int len = my_str_len_prec(str, 20);

    cr_assert_eq(len, 13);
}

Test(my_str_len_prec, test_my_str_len_prec3, .init = redirect_all_std)
{
    char str[] = "Hello, World!";
    int len = my_str_len_prec(str, 0);

    cr_assert_eq(len, 0);
}

Test(my_str_len_prec, test_my_str_len_prec4, .init = redirect_all_std)
{
    char str[] = "";
    int len = my_str_len_prec(str, 5);

    cr_assert_eq(len, 0);
}

Test(my_str_len_prec, test_my_str_len_prec5, .init = redirect_all_std)
{
    char str[] = "Hello";
    int len = my_str_len_prec(str, 5);

    cr_assert_eq(len, 5);
}

Test(my_str_len_prec, test_my_str_len_prec6, .init = redirect_all_std)
{
    char str[] = "Hello";
    int len = my_str_len_prec(str, 3);

    cr_assert_eq(len, 3);
}

Test(my_nbr_exp_len, test1, .init = redirect_all_std)
{
    double nb = 123.456;
    int len = my_nbr_exp_len(nb);

    cr_assert_eq(len, 12);
}

Test(my_nbr_exp_len, test2, .init = redirect_all_std)
{
    double nb = -123.456;
    int len = my_nbr_exp_len(nb);

    cr_assert_eq(len, 13);
}

Test(my_nbr_exp_len, test3, .init = redirect_all_std)
{
    double nb = 0.0;
    int len = my_nbr_exp_len(nb);

    cr_assert_eq(len, 12);
}

Test(my_nbr_exp_len, test5, .init = redirect_all_std)
{
    double nb = 1.0e-10;
    int len = my_nbr_exp_len(nb);

    cr_assert_eq(len, 12);
}

Test(my_nbr_exp_len, test6, .init = redirect_all_std)
{
    double nb = -1.0e-10;
    int len = my_nbr_exp_len(nb);

    cr_assert_eq(len, 13);
}

Test(handle_format_precision, test1, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = ".5";

    handle_format_precision(str, &element);
    cr_assert_eq(element.precision, 5);
}

Test(handle_format, test_handle_format1, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "5";

    int length = handle_format(str, &element);
    cr_assert_eq(length, 1);
    cr_assert_eq(element.width, 5);
}

Test(handle_format, test_handle_format2, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "#5";

    int length = handle_format(str, &element);
    cr_assert_eq(length, 2);
    cr_assert_eq(element.hash_flag, true);
    cr_assert_eq(element.width, 5);
}

Test(handle_format, test_handle_format3, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "0";

    int length = handle_format(str, &element);
    cr_assert_eq(length, 1);
    cr_assert_eq(element.zero_flag, true);
}

Test(handle_format, test_handle_format4, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "-";

    int length = handle_format(str, &element);
    cr_assert_eq(length, 1);
    cr_assert_eq(element.minus_flag, true);
}

Test(handle_format, test_handle_format5, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = ".5";

    int length = handle_format(str, &element);
    cr_assert_eq(length, 2);
    cr_assert_eq(element.precision, 5);
}

Test(handle_format, test_handle_format7, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "";

    int length = handle_format(str, &element);
    cr_assert_eq(length, 0);
}

Test(handle_hash_flag, test_handle_hash_flag6, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "#";

    int length = handle_hash_flag(str, &element);
    cr_assert_eq(length, 1);
    cr_assert_eq(element.hash_flag, true);
}

Test(handle_end_flag, test_handle_end_flag1, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "5";

    int length = handle_end_flag(str, &element);
    cr_assert_eq(length, 1);
    cr_assert_eq(element.width, 5);
    cr_assert_eq(element.padding_flag, true);
    cr_assert_eq(element.is_format, true);
    cr_assert_eq(element.end_flag, true);
}

Test(handle_end_flag, test_handle_end_flag4, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = ".5";

    int length = handle_end_flag(str, &element);
    cr_assert_eq(length, 2);
    cr_assert_eq(element.precision, 5);
    cr_assert_eq(element.end_flag, true);
}

Test(handle_end_flag, test_handle_end_flag5, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "";

    int length = handle_end_flag(str, &element);
    cr_assert_eq(length, 0);
    cr_assert_eq(element.end_flag, false);
}

Test(my_put_zero_float, test_my_put_zero_float2, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .zero_flag = true, .width = 10, .precision = 2 };
    double nb = 42.0;
    int counter = 0;

    my_put_zero_float(&element, nb, &counter);
    cr_assert_stdout_eq_str("000000");
    cr_assert_eq(counter, 6);
}

Test(my_put_zero_float, test_my_put_zero_float3, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .zero_flag = false, .width = 10, .precision = 0 };
    double nb = 42.0;
    int counter = 0;

    my_put_zero_float(&element, nb, &counter);
    cr_assert_stdout_eq_str("");
    cr_assert_eq(counter, 0);
}

Test(my_put_zero_float, test_my_put_zero_float4, .init = redirect_all_std)
{
    element_t element = { .is_format = false, .zero_flag = true, .width = 10, .precision = 0 };
    double nb = 42.0;
    int counter = 0;

    my_put_zero_float(&element, nb, &counter);
    cr_assert_stdout_eq_str("");
    cr_assert_eq(counter, 0);
}

Test(my_put_zero_float, test_my_put_zero_float5, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .zero_flag = true, .width = 5, .precision = 0 };
    double nb = 42.0;
    int counter = 0;

    my_put_zero_float(&element, nb, &counter);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(counter, 1);
}

Test(my_put_nbr_rec, test_my_put_nbr_rec1, .init = redirect_all_std)
{
    element_t element = {0};
    int counter = 0;
    my_put_nbr_rec(&element, 12345, &counter);
    cr_assert_stdout_eq_str("12345");
    cr_assert_eq(counter, 5);
}

Test(my_put_nbr_rec, test_my_put_nbr_rec2, .init = redirect_all_std)
{
    element_t element = {0};
    int counter = 0;
    my_put_nbr_rec(&element, -12345, &counter);
    cr_assert_stdout_eq_str("-12345");
    cr_assert_eq(counter, 6);
}

Test(my_put_nbr_rec, test_my_put_nbr_rec3, .init = redirect_all_std)
{
    element_t element = {0};
    int counter = 0;
    my_put_nbr_rec(&element, 0, &counter);
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(counter, 1);
}

Test(my_put_nbr_rec, test_my_put_nbr_rec4, .init = redirect_all_std)
{
    element_t element = {0};
    int counter = 0;
    my_put_nbr_rec(&element, INT_MIN, &counter);
    cr_assert_stdout_eq_str("-2147483648");
    cr_assert_eq(counter, 11);
}

Test(my_put_nbr_rec, test_my_put_nbr_rec5, .init = redirect_all_std)
{
    element_t element = { .plus_flag = true };
    int counter = 0;
    my_put_nbr_rec(&element, 12345, &counter);
    cr_assert_stdout_eq_str("12345");
    cr_assert_eq(counter, 5);
}

Test(my_put_nbr_rec, test_my_put_nbr_rec6, .init = redirect_all_std)
{
    element_t element = { .plus_flag = true };
    int counter = 0;
    my_put_nbr_rec(&element, -12345, &counter);
    cr_assert_stdout_eq_str("-12345");
    cr_assert_eq(counter, 6);
}

Test(my_put_nbr_rec, test_my_put_nbr_rec7, .init = redirect_all_std)
{
    element_t element = { .zero_flag = true };
    int counter = 0;
    my_put_nbr_rec(&element, -12345, &counter);
    cr_assert_stdout_eq_str("-12345");
    cr_assert_eq(counter, 6);
}

Test(my_str_isupper, test126, .init = redirect_all_std)
{
    char str[] = "HELLO";

    cr_assert_eq(my_str_isupper(str), 1);
}

Test(my_str_isupper, test127, .init = redirect_all_std)
{
    char str[] = "Hello";

    cr_assert_eq(my_str_isupper(str), 0);
}

Test(my_str_isupper, test128, .init = redirect_all_std)
{
    char str[] = "HELLO123";

    cr_assert_eq(my_str_isupper(str), 0);
}

Test(my_str_isupper, test129, .init = redirect_all_std)
{
    char str[] = "";

    cr_assert_eq(my_str_isupper(str), 1);
}

Test(my_str_isupper, test130, .init = redirect_all_std)
{
    char str[] = "HELLO WORLD";

    cr_assert_eq(my_str_isupper(str), 0);
}

Test(my_str_isnum, test1, .init = redirect_all_std)
{
    char str[] = "12345";

    cr_assert_eq(my_str_isnum(str), 1);
}

Test(my_str_isnum, test2, .init = redirect_all_std)
{
    char str[] = "123a45";

    cr_assert_eq(my_str_isnum(str), 0);
}

Test(my_str_isnum, test3, .init = redirect_all_std)
{
    char str[] = "";

    cr_assert_eq(my_str_isnum(str), 1);
}

Test(my_str_isnum, test4, .init = redirect_all_std)
{
    char str[] = "0";

    cr_assert_eq(my_str_isnum(str), 1);
}

Test(my_str_isnum, test5, .init = redirect_all_std)
{
    char str[] = "9";

    cr_assert_eq(my_str_isnum(str), 1);
}

Test(my_str_isnum, test6, .init = redirect_all_std)
{
    char str[] = "0123456789";

    cr_assert_eq(my_str_isnum(str), 1);
}

Test(my_str_isnum, test7, .init = redirect_all_std)
{
    char str[] = "123 456";

    cr_assert_eq(my_str_isnum(str), 0);
}
Test(my_str_isprintable, test1, .init = redirect_all_std)
{
    char str[] = "Hello";

    cr_assert_eq(my_str_isprintable(str), 1);
}

Test(my_str_isprintable, test2, .init = redirect_all_std)
{
    char str[] = "Hello\n";

    cr_assert_eq(my_str_isprintable(str), 0);
}

Test(my_str_isprintable, test3, .init = redirect_all_std)
{
    char str[] = "Hello\t";

    cr_assert_eq(my_str_isprintable(str), 0);
}

Test(my_str_isprintable, test4, .init = redirect_all_std)
{
    char str[] = "Hello\177";

    cr_assert_eq(my_str_isprintable(str), 0);
}

Test(my_str_isprintable, test5, .init = redirect_all_std)
{
    char str[] = "";

    cr_assert_eq(my_str_isprintable(str), 1);
}

Test(my_put_hash, test_my_put_hash3, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .hash_flag = true };
    int counter = 0;
    my_put_hash(&element, "01", &counter);
    cr_assert_stdout_eq_str("0b");
    cr_assert_eq(counter, 2);
}

Test(my_put_width, test_my_put_width9, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .padding_flag = false, .minus_flag = false, .star_flag = false, .width = 5 };
    int counter = 0;
    my_put_width(&element, 2, &counter);
    cr_assert_stdout_eq_str("");
    cr_assert_eq(counter, 0);
}

Test(my_put_width, test_my_put_width10, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .padding_flag = true, .minus_flag = false, .star_flag = false, .width = 5 };
    int counter = 0;
    my_put_width(&element, 2, &counter);
    cr_assert_stdout_eq_str("   ");
    cr_assert_eq(counter, 3);
}

Test(my_put_width, test_my_put_width11, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .padding_flag = true, .minus_flag = true, .star_flag = false, .width = 5 };
    int counter = 0;
    my_put_width(&element, 2, &counter);
    cr_assert_stdout_eq_str("   ");
    cr_assert_eq(counter, 3);
}

Test(my_put_width, test_my_put_width12, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .padding_flag = true, .minus_flag = false, .star_flag = true, .width = 5 };
    int counter = 0;
    my_put_width(&element, 2, &counter);
    cr_assert_stdout_eq_str("   ");
    cr_assert_eq(counter, 3);
}

Test(my_put_width, test_my_put_width13, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .padding_flag = true, .minus_flag = false, .star_flag = false, .width = 5 };
    int counter = 0;
    my_put_width(&element, 2, &counter);
    cr_assert_stdout_eq_str("   ");
    cr_assert_eq(counter, 3);
}

Test(my_put_zero_float, test_my_put_zero_float6, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .zero_flag = true, .width = 5, .precision = 0 };
    double nb = 12345.0;
    int counter = 0;

    my_put_zero_float(&element, nb, &counter);
    cr_assert_stdout_eq_str("");
    cr_assert_eq(counter, 0);
}

Test(my_itoa, test1, .init = redirect_all_std)
{
    char buffer[12];
    int len = my_itoa(0, buffer);

    cr_assert_eq(len, 1);
    cr_assert_str_eq(buffer, "0");
}

Test(my_itoa, test2, .init = redirect_all_std)
{
    char buffer[12];
    int len = my_itoa(12345, buffer);

    cr_assert_eq(len, 5);
    cr_assert_str_eq(buffer, "12345");
}

Test(my_itoa, test4, .init = redirect_all_std)
{
    char buffer[12];
    int len = my_itoa(INT_MAX, buffer);

    cr_assert_eq(len, 10);
    cr_assert_str_eq(buffer, "2147483647");
}

Test(my_itoa, test6, .init = redirect_all_std)
{
    char buffer[12];
    int len = my_itoa(1, buffer);

    cr_assert_eq(len, 1);
    cr_assert_str_eq(buffer, "1");
}
Test(my_put_zero_base, test_my_put_zero_base1, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .zero_flag = true, .width = 5 };
    int counter = 0;
    my_put_zero_base(&element, 42, &counter, "0123456789");
    cr_assert_stdout_eq_str("000");
    cr_assert_eq(counter, 3);
}

Test(my_put_zero_base, test_my_put_zero_base2, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .zero_flag = true, .width = 3 };
    int counter = 0;
    my_put_zero_base(&element, 42, &counter, "0123456789");
    cr_assert_stdout_eq_str("0");
    cr_assert_eq(counter, 1);
}

Test(my_put_zero_base, test_my_put_zero_base3, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .zero_flag = false, .width = 5 };
    int counter = 0;
    my_put_zero_base(&element, 42, &counter, "0123456789");
    cr_assert_stdout_eq_str("");
    cr_assert_eq(counter, 0);
}

Test(my_put_zero_base, test_my_put_zero_base4, .init = redirect_all_std)
{
    element_t element = { .is_format = false, .zero_flag = true, .width = 5 };
    int counter = 0;
    my_put_zero_base(&element, 42, &counter, "0123456789");
    cr_assert_stdout_eq_str("");
    cr_assert_eq(counter, 0);
}

Test(my_put_zero_base, test_my_put_zero_base5, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .zero_flag = true, .width = 2 };
    int counter = 0;
    my_put_zero_base(&element, 42, &counter, "0123456789");
    cr_assert_stdout_eq_str("");
    cr_assert_eq(counter, 0);
}

Test(my_itoa, test17, .init = redirect_all_std)
{
    char buffer[12];
    int value = 12345;

    int len = my_itoa(value, buffer);
    cr_assert_eq(len, 5);
    cr_assert_str_eq(buffer, "12345");
}

Test(my_itoa, test28, .init = redirect_all_std)
{
    char buffer[12];
    int value = -12345;

    int len = my_itoa(value, buffer);
    cr_assert_eq(len, 6);
    cr_assert_str_eq(buffer, "12345-");
}

Test(my_itoa, test37, .init = redirect_all_std)
{
    char buffer[12];
    int value = 0;

    int len = my_itoa(value, buffer);
    cr_assert_eq(len, 1);
    cr_assert_str_eq(buffer, "0");
}

Test(my_put_zero, test_my_put_zero1841, .init = redirect_all_std)
{
    element_t element = { .is_format = true, .zero_flag = true, .width = 5 };
    int counter = 0;
    my_put_zero(&element, 42, &counter);
    cr_assert_stdout_eq_str("000");
    cr_assert_eq(counter, 3);
}

Test(handle_minus_flag, test_handle_minus_flag_with_dot, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "-5.2";

    int result = handle_minus_flag(str, &element);
    cr_assert_eq(result, 4);
    cr_assert_eq(element.minus_flag, true);
    cr_assert_eq(element.width, 5);
    cr_assert_eq(element.precision, 2);
    cr_assert_eq(element.end_flag, true);
}


Test(handle_minus_flag, test_handle_minus_flag_with_dot_no_precision, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "-5.";

    int result = handle_minus_flag(str, &element);
    cr_assert_eq(result, 3);
    cr_assert_eq(element.minus_flag, true);
    cr_assert_eq(element.width, 5);
    cr_assert_eq(element.precision, 0);
    cr_assert_eq(element.end_flag, true);
}

Test(handle_zero_flag, test_handle_zero_flag_with_dot, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "05.2";

    int result = handle_zero_flag(str, &element);
    cr_assert_eq(result, 4);
    cr_assert_eq(element.zero_flag, true);
    cr_assert_eq(element.width, 5);
    cr_assert_eq(element.precision, 2);
    cr_assert_eq(element.end_flag, true);
}

Test(handle_zero_flag, test_handle_zero_flag_with_dot_no_precision, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "05.";

    int result = handle_zero_flag(str, &element);
    cr_assert_eq(result, 3);
    cr_assert_eq(element.zero_flag, true);
    cr_assert_eq(element.width, 5);
    cr_assert_eq(element.precision, 0);
    cr_assert_eq(element.end_flag, true);
}

Test(handle_format_width, test_handle_format_width_no_flags, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "5";

    int result = handle_format_width(str, &element);
    cr_assert_eq(result, 1);
    cr_assert_eq(element.padding_flag, true);
    cr_assert_eq(element.is_format, true);
    cr_assert_eq(element.width, 5);
}

Test(handle_format_width, test_handle_format_width_minus_flag, .init = redirect_all_std)
{
    element_t element = { .minus_flag = true };
    char const *str = "5";

    int result = handle_format_width(str, &element);
    cr_assert_eq(result, 1);
    cr_assert_eq(element.padding_flag, false);
    cr_assert_eq(element.is_format, true);
    cr_assert_eq(element.width, 5);
}

Test(handle_format_width, test_handle_format_width_zero_flag, .init = redirect_all_std)
{
    element_t element = { .zero_flag = true };
    char const *str = "5";

    int result = handle_format_width(str, &element);
    cr_assert_eq(result, 1);
    cr_assert_eq(element.padding_flag, false);
    cr_assert_eq(element.is_format, true);
    cr_assert_eq(element.width, 5);
}

Test(handle_format_width, test_handle_format_width_both_flags, .init = redirect_all_std)
{
    element_t element = { .minus_flag = true, .zero_flag = true };
    char const *str = "5";

    int result = handle_format_width(str, &element);
    cr_assert_eq(result, 1);
    cr_assert_eq(element.padding_flag, false);
    cr_assert_eq(element.is_format, true);
    cr_assert_eq(element.width, 5);
}

Test(handle_format, test_handle_format_with_end_flag, .init = redirect_all_std)
{
    element_t element = {0};
    char const *str = "5.2";

    int length = handle_format(str, &element);
    cr_assert_eq(length, 3);
    cr_assert_eq(element.width, 5);
    cr_assert_eq(element.precision, 2);
    cr_assert_eq(element.end_flag, true);
}
