/*
** EPITECH PROJECT, 2024
** my_puy_nbr.c
** File description:
** Put nbr
*/

#include "my.h"

static void my_put_unsigned_long_rec(unsigned long nb, int *counter)
{
    if (nb >= 10) {
        my_put_unsigned_long_rec(nb / 10, counter);
        my_put_unsigned_long_rec(nb % 10, counter);
    } else {
        *counter += my_putchar(nb + '0');
    }
}

int my_put_unsigned_long(element_t *element)
{
    unsigned long nb = va_arg(*(element->args), unsigned long);
    int counter = 0;

    my_put_unsigned_long_rec(nb, &counter);
    return (counter);
}

static void my_put_unsigned_long_long_rec(unsigned long long nb,
    int *counter)
{
    if (nb >= 10) {
        my_put_unsigned_long_long_rec(nb / 10, counter);
        my_put_unsigned_long_long_rec(nb % 10, counter);
    } else {
        *counter += my_putchar(nb + '0');
    }
}

int my_put_unsigned_long_long(element_t *element)
{
    unsigned long long nb = va_arg(*(element->args), unsigned long long);
    int counter = 0;

    my_put_unsigned_long_long_rec(nb, &counter);
    return (counter);
}
