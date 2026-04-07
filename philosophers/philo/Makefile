NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = -I includes/

OBJ_DIR = obj

SRC_DIR = srcs/
SRC_FILES = $(SRC_DIR)main.c \
			$(SRC_DIR)init.c \
			$(SRC_DIR)threads.c \
			$(SRC_DIR)actions.c \
			$(SRC_DIR)monitor.c \
			$(SRC_DIR)utils/error.c \
			$(SRC_DIR)utils/time.c \
			$(SRC_DIR)utils/philo_atol.c \
			$(SRC_DIR)utils/utils_philo.c
OBJ_FILES = $(SRC_FILES:srcs/%.c=$(OBJ_DIR)/%.o)

# Colors
GREEN	= \033[0;32m
BLUE	= \033[0;34m
YELLOW	= \033[0;33m
RED		= \033[0;31m
RESET	= \033[0m

BANNER = \
"\n $(RESET)██████$(RED)╗ $(RESET)██$(RED)╗  $(RESET)██$(RED)╗$(RESET)██$(RED)╗$(RESET)██$(RED)╗      $(RESET)██████$(RED)╗ $(RESET)███████$(RED)╗ $(RESET)██████$(RED)╗ $(RESET)██████$(RED)╗ $(RESET)██$(RED)╗  $(RESET)██$(RED)╗$(RESET)███████$(RED)╗$(RESET)██████$(RED)╗ $(RESET)███████$(RED)╗ \n" \
"$(RESET)██$(RED)╔══$(RESET)██$(RED)╗$(RESET)██$(RED)║  $(RESET)██$(RED)║$(RESET)██$(RED)║$(RESET)██$(RED)║     $(RESET)██$(RED)╔═══$(RESET)██$(RED)╗$(RESET)██$(RED)╔════╝$(RESET)██$(RED)╔═══$(RESET)██$(RED)╗$(RESET)██$(RED)╔══$(RESET)██$(RED)╗$(RESET)██$(RED)║  $(RESET)██$(RED)║$(RESET)██$(RED)╔════╝$(RESET)██$(RED)╔══$(RESET)██$(RED)╗$(RESET)██$(RED)╔════╝ \n" \
"$(RESET)██████$(RED)╔╝$(RESET)███████$(RED)║$(RESET)██$(RED)║$(RESET)██$(RED)║     $(RESET)██$(RED)║   $(RESET)██$(RED)║$(RESET)███████$(RED)╗$(RESET)██$(RED)║   $(RESET)██$(RED)║$(RESET)██████$(RED)╔╝$(RESET)███████$(RED)║$(RESET)█████$(RED)╗  $(RESET)██████$(RED)╔╝$(RESET)███████$(RED)╗ \n" \
"$(RESET)██$(RED)╔═══╝ $(RESET)██$(RED)╔══$(RESET)██$(RED)║$(RESET)██$(RED)║$(RESET)██$(RED)║     $(RESET)██$(RED)║   $(RESET)██$(RED)║╚════$(RESET)██$(RED)║$(RESET)██$(RED)║   $(RESET)██$(RED)║$(RESET)██$(RED)╔═══╝ $(RESET)██$(RED)╔══$(RESET)██$(RED)║$(RESET)██$(RED)╔══╝  $(RESET)██$(RED)╔══$(RESET)██$(RED)╗╚════$(RESET)██$(RED)║ \n" \
"$(RESET)██$(RED)║     $(RESET)██$(RED)║  $(RESET)██$(RED)║$(RESET)██$(RED)║$(RESET)███████$(RED)╗╚$(RESET)██████$(RED)╔╝$(RESET)███████$(RED)║╚$(RESET)██████$(RED)╔╝$(RESET)██$(RED)║     $(RESET)██$(RED)║  $(RESET)██$(RED)║$(RESET)███████$(RED)╗$(RESET)██$(RED)║  $(RESET)██$(RED)║$(RESET)███████$(RED)║ \n" \
"$(RED)╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝ \n$(RESET)"

all: banner $(NAME)

banner:
	@echo $(BANNER)

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