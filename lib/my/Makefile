##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile of the in
##

AR = ar rc
CFLAGS = -W -Wall -Wextra -Werror -fno-builtin -g3 -I../../include
SRC = ./my_strcat.c	\
	./my_put_ptr.c	\
	./my_str_isalpha.c	\
	./my_printf.c	\
	./my_revstr.c	\
	./my_printf_util.c	\
	./my_put_misc.c	\
	./my_strstr.c	\
	./my_isneg.c	\
	./my_putchar_plus.c	\
	./my_put_nbr.c	\
	./my_put_long.c	\
	./my_strcpy.c	\
	./my_strncpy.c	\
	./my_putchar.c	\
	./my_compute_square_root.c	\
	./my_strupcase.c	\
	./my_is_prime.c	\
	./my_sort_int_array.c	\
	./my_strncmp.c	\
	./my_strlen.c	\
	./my_put_unsigned_long.c	\
	./my_showstr.c	\
	./my_putstr.c	\
	./my_str_isupper.c	\
	./my_puterr.c	\
	./my_strcmp.c	\
	./my_swap.c	\
	./my_strlowcase.c	\
	./my_str_isnum.c	\
	./my_str_isprintable.c	\
	./my_put_float.c	\
	./my_strcapitalize.c	\
	./my_str_islower.c	\
	./my_find_prime_sup.c	\
	./my_getnbr.c	\
	./my_compute_power_rec.c	\
	./my_putnbr_base.c	\
	./my_strncat.c	\
	./my_abs.c	\
	./my_showmem.c	\
	./my_put_short.c	\
	./my_put_short_unsigned.c	\
	./my_put_va.c	\
	./my_is.c	\
	./my_formatting.c	\
	./my_format_compute.c	\
	./my_format_exec.c	\
	./my_format_handling.c	\
	./my_other_len.c	\
	./my_format_handling_bis.c	\
	./my_formatting_bis.c	\
	./my_put_g.c
OBJ = $(SRC:.c=.o)
NAME = ./libmy.a

all: $(NAME) clean

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	cp ./$(NAME) ../
	cp ./$(NAME) ../../

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) *.gcda *.gcno $(NAME)

re: fclean all

tests_make: CFLAGS += --coverage -lcriterion
tests_make: fclean $(NAME)

.PHONY: all clean fclean re tests_make
