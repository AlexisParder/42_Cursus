*Ce projet a été créé dans le cadre du cursus 42 par achauvie.*

# philosophers
<!-- [![Score](https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus/tree/main/philosophers)<br> -->
[🇬🇧 English](./README_EN.md)
- [philosophers](#philosophers)
	- [Description](#description)
	- [Instructions](#instructions)
	- [Bonus](#bonus)
	- [Utilisation de l’IA](#utilisation-de-lia)
	- [Resources](#resources)

## Description
Un projet axé sur la concurrence basé sur le problème classique des philosophes mangeurs. L’objectif est de simuler plusieurs philosophes partageant des ressources limitées tout en évitant les interblocages (deadlocks), la famine (starvation) et les conditions de course (race conditions). L’implémentation repose sur l’utilisation de threads (ou de processus), de mutex, d’une gestion précise du temps et d’un accès synchronisé aux données partagées. Le projet exige un contrôle rigoureux des contraintes temporelles, une gestion propre du cycle de vie des threads et une journalisation précise des états. Il permet de développer une compréhension approfondie du multithreading, des primitives de synchronisation, des pièges de la programmation concurrente et de la logique sensible aux performances sous des contraintes strictes de temps réel.

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