CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
A_C = ar rcs
FILES_MINE = \
		$(SRC)ft_islower.c $(SRC)ft_isupper.c $(SRC)ft_isspace.c \
		$(SRC)ft_strcpy.c $(SRC)ft_atol.c $(SRC)ft_sqrt.c \
		$(SRC)ft_power.c
FILES_LIBFT = \
		$(SRC)ft_isalpha.c $(SRC)ft_isdigit.c $(SRC)ft_isalnum.c \
		$(SRC)ft_isascii.c $(SRC)ft_isprint.c $(SRC)ft_strlen.c \
		$(SRC)ft_memset.c $(SRC)ft_bzero.c $(SRC)ft_memcpy.c \
		$(SRC)ft_memmove.c $(SRC)ft_strlcpy.c $(SRC)ft_strlcat.c \
		$(SRC)ft_toupper.c $(SRC)ft_tolower.c $(SRC)ft_strchr.c \
		$(SRC)ft_strrchr.c $(SRC)ft_strncmp.c $(SRC)ft_memchr.c \
		$(SRC)ft_memcmp.c $(SRC)ft_strnstr.c $(SRC)ft_atoi.c \
		$(SRC)ft_calloc.c $(SRC)ft_strdup.c $(SRC)ft_substr.c \
		$(SRC)ft_strjoin.c $(SRC)ft_strtrim.c $(SRC)ft_split.c \
		$(SRC)ft_itoa.c $(SRC)ft_strmapi.c $(SRC)ft_striteri.c \
		$(SRC)ft_putchar_fd.c $(SRC)ft_putstr_fd.c $(SRC)ft_putendl_fd.c \
		$(SRC)ft_putnbr_fd.c
FILES_LIBFT_BONUS = \
		$(SRC)ft_lstnew_bonus.c $(SRC)ft_lstadd_front_bonus.c \
		$(SRC)ft_lstsize_bonus.c $(SRC)ft_lstlast_bonus.c \
		$(SRC)ft_lstadd_back_bonus.c $(SRC)ft_lstdelone_bonus.c \
		$(SRC)ft_lstclear_bonus.c $(SRC)ft_lstiter_bonus.c \
		$(SRC)ft_lstmap_bonus.c
FILES_GNL = \
		$(SRC)get_next_line.c $(SRC)get_next_line_utils.c
OBJS_MINE = $(FILES_MINE:.c=.o)
OBJS_LIBFT = $(FILES_LIBFT:.c=.o)
OBJS_LIBFT_BONUS = $(FILES_LIBFT_BONUS:.c=.o)
OBJS_GNL = $(FILES_GNL:.c=.o)

%.o: %.c
	@echo "🔧Compiling $< 🔨"
	@$(CC) $(CFLAGS) -c $< -o $@


SRC = ./src/



all: show_name $(NAME)

$(NAME): $(OBJS_MINE) $(OBJS_LIBFT) $(OBJS_LIBFT_BONUS) $(OBJS_GNL)
		@$(A_C) $(NAME) $(OBJS_MINE) $(OBJS_LIBFT) $(OBJS_LIBFT_BONUS) $(OBJS_GNL)
		@echo "$(GREEN)Created $(NAME) ✓$(RESET)"

clean:
		@rm -rf $(OBJS_MINE) $(OBJS_LIBFT) $(OBJS_LIBFT_BONUS) $(OBJS_GNL)
		@echo "$(RED)Objects Libft Removed ✓$(RESET)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(RED)$(NAME) Removed ✓$(RESET)"

re: fclean all

#Edicion
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
	@echo "$(GREEN)Compiling libft...$(RESET)"

.PHONY: all clean fclean re bonus show_name