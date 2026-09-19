# REPONSE DE LA DEMO 3

> Cet exercie utilise lui qussi le dépôt d'essai mis à jour de la démontration 2. il n'utilisera que le dépôt initial, tel qu'il sera présenté ci dessous avec le fichier f2.cpp mis à jour.

## Etat initial du dépôt d'essai

- f2.cpp le fichier le fichier modifié dans la démonstration précédente :

```cpp
#include <iostream>

int main() {
    int q = 1;
    float c = 11;
    double z = 20;
    return 0;
}
```

- dernier commit en date :

```
git log --oneline --graph

*   2fc7b07 (HEAD -> main, origin/main, origin/HEAD) fix: Résolution du conflit entre le dépôt initial et le dépôt secondaire
|\  
| * d977c3a feat : modification du fichier f2.cpp dans la branche main du dépôt initial
* | 14c5f9a feat : modification du fichier f2.cpp à la ligne 6 sur le dépôt secondaire
|/  
```

## Suppression du commit précédent

Ici nous nous débarasserons simplement du dernier commit en date. 

```
git reset --hard HEAD~1

HEAD is now at 14c5f9a feat : modification du fichier f2.cpp à la ligne 6 sur le dépôt secondaire
```
La tête pointe maintenant sur le commit au hash d977c3a

```
git log --oneline --graph

* 14c5f9a (HEAD -> main) feat : modification du fichier f2.cpp à la ligne 6 sur le dépôt secondaire
*   8f6e44a Merge branch 'main' of https://github.com/Nyeck-Abondo/ex2
|\  
| * 8c7e0f9 feat: Modification du fi.cpp dans le cadre du second volet de l'exercice 10 dans la branche main
| *   42048f0 Merge branch 'test-exo10' fusion de la branche test-exo10
```

## Recherche du commit perdu par le `git reset --hard`

Pour le recup2rerm nous relèverons son hash avec `git reflog` et le restaurerons avec `git restore <hash du commit>`

```
git reflog

14c5f9a (HEAD -> main) HEAD@{0}: reset: moving to HEAD~1
2fc7b07 (origin/main, origin/HEAD) HEAD@{1}: pull: Fast-forward
d977c3a HEAD@{2}: commit: feat : modification du fichier f2.cpp dans la branche main du dépôt initial
8f6e44a HEAD@{3}: pull: Merge made by the 'ort' strategy.
dccda80 HEAD@{4}: commit: Retrait de la video de 10 mo
```

la commande `git reflog` nous permet d'identifier le commit suppriimé par le `git reset --hard`. Il s'agit en effet de celui au hash **2fc7b07**, tel que présenté plus haut dans l'historique du dépôt d'essai initial.