NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libs/libft.a
MLX_DIR = libs/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

INC_DIR = -I includes/ -I $(MLX_DIR)

SRC_DIR = srcs/mandatory/
SRC_FILES = $(SRC_DIR)main.c \
			$(SRC_DIR)manage_win.c \
			$(SRC_DIR)create_images.c \
			$(SRC_DIR)make_moves.c \
			$(SRC_DIR)checks_map.c \
			$(SRC_DIR)checks_map_path.c \
			$(SRC_DIR)utils/utils_main.c \
			$(SRC_DIR)utils/utils_str.c \
			$(SRC_DIR)utils/utils_move.c \
			$(SRC_DIR)utils/utils_map.c \
			$(SRC_DIR)utils/utils_clean.c \
			$(SRC_DIR)utils/utils_draw.c
OBJ_FILES = $(SRC_FILES:.c=.o)

SRC_BONUS_DIR = srcs/bonus/
SRC_BONUS_FILES = 	$(SRC_BONUS_DIR)main_bonus.c \
					$(SRC_BONUS_DIR)manage_win_bonus.c \
					$(SRC_BONUS_DIR)create_images_bonus.c \
					$(SRC_BONUS_DIR)make_moves_bonus.c \
					$(SRC_BONUS_DIR)checks_map_bonus.c \
					$(SRC_BONUS_DIR)checks_map_path_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_main_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_str_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_move_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_map_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_clean_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_draw_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_display_bonus.c
OBJ_BONUS_FILES = $(SRC_BONUS_FILES:.c=.o)

LIBS = $(LIBFT) $(MLX) -lXext -lX11 -lm

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ_FILES)
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ $^ $(LIBS)

$(NAME_BONUS): $(OBJ_BONUS_FILES)
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ $^ $(LIBS)

%.o : %.c
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ -c $<

clean:
		@rm -rf $(OBJ_FILES)
		@rm -rf $(OBJ_BONUS_FILES)

fclean: clean
		@rm -rf $(NAME)
		@rm -rf $(NAME_BONUS)

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re