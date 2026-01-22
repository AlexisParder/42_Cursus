*Ce projet a été créé dans le cadre du cursus 42 par achauvie et tjourdai.*

# minishell
![42 Cursus](https://img.shields.io/badge/42-Cursus-blue?style=for-the-badge)
![Projects](https://img.shields.io/badge/Projects-Common_Core-success?style=for-the-badge)
<!-- [![Score](https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus/tree/main/minishell)<br> -->
[🇬🇧 English](./README_EN.md)
- [minishell](#minishell)
	- [Description](#description)
	- [Instructions](#instructions)
	- [Bonus](#bonus)
	- [Utilisation de l’IA](#utilisation-de-lia)
	- [Resources](#resources)

## Description
Un projet complet de programmation système consistant à recréer un shell Unix simplifié à partir de zéro. Le programme doit analyser et exécuter les commandes utilisateur, gérer les variables d’environnement, prendre en charge les commandes intégrées (built-ins), supporter les pipes et les redirections, et propager correctement les codes de sortie. La difficulté réside dans la tokenisation précise de l’entrée, la gestion de la création des processus, le traitement des signaux (Ctrl-C, Ctrl-D, Ctrl-\\), ainsi que la reproduction d’un comportement proche de Bash dans des limites définies. Ce projet permet de développer une solide expertise en contrôle des processus, en logique de parsing, en gestion des descripteurs de fichiers, en gestion des signaux et en récupération d’erreurs robuste dans un environnement C bas niveau.

## Instructions
<!-- - Utilisez la commande `make` pour compiler le programme.
	- Utilisez la commande `make bonus` pour compiler le programme avec les bonus.
- Utilisez la commande `./pipex file1 cmd1 cmd2 file2` pour lancer le programme.
	- **file1** et **file2** sont des noms de fichiers.
	- **cmd1** et **cmd2** sont des commandes shell avec leurs paramètres.
	- Exemple : `./pipex infile "ls -l" "wc -l" outfile`
    	- L'equivalent en **bash** serait `< infile ls -l | wc -l > outfile` -->

## Bonus
<!-- - [x] Gérer plusieurs pipes.
	- `./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2`
	- L'equivalent en **bash** serait `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`
- [ ] Prise en charge de « and » lorsque le premier paramètre est « here_doc ».
	- `./pipex here_doc LIMITER cmd cmd1 file`
	- L'equivalent en **bash** serait `cmd << LIMITER | cmd1 >> file` -->

## Utilisation de l’IA
<!-- L’intelligence artificielle a été utilisée comme support pour comprendre et regrouper les notions clés du projet, notamment les concepts de forks, pipes et autres mécanismes systèmes. -->

## Resources
<!-- - [Les processus Unix en C](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
- [Pipes, Forks & Dups par Roslyn McConnell](https://www.rozmichelle.com/pipes-forks-dups/) -->
- [libft](https://github.com/AlexisParder/42_Cursus/tree/main/libft)