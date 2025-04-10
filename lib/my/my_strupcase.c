/*
** EPITECH PROJECT, 2024
** my_strupcase.c
** File description:
** Uppercase
*/

#include "my.h"

char *my_strupcase(char *str)
{
    if (*str == '\0') {
        return (str);
    }
    if (*str >= 'a' && *str <= 'z') {
        *str = *str - 32;
    }
    my_strupcase(str + 1);
    return (str);
}
