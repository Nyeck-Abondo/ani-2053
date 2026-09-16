# REPONSE DE L'EXERCICE 5

> Cet exercice repose toujours comme les autres sur le dépôt d'essai créé depuis l'exercice 1. LEs branches seront créée et les fichiers y seront ajoutés.

## Poids actuel du dépot sans aucune branches crées à l'intérieur

- Taille sur le disque : 64.0 KB

- fichier contenu à l'intérieur:

la commande exécutée ici est : 
```
ls
```
```
    Directory: C:\Users\Administrator\Documents\Github\ex2


Mode                 LastWriteTime         Length Name                                        
----                 -------------         ------ ----                                        
-a----         9/16/2026   2:03 PM             53 f1.cpp                                      
-a----         9/16/2026   5:36 PM             65 f2.cpp                                      
-a----         9/17/2026  12:00 AM            135 f3.cpp                                      
-a----         9/16/2026   2:01 PM           1090 LICENSE 
```

ceci constitue la taille sur le disque avant toute modification en lien avec l'exercice.

## Poids après création de la branche et des trois commits

- Création de la branche pour l'exercice:

```
git checkout -b Testbranch
```
on crée la branche, puis on se place directement sur elle.

- Création des fichiers sources du dépôt pour des commits séparés:

    - Création et commit de `test/test1.cpp` :
    
    ```cpp
    #include <iostream>

    int main() {
        return 0;
    }
    ```
    >tous les autres fichiers sources sont déclarés de la même manière que celui ci, ce qui fait que leur contenu ne sera pas présenté par la suite

    commit des changements:
    ```
    git commit -m "ajout du test1.cpp pour le premier commit"

    [Testbranch 4b68b94] ajout du test1.cpp pour le premier commit
    1 file changed, 5 insertions(+)
    create mode 100644 test/test1.cpp
    ```
    - Création et commit de `test/test2.cpp` :
    
    commit des changements:
    ```
    git commit -m "ajout du test2.cpp pour le second commit"   

    [Testbranch 3fbbaac] ajout du test2.cpp pour le second commit
    1 file changed, 5 insertions(+)
    create mode 100644 test/test2.cpp
    ```

    - Création et commit de `test/test3.cpp` :
    
    commit des changements:
    ```
    git commit -m "ajout du test2.cpp pour le troisième commit"

    [Testbranch 1d928b3] ajout du test2.cpp pour le troisième commit
    1 file changed, 5 insertions(+)
    create mode 100644 test/test3.cpp
    ```

- Etat actuel du répertoire après création de la branche :

```
    Directory: C:\Users\Administrator\Documents\Github\ex2


Mode                 LastWriteTime         Length Name                                        
----                 -------------         ------ ----                                        
d-----         9/17/2026  12:36 AM                test                                        
-a----         9/16/2026   2:03 PM             53 f1.cpp                                      
-a----         9/16/2026   5:36 PM             65 f2.cpp                                      
-a----         9/17/2026  12:00 AM            135 f3.cpp                                      
-a----         9/16/2026   2:01 PM           1090 LICENSE                                     


    Directory: C:\Users\Administrator\Documents\Github\ex2\test


Mode                 LastWriteTime         Length Name                                        
----                 -------------         ------ ----                                        
-a----         9/17/2026  12:36 AM             53 test1.cpp                                   
-a----         9/17/2026  12:36 AM             53 test2.cpp                                   
-a----         9/17/2026  12:36 AM             53 test3.cpp
```

- **Taille sur le disque** : 72.0 KB 

## Explication de la différence de taille

Comme on peut le remarquer, la création d'une branche et des commits . Cette différence de poids sur le disque s'explique par le fait que chaque commit est stocké comme un instantané dans le dossier (normalement caché) `.git` qui se trouve dans le dépot local. il stocke l'historique des commits de l'utilisateur.