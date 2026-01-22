# 42 Cursus
[![Repo size](https://img.shields.io/github/repo-size/AlexisParder/42_Cursus?style=for-the-badge&logo=github)](https://github.com/AlexisParder/42_Cursus)
[![Languages count](https://img.shields.io/github/languages/count/AlexisParder/42_Cursus?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus)
[![Top language](https://img.shields.io/github/languages/top/AlexisParder/42_Cursus?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus)
[![Last commit](https://img.shields.io/github/last-commit/AlexisParder/42_Cursus?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus)<br>
[![achauvie's 42 stats](https://badge.mediaplus.ma/darkblue/achauvie?1337Badge=off&UM6P=off)](https://github.com/AlexisParder)<br>
[🇬🇧 English](./README_EN.md)<br>
- [42 Cursus](#42-cursus)
	- [libf](#libf)
	- [ft\_print](#ft_print)
	- [get\_next\_line](#get_next_line)
	- [born2beroot](#born2beroot)
	- [push\_swap](#push_swap)
	- [so\_long](#so_long)
	- [pipex](#pipex)
	- [philosophers](#philosophers)
	- [minishell](#minishell)

## libf
Un projet fondamental du cursus 42.
Libft consiste à recréer une version personnalisée de la bibliothèque standard C en implémentant un large ensemble de fonctions essentielles pour la manipulation de la mémoire, la gestion des chaînes de caractères, les vérifications de caractères et les opérations sur les listes chaînées.
Cette bibliothèque devient une dépendance centrale pour tous les projets suivants (get_next_line, ft_printf, push_swap, minishell, etc.) et pose des bases solides en programmation bas niveau, gestion de la mémoire et structure de code propre.

[Voir libft](https://github.com/AlexisParder/42_Cursus/tree/main/libft)

## ft_print
Une réimplémentation complète de la célèbre fonction printf en C.
Le projet a pour objectif de gérer l’affichage formaté en analysant les chaînes de format et en prenant en charge les arguments variables à l’aide de stdarg.h.
Il couvre toutes les conversions obligatoires (c, s, p, d, i, u, x, X, %) et met l’accent sur la construction d’un moteur de formatage modulaire, bien structuré et efficace.
Ce projet renforce les compétences en logique de parsing, conversions de bases, gestion de buffers et architecture de fonctions.

[Voir ft_printf](https://github.com/AlexisParder/42_Cursus/tree/main/ft_printf)

## get_next_line
Un projet axé sur la création d’une fonction capable de lire n’importe quel fichier, flux d’entrée ou l’entrée standard (stdin) ligne par ligne.
L’implémentation doit gérer des buffers internes, conserver les données non lues entre les appels, prendre en charge des valeurs arbitraires de BUFFER_SIZE et garantir une sécurité mémoire totale.
Le bonus optionnel ajoute la gestion de plusieurs descripteurs de fichiers simultanément.
Ce projet renforce les connaissances sur les descripteurs de fichiers, la mémoire dynamique, les variables statiques, la logique de buffer et la gestion robuste des cas limites.

[Voir get_next_line](https://github.com/AlexisParder/42_Cursus/tree/main/get_next_line)

## born2beroot
Un projet d’administration système centré sur l’installation et la configuration complète d’une machine virtuelle Linux sécurisée à partir de zéro. L’objectif est de mettre en place des règles strictes de sécurité et de conformité, incluant la gestion des utilisateurs et des groupes, des politiques minimales de mots de passe, une configuration SSH renforcée et une configuration personnalisée du pare-feu.
Le projet exige également la surveillance des ressources système à l’aide d’un script personnalisé et la documentation complète de l’installation selon des consignes rigoureuses. Ce projet permet de renforcer la compréhension des bases de Linux, de la gestion des privilèges, du durcissement de la sécurité, de la virtualisation et de la configuration système reproductible.

[Voir born2beroot](https://github.com/AlexisParder/42_Cursus/tree/main/born2beroot)

## push_swap
Un projet fortement algorithmique dont l’objectif est de trier une liste d’entiers en utilisant deux piles et un ensemble restreint d’opérations.
Le défi consiste à concevoir et implémenter une stratégie de tri optimisée produisant le moins d’instructions possible, en particulier pour de grands ensembles de données (100 à 500 éléments).
Les approches courantes incluent le tri de petits ensembles, les stratégies par chunks et le radix sort.
Ce projet développe la réflexion algorithmique, l’optimisation du temps et du nombre d’opérations, la manipulation de structures de données et l’implémentation d’une logique complexe sous de fortes contraintes.

[Voir push_swap](https://github.com/AlexisParder/42_Cursus/tree/main/push_swap)

## so_long
Un projet graphique axé sur la création d’un petit jeu 2D en utilisant la bibliothèque MiniLibX. L’objectif est d’implémenter l’analyse de la carte, la logique de collision, le rendu des sprites et la gestion des événements, tout en respectant un ensemble strict de règles concernant la validité de la carte, les contraintes de déplacement et la gestion des ressources graphiques. La difficulté augmente avec la nécessité de créer des interactions fluides avec le joueur, de gérer les cycles d’animation et d’assurer un nettoyage correct des ressources. Ce projet permet de développer des compétences en graphismes bas niveau, programmation événementielle, gestion des entrées utilisateur, analyse de fichiers et gestion de la mémoire/des ressources dans un environnement C contraint.

[Voir so_long](https://github.com/AlexisParder/42_Cursus/tree/main/so_long)

## pipex
Un projet visant à reproduire le comportement des pipelines Unix en redirigeant les flux d’entrée et de sortie entre plusieurs commandes. Le programme doit créer correctement des processus avec fork, mettre en place des pipes, gérer les descripteurs de fichiers et exécuter les commandes via la résolution du PATH, tout en garantissant une gestion stricte des erreurs et une sécurité mémoire totale.
Le bonus consiste à gérer plusieurs pipes ainsi que la fonctionnalité heredoc.
Ce projet renforce la maîtrise des processus, des appels système, de la redirection des entrées/sorties, des variables d’environnement et de la communication inter-processus, tout en apprenant à orchestrer des flux de données complexes au niveau système.

[Voir pipex](https://github.com/AlexisParder/42_Cursus/tree/main/pipex)

## philosophers
Un projet axé sur la concurrence basé sur le problème classique des philosophes mangeurs. L’objectif est de simuler plusieurs philosophes partageant des ressources limitées tout en évitant les interblocages (deadlocks), la famine (starvation) et les conditions de course (race conditions). L’implémentation repose sur l’utilisation de threads (ou de processus), de mutex, d’une gestion précise du temps et d’un accès synchronisé aux données partagées. Le projet exige un contrôle rigoureux des contraintes temporelles, une gestion propre du cycle de vie des threads et une journalisation précise des états. Il permet de développer une compréhension approfondie du multithreading, des primitives de synchronisation, des pièges de la programmation concurrente et de la logique sensible aux performances sous des contraintes strictes de temps réel.

[Voir philosophers](https://github.com/AlexisParder/42_Cursus/tree/main/philosophers)

## minishell
Un projet complet de programmation système consistant à recréer un shell Unix simplifié à partir de zéro. Le programme doit analyser et exécuter les commandes utilisateur, gérer les variables d’environnement, prendre en charge les commandes intégrées (built-ins), supporter les pipes et les redirections, et propager correctement les codes de sortie. La difficulté réside dans la tokenisation précise de l’entrée, la gestion de la création des processus, le traitement des signaux (Ctrl-C, Ctrl-D, Ctrl-\\), ainsi que la reproduction d’un comportement proche de Bash dans des limites définies. Ce projet permet de développer une solide expertise en contrôle des processus, en logique de parsing, en gestion des descripteurs de fichiers, en gestion des signaux et en récupération d’erreurs robuste dans un environnement C bas niveau.

[Voir minishell](https://github.com/AlexisParder/42_Cursus/tree/main/minishell)