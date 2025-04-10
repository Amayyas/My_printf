/*
** EPITECH PROJECT, 2024
** my_putnbr_base.c
** File description:
** Put nbr
*/

#include "my.h"

int my_putnbr_base(int nbr, char const *base, int *counter)
{
    int base_len = 0;

    while (base[base_len] != '\0') {
        base_len++;
    }
    if (nbr < 0) {
        *counter += my_putchar('-');
        nbr = -nbr;
    }
    if (nbr >= base_len) {
        *counter += my_putnbr_base(nbr / base_len, base, counter);
    }
    *counter += my_putchar(base[nbr % base_len]);
    return (*counter);
}

int my_put_hex(element_t *element)
{
    int nb = va_arg(*(element->args), int);
    int counter = 0;
    int nb_len = my_nbr_base_len(nb, HEX_CHARS);

    if (element->hash_flag) {
        nb_len += 2;
    }
    if (!element->minus_flag &&
        (element->padding_flag || element->star_flag)) {
        my_put_width(element, nb_len, &counter);
    }
    my_put_zero_base(element, nb, &counter, HEX_CHARS);
    if (nb > 0) {
        my_put_hash(element, HEX_CHARS, &counter);
    }
    my_putnbr_base(nb, HEX_CHARS, &counter);
    if (element->minus_flag && !element->padding_flag) {
        my_put_width(element, nb_len, &counter);
    }
    return (counter);
}

int my_put_hexmaj(element_t *element)
{
    int nb = va_arg(*(element->args), int);
    int counter = 0;
    int nb_len = my_nbr_base_len(nb, HEX_CHARS_MAJ);

    if (element->hash_flag) {
        nb_len += 2;
    }
    if (!element->minus_flag &&
        (element->padding_flag || element->star_flag)) {
        my_put_width(element, nb_len, &counter);
    }
    my_put_zero_base(element, nb, &counter, HEX_CHARS_MAJ);
    if (nb > 0) {
        my_put_hash(element, HEX_CHARS_MAJ, &counter);
    }
    my_putnbr_base(nb, HEX_CHARS_MAJ, &counter);
    if (element->minus_flag && !element->padding_flag) {
        my_put_width(element, nb_len, &counter);
    }
    return (counter);
}

int my_put_octal(element_t *element)
{
    int nb = va_arg(*(element->args), int);
    int counter = 0;
    int nb_len = my_nbr_base_len(nb, OCTAL_CHARS);

    if (element->hash_flag) {
        nb_len += 1;
    }
    if (!element->minus_flag &&
        (element->padding_flag || element->star_flag)) {
        my_put_width(element, nb_len, &counter);
    }
    my_put_zero_base(element, nb, &counter, OCTAL_CHARS);
    if (nb > 0) {
        my_put_hash(element, OCTAL_CHARS, &counter);
    }
    my_putnbr_base(nb, OCTAL_CHARS, &counter);
    if (element->minus_flag && !element->padding_flag) {
        my_put_width(element, nb_len, &counter);
    }
    return (counter);
}

int my_put_binary(element_t *element)
{
    int nb = va_arg(*(element->args), int);
    int counter = 0;
    int nb_len = my_nbr_base_len(nb, "01");

    if (element->hash_flag) {
        nb_len += 2;
    }
    if (!element->minus_flag &&
        (element->padding_flag || element->star_flag)) {
        my_put_width(element, nb_len, &counter);
    }
    my_put_zero_base(element, nb, &counter, "01");
    if (nb > 0) {
        my_put_hash(element, "01", &counter);
    }
    my_putnbr_base(nb, "01", &counter);
    if (element->minus_flag && !element->padding_flag) {
        my_put_width(element, nb_len, &counter);
    }
    return (counter);
}
