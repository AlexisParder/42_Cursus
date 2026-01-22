*Ce projet a été créé dans le cadre du cursus 42 par achauvie.*

# ft_printf
[![Score](https://img.shields.io/badge/score-100%20%2F%20100-success?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus/tree/main/ft_printf)<br>
[🇬🇧 English](./README_EN.md)
- [ft\_printf](#ft_printf)
	- [Description](#description)
	- [Instructions](#instructions)
	- [Exemple d’utilisation](#exemple-dutilisation)
	- [Ressources](#ressources)

## Description
Une réimplémentation complète de la célèbre fonction printf en C.
Le projet a pour objectif de gérer l’affichage formaté en analysant les chaînes de format et en prenant en charge les arguments variables à l’aide de stdarg.h.
Il couvre toutes les conversions obligatoires (c, s, p, d, i, u, x, X, %) et met l’accent sur la construction d’un moteur de formatage modulaire, bien structuré et efficace.
Ce projet renforce les compétences en logique de parsing, conversions de bases, gestion de buffers et architecture de fonctions.

## Instructions
- Utilisez la commande `make` pour compiler l’archive.
- Exportez les fichiers `ft_printf.a` et `ft_printf.h` vers le programme qui nécessite la fonction `ft_printf`.

## Exemple d’utilisation
La fonction s’utilise comme le `printf` classique.<br>
`int printf(const char *format, ...);`

## Ressources
- man 3 printf
- [libft](https://github.com/AlexisParder/42_Cursus/tree/main/libft)