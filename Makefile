# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 01:22:18 by samusanc          #+#    #+#              #
#    Updated: 2024/08/10 23:02:21 by samusanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d
COMMIT_D	:= $(shell date)
COMMIT_U	:= ${USER}
CFLAGS		= 

#=============================== INCLUDES ===============================#

INC			= -I./includes/ 
INC			+= -I./libft/ 
INC			+= -I./mlx_utils/ 
INC			+= -I./mlx_utils/includes/ 
INC			+= -I./T-Engine/ 
INC			+= -I./T-Engine/includes/ 
INC			+= -I./ft_math/
INC			+= -I./ft_math/includes/
INC			+= -I/usr/include -O3 -I./minilibx-linux/ 

#============================== LIBRARIES ===============================#

LIBFT		= -L./libft/ -lft 
CC			= gcc $(CFLAGS)

#================================= SCRS =================================#

SRCS		= ./mandatory/main.c


O_DIR		= ./objects/
OBJS		= $(addprefix $(O_DIR)/, $(SRCS:.c=.o))

#========================================================================#
#========================================================================#

$(O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -D BONUS=0 $(LIBFT) $(INC) -g -c $< -o $(O_DIR)/$(<:.c=.o)
	@echo ""

all: title submodules $(NAME)
	@echo "===================================="
	@echo ""
	@echo "usage: $$./cub3d map.cub"

$(NAME): .mandatory
	@echo "mandatory done..."

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

#============================= GIT RULES ==============================#

add: fclean .submodule-init
	@-git pull
	@git add .

commit: add
	@echo "" >> .TODO
	@cp .TODO .TODO.tmp
	sed -i '1s/^/$(COMMIT_D) by $(COMMIT_U)\n/' .TODO.tmp
	echo "======================= end of git description" >> .TODO.tmp
	git commit -F .TODO.tmp 
	@rm -rf .TODO.tmp

push: commit
	git push

#============================= SUBMODULES =============================#

submodules: .submodule-init .mlx_utils .libft .T-Engine .ft_math
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

.T-Engine:
	@make -sC ./T-Engine/ all
	@touch .T-Engine

.ft_math:
	@make -sC ./ft_math/ all
	@touch .ft_math

#======================= MANDATORY AND BONUS =========================#

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
	@make -sC ./T-Engine/ fclean
	@make -sC ./mlx_utils/ fclean
	@make -sC ./ft_math/ fclean
	@rm -f $(NAME)
	@rm -f $(NAME)_bonus
	@rm -rf .bonus
	@rm -rf .mandatory
	@rm -rf .submodule-init
	@rm -rf .clean
	@rm -rf .mlx
	@rm -rf .mlx_utils
	@rm -rf .libft
	@rm -rf .T-Engine
	@rm -rf .ft_math

clean: .clean
	@echo "objects removed!"

.clean: .submodule-init
	@echo "cleaning objects..."
	@make -sC ./minilibx-linux/ clean
	@make -sC ./libft/ clean
	@make -sC ./T-Engine/ clean
	@make -sC ./mlx_utils/ clean
	@make -sC ./ft_math/ clean
	@rm -f $(OBJS)
	@rm -f $(B_OBJS)
	@rm -rf $(O_DIR)
	@rm -rf $(B_O_DIR)
	@touch .clean

.PHONY: all title bonus clean fclean re submodules add commit push
