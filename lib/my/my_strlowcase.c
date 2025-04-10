/*
** EPITECH PROJECT, 2024
** my_strlowcase.c
** File description:
** Lowercase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    if (*str == '\0') {
        return (str);
    }
    if (*str >= 'A' && *str <= 'Z') {
        *str = *str + 32;
    }
    my_strlowcase(str + 1);
    return (str);
}
