NAME = accounts

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INC_DIR = -I includes/

OBJ_DIR = obj

SRC_DIR = srcs/
SRC_FILES = $(SRC_DIR)tests.cpp \
			$(SRC_DIR)Account.cpp
OBJ_FILES = $(SRC_FILES:srcs/%.cpp=$(OBJ_DIR)/%.o)

# Colors
GREEN	= \033[0;32m
BLUE	= \033[0;34m
YELLOW	= \033[0;33m
RED		= \033[0;31m
RESET	= \033[0m

BANNER = \
"\n  $(RESET)██████$(RED)╗$(RESET)██████$(RED)╗ $(RESET)██████$(RED)╗ \n" \
"$(RESET)██$(RED)╔════╝$(RESET)██$(RED)╔══$(RESET)██$(RED)╗$(RESET)██$(RED)╔══$(RESET)██$(RED)╗ \n" \
"$(RESET)██$(RED)║     $(RESET)██████$(RED)╔╝$(RESET)██████$(RED)╔╝ \n" \
"$(RESET)██$(RED)║     $(RESET)██$(RED)╔═══╝ $(RESET)██$(RED)╔═══╝\n" \
"╚$(RESET)██████$(RED)╗$(RESET)██$(RED)║     $(RESET)██$(RED)║\n" \
"$(RED) ╚═════╝╚═╝     ╚═╝ $(RESET)\n"

all: banner $(NAME)

banner:
	@echo $(BANNER)

$(NAME): $(OBJ_FILES)
		@echo "$(BLUE)[BUILD] Compiling $(NAME)...$(RESET)"
		@$(CXX) $(CXXFLAGS) $(INC_DIR) -o $@ $^
		@echo "$(GREEN)[OK] $(NAME) ready ✔$(RESET)"

$(OBJ_DIR)/%.o: srcs/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INC_DIR) -c $< -o $@

clean:
		@echo "$(YELLOW)[CLEAN] Removing object files...$(RESET)"
		@rm -rf $(OBJ_DIR)
		@echo "$(GREEN)[CLEAN] OK ✔$(RESET)"

fclean: clean
		@echo "$(RED)[FCLEAN] Removing binaries...$(RESET)"
		@rm -rf $(NAME)
		@echo "$(GREEN)[FCLEAN] OK ✔$(RESET)"

re: fclean all
		@echo "$(GREEN)[RE] Rebuild finished ✔$(RESET)"

.PHONY: all clean fclean re