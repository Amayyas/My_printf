/*
** EPITECH PROJECT, 2024
** my_sort_int_array.c
** File description:
** Sort array
*/

#include "my.h"

static int sorting_pass(int *array, int size)
{
    int swapped = 0;

    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            my_swap(&array[i], &array[i + 1]);
            swapped = 1;
        }
    }
    return (swapped);
}

void my_sort_int_array(int *array, int size)
{
    while (sorting_pass(array, size)) {
        size--;
    }
}
