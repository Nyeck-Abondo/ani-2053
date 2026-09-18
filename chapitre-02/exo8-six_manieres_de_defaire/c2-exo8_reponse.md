# REPONSE DE L'EXERCICE 8

> Cet exercice utilise le dépôt expérimental créér depuis l'exercice 1 ou 2 environ: `ex2` présent à l'adresse https://github.com/Nyeck-Abondo/ex2.git . 

## Etati initial du fichier `f1.cpp`

```cpp
#include <iostream>

int main() {
    float p = 10;
    return 5;
}
```

## Situation 01 : une modification non voulue

- Provocation de la situation: modification du chier à la ligne 5

```cpp
#include <iostream>

int main() {
    float p = 10;
    return 2;
}
```

- Correction de la situation:

```
git restore f1.cpp
```

retusltat :

```cpp
#include <iostream>

int main() {
    float p = 10;
    return 5;
}
```
On peut remarquer que les deux fichiers sont revenus à la normale.

## Situation 02 : un add de trop

Considéront la modifiation plus haut :

```cpp
#include <iostream>

int main() {
    float p = 10;
    return 2;
}
```
Encore repétée ici suivi d'une indexation avec `git add`. (le contenu du fichier `f1.cpp` est présenté tel quel. aucune supposition n'est utilisée)

```
git status

On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   f1.cpp
```
Pour annuler l'indexation des modificaitons dans le fichier, on utilisera la commade suivante :

```
git restore --staged f1.cpp
```
après vérification on obtient :

```
git status 

On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   f1.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```

La modification effectuée sur le fichier n'est plus suivie.

## Situation 03: un commit de trop

considéron toujours la modification effectué plus haut :

```cpp
#include <iostream>

int main() {
    float p = 10;
    return 2;
}
```
Ceci est l42tqt qctuel de `f1.cpp`. Indexons la de nouveau puis validons la.

- **Indexation**
```
git add .
```

- **Validation** :

```
git commit -m "Validation des modification"

[main 2216225] Validation des modification
 1 file changed, 1 insertion(+), 1 deletion(-)
```

- **Correction de la situation** :

```
git reset --soft HEAD~1

git log --oneline

703e420 (HEAD -> main, origin/main, origin/HEAD) feat: Modification du second dépôt
3842571 feat: modification de la ligne 4 pour le compte de l'exercice 7 dqns le dépôt initial
be257e7 feat: resolution du conflit des dépôts
713e1de feat: rempacement de float a = 0 par float a = 12 dans le dépôt secondaire
9276e7b remplacement de la variable int a = 0 par float p = 3 dans le dépôt initial
f9c3fe1 Modification du dépôt initial sur la dépôt principal
cadaa75 Modification du dépôt initial sur la dépôt principal
```

La tête a reculé d'un commit vers l'arrière, en conservant les modifications apportées dans le fichier qui étaient liées au commit précédent.

- Etat actuel de `f1.cpp` :

```cpp
#include <iostream>

int main() {
    float p = 10;
    return 2;
}
```
avec un statut **modifié**

Comme on peut le constater, la ligne 6 a changé

## Situation 04 : un commit poussé qu'il faut annuler

considérons toujours le ême commit. Les étapes précédentes sont simplement répétées. A ce stade le fichier `f1.cpp` est avce un statut **modifier** à cause de la dernière opération. indexons et poussons le tout sur le dépôt distant

```
git add .

git commit -m "Validation des modification"

[main 67841f5] Validation des modification
 1 file changed, 1 insertion(+), 1 deletion(-)

git push

Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 12 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 307 bytes | 307.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/Nyeck-Abondo/ex2.git
   703e420..67841f5  main -> main
```

- **état de l'istorique des Commits du dépôt** :

```
git log --oneline --graph --decorate

* 67841f5 (HEAD -> main, origin/main, origin/HEAD) Validation des modification
* 703e420 feat: Modification du second dépôt
* 3842571 feat: modification de la ligne 4 pour le compte de l'exercice 7 dqns le dépôt initial
```

Comme on peut le remarquer, le commit est bien apparu dans l'historique.

- Résolution de la situation problème :  La commande à exécuter ici

```
git revert 67841f5

[main fb052b2] Revert "Validation des modification"
 1 file changed, 1 insertion(+), 1 deletion(-)

git push origin main
```

67841f5 aui correspont qu au hash du commit. Cette commande va annuler le commit dont le hash a été passé en second argument. Et le git push envoie la modification vers le dépôt distant

## Situation 05 : un travail en cours qu'il faut mettre de côté

Dans cette situation, nous ajouterons une dernière modification pour l'exercice à la ligne 4:

```cpp
#include <iostream>

int main() {
    float p = 6;
    return 5;
}
```

La commande a utiliser lorsque l'on ne veut pas valider un travail en cous est `git stash`. Dans le dépôt, son exécution abouti au résultat suivant:

```
git add . 

git status
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   f1.cpp

git stash

Saved working directory and index state WIP on main: fb052b2 Revert "Validation des modification"
```

## Situation 06 : un commit « perdu » à retrouver par le `reflog

Dans cette situation, on retirera un commit de l'historique à l'aide de `git reset --soft HEAD~1`. Et on le cherchera de nouveau grâce à `git reflog`.

- **Recherche et Suppression du commit** :

```
git log --oneline --graph --decorate

* fb052b2 (HEAD -> main) Revert "Validation des modification"
...

git revert fb052b2       

[main 551c037] Reapply "Validation des modification"
 1 file changed, 1 insertion(+), 1 deletion(-)
```

- **Recherche du commit** : Le commit qui nous interresse ici est celui avec le hash **fb052b2** :

```
git reflog

551c037 (HEAD -> main) HEAD@{0}: rebase (finish): returning to refs/heads/main

551c037 (HEAD -> main) HEAD@{1}: rebase (start): checkout refs/remotes/origin/main

551c037 (HEAD -> main) HEAD@{2}: revert: Reapply "Validation des modification"

fb052b2 HEAD@{3}: reset: moving to fb052b2
fb052b2 HEAD@{4}: reset: moving to HEAD
fb052b2 HEAD@{5}: revert: Revert "Validation des modification"
```

- **restauration du commit** :
```
git reset --hard fb052b2

HEAD is now at fb052b2 Revert "Validation des modification"

git log --oneline

fb052b2 (HEAD -> main) Revert "Validation des modification"
```

Comme on s'y attendait, le commit a été restauré à la dernière position.