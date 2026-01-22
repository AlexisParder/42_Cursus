NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = -I includes/

OBJ_DIR = obj

SRC_DIR = srcs/
SRC_FILES = $(SRC_DIR)main.c
OBJ_FILES = $(SRC_FILES:srcs/%.c=$(OBJ_DIR)/%.o)

# Colors
GREEN	= \033[0;32m
BLUE	= \033[0;34m
YELLOW	= \033[0;33m
RED		= \033[0;31m
RESET	= \033[0m


all: $(NAME)

$(NAME): $(OBJ_FILES)
		@echo "$(BLUE)[BUILD] Compilation de $(NAME)...$(RESET)"
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ $^
		@echo "$(GREEN)[OK] $(NAME) prêt ✔$(RESET)"

$(OBJ_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

clean:
		@echo "$(YELLOW)[CLEAN] Suppression des objets...$(RESET)"
		@rm -rf $(OBJ_DIR)
		@echo "$(GREEN)[CLEAN] OK ✔$(RESET)"

fclean: clean
		@echo "$(RED)[FCLEAN] Suppression des binaires...$(RESET)"
		@rm -rf $(NAME)
		@echo "$(GREEN)[FCLEAN] OK ✔$(RESET)"

re: fclean all
		@echo "$(GREEN)[RE] Rebuild terminé ✔$(RESET)"

.PHONY: all clean fclean re