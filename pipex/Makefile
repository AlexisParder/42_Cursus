NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libs/libft/libft.a

INC_DIR = -I includes/ -I libs/libft/ 

OBJ_DIR = obj
OBJ_MAND_DIR = $(OBJ_DIR)/mandatory
OBJ_BONUS_DIR = $(OBJ_DIR)/bonus

SRC_DIR = srcs/mandatory/
SRC_FILES = $(SRC_DIR)main.c \
			$(SRC_DIR)split_with_quotes.c \
			$(SRC_DIR)exec_parent.c \
			$(SRC_DIR)utils/utils.c \
			$(SRC_DIR)utils/utils_cmds.c \
			$(SRC_DIR)utils/utils_envp.c \
			$(SRC_DIR)utils/utils_exec_parent.c
OBJ_FILES = $(SRC_FILES:srcs/mandatory/%.c=$(OBJ_MAND_DIR)/%.o)

SRC_BONUS_DIR = srcs/bonus/
SRC_BONUS_FILES = $(SRC_BONUS_DIR)main_bonus.c \
			$(SRC_BONUS_DIR)split_with_quotes_bonus.c \
			$(SRC_BONUS_DIR)exec_parent_bonus.c \
			$(SRC_BONUS_DIR)utils/utils_bonus.c \
			$(SRC_BONUS_DIR)utils/utils_cmds_bonus.c \
			$(SRC_BONUS_DIR)utils/utils_envp_bonus.c \
			$(SRC_BONUS_DIR)utils/utils_exec_parent_bonus.c
OBJ_BONUS_FILES = $(SRC_BONUS_FILES:srcs/bonus/%.c=$(OBJ_BONUS_DIR)/%.o)

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

bonus: $(LIBFT) $(OBJ_BONUS_FILES)
		@echo "$(BLUE)[BONUS] Compilation de $(NAME) (bonus)...$(RESET)"
		@$(CC) $(CFLAGS) $(INC_DIR) -o $(NAME) $(OBJ_BONUS_FILES) $(LIBS)
		@echo "$(GREEN)[OK] $(NAME) (bonus) prêt ✓$(RESET)"

$(OBJ_MAND_DIR)/%.o: srcs/mandatory/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: srcs/bonus/%.c
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

.PHONY: all bonus clean fclean re