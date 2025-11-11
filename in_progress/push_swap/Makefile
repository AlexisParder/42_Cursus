NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror
INC_FILES = -I libft.h \
			push_swap.h \
			libft.a
SRC_FILES = main.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
		$(CC) $(CFLAGS) $(INC_FILES) -o $@ $^

%.o : %.c
		$(CC) $(CFLAGS) $(INC_FILES) -o $@ -c $<

clean:
		rm -rf $(OBJ_FILES)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re