# REPONSE DE L'EXERCICE 2

> Le contenu des reponses est tiré du dépot créé dans l'exercice 1. `ex2`

Le fichier modifié dans le dépôt est f2.cpp

- avant modification:

```cpp
#include <iostream>

int main() {
    return 0;
}
```

- après modification :

```cpp
#include <iostream>

int main() {
    int q;
    return 0;
}
```

## Obeservations

### **après modification**

commande tapée:
```
git status
```
cette commande a été exécutée à la racine du projet.

- resultat:

```
PS C:\Users\Administrator\Documents\Github\ex2> git status
On branch main
Your branch is ahead of 'origin/main' by 3 commits.
  (use "git push" to publish your local commits)

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   f2.cpp

no changes added to commit (use "git add" and/or "git commit -a")
```

### **Après un git add .**

commandes tapées dqns l'ordre:

```
git add

git status
```

reultat du `git status` :

```
PS C:\Users\Administrator\Documents\Github\ex2> git status
On branch main
Your branch is ahead of 'origin/main' by 3 commits.
  (use "git push" to publish your local commits)

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   f2.cpp
```

### **Après git commit**

commandes exécutés dans l'ordre :

```
git commit -m "feat: modification de f2.cpp.
>>
>> La modification de f2.cpp est une condition nécessaire pour pouvoir étudier les messages envoyés par git status tel que demandé dans l'ecercice 2 du chapitre 2 du sprint 2 du l'UE ANI-2053.
>> f2.cpp contient maintenant une déclaration inutilisée de variable de type integer."
```

```
git status
```

- resultat de `git commit` :

```
[main dc3cd75] feat: modification de f2.cpp.
 1 file changed, 1 insertion(+)
PS C:\Users\Administrator\Documents\Github\ex2> git status
On branch main
```

- resultat de la commande `git status`:

```
On branch main
Your branch is ahead of 'origin/main' by 4 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
```

## Changements observés entre les trois sorties

- Entre la première et la deuxième sortie, les fichier `f2.cpp` est détecté comme étant modifié. Sa version du précédent commit est indexée, mais pas celle qui vient d'être modifiée

- La seconde sortie permet de nous dire que la verison modifiée de `f2.cpp` a bien été indexée par git sur le dépôt local et que la modification est prête à être validée.

- la troisième, nous indique que la modification a été validée sur la branche spécifique et que le commit est prêt à être envoyé sur le dépôt distant.