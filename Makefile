##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for the printf project
##

CFLAGS = -W -Wall -Wextra -Werror -fno-builtin -g3 -I./include
LDFLAGS = -L./lib -lmy
TEST_PATH = tests/
TEST_SRC = $(TEST_PATH)test_basic_format.c	\
	$(TEST_PATH)test_float_format.c	\
	$(TEST_PATH)test_hex_format.c	\
	$(TEST_PATH)test_invalid_format.c	\
	$(TEST_PATH)test_lib.c	\
	$(TEST_PATH)test_long_format.c	\
	$(TEST_PATH)test_ptr_format.c	\
	$(TEST_PATH)test_short_format.c	\
	$(TEST_PATH)test_unsigned_format.c	\
	$(TEST_PATH)test_format_combinations.c	\
	$(TEST_PATH)test_edge_cases.c	\
	$(TEST_PATH)test_dynamic_formats.c	\
	$(TEST_PATH)test_combined_formats.c
TEST_OBJ = $(TEST_SRC:.c=.o)
NAME = my_printf
FILE_NAME = coverage_report.html

all: $(NAME)

$(NAME):
	$(MAKE) -C ./lib/my

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(TEST_OBJ)
	$(MAKE) -C ./lib/my clean

fclean: clean
	$(RM) unit_tests *.gcda *.gcno *.html *.css $(NAME)
	$(MAKE) -C ./lib/my fclean
	$(RM) libmy.a
	$(RM) lib/libmy.a
	$(RM) lib/my/libmy.a

re: fclean all

compile: all
	$(CC) main.c -o $(NAME) $(CFLAGS) $(LDFLAGS)
	clear
	./my_printf

tests_make:
	$(MAKE) -C ./lib/my tests_make

tests_run: tests_make $(TEST_OBJ)
	$(CC) -o unit_tests $(TEST_OBJ) $(CFLAGS) $(LDFLAGS) --coverage -lcriterion
	./unit_tests

web_tests_run: tests_run
	gcovr --exclude $(TEST_PATH) -r . --html --html-details -o $(FILE_NAME)

.PHONY: all clean fclean re compile tests_run web_tests_run tests_make
