# REPONSE DE L'EXERCICE 2

- **But de l'exercice :** L'exercice a  pour but de mettre en évidence le comportement observé par l'utilisation des différentes méthodes d'identification des touches du clavier durant le passage entre deux dispositions.

## Etat du programme

Le programme ici se veut minimal. Il ne contient que le stricte minimum pour la création d'une fenêtre, ainsi que des messages de logs pour assurer l'affichage de la lettre de la touchefrappée ainsi que son code physique . Comme l'indique le bloc suivant:

```cpp
if (auto* key = e->As<NkKeyPressEvent>()) {
                logger.Info("Lettre de la touche: {0} -- Code physique: {1}", NkKeyToString(NkKeycodeMap::NkKeyFromWin32VK(key->GetNativeKey())), (uint32)key->GetScancode());
            }
```

## Construction et lancement

- **Construction** : La construction du programme a été rapide et se termine par un succès.

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo2-la_lettre_et_la_position> jenga build

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
  1. exo-2-c4 [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exo-2-c4                                                       Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled with warnings: c4-exo2_main.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                  Warning: c4-exo2_main.cpp                                   ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo2-la_lettre_et_la_po ║
║ sition\c4-exo2_main.cpp:3:10: warning: non-portable path to file '"NKEvent/NkKeycodeMap.h"'; ║
║ specified path differs in case from file name on disk [-Wnonportable-include-path]           ║
║     3 | #include "NkEvent/NkKeycodeMap.h"                                                    ║
║       |          ^~~~~~~~~~~~~~~~~~~~~~~~                                                    ║
║       |          "NKEvent/NkKeycodeMap.h"                                                    ║
║ 1 warning generated.                                                                         ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exo-2-c4\exo-2-c4.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.69s  │
│ Warnings: 2                                                                                  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Warnings:       2
Time:           2.69s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

- **LAncement du programme** : Durant l'exécution du programme, la touche avec la lettre W sur le clavier **QWERTY** de mon appareil a été testé dans différentes dispositions de clavier. Le premier étant la disposition **QWERTY**, par défaut de mon clavier. C'est celle qui a fourni le premier message de log. Le second test en **AZERTY**. C'est lui qui a entrainé le troisième message de log.

    - Le seconde message de log a été entrainé par le raccourci clavier **Windows + Espace**

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo2-la_lettre_et_la_position> jenga run  

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
  ▶  EXECUTION  —  exo-2-c4.exe
     C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo2-la_lettre_et_la_position\Build\Bin\Debug-Windows\exo-2-c4\exo-2-c4.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[NKLogger] niveau=info | console=debug | journal=C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo2-la_lettre_et_la_position\logs\app.log
[NKLogger] trace/debug sont SOUS le niveau : NK_LOG_LEVEL=debug pour les voir ; NK_LOG_CONSOLE=1 pour tout mettre a l'ecran ; NK_LOG_QUIET=1 pour taire ces deux lignes.
[2026-09-29 19:50:16.975] [INF] [default] [c4-exo2_main.cpp:24 in nkmain] -> Lettre de la touche: NK_W -- Code physique 26
[2026-09-29 19:50:23.926] [INF] [default] [c4-exo2_main.cpp:24 in nkmain] -> Lettre de la touche: NK_LSUPER -- Code physique 227
[2026-09-29 19:50:27.525] [INF] [default] [c4-exo2_main.cpp:24 in nkmain] -> Lettre de la touche: NK_Z -- Code physique 26

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (22.81s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

## Observations faites

Les différents messages de log nous permettent de voir un différence flagrante. 
- La lettre d'une touche pressée sur le clavier diffère selon la diposition du clavier. comme indiqué ici pour la pression de la même touche indiquant **W** sur le clavier:

    - En disposition  **QWERTY** :
        ```
        [2026-09-29 19:50:16.975] [INF] [default] [c4-exo2_main.cpp:24 in nkmain] -> Lettre de la touche: NK_W
        ```
    - En disposition **AZERTY** :
        ```
        [2026-09-29 19:50:27.525] [INF] [default] [c4-exo2_main.cpp:24 in nkmain] -> Lettre de la touche: NK_Z
        ```

- Par contre, le code physique du clavier reste le même indépendemment de la disposition du clavier.

    - En disposition  **QWERTY** :
        ```
        [2026-09-29 19:50:16.975] [INF] [default] [c4-exo2_main.cpp:24 in nkmain] -> Lettre de la touche: NK_W -- Code physique 26
        ```
    - En disposition **AZERTY** :
        ```
        [2026-09-29 19:50:27.525] [INF] [default] [c4-exo2_main.cpp:24 in nkmain] -> Lettre de la touche: NK_Z -- Code physique 26
        ```
Le code physique reste toujours 26 quelque soit la disposition.