/*
** EPITECH PROJECT, 2024
** my_printf.c
** File description:
** Printf
*/

#include "my.h"

static void compute_printf(char const *format, int length, int *char_count,
    va_list *args)
{
    while (*format) {
        if (*format != '%') {
            *char_count += my_putchar(*format);
            format++;
            continue;
        }
        format++;
        length = call_format_function(format, args, char_count);
        format += length;
    }
}

int my_printf(char const *format, ...)
{
    int length = 0;
    int char_count = 0;
    va_list args;

    va_start(args, format);
    compute_printf(format, length, &char_count, &args);
    va_end(args);
    return (char_count);
}
