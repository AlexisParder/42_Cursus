*Ce projet a été créé dans le cadre du cursus 42 par achauvie.*

# born2beroot
![🇬🇧 English](./README.md)

## Description
Un projet d’administration système centré sur l’installation et la configuration complète d’une machine virtuelle Linux sécurisée à partir de zéro. L’objectif est de mettre en place des règles strictes de sécurité et de conformité, incluant la gestion des utilisateurs et des groupes, des politiques minimales de mots de passe, une configuration SSH renforcée et une configuration personnalisée du pare-feu.
Le projet exige également la surveillance des ressources système à l’aide d’un script personnalisé et la documentation complète de l’installation selon des consignes rigoureuses. Ce projet permet de renforcer la compréhension des bases de Linux, de la gestion des privilèges, du durcissement de la sécurité, de la virtualisation et de la configuration système reproductible.

## Script Monitoring.sh
Le script doit toujours être capable d’afficher les informations suivantes :
- L’architecture de votre système d’exploitation ainsi que la version de son noyau.
- Le nombre de processeurs physiques.
- Le nombre de processeurs virtuels.
- La quantité de mémoire vive (RAM) disponible sur le serveur ainsi que son taux d’utilisation en pourcentage.
- L’espace de stockage disponible sur le serveur ainsi que son taux d’utilisation en pourcentage.
- Le taux d’utilisation actuel des processeurs en pourcentage.
- La date et l’heure du dernier redémarrage.
- Si LVM est actif ou non.
- Le nombre de connexions actives.
- Le nombre d’utilisateurs actuellement connectés au serveur.
- L’adresse IPv4 du serveur ainsi que son adresse MAC (Media Access Control).
- Le nombre de commandes exécutées avec le programme `sudo`.

### Ressources
- ![Guide Born2beroot](https://github.com/Vikingu-del/Born2beRoot)