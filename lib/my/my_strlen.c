/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** String length
*/

#include "my.h"

int my_strlen(char const *str)
{
    if (*str == '\0') {
        return (0);
    }
    return (1 + my_strlen(str + 1));
}

int my_str_len_prec(char const *str, int precision)
{
    int counter = 0;

    while (str[counter] != '\0' && counter < precision) {
        counter++;
    }
    return (counter);
}

int my_nbr_len(long nb)
{
    if (nb < 0) {
        nb = -nb;
        return (1 + my_nbr_len(nb));
    }
    if (nb < 10) {
        return (1);
    }
    return (1 + my_nbr_len(nb / 10));
}

int my_float_len(double nb)
{
    int int_part = (int)nb;
    double frac_part = nb - int_part;
    int counter = 0;

    counter += my_nbr_len(int_part);
    counter += 1;
    for (int i = 0; i < 6; i++) {
        frac_part *= 10;
        counter++;
        if ((int)frac_part == 0) {
            break;
        }
    }
    return (counter);
}

int my_float_len_prec(double nb, int precision)
{
    int int_part = (int)nb;
    double frac_part = nb - int_part;
    int counter = 0;

    counter += my_nbr_len(int_part);
    counter += 1;
    for (int i = 0; i < precision; i++) {
        frac_part *= 10;
        counter++;
        if ((int)frac_part == 0) {
            break;
        }
    }
    return (counter);
}
