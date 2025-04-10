/*
** EPITECH PROJECT, 2024
** my_put_nbr_short.c
** File description:
** Short put
*/

#include "my.h"

static void my_put_short_rec(short int nb, int *counter)
{
    if (nb == SHRT_MIN) {
        *counter += my_putstr("-32768");
        return;
    }
    if (nb < 0) {
        *counter += my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_short_rec(nb / 10, counter);
        my_put_short_rec(nb % 10, counter);
    } else {
        *counter += my_putchar(nb + '0');
    }
}

int my_put_short(element_t *element)
{
    short nb = va_arg(*(element->args), int);
    int counter = 0;

    my_put_short_rec(nb, &counter);
    return (counter);
}
