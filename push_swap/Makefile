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

all: $(NAME)

$(NAME): $(OBJ_FILES)
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ $^ libs/libft.a

%.o : %.c
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ -c $<

clean:
		@rm -rf $(OBJ_FILES)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re