NAME = do-op

all: $(NAME)

$(NAME):
	cc -Wall -Wextra -Werror main.c operations.c -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all