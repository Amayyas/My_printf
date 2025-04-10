/*
** EPITECH PROJECT, 2024
** my_puy_nbr.c
** File description:
** Put nbr
*/

#include "my.h"

static void my_put_long_rec(long nb, int *counter)
{
    if (nb == LONG_MIN) {
        *counter += my_putstr("-9223372036854775808");
        return;
    }
    if (nb < 0) {
        *counter += my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_long_rec(nb / 10, counter);
        my_put_long_rec(nb % 10, counter);
    } else {
        *counter += my_putchar(nb + '0');
    }
}

int my_put_long(element_t *element)
{
    long nb = va_arg(*(element->args), long);
    int counter = 0;
    int nb_len = my_float_len(nb);

    if (!element->minus_flag && element->padding_flag) {
        my_put_width(element, nb_len, &counter);
    }
    my_put_long_rec(nb, &counter);
    if (element->minus_flag && !element->padding_flag) {
        my_put_width(element, nb_len, &counter);
    }
    return (counter);
}

static void my_put_long_long_rec(long long nb, int *counter)
{
    if (nb == LLONG_MIN) {
        *counter += my_putstr("-9223372036854775808");
        return;
    }
    if (nb < 0) {
        *counter += my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_long_long_rec(nb / 10, counter);
        my_put_long_long_rec(nb % 10, counter);
    } else {
        *counter += my_putchar(nb + '0');
    }
}

int my_put_long_long(element_t *element)
{
    long long nb = va_arg(*(element->args), long long);
    int counter = 0;
    int nb_len = my_float_len(nb);

    if (!element->minus_flag && element->padding_flag) {
        my_put_width(element, nb_len, &counter);
    }
    my_put_long_long_rec(nb, &counter);
    if (element->minus_flag && !element->padding_flag) {
        my_put_width(element, nb_len, &counter);
    }
    return (counter);
}
