NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror
INC_FILES = -I push_swap.h
SRC_FILES = main.c \
			utils_str.c \
			utils_swap.c \
			utils_push.c \
 			utils_rotation.c \
 			utils_rotation_rev.c \
			utils_stack.c \
			utils_check_parsing.c \
			utils_global.c \
			quick_sort.c \
			calc_moves.c \
			utils_calc_moves.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
		$(CC) $(CFLAGS) $(INC_FILES) -o $@ $^ libft.a

%.o : %.c
		$(CC) $(CFLAGS) $(INC_FILES) -o $@ -c $<

clean:
		rm -rf $(OBJ_FILES)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re