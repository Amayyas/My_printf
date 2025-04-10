/*
** EPITECH PROJECT, 2024
** my_putchar_plus.c
** File description:
** My put char plus
*/

#include "my.h"
#include <unistd.h>

void my_putchar_plus(int fd, char c)
{
    write(fd, &c, 1);
}
