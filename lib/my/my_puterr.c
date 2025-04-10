/*
** EPITECH PROJECT, 2024
** my_puterr.c
** File description:
** Put err func
*/

#include "my.h"

int my_puterr(char const *str)
{
    if (*str == '\0') {
        return (0);
    }
    my_putchar_plus(2, *str);
    my_puterr(str + 1);
    return (0);
}
