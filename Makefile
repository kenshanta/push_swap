# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/05 15:00:48 by jziental          #+#    #+#              #
#    Updated: 2026/09/02 19:39:09 by jziental         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = benchmark.c ft_atoi.c ft_digit.c ft_lstadd_back.c ft_strcmp.c ft_lstnew.c ft_lstsize.c ft_lstlast.c  \
ft_lstdelone.c ft_lstclear.c ft_split.c ft_printf.c ft_utils.c ft_utils_ultra.c \
push_swap.c

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
