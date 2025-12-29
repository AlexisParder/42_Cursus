NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libs/libft/libft.a
MLX_DIR = libs/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

INC_DIR = -I includes/ -I libs/libft/ -I $(MLX_DIR)

OBJ_DIR = obj
OBJ_MAND_DIR = $(OBJ_DIR)/mandatory
OBJ_BONUS_DIR = $(OBJ_DIR)/bonus

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
			$(SRC_DIR)utils/utils_image.c \
			$(SRC_DIR)utils/utils_error.c \
			$(SRC_DIR)utils/utils_draw.c
OBJ_FILES = $(SRC_FILES:srcs/mandatory/%.c=$(OBJ_MAND_DIR)/%.o)

SRC_BONUS_DIR = srcs/bonus/
SRC_BONUS_FILES = 	$(SRC_BONUS_DIR)main_bonus.c \
					$(SRC_BONUS_DIR)manage_win_bonus.c \
					$(SRC_BONUS_DIR)create_images_bonus.c \
					$(SRC_BONUS_DIR)make_moves_bonus.c \
					$(SRC_BONUS_DIR)checks_map_bonus.c \
					$(SRC_BONUS_DIR)checks_map_path_bonus.c \
					$(SRC_BONUS_DIR)move_enemy_bonus.c \
					$(SRC_BONUS_DIR)manage_loop_bonus.c \
					$(SRC_BONUS_DIR)create_enemy_bonus.c \
					$(SRC_BONUS_DIR)generate_map_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_main_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_str_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_move_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_map_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_clean_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_image_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_draw_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_lst_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_display_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_move_enemy_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_enemy_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_create_image_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_time_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_error_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_gen_fill_map_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_gen_walls_bonus.c \
					$(SRC_BONUS_DIR)utils/utils_distance_player_bonus.c
OBJ_BONUS_FILES = $(SRC_BONUS_FILES:srcs/bonus/%.c=$(OBJ_BONUS_DIR)/%.o)

LIBS = $(LIBFT) $(MLX) -lXext -lX11 -lm

# Colors
GREEN	= \033[0;32m
BLUE	= \033[0;34m
YELLOW	= \033[0;33m
RED		= \033[0;31m
RESET	= \033[0m

all: $(MLX) $(LIBFT) $(NAME)

bonus: $(MLX) $(LIBFT) $(NAME_BONUS)

$(MLX):
		@echo "$(BLUE)[MLX] Compilation de la minilibx...$(RESET)"
		@$(MAKE) -C libs/minilibx-linux
		@echo "$(GREEN)[MLX] Minilibx compilée ✔$(RESET)"

$(LIBFT):
		@echo "$(BLUE)[LIBFT] Compilation de la libft...$(RESET)"
		@$(MAKE) -C libs/libft
		@echo "$(GREEN)[LIBFT] libft compilée ✔$(RESET)"

$(NAME): $(OBJ_FILES)
		@echo "$(BLUE)[BUILD] Compilation de $(NAME)...$(RESET)"
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ $^ $(LIBS)
		@echo "$(GREEN)[OK] $(NAME) prêt ✔$(RESET)"

$(NAME_BONUS): $(OBJ_BONUS_FILES)
		@echo "$(BLUE)[BUILD] Compilation de $(NAME_BONUS)...$(RESET)"
		@$(CC) $(CFLAGS) $(INC_DIR) -o $@ $^ $(LIBS)
		@echo "$(GREEN)[OK] $(NAME_BONUS) prêt ✔$(RESET)"

$(OBJ_MAND_DIR)/%.o: srcs/mandatory/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: srcs/bonus/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

clean:
		@echo "$(YELLOW)[CLEAN] Suppression des objets...$(RESET)"
		@rm -rf $(OBJ_DIR)
		@$(MAKE) -C libs/minilibx-linux clean
		@$(MAKE) -C libs/libft clean
		@echo "$(GREEN)[CLEAN] OK ✔$(RESET)"

fclean: clean
		@echo "$(RED)[FCLEAN] Suppression des binaires...$(RESET)"
		@rm -rf $(NAME)
		@rm -rf $(NAME_BONUS)
		@rm -rf libs/libft/libft.a
		@echo "$(GREEN)[FCLEAN] OK ✔$(RESET)"

re: fclean all
		@echo "$(GREEN)[RE] Rebuild terminé ✔$(RESET)"

.PHONY: all bonus clean fclean re