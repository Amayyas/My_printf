/*
** EPITECH PROJECT, 2024
** my_revstr.c
** File description:
** Reverse string
*/

#include "my.h"

static void my_swap_char(char *a, char *b)
{
    char tempA = *a;

    *a = *b;
    *b = tempA;
}

static char *my_revstr_rec(char *str, int start, int end)
{
    if (start >= end) {
        return (str);
    }
    my_swap_char(&str[start], &str[end]);
    return (my_revstr_rec(str, start + 1, end - 1));
}

char *my_revstr(char *str)
{
    int length = my_strlen(str);

    return (my_revstr_rec(str, 0, length - 1));
}
