# REPONSE DE L'EXERCICE 1

> L'énoncé de l'exercice 1 demande la création de trois fichiers dans un dépôt vide et la collecte des logs des commits en une lignes et de leur graphe. Pour se faire, le dépôt `ex2` a été créé à en mode public à l'adresse suivante: https://github.com/Nyeck-Abondo/ex2.git

## HISTORIQUE EN UNE LIGNE PAR COMMIT

Commande tapée à la racine du dépot:
```
git log --oneline
```

resultat:

```
889b6de (HEAD -> main) Ajout du troisième fichier dans le dépôt:
5ce0b05 Ajout du second fichier de l'exercice 2:
51f829f Ajout du premier fichier de l'exercice 1 du Ch2
a5a9943 (origin/main, origin/HEAD) Initial commit
```

## AFFICHAGE DU GRAPHE DES COMMITS

Commande tapée à la racine du dépot:

```
git log
```
resultat :
```
commit 889b6decc4cf5d8495ef82abeba461794f6215fe (HEAD -> main)
Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
Date:   Wed Sep 16 14:12:52 2026 +0100

    Ajout du troisième fichier dans le dépôt:

    L'exercice démande d'ajouter trois fichiers quelconques. f3.cpp constitue le troisième nécessaire pour être conforme à l'énoncé de l'exercie.
    Maintenant, le dépôt contient les trois fichiers demandé par l'énoncé.

commit 5ce0b054551f4fa4e04a71f1fce986d89c777a8d
Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
Date:   Wed Sep 16 14:09:09 2026 +0100

    Ajout du second fichier de l'exercice 2:

    Le second tiers de l'exercice demande d'ajouter un fichier quelconque dans le dépôt vièrge.
    Maintenant, le dépot contient deux fichiers.

commit 51f829f3d5abc8397c1749587eb00061e96b6686
Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
Date:   Wed Sep 16 14:04:00 2026 +0100

    Ajout du premier fichier de l'exercice 1 du Ch2

commit a5a9943f49f5445d313ddccf04c8d8b84d417752 (origin/main, origin/HEAD)
Author: Nyeck-Abondo <emilemaelnyeckabondo@gmail.com>
Date:   Wed Sep 16 14:01:19 2026 +0100
```