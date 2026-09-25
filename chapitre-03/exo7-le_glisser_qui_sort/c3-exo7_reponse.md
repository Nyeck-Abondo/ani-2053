# REPONSE DE L'EXERCICE 7

> Dans cet exercice faute de pouvoir suivre directement les modifications apportées sur la fenêtre , nous utiliserons tout simplement le logger pour pouvoir suivre les modifications de chaque version du code .

## Utilistion de la capture de la souris

- **Etat initial du fichier source** :

```cpp
#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkMouseEvent.h"
#include "NKEvent/NkKeyboardEvent.h"
#include "NKTime/NkClock.h"

using namespace nkentseu;

NKENTSEU_APP_DATA_DEFINED(([] () {
    NkAppData d {};
    d.appName   =   "Exercice 7";
    d.appVersion    =   "0.1.0";
    return d;
})())

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title       =   "Exercice 7";
    cfg.width       =   1280;
    cfg.height      =   720;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[APP] : Erreur de creation de la fenetre");
        return -1;
    }
    bool isDraging = false;
    NkClock clock;
    float32 logInterval = 0.f;
    while (window.IsOpen()) {
        while(NkEvent* e = NkEvents().PollEvent()) {
            float32 dt = clock.Tick().delta;
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
            if (auto* press = e->As<NkMouseButtonPressEvent>()){
                if (press->IsRight()) {
                    window.CaptureMouse(true);
                    isDraging = true;
                }
            }
            if (auto* press = e->As<NkMouseButtonReleaseEvent>()) {
                if (press->IsRight()) {
                    window.CaptureMouse(false);
                }
            }
            if (auto* move = e->As<NkMouseMoveEvent>()) {
                if (logInterval > 2) {
                    logger.Info("position curseur: ({0} ; {1})", move->GetX(), move->GetY());
                    logInterval = 0.f;
                }
            }
            if (auto* key = e->As<NkKeyPressEvent>()) {
                if (key->GetKey() == NkKey::NK_F) {
                    window.Close();
                }
            }
            logInterval += dt;
        }
    }
    return 0;
}
```

L'utilisation de la capture de la souris se fait à travers la méthode `CaptureMouse` propre à la classe `NKWindow`. La capture de la souris ici est déclenchée par un événement de clic droit de la souris. Le test ici consiste à effectuer un clic droit dans la zone cliente de la fenêtre et de délpasser la souris hors de cette zone cliente, Tout en effectuant le logging toutes les 2.0 secondes environ des différentes positions de la souris. Cette tâche est donc exécutée par le bloc de code ci dessous :

```cpp
    bool isDraging = false;
    NkClock clock;
    float32 logInterval = 0.f;
    while (window.IsOpen()) {
        while(NkEvent* e = NkEvents().PollEvent()) {
            float32 dt = clock.Tick().delta;
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
            if (auto* press = e->As<NkMouseButtonPressEvent>()){
                if (press->IsRight()) {
                    window.CaptureMouse(true);
                    isDraging = true;
                }
            }
            if (auto* move = e->As<NkMouseMoveEvent>()) {
                if (logInterval > 2) {
                    logger.Info("position curseur: ({0} ; {1})", move->GetX(), move->GetY());
                    logInterval = 0.f;
                }
            }
            if (auto* key = e->As<NkKeyPressEvent>()) {
                if (key->GetKey() == NkKey::NK_F) {
                    window.Close();
                }
            }
            logInterval += dt;
        }
    }

```
- **Mise en évidence du rôle de chaque blocs du code** :
    - Le bloc du logging : Le logging espacé est assuré par la variable `logInetrval` qui est incrémenté grace au deltaTime fourni par la variable `clock` à chaque début de frame, afin d'éviter une surcharge d'informations dans le terminal.

    ```cpp
    if (logInterval > 2) {
        logger.Info("position curseur: ({0} ; {1})", move->GetX(), move->GetY());
        logInterval = 0.f;
    }
    ```
    - Le déclenchement de la capture de la souris : La capture de la souris ne se lance que lorsque la fenêtre reçoit un évènement de clic droit en son sein. Cette mécanique est assurée par le bloc ci dessous :

    ```cpp
    if (auto* press = e->As<NkMouseButtonPressEvent>()){
        if (press->IsRight()) {
            window.CaptureMouse(true);
            isDraging = true;
        }
    }
    ```
    - L'arrêt de la capture de la souris : L'arrêt de la capture de la souris est produit lorsque la fenêtre reçoit l'évènement de relachement de la souris. Cette mécanique est assurée par le bloc :

    ```cpp
    if (auto* press = e->As<NkMouseButtonReleaseEvent>()) {
                if (press->IsRight()) {
                    window.CaptureMouse(false);
                }
            }
    ```

    - La fermeture de la fenêtre : En procédant à ce test, je me suis rendu compte que la fenêtre ne se fermait pas en utilisant le bouton dédié sur la barre de titre. Afin de remédier à ce problème, j'ai assigné à la touche `F` la responsabilité de fermeture propre de la fenêtre.

    ```cpp
    if (auto* key = e->As<NkKeyPressEvent>()) {
            if (key->GetKey() == NkKey::NK_F) {
            window.Close();
        }
    }
    ```

- **Construction et lancement du programme** :

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo7-le_glisser_qui_sort> jenga build --target "exercice 7"

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
  1. exercice 7 [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exercice 7                                                     Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.03s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo7-le_glisser_qui_sort> jenga run "exercice 7"           

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
  ▶  EXECUTION  —  exercice 7.exe
     C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo7-le_glisser_qui_sort\Build\Bin\Debug-Windows\exercice 7\exercice 7.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-25 21:55:30.748] [INF] [default] [c3-exo7_main.cpp:49 in nkmain] -> position curseur: (937 ; 546)
[2026-09-25 21:55:32.748] [INF] [default] [c3-exo7_main.cpp:49 in nkmain] -> position curseur: (1107 ; 350)
[2026-09-25 21:55:34.868] [INF] [default] [c3-exo7_main.cpp:49 in nkmain] -> position curseur: (1470 ; 351)
[2026-09-25 21:55:36.894] [INF] [default] [c3-exo7_main.cpp:49 in nkmain] -> position curseur: (1499 ; 261)
[2026-09-25 21:55:39.022] [INF] [default] [c3-exo7_main.cpp:49 in nkmain] -> position curseur: (-103 ; 541)
[2026-09-25 21:55:41.896] [INF] [default] [c3-exo7_main.cpp:49 in nkmain] -> position curseur: (12 ; 351)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (15.04s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

- **Observations faites** : Après un premier clic droit dans la zone cliente de la fenêtre et maintient de celui ci tout le long, on observe que le terminal log les positions de la souris dans la fenêtre. Lorsque le curseur sort enfin de la zone cliente de la fenêtre, le terminal continu toujours de logger les positions de la souris, sauf que cette fois ci les positions mentionnées dans le terminal vont au delà des dimensions de la fenêtre (`[2026-09-25 21:55:34.868] [INF] [default] [c3-exo7_main.cpp:49 in nkmain] -> position curseur: (1470 ; 351)` au niveau du troisième log). Ce qui ne peut signifier que tant que le bouton droit n'est pas relaché, la fenêtre continue de recevoir les évènements normalement, même si la souris est hors de sa zone cliente.

## Retrait de la capture de la souris

Dans ce cas précis, un nouveau fichier nommé `exo7.cpp` a été ajouté dans le dossier de l'exercie. Il contient la seconde version du code à étudier dans le cas de l'ommission de la capture de la souris. 

```cpp
#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkMouseEvent.h"
#include "NKEvent/NkKeyboardEvent.h"
#include "NKTime/NkClock.h"

using namespace nkentseu;

NKENTSEU_APP_DATA_DEFINED(([] () {
    NkAppData d {};
    d.appName   =   "Exercice 7";
    d.appVersion    =   "0.1.0";
    return d;
})())

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title       =   "Exercice 7";
    cfg.width       =   1280;
    cfg.height      =   720;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[APP] : Erreur de creation de la fenetre");
        return -1;
    }
    bool isDraging = false;
    NkClock clock;
    float32 logInterval = 0.f;
    while (window.IsOpen()) {
        while(NkEvent* e = NkEvents().PollEvent()) {
            float32 dt = clock.Tick().delta;
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
            if (auto* move = e->As<NkMouseMoveEvent>()) {
                if (logInterval > 2) {
                    logger.Info("position curseur: ({0} ; {1})", move->GetX(), move->GetY());
                    logInterval = 0.f;
                }
            }
            if (auto* key = e->As<NkKeyPressEvent>()) {
                if (key->GetKey() == NkKey::NK_F) {
                    window.Close();
                }
            }
            logInterval += dt;
        }
    }
    return 0;
}
```
Ici le clic droit de la souris ne fait plus rien.

- **Contruction et lancement du programme** :

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo7-le_glisser_qui_sort> jenga build --target exo7

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
  1. exo7 [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exo7                                                           Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: exo7.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exo7\exo7.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 6.66s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           6.66s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo7-le_glisser_qui_sort> jenga run exo7           

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
  ▶  EXECUTION  —  exo7.exe
     C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo7-le_glisser_qui_sort\Build\Bin\Debug-Windows\exo7\exo7.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[2026-09-25 22:00:01.872] [INF] [default] [exo7.cpp:39 in nkmain] -> position curseur: (938 ; 380)
[2026-09-25 22:00:03.875] [INF] [default] [exo7.cpp:39 in nkmain] -> position curseur: (1146 ; 352)
[2026-09-25 22:00:05.885] [INF] [default] [exo7.cpp:39 in nkmain] -> position curseur: (1207 ; 222)
[2026-09-25 22:00:12.135] [INF] [default] [exo7.cpp:39 in nkmain] -> position curseur: (1276 ; 328)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (14.93s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

- **Observations faites** : Dans le cadre de ce texte les observations faites sont les suivantes :
    - Le placement du glisser et de la souris dans la zone cliente entraîne bel et bien un log de Sa position dans le terminal .
    - La sortie du glisser de la zone cliente de la fenêtre arrête les logs dans le terminal. Ils ne reprennent que plus tard avec un intervalle de temps extrêmement décalé d'environ 10 à 20 secondes selon le temps d'attente à l'extérieur de la fenêtre, Lorsque le Curseur entre de nouveau dans la zone cliente de la fenêtre.

Ce test nous permet de comprendre que la fenêtre ne reçoit des événements que lorsque le curseur est à l'intérieur de sa zone cliente et aussi lorsqu'elle a encore le focus .

## Différence globale du point de vue de l'utilisateur (LA réponse à la question)

Du point de vue de l'utilisateur la différence qui se pose ici entre l'usage et la capture de la souris et son omission, est que la capture de la souris permet à la fenêtre de continuer de traiter des évènements de la souris même lorsque le curseur n'est plus dans la zone cliente. C'est un atout qui garanti une certain confort. Dans le cas où un utilisateur porterait un objet de la fenêtre et le ferait sortir de celle ci sans le vouloir, il aura encore la possibilité d'annuler son action en revenant le déposer dans celle ci tant qu'il ne relâche pas la touche de la souris qui active la capture. Contrairement à l'omission de cet fonctionnalité, qui oblige le curseur à être dans la zone cliente de la fenêtre pour traiter les évènements relatifs à la souris.