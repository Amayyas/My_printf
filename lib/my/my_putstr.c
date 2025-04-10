/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** Put string to term
*/

#include "my.h"

int my_putstr(char *str)
{
    int counter = 0;

    while (*str) {
        counter += my_putchar(*str);
        str++;
    }
    return (counter);
}
