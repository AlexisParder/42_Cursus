- [📘 PARTIE 1 : Maîtriser les Threads](#-partie-1--maîtriser-les-threads)
  - [Exercice 1.1 : Mon premier thread](#exercice-11--mon-premier-thread)
    - [Objectif : Créer et attendre un thread simple](#objectif--créer-et-attendre-un-thread-simple)
      - [Consignes](#consignes)
      - [Contraintes](#contraintes)
      - [Resultats](#resultats)
  - [Exercice 1.2 : Plusieurs threads](#exercice-12--plusieurs-threads)
    - [Objectif : Gérer plusieurs threads avec des IDs](#objectif--gérer-plusieurs-threads-avec-des-ids)
      - [Consigne](#consigne)
      - [Contraintes](#contraintes-1)
      - [Piège à éviter](#piège-à-éviter)
  - [Exercice 1.3 : Thread avec retour de valeur](#exercice-13--thread-avec-retour-de-valeur)
    - [Objectif : Récupérer un résultat depuis un thread](#objectif--récupérer-un-résultat-depuis-un-thread)
      - [Consigne :](#consigne-)
      - [Contraintes :](#contraintes-)
      - [À comprendre :](#à-comprendre-)
  - [Exercice 1.4 : pthread\_detach](#exercice-14--pthread_detach)
    - [Objectif : Comprendre la différence entre join et detach](#objectif--comprendre-la-différence-entre-join-et-detach)
      - [Consigne :](#consigne--1)
      - [Contraintes :](#contraintes--1)
      - [Fonctions nécessaires :](#fonctions-nécessaires-)
      - [À comprendre :](#à-comprendre--1)
  - [Exercice 1.5 : Mesurer le temps](#exercice-15--mesurer-le-temps)
    - [Objectif : Maîtriser gettimeofday](#objectif--maîtriser-gettimeofday)
      - [Consigne :](#consigne--2)
      - [Contraintes :](#contraintes--2)
      - [Fonctions nécessaires :](#fonctions-nécessaires--1)
      - [À comprendre :](#à-comprendre--2)
- [📗 PARTIE 2 : Threads + Mutex](#-partie-2--threads--mutex)
  - [Exercice 2.1 : Le problème sans mutex](#exercice-21--le-problème-sans-mutex)
    - [Objectif : Visualiser une race condition](#objectif--visualiser-une-race-condition)
      - [Consigne :](#consigne--3)
      - [Contraintes :](#contraintes--3)
      - [Fonctions nécessaires :](#fonctions-nécessaires--2)
      - [À comprendre :](#à-comprendre--3)
  - [Exercice 2.2 : Résoudre avec un mutex](#exercice-22--résoudre-avec-un-mutex)
    - [Objectif : Protéger une ressource partagée](#objectif--protéger-une-ressource-partagée)
      - [Consigne :](#consigne--4)
      - [Contraintes :](#contraintes--4)
      - [Fonctions nécessaires :](#fonctions-nécessaires--3)
      - [À comprendre :](#à-comprendre--4)
  - [Exercice 2.3 : Mutex et affichage](#exercice-23--mutex-et-affichage)
    - [Objectif : Protéger les prints pour éviter les affichages mélangés](#objectif--protéger-les-prints-pour-éviter-les-affichages-mélangés)
      - [Consigne :](#consigne--5)
      - [Contraintes :](#contraintes--5)
      - [Fonctions nécessaires :](#fonctions-nécessaires--4)
      - [À comprendre :](#à-comprendre--5)
  - [Exercice 2.4 : Plusieurs mutex](#exercice-24--plusieurs-mutex)
    - [Objectif : Gérer plusieurs ressources indépendantes](#objectif--gérer-plusieurs-ressources-indépendantes)
      - [Consigne :](#consigne--6)
      - [Contraintes :](#contraintes--6)
      - [Fonctions nécessaires :](#fonctions-nécessaires--5)
      - [⚠️ Piège :](#️-piège-)
  - [Exercice 2.5 : Détecter et prévenir le deadlock](#exercice-25--détecter-et-prévenir-le-deadlock)
    - [Objectif : Résoudre le deadlock de l'exercice 2.4](#objectif--résoudre-le-deadlock-de-lexercice-24)
      - [Consigne :](#consigne--7)
      - [Piste :](#piste-)
      - [Fonctions nécessaires :](#fonctions-nécessaires--6)
      - [À comprendre :](#à-comprendre--6)


# 📘 PARTIE 1 : Maîtriser les Threads
## Exercice 1.1 : Mon premier thread

### Objectif : Créer et attendre un thread simple

#### Consignes
1. Crée un thread qui affiche `Hello from thread!` 5 fois
2. Le main affiche `Hello from main!` 5 fois
3. Le main attend la fin du thread
4. Affiche `Program finished`

#### Contraintes
- Utiliser `pthread_create()`
- Utiliser `pthread_join()`
- Pas de variables globales

#### Resultats
Les messages main et thread s'entremêlent (ordre non déterministe)

## Exercice 1.2 : Plusieurs threads

### Objectif : Gérer plusieurs threads avec des IDs

#### Consigne
1. Prend un argument `N` (nombre de threads)
2. Crée `N` threads
3. Chaque thread affiche son ID (0, 1, 2...) 3 fois
   - Format : `Thread 2: message 1`
4. Le main attend tous les threads
5. Affiche combien de threads ont été créés

#### Contraintes
- Utiliser un tableau de `pthread_t`
- Passer l'ID à chaque thread
- Faire un `join` sur tous les threads

#### Piège à éviter
```c
// ❌ FAUX :
for (int i = 0; i < n; i++)
    pthread_create(&threads[i], NULL, routine, &i);
// Le &i est partagé ! Tous les threads voient la même adresse

// ✅ CORRECT :
// Allouer un ID unique par thread ou utiliser une structure
```

## Exercice 1.3 : Thread avec retour de valeur

### Objectif : Récupérer un résultat depuis un thread

#### Consigne :
1. Créer 5 threads
2. Chaque thread calcule la somme des `N` premiers nombres
    - Thread 0 : somme de 1 à 100
    - Thread 1 : somme de 101 à 200
    - Thread 2 : somme de 201 à 300...
3. Le main récupère chaque résultat avec `pthread_join()`
4. Affiche la somme totale

#### Contraintes :
- Utiliser le deuxième paramètre de pthread_join() pour récupérer la valeur
- Allouer la mémoire pour le retour correctement

#### À comprendre :
Comment retourner une valeur depuis un thread ?

## Exercice 1.4 : pthread_detach

### Objectif : Comprendre la différence entre join et detach

#### Consigne :
- Crée 3 threads detachés
- Chaque thread affiche son ID puis attend 1 seconde (`usleep`)
- Le main affiche `Main finished` et termine
- Observer ce qui se passe

#### Contraintes :
- Utiliser `pthread_detach()`
- Utiliser `usleep()`

#### Fonctions nécessaires :
`pthread_create`, `pthread_detach`, `usleep`, `printf`

#### À comprendre :
- Que se passe-t-il si le main se termine avant les threads detachés ?
- Quelle est la différence fondamentale avec pthread_join ?

## Exercice 1.5 : Mesurer le temps

### Objectif : Maîtriser gettimeofday

#### Consigne :
- Crée une fonction get_time_ms() qui retourne le temps en millisecondes
- Crée 3 threads
- Chaque thread affiche :
  - Thread 0 started at: 0ms
  - Thread 0 finished at: 150ms
- Chaque thread simule un travail avec usleep

#### Contraintes :
- Utiliser `gettimeofday()`
- Calculer le temps relatif au lancement du programme
- Pas d'horloge absolue dans l'affichage

#### Fonctions nécessaires :
`pthread_create`, `pthread_join`, `gettimeofday`, `usleep`, `printf`

#### À comprendre :
- struct timeval tv;
  - gettimeofday(&tv, NULL);
  - long ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
- Comment calculer un temps relatif ?
- Pourquoi éviter time() qui ne donne que les secondes ?

# 📗 PARTIE 2 : Threads + Mutex

## Exercice 2.1 : Le problème sans mutex

### Objectif : Visualiser une race condition

#### Consigne :
- Crée une variable globale int counter = 0
- Lance 5 threads
- Chaque thread incrémente counter 10 000 fois
- Le main affiche la valeur finale
- Résultat attendu : 50 000
- Résultat obtenu : ???

#### Contraintes :
- NE PAS utiliser de mutex (c'est le but !)
- Lancer plusieurs fois le programme

#### Fonctions nécessaires :
`pthread_create`, `pthread_join`, `printf`

#### À comprendre :
- Pourquoi le résultat est différent à chaque fois ?
- Qu'est-ce qu'une race condition ?

## Exercice 2.2 : Résoudre avec un mutex

### Objectif : Protéger une ressource partagée

#### Consigne :
- Reprends l'exercice 2.1
- Ajoute un mutex pour protéger l'incrémentation
- Le résultat doit toujours être 50 000

#### Contraintes :
- Utiliser `pthread_mutex_init()`
- Utiliser `pthread_mutex_lock()` / `pthread_mutex_unlock()`
- Utiliser `pthread_mutex_destroy()`
- Toujours détruire le mutex à la fin

#### Fonctions nécessaires :
`pthread_create`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_lock`, `pthread_mutex_unlock`, `pthread_mutex_destroy`, `printf`

#### À comprendre :
```c
// Section critique
pthread_mutex_lock(&mutex);
counter++;              // Une seule thread à la fois ici
pthread_mutex_unlock(&mutex);
```

## Exercice 2.3 : Mutex et affichage

### Objectif : Protéger les prints pour éviter les affichages mélangés

#### Consigne :
- Crée 5 threads
- Chaque thread affiche 3 messages avec timestamp :
  - [42ms] Thread 2: eating
  - [43ms] Thread 2: sleeping
  - [44ms] Thread 2: thinking
- Les lignes ne doivent jamais être mélangées

#### Contraintes :
- Un mutex dédié uniquement pour les prints
- Utiliser `gettimeofday()` pour le timestamp
- Chaque printf complet doit être atomique

#### Fonctions nécessaires :
`pthread_create`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_lock`, `pthread_mutex_unlock`, `pthread_mutex_destroy`, `gettimeofday`, `printf`

#### À comprendre :
- Pourquoi même les prints ont besoin d'être protégés ?

## Exercice 2.4 : Plusieurs mutex

### Objectif : Gérer plusieurs ressources indépendantes

#### Consigne :
- Crée 5 fourchettes (5 mutex)
- Lance 5 threads (philosophes)
- Chaque philosophe a besoin de 2 fourchettes pour manger
- Philosophe i prend la fourchette i et i+1
- Chaque philosophe mange 3 fois puis termine
- Affiche quand il prend/pose chaque fourchette

#### Contraintes :
- Un tableau de mutex : pthread_mutex_t forks[5]
- Pas de deadlock (pour l'instant, ne pas y penser)
- Utiliser `usleep()` pour simuler manger/penser

#### Fonctions nécessaires :
`pthread_create`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_lock`, `pthread_mutex_unlock`, `pthread_mutex_destroy`, `usleep`, `gettimeofday`, `printf`

#### ⚠️ Piège :
- Cet exercice peut provoquer un deadlock
- Observer dans quelles conditions il apparaît
- C'est exactement le problème de Philosophers !

## Exercice 2.5 : Détecter et prévenir le deadlock

### Objectif : Résoudre le deadlock de l'exercice 2.4

#### Consigne :
    Reprends l'exercice 2.4
    Trouve une stratégie pour éviter le deadlock

#### Piste :
- Les philosophes pairs prennent gauche puis droite
- Les philosophes impairs prennent droite puis gauche

#### Fonctions nécessaires :
`pthread_create`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_lock`, `pthread_mutex_unlock`, `pthread_mutex_destroy`, `usleep`, `gettimeofday`, `printf`

#### À comprendre :
- Pourquoi l'ordre de prise des mutex est crucial ?
- Quelles autres stratégies existent ?