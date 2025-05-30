CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf
SRC = ./src/
A_C = ar rcs
FILES = \
		$(SRC)fdf_utils_1.c $(SRC)window_utils_1.c $(SRC)draw_functions_1.c \
		$(SRC)draw_functions_2.c $(SRC)map_functions_1.c $(SRC)map_functions_2.c \
		$(SRC)map_functions_3.c $(SRC)fdf.c $(SRC)draw_functions_3.c \
		$(SRC)window_utils_2.c

OBJS = $(FILES:.c=.o)

INC = -Iinc -I../minilibx-linux -I.
MLX = -Lminilibx-linux -lmlx -lXext -lX11 -lm

%.o: %.c
	@echo "🔧Compiling $< 🔨"
	@$(CC) $(CFLAGS) -c $(INC) $< -o $@


all: show_name $(NAME)

$(NAME): $(OBJS)
		@$(MAKE) -C libft
		@$(MAKE) -C minilibx-linux
		@$(CC) $(CFLAGS) $(OBJS) $(INC) $(MLX) libft/libft.a -o $(NAME)
		@echo "$(GREEN)Created $(NAME) ✓$(RESET)"

clean:
		@rm -rf $(OBJS)
		@echo "$(RED)Objects FDF Removed ✓$(RESET)"

fclean: clean
		@$(MAKE) -C libft fclean
		@rm -f $(NAME)
		@echo "$(RED)$(NAME) Removed ✓$(RESET)"

re: fclean all


GREEN = \033[0;32m
YELLOW = \033[1;33m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

show_name:
	@echo "$(BLUE)==================================================$(RESET)"
	@echo "$(YELLOW)[........[.......          [.       [...     [.."
	@echo "[..      [..    [..       [. ..     [. [..   [.."
	@echo "[..      [..    [..      [.  [..    [.. [..  [.."
	@echo "[......  [. [..         [..   [..   [..  [.. [.."
	@echo "[..      [..  [..      [...... [..  [..   [. [.."
	@echo "[..      [..    [..   [..       [.. [..    [. .."
	@echo "[..      [..      [..[..         [..[..      [..$(RESET)"
	@echo "$(BLUE)==================================================$(RESET)"
	@echo "$(GREEN)Compiling fdf...$(RESET)"

.PHONY: all clean fclean re show_name
