# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 18:12:48 by vimafra-          #+#    #+#              #
#    Updated: 2024/11/19 18:12:52 by vimafra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunint.c ft_puthexa.c ft_putptr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
