.SILENT:

SRCS = ./srcs/free.c \
			 ./srcs/push.c \
			 ./srcs/swap.c \
			 ./srcs/rotate.c \
			 ./srcs/sorting.c \
			 ./srcs/push_swap.c \
			 ./srcs/case_counter.c \
			 ./srcs/stack_tools_1.c \
			 ./srcs/stack_tools_2.c \
			 ./srcs/stack_tools_3.c \
			 ./srcs/stack_tools_4.c \
			 ./srcs/stack_tools_5.c \
			 ./srcs/stack_tools_6.c \
			 ./srcs/error_handling.c \
			 ./srcs/before_push_ops.c
LIB = ./libft/libft.a
NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	@echo "Target is up to date!"

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "Program Created!"

$(LIB):
	@echo "Building libft..."
	@(make -C ./libft/) > /dev/null


%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@(make clean -C ./libft/) > /dev/null
	rm -rf srcs/*.o
	@echo "Files were romved!"

fclean: clean
	@(make fclean -C ./libft/) > /dev/null
	rm -rf $(NAME)
	@echo "Files were romved!"

re: fclean all
