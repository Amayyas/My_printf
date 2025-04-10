/*
** EPITECH PROJECT, 2024
** my_compute_square_root.c
** File description:
** Square compute
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    if (nb < 0) {
        return (0);
    }
    for (int i = 0; i * i <= nb; i++) {
        if (i * i != nb) {
            continue;
        }
        return (i);
    }
    return (0);
}
