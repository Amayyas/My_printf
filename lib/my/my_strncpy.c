/*
** EPITECH PROJECT, 2024
** my_strncpy.c
** File description:
** String copy n char
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    if (n == 0 || *src == '\0') {
        if (n > 0) {
            *dest = '\0';
            my_strncpy(dest + 1, src, n - 1);
        }
        return (dest);
    }
    *dest = *src;
    my_strncpy(dest + 1, src + 1, n - 1);
    return (dest);
}
