NAME = so_long
CC = cc 
CFLAGS = -Wall -Wextra -Werror
LIBFT = libs/libft.a
MLX_DIR = libs/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
INC_DIR = -I includes/ -I $(MLX_DIR)
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
			$(SRC_DIR)utils/utils_draw.c \
			$(SRC_DIR)utils/utils_bonus.c
OBJ_FILES = $(SRC_FILES:.c=.o)

LIBS = $(LIBFT) $(MLX) -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ_FILES)
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ $^ $(LIBS)

%.o : %.c
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ -c $<

clean:
		@rm -rf $(OBJ_FILES)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re