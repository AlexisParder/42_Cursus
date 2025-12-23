NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror
INC_DIR = -I includes/
SRC_DIR = srcs/
SRC_FILES = $(SRC_DIR)main.c \
			$(SRC_DIR)calc_moves.c \
			$(SRC_DIR)make_moves.c \
			$(SRC_DIR)utils/utils_str.c \
			$(SRC_DIR)utils/utils_swap.c \
			$(SRC_DIR)utils/utils_push.c \
 			$(SRC_DIR)utils/utils_rotation.c \
 			$(SRC_DIR)utils/utils_rotation_rev.c \
			$(SRC_DIR)utils/utils_stack.c \
			$(SRC_DIR)utils/utils_check_parsing.c \
			$(SRC_DIR)utils/utils_global.c \
			$(SRC_DIR)utils/utils_calc_moves.c \
			$(SRC_DIR)utils/utils_sort.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Colors
GREEN	= \033[0;32m
BLUE	= \033[0;34m
YELLOW	= \033[0;33m
RED		= \033[0;31m
RESET	= \033[0m

all: $(NAME)

$(NAME): $(OBJ_FILES)
		@echo "$(BLUE)[BUILD] Compilation de $(NAME)...$(RESET)"
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ $^ libs/libft.a
		@echo "$(GREEN)[OK] $(NAME) prêt ✔$(RESET)"

%.o : %.c
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ -c $<

clean:
		@echo "$(YELLOW)[CLEAN] Suppression des objets...$(RESET)"
		@rm -rf $(OBJ_FILES)
		@echo "$(GREEN)[CLEAN] OK ✔$(RESET)"

fclean: clean
		@echo "$(RED)[FCLEAN] Suppression des binaires...$(RESET)"
		@rm -rf $(NAME)
		@echo "$(GREEN)[FCLEAN] OK ✔$(RESET)"

re: fclean all
		@echo "$(GREEN)[RE] Rebuild terminé ✔$(RESET)"

.PHONY: all clean fclean re