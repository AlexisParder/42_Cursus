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