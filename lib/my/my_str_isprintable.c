/*
** EPITECH PROJECT, 2024
** my_str_isprintable.c
** File description:
** Is printable
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    if (*str == '\0') {
        return (1);
    }
    if (*str < ' ' || *str == 127) {
        return (0);
    }
    return (my_str_isprintable(str + 1));
}
