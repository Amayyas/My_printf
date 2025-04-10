/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** Concat two str
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    if (*dest == '\0') {
        if (*src == '\0') {
            return (dest);
        }
        *dest = *src;
        *(dest + 1) = '\0';
        my_strcat(dest + 1, src + 1);
    } else {
        my_strcat(dest + 1, src);
    }
    return (dest);
}
