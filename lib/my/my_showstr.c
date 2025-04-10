/*
** EPITECH PROJECT, 2024
** my_showstr.c
** File description:
** Show str
*/

#include "my.h"

static int is_printable(char c)
{
    return (c >= 32 && c <= 126);
}

int my_showstr(char const *str)
{
    if (*str == '\0') {
        return (0);
    }
    if (is_printable(*str)) {
        my_putchar(*str);
    } else {
        my_putchar('\\');
        my_putchar(HEX_CHARS[(*str / 16) % 16]);
        my_putchar(HEX_CHARS[*str % 16]);
    }
    my_showstr(str + 1);
    return (0);
}
