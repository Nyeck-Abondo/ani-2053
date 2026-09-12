# REPONSE DE L'EXERCICE 11

Comme indiqué dans l'ennoncé une erreur de syntaxe dans un fichier de NKMath: `namepce` au lieu de `namespace` dans le fichier **NKFunctions.cpp** à la ligne 46 .

```cpp
namespace nkentseu {

	// Indentation niveau 1 : namespace math
	namepace math {

```

Cette faute de syntaxe a entrainé une erreur de compilation une fois Jenga arrivée sur le projet NKMath lui même:

```
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                              Compilation Error: NkFunctions.cpp                              ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkFunc ║
║ tions.cpp:45:2: error: unknown type name 'namepace'                                          ║
║    45 |         namepace math {                                                              ║
║       |         ^                                                                            ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkFunc ║
║ tions.cpp:61:3: error: unexpected type name 'float32': expected expression                   ║
║    61 |                 float32 NkFloor(float32 x) noexcept {                                ║
║       |                 ^                                                                    ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkFunc ║
║ tions.cpp:61:11: error: expected '}'                                                         ║
║    61 |                 float32 NkFloor(float32 x) noexcept {                                ║
║       |                         ^                                                            ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkFunc ║
║ tions.cpp:45:16: note: to match this '{'                                                     ║
║    45 |         namepace math {                                                              ║
║       |                       ^                                                              ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkFunc ║
║ tions.cpp:1102:3: error: expected ';' after top level declarator                             ║
║  1102 |         } // namespace math                                                          ║
║       |          ^                                                                           ║
║       |          ;                                                                           ║
║ 4 errors generated.                                                                          ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkFunctions.cpp
✓   [3/12] Compiled: NkEulerAngle.cpp
✓   [4/12] Compiled: NkRandom.cpp
✓   [5/12] Compiled: NkRectangle.cpp
✓   [6/12] Compiled: NkMat.cpp
✓   [7/12] Compiled: NkAngle.cpp
✓   [8/12] Compiled: NkSegment.cpp
✓   [9/12] Compiled: NkQuat.cpp
✓   [10/12] Compiled: NkRange.cpp
✓   [11/12] Compiled: NkColor.cpp
✓   [12/12] Compiled: NkVec.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                Time: 13.49s  │
│ Errors: 4  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  4/5
Failed:         1
Errors:         4
Time:           37.14s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ NKMath
```

On remarque ainsi que malgré la faute syntaxe dans **NKFunctions.cpp**, les projets **NKPlatform**, **NKMemory**, **NKCore** et **NKContainers** ont été construit sans encombre. Ce qui nous apprend que l'ordre de construction de Jenga se fait de façon succéssive, du projet possédant le moins de dépendances vers celui qui en a le plus.