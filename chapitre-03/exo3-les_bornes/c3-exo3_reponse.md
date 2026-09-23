# REPONSE DE L'EXERCICE 3

## Redimensionnement de la fenêtre après spécification de la taille minimale

Ici, nous avons spécifié la taille minimale de la fenêtre à du 800 x 600. tel que précisé dans le code minimal suivant aux lignes 13 et 14 :

```cpp
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEvent.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title       =   "Fenetre de l'exercice 3";
    cfg.width       =   1400;
    cfg.height      =   800;
    cfg.minHeight   =   600;
    cfg.minWidth    =   800;

    NkWindow window;
    if (!window.Create(cfg)) {
        logger.Error("[APP] : Erreur de creation de la fenetre");
        return -1;
    }

    while(window.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
            if (e->Is<NkWindowResizeBeginEvent>())
                logger.Info("[Window] : width = {0}     height = {1}", window.GetConfig().width, window.GetConfig().height);
        }
    }

    return 0;
}

```

La taille de la fenêtre est ici là loggée à chaque redimensionnement de celle ci dans la console

- **Construction et lancement** :

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
  1. exo 3 [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exo 3                                                          Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c3-exo3_main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exo 3\exo 3.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.74s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.74s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo3-les_bornes> jenga run

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
  ▶  EXECUTION  —  exo 3.exe
     C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo3-les_bornes\Build\Bin\Debug-Windows\exo 3\exo 3.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-24 00:43:40.460] [INF] [default] [c3-exo3_main.cpp:27 in nkmain] -> [Window] : width = 1398     height = 792
[2026-09-24 00:43:46.662] [INF] [default] [c3-exo3_main.cpp:27 in nkmain] -> [Window] : width = 1319     height = 792
[2026-09-24 00:43:52.781] [INF] [default] [c3-exo3_main.cpp:27 in nkmain] -> [Window] : width = 857     height = 740
[2026-09-24 00:44:04.564] [INF] [default] [c3-exo3_main.cpp:27 in nkmain] -> [Window] : width = 782     height = 553

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (119.25s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

- **Observations faites** : Lorsque l'on essaie de réduire la taille de la fenêtre, le curseur de la souris s'arrête à une taille fixe de la fenêtre, qui semble grandement ressembler à la taille décrite dans la structure de configuration (la dernière valeur loggée dans le terminal). Cet écart entre les valeur loguée et la valeur minimal définie dans la configuration de la fenêtre est du au faut que les valeurs de `window.GetConfig().width` et `window.GetConfig().height` n'évaluent que la taille de la zone cliente. dans quel cas, la fenêtre fait exactement **800X600** pixels.

## Redimentionnement de la fenêtre sans spécification de taille limite

Ici nous retirerons préalablement les deux dernière lignes de configuration suivantes :

```cpp
cfg.minHeight   =   600;
cfg.minWidth    =   800;
```
Ce aui nous laisse avec un fichier source dans l'état actuel :

```cpp
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEvent.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title       =   "Fenetre de l'exercice 3";
    cfg.width       =   1400;
    cfg.height      =   800;

    NkWindow window;
    if (!window.Create(cfg)) {
        logger.Error("[APP] : Erreur de creation de la fenetre");
        return -1;
    }

    while(window.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
            if (e->Is<NkWindowResizeBeginEvent>())
                logger.Info("[Window] : width = {0}     height = {1}", window.GetConfig().width, window.GetConfig().height);
        }
    }

    return 0;
}

```

- **Contruction et lancement** :

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
  1. exo 3 [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exo 3                                                          Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c3-exo3_main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exo 3\exo 3.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.49s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.49s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo3-les_bornes> jenga run

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
  ▶  EXECUTION  —  exo 3.exe
     C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo3-les_bornes\Build\Bin\Debug-Windows\exo 3\exo 3.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-24 00:51:13.487] [INF] [default] [c3-exo3_main.cpp:25 in nkmain] -> [Window] : width = 1196     height = 620
[2026-09-24 00:51:14.760] [INF] [default] [c3-exo3_main.cpp:25 in nkmain] -> [Window] : width = 1102     height = 534
[2026-09-24 00:51:15.984] [INF] [default] [c3-exo3_main.cpp:25 in nkmain] -> [Window] : width = 1037     height = 488
[2026-09-24 00:51:17.321] [INF] [default] [c3-exo3_main.cpp:25 in nkmain] -> [Window] : width = 944     height = 404
[2026-09-24 00:51:18.445] [INF] [default] [c3-exo3_main.cpp:25 in nkmain] -> [Window] : width = 793     height = 323
[2026-09-24 00:51:19.593] [INF] [default] [c3-exo3_main.cpp:25 in nkmain] -> [Window] : width = 625     height = 253
[2026-09-24 00:51:20.616] [INF] [default] [c3-exo3_main.cpp:25 in nkmain] -> [Window] : width = 519     height = 209
[2026-09-24 00:51:27.043] [INF] [default] [c3-exo3_main.cpp:25 in nkmain] -> [Window] : width = 148     height = 43
[2026-09-24 00:51:29.764] [INF] [default] [c3-exo3_main.cpp:25 in nkmain] -> [Window] : width = 148     height = 43
[2026-09-24 00:51:33.241] [INF] [default] [c3-exo3_main.cpp:25 in nkmain] -> [Window] : width = 148     height = 43

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (35.31s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

- **observations faites** : La fenêtre dans ce cas présent est redimensionnable déjà au delà de la limite de 800 x 600 imposée dans le premier test. PAr ailleurs, elle admet une dimension minimale imposée par le système de **148 x 43** pour la zone cliente.