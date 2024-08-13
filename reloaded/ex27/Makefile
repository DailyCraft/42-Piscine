# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 15:07:52 by dvan-hum          #+#    #+#              #
#    Updated: 2024/08/13 15:10:57 by dvan-hum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c main.c
	gcc main.o -o $(NAME)

clean:
	rm -f main.o

fclean: clean
	rm -f $(NAME)

re: fclean all
