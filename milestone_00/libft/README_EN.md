*This project has been created as part of the 42 curriculum by achauvie.*

# libft
![42 Cursus](https://img.shields.io/badge/42-Cursus-blue?style=for-the-badge)
![Projects](https://img.shields.io/badge/Projects-Common_Core-success?style=for-the-badge)
[![Score](https://img.shields.io/badge/score-115%20%2F%20100-success?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus/tree/main/libft)<br>
[🇫🇷 French](./README.md)
- [libft](#libft)
	- [Description](#description)
	- [Functions Mandatory](#functions-mandatory)
	- [Functions Bonus](#functions-bonus)
	- [Additional Projects Integrated](#additional-projects-integrated)
	- [Instructions](#instructions)

## Description
A foundational project from the 42 curriculum.
Libft consists of recreating a custom version of the standard C library by implementing a wide set of essential functions for memory manipulation, string handling, character checks, and linked list operations.
This library becomes a core dependency for all subsequent projects (get_next_line, ft_printf, push_swap, minishell, etc.) and establishes strong fundamentals in low-level programming, memory management, and clean code structure.

## Functions Mandatory
- **ft_isalpha**
	- Checks if the character is alphabetic (a–z or A–Z).
- **ft_isdigit**
	- Checks if the character is a decimal digit (0–9).
- **ft_isalnum**
	- Checks if the character is alphanumeric (letter or digit).
- **ft_isascii**
	- Checks if the character is a valid ASCII character (0–127).
- **ft_isprint**
	- Checks if the character is printable (including space).
- **ft_toupper**
	- Converts a lowercase letter to uppercase.
- **ft_tolower**
	- Converts an uppercase letter to lowercase.
- **ft_strlen**
	- Returns the length of a string.
- **ft_memset**
	- Fills a block of memory with a given value.
- **ft_bzero**
	- Sets a block of memory to zero.
- **ft_memcpy**
	- Copies a block of memory to another (no overlap handling).
- **ft_memmove**
	- Copies a block of memory while handling overlapping areas safely.
- **ft_memchr**
	- Searches for a byte in a block of memory.
- **ft_memcmp**
	- Compares two blocks of memory.
- **ft_strlcpy**
	- Copies a string into a buffer with size limitation.
- **ft_strlcat**
	- Concatenates a string into a buffer with size limitation.
- **ft_strchr**
	- Finds the first occurrence of a character in a string.
- **ft_strrchr**
	- Finds the last occurrence of a character in a string.
- **ft_strncmp**
	- Compares two strings up to n characters.
- **ft_strnstr**
	- Searches for a substring inside another string, limited by length.
- **ft_strdup**
	- Duplicates a string using dynamic memory.
- **ft_atoi**
	- Converts a string to an integer.
- **ft_calloc**
	- Allocates memory and initializes it to zero.
- **ft_substr**
	- Allocates and returns a substring from a given string.
- **ft_strjoin**
	- Joins two strings into a newly allocated string.
- **ft_strtrim**
	- Trims characters from the start and end of a string based on a given set.
- **ft_split**
	- Splits a string into substrings based on a delimiter.
- **ft_itoa**
	- Converts an integer into a string.
- **ft_strmapi**
	- Applies a function to each character of a string and returns a new string.
- **ft_striteri**
	- Applies a function to each character of a string, passing its index.
- **ft_putchar_fd**
	- Writes a character to a file descriptor.
- **ft_putstr_fd**
	- Writes a string to a file descriptor.
- **ft_putendl_fd**
	- Writes a string followed by a newline to a file descriptor.
- **ft_putnbr_fd**
	- Writes an integer in base 10 to a file descriptor.

## Functions Bonus
- **ft_lstnew**
	- Allocates a new list node with the given content.
- **ft_lstadd_front**
	- Adds a node at the beginning of the list.
- **ft_lstsize**
	- Counts the number of nodes in the list.
- **ft_lstlast**
	- Returns the last node of the list.
- **ft_lstadd_back**
	- Adds a node at the end of the list.
- **ft_lstdelone**
	- Deletes a node and frees its content using the del function.
- **ft_lstclear**
	- Deletes and frees the entire list.
- **ft_lstiter**
	- Iterates through the list and applies a function to each node's content.
- **ft_lstmap**
	- Creates a new list by applying a function to each node of an existing list.

## Additional Projects Integrated
The following functions come from two separate 42 projects — get_next_line and ft_printf.
They are not part of the original mandatory Libft project, but they are commonly integrated afterwards to extend the library with more advanced features such as formatted output and line-by-line file reading.
- [ft_printf](https://github.com/AlexisParder/42_Cursus/tree/main/ft_printf)
	- A custom re-implementation of the standard printf function.
- [get_next_line](https://github.com/AlexisParder/42_Cursus/tree/main/get_next_line)
	- Reads a file descriptor line by line, returning one line per call, regardless of the buffer size.

## Instructions
- Use the `make` command to compile the archive.
	- Use the `make bonus` command to compile the archive with bonus functions.
- Export the `libft.a` and `libft.h` files to the program that requires these functions.