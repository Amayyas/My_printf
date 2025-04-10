/*
** EPITECH PROJECT, 2024
** my_is.c
** File description:
** is functions
*/

#include "my.h"

int my_isnum(char c)
{
    return (c >= '0' && c <= '9');
}

int my_isalpha(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
