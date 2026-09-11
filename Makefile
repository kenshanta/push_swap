# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/05 15:00:48 by jziental          #+#    #+#              #
#    Updated: 2026/09/11 17:31:33 by jziental         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = benchmark.c compute_disorder.c ft_exit.c ft_printf_utils.c ft_printf.c \
ft_split.c ft_strcmp.c ft_write_stderr.c indexing.c ints_utils.c lst_ops_sec.c \
lst_ops.c ops_general.c ops_push_swap.c ops_rev_rotate.c ops_rotate.c push_swap.c \
sort_simple.

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
