SRCS=srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJECTS=$(SRCS:.c=.o)
COMPILE=gcc -Wall -Wextra -Werror -I includes

all: libft.a

libft.a:
	$(COMPILE) -c srcs/ft_putchar.c -o srcs/ft_putchar.o
	$(COMPILE) -c srcs/ft_swap.c -o srcs/ft_swap.o
	$(COMPILE) -c srcs/ft_putstr.c -o srcs/ft_putstr.o
	$(COMPILE) -c srcs/ft_strlen.c -o srcs/ft_strlen.o
	$(COMPILE) -c srcs/ft_strcmp.c -o srcs/ft_strcmp.o
	ar rcs libft.a $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f libft.a

re: fclean all