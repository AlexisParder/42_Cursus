NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libs/libft/libft.a

INC_DIR = -I includes/ -I libs/libft/ 

OBJ_DIR = obj
OBJ_MAND_DIR = $(OBJ_DIR)/mandatory

SRC_DIR = srcs/mandatory/
SRC_FILES = $(SRC_DIR)main.c \
			$(SRC_DIR)split_with_quotes.c \
			$(SRC_DIR)utils/utils.c \
			$(SRC_DIR)utils/utils_cmds.c \
			$(SRC_DIR)utils/utils_envp.c
OBJ_FILES = $(SRC_FILES:srcs/mandatory/%.c=$(OBJ_MAND_DIR)/%.o)

# Colors
GREEN	= \033[0;32m
BLUE	= \033[0;34m
YELLOW	= \033[0;33m
RED		= \033[0;31m
RESET	= \033[0m

LIBS = $(LIBFT)

all: $(LIBFT) $(NAME)

$(LIBFT):
		@echo "$(BLUE)[LIBFT] Compilation de la libft...$(RESET)"
		@$(MAKE) -C libs/libft
		@echo "$(GREEN)[LIBFT] libft compilée ✔$(RESET)"

$(NAME): $(OBJ_FILES)
		@echo "$(BLUE)[BUILD] Compilation de $(NAME)...$(RESET)"
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ $^ $(LIBS)
		@echo "$(GREEN)[OK] $(NAME) prêt ✔$(RESET)"

$(OBJ_MAND_DIR)/%.o: srcs/mandatory/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

clean:
		@echo "$(YELLOW)[CLEAN] Suppression des objets...$(RESET)"
		@rm -rf $(OBJ_DIR)
		@$(MAKE) -C libs/libft clean
		@echo "$(GREEN)[CLEAN] OK ✔$(RESET)"

fclean: clean
		@echo "$(RED)[FCLEAN] Suppression des binaires...$(RESET)"
		@rm -rf $(NAME)
		@rm -rf libs/libft/libft.a
		@echo "$(GREEN)[FCLEAN] OK ✔$(RESET)"

re: fclean all
		@echo "$(GREEN)[RE] Rebuild terminé ✔$(RESET)"

.PHONY: all clean fclean re