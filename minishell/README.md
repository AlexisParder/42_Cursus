*Ce projet a été créé dans le cadre du cursus 42 par achauvie et tjourdai.*

# minishell
![42 Cursus](https://img.shields.io/badge/42-Cursus-blue?style=for-the-badge)
![Projects](https://img.shields.io/badge/Projects-Common_Core-success?style=for-the-badge)
<!-- [![Score](https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus/tree/main/minishell)<br> -->
[🇬🇧 English](./README_EN.md)
- [minishell](#minishell)
	- [Description](#description)
	- [Instructions](#instructions)
	- [Feuille de route](#feuille-de-route)
	- [Utilisation de l’IA](#utilisation-de-lia)
	- [Resources](#resources)

## Description
Un projet complet de programmation système consistant à recréer un shell Unix simplifié à partir de zéro. Le programme doit analyser et exécuter les commandes utilisateur, gérer les variables d’environnement, prendre en charge les commandes intégrées (built-ins), supporter les pipes et les redirections, et propager correctement les codes de sortie. La difficulté réside dans la tokenisation précise de l’entrée, la gestion de la création des processus, le traitement des signaux (Ctrl-C, Ctrl-D, Ctrl-\\), ainsi que la reproduction d’un comportement proche de Bash dans des limites définies. Ce projet permet de développer une solide expertise en contrôle des processus, en logique de parsing, en gestion des descripteurs de fichiers, en gestion des signaux et en récupération d’erreurs robuste dans un environnement C bas niveau.

## Instructions
<!-- - Utilisez la commande `make` pour compiler le programme.
	- Utilisez la commande `make bonus` pour compiler le programme avec les bonus.
- Utilisez la commande `./pipex file1 cmd1 cmd2 file2` pour lancer le programme.
	- **file1** et **file2** sont des noms de fichiers.
	- **cmd1** et **cmd2** sont des commandes shell avec leurs paramètres.
	- Exemple : `./pipex infile "ls -l" "wc -l" outfile`
    	- L'equivalent en **bash** serait `< infile ls -l | wc -l > outfile` -->

## Feuille de route
- [ ] Afficher une invite lorsqu’on attend une nouvelle commande.
- [ ] Avoir un historique fonctionnel.
- [ ] Rechercher et lancer le bon exécutable (en se basant sur la variable PATH ou en utilisant
un chemin relatif ou absolu).
- [ ] Utiliser au maximum une variable globale pour indiquer la réception d’un signal. Considérer
les implications : cette approche garantit que le gestionnaire de signaux n’accède pas aux
structures de données principales.
- [ ] Ne pas interpréter les guillemets non fermés ou les caractères spéciaux qui ne sont pas requis
par le sujet, tels que `\` (antislash) ou `;` (point-virgule).
- [ ] Gérer le caractère `’` (apostrophe simple), qui doit empêcher le shell d’interpréter les
méta-caractères dans la séquence entre guillemets.
- [ ] Gérer le caractère `"` (guillemet double), qui doit empêcher le shell d’interpréter les
méta-caractères dans la séquence entre guillemets, à l’exception de `$`(signe dollar).
- [ ] Implémenter les redirections suivantes :
	- `<` doit rediriger l’entrée standard.
	- `>` doit rediriger la sortie standard.
	- `<<` doit recevoir un délimiteur, puis lire l’entrée jusqu’à ce qu’une ligne contenant le
	- `délimiteur` soit rencontrée. Cependant, cela n’a pas besoin de mettre à jour l’historique.
	- `>>` doit rediriger la sortie en mode ajout (append).
- [ ] Implémenter les pipes (caractère `|`). La sortie de chaque commande dans le pipeline est
connectée à l’entrée de la commande suivante via un pipe.
- [ ] Gérer les variables d’environnement (`$` suivi d’une séquence de caractères), qui doivent
être développées en leurs valeurs.
- [ ] Gérer `$?`, qui doit être développé en le code de retour de la dernière pipeline exécutée
au premier plan.
- [ ] Gérer `ctrl-C`, `ctrl-D` et `ctrl-\`, qui doivent se comporter comme dans bash.
- [ ] En mode interactif :
	- `ctrl-C` affiche une nouvelle invite sur une nouvelle ligne.
	- `ctrl-D` quitte le shell.
	- `ctrl-\` ne fait rien.
- [ ] Le shell doit implémenter les commandes internes suivantes :
	- echo avec l’option `-n`
	- cd avec uniquement un chemin relatif ou absolu
	- pwd sans options
	- export sans options
	- unset sans options
	- env sans options ni arguments
	- exit sans options

## Utilisation de l’IA
<!-- L’intelligence artificielle a été utilisée comme support pour comprendre et regrouper les notions clés du projet, notamment les concepts de forks, pipes et autres mécanismes systèmes. -->

## Resources
<!-- - [Les processus Unix en C](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
- [Pipes, Forks & Dups par Roslyn McConnell](https://www.rozmichelle.com/pipes-forks-dups/) -->
- [libft](https://github.com/AlexisParder/42_Cursus/tree/main/libft)