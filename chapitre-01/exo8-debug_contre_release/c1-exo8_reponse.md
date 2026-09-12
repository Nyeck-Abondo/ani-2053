# Réponses à l'exercice 8

> les réponses à cet exercices ont été trouvée en utilisant le projet **MyProject** présent dans le dossier de l'exercice

## comparaison des deux configs de construction
La tâche de l'exercice a été exécutée en trois étapes:

- **Construction en config `Debug`**: la commande saisie ici fut:
```
jenga build --config Debug
``` 
la construction du binaire final à duré exactement **3.70s** conformément à la sortie ci dessous:
```
✓ Built: Build\Bin\Debug-Windows\Simulation\Simulation.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.88s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  4/4
Time:           2.74s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```
La taille du binaire quant à elle est de : **348KB**

- **Construction en config `Release`**: la commande saisie ici fut:
```
jenga build --config Release
```

La contruction du binaire final a ici été sensiblement plus rapide que celle du mode de configuration `Debug`, avec **2.97s**, comme l'indique la sortie suivante:

```
✓ Built: Build\Lib\Release-Windows\world\world.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.82s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Simulation                                                      Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Release-Windows\Simulation\Simulation.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.97s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  4/4
Time:           3.70s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```
La taille du binaire produit fait ainsi: **252KB** soit **43KB** de moins que la version en configuration Debug.

On observe donc que le binaire produit en conf `Debug` est plus volumineux que celuui produit en config `Release` pour un même projet.

## identification des lignes responsables de la différence

Dans le fichier `MyProject.jenga` les lignes responsables de cette différence ne sont rien d'autre que:

- Dans le cas de la configuration `Debug`:
```py
with filter("config:Debug"):
            symbols(True) #//< active les symboles
            optimize("OFF") #//< retire toutes optimisations
            defines(["_DEBUG", "DEBUG"]) #//<Macro de Debug
```

- Dans le cas de la configuration `Release`:
```py
with filter("config:Release"): #//< qctive le bloc uniquement en config release
            symbols(False) #//< retire les symboles utiles au débugage
            optimize("Speed") #//< activation des flags d'optimisation -02, -01...
            defines("NDEBUG")
```