NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libs/libft.a

INC_DIR = -I includes/

SRC_DIR = srcs/
SRC_FILES = $(SRC_DIR)main.c

OBJ_FILES = $(SRC_FILES:.c=.o)

LIBS = $(LIBFT)

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