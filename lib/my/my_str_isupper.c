/*
** EPITECH PROJECT, 2024
** my_str_isupper.c
** File description:
** Is upper
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    if (*str == '\0') {
        return (1);
    }
    if (*str >= 'A' && *str <= 'Z') {
        return (my_str_isupper(str + 1));
    }
    return (0);
}
