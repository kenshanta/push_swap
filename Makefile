# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jziental <jziental@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/30 02:27:31 by skovlekj          #+#    #+#              #
#    Updated: 2026/08/24 17:14:08 by jziental         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
SRC = ft_printf ft_get_hexadecimal ft_get_len
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $@ $(OBJS)

$(LIBFT):
	$(MAKE) -C ${LIBFT_DIR}

clean:
	rm -f *.o

fclean: clean
	rm -f  $(NAME)

re: clean all

.PHONY: all re clean fclean

