# NetPractice
![42 Cursus](https://img.shields.io/badge/42-Cursus-blue?style=for-the-badge)
![Projects](https://img.shields.io/badge/Projects-Common_Core-success?style=for-the-badge)
![Score](https://img.shields.io/badge/score-100%20%2F%20100-success?style=for-the-badge)<br>
[🇫🇷 Français](./README.md)
- [NetPractice](#netpractice)
  - [Description](#description)
  - [Instructions](#instructions)
  - [Ressources](#ressources)
    - [Adressage TCP/IP](#adressage-tcpip)
    - [Masques de sous-réseau](#masques-de-sous-réseau)
    - [Passerelle par défaut](#passerelle-par-défaut)
    - [Routeurs et switches](#routeurs-et-switches)
    - [Couches OSI](#couches-osi)
    - [Routage IP statique](#routage-ip-statique)
    - [Liens Utils](#liens-utils)

## Description
Un projet axé sur les réseaux conçu pour développer une compréhension pratique de l’adressage TCP/IP et de la configuration réseau. À travers une série d’exercices de difficulté progressive, l’objectif est de configurer correctement de petites infrastructures réseau en manipulant les adresses IP, les masques de sous-réseau, le routage et les règles de connectivité. Le projet met l’accent sur la résolution de problèmes logiques liés aux réseaux, la compréhension de la communication entre appareils à travers différents sous-réseaux, ainsi que l’application des concepts fondamentaux du réseau sans recourir à des outils automatisés. Ce projet renforce les connaissances en réseaux informatiques, en schémas d’adressage, en logique de routage, en subnetting et en bases de l’architecture réseau bas niveau.

## Instructions
- Lancer le script fourni par l'école (run.sh)
- Deux modes sont disponibles :
  - Le mode entrainement vous donnera accès à 10 niveaux avec une difficulté croissante.
  - Le mode examen vous donnera 3 exercices aléatoires entre les exercices 6 - 10 du mode entrainement.
- Pendant un exercice, il y a 2 boutons principaux :
  - `Check Again` : Permet de vérifier si l'exercice est correct après une modification.
  - `Get my config` : Télécharger un fichier `json` contenant la configuration de votre exercice avec les données que vous avez saisies.
  - Un dernier bouton apparaît une fois l'exercice réussi pour passer au suivant.
- Pour la soumission des exercices, les 10 fichiers de configuration `json` (1 par niveau) doivent être mis à la racine du dépôt git pour la correction.

## Ressources
### Adressage TCP/IP
`TCP/IP` est le langage commun d'Internet. 
- IP (`Internet Protocol`) s'occupe de l'adressage, chaque machine sur un réseau possède une adresse IP unique (exemple: 192.168.1.10), comme une adresse postale. 
- TCP (`Transmission Control Protocol`) s'occupe de la livraison, il découpe les données en paquets, les envoie, et s'assure qu'ils arrivent tous à destination dans le bon ordre.

### Masques de sous-réseau
Un `masque de sous-réseau` (exemple: `255.255.255.0` ou `/24`) permet de diviser un réseau en plusieurs petits sous-réseaux. Il indique quelle partie de l'adresse IP désigne le réseau, et quelle partie désigne la machine. Par exemple, deux machines avec les adresses `192.168.1.10` et `192.168.1.20` en `/24` sont sur le même réseau et peuvent communiquer directement. En `/30`, elles pourraient se retrouver dans deux sous-réseaux différents.

### Passerelle par défaut
La `passerelle par défaut` est l'adresse du routeur à qui une machine envoie ses paquets quand la destination est en dehors de son réseau local. C'est la "porte de sortie" du réseau. Sans elle configurée correctement, une machine peut parler à ses voisins, mais pas au reste du monde.

### Routeurs et switches
- Un `switch` relie des machines au sein d'un même réseau local (`LAN (Local Area Network)`). Il connaît les `adresses MAC` de chaque appareil connecté et fait suivre les trames au bon destinataire.
- Un `routeur`, relie plusieurs réseaux différents entre eux. Il lit les adresses `IP` et décide par quel chemin faire passer un paquet pour qu'il atteigne sa destination, en s'appuyant sur une table de routage.

### Couches OSI
Les `couches OSI` découpent la communication réseau en 7 couches, chacune ayant un rôle précis:

- `Couche 1 — Physique` : Elle s'occupe de la transmission brute des bits sur le support physique (câble Ethernet, fibre optique, Wi-Fi).
- `Couche 2 — Liaison de données` : Elle organise les bits en trames et gère la communication entre deux machines directement connectées. C'est ici qu'interviennent les adresses MAC et les switches.
- `Couche 3 — Réseau` : Elle gère l'adressage IP et le routage des paquets d'un réseau à un autre. C'est le domaine des routeurs et du protocole IP.
- `Couche 4 — Transport` : Elle assure la livraison fiable des données de bout en bout.
- `Couche 5 — Session` : Elle ouvre, maintient et ferme les sessions de communication entre deux applications. Elle gère par exemple la reprise d'une connexion interrompue.
- `Couche 6 — Présentation` : Elle s'occupe du format des données : chiffrement (SSL/TLS), compression, encodage. Elle fait en sorte que les données envoyées par une machine soient compréhensibles par une autre.
- `Couche 7 — Application` : Elle contient les protocoles que les applications utilisent directement : HTTP, FTP, DNS, SMTP, etc.

> Chaque couche ne parle qu'à la couche juste au-dessus ou en dessous d'elle, ce qui rend le système modulaire et universel.

### Routage IP statique
Le `routage statique`, consiste à configurer manuellement dans un routeur les chemins à emprunter pour atteindre tel ou tel réseau. Contrairement au routage dynamique (où les routeurs se parlent entre eux pour se mettre à jour), ici chaque route est écrite à la main.

### Liens Utils
- [TCP/IP - IT Connect](https://www.it-connect.fr/modules/protocole-tcp-ip/)
- [Modele OSI](https://www.cloudflare.com/learning/ddos/glossary/open-systems-interconnection-model-osi/)
- [Calculatrice de sous-reseaux](https://www.subnet-calculator.com/)