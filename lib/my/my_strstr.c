/*
** EPITECH PROJECT, 2024
** my_strstr.c
** File description:
** Find str in str
*/

#include "my.h"
#include <stddef.h>

static int compute_strstr(char *s, char const *to_find)
{
    char *start = s;
    char const *tf = to_find;

    while (*start != '\0' && *tf != '\0' && *start == *tf) {
        start++;
        tf++;
    }
    if (*tf == '\0') {
        return (1);
    }
    return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    if (*to_find == '\0') {
        return (str);
    }
    for (char *s = str; *s != '\0'; s++) {
        if (compute_strstr(s, to_find)) {
            return (s);
        }
    }
    return (NULL);
}
