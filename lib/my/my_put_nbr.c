/*
** EPITECH PROJECT, 2024
** my_puy_nbr.c
** File description:
** Put nbr
*/

#include "my.h"

void my_put_nbr_rec(element_t *element, int nb, int *counter)
{
    if (nb == INT_MIN) {
        *counter += my_putstr("-2147483648");
        return;
    }
    if (nb < 0) {
        if (!element->plus_flag || !element->zero_flag) {
            *counter += my_putchar('-');
        }
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr_rec(element, nb / 10, counter);
        my_put_nbr_rec(element, nb % 10, counter);
    } else {
        *counter += my_putchar(nb + '0');
    }
}

static void plus_flag_exe(element_t *element, int nb, int *temp_len)
{
    if (element->plus_flag) {
        (*temp_len)++;
        if (nb < 0) {
            (*temp_len)--;
        }
    }
}

int my_put_nbr(element_t *element)
{
    int nb = va_arg(*(element->args), int);
    int counter = 0;
    int nb_len = my_nbr_len(nb);
    int temp_len = nb_len;

    plus_flag_exe(element, nb, &temp_len);
    my_put_space(element, nb, &counter);
    if (!element->minus_flag &&
        (element->padding_flag || element->star_flag)) {
        my_put_width(element, temp_len, &counter);
    }
    my_put_plus(element, nb, &counter);
    my_put_zero(element, nb, &counter);
    my_put_nbr_rec(element, nb, &counter);
    if (element->minus_flag && !element->padding_flag) {
        my_put_width(element, nb_len, &counter);
    }
    return (counter);
}

static void my_put_nbr_unsigned_rec(unsigned int nb, int *counter)
{
    if (nb >= 10) {
        my_put_nbr_unsigned_rec(nb / 10, counter);
        my_put_nbr_unsigned_rec(nb % 10, counter);
    } else {
        *counter += my_putchar(nb + '0');
    }
}

int my_put_nbr_unsigned(element_t *element)
{
    int nb = va_arg(*(element->args), unsigned int);
    int counter = 0;
    int nb_len = my_nbr_len(nb);

    element->is_unsigned = true;
    my_put_space(element, nb, &counter);
    if (!element->minus_flag &&
        (element->padding_flag || element->star_flag)) {
        my_put_width(element, nb_len, &counter);
    }
    my_put_zero(element, nb, &counter);
    my_put_nbr_unsigned_rec(nb, &counter);
    if (element->minus_flag && !element->padding_flag) {
        my_put_width(element, nb_len, &counter);
    }
    return (counter);
}
