*Ce projet a été créé dans le cadre du cursus 42 par achauvie.*

# pipex
[![Score](https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus/tree/main/pipex)<br>
[🇬🇧 English](./README_EN.md)
- [pipex](#pipex)
	- [Description](#description)
	- [Instructions](#instructions)
	- [Bonus](#bonus)
	- [Utilisation de l’IA](#utilisation-de-lia)
	- [Resources](#resources)

## Description
Un projet visant à reproduire le comportement des pipelines Unix en redirigeant les flux d’entrée et de sortie entre plusieurs commandes. Le programme doit créer correctement des processus avec fork, mettre en place des pipes, gérer les descripteurs de fichiers et exécuter les commandes via la résolution du PATH, tout en garantissant une gestion stricte des erreurs et une sécurité mémoire totale.
Le bonus consiste à gérer plusieurs pipes ainsi que la fonctionnalité heredoc.
Ce projet renforce la maîtrise des processus, des appels système, de la redirection des entrées/sorties, des variables d’environnement et de la communication inter-processus, tout en apprenant à orchestrer des flux de données complexes au niveau système.

## Instructions
- Utilisez la commande `make` pour compiler le programme.
	- Utilisez la commande `make bonus` pour compiler le programme avec les bonus.
- Utilisez la commande `./pipex file1 cmd1 cmd2 file2` pour lancer le programme.
	- **file1** et **file2** sont des noms de fichiers.
	- **cmd1** et **cmd2** sont des commandes shell avec leurs paramètres.
	- Exemple : `./pipex infile "ls -l" "wc -l" outfile`
    	- L'equivalent en **bash** serait `< infile ls -l | wc -l > outfile`

## Bonus
- [x] Gérer plusieurs pipes.
	- `./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2`
	- L'equivalent en **bash** serait `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`
- [x] Prise en charge de `«` et `»` lorsque le premier paramètre est `here_doc`.
	- `./pipex here_doc LIMITER cmd cmd1 file`
	- L'equivalent en **bash** serait `cmd << LIMITER | cmd1 >> file`

## Utilisation de l’IA
L’intelligence artificielle a été utilisée comme support pour comprendre et regrouper les notions clés du projet, notamment les concepts de forks, pipes et autres mécanismes systèmes.

## Resources
- [Les processus Unix en C](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
- [Pipes, Forks & Dups par Roslyn McConnell](https://www.rozmichelle.com/pipes-forks-dups/)
- [libft](https://github.com/AlexisParder/42_Cursus/tree/main/libft)
- [pipex tester](https://github.com/bastienkody/pipex_tester)