/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** Get nbr
*/

#include "my.h"

static int get_digit(char c)
{
    return (c - '0');
}

static int check_overflow(int result, char c, int sign)
{
    int const digit = get_digit(c);

    if (sign == 1 && result > (2147483647 - digit) / 10) {
        return (1);
    }
    if (sign == -1 && result > (2147483648 - digit) / 10) {
        return (1);
    }
    return (0);
}

int my_getnbr(char const *str)
{
    int result = 0;
    int sign = 1;

    while (*str != '\0' && (*str < '0' || *str > '9')) {
        if (*str == '-') {
            sign = -sign;
        }
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        if (check_overflow(result, *str, sign)) {
            return (0);
        }
        result = result * 10 + get_digit(*str);
        str++;
    }
    return (result * sign);
}
