# Réponse à l'exercice 7

- **Chronométrage de la construction complète du projet**:
```
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Simulation                                                      Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\Simulation\Simulation.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.48s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  4/4
Time:           5.42s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

Le temps écoulé est de **5.42s**.

- **chronométrage de la seconde contruction du projet sans rien toucher**:

```
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Simulation                                                      Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.03s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  4/4
Time:           0.12s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```
Le temps cette fois ci enregistré est de : **0.12s**

- **Explications de la différence de temps**: LA différence de temps, sensiblement 45.17 fois plus petite entre les deux opérations peut s'explique par le fait que Jenga ne recompile que les fichiers ayant été modifiers, ce qui permet de gagner un temps significatif dans le second teste car aucune de ceux ci n'a été touché après le premier test de build.

Par alileurs, durant la deuxième opération de compilation jenga prends tout de même **0.12s**, car celui ci vérifie l'état de chaque fichiers de chaque projet.