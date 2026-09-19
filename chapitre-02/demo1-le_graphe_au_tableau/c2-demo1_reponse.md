# REPONSE DE LA DEMO 1

> Le dépôt utilisé ici est celui d'essai, car portant des commit plus court que celui de nkentseu, et des modification de fusion resultant des exercices précédent. Ce qui rendra l'exercice plus lisible.

## Dessin du graphe à la main

Afin de pouvoir dessiner le graphe du dépôt d'essai, celui ci a d'abord été affiché en sa forme minimale avec la commande:

```
git log --oneline --graph
```
ce qui manuelement représenté donne le resultat suivant:

```



                                (test-exo10)    b7b9139 ● ── 581c34b ● ── c0d93a2 ── ── ── ───                     
                                              /                                                ╲                  
(main)  ...3842571 ● ── 703e420 ● ── 67841f5 ● ── ── ── ── ── ── ── ── ── ── ── ── ● 5228508 ── ● a7b0f66 ── ● 27674da ....

```

- point de divergence de fusion: le point de divergence de fusion dur ce graphe se présente à partir du commit 67841f5 tel que représenté ici

```
      (test-exo10)    b7b9139                      
                    /                                                                
(main)  ...67841f5 ● ── 
```

- La fusion : La fusion elle ne survient que vers la fin de la représentation. Elle se reconnait facilement sur la portion du graphe commençant avec le commit a7b0f66 qui représente le commit de fusion.

```
(test-exo10) c0d93a2 ── ── ── ───                     
                                  ╲                  
                 (main) 5228508 ── ● a7b0f66 ── ● 27674da ....
```

## Affichage par la commande dédiée

ici nous utiliserons la commande de l'énoncé:

```
git log --graph
```

sont résultat pour ce dépôt est le suivant:

```
* commit dccda80d74d4d14da863de1da06db133575c6699 (HEAD -> main)
| Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| Date:   Sat Sep 19 01:54:44 2026 +0100
| 
|     Retrait de la video de 10 mo
| 
* commit 84345a3868e1bbcdc52c5dc7afc3d9d3c914e7d2
| Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| Date:   Sat Sep 19 01:27:47 2026 +0100
| 
|     feat : ajout de la vidéo de 10 mo pour le compte de l'exerciec 11 du srprint 2
| 
* commit ab3850428c6b4bb5530f6f2c374cd92da6b04a0c
| Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| Date:   Sat Sep 19 00:40:32 2026 +0100
| 
|     feat: Modification du fi.cpp dans le cadre du second volet de l'exercice 10 dans la branche main
| 
* commit 48d0f65b9275a4b9824b4ee7e76d362e3bc39b6b (origin/test-exo10, test-exo10)
| Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| Date:   Sat Sep 19 00:37:40 2026 +0100
| 
|     Seconde Modification de f2.cpp pour le compte de l'exercice 10 pour le second volet dans la branche test-exo10
| 
* commit 27674da216d8b47278fadcdcb5b6f56def0843e8
| Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| Date:   Sat Sep 19 00:36:15 2026 +0100
| 
|     Modification de f2.cpp pour le compte de l'exercice 10 dans la branche test-exo10
|   
*   commit a7b0f66234d16928d96fcf5c22817982c9e0e709
|\  Merge: c0d93a2 5228508
| | Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| | Date:   Sat Sep 19 00:33:45 2026 +0100
| | 
| |     Merge branch 'main' of https://github.com/Nyeck-Abondo/ex2 into test-exo10
| | 
| * commit 522850856ef0d0c11799e898796284527835a570
| | Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| | Date:   Sat Sep 19 00:14:08 2026 +0100
| | 
| |     modification de f1.cpp pour faire avancer la branche main
| | 
* | commit c0d93a2a6ad9919f055e952a8854c136ad395987
| | Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| | Date:   Fri Sep 18 23:51:00 2026 +0100
| | 
| |     modification numéro tois de f2.cpp pour le compte de l'exercice 10
| | 
* | commit 581c34b64471fbda943e684e84c6a2021196abdb
| | Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| | Date:   Fri Sep 18 23:50:37 2026 +0100
| | 
| |     modification numéro une de f2.cpp pour le compte de l'exercice 10
| | 
* | commit b7b9139cabc0b5c58afddae810b64be17ea112d2
|/  Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
|   Date:   Fri Sep 18 23:50:20 2026 +0100
|   
|       modification numéro une de f2.cpp pour le compte de l'exercice 10
| 
* commit 67841f540445ff2dd9383afc2804e970580ec91d
| Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| Date:   Fri Sep 18 00:03:00 2026 +0100
| 
|     Validation des modification
| 
```

## Correspondance entre les deux graphes

Après observation des deux graphes fournis plus haut, on remarque que ceux ci présentent effectivement les même informations:

- Le point de divergence s'effectue effectivement sur le même commit: **b7b9139cabc0b5c58afddae810b64be17ea112d2** qui correspond avec son identifiant court à **67841f5**
- le point de fusion : qui est marqué par le même commit de merge dans les deux cas : **a7b0f66234d16928d96fcf5c22817982c9e0e709** qui correspond à **a7b0f66** dans sa version courte.
- Ils font tous les deux intervenir les même branches : **main** et **test-exo01**, comme indiqué sur le graphe manuel et d'après le commit de merge **Merge branch 'main' of https://github.com/Nyeck-Abondo/ex2 into test-exo10** .