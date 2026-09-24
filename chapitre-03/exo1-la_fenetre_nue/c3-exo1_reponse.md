# Reponse de l'exercice 1

>L'exercice a été effectué sur un DELL avec le système d'exploitation  windows 11

## Rédaction du plus petit code

programme minimal retenu pour l'exécution et la terminaison propre:

```cpp
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
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
    cfg.title   =   "Fenetre";
    cfg.width   =   1280;
    cfg.height  =   720;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("Erreur de création de la fenêtre.");
        return -1;
    }
    while (window.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
        }   
    }
    return 0;
}
```

- **Preuve de construction et de lancement propre du programme** :

```
jenga build --target window

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
  1. window [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: window                                                         Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c3-exo1_main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\window\window.exe

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

PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo1-la_fenetre_nue> jenga run window

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
  ▶  EXECUTION  —  window.exe
     C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo1-la_fenetre_nue\Build\Bin\Debug-Windows\window\window.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (3.07s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

- **Nombre de lignes de code** : Ce programme comprends exactement **34** lignes, lignes vides comprises.

Numéro de ligne dans l'exercice |Lignes dans l'exercice | numro de ligne dans le cours| lignes dans le cours | correspondences 
| -- | -- | --| --| --|
**1** | `#include "NKWindow/NKWindow.h"` | **1** | `#include "NKWindow/NKWindow.h"`| ces deux lignes permettent l'utilisation des types relatifs à la création de la fenêtre tels que `NkWindowConfig` et `NKWindow`
**2** | `#include "NKWindow/NKMain.h"` | **2** | `#include "NKWindow/NKMain.h"`| Cette ligne permet d'utiliser le point d'entré du framework Nkentseu
**15** | `int nkmain(const NkEntryState& state) {` | **4** | `int nkmain(const NkEntryState& state) {` | cette ligne définit le point d'entré du programme
**16** | `NkWindowConfig cfg;` | **5** |`NkWindowConfig cfg;` | crée la structure de configuration de la fenêtre
**17**, **18**, **19** | `cfg.title   =   "Fenetre";`, `cfg.width  = 1280;`, `cfg.height = 720;` | **6**, **7**, **8** |  `cfg.title  = "Ma fenetre";`, `cfg.width  = 1280;`, `cfg.height = 720;` | Ces lignes définissent les caractéristiques que sont le titre, la taille en longueur et en largeur de la fenêtre
**21** | `NkWindow window(cfg);` | **9** | `NkWindow window(cfg);` | crée la fenêtre et l'initialise avec la configuration définie plus haut
**22**, **23**, **24**, **25** | `if (!window.IsOpen()) {`, `logger.Error("Erreur de création de la fenêtre.");`, `return -1;`, `}` | **10**, **11**, **12**, **13** | `if (!window.IsOpen()) {`, `logger.Error("[app] creation fenetre echouee");`, `return -1;`, `}` | Ces lignes contribuent à vérifier si la création de la fenêtre à bien été russie elles stopent directement le programme sinon
**26** | `while (window.IsOpen()) {` | **14** |`while (window.IsOpen()) {/* les evenements arrivent ici */ }` | Cette partie constitue la boucle de jeu qui maintient la fenêtre en vie
**33** | `return 0;` | **15** | `return 0;` | constitue le code de sortie du programme en cas de réussite
**34** | `}` | **16** | `}` | c'est l'arcollade fermante du programme.

## Lignes abscentes du code minimal du chapitre et leur provenance

Bien que le code minimal de la réponse contient effectivement des similitudes avec celles du chapitre. Le code minimal qui fonctionne sur ma machine présente aussi des lignes nouvelles dont la présence n'est pas un hasard. Elles ont toutes été ajoutée grâce au guide du fichier markdown ``

Lignes | Contenu| Rôle dans le programme
|--|--|--
**3** | `#include "NKEvent/NkEventSystem.h"` | Elle permet d'utiliser les méthodes que sont PollEvent et la Macro NKEvents(), mais aussi à l'utilisation de callbacks pour le traitement des évènements hors de la boucle de jeu.
**4** | `#include "NKEvent/NkWindowEvent.h"`| Permet de gérer les évènement relatifs à la fenêtre: son redimensionnement, sa cration, son changement de DPI et bien d'autre
**6** | `using namespace nkentseu;`| L'ensemble des types utilisé dans le chapitre se trouvent en fait dans l'espace de nom **nkentseu**. Ce qui n'y est pasprécisé. Cetteligne permet d'avoir accès directement à tous ces typeset méthodes sans avoir à mentionner le nom de l'espace de nom suivi de l'opérateur d'indirection `::` à chaque utilisations. (il alège lasyntaxe).
**8** | `NKENTSEU_DEFINE_APP_DATA(([]() {` | Elle défini les méta donnée de l'application faites avec le framework. C'est celle Macro ui est appelée par le runtime avant même le NKmain().
**9** | `NkAppData d{};` | initialise la structure NKAppData
**10**, **11**, **12** | `d.appName    = "exercice 1";`, `d.appVersion = "0.1.0";`, `return d;` | C'est lignes remplissent consécutivement la structure des métadonnées de l'application avant de la retourner pour utilisation parr le runtime.
**27** | ` while (NkEvent* e = NkEvents().PollEvent()) {` | Cette ligne pompe les évènements de la file en continue et la passe au pointeur `e` qui sera utilisé pour consommer l'évènement courant
**28** | `if (e->Is<NkWindowCloseEvent>()) {` | Vérifie si l'écènement courant estexactement celui de femeture de la fenêtre (`NkWindowCloseEvent`). la condition retourne true si oui et false si non
**29** | `window.Close();` | Fermeture propre de la fenêtre
**30**, **31**, **32** | `}`, `}`, `}` | arcolades fermantes respectives du `if (e->Is<NkWindowCloseEvent>())`, `while (NkEvent* e = NkEvents().PollEvent())` et `while (window.IsOpen())`. Elles empêchent les erreurs desyntaxes c++.

## Erreurs rencontrées lors de l'exécution du programme minimal de l'exercice

Ceci est la forme actuelle du programme pour la reproduction des erreurs lors du lancement de la commande d'exécution, avec le dossier de build du précédent essai supprimé.

```cpp
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title   =   "Fenetre";
    cfg.width   =   1280;
    cfg.height  =   720;

    cfg.canFullscreen   =   true;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("Erreur de création de la fenêtre.");
        return -1;
    }
    while (window.IsOpen()) {}
    return 0;
}
```
CE code est celui présent dans le fichier source `c3-exo1-erreur.cpp`. Ce fichier n'étantpas demandé parl'exercice,il a entrainé des modification spécifiques du workspace de l'exercice, ce qui justifie les commandes exécutées plus bas.

- **contenu du fichier.jenga** :

```py
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# exo1-la_fenetre_nue – Jenga Workspace
# Generated by `jenga workspace` on 2026-09-23 12:35:28

from Jenga import *

with workspace("exo1-la_fenetre_nue"):
    useconfig("../NkentseuKit/NkentseuKit.jenga")
    configurations(['Debug', 'Release'])
    targetoses([TargetOS.WINDOWS])
    targetarchs([TargetArch.X86_64])

    with project("window"):
        windowedapp()
        files(["./c3-exo1_main.cpp"])
        usenkentseukit()

    with project("exo1-erreur") :
        windowedapp()
        files(["./c3-exo1-erreur.cpp"])
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
LE projet de cet démonstration étant `exo1-erreur`.

- **Construction et lancement du prijet `exo1-erreur`** :

```
jenga build --target exo1-erreur

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
  1. exo1-erreur [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exo1-erreur                                                    Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c3-exo1-erreur.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exo1-erreur\exo1-erreur.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.68s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.68s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo1-la_fenetre_nue> jenga run exo1-erreur

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
  ▶  EXECUTION  —  exo1-erreur.exe
     C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo1-la_fenetre_nue\Build\Bin\Debug-Windows\exo1-erreur\exo1-erreur.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine avec le code 3489660927  (114.67s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

Le programme se termine avec un code d'erreur 3489660927 traduisant un freeze du programme, de façon inévitable, ce qui m'a poussé à intégrer le traitement de l'évènement de fermeture tel qu'indiqué dans le guide `03-NKEvent.md`.