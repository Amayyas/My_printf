/*
** EPITECH PROJECT, 2024
** my_put_va.c
** File description:
** My put va
*/

#include "my.h"

int my_putchar_va(element_t *element)
{
    char const c = va_arg(*(element->args), int);
    int counter = 0;

    if (!element->minus_flag &&
        (element->padding_flag || element->star_flag)) {
        my_put_width(element, 1, &counter);
    }
    write(1, &c, 1);
    if (element->minus_flag && !element->padding_flag) {
        my_put_width(element, 1, &counter);
    }
    return (counter);
}

static void compute_putstr(int temp_precision, bool *has_precision,
    char const *str, int *counter)
{
    if (temp_precision != 0) {
        *has_precision = true;
    }
    if (!*has_precision) {
        while (*str) {
            *counter += my_putchar(*str);
            str++;
        }
    } else {
        while (*str && temp_precision != 0) {
            *counter += my_putchar(*str);
            str++;
            temp_precision--;
        }
    }
}

static void handle_null_string(element_t *element, int *counter)
{
    if (element->precision == 0) {
        *counter += my_putstr("(null)");
    }
}

static void handle_string_width(element_t *element, int str_len, int *counter)
{
    if (!element->minus_flag &&
        (element->padding_flag || element->star_flag)) {
        my_put_width(element, str_len, counter);
    }
}

static void compute_length(int *str_len, char const *str, element_t *element)
{
    if (*str_len == 0) {
        if (element->precision == 0) {
            *str_len = my_strlen(str);
        } else {
            *str_len = my_str_len_prec(str, element->precision);
        }
    }
}

int my_putstr_va(element_t *element)
{
    char const *str = va_arg(*(element->args), char *);
    int counter = 0;
    int str_len = str == NULL ? 6 : 0;
    int temp_precision = element->precision;
    bool has_precision = false;

    compute_length(&str_len, str, element);
    if (str == NULL && element->precision != 0)
        element->width += 6;
    handle_string_width(element, str_len, &counter);
    if (str == NULL) {
        handle_null_string(element, &counter);
    } else {
        element->is_str = true;
        compute_putstr(temp_precision, &has_precision, str, &counter);
    }
    if (element->minus_flag && !element->padding_flag) {
        my_put_width(element, str_len, &counter);
    }
    return (counter);
}
