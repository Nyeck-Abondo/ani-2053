# REPONSE DE L'EXERCICE 3

- **But de l'exercice** : Vérifier que les différents moyens de fermeture de la fenêtre passent tous par le seul évènement de fermeture de la fenêtre.

## Etat du programme

Le programme ici ne créer qu'une fenêtre mnimale avec une gestion seule ded l'évènement de fermeture. Afin de savoir si toutes les méthodes seront effective redirigée vers l'évènement de fermeture géré par le code, un message du logger sera affiché à chaque fois qu'il se produira. Cmme l'indique le bloc de code suivant :

```cpp
while (NkEvent* e = NkEvents().PollEvent()) {
    if (e->Is<NkWindowCloseEvent>()) {
        logger.Info("[window] : femeture de la fenetre");
        win.Close();
    }
}
```

## Construction et exécution du programme

- **Construciotn** :

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo3-fermer_proprement> jenga build

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
  1. exo-3-c4 [WINDOWED_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exo-3-c4                                                       Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c4-exo3_main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exo-3-c4\exo-3-c4.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.62s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           2.62s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

- **Lancement du programme** : Pour le lancement du programme, les sorties du logger dans le terminal pour les différentes méthodes seront affichées une à une.
    - **En utilisant ALT + F4** :
        ```
        PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo3-fermer_proprement> jenga run  

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
        ▶  EXECUTION  —  exo-3-c4.exe
            C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo3-fermer_proprement\Build\Bin\Debug-Windows\exo-3-c4\exo-3-c4.exe
        ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

        [NKLogger] niveau=info | console=debug | journal=C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo3-fermer_proprement\logs\app.log
        [NKLogger] trace/debug sont SOUS le niveau : NK_LOG_LEVEL=debug pour les voir ; NK_LOG_CONSOLE=1 pour tout mettre a l'ecran ; NK_LOG_QUIET=1 pour taire ces deux lignes.
        [2026-09-29 20:24:34.030] [INF] [default] [c4-exo3_main.cpp:21 in nkmain] -> [window] : femeture de la fenetre

        ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
        ◀  FIN D'EXECUTION  —  termine normalement  (14.54s)
        ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
        ```
    - **En utilisant le gestionnaire de tâches** :
        ```
        PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo3-fermer_proprement> jenga run

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
        ▶  EXECUTION  —  exo-3-c4.exe
            C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo3-fermer_proprement\Build\Bin\Debug-Windows\exo-3-c4\exo-3-c4.exe
        ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

        [NKLogger] niveau=info | console=debug | journal=C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo3-fermer_proprement\logs\app.log
        [NKLogger] trace/debug sont SOUS le niveau : NK_LOG_LEVEL=debug pour les voir ; NK_LOG_CONSOLE=1 pour tout mettre a l'ecran ; NK_LOG_QUIET=1 pour taire ces deux lignes.
        [2026-09-29 20:25:10.856] [INF] [default] [c4-exo3_main.cpp:21 in nkmain] -> [window] : femeture de la fenetre

        ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
        ◀  FIN D'EXECUTION  —  termine normalement  (20.54s)
        ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
        ```
        <img src="Preuves/Screenshot 2026-09-29 202505.png">
    - **En utilisant le bouton du système sur la barre de titre** :

        ```
        PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo3-fermer_proprement> jenga run

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
        ▶  EXECUTION  —  exo-3-c4.exe
            C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo3-fermer_proprement\Build\Bin\Debug-Windows\exo-3-c4\exo-3-c4.exe
        ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

        [NKLogger] niveau=info | console=debug | journal=C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo3-fermer_proprement\logs\app.log
        [NKLogger] trace/debug sont SOUS le niveau : NK_LOG_LEVEL=debug pour les voir ; NK_LOG_CONSOLE=1 pour tout mettre a l'ecran ; NK_LOG_QUIET=1 pour taire ces deux lignes.
        [2026-09-29 20:36:28.846] [INF] [default] [c4-exo3_main.cpp:21 in nkmain] -> [window] : femeture de la fenetre

        ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
        ◀  FIN D'EXECUTION  —  termine normalement  (2.49s)
        ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
        ```

On remarque que dans les trois situations,le message de log apparait. Ce qui nous permet de conclure que toutes les methodes de fermetures passent toutes par le même chemin. La preuve des tests se trouvent dans le dossier `Preuves`.