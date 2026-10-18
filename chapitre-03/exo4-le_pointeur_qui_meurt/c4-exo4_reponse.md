# REPONSE DE L'EXERCICE 4

- **But de l'exercice** : L'exercice demande de réutilisé un pointeur sur un évènement déjà consommé et ensuite de corriger ce que l'on observe avec la méthode `PoolEventCopy()`

## Réutilisation du pointeur d'évènement

L'évènement onservé ici est un évènement de pression de clavier sur une touche du clavier, quelle quelle soit.
>le code peut être retrouvé dans le fichier ex4.cpp

```cpp
NkKeyPressEvent* event = nullptr;
    NkClock clock;
    float32 time = 0.f;
    while (win.IsOpen()) {
        float32 dt = clock.Tick().delta;
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>()) {
                win.Close();
            }
            if (auto* key = e->As<NkKeyPressEvent>()) {
                event = key;
                logger.Info("[App] : touche du clavier");
            }
            if(time > 5) {
                logger.Warn("[App] : Utilisation de la copie de l'évènement {0}", NkScancodeToString(event->GetScancode()));
                time = 0.f;
            }
        }
        time += dt;
    }
```

- **Construction et lancement du programme** :

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo4-le_pointeur_qui_meurt> jenga build

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
  1. exo-4-c4 [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exo-4-c4                                                       Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c4-exo4_main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exo-4-c4\exo-4-c4.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.91s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.91s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

- **Lancement du programme** : le code du programme relance l'utilisation du pointeur sur l'évènement de pression de n'importe quelle touche du clavier après 5 secondes d'attente.

Durant l'exécution, une touche du clavier a été frappé, puis j'ai attendu 5 secondes avant d'obtenir la sortie d'erreur plus bas.

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo4-le_pointeur_qui_meurt> jenga run

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
  ▶  EXECUTION  —  exo-4-c4.exe
     C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo4-le_pointeur_qui_meurt\Build\Bin\Debug-Windows\exo-4-c4\exo-4-c4.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[NKLogger] niveau=info | console=debug | journal=C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo4-le_pointeur_qui_meurt\logs\app.log
[NKLogger] trace/debug sont SOUS le niveau : NK_LOG_LEVEL=debug pour les voir ; NK_LOG_CONSOLE=1 pour tout mettre a l'ecran ; NK_LOG_QUIET=1 pour taire ces deux lignes.
[2026-09-30 21:47:29.546] [INF] [default] [c4-exo4_main.cpp:31 in nkmain] -> [App] : touche du clavier
[2026-09-30 21:47:33.630] [WRN] [default] [c4-exo4_main.cpp:34 in nkmain] -> [App] : Utilisation de la copie de l'evenement SC_J
[2026-09-30 21:47:37.720] [INF] [default] [c4-exo4_main.cpp:31 in nkmain] -> [App] : touche du clavier
[2026-09-30 21:47:38.941] [WRN] [default] [c4-exo4_main.cpp:34 in nkmain] -> [App] : Utilisation de la copie de l'evenement SC_R

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (13.60s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```
Le pointeur recopié de la trame effectuée cinq secondes au paravant apparait ici. on l'observe notemment avec la pression de la touche J et de la touche R.

## Provocation du cas où deux évènements arrivent dans la même trame

- **Etat du code** : Ici, un second appel de PollEvent a été fait dans la boucle d'évènement pour traiter l'évènement suivant de la file. le code suivqnt peut être retrouvé dans le fichier `exo4.cpp`.

```cpp
#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKTime/NkClock.h"
#include "NKMemory/NkUniquePtr.h"

using namespace nkentseu;

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title       =   "C4-exercice 3";
    cfg.width       =   1280;
    cfg.height      =   720;

    NkWindow win(cfg);
    if(!win.IsOpen()) {
        logger.Error("[Window] : Erreur de creation de la fenêtre");
        return -1;
    }

    NkEvent* event = nullptr;
    NkClock clock;
    float32 time = 0.f;
    while (win.IsOpen()) {
        float32 dt = clock.Tick().delta;
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>()) {
                win.Close();
            }
            event = NkEvents().PollEvent();
            if (auto* p = event->As<NkKeyPressEvent>()) {
                logger.Warn("Seconde Evenement dans la même frame");
            }
            if (auto* key = e->As<NkKeyPressEvent>()) {
                logger.Info("[App] : touche du clavier");
            }
        }
        time += dt;
    }
    return 0;
}
```

- **Construction du programme** :

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo4-le_pointeur_qui_meurt> jenga build

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
  1. exo-4-c4 [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exo-4-c4                                                       Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exo-4-c4\exo-4-c4.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.42s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.42s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

- **Lancement du programme** : Le lancement du programme, dès le premier évènement de pression du clavier entraine une freeze du programme, avec une sortie d'erreur de code **3221225477**, marquant un arrêt forcé.

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo4-le_pointeur_qui_meurt> jenga run  

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
  ▶  EXECUTION  —  exo-4-c4.exe
     C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo4-le_pointeur_qui_meurt\Build\Bin\Debug-Windows\exo-4-c4\exo-4-c4.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine avec le code 3221225477  (33.29s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

## Correction avec `PollEventCopy()`

- **Modifications apportées au code** : Afin de corriger cette erreur avec pollEventCopy, le code a été modifié à un seul endroit.
```

- **Construction** :

```

```

- **Lancement du programme** : le programme a aussi été exécuté dans les mêmes conditions que le premier tes. La touche Q du clavier QWERTY a été tapée une seule fois, puis 5 secondes d'attente ont été faites avant d'observer la sortie du terminal.

```

```