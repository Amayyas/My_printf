/*
** EPITECH PROJECT, 2024
** my_other_len.c
** File description:
** Other len
*/

#include "my.h"

int my_ptr_len(void *ptr)
{
    unsigned long long addr = (unsigned long long) ptr;
    int counter = 0;

    counter += 2;
    for (int i = (sizeof(addr) * 8) - 4; i >= 0; i -= 4) {
        counter++;
    }
    return (counter);
}

int my_nbr_base_len(int nbr, char const *base)
{
    int base_len = 0;
    int counter = 0;

    while (base[base_len] != '\0') {
        base_len++;
    }
    if (nbr < 0) {
        counter++;
        nbr = -nbr;
    }
    do {
        counter++;
        nbr /= base_len;
    } while (nbr > 0);
    return (counter);
}
