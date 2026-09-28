# REPONSE DE L'EXERCICE 11

> L'exercice 11 demande de créer deux fenêtre et de répertorier celle dans laquell l'évènement se produit et de dire clairement ce qu'il manquerait pour dessiner dans les deux, au vu de l'état actuel dans lequel elles sont.

## Etude l'apparition de l'évènement dans les fenêtres

L'évènement exploré ici est l'évènement de clic de la souris. quelqu'il soit. Ce choix est justifier par le fait que pour un test minimal comme celui ci la lisibilité des traces de logging bénéficient d'une certaine priorité. et aussi parcequ'il es plus facile à suivre.

- **Etat du fichier source** : Le fichier source de l'exercice ne s'apûis que sur la création la plus simple de deux fenêtre suivant la mpême structure e configuration. Il défini ensuite un message de log dans lequel est affiché l'identifiant de la fenêtre dans lequel s'est produit l'évènement. Ainsi, en considérant le fait que l'identifiant de la seconde fenêtre créée est calculé suivant le postulat suivant : L'id de la fenêtre suivante est l'incrément de 1 de la fenêtre créée avant elle, `window` est d'identifiant **1** et `win02` est d'identifiant **2**.

    ```cpp
    #include "NKWindow/NKWindow.h"
    #include "NKWindow/NKMain.h"
    #include "NKEvent/NkEventSystem.h"
    #include "NKEvent/NkWindowEvent.h"

    using namespace nkentseu;

    NKENTSEU_DEFINE_APP_DATA(([]() {
        NkAppData d{};
        d.appName    = "exercice 1";
        d.appVersion = "0.1.0";
        return d;
    })());

    int nkmain(const NkEntryState& state) {
        NkWindowConfig cfg;
        cfg.title   =   "Fenetre";
        cfg.width   =   1280;
        cfg.height  =   720;

        NkWindow window(cfg);
        NkWindow win02(cfg);
        if (!window.IsOpen() || !win02.IsOpen()) {
            logger.Error("Erreur de création de la fenêtre.");
            return -1;
        }
        while (window.IsOpen()) {
            while (NkEvent* e = NkEvents().PollEvent()) {
                if (e->As<NkWindowCloseEvent>()) {
                    if (e->GetWindowId() == window.GetId())
                        window.Close();
                    else 
                        win02.Close();
                }

                if (e->As<NkMouseButtonPressEvent>()) {
                    logger.Info("[Clic] : Fenêtre d'identifiant : {0}", e->GetWindowId());
                }
            }
        }
        return 0;
    }
    ```
- **Construction et lancement du programme** :


```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo11-deux_fenetres> jenga build 

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
  1. exercice-11 [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exercice-11                                                    Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.05s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.05s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo11-deux_fenetres> jenga run

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
  ▶  EXECUTION  —  exercice-11.exe
     C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo11-deux_fenetres\Build\Bin\Debug-Windows\exercice-11\exercice-11.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[NKLogger] niveau=info | console=debug | journal=C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo11-deux_fenetres\logs\app.log
[NKLogger] trace/debug sont SOUS le niveau : NK_LOG_LEVEL=debug pour les voir ; NK_LOG_CONSOLE=1 pour tout mettre a l'ecran ; NK_LOG_QUIET=1 pour taire ces deux lignes.
[2026-09-27 23:02:51.513] [INF] [default] [c3-exo11_main.cpp:37 in nkmain] -> [Clic] : Fenetre d'identifiant : 2
[2026-09-27 23:02:56.060] [INF] [default] [c3-exo11_main.cpp:37 in nkmain] -> [Clic] : Fenetre d'identifiant : 1
[2026-09-27 23:02:59.032] [INF] [default] [c3-exo11_main.cpp:37 in nkmain] -> [Clic] : Fenetre d'identifiant : 2
[2026-09-27 23:03:00.157] [INF] [default] [c3-exo11_main.cpp:37 in nkmain] -> [Clic] : Fenetre d'identifiant : 2
[2026-09-27 23:03:01.168] [INF] [default] [c3-exo11_main.cpp:37 in nkmain] -> [Clic] : Fenetre d'identifiant : 1

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (21.89s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

- **Analyse des messages de log** : Comme demandé par l'énoncé de l'exerciec, des clics de la souris ont été effectués dans chaques fenêtre aléatoirement sans s'attardersur leur titres, qui d'ailleurs selon le code est le même pour l'une comme pour l'autre. Les remarques qu'on fait :
    - Le clic effectué dans la fenpêtre un ne revoit un message de log à un instant T qui n'indique n'avoir été produit dans la fenêtre d'indice 1. on ne voit pas un second message apparaitre immédiatement aprait indiquant que l'évènement est produit dans la fenêtre d'id 2.
    ```
    [2026-09-27 23:02:51.513] [INF] [default] [c3-exo11_main.cpp:37 in nkmain] -> [Clic] : Fenetre d'identifiant : 2
    ```
    Le clic est effectué dans la fenêtre d'id 2 à T = **23:02:51.513**
    ```
    [2026-09-27 23:02:56.060] [INF] [default] [c3-exo11_main.cpp:37 in nkmain] -> [Clic] : Fenetre d'identifiant : 1
    ```
    Le clic dans la fenêtre d'id 1 ne survient que à **23:02:56.060**, soit une différence de **4.547** secondes

On conclu donc que deux fenêtres ne reçoivent donc pas le même évènement.

## Ce qui manque pour dessiner dans ces fenêtre

Après le test des évènements, ce qui manquerait pour dessiner dans ces fenêtre serait des méthodes provenant d'un Renderer qui serait facilement associable à des évènements:
- **Des méthodes de dessin de primitives**: des points, des lignes, des triangles, des cercles.

Ce Renderer servirait de pont entre la surface de la fenêtre et des API graphiques telles que OpenGL, DirectX ou Vulkan pour faciliter le dessin ciblé dans chaque fenêtres, puique les évènements ne se produise que dans une seule fenêtre à la fois: celle qui a le focus.