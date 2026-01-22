*Ce projet a été créé dans le cadre du cursus 42 par achauvie.*

# libft
![42 Cursus](https://img.shields.io/badge/42-Cursus-blue?style=for-the-badge)
![Projects](https://img.shields.io/badge/Projects-Common_Core-success?style=for-the-badge)
[![Score](https://img.shields.io/badge/score-115%20%2F%20100-success?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus/tree/main/libft)<br>
[🇬🇧 English](./README_EN.md)
- [libft](#libft)
	- [Description](#description)
	- [Fonctions obligatoires](#fonctions-obligatoires)
	- [Fonctions bonus](#fonctions-bonus)
	- [Projets supplémentaires intégrés](#projets-supplémentaires-intégrés)
	- [Instructions](#instructions)

## Description
Un projet fondamental du cursus 42.
Libft consiste à recréer une version personnalisée de la bibliothèque standard C en implémentant un large ensemble de fonctions essentielles pour la manipulation de la mémoire, la gestion des chaînes de caractères, les vérifications de caractères et les opérations sur les listes chaînées.
Cette bibliothèque devient une dépendance centrale pour tous les projets suivants (get_next_line, ft_printf, push_swap, minishell, etc.) et pose des bases solides en programmation bas niveau, gestion de la mémoire et structure de code propre.

## Fonctions obligatoires
- **ft_isalpha**
	- Vérifie si le caractère est alphabétique (a–z ou A–Z).
- **ft_isdigit**
	- Vérifie si le caractère est un chiffre décimal (0–9).
- **ft_isalnum**
	- Vérifie si le caractère est alphanumérique (lettre ou chiffre).
- **ft_isascii**
	- Vérifie si le caractère est un caractère ASCII valide (0–127).
- **ft_isprint**
	- Vérifie si le caractère est imprimable (y compris l’espace).
- **ft_toupper**
	- Convertit une lettre minuscule en majuscule.
- **ft_tolower**
	- Convertit une lettre majuscule en minuscule.
- **ft_strlen**
	- Retourne la longueur d’une chaîne de caractères.
- **ft_memset**
	- Remplit une zone mémoire avec une valeur donnée.
- **ft_bzero**
	- Met une zone mémoire à zéro.
- **ft_memcpy**
	- Copie une zone mémoire vers une autre (sans gestion du chevauchement).
- **ft_memmove**
	- Copie une zone mémoire en gérant correctement les zones qui se chevauchent.
- **ft_memchr**
	- Recherche un octet dans une zone mémoire.
- **ft_memcmp**
	- Compare deux zones mémoire.
- **ft_strlcpy**
	- Copie une chaîne dans un buffer avec une limitation de taille.
- **ft_strlcat**
	- Concatène une chaîne dans un buffer avec une limitation de taille.
- **ft_strchr**
	- Trouve la première occurrence d’un caractère dans une chaîne.
- **ft_strrchr**
	- Trouve la dernière occurrence d’un caractère dans une chaîne.
- **ft_strncmp**
	- Compare deux chaînes jusqu’à n caractères.
- **ft_strnstr**
	- Recherche une sous-chaîne dans une autre chaîne, avec une limite de longueur.
- **ft_strdup**
	- Duplique une chaîne en utilisant la mémoire dynamique.
- **ft_atoi**
	- Convertit une chaîne en entier.
- **ft_calloc**
	- Alloue de la mémoire et l’initialise à zéro.
- **ft_substr**
	- Alloue et retourne une sous-chaîne à partir d’une chaîne donnée.
- **ft_strjoin**
	- Assemble deux chaînes dans une nouvelle chaîne allouée.
- **ft_strtrim**
	- Supprime les caractères au début et à la fin d’une chaîne selon un ensemble donné.
- **ft_split**
	- Découpe une chaîne en sous-chaînes à partir d’un délimiteur.
- **ft_itoa**
	- Convertit un entier en chaîne de caractères.
- **ft_strmapi**
	- Applique une fonction à chaque caractère d’une chaîne et retourne une nouvelle chaîne.
- **ft_striteri**
	- Applique une fonction à chaque caractère d’une chaîne en passant son index.
- **ft_putchar_fd**
	- Écrit un caractère sur un descripteur de fichier.
- **ft_putstr_fd**
	- Écrit une chaîne sur un descripteur de fichier.
- **ft_putendl_fd**
	- Écrit une chaîne suivie d’un retour à la ligne sur un descripteur de fichier.
- **ft_putnbr_fd**
	- Écrit un entier en base 10 sur un descripteur de fichier.

## Fonctions bonus
- **ft_lstnew**
	- Alloue un nouveau maillon de liste avec le contenu donné.
- **ft_lstadd_front**
	- Ajoute un maillon au début de la liste.
- **ft_lstsize**
	- Compte le nombre de maillons dans la liste.
- **ft_lstlast**
	- Retourne le dernier maillon de la liste.
- **ft_lstadd_back**
	- Ajoute un maillon à la fin de la liste.
- **ft_lstdelone**
	- Supprime un maillon et libère son contenu à l’aide de la fonction del.
- **ft_lstclear**
	- Supprime et libère entièrement la liste.
- **ft_lstiter**
	- Parcourt la liste et applique une fonction au contenu de chaque maillon.
- **ft_lstmap**
	- Crée une nouvelle liste en appliquant une fonction à chaque maillon d’une liste existante.

## Projets supplémentaires intégrés
Les fonctions suivantes proviennent de deux projets distincts du cursus 42 — get_next_line et ft_printf.
Elles ne font pas partie du projet Libft obligatoire original, mais sont souvent intégrées par la suite afin d’enrichir la bibliothèque avec des fonctionnalités plus avancées telles que l’affichage formaté et la lecture de fichiers ligne par ligne.
- [ft_printf](https://github.com/AlexisParder/42_Cursus/tree/main/ft_printf)
	- Une réimplémentation personnalisée de la fonction standard printf.
- [get_next_line](https://github.com/AlexisParder/42_Cursus/tree/main/get_next_line)
	- Lit un descripteur de fichier ligne par ligne, en retournant une ligne par appel, quelle que soit la taille du buffer.

## Instructions
- Utilisez la commande `make` pour compiler l’archive.
	- Utilisez la commande `make bonus` pour compiler l’archive avec les fonctions bonus.
- Exportez les fichiers `libft.a` et `libft.h` vers le programme qui nécessite ces fonctions.