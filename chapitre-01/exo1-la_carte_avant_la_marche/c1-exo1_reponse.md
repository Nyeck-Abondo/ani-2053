# Analyse des informations fournies dans le dépôt de Nkentseu

> Dans le dépôt de nkentseu, après le lancement de la commade `jenga info`, il a été retourné en sortie dans le terminal un nombre varié d'informations.

## occurence par types de projets
Le dépôt de Nkentseu présente 4 types de projets, **ConsoleApp**, **WindowedApp**, **StaticLib**, et **TestSuite** répartis comme suit :

- **ConsoleApp** : 64 projets
- **WindowedApp** : 52 projets
- **StaticLib** : 55 projets
- **TestSuite** : 64 projets

pout un **total de**: 235 projets

## Nombre de chqines de compilation
le dépot présete aussi une diversité de chaines de compilation (**ToolChains**). Ces chaines de compilations se compte au nombre de:  **7**.  Ce chiffre est exclusivement dépendant de la machine qui l'exécute car la commande `jenga info` renvoie les chaines de compilation disponibles sur la machine hôte.

- **host-clang**
- **host-gcc**
- **clang-mingw**
- **mingw**
- **clang-cross-linux**
- **android-ndk**
- **emscripten**

## Projet de démarrage
le projet de démarrage est `Sandbox`

## Fichier racine du workspace

c'est le fichier `Nkentseu.jenga`