# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 14:39:54 by dvan-hum          #+#    #+#              #
#    Updated: 2024/08/13 14:46:41 by dvan-hum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJ = srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_strcmp.o srcs/ft_strlen.o srcs/ft_swap.o
COMPILE = gcc -Wall -Wextra -Werror -I includes/

all: $(NAME)

$(NAME):
	$(COMPILE) -c srcs/ft_putchar.c -o srcs/ft_putchar.o
	$(COMPILE) -c srcs/ft_putstr.c -o srcs/ft_putstr.o
	$(COMPILE) -c srcs/ft_strcmp.c -o srcs/ft_strcmp.o
	$(COMPILE) -c srcs/ft_strlen.c -o srcs/ft_strlen.o
	$(COMPILE) -c srcs/ft_swap.c -o srcs/ft_swap.o
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all