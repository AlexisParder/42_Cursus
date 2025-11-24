NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror
INC_DIR = -I includes/
SRC_DIR = srcs/
SRC_FILES = $(SRC_DIR)main.c \
			$(SRC_DIR)calc_moves.c \
			$(SRC_DIR)make_moves.c \
			$(SRC_DIR)utils_str.c \
			$(SRC_DIR)utils_swap.c \
			$(SRC_DIR)utils_push.c \
 			$(SRC_DIR)utils_rotation.c \
 			$(SRC_DIR)utils_rotation_rev.c \
			$(SRC_DIR)utils_stack.c \
			$(SRC_DIR)utils_check_parsing.c \
			$(SRC_DIR)utils_global.c \
			$(SRC_DIR)utils_calc_moves.c \
			$(SRC_DIR)utils_sort.c
LIBS_DIR = libs/
LIBS_FILES = $(LIBS_DIR)libft.a
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ $^ $(LIBS_FILES)

%.o : %.c
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ -c $<

clean:
		@rm -rf $(OBJ_FILES)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re