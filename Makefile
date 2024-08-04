NAME	= cub3d
CFLAGS	= 
CC	= gcc $(CFLAGS)

SRCS	= main.c
O_DIR	= ./objects/
OBJS	= $(addprefix $(O_DIR)/, $(SRCS:.c=.o))

$(O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -I/usr/include -O3 -I./minilibx-linux/ -g -c $< -o $(O_DIR)/$(<:.c=.o)
	@echo ""
	@echo "===================================== MAKING OBJS ====================================="

all: mlx .mandatory

mlx:
	@make -sC ./minilibx-linux/ all

.mandatory: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L./minilibx-linux/ -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd

fclean: clean
	@echo "cleaning binaries..."
	@rm -f $(NAME)
	@rm -f $(NAME)_bonus
	@rm -rf .bonus
	@rm -rf .mandatory
	@rm -rf .clean

clean: .clean
	@echo "objects removed!"

.clean:
	@echo "cleaning objects..."
	@make -sC ./minilibx-linux/ clean
	@rm -f $(OBJS)
	@rm -f $(B_OBJS)
	@rm -rf $(O_DIR)
	@rm -rf $(B_O_DIR)
	@touch .clean

.PHONY: all bonus clean fclean re mlx
