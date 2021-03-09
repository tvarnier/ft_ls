# FT_LS [[Sujet](https://github.com/tvarnier/42/blob/master/system/ft_ls/subject.pdf)]

<br>

Le projet consiste simplement à recoder la commande `ls`, voir la [page manuel](http://manpagesfr.free.fr/man/man1/ls.1.html) pour plus d'informations.

IL nous permet de découvir un sous ensemble de fonctions de l’API de notre système d’exploitation et les structures de données associées, ainsi que la gestion des allocations mémoires qui vont avec ces données.

ft_ls est également une excellente opportunité de réflechir à la structure de notre code avant de nous jeter à corps perdu dans l’écriture du code.

<br>

## Lancer le projet

<br>

Lancer la commande `make` pour compiler le projet.

Il suffit ensuite de lancer la commande `./ft_ls <options>`

Les options suivantes sont implémantées :

 * `-G` | *Afficher avec les couleurs*
 * `-R` | *Afficher récursivement le contenu des sous-répertoires*
 * `-a` | *Afficher tous les fichiers des répertoires, y compris les fichiers commençant par un « . »*
 * `-d` | *Afficher les répertoires avec la même présentation que les fichiers, sans lister leur contenu*
 * `-f` | *Ne pas trier le contenu des répertoires, l'afficher dans l'ordre où il se présente sur le disque.*
 * `-g` | *Option sans effet, conservée pour assurer la compatibilité avec Unix*
 * `-l` | *Afficher en format long, voir le man pour plus de précisions*
 * `-r` | *Inverser le tri du contenu des répertoires*
 * `-t` | *Trier le contenu des répertoires en fonction de la date, les fichiers les plus récents sont présentés en premier*
 * `-u` | *Employer la date des derniers accès aux fichiers plutôt que la date de modification (Affichage et Tri)*
