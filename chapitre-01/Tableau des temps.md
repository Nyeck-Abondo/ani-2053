# TABLEAU DES TEMPS

> Dans ce document, nous effectuerons les tests sur le projet MyProject poussé sur github à partir de l'exercice 7

## Arborécence du projet

```
C:.
└───MyProject
    ├───.jenga
    ├───2DEntity / Entity.cpp, .h, .jenga
    ├───maths / math.cpp, .h, .jenga
    ├───src / main.cpp
    ├───world/ world.cpp, .h, .jenga
    └───MyProject.jenga

```

## contruction complète à froid

La construction à froid représente la première construction du projet avec **Jenga** elle peut se faire en configuration **Debug** ou **Release** .Pour la construction à froid, la commande exécuté est simplem lancé à la racine du projet:

```
jenga build
```

- **sortie en console** :

```
┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.07s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  4/4
Time:           3.78s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```
indique un succès de la construcition du projet


- Temps mis: Le temps mis pour ce projet à froid est de **3.78s**

##  construction complète à chaud

La construction à chaud représente une contruction du projet après une première construction à froid sans modification du contenu des fichiers sources ou entête .De façon analogue à la construction à froid, la commande exécuté reste:

```
jenga build
```

- **sortie console** : 

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
Time:           0.13s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```
indique un succès de la construction

- **temps mis** : contruction à chaud (construction après le premier build) n'a durée pour le même projet que **0.13s**

## construction d'un seul module

La construction d'un module n'est autre le processus de compilatoin d'un projet intermédiaire à l'obtention de l'exécutable final. Il peut sagir d'une bibliothèque statique ou dynamique .Le module choisi pour cette étape est le module math présent dans le répertoire math. Après suppression du dossier de Build, la commande tapée ici est:

```
jenga build --target maths
```

- **sortie en console** :

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

Build Order (4 projects):
  1. maths [STATIC_LIB] → 
  2. Entity [STATIC_LIB] (depends: maths) → 
  3. world [STATIC_LIB] (depends: maths, Entity) → 
  4. Simulation [CONSOLE_APP] (depends: maths, Entity, world)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: maths                                                            Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.01s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Entity                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.01s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: world                                                            Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.01s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Simulation                                                      Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.01s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  4/4
Time:           0.04s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

- **Temps mis** : la compilation spécifique du module maths de MyProject a pris **0.67s**. Ce temps s'explique par le fait que jenga n'a besoin de ne construire que les dépendances du projet spécifique du workspace et non tous les projets. Si le projet à construire n'a qu'une seule dépendance, jenga ne construira que ce projet et sa dépendance au préalable. Le procéssus étant encore plus rapide si le projet à construire ne présente aucune dépendance.

## modification d'un seul fichier **source**
Ici, nous nous contenterons de modifier uniquement le fichier **math.cpp** à la ligne 7 en ajoutant un espace dans l'entête de la définition de la fonction.

- avant :

```cpp
    std::ostream& operator<<(std::ostream& os, const Vec2& v) {
        os << "< " << v.x << " ; " << v.y << " >";
        return os;
    }
```

- après :

```cpp
    std::ostream& operator<< (std::ostream& os, const Vec2& v) {
        os << "< " << v.x << " ; " << v.y << " >";
        return os;
    }
```

- commande lancée :
```
jenga build
```

- **sortie console** :

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

Build Order (4 projects):
  1. maths [STATIC_LIB] → 
  2. Entity [STATIC_LIB] (depends: maths) → 
  3. world [STATIC_LIB] (depends: maths, Entity) → 
  4. Simulation [CONSOLE_APP] (depends: maths, Entity, world)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: maths                                                            Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: maths.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\maths\maths.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.18s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Entity                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\Entity\Entity.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.08s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: world                                                            Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\world\world.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.07s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Simulation                                                      Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\Simulation\Simulation.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.35s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  4/4
Time:           1.68s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

On observe donc grace à cette sortie en console de Jenga que seul le fichier `math.cpp` a effectivement été compilé . Cela s'explique par le fait que Jenga vérifie au préalable les fichiers sources et entêtes modifiés, et adopte un comportement différent selon les deux types. Dans le cas des fichiers sources tel que présenté ici, seul ceux qui sont modifiés sont recompiléscar le changement de leur contenu n'affecte en rien les fichiers qui incluent leur fichier entête. ce qui justifie en passant le temps mis d'exactement **1.68 secondes** durant la construction du projet tout entier. 

## Construction après modification d'un seul entête

dans ce cas précis, nous allons ajouter un espace dans le fichier `math.h` à la ligne 16:

- avant :

```cpp
Vec2 operator/(Vec2& other) {
    ...
}
```
- après :

```cpp
Vec2  operator/(Vec2& other) {

}
```

- **commande lancée** :

```
jenga build
```

- **sortie en console**

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

Build Order (4 projects):
  1. maths [STATIC_LIB] → 
  2. Entity [STATIC_LIB] (depends: maths) → 
  3. world [STATIC_LIB] (depends: maths, Entity) → 
  4. Simulation [CONSOLE_APP] (depends: maths, Entity, world)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: maths                                                            Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: maths.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\maths\maths.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.74s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Entity                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: Entity.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\Entity\Entity.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.68s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: world                                                            Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: world.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\world\world.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.01s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Simulation                                                      Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\Simulation\Simulation.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.16s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  4/4
Time:           3.59s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

Comme l'ensemble du projet inclu math.h, tous les fichiers sources des projets du workspace ont été recompilés. ce qui explique le temps de **3.59s** mis par jenga pour construire le projet **Simulation**

## Tableau récapitulatif de l'expérience

|**type de construction** | Commande | temps mis| Explications
|---|---| ---|---
|contruction complète à froid| `jenga build`|3.78s | jenga parcours tous les fichiers vérifies si ils sont modifiers puis construit tout
|construction complète à chaud| `jenga build` | 0.04s| Jenga vérifie les fichiers source. Ceux ci ne présentent aucune modifications, donc ne recompile pas.
|construction d'un seul module| `jenga build --target maths` | 0.67s| le nombre de module à construire ayant diminué, le temps mis à construire le projet diminue aussi proportionnellement au nombre de dépendances de ce projet
|Construction après modification d'un seul entête| `jenga build` | 3.59s| lors de la compilation, jenga vérifie si les ficier du projet ont été modifiés. si un fichier entête est modifié, alors tous les fichiers sources qui l'incluent seront recompiler.
|modification d'un seul fichier **source**| `jenga build` | 1.68s| Lors de la vérification des fichiers souces du projet, Jenga ne recompile que ceux qui ont effectivement été modifiers. Car, ceux ci n'influencent en rien les fichiers sources qui incluent leurs fichier entête.