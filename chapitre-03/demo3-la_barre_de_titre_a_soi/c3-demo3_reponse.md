# REPONSE DE LA DEMO 3 DU CHAPITRE 3

> Cette démonstration utilise la fenêtre sans bordure de l'exercice 10, corrigée selon la majorité des commentaires apporté pour l'améliorer. L'exécution et le test en temps réél ont été repris juste avant la rédaction de la réponse.

## Construction et lancement de la fenêtre sans bordure munie de sa barre de titre

- **Construction** : La construction de la fenêtre est faite en gardant l'ordre des projets de la version initiale de l'exercice 10.

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\demo3-la_barre_de_titre_a_soi> jenga build

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

Build Order (3 projects):
  1. Button [STATIC_LIB] → 
  2. TitleBar [STATIC_LIB] (depends: Button) → 
  3. demo-3 [WINDOWED_APP] (depends: Button, TitleBar)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Button                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: button.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\Button\Button.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.10s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: TitleBar                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: TitleBar.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\TitleBar\TitleBar.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.10s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: demo-3                                                         Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\demo-3\demo-3.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.40s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  3/3
Time:           6.60s
Status:         ✓ SUCCESS
```

- **Lancement du programme** : De nmbreuses actions ont été effectuées, ce qui a entrainé une très longues sorties de log pour débuguer certaines d'entre elles. C'est notemment: **le déplacement** de la fenêtre depuis la barre de titre, la **maximisation**, la **minimisation** depuis la barre de titre et depuis les boutons et enfin, **fermeture de la fenêtre**.

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\demo3-la_barre_de_titre_a_soi> jenga run

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
  ▶  EXECUTION  —  demo-3.exe
     C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\demo3-la_barre_de_titre_a_soi\Build\Bin\Debug-Windows\demo-3\demo-3.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[NKLogger] niveau=info | console=debug | journal=C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\demo3-la_barre_de_titre_a_soi\logs\app.log
[NKLogger] trace/debug sont SOUS le niveau : NK_LOG_LEVEL=debug pour les voir ; NK_LOG_CONSOLE=1 pour tout mettre a l'ecran ; NK_LOG_QUIET=1 pour taire ces deux lignes.
[2026-09-28 22:01:11.548] [INF] [default] [main.cpp:40 in nkmain] -> [window] : (311, 156)
[2026-09-28 22:01:11.549] [INF] [default] [button.h:33 in Button] -> [button] size : NkRectT[pos(1130, 6); size(40, 30)]
[2026-09-28 22:01:11.549] [INF] [default] [button.h:33 in Button] -> [button] size : NkRectT[pos(1060, 6); size(40, 30)]
[2026-09-28 22:01:11.549] [INF] [default] [button.h:33 in Button] -> [button] size : NkRectT[pos(1020, 6); size(40, 30)]
[2026-09-28 22:01:11.550] [INF] [default] [main.cpp:43 in nkmain] -> [button] : RECT : (1130, 6) (1170, 36)
[2026-09-28 22:01:13.362] [INF] [default] [TitleBar.cpp:145 in Update] -> [follow mouse ok] : (488, 488)
[2026-09-28 22:01:13.577] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (487, 20) 
 mousePos : (798, 176); delta: (311, 176)
[2026-09-28 22:01:13.586] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (308, 20) 
 mousePos : (795, 176); delta: (311, 176)
[2026-09-28 22:01:13.592] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (306, 21) 
 mousePos : (790, 177); delta: (311, 176)
[2026-09-28 22:01:13.595] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (311, 20) 
 mousePos : (790, 177); delta: (311, 176)
[2026-09-28 22:01:13.598] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (302, 22) 
 mousePos : (781, 179); delta: (311, 176)
[2026-09-28 22:01:13.606] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (304, 20) 
 mousePos : (774, 179); delta: (311, 176)
[2026-09-28 22:01:13.611] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (311, 20) 
 mousePos : (774, 179); delta: (311, 176)
[2026-09-28 22:01:13.614] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (301, 21) 
 mousePos : (764, 180); delta: (311, 176)
[2026-09-28 22:01:13.620] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (301, 21) 
 mousePos : (754, 181); delta: (311, 176)
[2026-09-28 22:01:13.627] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (299, 20) 
 mousePos : (742, 181); delta: (311, 176)
[2026-09-28 22:01:13.628] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (311, 20) 
 mousePos : (742, 181); delta: (311, 176)
[2026-09-28 22:01:13.634] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (298, 20) 
 mousePos : (729, 181); delta: (311, 176)
[2026-09-28 22:01:13.641] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (302, 20) 
 mousePos : (720, 181); delta: (311, 176)
[2026-09-28 22:01:13.645] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (311, 20) 
 mousePos : (720, 181); delta: (311, 176)
[2026-09-28 22:01:13.648] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (301, 19) 
 mousePos : (710, 180); delta: (311, 176)
[2026-09-28 22:01:13.655] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (304, 20) 
 mousePos : (703, 180); delta: (311, 176)
[2026-09-28 22:01:13.662] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (300, 20) 
 mousePos : (692, 180); delta: (311, 176)
[2026-09-28 22:01:13.663] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (311, 20) 
 mousePos : (692, 180); delta: (311, 176)
[2026-09-28 22:01:13.668] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (301, 20) 
 mousePos : (682, 180); delta: (311, 176)
[2026-09-28 22:01:13.674] [INF] [default] [TitleBar.cpp:164 in Update] -> mouseOldPos : (301, 20) 
 mousePos : (672, 180); delta: (311, 176)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (11.99s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

La preuve de test peut être retrouvé dans le document `Preuves`. Il contient une vidéo du test fraichement fait de la version corrigée du programme. Elle présente encore des imperfections, mais la majorité a pu être corrigée.


## Ce qui a été perdu par rapport à la barre système

Bien que la barre de titre système se présentais comme une forme classique déjà rencontrée dans toute les fenêtre windows, Cette barre de titre personnalisé, dans l'état actel fait été=at d'un certain nombre de défauts que la barre système n'avait pas.

- **Le plan esthétique** : Sans Renderer, pour faciliter le dessin dans la fenêtre, l'interface de la barre de titre obtenue manuellement reste moins attrayante que celle par defaut du système. Elle prive l'usagé de l'icône de la fenêtre (dans le cas échéant), la disposition des boutons et leurs design.

- **Le plan fonctionnel** : La barre définit encore un déplacement approximatif. presque ce que le système propose sans être tout à fait cela. Par ailleurs, le dessin de la barre doit être géré manuellement avec un double buffering pour éviter le clignotement. Chose que la barre de titre système assurait automatiquement.

<video src="Preuves/20260928-2101-07.2129987.mp4">
