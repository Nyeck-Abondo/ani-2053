# REPONSE DE L'EXERCICE 7

> Cet exercice utilise le dépôt expérimental créér depuis l'exercice 1 ou 2 environ: `ex2` présent à l'adresse https://github.com/Nyeck-Abondo/ex2.git . Il utilisera aussi les deux dépôts locaux créés pour l'exercice 6 pour simuler le travail collaboratif

## Etat du dépôt avant quelconques modifications

Le fichier à modifier restera toujours le fichier `f1.cpp` qui se trouve à la racine du dépôt

```cpp
#include <iostream>

int main() {
    float p = 3;
    return 0;
}
```
conformément aux modifications de l'exercice précédent.


## Modification des lignes dans les dépôts locaux

- **Dans le dépôt inital** :

    - modification de la ligne 6 de f1.cpp :

    ```cpp
    #include <iostream>

    int main() {
        float p = 3;
        return 5;
    }
    ```
    - Commit et push de la modification:

    ```

    ```


- **Dans le dépôt secondaire** :

    - Modification du contenu de f1.cpp à la ligne 4:

    ```cpp
    #include <iostream>

    int main() {
        float p = 10;
        return 0;
    }
    ```

    - mise à jours

    ```
    git pull

    remote: Enumerating objects: 5, done.
    remote: Counting objects: 100% (5/5), done.
    remote: Compressing objects: 100% (1/1), done.
    remote: Total 3 (delta 2), reused 3 (delta 2), pack-reused 0 (from 0)
    Unpacking objects: 100% (3/3), 329 bytes | 54.00 KiB/s, done.
    From https://github.com/Nyeck-Abondo/ex2
    be257e7..3842571  main       -> origin/main
    Updating be257e7..3842571
    Fast-forward
    f1.cpp | 2 +-
    1 file changed, 1 insertion(+), 1 deletion(-)
    ```

    - mise à jour de f1.cpp :
    
    ```cpp
    #include <iostream>

    int main() {
        float p = 10;
        return 5;
    }
    ```
    On peut remarquer ici que la modification effectuée dans le dépôt principal n'a modifié que la ligne concernée

    - poussée du contenu du dépôt secondaire :
    ```
    git push

    Enumerating objects: 5, done.
    Counting objects: 100% (5/5), done.
    Delta compression using up to 12 threads
    Compressing objects: 100% (3/3), done.
    Writing objects: 100% (3/3), 351 bytes | 351.00 KiB/s, done.
    Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
    remote: Resolving deltas: 100% (1/1), completed with 1 local object.
    To https://github.com/Nyeck-Abondo/ex2.git
    3842571..703e420  main -> main
    ```

    - Mise à jour du contenu du dépôt initial :

    ```
    git pull

    remote: Enumerating objects: 5, done.
    remote: Counting objects: 100% (5/5), done.
    remote: Compressing objects: 100% (2/2), done.
    remote: Total 3 (delta 1), reused 3 (delta 1), pack-reused 0 (from 0)
    Unpacking objects: 100% (3/3), 331 bytes | 30.00 KiB/s, done.
    From https://github.com/Nyeck-Abondo/ex2
    3842571..703e420  main       -> origin/main
    Updating 3842571..703e420
    Fast-forward
    f1.cpp | 2 +-
    1 file changed, 1 insertion(+), 1 deletion(-)
    ```

    - contenu du dépôt initial après mise à jour: 

    ```cpp
    #include <iostream>

    int main() {
        float p = 10;
        return 5;
    }
    ```

On remarque alors que dans les deux dépôts, la modification de deux endroits distant en l'occurence ici la ligne 6 dans le cas du dépôt **initial** et de la ligne 4 dans celui du dépôt **secondaire**, est gérée de façon automatique pat git avec la délétion et l'ajout des modifications rencontrées.