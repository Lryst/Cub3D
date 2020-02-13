# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lryst <lryst@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 18:37:25 by lryst             #+#    #+#              #
#    Updated: 2020/02/13 20:52:29 by lryst            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC_PATH = src
SRC_NAME = main.c ft_parse.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = gcc
CFLAGS = #-Wall -Werror -Wextra

LIB_DIR = libft
LIB = $(LIB_DIR)/libft.a

SRC = $(addprefix $(SRC_PATH)/,$(SR_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(LIB) $(NAME)

$(LIB):
	@make -C $(LIB_DIR)

$(NAME): $(OBJ)
	@printf "\n"
	@$(CC) $^ $(LIB) -o $@
	@echo "Compilation of \033[33;1m$(NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@printf "\033[34;1m| \033[0;1m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIB_DIR) clean
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo "\033[33;1m$(NAME)\033[0;1m: objects deleted\033[0m"

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -rf $(NAME)
	@echo "\033[33;1m$(NAME)\033[0;1m: $(NAME) deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re
