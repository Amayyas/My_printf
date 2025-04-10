/*
** EPITECH PROJECT, 2024
** my_format_compute.c
** File description:
** Format compute
*/

#include "my.h"

int handle_advanced_format(char const *str)
{
    int length = 1;

    str++;
    length++;
    if (*str == 'l') {
        str++;
        length++;
    }
    if (*str == 'd' || *str == 'u') {
        return (length);
    }
    return (0);
}

static int handle_plus_advanced(char const *str, element_t *element)
{
    if (*str == '0') {
        return (handle_zero_flag(str, element) + 1);
    } else {
        return (handle_format_width(str, element) + 1);
    }
}

static int handle_formats_flags_bis(char const *str, element_t *element)
{
    switch (*str) {
        case '-':
            return (handle_minus_flag(str, element));
        case '0':
            return (handle_zero_flag(str, element));
        case '.':
            if (*(str + 1) == '*') {
                element->is_dynamic = true;
                element->precision = va_arg(*(element->args), int);
                return (2);
            }
            return (handle_format_precision(str, element));
        default:
            element->is_format = false;
            return (0);
    }
    return (1);
}

static int handle_format_flags(char const *str, element_t *element)
{
    element->is_format = true;
    switch (*str) {
        case ' ':
            element->space_flag = true;
            break;
        case '+':
            element->plus_flag = true;
            str++;
            if (my_isnum(*str)) {
                return (handle_plus_advanced(str, element));
            }
            break;
        case '*':
            return (handle_star_flag(str, element));
        case '#':
            return (handle_hash_flag(str, element));
        default:
            return (handle_formats_flags_bis(str, element));
    }
    return (1);
}

static void compute_num_format(int nb_len, int *length, char const *str,
    element_t *element)
{
    if (str[nb_len] == '.') {
        *length = handle_end_flag(str, element);
    } else {
        *length = handle_format_width(str, element);
    }
}

int handle_format(char const *str, element_t *element)
{
    int length = handle_format_flags(str, element);
    int nb_len = 0;

    if (length == 0) {
        if (my_isnum(str[0])) {
            nb_len = my_nbr_len(my_getnbr(str));
            compute_num_format(nb_len, &length, str, element);
        }
    }
    return (length);
}
