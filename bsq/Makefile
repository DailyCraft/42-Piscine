# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 11:37:37 by gakarbou          #+#    #+#              #
#    Updated: 2024/08/07 22:30:39 by gakarbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS_DIR = srcs/
HEAD_DIR = includes/

CC = gcc
FLAGS = -Wall -Wextra -Werror

FILES = main.c \
	map.c \
	parser.c \
	solver.c \
	utils.c \
	print.c \
	ft_fill_slots.c \

SRCS = $(addprefix $(SRCS_DIR), $(FILES))
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEAD_DIR)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
