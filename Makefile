SRCS = ./srcs/*.c
LIBFT = ./libft.a
NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all

debug:
	$(CC) $(SRCS) $(LIBFT) -o $(NAME)
