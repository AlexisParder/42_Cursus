# libft
*This project has been created as part of the 42 curriculum by achauvie.*

## Description
A foundational project from the 42 curriculum.
Libft consists of recreating a custom version of the standard C library by implementing a wide set of essential functions for memory manipulation, string handling, character checks, and linked list operations.
This library becomes a core dependency for all subsequent projects (get_next_line, ft_printf, push_swap, minishell, etc.) and establishes strong fundamentals in low-level programming, memory management, and clean code structure.

## Functions Mandatory
- **ft_isalpha**
	- Vérifie si un caractère est alphabétique (a–z ou A–Z).
- **ft_isdigit**
	- Vérifie si un caractère est un chiffre décimal (0–9).
- **ft_isalnum**
	- Vérifie si un caractère est alphanumérique (lettre ou chiffre).
- **ft_isascii**
	- Vérifie si un caractère est un caractère ASCII valide (0–127).
- **ft_isprint**
	- Vérifie si un caractère est imprimable (y compris l’espace).
- **ft_toupper**
	- Convertit une lettre minuscule en majuscule si possible.
- **ft_tolower**
	- Convertit une lettre majuscule en minuscule si possible.
- **ft_strlen**
	- Retourne la longueur d’une chaîne de caractères.
- **ft_memset**
	- Remplit un bloc mémoire avec une valeur donnée.
- **ft_bzero**
	- Met à zéro un bloc mémoire sur une taille donnée.
- **ft_memcpy**
	- Copie un bloc mémoire vers un autre (sans chevauchement garanti).
- **ft_memmove**
	- Copie un bloc mémoire en gérant le chevauchement des zones.
- **ft_memchr**
	- Recherche un caractère dans un bloc mémoire.
- **ft_memcmp**
	- Compare deux blocs mémoire.
- **ft_strlcpy**
	- Copie une chaîne dans un buffer en limitant la taille.
- **ft_strlcat**
	- Concatène une chaîne dans un buffer en limitant la taille.
- **ft_strchr**
	- Cherche la première occurrence d’un caractère dans une chaîne.
- **ft_strrchr**
	- Cherche la dernière occurrence d’un caractère dans une chaîne.
- **ft_strncmp**
	- Compare deux chaînes jusqu’à n caractères.
- **ft_strnstr**
	- Cherche une sous-chaîne dans une autre, limitée par une longueur.
- **ft_strdup**
	- Duplique une chaîne en allouant de la mémoire.
- **ft_atoi**
	- Convertit une chaîne en entier (ASCII to int).
- **ft_calloc**
	- Alloue de la mémoire et l’initialise à zéro.
- **ft_substr**
	- Alloue et retourne une sous-chaîne à partir d’une chaîne donnée.
- **ft_strjoin**
	- Concatène deux chaînes dans une nouvelle chaîne allouée.
- **ft_strtrim**
	- Supprime les caractères d’un set au début et à la fin d’une chaîne.
- **ft_split**
	- Divise une chaîne en tableau de chaînes selon un délimiteur.
- **ft_itoa**
	- Convertit un entier en chaîne de caractères.
- **ft_strmapi**
	- Applique une fonction sur chaque caractère d’une chaîne et retourne une nouvelle chaîne.
- **ft_striteri**
	- Applique une fonction à chaque caractère de la chaîne (indexes fournis).
- **ft_putchar_fd**
	- Écrit un caractère sur un descripteur de fichier.
- **ft_putstr_fd**
	- Écrit une chaîne sur un descripteur de fichier.
- **ft_putendl_fd**
	- Écrit une chaîne suivie d’un saut de ligne.
- **ft_putnbr_fd**
	- Écrit un entier en base 10 sur un descripteur de fichier.
## Functions Bonus
- **ft_lstnew**
	- Alloue une nouvelle liste avec le contenu donné.
- **ft_lstadd_front**
	- Ajoute un élément au début de la liste.
- **ft_lstsize**
	- Compte le nombre d’éléments dans la liste.
- **ft_lstlast**
	- Retourne le dernier élément de la liste.
- **ft_lstadd_back**
	- Ajoute un élément à la fin de la liste.
- **ft_lstdelone**
	- Supprime un élément et libère son contenu à l’aide de del.
- **ft_lstclear**
	- Supprime et libère toute la liste.
- **ft_lstiter**
	- Parcourt la liste en appliquant f au contenu de chaque élément.
- **ft_lstmap**
	- Crée une nouvelle liste en appliquant une fonction à chaque élément.

## Instructions
- Use the `make` command to generate the archive.
	- Use the `make bonus` command to generate the archive with bonus functions.
- Export the `libft.a` and `libft.h` files to the program that requires these functions.