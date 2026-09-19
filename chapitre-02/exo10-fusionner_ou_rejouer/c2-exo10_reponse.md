# REPONSE DE L'EXERCCICE 10

> Dans le cadre de cet exercice, la seconde copie du dépôt d'essai a été supprimé pour ne rester qu'avec une seule valable. Il ne contitent que la branche de Test de l'exercice 5, et les fichiers qui seront modifiés ici sont `f2.cpp` et `f1.cpp`

## Etat intial du dépôt

ceci est l'état initial de `f2.cpp`

```cpp
#include <iostream>

int main() {
    int q;
    return 0;
}
```

ceci est celui de `f1.cpp` :

```cpp
#include <iostream>

int main() {
    float p = 10;
    return 2;
}
```

## Création de la branche de test pour l'exercice

```
git checkout -b test-exo10
```
la position actuelle de la tête se trouve sur la branche test-exo10 comme indiqué ci dessous

```
git branch
  main
* test-exo10
```

## Modification sur la branche `test-exo10` de `f2.cpp`

- première modification ligne 4:

    ```cpp
    #include <iostream>

    int main() {
        int q = 1;
        return 0;
    }
    ```
    - indexation et validation

    ```
    git add .

    git commit -m "modification numéro une de f2.cpp pour le compte de l'exercice 10"

    [test-exo10 a7dddd8] modification numéro une de f2.cpp pour le compte de l'exercice 10
    1 file changed, 1 insertion(+), 1 deletion(-)

    git push
  
    Enumerating objects: 5, done.
    Counting objects: 100% (5/5), done.
    Delta compression using up to 12 threads
    Compressing objects: 100% (3/3), done.
    Writing objects: 100% (3/3), 364 bytes | 364.00 KiB/s, done.
    Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
    remote: Resolving deltas: 100% (1/1), completed with 1 local object.
    ```

- seconde modification ligne 5:

    ```cpp
    #include <iostream>

    int main() {
        int q = 1;
        float c = 15;
        double q = 15;
        return 0;
    }
    ```

    - indexation et validation:
    ```
    git add .                                                                        
    git commit -m "modification numéro 02 de f2.cpp pour le compte de l'exercice 10" 
    
    [test-exo10 ffb9d2b] modification numéro 02 de f2.cpp pour le compte de l'exercice 10
    1 file changed, 1 insertion(+)
    
    git push
    
    Enumerating objects: 5, done.
    Counting objects: 100% (5/5), done.
    Delta compression using up to 12 threads
    Compressing objects: 100% (3/3), done.
    Writing objects: 100% (3/3), 369 bytes | 369.00 KiB/s, done.
    Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
    remote: Resolving deltas: 100% (1/1), completed with 1 local object.
    To https://github.com/Nyeck-Abondo/ex2.git
    a7dddd8..ffb9d2b  test-exo10 -> test-exo10
    ```
- troisièmr modification ligne 6 et 7:
    ```cpp
    #include <iostream>

    int main() {
        int q = 1;
        float c = 15;
        double q = 15;
        return 0;
    }
    ```

    - indexation et validation:
    ```                                                          git add .        
    
    git commit -m "modification numéro 02 de f2.cpp pour le compte de l'exercice 10" 
    
    [test-exo10 ffb9d2b] modification numéro 02 de f2.cpp pour le compte de l'exercice 10
    1 file changed, 1 insertion(+)
    
    git push
    
    Enumerating objects: 5, done.
    Counting objects: 100% (5/5), done.
    Delta compression using up to 12 threads
    Compressing objects: 100% (3/3), done.
    Writing objects: 100% (3/3), 369 bytes | 369.00 KiB/s, done.
    Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
    remote: Resolving deltas: 100% (1/1), completed with 1 local object.
    To https://github.com/Nyeck-Abondo/ex2.git
    a7dddd8..ffb9d2b  test-exo10 -> test-exo10
    ```
## Avancée de la branche main

Dans le fichier f1.cpp on apporte une modificcation à la ligne 4 :
```cpp
#include <iostream>

int main() {
    float p = 12;
    return 2;
}
```

- indexation, validation et poussée sur le dépôt distant:

```

```

les modifications ont été poussées, maintenant fusionnons le tou à la branche principale avevc un simple `git merge`:

## placement de la têt sur la branche principale et fusion du contenu:

- Déplacement entre les branches:

```
git checkout main

Switched to branch 'main'
Your branch is up to date with 'origin/main'.
```

- fusion du contenu de la branche `test-exo10` sur la branche main:

```
git add .

git commit -m "modification de f1.cpp pour faire avancer la branche main"

[main 5228508] modification de f1.cpp pour faire avancer la branche main
 1 file changed, 1 insertion(+), 1 deletion(-)

git push

Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 12 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 363 bytes | 363.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/Nyeck-Abondo/ex2.git
   67841f5..5228508  main -> main
```
## Fusion de la branche `test-exo10`

```
git merge test-exo10
Merge made by the 'ort' strategy.
 f2.cpp | 4 +++-
 1 file changed, 3 insertions(+), 1 deletion(-)
```
## Etat de l'historique des commits

pour vérifier l'historique des commits, la commande exécutée est `git log --decorate --graph` deouis la branche main:

```
git log --graph
*   commit 42048f0c9f11947769f256d22c859cd6b7a099da (HEAD -> main)
|\  Merge: 5228508 c0d93a2
| | Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| | Date:   Sat Sep 19 00:15:53 2026 +0100
| | 
| |     Merge branch 'test-exo10'
| |     fusion de la branche test-exo10
| | 
| * commit c0d93a2a6ad9919f055e952a8854c136ad395987 (origin/test-exo10, test-exo10)
| | Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| | Date:   Fri Sep 18 23:51:00 2026 +0100
| | 
| |     modification numéro tois de f2.cpp pour le compte de l'exercice 10
| | 
| * commit 581c34b64471fbda943e684e84c6a2021196abdb
| | Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| | Date:   Fri Sep 18 23:50:37 2026 +0100
| | 
| |     modification numéro une de f2.cpp pour le compte de l'exercice 10
| | 
| * commit b7b9139cabc0b5c58afddae810b64be17ea112d2
| | Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| | Date:   Fri Sep 18 23:50:20 2026 +0100
| | 
| |     modification numéro une de f2.cpp pour le compte de l'exercice 10
| | 
* | commit 522850856ef0d0c11799e898796284527835a570 (origin/main, origin/HEAD)
|/  Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
|   Date:   Sat Sep 19 00:14:08 2026 +0100
:
| | Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| | Date:   Fri Sep 18 23:50:20 2026 +0100
| | 
| |     modification numéro une de f2.cpp pour le compte de l'exercice 10
| | 
* | commit 522850856ef0d0c11799e898796284527835a570 (origin/main, origin/HEAD)
|/  Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
|   Date:   Sat Sep 19 00:14:08 2026 +0100
|   
|       modification de f1.cpp pour faire avancer la branche main
```

On remaque ici un second graphe de commit qui semble apparteni à la branche `test-exo10` sur la droite de celle totalement vertivale qui vient s'introduire sur le graphe de la branche main.

> NB : Pour la suite, le dépôt d'essai gardera son état actuel

## Etat acutel des deux fichiers sur la branche main

- **f1.cpp** :

```cpp
#include <iostream>

int main() {
    float p = 12;
    return 2;
}
```

- **f2.cpp** :

```cpp
#include <iostream>

int main() {
    int q = 1;
    float c = 15;
    double q = 15;
    return 0;
}
```

## Modification de f2.cpp sur `test-exo10`

avant de procéder au modification, afin d'éviter tout conflit, procédons à un pull des données de main:

- placement sur la branche concernée :

```
git checkout test-exo10

Switched to branch 'test-exo10'
Your branch is up to date with 'origin/test-exo10'.
```

- Pull des changements :

```
git pull origin main

From https://github.com/Nyeck-Abondo/ex2
 * branch            main       -> FETCH_HEAD
Merge made by the 'ort' strategy.
 f1.cpp | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)
```

- Modification de f2.cpp ligne 6 :

    ```cpp
    #include <iostream>

    int main() {
        int q = 1;
        float c = 15;
        double q = 20;
        return 0;
    }
    ```
    q passe à 20.

    - commit des changements :

    ```
    git commit -m "Modification de f2.cpp pour le compte de l'exercice 10 dans la branche test-exo10"

    [test-exo10 27674da] Modification de f2.cpp pour le compte de l'exercice 10 dans la branche test-exo10
    1 file changed, 1 insertion(+), 1 deletion(-)
    ```

- Modification de f2.cpp ligne 5 :

    ```cpp
    #include <iostream>

    int main() {
        int q = 1;
        float c = 11;
        double q = 20;
        return 0;
    }
    ```
    c passe à 11 .

    - commit des changements :

    ```
    git commit -m "Seconde Modification de f2.cpp pour le compte de l'exercice 10 pour le second volet dans la branche test-exo10"
    
    [test-exo10 48d0f65] Seconde Modification de f2.cpp pour le compte de l'exercice 10 pour le second volet dans la branche test-exo10
    1 file changed, 1 insertion(+), 1 deletion(-)
    ```

Toutes les modifications sont poussées en une fois :

```
git push

Enumerating objects: 12, done.
Counting objects: 100% (12/12), done.
Delta compression using up to 12 threads
Compressing objects: 100% (8/8), done.
Writing objects: 100% (8/8), 1007 bytes | 1007.00 KiB/s, done.
Total 8 (delta 4), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (4/4), completed with 1 local object.
To https://github.com/Nyeck-Abondo/ex2.git
   c0d93a2..48d0f65  test-exo10 -> test-exo10
```

## Avancée de la branche main

Comme dans le cas précédent, nous recréons les condition de fusion des modifications de la brache de test sur la branche principale en avançant d'un commit celle ci:

- passage sur la branche main :

```
git checkout main

Switched to branch 'main'
Your branch is ahead of 'origin/main' by 4 commits.
  (use "git push" to publish your local commits)
```

- Modification de f1.cpp ligne 5 :

```cpp
#include <iostream>

int main() {
    float p = 12;
    return 12;
}
```

On retourne maintenant 12 .

- Validation et poussée sur le dépôt distant :

```
git commit -m "feat: Modification du fi.cpp dans le cadre du second volet de l'exercice 10 dans la branche main"

[main 8c7e0f9] feat: Modification du fi.cpp dans le cadre du second volet de l'exercice 10 dans la branche main
 1 file changed, 1 insertion(+), 1 deletion(-)

git push

Enumerating objects: 9, done.
Counting objects: 100% (9/9), done.
Delta compression using up to 12 threads
Compressing objects: 100% (5/5), done.
Writing objects: 100% (5/5), 639 bytes | 639.00 KiB/s, done.
Total 5 (delta 3), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (3/3), completed with 2 local objects.
To https://github.com/Nyeck-Abondo/ex2.git
   5228508..8c7e0f9  main -> main
```

## Lancement du rebase sur main

```
git rebase test-exo10

Successfully rebased and updated refs/heads/main.
```

## Organisation de l'historique des commits

```
 git log --graph --decorate
* commit ab3850428c6b4bb5530f6f2c374cd92da6b04a0c (HEAD -> main)
| Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| Date:   Sat Sep 19 00:40:32 2026 +0100
| 
|     feat: Modification du fi.cpp dans le cadre du second volet de l'exercice 10 dans la branche main
| 
* commit 48d0f65b9275a4b9824b4ee7e76d362e3bc39b6b (origin/test-exo10, test-exo10)
| Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| Date:   Sat Sep 19 00:37:40 2026 +0100
| 
|     Seconde Modification de f2.cpp pour le compte de l'exercice 10 pour le second volet dans 
la branche test-exo10
| 
* commit 27674da216d8b47278fadcdcb5b6f56def0843e8
| Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| Date:   Sat Sep 19 00:36:15 2026 +0100
| 
:
| 
|     Seconde Modification de f2.cpp pour le compte de l'exercice 10 pour le second volet dans la branche test-exo10
| 
* commit 27674da216d8b47278fadcdcb5b6f56def0843e8
| Author: Maël Abondo <emilemaelnyeckabondo@gmail.com>
| Date:   Sat Sep 19 00:36:15 2026 +0100
| 
|     Modification de f2.cpp pour le compte de l'exercice 10 dans la branche test-exo10
|   
```

On remarque ici qu'en rejouant, les commits sont placés dsirectement à la suite du commit parent du premier commit de modification effectué sur `test-exo10` . de plus, ces commits sont insérés directement dans la ligne du graphe de la branche principale.

## Conclusion argumentée sur les préférences de lecture

Au terme des deux expérimentations des commandes, on remarque que `git merge` crée un graphe secondaire indiquant de façon séparé les changements ajouté à la branche sur laquelle il est appelé. Tandis que `git rebase` lui concatène tous les commits à la suite du commit parent et le tout sur la même branche. Mais ces deux commandes font exactement la même chose: **ajouter les modifications d'une branche sur une autre**

Pour des préférence de lisibilité et de suivi, je prefèrerai travailler avec `git merge` , car cette commande permet de voir exactement sur un graphe séparé sur quelle branche venait des modifications précises. Cela facilite grandement le traçage du travail