/*
** EPITECH PROJECT, 2024
** my_put_short_unsigned.c
** File description:
** Put short unsigned
*/

#include "my.h"

static void my_put_short_unsigned_rec(unsigned short int nb, int *counter)
{
    if (nb == USHRT_MAX) {
        *counter += my_putstr("65535");
        return;
    }
    if (nb >= 10) {
        my_put_short_unsigned_rec(nb / 10, counter);
        my_put_short_unsigned_rec(nb % 10, counter);
    } else {
        *counter += my_putchar(nb + '0');
    }
}

void my_put_short_unsigned(element_t *element)
{
    unsigned short int nb = va_arg(*(element->args), int);
    int counter = 0;

    my_put_short_unsigned_rec(nb, &counter);
}
