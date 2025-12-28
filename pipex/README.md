*Ce projet a été créé dans le cadre du cursus 42 par achauvie.*

# pipex
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
- Utilisez la commande `make` pour générer le programme.
- Utilisez la commande `./pipex file1 cmd1 cmd2 file2` pour lancer le programme.
	- **file1** et **file2** sont des noms de fichiers.
	- **cmd1** et **cmd2** sont des commandes shell avec leurs paramètres.
	- Exemple : `./pipex infile "ls -l" "wc -l" outfile`

## Bonus

## Utilisation de l’IA

## Resources
- [libft](https://github.com/AlexisParder/42_Cursus/tree/main/libft)