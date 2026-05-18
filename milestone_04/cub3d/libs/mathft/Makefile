NAME = mathft.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
INC_FILES = -I .

OBJ_DIR = obj

SRC_FILES = vec2_add.c \
			vec2_sub.c \
			vec2_scale.c \
			vec2_cross.c \
			vec2_dot.c \
			vec2_div.c \
			vec2_length.c \
			vec2_normalize.c \
			vec2_dist.c \
			vec3_add.c \
			vec3_sub.c \
			vec3_scale.c \
			vec3_cross.c \
			vec3_dot.c \
			vec3_div.c \
			vec3_length.c \
			vec3_normalize.c

OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

# Colors
GREEN	= \033[0;32m
BLUE	= \033[0;34m
YELLOW	= \033[0;33m
RED		= \033[0;31m
RESET	= \033[0m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $(NAME) $(OBJ_FILES)
	@echo "$(GREEN)[OK] mathft compiled ✔$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_FILES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re