# REPONSE DE L'EXERCICE 4

>Pour cet exercicem nous considèrerons le programme minimal de `c3-exo4_main.cpp`. Les différentes données seront explicitement présentées en sortie de logger dans le teminal.

En se basant sur la documentation de windows sur la hauteru de la zone non cliente de windows présente sur le lien ci contre https://learn.microsoft.com/en-us/windows/apps/design/basics/titlebar-design . J'ai approximé la taille de la barre de titre standard à environ 32 pixels. La largeur de celle ci étant la même que celle de la zone cliente, aucune approximation n'a été faite sur la largeur de la barre de titre.

- **construction et lancement de l'exécutable** :

```
jenga build

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

Loading workspace...

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (1 projects):
  1. exercice 4 [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exercice 4                                                     Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c3-exo4_main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exercice 4\exercice 4.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.31s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.32s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo4-le_facteur_d_echelle> jenga run  

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  exercice 4.exe
     C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo4-le_facteur_d_echelle\Build\Bin\Debug-Windows\exercice 4\exercice 4.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-24 02:18:54.563] [INF] [default] [c3-exo4_main.cpp:23 in nkmain] -> [Window] : taille rendue par la fenetre: 1278 x 844 
 [Window] : Taille rendue par la cible de rendu: 1278 x 812 
 facteur d'echelle : 1.25
[2026-09-24 02:18:54.564] [INF] [default] [c3-exo4_main.cpp:23 in nkmain] -> [Window] : taille rendue par la fenetre: 1278 x 844 
 [Window] : Taille rendue par la cible de rendu: 1278 x 812 
 facteur d'echelle : 1.25

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (3.23s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

- **Observations Faites** : On observe ici pour chaque valeur mesurée les caractéristiques suivantes pour une fenêtre configurée en **1280 x 820**:
    - **taille rendue par la fenetre** : **1278 x 844**
    - **Taille rendue par la cible de rendu** : 1278 x 812
    - **facteur d'echelle** : 1.25

Le facteur étant différent de 1, la nécessité de poursuivre sur un autre moniteur n'a pas été ressentie.