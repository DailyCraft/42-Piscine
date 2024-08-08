# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 10:48:08 by dvan-hum          #+#    #+#              #
#    Updated: 2024/08/08 16:00:39 by dvan-hum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

SRCS = main.c utils.c utils2.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
