# Milestone 3
![Repo size](https://img.shields.io/github/repo-size/AlexisParder/42_Cursus?style=for-the-badge&logo=github)
![Languages count](https://img.shields.io/github/languages/count/AlexisParder/42_Cursus?style=for-the-badge)
![Top language](https://img.shields.io/github/languages/top/AlexisParder/42_Cursus?style=for-the-badge)
![Last commit](https://img.shields.io/github/last-commit/AlexisParder/42_Cursus?style=for-the-badge)<br>
[🇬🇧 English](./README_EN.md)<br>
- [Milestone 3](#milestone-3)
	- [philosophers](#philosophers)
	- [minishell](#minishell)

## philosophers
Un projet axé sur la concurrence basé sur le problème classique des philosophes mangeurs. L’objectif est de simuler plusieurs philosophes partageant des ressources limitées tout en évitant les interblocages (deadlocks), la famine (starvation) et les conditions de course (race conditions). L’implémentation repose sur l’utilisation de threads (ou de processus), de mutex, d’une gestion précise du temps et d’un accès synchronisé aux données partagées. Le projet exige un contrôle rigoureux des contraintes temporelles, une gestion propre du cycle de vie des threads et une journalisation précise des états. Il permet de développer une compréhension approfondie du multithreading, des primitives de synchronisation, des pièges de la programmation concurrente et de la logique sensible aux performances sous des contraintes strictes de temps réel.

[Voir philosophers](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_03/philosophers)

## minishell
Un projet complet de programmation système consistant à recréer un shell Unix simplifié à partir de zéro. Le programme doit analyser et exécuter les commandes utilisateur, gérer les variables d’environnement, prendre en charge les commandes intégrées (built-ins), supporter les pipes et les redirections, et propager correctement les codes de sortie. La difficulté réside dans la tokenisation précise de l’entrée, la gestion de la création des processus, le traitement des signaux (Ctrl-C, Ctrl-D, Ctrl-\\), ainsi que la reproduction d’un comportement proche de Bash dans des limites définies. Ce projet permet de développer une solide expertise en contrôle des processus, en logique de parsing, en gestion des descripteurs de fichiers, en gestion des signaux et en récupération d’erreurs robuste dans un environnement C bas niveau.

[Voir minishell](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_03/minishell)