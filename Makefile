CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
SRC = src/push_swap.c src/stack.c src/parse.c src/instructions.c src/sort_simple.c
OBJ = $(SRC:.c=.o)

all: push_swap tests

push_swap: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

tests: tests/test_push_swap

tests/test_push_swap: src/stack.c src/parse.c src/instructions.c src/sort_simple.c tests/test_push_swap.c
	$(CC) $(CFLAGS) src/stack.c src/parse.c src/instructions.c src/sort_simple.c tests/test_push_swap.c -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f push_swap tests/test_push_swap

re: fclean all
