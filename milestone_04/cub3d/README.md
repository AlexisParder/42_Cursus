*Ce projet a été créé en groupe avec [Altixx](https://github.com/Altixx) dans le cadre du cursus 42.*

# cub3d
![42 Cursus](https://img.shields.io/badge/42-Cursus-blue?style=for-the-badge)
![Projects](https://img.shields.io/badge/Projects-Common_Core-success?style=for-the-badge)
[![Score](https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus/tree/main/cub3d)<br>
[🇬🇧 English](./README_EN.md)
- [cub3d](#cub3d)
	- [Description](#description)
	- [Instructions](#instructions)
		- [Obligatoire](#obligatoire)
		- [Bonus](#bonus)
	- [Bonus](#bonus-1)
	- [Contrôles](#contrôles)
		- [Obligatoire](#obligatoire-1)
		- [Bonus](#bonus-2)
	- [Cartes](#cartes)
	- [Exemple de fichier .cub](#exemple-de-fichier-cub)
	- [Utilisation de l’IA](#utilisation-de-lia)
	- [Resources](#resources)

## Description
Un projet de programmation graphique inspiré des premiers moteurs de raycasting comme Wolfenstein 3D. L’objectif est de construire un moteur de rendu pseudo-3D en utilisant une carte 2D et des techniques de raycasting afin de simuler une vue à la première personne. L’implémentation comprend le parsing de fichiers de carte, la gestion des déplacements du joueur et de la rotation de la caméra, le calcul des rayons en temps réel, ainsi que le rendu de murs texturés avec une profondeur et une perspective correctes.

Les défis supplémentaires incluent la gestion des sprites, la détection des collisions et l’optimisation des performances pour un rendu fluide. Ce projet permet de développer de solides compétences en bases de l’infographie, en trigonométrie, en rendu temps réel, en optimisation bas niveau, ainsi qu’en conception structurée de moteur de jeu dans un environnement C contraint.

## Instructions
### Obligatoire
- Utilisez la commande `make` pour compiler le programme.
- Utilisez la commande `./cub3D <path/map_file>.cub` pour lancer le jeu.
### Bonus
- Utilisez la commande `make bonus` pour compiler le programme avec les bonus.
- Utilisez la commande `./cub3D <path/map_file>.cub` pour lancer le jeu.

## Bonus
- [X] Collisions avec les murs.
- [X] Système de minimap.
- [X] Portes pouvant s’ouvrir et se fermer.
- [X] Sprites animés.
- [X] Rotation de la vue avec la souris.

## Contrôles
### Obligatoire
| Key                   | Action Description           |
|-----------------------|------------------------------|
| **W**                 | Avancer                      |
| **A**                 | Aller à gauche               |
| **S**                 | Reculer                      |
| **D**                 | Aller à droite               |
| **← (Gauche)**        | Tourner la caméra à gauche   |
| **→ (Droite)**        | Tourner la caméra à droite   |
| **ESCAPE**            | Quitter le jeu               |
### Bonus
| Key                   | Action Description              |
|-----------------------|---------------------------------|
| **SOURIS**            | Tourner la caméra               |
| **E**                 | Interagir                       |
| **Q**                 | Afficher/Masquer les FPS        |
| **F**                 | Lampe torche                    |
| **R**                 | Recharger la batterie           |
| **TAB**               | Afficher/Masquer les paramètres |
| **SHIFT**             | Courir	                      |
| **CTRL**              | S’accroupir                     |

## Cartes
La carte doit respecter certaines règles :
- La carte doit être au format .cub.
- La carte peut être composée uniquement de ces 6 caractères :
	- **0** : espace vide
	- **1** : mur
	- **N** : position de départ du joueur, orienté vers le Nord
	- **S** : position de départ du joueur, orienté vers le Sud
	- **E** : position de départ du joueur, orienté vers l’Est
	- **W** : position de départ du joueur, orienté vers l’Ouest
	- Pour les bonus, vous pouvez ajouter :
		- **D** : porte
- Pour être valide, une carte doit contenir 1 position de départ du joueur.
- La carte doit être fermée/entourée par des murs.
  
## Exemple de fichier .cub
```
NO ./textures/wall.png
SO ./textures/wall.jpg
WE ./textures/wall.jpeg
EA ./textures/wall.bmp

F 220,100,0
C 225,30,0

           1111111111111111111111111
           1000000000110000000000001
           1011000001110000000000001
           1001000000000000000000111
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```
- **NO** : texture (format : `png`, `jpg`, `jpeg` ou `bmp`) appliquée à la face nord des cubes.
- **SO** : texture (format : `png`, `jpg`, `jpeg` ou `bmp`) appliquée à la face sud des cubes.
- **WE** : texture (format : `png`, `jpg`, `jpeg` ou `bmp`) appliquée à la face ouest des cubes.
- **EA** : texture (format : `png`, `jpg`, `jpeg` ou `bmp`) appliquée à la face est des cubes.
- **F** : couleur du sol (format : `r`,`g`,`b`).
- **C** : couleur du plafond (format : `r`,`g`,`b`).
- **BONUS**
	- **DO** : texture (format : `png`, `jpg`, `jpeg` ou `bmp`) appliquée aux portes ouvertes.
	- **DC** : texture (format : `png`, `jpg`, `jpeg` ou `bmp`) appliquée aux portes fermées.
	- **I** : couleur du texte d’interaction (format : `r`,`g`,`b`). Ce paramètre est optionnel, si non spécifié, la couleur par défaut est blanche.
- **Note** : les paramètres ci-dessus peuvent être spécifiés dans n’importe quel ordre. Cependant, la carte doit toujours être placée en dernier.

## Utilisation de l’IA
L’intelligence artificielle a été utilisée comme support pour comprendre et regrouper les notions clés du projet.

## Resources
- [Bibliothèque C maths (math.h)](https://www.w3schools.com/c/c_ref_math.php)
- [MacroLibX](https://macrolibx.kbz8.me/guides/getting_started/)
- [Notions mathématiques du projet Cub3D](https://docs.google.com/document/d/1tdNYHg3Mfqf8dr8W6Ajs3seUugwtmaQizZ7BzimkXog/edit)