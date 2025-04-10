/*
** EPITECH PROJECT, 2024
** my_puy_nbr.c
** File description:
** Put nbr
*/

#include "my.h"

static void compute_ptr(int digit, int *started, int *counter)
{
    if (digit != 0 || *started) {
        *counter += my_putchar(HEX_CHARS[digit]);
        *started = 1;
    }
}

static void print_address(unsigned long long addr, int *counter)
{
    int started = 0;
    int digit;

    for (int i = (sizeof(addr) * 8) - 4; i >= 0; i -= 4) {
        digit = (addr >> i) & 0xF;
        compute_ptr(digit, &started, counter);
    }
    if (!started) {
        *counter += my_putchar('0');
    }
}

int my_put_ptr(element_t *element)
{
    void *ptr = va_arg(*(element->args), void *);
    unsigned long long addr = (unsigned long long) ptr;
    int counter = 0;
    int nb_len = ptr == NULL ? 5 : my_ptr_len(ptr) - 4;

    my_put_space(element, addr, &counter);
    if (!element->minus_flag &&
        (element->padding_flag || element->star_flag)) {
        my_put_width(element, nb_len, &counter);
    }
    if (ptr == NULL) {
        counter += my_putstr("(nil)");
    } else {
        counter += my_putstr("0x");
        print_address(addr, &counter);
    }
    if (element->minus_flag && !element->padding_flag) {
        my_put_width(element, nb_len, &counter);
    }
    return (counter);
}
