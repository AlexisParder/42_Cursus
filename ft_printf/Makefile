NAME = libftprintf.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
INC_DIR = -I includes/
SRC_DIR = srcs/
SRC_FILES = $(SRC_DIR)ft_printf.c \
			$(SRC_DIR)ft_printf_utils.c \
			$(SRC_DIR)ft_printf_str_utils.c 
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
		ar rcs -o $(NAME) $(OBJ_FILES)

%.o : %.c
		$(CC) $(CFLAGS) $(INC_DIR) -o $@ -c $<

clean:
		rm -rf $(OBJ_FILES)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re