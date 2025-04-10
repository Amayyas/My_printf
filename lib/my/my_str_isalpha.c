/*
** EPITECH PROJECT, 2024
** my_str_isaplha.c
** File description:
** Is alpha
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    if (*str == '\0') {
        return (1);
    }
    if (*str >= 'a' && *str <= 'z') {
        return (my_str_isalpha(str + 1));
    }
    if (*str >= 'A' && *str <= 'Z') {
        return (my_str_isalpha(str + 1));
    }
    return (0);
}
