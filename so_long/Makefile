NAME = so_long
CC = cc 
CFLAGS = -Wall -Wextra -Werror
INC_DIR = -I includes/ -I libs/MacroLibX/includes
SRC_DIR = srcs/
SRC_FILES = $(SRC_DIR)main.c \
			$(SRC_DIR)utils/utils_imgs.c
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