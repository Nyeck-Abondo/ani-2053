# REPONSE DE LA DEMO 2

> Le dépôt utilisé ici restera le dépôt d'essai dans son état tel qu'il sera décrit plus bas. Par ailleurs, le dépôt secondaire à été mis à jour pour ganger en temps. Il se situe ainsi au même niveau d'avancement que le dépôt initial.

## Etat inital du dépôt d'essai

Cet état est partagé par les deux dépôts (le dépôt **initial** et le dépôt **secondaire**)
- f1.cpp

```cpp
#include <iostream>

int main() {
    float p = 12;
    return 12;
}
```

- f2.cpp :

```cpp
#include <iostream>

int main() {
    int q = 1;
    float c = 11;
    double q = 20;
    return 0;
}
```

- f3.cpp :

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

## Modification effectuées sur f2.cpp sur le dépôt initial

Les modifications apportées à la ligne 6 dans le dépôt initial. Tout se passe sur la branche main :

```
git branch

* main
  test-exo10
```

```cpp
#include <iostream>

int main() {
    int q = 1;
    float c = 11;
    double z = 20;
    return 0;
}
```

- indexation et validation des modification :

```
git add .

git commit -m "feat : modification du fichier f2.cpp dans la branche main du dépôt initial"

[main d977c3a] feat : modification du fichier f2.cpp dans la branche main du dépôt initial
 1 file changed, 1 insertion(+), 1 deletion(-)
```

- Poussée des changements sur le épôt distant :

```
git push

Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 12 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 341 bytes | 341.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/Nyeck-Abondo/ex2.git
   8f6e44a..d977c3a  main -> main
```

L'opérations'est déroulée sans soucis

## Modification effectuées sur f2.cpp sur le dépôt secondaire

- vérification de la branche :

```
git branch -a 

* main
  remotes/origin/HEAD -> origin/main
  remotes/origin/Testbranch
  remotes/origin/main
  remotes/origin/test-exo10
```

- Modification apportées à la ligne 6 : q passe à f

```cpp
#include <iostream>

int main() {
    int q = 1;
    float c = 11;
    double f = 10;
    return 0;
}
```

- VAlidation et indexation des modifications

```
git add .

git commit -m "feat : modification du fichier f2.cpp à la ligne 6 sur le dépôt secondaire"

[main 14c5f9a] feat : modification du fichier f2.cpp à la ligne 6 sur le dépôt secondaire
 1 file changed, 1 insertion(+), 1 deletion(-)
```

##  Provocation du rejet dans le dépôt secodaire

```
git push

To https://github.com/Nyeck-Abondo/ex2.git
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'https://github.com/Nyeck-Abondo/ex2.git'
hint: Updates were rejected because the remote contains work that you do not
hint: have locally. This is usually caused by another repository pushing to
hint: the same ref. If you want to integrate the remote changes, use
hint: 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```

## Identification et correction du conflit

- Identification du conflit :

```
git pull
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (1/1), done.
remote: Total 3 (delta 2), reused 3 (delta 2), pack-reused 0 (from 0)
Unpacking objects: 100% (3/3), 321 bytes | 24.00 KiB/s, done.
From https://github.com/Nyeck-Abondo/ex2
   8f6e44a..d977c3a  main       -> origin/main
Auto-merging f2.cpp
CONFLICT (content): Merge conflict in f2.cpp
Automatic merge failed; fix conflicts and then commit the result.
```

- correction du conflit :

```cpp
#include <iostream>

int main() {
    int q = 1;
    float c = 11;
<<<<<<< HEAD
    double f = 10;
=======
    double z = 20;
>>>>>>> d977c3a2d29571780d84a05d2d1613279060c5d6
    return 0;
}
```
ici, la seconde modification, celle qui vient du dépôt secondaire **z = 20** sera retenue. On obtient ainsi un fichier f2:

```cpp
#include <iostream>

int main() {
    int q = 1;
    float c = 11;
    double z = 20;
    return 0;
}
```

- indexation et validation du fichier résolu :

```
git add .

git commit -m "fix: Résolution du conflit entre le dépôt initial et le dépôt secondaire"

[main 2fc7b07] fix: Résolution du conflit entre le dépôt initial et le dépôt secondaire
```

- poussée sur le dépôt principal :

```
git push

Enumerating objects: 8, done.
Counting objects: 100% (8/8), done.
Delta compression using up to 12 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (4/4), 600 bytes | 600.00 KiB/s, done.
Total 4 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/Nyeck-Abondo/ex2.git
   d977c3a..2fc7b07  main -> main
```

LE conflit a été résolu sans aucun souci et en moins de 10 minutes.