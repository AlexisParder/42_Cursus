*Ce projet a été créé dans le cadre du cursus 42 par achauvie.*

# push_swap
[🇬🇧 English](./README_EN.md)
- [push\_swap](#push_swap)
	- [Description](#description)
	- [Opérations autorisées](#opérations-autorisées)
	- [Instructions](#instructions)
	- [Ressources](#ressources)

## Description
Un projet fortement algorithmique dont l’objectif est de trier une liste d’entiers en utilisant deux piles et un ensemble restreint d’opérations.
Le défi consiste à concevoir et implémenter une stratégie de tri optimisée produisant le moins d’instructions possible, en particulier pour de grands ensembles de données (100 à 500 éléments).
Les approches courantes incluent le tri de petits ensembles, les stratégies par chunks et le radix sort.
Ce projet développe la réflexion algorithmique, l’optimisation du temps et du nombre d’opérations, la manipulation de structures de données et l’implémentation d’une logique complexe sous de fortes contraintes.

## Opérations autorisées
La liste ci-dessous présente toutes les opérations autorisées pour trier les nombres dans le projet `push_swap`.
Vous devez utiliser uniquement ces opérations pour manipuler les piles et obtenir une liste triée.
- **sa (swap a)**
	- Échange les 2 premiers éléments au sommet de la pile a.
	- Ne fait rien s’il n’y a qu’un seul élément ou aucun.
- **sb (swap b)**
	- Échange les 2 premiers éléments au sommet de la pile b.
	- Ne fait rien s’il n’y a qu’un seul élément ou aucun.
- **ss**
	- Exécute sa et sb en même temps.
- **pa (push a)**
	- Prend le premier élément au sommet de b et le place au sommet de a.
	- Ne fait rien si b est vide.
- **pb (push b)**
	- Prend le premier élément au sommet de a et le place au sommet de b.
	- Ne fait rien si a est vide.
- **ra (rotate a)**
	- Décale vers le haut tous les éléments de la pile a de 1.
	- Le premier élément devient le dernier.
- **rb (rotate b)**
	- Décale vers le haut tous les éléments de la pile b de 1.
	- Le premier élément devient le dernier.
- **rr**
	- Exécute ra et rb en même temps.
- **rra (reverse rotate a)**
	- Décale vers le bas tous les éléments de la pile a de 1.
	- Le dernier élément devient le premier.
- **rrb (reverse rotate b)**
	- Décale vers le bas tous les éléments de la pile b de 1.
	- Le dernier élément devient le premier.
- **rrr**
	- Exécute rra et rrb en même temps.

## Instructions
- Utilisez la commande `make` pour générer le programme.
- Utilisez la commande `./push_swap <liste de nombres non triés> `pour trier la liste.
	- ⚠️ Le programme ne retourne pas la liste triée. Il affiche uniquement les instructions utilisées pour effectuer le tri.
	- La commande `./push_swap <liste de nombres non triés> | wc -l` permet d’afficher le nombre d’instructions utilisées pour trier la liste.

## Ressources
- [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [libft](https://github.com/AlexisParder/42_Cursus/tree/main/libft)