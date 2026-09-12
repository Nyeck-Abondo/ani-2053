# REPONSE DE L'EXERCICE 12

## Identification de la cause de la désactivation des tests

En parcourant le fichier `nkentseu.jenga`, on remarque que les tests sont désactivés à la ligne **451** et **453** comme indiqué ci dessous:

```py
    dutc(enable=True)

    dute(enable=True)
```
## Lancement des des du module NkCanvasDemo

La suite de l'ennoncé indique le lancement des test d'un module spécifique. Le module choisi pour cela ici est NKMath qui les test sont précisés par **NKMath_Tests**.

état actuel de **nkentseu.jenga**, de la ligne 451 à 453 pour le lancement des **NKMath_Tests**.

```py
    dutc(enable=False)

    dute(enable=False)
```

Commande exécuter pour lancer la construction des test de NKMath:
```
jenga test --project NkCanvasDemo_Tests
```

Sortie obtenu du lancement de la commande:

```
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkCanvasDemo_Tests                                               Kind: TEST_SUITE  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 3 source file(s)
✓   [1/3] Compiled: Entry.cpp
✓   [2/3] Compiled: test_smoke.cpp
✓   [3/3] Compiled: benchmark_smoke.cpp
ℹ Linking...
✓ Built: Build\Tests\Debug-Windows\NkCanvasDemo_Tests.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.09s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  20/20
Time:           1m23.9s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════


Running tests for NkCanvasDemo_Tests...
╔======================================================================╗
║                                                                      ║
║      ██╗   ██╗███╗   ██╗██╗████████╗███████╗███████╗████████╗        ║
║      ██║   ██║████╗  ██║██║╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝        ║
║      ██║   ██║██╔██╗ ██║██║   ██║   █████╗  ███████╗   ██║           ║
║      ██║   ██║██║╚██╗██║██║   ██║   ██╔══╝  ╚════██║   ██║           ║
║      ╚██████╔╝██║ ╚████║██║   ██║   ███████╗███████║   ██║           ║
║       ╚═════╝ ╚═╝  ╚═══╝╚═╝   ╚═╝   ╚══════╝╚══════╝   ╚═╝           ║
║                                                                      ║
║                C++ Unit Testing Framework v1.0.0                     ║
║              Fast, Reliable, and Developer-Friendly                  ║
║                                                                      ║
║  Number of tests: 2                                                  ║
║  Verbose mode: enabled                                               ║
║  Colors: enabled                                                     ║
║  Progress bar: disabled                                              ║
║                                                                      ║
║               Session started: 2026-09-12 13:43:41                   ║
║                                                                      ║
╚======================================================================╝

[2026-09-12 13:43:41.199] [INF] [default] [benchmark_smoke.cpp:21 in Run] -> [Sandbox Benchmark] color packing: 2e+06 ns total (sink=12632064)
✓ SandboxBenchmark_ColorPackingLoop             [OK]  1/1 assertions  (3ms)
  ✓ 1 assertion(s) réussie(s) (moy: 3ms/assert)
✓ SandboxSmoke_RuntimeTypesAccessible           [OK]  3/3 assertions  (< 1ms)
  ✓ 3 assertion(s) réussie(s) (moy: < 1ms/assert)


┌────────────────────── RÉSULTATS DES TESTS ──────────────────────┐
│ SUCCÈS                                                          │
├─────────────────────────────────────────────────────────────────┤
│ Tests :      2 réussis, 2 au total          │
│ Assertions : 4 réussies, 4 au total         │
│ Taux succès : Tests: 100.0%, Assertions: 100.0%        │
│ Temps total : 3ms (1ms/test)     │
└──────────────────────────────────────────────────────────────┘

✅ Tous les tests sont réussis !

All tests passed for NkCanvasDemo_Tests.
```

Comme l'indique la sortie en console de Jenga, la construction des tests unitaires de **NkCanvasDemo** a réussie en affichant les statistiques suivantes:

- **Nombre de suites existantes** : 2;
- **Nombre de testes qui s'exécutent** : 2;
- **Nombre de testes qui passent** : 2

## Etat de nkentseu.jenga après l'exercice

Une fois l'exercice terminé, le fichier nkentseu.jenga a été restauré tel qu'il était avant ceux ci au niveau des lignes **451** à **453**:

```py
    dutc(enable=True)

    dute(enable=True)

```