# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/10 12:38:43 by tjourdai          #+#    #+#              #
#    Updated: 2026/05/05 15:59:49 by achauvie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= cub3D

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -MMD -MP

LIBFT_DIR	:= libs/libft
LIBFT		:= $(LIBFT_DIR)/libft.a

MATHFT_DIR	:= libs/mathft
MATHFT		:= $(MATHFT_DIR)/mathft.a

MLX_DIR		:= libs/MacroLibX
MLX			:= $(MLX_DIR)/libmlx.so
LDFLAGS		:= -lSDL2 -lvulkan -lm

INC_DIR			:= includes/
OBJ_DIR			:= obj/mandatory/
OBJ_DIR_BONUS	:= obj/bonus/

SRC_DIR := srcs/mandatory/
SRC_FILES := \
	$(SRC_DIR)main.c \
	$(SRC_DIR)map_checker.c \
	$(SRC_DIR)_utils/clean.c \
	$(SRC_DIR)_utils/init.c \
	$(SRC_DIR)raycasting/raycasting.c \
	$(SRC_DIR)raycasting/drawing.c \
	$(SRC_DIR)raycasting/utils.c \
	$(SRC_DIR)parsing/utils.c \
	$(SRC_DIR)parsing/color.c \
	$(SRC_DIR)parsing/param.c \
	$(SRC_DIR)parsing/parsing.c \
	$(SRC_DIR)parsing/parse_line.c \
	$(SRC_DIR)player/init_player.c \
	$(SRC_DIR)player/move_player.c

SRC_DIR_BONUS := srcs/bonus/
SRC_FILES_BONUS := \
	$(SRC_DIR_BONUS)main_bonus.c \
	$(SRC_DIR_BONUS)map_checker_bonus.c \
	$(SRC_DIR_BONUS)fps_bonus.c \
	$(SRC_DIR_BONUS)events/events_bonus.c \
	$(SRC_DIR_BONUS)events/actions_bonus.c \
	$(SRC_DIR_BONUS)_utils/clean_bonus.c \
	$(SRC_DIR_BONUS)_utils/clean_sprites_bonus.c \
	$(SRC_DIR_BONUS)_utils/init_bonus.c \
	$(SRC_DIR_BONUS)_utils/init_imgs_bonus.c \
	$(SRC_DIR_BONUS)_utils/time_bonus.c \
	$(SRC_DIR_BONUS)_utils/cache_bonus.c \
	$(SRC_DIR_BONUS)raycasting/raycasting_bonus.c \
	$(SRC_DIR_BONUS)raycasting/drawing_bonus.c \
	$(SRC_DIR_BONUS)raycasting/utils_bonus.c \
	$(SRC_DIR_BONUS)raycasting/utils_draw_bonus.c \
	$(SRC_DIR_BONUS)raycasting/collision_bonus.c \
	$(SRC_DIR_BONUS)raycasting/flashlight_bonus.c \
	$(SRC_DIR_BONUS)parsing/utils_bonus.c \
	$(SRC_DIR_BONUS)parsing/color_bonus.c \
	$(SRC_DIR_BONUS)parsing/param_bonus.c \
	$(SRC_DIR_BONUS)parsing/parsing_bonus.c \
	$(SRC_DIR_BONUS)parsing/parse_line_bonus.c \
	$(SRC_DIR_BONUS)player/init_player_bonus.c \
	$(SRC_DIR_BONUS)player/move_player_bonus.c \
	$(SRC_DIR_BONUS)player/jump_crouch_bonus.c \
	$(SRC_DIR_BONUS)settings/init_settings_bonus.c \
	$(SRC_DIR_BONUS)settings/register_bonus.c \
	$(SRC_DIR_BONUS)settings/draw_bonus.c \
	$(SRC_DIR_BONUS)settings/draw_btn_bonus.c \
	$(SRC_DIR_BONUS)settings/draw_sld_bonus.c \
	$(SRC_DIR_BONUS)settings/buttons_bonus.c \
	$(SRC_DIR_BONUS)settings/keys_bonus.c \
	$(SRC_DIR_BONUS)settings/utils_change_bonus.c \
	$(SRC_DIR_BONUS)minimap/minimap_bonus.c \
	$(SRC_DIR_BONUS)minimap/cells_bonus.c \
	$(SRC_DIR_BONUS)sprites/init_sprites_bonus.c \
	$(SRC_DIR_BONUS)sprites/sprites_bonus.c

OBJ_FILES		:= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))
DEP				:= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.d, $(SRC_FILES))
OBJ_FILES_BONUS	:= $(patsubst $(SRC_DIR_BONUS)%.c, $(OBJ_DIR_BONUS)%.o, $(SRC_FILES_BONUS))
DEP_BONUS		:= $(patsubst $(SRC_DIR_BONUS)%.c, $(OBJ_DIR_BONUS)%.d, $(SRC_FILES_BONUS))

GREEN	= \033[0;32m
BLUE 	= \033[38;5;39m
BLUE2 	= \033[0;34m
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
" $(RESET)██████$(BLUE2)╗$(RESET)██$(BLUE2)╗   $(RESET)██$(BLUE2)╗$(RESET)██████$(BLUE2)╗ $(RESET)██████$(BLUE2)╗ $(RESET)██████$(BLUE2)╗  \n" \
"$(RESET)██$(BLUE2)╔════╝$(RESET)██$(BLUE2)║   $(RESET)██$(BLUE2)║$(RESET)██$(BLUE2)╔══$(RESET)██$(BLUE2)╗╚════$(RESET)██$(BLUE2)╗$(RESET)██$(BLUE2)╔══$(RESET)██$(BLUE2)╗ \n" \
"$(RESET)██$(BLUE2)║     $(RESET)██$(BLUE2)║   $(RESET)██$(BLUE2)║$(RESET)██████$(BLUE2)╔╝ $(RESET)█████$(BLUE2)╔╝$(RESET)██$(BLUE2)║  $(RESET)██$(BLUE2)║ \n" \
"$(RESET)██$(BLUE2)║     $(RESET)██$(BLUE2)║   $(RESET)██$(BLUE2)║$(RESET)██$(BLUE2)╔══$(RESET)██$(BLUE2)╗ ╚═══$(RESET)██$(BLUE2)╗$(RESET)██$(BLUE2)║  $(RESET)██$(BLUE2)║ \n" \
"$(BLUE2)╚$(RESET)██████$(BLUE2)╗╚$(RESET)██████$(BLUE2)╔╝$(RESET)██████$(BLUE2)╔╝$(RESET)██████$(BLUE2)╔╝$(RESET)██████$(BLUE2)╔╝ \n" \
"$(BLUE2) ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝  $(RESET)\n"

BONUS_BANNER = \
"\n $(RED)$(RESET)██$(RED)╗   $(RESET)██$(RED)╗$(RESET)███$(RED)╗   $(RESET)██$(RED)╗$(RESET)██████$(RED)╗ $(RESET)███████$(RED)╗$(RESET)███████$(RED)╗$(RESET)██$(RED)╗$(RESET)███$(RED)╗   $(RESET)██$(RED)╗$(RESET)███████$(RED)╗$(RESET)██████$(RED)╗ $(RESET)\n" \
"$(RED)$(RESET)██$(RED)║   $(RESET)██$(RED)║$(RESET)████$(RED)╗  $(RESET)██$(RED)║$(RESET)██$(RED)╔══$(RESET)██$(RED)╗$(RESET)██$(RED)╔════╝$(RESET)██$(RED)╔════╝$(RESET)██$(RED)║$(RESET)████$(RED)╗  $(RESET)██$(RED)║$(RESET)██$(RED)╔════╝$(RESET)██$(RED)╔══$(RESET)██$(RED)╗$(RESET)\n" \
"$(RED)$(RESET)██$(RED)║   $(RESET)██$(RED)║$(RESET)██$(RED)╔$(RESET)██$(RED)╗ $(RESET)██$(RED)║$(RESET)██$(RED)║  $(RESET)██$(RED)║$(RESET)█████$(RED)╗  $(RESET)█████$(RED)╗  $(RESET)██$(RED)║$(RESET)██$(RED)╔$(RESET)██$(RED)╗ $(RESET)██$(RED)║$(RESET)█████$(RED)╗  $(RESET)██$(RED)║  $(RESET)██$(RED)║$(RESET)\n" \
"$(RED)$(RESET)██$(RED)║   $(RESET)██$(RED)║$(RESET)██$(RED)║╚$(RESET)██$(RED)╗$(RESET)██$(RED)║$(RESET)██$(RED)║  $(RESET)██$(RED)║$(RESET)██$(RED)╔══╝  $(RESET)██$(RED)╔══╝  $(RESET)██$(RED)║$(RESET)██$(RED)║╚$(RESET)██$(RED)╗$(RESET)██$(RED)║$(RESET)██$(RED)╔══╝  $(RESET)██$(RED)║  $(RESET)██$(RED)║$(RESET)\n" \
"$(RED)╚$(RESET)██████$(RED)╔╝$(RESET)██$(RED)║ ╚$(RESET)████$(RED)║$(RESET)██████$(RED)╔╝$(RESET)███████$(RED)╗$(RESET)██$(RED)║     $(RESET)██$(RED)║$(RESET)██$(RED)║ ╚$(RESET)████$(RED)║$(RESET)███████$(RED)╗$(RESET)██████$(RED)╔╝$(RESET)\n" \
"$(RED) ╚═════╝ ╚═╝  ╚═══╝╚═════╝ ╚══════╝╚═╝     ╚═╝╚═╝  ╚═══╝╚══════╝╚═════╝ $(RESET)\n" \
" $(RESET)██████$(BLUE2)╗$(RESET)██$(BLUE2)╗   $(RESET)██$(BLUE2)╗$(RESET)██████$(BLUE2)╗ $(RESET)██████$(BLUE2)╗ $(RESET)██████$(BLUE2)╗     $(RESET)██████$(BLUE2)╗  $(RESET)██████$(BLUE2)╗ $(RESET)███$(BLUE2)╗   $(RESET)██$(BLUE2)╗$(RESET)██$(BLUE2)╗   $(RESET)██$(BLUE2)╗$(RESET)███████$(BLUE2)╗ \n" \
"$(RESET)██$(BLUE2)╔════╝$(RESET)██$(BLUE2)║   $(RESET)██$(BLUE2)║$(RESET)██$(BLUE2)╔══$(RESET)██$(BLUE2)╗╚════$(RESET)██$(BLUE2)╗$(RESET)██$(BLUE2)╔══$(RESET)██$(BLUE2)╗    $(RESET)██$(BLUE2)╔══$(RESET)██$(BLUE2)╗$(RESET)██$(BLUE2)╔═══$(RESET)██$(BLUE2)╗$(RESET)████$(BLUE2)╗  $(RESET)██$(BLUE2)║$(RESET)██$(BLUE2)║   $(RESET)██$(BLUE2)║$(RESET)██$(BLUE2)╔════╝ \n" \
"$(RESET)██$(BLUE2)║     $(RESET)██$(BLUE2)║   $(RESET)██$(BLUE2)║$(RESET)██████$(BLUE2)╔╝ $(RESET)█████$(BLUE2)╔╝$(RESET)██$(BLUE2)║  $(RESET)██$(BLUE2)║    $(RESET)██████$(BLUE2)╔╝$(RESET)██$(BLUE2)║   $(RESET)██$(BLUE2)║$(RESET)██$(BLUE2)╔$(RESET)██$(BLUE2)╗ $(RESET)██$(BLUE2)║$(RESET)██$(BLUE2)║   $(RESET)██$(BLUE2)║$(RESET)███████$(BLUE2)╗ \n" \
"$(RESET)██$(BLUE2)║     $(RESET)██$(BLUE2)║   $(RESET)██$(BLUE2)║$(RESET)██$(BLUE2)╔══$(RESET)██$(BLUE2)╗ ╚═══$(RESET)██$(BLUE2)╗$(RESET)██$(BLUE2)║  $(RESET)██$(BLUE2)║    $(RESET)██$(BLUE2)╔══$(RESET)██$(BLUE2)╗$(RESET)██$(BLUE2)║   $(RESET)██$(BLUE2)║$(RESET)██$(BLUE2)║╚$(RESET)██$(BLUE2)╗$(RESET)██$(BLUE2)║$(RESET)██$(BLUE2)║   $(RESET)██$(BLUE2)║╚════$(RESET)██$(BLUE2)║ \n" \
"$(BLUE2)╚$(RESET)██████$(BLUE2)╗╚$(RESET)██████$(BLUE2)╔╝$(RESET)██████$(BLUE2)╔╝$(RESET)██████$(BLUE2)╔╝$(RESET)██████$(BLUE2)╔╝    $(RESET)██████$(BLUE2)╔╝╚$(RESET)██████$(BLUE2)╔╝$(RESET)██$(BLUE2)║ ╚$(RESET)████$(BLUE2)║╚$(RESET)██████$(BLUE2)╔╝$(RESET)███████$(BLUE2)║ \n" \
"$(BLUE2) ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝     ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝ $(RESET)\n"
                                                                                         
all: banner $(LIBFT) $(MATHFT) $(MLX) $(NAME)

banner:
	@echo $(BANNER)

bonus_banner:
	@echo $(BONUS_BANNER)

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(MATHFT):
	@$(MAKE) --no-print-directory -C $(MATHFT_DIR)

$(MLX_DIR):
	@git clone -q --config advice.detachedHead=false --depth=1 https://github.com/seekrs/MacroLibX.git -b v2.2.2 $(MLX_DIR)
	@echo "$(RED)[GIT] MacroLibX cloned ✔$(RESET)"

$(MLX): $(MLX_DIR)
	@$(MAKE) --no-print-directory -C $(MLX_DIR) -j
	@echo "$(RED)[OK] MacroLibX compiled ✔$(RESET)"

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR) -I $(MATHFT_DIR) -I $(MLX_DIR)/includes -o $@ $^ $(LIBFT) $(MATHFT) $(MLX) $(LDFLAGS)
	@echo "$(BLUE)[OK] $(NAME) compiled ✔$(RESET)"

bonus: bonus_banner $(LIBFT) $(MATHFT) $(MLX) $(OBJ_FILES_BONUS)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR) -I $(MATHFT_DIR) -I $(MLX_DIR)/includes -o $(NAME) $(OBJ_FILES_BONUS) $(LIBFT) $(MATHFT) $(MLX) $(LDFLAGS)
	@echo "$(BLUE)[OK] $(NAME) (bonus) compiled ✔$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR) -I $(MATHFT_DIR) -I $(MLX_DIR)/includes -c $< -o $@

$(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR) -I $(MATHFT_DIR) -I $(MLX_DIR)/includes -c $< -o $@

clean:
	@rm -rf obj/
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@$(MAKE) --no-print-directory -C $(MATHFT_DIR) clean
	@rm -rf $(MLX_DIR)/objs
	@echo "$(GREEN)[CLEAN] Objects removed ✔$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@$(MAKE) --no-print-directory -C $(MATHFT_DIR) fclean
	@rm -rf $(MLX_DIR)
	@echo "$(GREEN)[FCLEAN] Binaries removed ✔$(RESET)"

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus

-include $(DEP) $(DEP_BONUS)