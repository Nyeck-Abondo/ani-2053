# REPONSE DE L'EXERCICE 11

Comme indiqué dans l'ennoncé une erreur de syntaxe dans un fichier de NKCore: `namepce` au lieu de `namespace` dans le fichier **NKLimits.cpp** à la ligne 21 . Cet avec cette faute que nous allons tenter de construire NKMath.

```cpp
// -------------------------------------------------------------------------
// SECTION 1 : ESPACE DE NOMS PRINCIPAL
// -------------------------------------------------------------------------

namepace nkentseu {


```

Cette faute de syntaxe a entrainé une erreur de compilation une fois Jenga arrivée sur le projet NKCore avant d'arriver à NKMath:

```
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

Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.14s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                               Compilation Error: NkLimits.cpp                                ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Foundation\NKCore\src\NKCore\NkLimi ║
║ ts.cpp:21:1: error: unknown type name 'namepace'                                             ║
║    21 | namepace nkentseu {                                                                  ║
║       | ^                                                                                    ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Foundation\NKCore\src\NKCore\NkLimi ║
║ ts.cpp:30:2: error: expected expression                                                      ║
║    30 |         union NkFloat32Bits {                                                        ║
║       |         ^                                                                            ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Foundation\NKCore\src\NKCore\NkLimi ║
║ ts.cpp:79:2: error: expected ';' after top level declarator                                  ║
║    79 | } // namespace nkentseu                                                              ║
║       |  ^                                                                                   ║
║       |  ;                                                                                   ║
║ 3 errors generated.                                                                          ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Foundation\NKCore\src\NKCore\NkLimits.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 0.18s  │
│ Errors: 3  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/5
Failed:         1
Not reached:    3  (arret au premier echec — voir --keep-going)
Errors:         3
Time:           0.32s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ NKCore
```

On remarque ainsi que malgré la faute syntaxe dans **NKLi,tis.cpp**, le projet **NKPlatform**, a été construit sans encombre. Ce qui nous apprend que l'ordre de construction de Jenga se fait de façon succéssive, du projet possédant le moins de dépendances vers celui qui en a le plus.

Par ailleurs, la construction s'est arrêtée en **0.32s**. Un temps non négligeable qui nous indique qu'une faute de syntaxe est une erreur impardonnable dans la construction d'un projet de plusieurs millier de lignes