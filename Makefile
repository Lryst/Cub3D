# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lryst <lryst@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 18:37:25 by lryst             #+#    #+#              #
#    Updated: 2020/06/13 23:06:36 by lryst            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC_PATH = src
SRC_NAME = main.c parse.c color.c init_check_struct.c resolution.c\
save_map.c textures.c ray_casting.c move.c set_texture.c wall_side.c\
sprites.c print.c cub3d_utils.c free.c save_bmp.c init_player.c main_utils.c\
mlx_handle.c rotation.c\

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

LIB_DIR = libft
LIB = $(LIB_DIR)/libft.a

MLX_DIR = ressources/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
#MLX_LIBS = -lbsd -lXext -lX11

SRC = $(addprefix $(SRC_PATH)/,$(SR_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(LIB) $(MLX) $(NAME)

$(LIB):
	@make -C $(LIB_DIR)

$(MLX):
	@make -C $(MLX_DIR)

$(NAME): $(OBJ)
	@printf "\n"
	@$(CC) -o $(NAME) $(OBJ) $(LIB) $(MLX) -lm -lXext -lX11 
	@echo "Compilation of \033[33;1m$(NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@printf "\033[34;1m| \033[0;1m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIB_DIR) clean
	@make -C $(MLX_DIR) clean
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo "\033[33;1m$(NAME)\033[0;1m: objects deleted\033[0m"

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -rf $(NAME)
	@echo "\033[33;1m$(NAME)\033[0;1m: $(NAME) deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re
