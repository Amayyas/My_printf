/*
** EPITECH PROJECT, 2024
** my_str_islower.c
** File description:
** Is lower
*/

#include "my.h"

int my_str_islower(char const *str)
{
    if (*str == '\0') {
        return (1);
    }
    if (*str >= 'a' && *str <= 'z') {
        return (my_str_islower(str + 1));
    }
    return (0);
}
