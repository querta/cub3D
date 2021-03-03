# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 14:23:30 by mmonte            #+#    #+#              #
#    Updated: 2021/03/03 17:24:59 by mmonte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT = libft.a
MLX = libmlx.dylib

CC = @gcc
FLAGS = -Wall -Wextra -Werror
HEADER = includes/

SRC_DIR = src/
LIBFT_DIR = $(SRC_DIR)libft/
MLX_DIR = minilibx_mms/

SRC = get_next_line.c \
	main.c \
	parser/parser.c parser/parse_mapfile.c parser/parse_player.c \
	parser/parse_colors.c processor.c \
	checker/checker.c checker/checker_filler_map.c checker/checker_map.c \
	utils.c errors.c mlx_utils.c movements.c save_screenshot.c \
	raycaster.c sprite_calculator.c draw_all.c draw_sprites.c

OBJ =	$(addprefix $(SRC_DIR), $(SRC:.c=.o)) 

INCLUDES		= -I $(HEADER) -I $(LIBFT_DIR) -I $(MLX_DIR)
LFLAGS	= -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -lm
MLX_FLAGS	= -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all:	$(SRC_DIR) $(NAME)

$(NAME): $(OBJ) 
	@make bonus -C $(LIBFT_DIR) -j 4
	@printf "\e[1;36mLib \e[1;32m'$(LIBFT)' \e[1;36mcreated\e[0m\n"
	@make -C $(MLX_DIR) > /dev/null
	@printf "\e[1;36mLib \e[1;32m'$(MLX)' \e[1;36mcreated\e[0m\n"
	@cp $(MLX_DIR)$(MLX) .
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ) $(LFLAGS) -o $(NAME)
	@printf "\e[1;36mProject \e[1;32m'$(NAME)' \e[1;36mcompiled!\e[0m\n"

%.o : %.c
	$(CC) $(FLAGS) -I$(HEADER) -c $< -o $@ 
	@printf "\e[1;36mCompiling $<\e[0m\n"

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJ)
	rm -f $(MLX)
	rm -f cub3d.bmp

fclean: clean
	rm -f $(LIBFT_DIR)$(LIBFT)
	rm -f $(NAME)

re: fclean all
