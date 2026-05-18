# 42 Cursus
[![Repo size](https://img.shields.io/github/repo-size/AlexisParder/42_Cursus?style=for-the-badge&logo=github)](https://github.com/AlexisParder/42_Cursus)
[![Languages count](https://img.shields.io/github/languages/count/AlexisParder/42_Cursus?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus)
[![Top language](https://img.shields.io/github/languages/top/AlexisParder/42_Cursus?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus)
[![Last commit](https://img.shields.io/github/last-commit/AlexisParder/42_Cursus?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus)<br>
[🇬🇧 English](./README_EN.md)<br>
- [42 Cursus](#42-cursus)
	- [Milestone 0](#milestone-0)
		- [libft](#libft)
	- [Milestone 1](#milestone-1)
		- [ft\_print](#ft_print)
		- [get\_next\_line](#get_next_line)
		- [born2beroot](#born2beroot)
	- [Milestone 2](#milestone-2)
		- [push\_swap](#push_swap)
		- [so\_long](#so_long)
		- [pipex](#pipex)
	- [Milestone 3](#milestone-3)
		- [philosophers](#philosophers)
		- [minishell](#minishell)
	- [Milestone 4](#milestone-4)
		- [cub3d](#cub3d)
		- [NetPractice](#netpractice)
		- [CPP module 00](#cpp-module-00)
		- [CPP module 01](#cpp-module-01)
		- [CPP module 02](#cpp-module-02)
		- [CPP module 03](#cpp-module-03)
		- [CPP module 04](#cpp-module-04)


## Milestone 0
### libft
Un projet fondamental du cursus 42.
Libft consiste à recréer une version personnalisée de la bibliothèque standard C en implémentant un large ensemble de fonctions essentielles pour la manipulation de la mémoire, la gestion des chaînes de caractères, les vérifications de caractères et les opérations sur les listes chaînées.
Cette bibliothèque devient une dépendance centrale pour tous les projets suivants (get_next_line, ft_printf, push_swap, minishell, etc.) et pose des bases solides en programmation bas niveau, gestion de la mémoire et structure de code propre.

[Voir libft](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_00/libft)

## Milestone 1
### ft_print
Une réimplémentation complète de la célèbre fonction printf en C.
Le projet a pour objectif de gérer l’affichage formaté en analysant les chaînes de format et en prenant en charge les arguments variables à l’aide de stdarg.h.
Il couvre toutes les conversions obligatoires (c, s, p, d, i, u, x, X, %) et met l’accent sur la construction d’un moteur de formatage modulaire, bien structuré et efficace.
Ce projet renforce les compétences en logique de parsing, conversions de bases, gestion de buffers et architecture de fonctions.

[Voir ft_printf](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_01/ft_printf)

### get_next_line
Un projet axé sur la création d’une fonction capable de lire n’importe quel fichier, flux d’entrée ou l’entrée standard (stdin) ligne par ligne.
L’implémentation doit gérer des buffers internes, conserver les données non lues entre les appels, prendre en charge des valeurs arbitraires de BUFFER_SIZE et garantir une sécurité mémoire totale.
Le bonus optionnel ajoute la gestion de plusieurs descripteurs de fichiers simultanément.
Ce projet renforce les connaissances sur les descripteurs de fichiers, la mémoire dynamique, les variables statiques, la logique de buffer et la gestion robuste des cas limites.

[Voir get_next_line](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_01/get_next_line)

### born2beroot
Un projet d’administration système centré sur l’installation et la configuration complète d’une machine virtuelle Linux sécurisée à partir de zéro. L’objectif est de mettre en place des règles strictes de sécurité et de conformité, incluant la gestion des utilisateurs et des groupes, des politiques minimales de mots de passe, une configuration SSH renforcée et une configuration personnalisée du pare-feu.
Le projet exige également la surveillance des ressources système à l’aide d’un script personnalisé et la documentation complète de l’installation selon des consignes rigoureuses. Ce projet permet de renforcer la compréhension des bases de Linux, de la gestion des privilèges, du durcissement de la sécurité, de la virtualisation et de la configuration système reproductible.

[Voir born2beroot](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_01/born2beroot)

## Milestone 2
### push_swap
Un projet fortement algorithmique dont l’objectif est de trier une liste d’entiers en utilisant deux piles et un ensemble restreint d’opérations.
Le défi consiste à concevoir et implémenter une stratégie de tri optimisée produisant le moins d’instructions possible, en particulier pour de grands ensembles de données (100 à 500 éléments).
Les approches courantes incluent le tri de petits ensembles, les stratégies par chunks et le radix sort.
Ce projet développe la réflexion algorithmique, l’optimisation du temps et du nombre d’opérations, la manipulation de structures de données et l’implémentation d’une logique complexe sous de fortes contraintes.

[Voir push_swap](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_02/push_swap)

### so_long
Un projet graphique axé sur la création d’un petit jeu 2D en utilisant la bibliothèque MiniLibX. L’objectif est d’implémenter l’analyse de la carte, la logique de collision, le rendu des sprites et la gestion des événements, tout en respectant un ensemble strict de règles concernant la validité de la carte, les contraintes de déplacement et la gestion des ressources graphiques. La difficulté augmente avec la nécessité de créer des interactions fluides avec le joueur, de gérer les cycles d’animation et d’assurer un nettoyage correct des ressources. Ce projet permet de développer des compétences en graphismes bas niveau, programmation événementielle, gestion des entrées utilisateur, analyse de fichiers et gestion de la mémoire/des ressources dans un environnement C contraint.

[Voir so_long](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_02/so_long)

### pipex
Un projet visant à reproduire le comportement des pipelines Unix en redirigeant les flux d’entrée et de sortie entre plusieurs commandes. Le programme doit créer correctement des processus avec fork, mettre en place des pipes, gérer les descripteurs de fichiers et exécuter les commandes via la résolution du PATH, tout en garantissant une gestion stricte des erreurs et une sécurité mémoire totale.
Le bonus consiste à gérer plusieurs pipes ainsi que la fonctionnalité heredoc.
Ce projet renforce la maîtrise des processus, des appels système, de la redirection des entrées/sorties, des variables d’environnement et de la communication inter-processus, tout en apprenant à orchestrer des flux de données complexes au niveau système.

[Voir pipex](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_02/pipex)

## Milestone 3
### philosophers
Un projet axé sur la concurrence basé sur le problème classique des philosophes mangeurs. L’objectif est de simuler plusieurs philosophes partageant des ressources limitées tout en évitant les interblocages (deadlocks), la famine (starvation) et les conditions de course (race conditions). L’implémentation repose sur l’utilisation de threads (ou de processus), de mutex, d’une gestion précise du temps et d’un accès synchronisé aux données partagées. Le projet exige un contrôle rigoureux des contraintes temporelles, une gestion propre du cycle de vie des threads et une journalisation précise des états. Il permet de développer une compréhension approfondie du multithreading, des primitives de synchronisation, des pièges de la programmation concurrente et de la logique sensible aux performances sous des contraintes strictes de temps réel.

[Voir philosophers](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_03/philosophers)

### minishell
Un projet complet de programmation système consistant à recréer un shell Unix simplifié à partir de zéro. Le programme doit analyser et exécuter les commandes utilisateur, gérer les variables d’environnement, prendre en charge les commandes intégrées (built-ins), supporter les pipes et les redirections, et propager correctement les codes de sortie. La difficulté réside dans la tokenisation précise de l’entrée, la gestion de la création des processus, le traitement des signaux (Ctrl-C, Ctrl-D, Ctrl-\\), ainsi que la reproduction d’un comportement proche de Bash dans des limites définies. Ce projet permet de développer une solide expertise en contrôle des processus, en logique de parsing, en gestion des descripteurs de fichiers, en gestion des signaux et en récupération d’erreurs robuste dans un environnement C bas niveau.

[Voir minishell](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_03/minishell)

## Milestone 4
### cub3d
Un projet de programmation graphique inspiré des premiers moteurs de raycasting comme Wolfenstein 3D. L’objectif est de construire un moteur de rendu pseudo-3D en utilisant une carte 2D et des techniques de raycasting afin de simuler une vue à la première personne. L’implémentation comprend le parsing de fichiers de carte, la gestion des déplacements du joueur et de la rotation de la caméra, le calcul des rayons en temps réel, ainsi que le rendu de murs texturés avec une profondeur et une perspective correctes.

Les défis supplémentaires incluent la gestion des sprites, la détection des collisions et l’optimisation des performances pour un rendu fluide. Ce projet permet de développer de solides compétences en bases de l’infographie, en trigonométrie, en rendu temps réel, en optimisation bas niveau, ainsi qu’en conception structurée de moteur de jeu dans un environnement C contraint.

[Voir cub3d](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_04/cub3d)

### NetPractice
Un projet axé sur les réseaux conçu pour développer une compréhension pratique de l’adressage TCP/IP et de la configuration réseau. À travers une série d’exercices de difficulté progressive, l’objectif est de configurer correctement de petites infrastructures réseau en manipulant les adresses IP, les masques de sous-réseau, le routage et les règles de connectivité. Le projet met l’accent sur la résolution de problèmes logiques liés aux réseaux, la compréhension de la communication entre appareils à travers différents sous-réseaux, ainsi que l’application des concepts fondamentaux du réseau sans recourir à des outils automatisés. Ce projet renforce les connaissances en réseaux informatiques, en schémas d’adressage, en logique de routage, en subnetting et en bases de l’architecture réseau bas niveau.

[Voir netpractice](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_04/net_practice)

### CPP module 00
An introductory object-oriented programming project designed to transition from procedural C programming to modern C++. The module focuses on the fundamentals of classes, member functions, namespaces, streams, initialization, and basic encapsulation. Through small practical exercises, the project introduces core C++ syntax and programming paradigms while emphasizing clean code structure and compilation discipline. This module builds foundational knowledge of object-oriented design and the differences between C and C++ development.

[Go to CPP 00](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_04/cpp_0-4/CPP00)

### CPP module 01
A project centered around memory allocation, references, pointers, and object lifecycle management in C++. The exercises explore stack versus heap allocation, references versus pointers, switch statements, and the use of class methods in more realistic scenarios. Particular attention is given to constructors, destructors, and memory safety. This module reinforces understanding of resource management and fundamental object-oriented programming practices in C++.

[Go to CPP 01](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_04/cpp_0-4/CPP01)

### CPP module 02
A project focused on operator overloading, fixed-point arithmetic, and canonical class form. The goal is to implement classes with proper copy semantics while reproducing behavior similar to native C++ types through overloaded operators. The exercises introduce concepts such as ad-hoc polymorphism, Orthodox Canonical Form, and precise value manipulation. This module develops a deeper understanding of class behavior, abstraction, and operator customization in C++.

[Go to CPP 02](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_04/cpp_0-4/CPP02)

### CPP module 03
A project dedicated to inheritance and object-oriented hierarchy design. The exercises revolve around creating base and derived classes, managing constructor/destructor chains, and implementing shared behavior through inheritance. The module also introduces method overriding and explores the relationship between composition and inheritance. This project strengthens understanding of class hierarchies, code reuse, and structured object-oriented architecture in C++.

[Go to CPP 03](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_04/cpp_0-4/CPP03)

### CPP module 04
A polymorphism-oriented project focused on abstract classes, interfaces, and dynamic binding. The objective is to design extensible class hierarchies using virtual functions and abstract base classes while ensuring proper memory management through deep copies and virtual destructors. The module also introduces runtime polymorphism and interface-based design patterns. This project develops advanced object-oriented programming skills and a strong understanding of abstraction, extensibility, and dynamic behavior in C++.

[Go to CPP 04](https://github.com/AlexisParder/42_Cursus/tree/main/milestone_04/cpp_0-4/CPP04)