NAME = libft.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
INC_FILES = -I .
SRC_FILES = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_atol.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strjoin_free.c \
			ft_strtrim.c \
			ft_split.c \
			ft_split_all_space.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_printf.c \
			ft_printf_utils.c \
			get_next_line.c \
			ft_free_arr.c \
			ft_char_occur.c \
			ft_arr_len.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Colors
GREEN	= \033[0;32m
BLUE	= \033[0;34m
YELLOW	= \033[0;33m
RED		= \033[0;31m
RESET	= \033[0m

all: $(NAME)

$(NAME): $(OBJ_FILES)
		@echo "$(BLUE)[BUILD] Compiling $(NAME)...$(RESET)"
		@ar rcs -o $(NAME) $(OBJ_FILES)
		@echo "$(GREEN)[OK] $(NAME) ready ✔$(RESET)"

%.o : %.c
		@$(CC) $(CFLAGS) $(INC_FILES) -o $@ -c $<

clean:
		@echo "$(YELLOW)[CLEAN] Removing object files...$(RESET)"
		@rm -rf $(OBJ_FILES)
		@echo "$(GREEN)[CLEAN] OK ✔$(RESET)"

fclean: clean
		@echo "$(RED)[FCLEAN] Removing binaries...$(RESET)"
		@rm -rf $(NAME)
		@echo "$(GREEN)[FCLEAN] OK ✔$(RESET)"

re: fclean all
		@echo "$(GREEN)[RE] Rebuild finished ✔$(RESET)"

.PHONY: all clean fclean re