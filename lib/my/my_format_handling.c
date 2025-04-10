/*
** EPITECH PROJECT, 2024
** my_format_handling.c
** File description:
** Format handling
*/

#include "my.h"

int handle_format_width(char const *str, element_t *element)
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
    return (length);
}

int handle_format_precision(char const *str, element_t *element)
{
    int length = 0;

    if (*str == '.') {
        element->is_format = true;
        str++;
        length++;
        element->precision = my_getnbr(str);
        while (my_isnum(*str)) {
            str++;
            length++;
        }
    }
    return (length);
}

int handle_minus_flag(char const *str, element_t *element)
{
    int nb_len;

    element->minus_flag = true;
    str++;
    nb_len = my_nbr_len(my_getnbr(str));
    if (str[nb_len] == '.') {
        return (handle_end_flag(str, element) + 1);
    } else {
        return (handle_format_width(str, element) + 1);
    }
}

int handle_zero_flag(char const *str, element_t *element)
{
    int nb_len;

    element->zero_flag = true;
    str++;
    nb_len = my_nbr_len(my_getnbr(str));
    if (str[nb_len] == '.') {
        return (handle_end_flag(str, element) + 1);
    } else {
        return (handle_format_width(str, element) + 1);
    }
}

int handle_star_flag(char const *str, element_t *element)
{
    element->star_flag = true;
    element->width = va_arg(*(element->args), int);
    str++;
    if (*str == '.' && *(str + 1) == '*') {
        element->precision = va_arg(*(element->args), int);
        return (3);
    }
    return (1);
}
