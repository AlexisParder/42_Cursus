NAME = libftprintf.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
INC_DIR = -I includes/
SRC_DIR = srcs/
SRC_FILES = $(SRC_DIR)ft_printf.c \
			$(SRC_DIR)ft_printf_utils.c \
			$(SRC_DIR)ft_printf_str_utils.c 
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
		@ar rcs -o $(NAME) $(OBJ_FILES)
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
