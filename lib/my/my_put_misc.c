/*
** EPITECH PROJECT, 2024
** my_put_misc.c
** File description:
** My put misc
*/

#include "my.h"

int my_put_percentage(element_t *element)
{
    (void)element;
    my_putchar('%');
    return (1);
}

void my_put_char_count(element_t *element)
{
    int *nb = va_arg(*(element->args), int *);

    *nb = element->char_count;
}

int my_put_invalid_format(char invalid_format)
{
    my_putchar('%');
    my_putchar(invalid_format);
    return (2);
}
