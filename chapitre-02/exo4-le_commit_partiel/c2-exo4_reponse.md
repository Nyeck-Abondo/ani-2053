# REPONSE DE L'EXERCICE 4 DU CAPITRE 02

> le dépôt utilisé pour cet exercice est toujours `ex2`, contenant les fichier sources f1; f2 et f3.cpp. Le fichier modifié ici est cette fois ci `f3.cpp`

## Etat de départ du fichier `f3.cpp`

```cpp
#include <iostream>

int main() {
    return 0;
}
```

## Etat  après modification

La définition de la fonction template Add a été ajouté entre la ligne 2 et 6, et son appel a été effectué à la ligne 8 dans la fonction `main()`.

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

## Commit du bloc de définition de la fonction template `Add()`

- commande tapée:
```
git add -p
```

- resultat :

```shell
diff --git a/f3.cpp b/f3.cpp
index e007ae9..5569f31 100644
--- a/f3.cpp
+++ b/f3.cpp
@@ -1,8 +1,10 @@
 #include <iostream>
 template <typename T>
-
+T Add(T a, T b) {
+    return a + b;
+}
 
 int main() {
-    
+    Add(10, 15);
     return 0;
 }
\ No newline at end of file
```

- dissociation des deux blocs de modifications et indexation de la modification de l'ajout de la définition de la fonction template:

```shell
(1/1) Stage this hunk [y,n,q,a,d,s,e,p,P,?]? s
Split into 2 hunks.
@@ -1,5 +1,7 @@
 #include <iostream>
 template <typename T>
-
+T Add(T a, T b) {
+    return a + b;
+}
 
 int main() {
(1/2) Stage this hunk [y,n,q,a,d,k,K,j,J,g,/,e,p,P,?]? y
```

- commit du changement :

```
git commit -m "feat: ajout une seconde fois de la fonction Template Add
>
>Cette fonction ne sert que de modification pour la complétion de l'exercice 4 du chapitree 2"
```
## Commit du bloc d'appel de la fonction Template `Add` dans le main()

- commande utilisée :

```
git add -p
```

- acceptation de l4indexation du changement :

```shell
diff --git a/f3.cpp b/f3.cpp
index 360f889..5569f31 100644
--- a/f3.cpp
+++ b/f3.cpp
@@ -5,6 +5,6 @@ T Add(T a, T b) {
 }
 
 int main() {
-    
+    Add(10, 15);
     return 0;
 }
\ No newline at end of file
(1/1) Stage this hunk [y,n,q,a,d,e,p,P,?]? y
```

- commit de la modification :

```
git commit -m "appel de la fonction Template Add dans le int main()" 
```

## Log de historique des commits réalisés

```
PS C:\Users\Administrator\Documents\Github\ex2> git log --oneline
78cf9af (HEAD -> main) appel de la fonction Template Add dans le int main()
5a1ff63 feat: ajout une seconde fois de la fonction Template Add
```

comme on peut l'observer, chaque modification internes du ficheier `f3.cpp` contient son propre sujet. Ce qui nous permet de comprendre que la commande `fit add -p` permet d'indexer des modification et de poser des commits différents afin de garantir un sujet unique par modifications significatives.