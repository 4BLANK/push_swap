# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 17:54:50 by amasdouq          #+#    #+#              #
#    Updated: 2023/11/27 10:42:26 by amasdouq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC= ft_isalpha.c\
     ft_isdigit.c\
     ft_isalnum.c\
     ft_isascii.c\
     ft_isprint.c\
     ft_toupper.c\
     ft_tolower.c\
     ft_strchr.c\
     ft_strrchr.c\
     ft_strncmp.c\
     ft_memchr.c\
     ft_strnstr.c\
     ft_atoi.c\
     ft_strlen.c\
     ft_memset.c\
     ft_bzero.c\
     ft_memmove.c\
     ft_strlcpy.c\
     ft_strlcat.c\
     ft_calloc.c\
     ft_strdup.c\
     ft_memcmp.c\
     ft_substr.c\
     ft_strjoin.c\
     ft_strtrim.c\
     ft_split.c\
     ft_itoa.c\
     ft_strmapi.c\
     ft_striteri.c\
     ft_putchar_fd.c\
     ft_putstr_fd.c\
     ft_putendl_fd.c\
     ft_putnbr_fd.c\
     ft_memcpy.c\
		 ft_putaddress.c\
		 ft_putchar.c\
		 ft_putnbr_base.c\
		 ft_putnbr_base_cap.c\
		 ft_putnbr_base_int.c\
		 ft_putstr.c\
		 ft_printf.c

BONUS_SRC= ft_lstnew_bonus.c\
	   ft_lstadd_front_bonus.c\
	   ft_lstsize_bonus.c\
	   ft_lstlast_bonus.c\
	   ft_lstadd_back_bonus.c\
	   ft_lstdelone_bonus.c\
           ft_lstclear_bonus.c\
           ft_lstiter_bonus.c\
	   ft_lstmap_bonus.c

OBJ= $(SRC:.c=.o)
BOBJ= $(BONUS_SRC:.c=.o)
CC= cc
CFLAGS= -Wall -Wextra  -Werror
RM= rm -f
AR= ar -rc

all: $(NAME)

$(NAME): $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
	$(AR) $(NAME) $@

clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(BOBJ) $(NAME)


.PHONY: all clean fclean re bonus
