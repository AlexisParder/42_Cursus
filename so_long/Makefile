NAME = so_long
CC = cc 
CFLAGS = -Wall -Wextra -Werror
INC_DIR = -I includes/ -I libs/MacroLibX/includes
SRC_DIR = srcs/
SRC_FILES = $(SRC_DIR)main.c \
			$(SRC_DIR)create_images.c \
			$(SRC_DIR)make_moves.c \
			$(SRC_DIR)checks_map.c \
			$(SRC_DIR)checks_map_path.c \
			$(SRC_DIR)utils/utils_main.c \
			$(SRC_DIR)utils/utils_str.c \
			$(SRC_DIR)utils/utils_move.c \
			$(SRC_DIR)utils/utils_map.c \
			$(SRC_DIR)utils/utils_clean.c \
			$(SRC_DIR)utils/utils_redraw.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ $^ libs/libft.a libs/MacroLibX/libmlx.so -lSDL2

%.o : %.c
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ -c $<

clean:
		@rm -rf $(OBJ_FILES)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re