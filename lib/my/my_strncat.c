/*
** EPITECH PROJECT, 2024
** my_strcnat.c
** File description:
** Concat two str for n
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    if (nb == 0) {
        return (dest);
    }
    if (*dest == '\0') {
        if (*src == '\0') {
            return (dest);
        }
        *dest = *src;
        *(dest + 1) = '\0';
        my_strncat(dest + 1, src + 1, nb - 1);
    } else {
        my_strncat(dest + 1, src, nb);
    }
    return (dest);
}
