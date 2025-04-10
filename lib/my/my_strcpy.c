/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** Copy string
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    if (*src == '\0') {
        *dest = '\0';
        return (dest);
    }
    *dest = *src;
    my_strcpy(dest + 1, src + 1);
    return (dest);
}
