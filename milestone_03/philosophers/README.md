*Ce projet a été créé dans le cadre du cursus 42 par achauvie.*

# philosophers
![42 Cursus](https://img.shields.io/badge/42-Cursus-blue?style=for-the-badge)
![Projects](https://img.shields.io/badge/Projects-Common_Core-success?style=for-the-badge)
[![Score](https://img.shields.io/badge/score-100%20%2F%20100-success?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus/tree/main/philosophers)<br>
[🇬🇧 English](./README_EN.md)
- [philosophers](#philosophers)
	- [Description](#description)
	- [Instructions](#instructions)
		- [Obligatoire](#obligatoire)
	- [Utilisation de l’IA](#utilisation-de-lia)
	- [Resources](#resources)

## Description
Un projet axé sur la concurrence basé sur le problème classique des philosophes mangeurs. L’objectif est de simuler plusieurs philosophes partageant des ressources limitées tout en évitant les interblocages (deadlocks), la famine (starvation) et les conditions de course (race conditions). L’implémentation repose sur l’utilisation de threads (ou de processus), de mutex, d’une gestion précise du temps et d’un accès synchronisé aux données partagées. Le projet exige un contrôle rigoureux des contraintes temporelles, une gestion propre du cycle de vie des threads et une journalisation précise des états. Il permet de développer une compréhension approfondie du multithreading, des primitives de synchronisation, des pièges de la programmation concurrente et de la logique sensible aux performances sous des contraintes strictes de temps réel.

## Instructions
### Obligatoire
- Allez dans le dossier `philo` pour compiler le programme de base
- Utilisez la commande `make` pour compiler le programme.
- Utilisez la commande `./philo <nombre_de_philosophes> <temps_pour_mourir> <temps_pour_manger> <temps_pour_dormir> <nombre_de_repas_par_philosophe>` pour lancer le programme.
	- Les temps sont en milliseconde (ms).
	- le dernier parametre est optionnel.

## Utilisation de l’IA
L’intelligence artificielle a été utilisée comme support pour comprendre et regrouper les notions clés du projet, notamment en créant une liste d’exercices afin d’apprendre à utiliser les threads et les mutex.
- [Voir les exercices](https://github.com/AlexisParder/42_Cursus/tree/main/philosophers/thread_exercices)

## Resources
- [Tester 1](https://github.com/dantonik/42-philosophers-tester)
- [Tester 2](https://github.com/Acholias/Philosophers_tester)
- [Langage C #17 (les threads)](https://youtu.be/o_GbRujGCnM?list=PLdDeXINE1ViRkmBtqLmC_fu-tIJUl4-Sd)