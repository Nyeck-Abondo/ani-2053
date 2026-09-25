# REPONSE DE L'EXERCICE 6

> Les deux volets de la question de l'exercice 6 seront traités à la base dans le même fichier, qui est celui demandé pat l'exercice. Toute fois, il existera tout de même au même emplacement un fichier du nom de `exo6` qui conservera une version comparable des deux versions de code demandées.

## Création des septs zones survolable avec les différents types de curseurs de la soursi

Ici, nous utiliserons cette première verison du fichier source, qui sera d'ailleurs celle conservée dans le fichier demandé par l'exercice et envoyé sur le dépôt distant pour ecamination.

- Etqt du fichier source:

```cpp
#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

NKENTSEU_DEFINE_APP_DATA(([]() {
    NkAppData d{};
    d.appName    = "MonJeu";
    d.appVersion = "0.1.0";
    return d;
})());

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.width   =   1280;
    cfg.height  =   720;
    cfg.title   =   "exerceice6";

    NkWindow window;
    if(!window.Create(cfg)) {
        logger.Error("[APP] : Erreur de creation de la fenetre");
        return -1;
    }

    while (window.IsOpen()) {
        while(NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
            if(auto* mouse = e->As<NkMouseMoveEvent>()) {
                if (mouse->GetX() < window.GetSize().width / 7) {
                    window.SetCursor(NkWindow::NkCursorType::Arrow);
                }
                if (mouse->GetX() >= window.GetSize().width / 7 && mouse->GetX() < window.GetSize().width * 2 / 7) {
                    window.SetCursor(NkWindow::NkCursorType::Hand);
                }
                if (mouse->GetX() >= window.GetSize().width * 2 / 7 && mouse->GetX() < window.GetSize().width * 3 / 7) {
                    window.SetCursor(NkWindow::NkCursorType::ResizeNESW);
                }
                if (mouse->GetX() >= window.GetSize().width * 3 / 7 && mouse->GetX() < window.GetSize().width * 4 / 7) {
                    window.SetCursor(NkWindow::NkCursorType::ResizeNS);
                }
                if (mouse->GetX() >= window.GetSize().width * 4 / 7 && mouse->GetX() < window.GetSize().width * 5 / 7) {
                    window.SetCursor(NkWindow::NkCursorType::ResizeNWSE);
                }
                if (mouse->GetX() >= window.GetSize().width * 5 / 7 && mouse->GetX() < window.GetSize().width * 6 / 7) {
                    window.SetCursor(NkWindow::NkCursorType::ResizeWE);
                }
                if (mouse->GetX() >= window.GetSize().width * 6 / 7) {
                    window.SetCursor(NkWindow::NkCursorType::TextInput);
                }
            }
        }
    }
    

    return 0;
}
```

LE choix du curseur ici se fait par subdivision de la surface disponible de la fenêtre en très exactement **7** espaces différents et consécutifs. La modification du curseur étant demandé une fois l'espace spécifique pénétré. Ce mécanisme est assuré par le blox de code:

```cpp
if(auto* mouse = e->As<NkMouseMoveEvent>()) {
    if (mouse->GetX() < window.GetSize().width / 7) {
        window.SetCursor(NkWindow::NkCursorType::Arrow);
    }
    if (mouse->GetX() >= window.GetSize().width / 7 && mouse->GetX() < window.GetSize().width * 2 / 7) {
        window.SetCursor(NkWindow::NkCursorType::Hand);
    }
    if (mouse->GetX() >= window.GetSize().width * 2 / 7 && mouse->GetX() < window.GetSize().width * 3 / 7) {
        window.SetCursor(NkWindow::NkCursorType::ResizeNESW);
    }
    if (mouse->GetX() >= window.GetSize().width * 3 / 7 && mouse->GetX() < window.GetSize().width * 4 / 7) {
        window.SetCursor(NkWindow::NkCursorType::ResizeNS);
    }
    if (mouse->GetX() >= window.GetSize().width * 4 / 7 && mouse->GetX() < window.GetSize().width * 5 / 7) {
        window.SetCursor(NkWindow::NkCursorType::ResizeNWSE);
    }
    if (mouse->GetX() >= window.GetSize().width * 5 / 7 && mouse->GetX() < window.GetSize().width * 6 / 7) {
        window.SetCursor(NkWindow::NkCursorType::ResizeWE);
    }
    if (mouse->GetX() >= window.GetSize().width * 6 / 7) {
        window.SetCursor(NkWindow::NkCursorType::TextInput);
    }
}
```
Il exploite l'évènment de déplacement de la souris `NkMouseMoveEvent` en récupérant les coordonnées de la souris dans la zone cliente, et en définissant une forme du curseur adapté à la zone délimitée dans laquelle il se trouve. Il n'utilise que la composante **X** des absisces par pur choix arbitraire. Un choix effectué afin de facilité la division de la fenêtre en zones suffisemment spacieuses.

## Construction et teste du programme -premier volet de l'exercice

>Le programme est testé directement après build et la vidéo associée comme preuve du lancement et du respect des normes de l'exercice par celui ci est contenu dans le dossier `Preuves`.

- **Construction et lancement du programme** :

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo6-les_sept_curseurs> jenga build

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
  1. exercice 6 [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exercice 6                                                     Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c3-exo6_main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exercice 6\exercice 6.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.38s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.38s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo6-les_sept_curseurs> jenga run

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
  ▶  EXECUTION  —  exercice 6.exe
     C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo6-les_sept_curseurs\Build\Bin\Debug-Windows\exercice 6\exercice 6.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (8.41s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```
- **Preuve du test concluant sur la machine**:
<video src="Preuves/premier volet.mp4">


## Teste de la définition du curseur en début de programme

>Dans se cadre ci, le fichier `exo6.cpp` contenant le code du second volet pour une possibilité de comapraison directe a été introduit dans un projet placé dans le workspace de l'exercice. Ce qui justifie les commandes qui vont suivre. Le projet en question a pour nom `exo6`.

- **Etat actuel du .jenga du workspace de l'exercice** :

```py
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# exo6-les_sept_curseurs – Jenga Workspace
# Generated by `jenga workspace` on 2026-09-24 18:34:50

from Jenga import *

with workspace("exo6-les_sept_curseurs"):
    configurations(['Debug', 'Release'])
    targetoses([TargetOS.WINDOWS])
    targetarchs([TargetArch.X86_64])

    useconfig("../NkentseuKit/NkentseuKit.jenga")

    with project("exercice 6") :
        windowedapp()
        files(["./c3-exo6_main.cpp"])
        language("C++")
        usenkentseukit()

    with project("exo6"):
        windowedapp()
        files(["./exo6.cpp"])
        language("C++")
        usenkentseukit()
    
    # Default toolchain (auto-detected)
    # usetoolchain("host-gcc")
    
    # Uncomment to use Unitest testing framework
    # with unitest() as u:
    #     u.Precompiled()
    
    # Add your projects here
    # with project("MyApp"):
    #     consoleapp()
    #     language("C++")
    #     files(["src/**.cpp"])

```

Le curseur dans ce cas précis ne passe plus par une subdivision de l'écran. Il est directement définit par l'objet de type `NKWindow` avant le lancement de la boucle de jeu. Il impose ainsi le tpe de curseur qui sera rencontré tout le long du parcour du curseur sur la zone cliente de la fenêtre. Le fichier source se présente maintenant comme suit :

```cpp
#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

NKENTSEU_DEFINE_APP_DATA(([]() {
    NkAppData d{};
    d.appName    = "MonJeu";
    d.appVersion = "0.1.0";
    return d;
})());

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.width   =   1280;
    cfg.height  =   720;
    cfg.title   =   "exerceice6";

    NkWindow window;
    if(!window.Create(cfg)) {
        logger.Error("[APP] : Erreur de creation de la fenetre");
        return -1;
    }

    //mise plqce du curseur dès le départ
    window.SetCursor(NkWindow::NkCursorType::Hand);
    while(window.IsOpen()) {
        while(NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
        }
    }
    return 0;
}
```

La ligne responsable par le changement du curseur n'est autre que l'instruction :

```cpp
window.SetCursor(NkWindow::NkCursorType::Hand);
```
Elle définit le curseur de l'application comme étant une main.

- **Construction et lancement du programme** :

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo6-les_sept_curseurs> jenga build --target exo6

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
  1. exo6 [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exo6                                                           Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.06s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.06s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo6-les_sept_curseurs> jenga run exo6

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
  ▶  EXECUTION  —  exo6.exe
     C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo6-les_sept_curseurs\Build\Bin\Debug-Windows\exo6\exo6.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (72.84s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

- **Preuve en image du resultat du programme** :

<video src="Preuves/second volet.mp4">