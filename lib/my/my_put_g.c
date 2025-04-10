/*
** EPITECH PROJECT, 2024
** my_put_g.c
** File description:
** Put g
*/

#include "my.h"

static bool is_scientific_notation_required(double number, int precision)
{
    int exponent = 0;

    if (number != 0.0) {
        while (number >= 10.0) {
            number /= 10.0;
            exponent++;
        }
        while (number < 1.0 && number != 0.0) {
            number *= 10.0;
            exponent--;
        }
    }
    return (exponent < -4 || exponent >= precision);
}

static int convert_to_string(int value, char *buffer)
{
    int index = 0;
    int temp_value = value;
    int digit_count = 0;

    while (temp_value > 0) {
        temp_value /= 10;
        digit_count++;
    }
    for (int i = digit_count - 1; i >= 0; i--) {
        buffer[i] = (value % 10) + '0';
        value /= 10;
    }
    index += digit_count;
    return index;
}

static int add_negative_sign(char *buffer, int index)
{
    buffer[index] = '-';
    index++;
    return (index);
}

int my_itoa(int value, char *buffer)
{
    int index = 0;
    bool is_negative = false;

    if (value == 0) {
        buffer[index] = '0';
        index++;
        buffer[index] = '\0';
        return (index);
    }
    if (value < 0) {
        is_negative = true;
        value = -value;
    }
    index = convert_to_string(value, buffer);
    if (is_negative) {
        index = add_negative_sign(buffer, index);
    }
    buffer[index] = '\0';
    return (index);
}

static void double_to_string(char *buffer, double number, int precision)
{
    int int_part = (int) number;
    int len = my_itoa(int_part, buffer);
    double fractional_part = number - int_part;

    if (precision > 0) {
        buffer[len] = '.';
        len++;
        for (int i = 0; i < precision; i++) {
            fractional_part *= 10;
            buffer[len] = '0' + (int) fractional_part;
            len++;
            fractional_part -= (int) fractional_part;
        }
        while (len > 0 && buffer[len - 1] == '0')
            len--;
        if (len > 0 && buffer[len - 1] == '.')
            len--;
    }
    buffer[len] = '\0';
}

static int adjust_precision_and_format(element_t *element, double number)
{
    int significant_digits = (element->precision > 0) ? element->precision : 6;
    char buffer[100];
    int printed_chars = 0;

    if (is_scientific_notation_required(number, significant_digits)) {
        element->precision = (significant_digits == 0) ?
            1 : significant_digits - 1;
        printed_chars = my_put_exp(element);
    } else {
        element->precision = significant_digits;
        double_to_string(buffer, number, significant_digits);
        printed_chars = my_putstr(buffer);
    }
    return (printed_chars);
}

int my_put_g(element_t *element)
{
    va_list args_copy;
    double number;
    int counter = 0;

    va_copy(args_copy, *(element->args));
    number = va_arg(args_copy, double);
    va_end(args_copy);
    counter += adjust_precision_and_format(element, number);
    return counter;
}
