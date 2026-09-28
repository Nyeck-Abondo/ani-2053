# REPONSE DE L'EXERCICE 4

> Dans cet exercice il nous est demandé de recolter une série d'information sur les écrans connectés à l'ordinateur de l'étudiant. Cet exercice a donc été réalisé en utilisant l'écran d'un laptop et celui d'une télé, tous deux connectés en tant qu'extension de l'autre via nu cable HDMI

## Presentation du fichier source

Le fichier source tel qu'il es t réellement est un code minimal de création d'un fenêtre, sans aucune spécificité. Il gère la fermeture et une entrée du clavier posée sur la touche `G`, qui déclanche le log des informations demandées par l'exercice.

```cpp
#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"

using namespace nkentseu;

NKENTSEU_DEFINE_APP_DATA(([] () {
    NkAppData d {};
    d.appName       =   "exercice 12";
    d.appVersion    =   "0.1.0";
    return d;
}) ())

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title       =   "Exercice 12";
    cfg.width       =   1280;
    cfg.height      =   720;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Info("[Window] : Erreur de creation de le den[etre]");
        return -1;
    }

    while (window.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
            if (auto* k = e->As<NkKeyPressEvent>()) {
                if (k->GetKey() == NkKey::NK_G) {
                    logger.Warn("[Fenetre] : {0} \n Identifiant : {1} \n Taille (resolution logique) : {2} x {3}\n Taille physique : {4} x {5} \n  Position : ({6} , {7}) \n Facteur d'échelle : {8}", 
                                window.GetCurrentMonitor().name, window.GetCurrentMonitor().index, window.GetCurrentMonitor().width, window.GetCurrentMonitor().height
                                , window.GetCurrentMonitor().physWidth, window.GetCurrentMonitor().physHeight, window.GetCurrentMonitor().posX, window.GetCurrentMonitor().posY, window.GetCurrentMonitor().dpiScale);
                }
            }
        }
        
    }
    
    return 0;
}
```

L'ensemble des informations des moniteurs sont recupérés via la méthode GetCurrentMonitorqui renvoie une structure décrivant les caractéristiques de celui ci , et directemen exploitable dans le logger.

## Construction et lancement du programme

- **Construction du programme** :

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo12-l_inventaire_des_ecrans> jenga build                          

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
  1. exercice-12 [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exercice-12                                                    Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c3-exo12_main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exercice-12\exercice-12.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.40s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.40s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

la construction s'est déroulée sans accros.

- **Lancement du programme** :

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo12-l_inventaire_des_ecrans> jenga r 

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
  ▶  EXECUTION  —  exercice-12.exe
     C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo12-l_inventaire_des_ecrans\Build\Bin\Debug-Windows\exercice-12\exercice-12.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[NKLogger] niveau=info | console=debug | journal=C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo12-l_inventaire_des_ecrans\logs\app.log
[NKLogger] trace/debug sont SOUS le niveau : NK_LOG_LEVEL=debug pour les voir ; NK_LOG_CONSOLE=1 pour tout mettre a l'ecran ; NK_LOG_QUIET=1 pour taire ces deux lignes.
[2026-09-28 06:30:03.218] [WRN] [default] [c3-exo12_main.cpp:31 in nkmain] -> [Fenetre] : \\.\DISPLAY1 
 Identifiant : 0 
 Taille (resolution logique) : 1920 x 1080
 Taille physique : 1920 x 1080 
  Position : (0 , 0) 
 Facteur d'echelle : 1.25
[2026-09-28 06:30:26.453] [WRN] [default] [c3-exo12_main.cpp:31 in nkmain] -> [Fenetre] : \\.\DISPLAY4 
 Identifiant : 0 
 Taille (resolution logique) : 1920 x 1080
 Taille physique : 1920 x 1080 
  Position : (1920 , 0) 
 Facteur d'echelle : 1.25

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (182.10s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

- **interprêtation des resultats**: Au vue des sorties de log, nous pouvons conclure que nous sommes effectivement en la présence de deux écrans différents.
    - **Ecran 1** : C'est ici la fenêtre de l'écran de mon ordinateur, celle qu'indique le premier log.
        - Sa taille : 1920 x 1080 . C'est sa résolution logique et physique recupérée de la structure `NkDisplayInfo`.
        - Son nom : il se nomme selon la sortie `\\.\DISPLAY1`.
        - Position : La position loggée ici est (0; 0)
        - facteur d'échelle : 1.25

    - **Ecran 2** : l'écran 2 est en fait un écran de télévision connecté à l'ordinateur via un cable HDMI.
        - Sa taille : 1920 X 1080
        - Son Nom: `\\.\DISPLAY4`
        -Position : (1920 , 0)
        - Facteur d'échelle : 1.25

L'écran qui porte la fenêtre correspond à celui dont le nom apparait dans le terminal à l'instant T:

A 06:30:03.218 en appuyant sur la touche G qui déclenche le logging, la fenêtre était dans l'écran de mon ordinateur : `\\.\DISPLAY1`
```
[2026-09-28 06:30:03.218] [WRN] [default] [c3-exo12_main.cpp:31 in nkmain] -> [Fenetre] : \\.\DISPLAY1 
```

A 06:30:26.453 lq fenêtre était dans l'écran de la télé : `\\.\DISPLAY4`
```
[2026-09-28 06:30:26.453] [WRN] [default] [c3-exo12_main.cpp:31 in nkmain] -> [Fenetre] : \\.\DISPLAY4 
```

lq preuve aue les vqleurs suivent le cours du test est dans cette image qui montre la fenêtre dans l'espace de la télévision, qui ne contient aucune icône d'applicationm et 0 l4heure indiquée sur l'image.

<img src="Preuves/Screenshot 2026-09-28 063114.png">