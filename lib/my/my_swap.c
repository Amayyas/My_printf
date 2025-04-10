/*
** EPITECH PROJECT, 2024
** my_swap.c
** File description:
** Swap to values
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int tempA = *a;

    *a = *b;
    *b = tempA;
}
