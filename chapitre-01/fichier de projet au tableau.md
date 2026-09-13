# PRESENTATION D'UN FICHIER .JENGA : Cas du MyProject.jenga de l'exercice 7

## Introduction

Un fichier .jenga est un programme python permettant d'orchestrer la construction de n'importe quel projet en c, c++ ,objective c, c++ et Rust. Dans ce document, nous présenterons le `MyProject.jenga` issu de `MysProject` un dossier de projet créé dans l'exercice 7 de la deuxième série du sprint 1. Nous verrons ensemble : pourquoi utiliser un fichier .jenga, ce qu'il déclare, ce qu'il filtre, et ce qu'il délègue.

## Pourquoi utiliser un fichier .jenga ?
les fichiers .jenga sont des de simples programmes écrits en syntaxe python qui décrit des projets c/c++, et permettant de faciliter l'organisation des tâches de compilation de façon aussi, ou voir plus efficace que des outils tel ques Cmake ou premake. Cela comprend:
- la création de bibliothèques staiques;
- la création de bibliothèques dynamique;
- la construction de tests unitaires;
- la production de programmes exécutables sur de multiples plateformes dont IOS, Android, Windows, MacOS, HarmonyOS et Linux.

Et si avec Jenga toutes ces tâches paraissent si simple, c'est parce que contenu de fichiers .jenga est l'une des chose les plus faciles à manipuler.

## Présentation du contenu dun fichier .jenga

Un fichier .jenga peut être rempli suivant deux modèles selon les préférences des utilisateurs. C'est notamment: l'imbrication des projets dans seul fichier, et l'usage d'inclusions externes. Dans les deux cas, les rôles des fonctions restent les mêmes. Seule la lisibilité change. Nous explorerons par la suite uniquement le premier modèle, tel que présenté ci dessous:

```py
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
from Jenga import * 
from Jenga.GlobalToolchains import RegisterJengaGlobalToolchains

with workspace("exercice6") :
    RegisterJengaGlobalToolchains()
    configurations(["Debug", "Release"])
    targetoses([
        TargetOS.WINDOWS,
            TargetOS.LINUX
        ])
    targetarchs([
        TargetArch.X86_64,
        TargetArch.ARM64
    ])

    cppcompiler("clang++")
    ccompiler("clang")
    
    startproject("Simul")

    with project("maths"):
        staticlib()
        language("C++")
        cppdialect("C++17")
        files(["maths.cpp"])
        includedirs(["./"])


    with project("Entity"):
        staticlib()
        language("C++")
        cppdialect("C++17")
        files(["Entity.cpp"])
        includedirs(["./"])

        dependson(["maths"])

    with project("world"):
        staticlib()
        language("C++")
        cppdialect("C++17")
        files(["world.cpp"])
        includedirs(["./"])

        dependson(["maths", "Entity"])

    with project("Simulation"):
        consoleapp()
        language("C++")
        cppdialect("C++17")
        files(["src/**.cpp"])

        dependson(["maths", "Entity", "world"])

        with filter("config:Debug"):
            symbols(True)
            optimize("OFF")
            defines(["_DEBUG", "DEBUG"])

        with filter("config:Release"):
            symbols(False)
            optimize("Speed")
            defines("NDEBUG")
```

### Ce qu'un .jenga déclare

Un fichier .Jenga déclare principalement deux choses: un **workspace**, un ou plusieurs **projets** et des **filtres**.

-**Le workspace**: C'est un bloc dans lequel est précisé les informations relatives à le ou les environnement(s) qui devra (devront) acceuillir l'exécutable final, mais aussi l'ensembles des projets et filtres conditionnant le comportement de jenga face à des situations spécifiques:
```py
with workspace("exercice6") :
    RegisterJengaGlobalToolchains()
    configurations(["Debug", "Release"])
    targetoses([
        TargetOS.WINDOWS,
            TargetOS.LINUX
        ])
    targetarchs([
        TargetArch.X86_64,
        TargetArch.ARM64
    ])

    cppcompiler("clang++")
    ccompiler("clang")
    
    startproject("Simul")
    ...
```
Il comprends donc pour ce faire, les Systèmes d'exploitation et architechtures ciblés, le compilateur ou SDK à utiliser dans le cas des progrrammes sur mobile et le projet principal à lancer. 

- **Les projets**: Ils définissent la nature du resultat qui sera obtebu pour un module spécifique d'un projet. Ils définissent pour leur par le **type**, le **langage** et les fichiers **sources** et **entête** s'il y en a. C'est ici qu'est décidé si'un module est une bibliothèque statique, grâce à la fontion `staticlib()`. Elle permet de dire explicitement à jenga que : le type de sortie du projet à la fin de sa contruction sera une bibliothèque statique (**.lib** sous windows, ou **.a** sous linux)

```py
with project("maths"):
    staticlib()
    language("C++")
    cppdialect("C++17")
    files(["maths.cpp"])
    includedirs(["./"])
```

### Ce qu'un .jenga filtre

Jenga permet en effet la compilation cross platform et la distribution des applications produits. Mais pour ce faire, il lui est bien souvent nécessaire de filtrer un certain nombre d'informations. Cette tâche dans les `.jenga` est attribuée à la fontion `filter`.

- les **Filtres** : Il définissent un comportement de Jenga selon des situations précise (la configuration, le système d'exploitation, ou encore l'architechture):

```py
    with filter("config:Debug"):
        symbols(True)
        optimize("OFF")
        defines(["_DEBUG", "DEBUG"])
```

### Ce qu'un .jenga délègue

Le fichier .jenga ne se coontente que de définir le comportement de l'outil selon les objectifs de l'utilisateur. Il délègues donc certaines tâches dont:

- la compilation des  fichiers sources : il ne remplace pas les compilateurs clang++ et g++;
- le packaging avec des logiciels tels que `inno setup`
- l'application d'iconnes aux exécutables: il utilise WRC, ou llvm-rc

# Conclusion
En définitive, les fichiers .jenga sont comme des panneau de contrôle écris en python, permettant de compiler efficacement, et distribuer n'importe quel projet c/c++.