# REPONSE DE L'EXERCICE 11

> Le dépôt utilisé ici est le dépôt d'essai tel qu'il a été laissé à l'exercice 10

## Etat initial du dépôt

- fichier **f1.cpp** :

```cpp
#include <iostream>

int main() {
    float p = 12;
    return 12;
}
```

- fichier **f2.cpp** :

```cpp
#include <iostream>

int main() {
    int q = 1;
    float c = 11;
    double q = 20;
    return 0;
}
```

- fichier **f3.cpp** :

```cpp
#include <iostream>
template <typename T>
T Add(T a, T b) {
    return a + b;
}

int main() {
    Add(10, 15);
    return 0;
}
```

- Poids du dépôt (le .git) : après mesure avant toute modification en lien avec l'exercice 11, le dépôt pèse actuellement sur le disque **100 KB (102,400 bytes)**

## Ajout dans le dépôt d'un fichier de 10 mégo octets

Le fichier choisi ici pour le commit est une capture vidéo de l'écran de mon bureau prise pendant 13 secondes pour atteindre le poids demandé, soit **10.7 mo** . le nom de la vidéo en question est **Recording 2026-09-18 170931.mp4** .

```
git status

On branch main
Your branch and 'origin/main' have diverged,
and have 4 and 2 different commits each, respectively.
  (use "git pull" if you want to integrate the remote branch with yours)

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        Recording 2026-09-18 170931.mp4

nothing added to commit but untracked files present (use "git add" to track)
```

comme on peut le voir, la vidéo a bien été ajouté au dépôt d'essai.

## Premier commit

```
git add .

git commit -m "feat : ajout de la vidéo de 10 mo pour le compte de l'exerciec 11 du srprint 2"

[main 84345a3] feat : ajout de la vidéo de 10 mo pour le compte de l'exerciec 11 du srprint 2
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 Recording 2026-09-18 170931.mp4
 ```

## Retrait du fichier vidéo de 10 mo

```
git status

On branch main
Your branch and 'origin/main' have diverged,
and have 5 and 2 different commits each, respectively.
  (use "git pull" if you want to integrate the remote branch with yours)

Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        deleted:    Recording 2026-09-18 170931.mp4

no changes added to commit (use "git add" and/or "git commit -a")
```

Ce message confirme effectivement le retrait du fichier de 10 mo

## Commit des changements

```
git add .

git commit -m "Retrait de la video de 10 mo"
[main dccda80] Retrait de la video de 10 mo

 1 file changed, 0 insertions(+), 0 deletions(-)
 delete mode 100644 Recording 2026-09-18 170931.mp4
```

## Mesure du dépôt

Su le disque après toutes ces opérations, le dépôt pèse actuellement **9.37 MB (9,834,496 bytes)**

## Conclusion quant à la différence de taille

On observe une très grande différence entre la taille du dépôt initialement de **100 KB (102,400 bytes)** contre **9.37 MB (9,834,496 bytes)** sur le disque une fois les changements de l'exercice effectué. Cela est principalement dû au fait que lors du premier **git add** et **git mit** sur la vidéo  de sur la vidéo de **10.7 mo**, git crée un instantané avec le fichier vidéo suivi qui est associé au commit actuel en compressant un minimum le fichier vidéo. par la suite, lors du second commit, un autre instantané est créé par git, mais cette fois ci plus petit, qui se contente de rendre compte de la délétion du fichier de **10.7 mo**. C'est ce qui explique la différence de poids sur le disque entre les deux états du dépôt d'essai.