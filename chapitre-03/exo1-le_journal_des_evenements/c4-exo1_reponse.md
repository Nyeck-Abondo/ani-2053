# REPONSE DE L'EXERCICE 1 DU CHAPITRE 4

> Cet exercice demande à l'étudiant de ressenser dans un journal les évènements provoqués dans une fenêtre de sa création, et de rendre par le mpeme occasion, le nombre d'évènements produites pour une seconde générale d'utilisation.

## L'état du fichier source

Le gichier source regroupe l'ensemble des évènements décris dans l'énoncé de l'exercice, traités un par un et annoncé dans le terminal au moyen du logger. Comme l'indique l'extrait de code suivant : 

```cpp
while (window.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            float32 dt = clock.Tick().delta;
            if (e->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
            if (auto* mouse = e->As<NkMouseMoveEvent>()) {
                logger.Info("[Famille] : Evènement souris  - [Type] : {0}", mouse->GetTypeStr());
            }
            if (auto* key = e->As<NkKeyPressEvent>()) {
                logger.Info("[Famille] : Evènement Clavier  - [Type] : {0}", key->GetTypeStr());
            }
            if (auto* size = e->As<NkWindowResizeEvent>()) {
                logger.Info("[Famille] : Evènement Fenêtre  - [Type] : {0}", size->GetTypeStr());
            }
            if (auto* drop = e->As<NkDropFileEvent>()) {
                const auto& fileData = drop->data;
                const uint32 fileCount = fileData.Count();

                logger.Info("[Famille] : Evènement input - [Type] : {} \n Fichiers déposés : {} fichier(s) à la position ({},{})",
                    drop->GetTypeStr(), fileCount, fileData.x, fileData.y  
                );
            }
            time += dt;
            if (time > 1.0f) {
                logger.Warn("[NkEventSystem] : [Total d'évènements] - {0} ", NkEvents().GetTotalEventCount());
            }
        }
    }
```

## La construction et le lancement du programme

- **Construciton du programme** : Ici nous o;2ttrons le contenu des fichier .Jenga .

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo1-le_journal_des_evenements> jenga build

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
  1. ex0-1-c4 [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: ex0-1-c4                                                       Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c4-exo1_main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\ex0-1-c4\ex0-1-c4.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.52s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.52s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

La construction c'est achevée avec succès.

- **Lancement du programme** :

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo1-le_journal_des_evenements> jenga run

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
  ▶  EXECUTION  —  ex0-1-c4.exe
     C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo1-le_journal_des_evenements\Build\Bin\Debug-Windows\ex0-1-c4\ex0-1-c4.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[NKLogger] niveau=info | console=debug | journal=C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo1-le_journal_des_evenements\logs\app.log
[NKLogger] trace/debug sont SOUS le niveau : NK_LOG_LEVEL=debug pour les voir ; NK_LOG_CONSOLE=1 pour tout mettre a l'ecran ; NK_LOG_QUIET=1 pour taire ces deux lignes.
[2026-09-28 23:32:27.485] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:27.496] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:27.496] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:27.499] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:27.504] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:27.511] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:27.518] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:27.524] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:27.525] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:27.531] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:27.538] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:27.546] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:28.486] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 0.0071233
[2026-09-28 23:32:28.487] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 130 
[2026-09-28 23:32:29.487] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 0.381674
[2026-09-28 23:32:29.488] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 161 
[2026-09-28 23:32:30.100] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:30.107] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:30.114] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:30.490] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 0.0067988
[2026-09-28 23:32:30.491] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 309 
[2026-09-28 23:32:31.556] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 0.275762
[2026-09-28 23:32:31.556] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 346 
[2026-09-28 23:32:32.558] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 0.0070443
[2026-09-28 23:32:32.558] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 458 
[2026-09-28 23:32:33.402] [INF] [default] [c4-exo1_main.cpp:49 in nkmain] -> [Famille] : Evenement input - [Type] : NK_DROP_FILE 
 Fichiers deposes : NK_DROP_FILE fichier(s) a la position (NK_DROP_FILE,NK_DROP_FILE)
[2026-09-28 23:32:33.406] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:34.015] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 0.609381
[2026-09-28 23:32:34.016] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 556 
[2026-09-28 23:32:34.016] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:34.022] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:34.029] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:34.036] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:34.043] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:34.050] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:34.057] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:34.064] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:34.071] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:35.018] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 0.007124
[2026-09-28 23:32:35.019] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 683 
[2026-09-28 23:32:36.023] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 0.0068526
[2026-09-28 23:32:36.024] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 751 
[2026-09-28 23:32:37.167] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 0.225141
[2026-09-28 23:32:37.167] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 851 
[2026-09-28 23:32:37.652] [INF] [default] [c4-exo1_main.cpp:40 in nkmain] -> [Famille] : Evenement Clavier  - [Type] : NK_KEY_PRESSED
[2026-09-28 23:32:39.643] [INF] [default] [c4-exo1_main.cpp:40 in nkmain] -> [Famille] : Evenement Clavier  - [Type] : NK_KEY_PRESSED
[2026-09-28 23:32:39.643] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 1.83966
[2026-09-28 23:32:39.644] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 856 
[2026-09-28 23:32:41.084] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 1.28547
[2026-09-28 23:32:41.085] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 858 
[2026-09-28 23:32:42.085] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 0.0069881
[2026-09-28 23:32:42.086] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 968 
[2026-09-28 23:32:43.177] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 0.210717
[2026-09-28 23:32:43.178] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 1019 
[2026-09-28 23:32:44.397] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 0.221373
[2026-09-28 23:32:44.398] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 1073 
[2026-09-28 23:32:46.751] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 2.08264
[2026-09-28 23:32:46.752] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 1113 
[2026-09-28 23:32:47.755] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 0.0068089
[2026-09-28 23:32:47.755] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 1194 
[2026-09-28 23:32:48.223] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:48.249] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:48.256] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:48.270] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:48.361] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:48.389] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:49.699] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 1.30932
[2026-09-28 23:32:49.699] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 1257 
[2026-09-28 23:32:50.049] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:50.601] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:50.615] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:50.629] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:50.636] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:50.651] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:50.672] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:50.685] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:50.713] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 0.0271382
[2026-09-28 23:32:50.713] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 1284 
[2026-09-28 23:32:50.727] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:50.754] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:50.887] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:50.929] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:50.963] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.117] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.151] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.165] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.186] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.200] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.207] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.221] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.235] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.241] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.257] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.263] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.284] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.291] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.312] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.319] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.326] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.340] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.346] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.354] [INF] [default] [c4-exo1_main.cpp:37 in nkmain] -> [Famille] : Evenement souris  - [Type] : NK_MOUSE_MOVE
[2026-09-28 23:32:51.941] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 0.379086
[2026-09-28 23:32:51.942] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 1364 
[2026-09-28 23:32:53.590] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 1.41873
[2026-09-28 23:32:53.590] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 1450 
[2026-09-28 23:32:53.590] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.591] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.591] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.591] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.591] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.591] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.591] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.591] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.592] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.592] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.592] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.592] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.592] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.592] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.593] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.593] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.593] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.593] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.593] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.593] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.594] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:53.594] [INF] [default] [c4-exo1_main.cpp:43 in nkmain] -> [Famille] : Evenement Fenetre  - [Type] : NK_WINDOW_RESIZE
[2026-09-28 23:32:54.591] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 0.0071034
[2026-09-28 23:32:54.591] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 1462 
[2026-09-28 23:32:55.598] [INF] [default] [c4-exo1_main.cpp:55 in nkmain] -> 0.0071445
[2026-09-28 23:32:55.599] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 1562 

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (29.10s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

La sortie en terminal nous renseigne sur les familles d'évènement survenues dans la fenêtre, ainsi que leurs types:

Famille | Type enregistré
|--|--
Evenement Fenetre | **NK_WINDOW_RESIZE**
Evenement souris | **NK_MOUSE_MOVE**
Evenement Clavier | **NK_KEY_PRESSED**
Evenement input | **NK_DROP_FILE** 

- **Le Nombre d'évènements produit en une seconde** : Le code contient un compteur, qui log toute les secondesm le nombre total dévènement traité.
```
[2026-09-28 23:32:28.487] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 130 
...
...
[2026-09-28 23:32:29.488] [WRN] [default] [c4-exo1_main.cpp:56 in nkmain] -> [NkEventSystem] : [Total d'evenements] - 161
```

On peut remarquer une variation très grande entre le nombre d'évènement qui se produi en une seconde, pouvant allez jusqu'à des centaines entre deux secondes consécutives d'utilisation. On remarque donc que le nombre d'évènement produit par seconde dépends de l'uilisation faite de l'application pendant cette période là. amenant le nombre d'évènement sensiblement vers la centaine.

> Le programme a été ménagé ici durant son utilisation pour faciliter le receuil et la lecture des logs dans le terminal. En conditions réelles om la souris est en constant mouvement dans la fenêtre, et où des clics sont souvent effectués, le nombre d'évènements par seconde triple facilement, faisant débuter le compteur à plus de 200 évènements.