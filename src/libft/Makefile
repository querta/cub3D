# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 18:34:35 by mmonte            #+#    #+#              #
#    Updated: 2021/01/24 18:57:58 by mmonte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
CC = @gcc

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c	ft_memcmp.c \
	ft_strlen.c ft_strncmp.c ft_atoi.c ft_tolower.c ft_strnstr.c ft_toupper.c ft_isalpha.c ft_isdigit.c \
	ft_isascii.c ft_isprint.c ft_isalnum.c ft_strchr.c ft_strrchr.c ft_strlcpy.c ft_strlcat.c ft_calloc.c \
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_strmapi.c ft_itoa.c ft_itoa_base.c ft_itoa_unsigned.c ft_split.c

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rcs $(NAME) $?

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus:	$(OBJ) $(OBJ_BONUS)
		ar -rc $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
