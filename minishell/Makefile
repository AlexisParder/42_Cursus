NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
FLAGS = -lreadline -lhistory

LIBFT = libs/libft/libft.a

INC_DIR = -I includes/ -I libs/libft/ 

OBJ_DIR = obj
OBJ_MAND_DIR = $(OBJ_DIR)

SRC_DIR = srcs/
SRC_FILES = $(SRC_DIR)main.c \
			$(SRC_DIR)_utils/utils.c \
			$(SRC_DIR)_utils/utils_main.c \
			$(SRC_DIR)_utils/utils_builtin.c \
			$(SRC_DIR)_utils/utils_clean.c \
			$(SRC_DIR)_utils/utils_lst.c \
			$(SRC_DIR)_utils/utils_reorg.c \
			$(SRC_DIR)_utils/utils_signals.c \
			$(SRC_DIR)parsing/utils.c \
			$(SRC_DIR)parsing/parsing.c \
			$(SRC_DIR)parsing/quotes.c \
			$(SRC_DIR)fill_cmds/fill_cmds.c \
			$(SRC_DIR)fill_cmds/utils_fill_cmds.c \
			$(SRC_DIR)expand/expand.c \
			$(SRC_DIR)expand/redirs.c \
			$(SRC_DIR)expand/reorganize.c \
			$(SRC_DIR)expand/divide.c \
			$(SRC_DIR)envp/envp.c \
			$(SRC_DIR)envp/utils_envp.c \
			$(SRC_DIR)envp/manage_shlvl.c \
			$(SRC_DIR)exec/exec.c \
			$(SRC_DIR)exec/redirs_and_signals.c \
			$(SRC_DIR)exec/utils_exec.c \
			$(SRC_DIR)exec/access_exec.c \
			$(SRC_DIR)heredoc/init_heredoc.c \
			$(SRC_DIR)heredoc/heredoc.c \
			$(SRC_DIR)heredoc/utils_heredoc.c \
			$(SRC_DIR)cmd/cd/cd.c \
			$(SRC_DIR)cmd/cd/manage_path.c \
			$(SRC_DIR)cmd/cd/utils_cd.c \
			$(SRC_DIR)cmd/echo.c \
			$(SRC_DIR)cmd/env.c \
			$(SRC_DIR)cmd/exit.c \
			$(SRC_DIR)cmd/export.c \
			$(SRC_DIR)cmd/pwd.c \
			$(SRC_DIR)cmd/unset.c \
			$(SRC_DIR)cmd/_utils/utils_export.c \
			$(SRC_DIR)cmd/_utils/sort_export.c \
			$(SRC_DIR)cmd/_utils/utils_exit.c

OBJ_FILES = $(SRC_FILES:srcs/%.c=$(OBJ_MAND_DIR)/%.o)

# Colors
GREEN	= \033[0;32m
BLUE	= \033[0;34m
YELLOW	= \033[0;33m
RED		= \033[0;31m
RESET	= \033[0m

BANNER = \
"\n $(RED)$(RESET)██$(RED)╗   $(RESET)██$(RED)╗$(RESET)███$(RED)╗   $(RESET)██$(RED)╗$(RESET)██████$(RED)╗ $(RESET)███████$(RED)╗$(RESET)███████$(RED)╗$(RESET)██$(RED)╗$(RESET)███$(RED)╗   $(RESET)██$(RED)╗$(RESET)███████$(RED)╗$(RESET)██████$(RED)╗ $(RESET)\n" \
"$(RED)$(RESET)██$(RED)║   $(RESET)██$(RED)║$(RESET)████$(RED)╗  $(RESET)██$(RED)║$(RESET)██$(RED)╔══$(RESET)██$(RED)╗$(RESET)██$(RED)╔════╝$(RESET)██$(RED)╔════╝$(RESET)██$(RED)║$(RESET)████$(RED)╗  $(RESET)██$(RED)║$(RESET)██$(RED)╔════╝$(RESET)██$(RED)╔══$(RESET)██$(RED)╗$(RESET)\n" \
"$(RED)$(RESET)██$(RED)║   $(RESET)██$(RED)║$(RESET)██$(RED)╔$(RESET)██$(RED)╗ $(RESET)██$(RED)║$(RESET)██$(RED)║  $(RESET)██$(RED)║$(RESET)█████$(RED)╗  $(RESET)█████$(RED)╗  $(RESET)██$(RED)║$(RESET)██$(RED)╔$(RESET)██$(RED)╗ $(RESET)██$(RED)║$(RESET)█████$(RED)╗  $(RESET)██$(RED)║  $(RESET)██$(RED)║$(RESET)\n" \
"$(RED)$(RESET)██$(RED)║   $(RESET)██$(RED)║$(RESET)██$(RED)║╚$(RESET)██$(RED)╗$(RESET)██$(RED)║$(RESET)██$(RED)║  $(RESET)██$(RED)║$(RESET)██$(RED)╔══╝  $(RESET)██$(RED)╔══╝  $(RESET)██$(RED)║$(RESET)██$(RED)║╚$(RESET)██$(RED)╗$(RESET)██$(RED)║$(RESET)██$(RED)╔══╝  $(RESET)██$(RED)║  $(RESET)██$(RED)║$(RESET)\n" \
"$(RED)╚$(RESET)██████$(RED)╔╝$(RESET)██$(RED)║ ╚$(RESET)████$(RED)║$(RESET)██████$(RED)╔╝$(RESET)███████$(RED)╗$(RESET)██$(RED)║     $(RESET)██$(RED)║$(RESET)██$(RED)║ ╚$(RESET)████$(RED)║$(RESET)███████$(RED)╗$(RESET)██████$(RED)╔╝$(RESET)\n" \
"$(RED) ╚═════╝ ╚═╝  ╚═══╝╚═════╝ ╚══════╝╚═╝     ╚═╝╚═╝  ╚═══╝╚══════╝╚═════╝ $(RESET)\n" \
"   $(RESET)███$(BLUE)╗   $(RESET)███$(BLUE)╗$(RESET)██$(BLUE)╗$(RESET)███$(BLUE)╗   $(RESET)██$(BLUE)╗$(RESET)██$(BLUE)╗$(RESET)███████$(BLUE)╗$(RESET)██$(BLUE)╗  $(RESET)██$(BLUE)╗$(RESET)███████$(BLUE)╗$(RESET)██$(BLUE)╗     $(RESET)██$(BLUE)╗ \n" \
"   $(RESET)████$(BLUE)╗ $(RESET)████$(BLUE)║$(RESET)██$(BLUE)║$(RESET)████$(BLUE)╗  $(RESET)██$(BLUE)║$(RESET)██$(BLUE)║$(RESET)██$(BLUE)╔════╝$(RESET)██$(BLUE)║  $(RESET)██$(BLUE)║$(RESET)██$(BLUE)╔════╝$(RESET)██$(BLUE)║     $(RESET)██$(BLUE)║ \n" \
"   $(RESET)██$(BLUE)╔$(RESET)████$(BLUE)╔$(RESET)██$(BLUE)║$(RESET)██$(BLUE)║$(RESET)██$(BLUE)╔$(RESET)██$(BLUE)╗ $(RESET)██$(BLUE)║$(RESET)██$(BLUE)║$(RESET)███████$(BLUE)╗$(RESET)███████$(BLUE)║$(RESET)█████$(BLUE)╗  $(RESET)██$(BLUE)║     $(RESET)██$(BLUE)║ \n" \
"   $(RESET)██$(BLUE)║╚$(RESET)██$(BLUE)╔╝$(RESET)██$(BLUE)║$(RESET)██$(BLUE)║$(RESET)██$(BLUE)║╚$(RESET)██$(BLUE)╗$(RESET)██$(BLUE)║$(RESET)██$(BLUE)║╚════$(RESET)██$(BLUE)║$(RESET)██$(BLUE)╔══$(RESET)██$(BLUE)║$(RESET)██$(BLUE)╔══╝  $(RESET)██$(BLUE)║     $(RESET)██$(BLUE)║ \n" \
"   $(RESET)██$(BLUE)║ ╚═╝ $(RESET)██$(BLUE)║$(RESET)██$(BLUE)║$(RESET)██$(BLUE)║ ╚$(RESET)████$(BLUE)║$(RESET)██$(BLUE)║$(RESET)███████$(BLUE)║$(RESET)██$(BLUE)║  $(RESET)██$(BLUE)║$(RESET)███████$(BLUE)╗$(RESET)███████$(BLUE)╗$(RESET)███████$(BLUE)╗ \n" \
"   $(BLUE)╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝ \n$(RESET)"
LIBS = $(LIBFT)

all: banner $(LIBFT) $(NAME)

banner:
	@echo $(BANNER)

$(LIBFT):
		@echo "$(BLUE)[LIBFT] Compiling libft...$(RESET)"
		@$(MAKE) -C libs/libft
		@echo "$(GREEN)[LIBFT] libft compiled ✔$(RESET)"

$(NAME): $(OBJ_FILES)
		@echo "$(BLUE)[BUILD] Compiling $(NAME)...$(RESET)"
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ $^ $(LIBS) $(FLAGS)
		@echo "$(GREEN)[OK] $(NAME) ready ✔$(RESET)"

$(OBJ_MAND_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

clean:
		@echo "$(YELLOW)[CLEAN] Removing object files...$(RESET)"
		@rm -rf $(OBJ_DIR)
		@$(MAKE) -C libs/libft clean
		@echo "$(GREEN)[CLEAN] OK ✔$(RESET)"

fclean: clean
		@echo "$(RED)[FCLEAN] Removing binaries...$(RESET)"
		@rm -rf $(NAME)
		@rm -rf libs/libft/libft.a
		@echo "$(GREEN)[FCLEAN] OK ✔$(RESET)"

re: fclean all
		@echo "$(GREEN)[RE] Rebuild finished ✔$(RESET)"

.PHONY: all banner clean fclean re