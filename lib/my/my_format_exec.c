/*
** EPITECH PROJECT, 2024
** my_format_exec.c
** File description:
** Format exec
*/

#include "my.h"

format_t const FORMATS[] = {
    {"c", (void *) my_putchar_va},
    {"s", (void *) my_putstr_va},
    {"i", (void *) my_put_nbr},
    {"d", (void *) my_put_nbr},
    {"f", (void *) my_put_float},
    {"F", (void *) my_put_float},
    {"u", (void *) my_put_nbr_unsigned},
    {"e", (void *) my_put_exp},
    {"E", (void *) my_put_exp},
    {"g", (void *) my_put_g},
    {"G", (void *) my_put_g},
    {"n", (void *) my_put_char_count},
    {"x", (void *) my_put_hex},
    {"X", (void *) my_put_hexmaj},
    {"o", (void *) my_put_octal},
    {"b", (void *) my_put_binary},
    {"p", (void *) my_put_ptr},
    {"ld", (void *) my_put_long},
    {"lu", (void *) my_put_unsigned_long},
    {"lld", (void *) my_put_long_long},
    {"llu", (void *) my_put_unsigned_long_long},
    {"hd", (void *) my_put_short},
    {"hu", (void *) my_put_short_unsigned},
    {"%", (void *) my_put_percentage},
};

int get_format_length(char const *str, element_t *element)
{
    char const one_char_formats[17] = {'c', 's', 'i', 'd',
        'u', 'e', 'E', 'g', 'G', 'x', 'X', 'o', 'f', 'F', 'n', 'p', 'b'};
    int length = 1;

    element->is_format = false;
    if (*str == '%') {
        return (length);
    }
    if (*str == 'l' || *str == 'h') {
        return (handle_advanced_format(str));
    }
    if (!my_isalpha(*str)) {
        return (handle_format(str, element));
    }
    for (size_t i = 0; i < sizeof(one_char_formats); i++) {
        if (*str == one_char_formats[i]) {
            return (1);
        }
    }
    return (0);
}

void compute_format(char const *format_str, element_t *element, int i,
    int *char_count)
{
    if (format_str[0] == 'f' || format_str[0] == 'F') {
        if (element->precision == 0) {
            element->precision = 6;
        }
    }
    if (format_str[0] == 'n') {
        element->char_count = *char_count;
    }
    if (format_str[0] == 'E' || format_str[0] == 'G') {
        element->is_maj = true;
    }
    *char_count += FORMATS[i].pf(element);
}

int find_and_compute_format(char const *str, element_t *element,
    int length, int *char_count)
{
    if (element->is_format) {
        length = 1;
    }
    for (size_t i = 0; i < sizeof(FORMATS) / sizeof(FORMATS[0]); i++) {
        if (my_strncmp(str, FORMATS[i].str, length) == 0) {
            compute_format(str, element, i, char_count);
            return (1);
        }
    }
    return (0);
}
