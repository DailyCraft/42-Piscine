# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/03 13:23:44 by dvan-hum          #+#    #+#              #
#    Updated: 2024/08/04 18:45:23 by dvan-hum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

all: $(NAME)

$(NAME):
	cc -Wall -Wextra -Werror -I includes src/*.c -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all