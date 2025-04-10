/*
** EPITECH PROJECT, 2024
** my_formatting.c
** File description:
** Formatting functions
*/

#include "my.h"

void my_put_space(element_t *element, int nb, int *counter)
{
    if (!element->is_format || nb < 0) {
        return;
    }
    if (element->space_flag && !element->plus_flag) {
        *counter += my_putchar(' ');
    }
}

void my_put_plus(element_t *element, int nb, int *counter)
{
    if (!element->is_format || nb < 0) {
        return;
    }
    if (element->plus_flag) {
        *counter += my_putchar('+');
    }
}

void my_put_hash(element_t *element, char const *base, int *counter)
{
    if (!element->is_format || !element->hash_flag) {
        return;
    }
    if (my_strcmp(base, HEX_CHARS) == 0 ||
        my_strcmp(base, HEX_CHARS_MAJ) == 0) {
        *counter += my_putstr("0x");
    }
    if (my_strcmp(base, OCTAL_CHARS) == 0) {
        *counter += my_putchar('0');
    }
    if (my_strcmp(base, "01") == 0) {
        *counter += my_putstr("0b");
    }
}

void my_put_width(element_t *element, int length, int *counter)
{
    int width;

    if (!element->is_format ||
        (!element->padding_flag && !element->minus_flag &&
            !element->star_flag)) {
        return;
    }
    if (element->width <= length) {
        return;
    }
    width = element->width - length;
    while (width > 0) {
        *counter += my_putchar(' ');
        width--;
    }
}
