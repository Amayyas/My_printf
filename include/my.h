/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** BIG HEADER
*/

#ifndef INCLUDE_MY_H
    #define INCLUDE_MY_H
    #define HEX_CHARS "0123456789abcdef"
    #define HEX_CHARS_MAJ "0123456789ABCDEF"
    #define OCTAL_CHARS "01234567"

    #include <stdarg.h>
    #include <limits.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdint.h>
    #include <stdbool.h>

typedef struct element {
    va_list *args;
    int precision;
    int char_count;
    int width;
    bool double_format;
    bool triple_format;
    bool is_str;
    bool is_maj;
    bool is_format;
    bool is_dynamic;
    bool space_flag;
    bool plus_flag;
    bool hash_flag;
    bool minus_flag;
    bool zero_flag;
    bool padding_flag;
    bool star_flag;
    bool end_flag;
    bool is_zero;
    bool is_unsigned;
} element_t;

typedef struct format {
    char *str;
    int (*pf)(element_t *element);
} format_t;

extern format_t const FORMATS[];

int my_putchar(char c);
void my_putchar_plus(int fd, char c);
int my_put_nbr(element_t *element);
void my_put_nbr_rec(element_t *element, int nb, int *counter);
int my_putnbr_base(int nbr, char const *base, int *counter);
int my_put_float(element_t *element);
int my_put_exp(element_t *element);
int my_put_g(element_t *element);
int my_putstr(char *str);
int my_puterr(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);

int my_strlen(char const *str);
int my_str_len_prec(char const *str, int precision);
int my_nbr_len(long nb);
int my_float_len(double nb);
int my_float_len_prec(double nb, int precision);
int my_ptr_len(void *ptr);
int my_nbr_base_len(int nbr, char const *base);
int my_nbr_exp_len(double nb);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);

int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_isalpha(char c);
int my_isnum(char c);

int my_isneg(int n);
int my_getnbr(char const *str);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int my_abs(int nb);

void my_swap(int *a, int *b);
void my_sort_int_array(int *array, int size);

int my_itoa(int value, char *buffer);

int my_printf(char const *format, ...);
void compute_format(char const *format_str, element_t *element, int i,
    int *char_count);
int call_format_function(char const *format_str, va_list *args,
    int *char_count);
int find_and_compute_format(char const *str, element_t *element,
    int length, int *char_count);

int handle_format_width(char const *str, element_t *element);
int handle_format_precision(char const *str, element_t *element);
int handle_minus_flag(char const *str, element_t *element);
int handle_zero_flag(char const *str, element_t *element);
int handle_star_flag(char const *str, element_t *element);
int handle_hash_flag(char const *str, element_t *element);
int handle_format(char const *str, element_t *element);
int handle_end_flag(char const *str, element_t *element);
int handle_advanced_format(char const *str);
int get_format_length(char const *str, element_t *element);

int my_putchar_va(element_t *element);
int my_putstr_va(element_t *element);
int my_put_percentage(element_t *element);
int my_put_nbr_unsigned(element_t *element);
int my_put_hex(element_t *element);
int my_put_hexmaj(element_t *element);
int my_put_octal(element_t *element);
int my_put_binary(element_t *element);
int my_put_ptr(element_t *element);
int my_put_long(element_t *element);
int my_put_long_long(element_t *element);
int my_put_unsigned_long(element_t *element);
int my_put_unsigned_long_long(element_t *element);
int my_put_short(element_t *element);
void my_put_short_unsigned(element_t *element);

void my_put_space(element_t *element, int nb, int *counter);
void my_put_plus(element_t *element, int nb, int *counter);
void my_put_hash(element_t *element, char const *base, int *counter);
void my_put_zero(element_t *element, int nb, int *counter);
void my_put_zero_float(element_t *element, double nb, int *counter);
void my_put_zero_base(element_t *element, int nb, int *counter, char *base);
void my_put_width(element_t *element, int length, int *counter);

void my_put_char_count(element_t *element);
int my_put_invalid_format(char invalid_format);

#endif
