/*
** EPITECH PROJECT, 2024
** my_printf_util.c
** File description:
** Printf utils
*/

#include "my.h"

static void def_element_base(element_t *element)
{
    element->precision = 0;
    element->width = 0;
    element->char_count = 0;
    element->is_str = false;
    element->hash_flag = false;
    element->is_format = false;
    element->is_maj = false;
    element->minus_flag = false;
    element->padding_flag = false;
    element->plus_flag = false;
    element->space_flag = false;
    element->zero_flag = false;
    element->star_flag = false;
    element->is_dynamic = false;
    element->end_flag = false;
    element->is_zero = false;
    element->is_unsigned = false;
}

static void compute_length_bis(element_t *element, int *length)
{
    if (element->end_flag) {
        *length += my_nbr_len(element->precision) + my_nbr_len(element->width)
            - *length + 2;
        *length += element->minus_flag ? 1 : 0;
    }
    if (element->is_zero)
        *length += 1;
    if (element->zero_flag && element->precision != 0 && element->width != 0)
        *length += 1;
    if (element->zero_flag && element->plus_flag)
        *length -= 1;
    if (element->padding_flag && element->plus_flag)
        *length -= 1;
}

static void compute_length(element_t *element, int *length)
{
    if (element->is_format && !element->minus_flag && !element->hash_flag)
        *length += *length;
    if (element->padding_flag)
        *length -= my_nbr_len(element->width) - 1;
    if (element->zero_flag)
        *length -= my_nbr_len(element->width);
    if (element->minus_flag)
        *length -= my_nbr_len(element->width) - *length;
    if (element->hash_flag && element->width != 0)
        *length += 2;
    if (element->hash_flag && element->width == 0)
        *length += 1;
    if (!element->is_dynamic &&
        (element->precision != 0 && element->precision != 6))
        *length += my_nbr_len(element->precision) - *length + 2;
    if (element->is_dynamic)
        *length -= 1;
    compute_length_bis(element, length);
}

int call_format_function(char const *format_str, va_list *args,
    int *char_count)
{
    element_t *element = malloc(sizeof(element_t));
    int length = 0;
    int found = 0;

    def_element_base(element);
    element->args = args;
    length = get_format_length(format_str, element);
    if (length == 0) {
        *char_count += my_put_invalid_format(*format_str);
        free(element);
        return (1);
    }
    if (element->is_format) {
        format_str += length;
    }
    found = find_and_compute_format(format_str, element, length, char_count);
    compute_length(element, &length);
    free(element);
    return (found ? length : 0);
}
