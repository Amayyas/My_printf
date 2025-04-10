/*
** EPITECH PROJECT, 2024
** my_str_isaplha.c
** File description:
** Is alpha
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    if (*str == '\0') {
        return (1);
    }
    if (*str >= '0' && *str <= '9') {
        return (my_str_isnum(str + 1));
    }
    return (0);
}
