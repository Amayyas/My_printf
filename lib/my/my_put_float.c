/*
** EPITECH PROJECT, 2024
** my_put_float.c
** File description:
** Put float
*/

#include "my.h"

static void compute_put_float(int precision,
    double *frac_part, int *counter)
{
    int digit;

    for (int i = 0; i < precision; i++) {
        *frac_part *= 10;
        digit = (int)*frac_part;
        *counter += my_putchar(digit + '0');
        *frac_part -= digit;
    }
}

static void compute_put_neg(int *counter, double *nb, int *int_part,
    double *frac_part)
{
    *counter += my_putchar('-');
    *nb = -(*nb);
    *int_part = -(*int_part);
    *frac_part = -(*frac_part);
}

static void my_put_float_rec(element_t *element, double nb, int *counter)
{
    int int_part = (int)nb;
    double frac_part = nb - int_part;
    double rounding_factor = 0.5;

    if (nb < 0 || (1.0 / nb) < 0) {
        compute_put_neg(counter, &nb, &int_part, &frac_part);
    }
    for (int i = 0; i < element->precision; i++) {
        rounding_factor /= 10.0;
    }
    frac_part += rounding_factor;
    if (frac_part >= 1.0) {
        int_part++;
        frac_part -= 1.0;
    }
    my_put_nbr_rec(element, int_part, counter);
    if (element->precision > 0) {
        *counter += my_putchar('.');
        compute_put_float(element->precision, &frac_part, counter);
    }
}

int my_put_float(element_t *element)
{
    double nb = va_arg(*(element->args), double);
    int counter = 0;
    int nb_len = my_float_len_prec(nb, element->precision);

    if (nb == 0 && element->precision != 0 && element->width != 0) {
        element->width--;
        element->is_zero = true;
    }
    my_put_space(element, nb, &counter);
    if (!element->minus_flag &&
        (element->padding_flag || element->star_flag)) {
        my_put_width(element, nb_len, &counter);
    }
    my_put_zero_float(element, nb, &counter);
    my_put_plus(element, nb, &counter);
    my_put_float_rec(element, nb, &counter);
    if (element->minus_flag && !element->padding_flag) {
        my_put_width(element, nb_len, &counter);
    }
    return (counter);
}

static void my_put_exp_rec(double number, int exponent, element_t *element,
    int *counter)
{
    if (number >= 10.0) {
        my_put_exp_rec(number / 10.0, exponent + 1, element, counter);
        return;
    }
    if (number < 1.0 && number != 0.0) {
        my_put_exp_rec(number * 10.0, exponent - 1, element, counter);
        return;
    }
    my_put_nbr_rec(element, (int) number, counter);
    *counter += my_putchar('.');
    number -= (int) number;
    for (int i = 0; i < element->precision; i++) {
        number *= 10.0;
        *counter += my_putchar((int) number + '0');
        number -= (int) number;
    }
}

static void my_put_exp_exponent(int exponent, element_t *element, int *counter)
{
    *counter += my_putchar(element->is_maj ? 'E' : 'e');
    *counter += my_putchar(exponent >= 0 ? '+' : '-');
    if (exponent < 0) {
        exponent = -exponent;
    }
    if (exponent < 10) {
        *counter += my_putchar('0');
    }
    my_put_nbr_rec(element, exponent, counter);
}

int my_put_exp(element_t *element)
{
    double number = va_arg(*(element->args), double);
    int counter = 0;
    int nb_len = my_nbr_exp_len(number);

    if (!element->minus_flag &&
        (element->padding_flag || element->star_flag)) {
        my_put_width(element, nb_len, &counter);
    }
    if (number < 0) {
        counter += my_putchar('-');
        number = -number;
    }
    my_put_exp_rec(number, 0, element, &counter);
    my_put_exp_exponent(0, element, &counter);
    if (element->minus_flag && !element->padding_flag) {
        my_put_width(element, nb_len, &counter);
    }
    return (counter);
}

int my_nbr_exp_len(double nb)
{
    int counter = 0;

    if (nb < 0) {
        counter++;
        nb = -nb;
    }
    counter += 1 + 1 + 6;
    counter += 1 + 1 + 2;
    return (counter);
}
