/*
** EPITECH PROJECT, 2024
** my_strcapitalize.c
** File description:
** Capitalize
*/

#include "my.h"

static int is_char_alpha(char c)
{
    if (c >= 'a' && c <= 'z') {
        return (1);
    }
    if (c >= 'A' && c <= 'Z') {
        return (1);
    }
    if (c >= '0' && c <= '9') {
        return (1);
    }
    return (0);
}

static void compute_capitalize(char *str)
{
    if (!is_char_alpha(*str)) {
        str++;
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 32;
        }
    }
}

char *my_strcapitalize(char *str)
{
    char *orig = my_strlowcase(str);

    if (*str >= 'a' && *str <= 'z') {
        *str = *str - 32;
    }
    str++;
    while (*str != '\0') {
        compute_capitalize(str);
        str++;
    }
    return (orig);
}
