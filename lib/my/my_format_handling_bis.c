/*
** EPITECH PROJECT, 2024
** my_format_handling_bis.c
** File description:
** Format handling bis
*/

#include "my.h"

int handle_hash_flag(char const *str, element_t *element)
{
    element->hash_flag = true;
    str++;
    if (*str == '*') {
        element->star_flag = true;
        element->is_dynamic = true;
        element->width = va_arg(*(element->args), int);
        return (2);
    }
    if (my_isnum(*str)) {
        return (handle_format_width(str, element) + 1);
    }
    return (1);
}

int handle_end_flag(char const *str, element_t *element)
{
    int length = 0;

    if (my_isnum(*str)) {
        if (!element->minus_flag && !element->zero_flag) {
            element->padding_flag = true;
        }
        element->is_format = true;
        element->width = my_getnbr(str);
        while (my_isnum(*str)) {
            str++;
            length++;
        }
    }
    length += handle_format_precision(str, element);
    if (length != 0) {
        element->end_flag = true;
    }
    return (length);
}
