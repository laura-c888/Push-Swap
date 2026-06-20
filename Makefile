# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchehbi <lchehbi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/20 18:00:00 by lchehbi           #+#    #+#              #
#    Updated: 2026/06/20 18:00:00 by lchehbi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I.

SRC		= src/main.c \
		  src/error.c \
		  src/stack_1.c \
		  src/stack_2.c \
		  src/parse_utils.c \
		  src/parse.c \
		  src/instr_utils.c \
		  src/instr_swap.c \
		  src/instr_push.c \
		  src/instr_rotate.c \
		  src/instr_rrotate.c \
		  src/sort_small.c \
		  src/sort_medium.c \
		  src/sort_medium_utils.c \
		  src/ft_utils.c \
		  src/adaptive.c \
		  src/bench_1.c \
		  src/bench_2.c \
		  src/chunksort.c \
		  src/disorder_metric.c \
		  src/flags.c \
		  src/mini_sort_utils.c \
		  src/mini_sort.c \
		  src/nearly_sorted.c \
		  src/radix_utils.c \
		  src/radix.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) test_push_swap

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(filter-out src/main.o, $(OBJ))
	$(CC) $(CFLAGS) $(filter-out src/main.o, $(OBJ)) tests/test_utils.c tests/test_push_swap.c -o test_push_swap
	./test_push_swap

.PHONY: all clean fclean re test
