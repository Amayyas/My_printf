/*
** EPITECH PROJECT, 2024
** my_formatting_bis.c
** File description:
** Formatting bis
*/

#include "my.h"

void my_put_zero(element_t *element, int nb, int *counter)
{
    int width;
    int nbrLen = my_nbr_len(nb);

    if (!element->is_format || !element->zero_flag)
        return;
    if (element->width <= nbrLen)
        return;
    if (element->plus_flag) {
        if (!element->is_unsigned)
            nbrLen++;
        if (nb < 0) {
            *counter += my_putchar('-');
            nbrLen--;
        }
    }
    width = element->width - nbrLen;
    while (width > 0) {
        *counter += my_putchar('0');
        width--;
    }
}

void my_put_zero_float(element_t *element, double nb, int *counter)
{
    int width;
    int nbrLen = element->precision == 0 ?
        my_float_len(nb) : my_float_len_prec(nb, element->precision);

    if (!element->is_format || !element->zero_flag) {
        return;
    }
    if (element->width <= nbrLen) {
        return;
    }
    width = element->width - nbrLen;
    while (width > 0) {
        *counter += my_putchar('0');
        width--;
    }
}

void my_put_zero_base(element_t *element, int nb, int *counter, char *base)
{
    int width;
    int nbrLen = my_nbr_base_len(nb, base);

    if (!element->is_format || !element->zero_flag) {
        return;
    }
    if (element->width <= nbrLen) {
        return;
    }
    width = element->width - nbrLen;
    while (width > 0) {
        *counter += my_putchar('0');
        width--;
    }
}
