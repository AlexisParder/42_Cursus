*Ce projet a été créé dans le cadre du cursus 42 par achauvie.*

# philosophers
![42 Cursus](https://img.shields.io/badge/42-Cursus-blue?style=for-the-badge)
![Projects](https://img.shields.io/badge/Projects-Common_Core-success?style=for-the-badge)
<!-- [![Score](https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus/tree/main/philosophers)<br> -->
[🇬🇧 English](./README_EN.md)
- [philosophers](#philosophers)
	- [Description](#description)
	- [Instructions](#instructions)
		- [Obligatoire](#obligatoire)
		- [Bonus](#bonus)
	- [Bonus](#bonus-1)
	- [Utilisation de l’IA](#utilisation-de-lia)
	- [Resources](#resources)

## Description
Un projet axé sur la concurrence basé sur le problème classique des philosophes mangeurs. L’objectif est de simuler plusieurs philosophes partageant des ressources limitées tout en évitant les interblocages (deadlocks), la famine (starvation) et les conditions de course (race conditions). L’implémentation repose sur l’utilisation de threads (ou de processus), de mutex, d’une gestion précise du temps et d’un accès synchronisé aux données partagées. Le projet exige un contrôle rigoureux des contraintes temporelles, une gestion propre du cycle de vie des threads et une journalisation précise des états. Il permet de développer une compréhension approfondie du multithreading, des primitives de synchronisation, des pièges de la programmation concurrente et de la logique sensible aux performances sous des contraintes strictes de temps réel.

## Instructions
### Obligatoire
- Allez dans le dossier `philo` pour compiler le programme de base
- Utilisez la commande `make` pour compiler le programme.
<!-- - Utilisez la commande `./philo ...` pour lancer le programme. -->
### Bonus
- Allez dans le dossier `philo_bonus` pour compiler le programme avec les bonus
- Utilisez la commande `make bonus` pour compiler le programme avec les bonus.

## Bonus
- [ ] Toutes les fourchettes sont placées au milieu de la table.
- [ ] Elles n’ont pas d’état en mémoire, mais le nombre de fourchettes disponibles est représenté par un sémaphore.
- [ ] Chaque philosophe doit être représenté par un processus distinct. Cependant, le processus principal ne doit pas agir comme un philosophe.

## Utilisation de l’IA
<!-- L’intelligence artificielle a été utilisée comme support pour comprendre et regrouper les notions clés du projet, notamment les concepts de forks, pipes et autres mécanismes systèmes. -->

## Resources
<!-- - [Les processus Unix en C](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
- [Pipes, Forks & Dups par Roslyn McConnell](https://www.rozmichelle.com/pipes-forks-dups/) -->