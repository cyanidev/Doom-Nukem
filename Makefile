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

all: title submodules .mandatory
	@echo "===================================="
	@echo ""
	@echo "usage: $$./cub3d map.cub"

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

#===================================================================================================================
#												Git Submodule Workflow
#===================================================================================================================

submodules: .submodule-init .mlx_utils .libft .T-engine
	@echo "All submodules loaded..."

.submodule-init:
	@git submodule update --init --recursive
	@git submodule update --recursive --remote
	@touch .submodule-init

.mlx_utils:
	@make -sC ./mlx_utils/ all
	@touch .mlx_utils

.libft:
	@make -sC ./libft/ all
	@touch .libft

.T-engine:
	@make -sC ./T-engine/ all
	@touch .T-engine


#===================================================================================================================
#									Git Submodule Workflow 4 ADD COMMIT and PUSH
#===================================================================================================================

add: fclean
	@make -sC ./T-engine/ add
	@make -sC ./mlx_utils/ add
	@make -sC ./libft/ add
	@git pull
	@git add .

commit:
	@make -sC ./T-engine/ commit
	@make -sC ./mlx_utils/ commit
	@make -sC ./libft/ commit
	@git commit -m 

.mandatory: .mlx $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) -L./minilibx-linux/ -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd
	@touch .mandatory

.mlx:
	@make -sC ./minilibx-linux/ all
	@touch .mlx

re: fclean all

fclean: clean
	@echo "cleaning binaries..."
	@make -sC ./libft/ fclean
	@make -sC ./T-engine/ fclean
	@make -sC ./mlx_utils/ fclean
	@rm -f $(NAME)
	@rm -f $(NAME)_bonus
	@rm -rf .bonus
	@rm -rf .mandatory
	@rm -rf .submodule-init
	@rm -rf .clean
	@rm -rf .mlx
	@rm -rf .mlx_utils
	@rm -rf .libft
	@rm -rf .T-engine

clean: .clean
	@echo "objects removed!"

.clean:
	@echo "cleaning objects..."
	@make -sC ./minilibx-linux/ clean
	@make -sC ./libft/ clean
	@make -sC ./T-engine/ clean
	@make -sC ./mlx_utils/ clean
	@rm -f $(OBJS)
	@rm -f $(B_OBJS)
	@rm -rf $(O_DIR)
	@rm -rf $(B_O_DIR)
	@touch .clean

.PHONY: all title bonus clean fclean re submodules add commit push
