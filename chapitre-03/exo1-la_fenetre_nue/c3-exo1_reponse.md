# Reponse de l'exercice 1

>L'exercice a été effectué sur un DELL avec le système d'exploitation  windows 11

## Rédaction du plus petit code

programme minimal retenu pour l'exécution et la terminaison propre:

```cpp
#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEvent.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

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
    bool run = true;
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

- **Nombre de lignes de code** : Ce programme comprends exactement 28 lignes de code.

Numéro de ligne dans l'exercice |Lignes dans l'exercice | numro de ligne dans le cours| lignes dans le cours | correspondences 
| -- | -- | --| --| --|
**1** | `#include "NKWindow/NKWindow.h"` | **1** | `#include "NKWindow/NKWindow.h"`| ces deux lignes permettent l'utilisation des types relatifs à la création de la fenêtre tels que `NkWindowConfig` et `NKWindow`
**2** | `#include "NKWindow/NKMain.h"` | **2** | `#include "NKWindow/NKMain.h"`| Cette ligne permet d'utiliser le point d'entré du framework Nkentseu
**8** | `int nkmain(const NkEntryState& state) {` | **4** | `int nkmain(const NkEntryState& state) {` | cette ligne définit le point d'entré du programme
**9** | `NkWindowConfig cfg;` | **5** |`NkWindowConfig cfg;` | crée la structure de configuration de la fenêtre
**10**, **11**, **12** | `cfg.title  = "Ma fenetre";`, `cfg.width  = 1280;`, `cfg.height = 720;` | **6**, **7**, **8** |  `cfg.title  = "Ma fenetre";`, `cfg.width  = 1280;`, `cfg.height = 720;` | Ces lignes définissent les caractéristiques que sont le titre, la taille en longueur et en largeur de la fenêtre
**16** | `NkWindow window(cfg);` | **9** | `NkWindow window(cfg);` | crée la fenêtre et l'initialise avec la configuration définie plus haut
**17**, **18**, **19**, **20** | `if (!window.IsOpen()) {`, `logger.Error("[app] creation fenetre echouee");`, `return -1;`, `}` | **10**, **11**, **12**, **13** | `if (!window.IsOpen()) {`, `logger.Error("[app] creation fenetre echouee");`, `return -1;`, `}` | Ces lignes contribuent à vérifier si la création de la fenêtre à bien été russie elles stopent directement le programme sinon
**21** | `while (window.IsOpen()) {` | **14** |`while (window.IsOpen()) {/* les evenements arrivent ici */ }` | Cette pqrtie constitue lq boucle de jeu qui maintient la fenêtre en vie
**28** | `return 0;` | **15** | `return 0;` | constitue le code de sortie du programme en cas de réussite

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

- **Résultat** :

```
jenga build

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: window                                                         Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c3-exo1_main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\window\window.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 6.23s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           6.23s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

Lancement du programme :

```
jenga run

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
  ◀  FIN D'EXECUTION  —  termine avec le code 3489660927  (26.51s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

Le programme se termine avec un code d'erreur 3489660927 traduisant un freeze du programme, de façon inévitable, ce qui m'a poussé à intégrer le traitement de l'évènement de fermeture tel qu'indiqué dans le guide `03-NKEvent.md`.