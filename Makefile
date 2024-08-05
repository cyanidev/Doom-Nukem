# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 01:22:18 by samusanc          #+#    #+#              #
#    Updated: 2024/08/05 02:51:27 by samusanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d
CFLAGS	= 
INC		= -I./includes/ -I./libft/
INC		+= -I/usr/include -O3 -I./minilibx-linux/ 
LIBFT	= -L./libft/ -lft 
CC		= gcc $(CFLAGS)

SRCS	= ./mandatory/main.c
O_DIR	= ./objects/
OBJS	= $(addprefix $(O_DIR)/, $(SRCS:.c=.o))

$(O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(LIBFT) $(INC) -g -c $< -o $(O_DIR)/$(<:.c=.o)
	@echo ""

all: title .mandatory
	@echo "===================================="
	@echo ""
	@echo "usage: $$./cub3d map.cub"

.mlx:
	@make -sC ./minilibx-linux/ all
	@touch .mlx

.libft:
	@make -sC ./libft/ all
	@touch .libft

title:
	@echo "===================================="
	@echo " _____ _   _______  ___________ "
	@echo "/  __ \\ | | | ___ \\|____ |  _  \\"
	@echo "| /  \\/ | | | |_/ /    / / | | |"
	@echo "| |   | | | | ___ \    \\ \\ | | |"
	@echo "| \\__/\\ |_| | |_/ /.___/ / |/ / "
	@echo " \\____/\\___/\\____/ \\____/|___/  "
	@echo ""
	@echo "===================================="
	@echo "Graphics:samusanc, Parsing:afelicia"
	@echo ""

.mandatory: .libft .mlx $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) -L./minilibx-linux/ -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd
	@touch .mandatory

re: fclean all

fclean: clean
	@echo "cleaning binaries..."
	@make -sC ./libft/ fclean
	@rm -f $(NAME)
	@rm -f $(NAME)_bonus
	@rm -rf .bonus
	@rm -rf .mandatory
	@rm -rf .clean
	@rm -rf .mlx
	@rm -rf .libft

clean: .clean
	@echo "objects removed!"

.clean:
	@echo "cleaning objects..."
	@make -sC ./minilibx-linux/ clean
	@make -sC ./libft/ clean
	@rm -f $(OBJS)
	@rm -f $(B_OBJS)
	@rm -rf $(O_DIR)
	@rm -rf $(B_O_DIR)
	@touch .clean

.PHONY: all title bonus clean fclean re
