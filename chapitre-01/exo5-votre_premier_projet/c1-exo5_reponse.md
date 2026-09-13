# Réponse à l'exercice 5

Après création du dossier `MonEssai` dans le dossier `Applications`  de NKentseu, les différents tests de l'exercices ont été effectués:

- **contenu du .jenga** :
```py
import os
from Jenga import *
from Jenga.GlobalToolchains import RegisterJengaGlobalToolchains

with project("MonEssai"):
    consoleapp()
    language("C++")
    cppdialect("C++17")
    files(["./**.cpp"])
    includedirs(["."])

    with filter("system:Window") :
        usetoolchain("clang−mingw")
```

- **contenu du `main.cpp`** : le programme n'affiche rien comme demandé dans l'énoncé

```cpp
#include <iostream>

int main() {
    return 0;
}
```

- **Vérification de la présence dans la liste des projets** : suite au lancement de la commande `jenga info` depuis le dossier racine, ont observe que le nom du projet (`MonEssai`) apparait effectivement vers la 30 ième position, tel que plassé dans le fichier `Nkentseu.jenga`, plus précisément entre les projet **frog** et **NKSLCheck**.

```
NKMeshRenderTest                ConsoleApp    C++        No     Yes
Model                           WindowedApp   C++        No     Yes
Nyeck                           WindowedApp   C++        No     Yes
ChatChat-Kongossa               WindowedApp   C++        No     Yes
frog                            WindowedApp   C++        No     Yes
MonEsssai                       ConsoleApp    C++        No     Yes
NkSLCheck                       ConsoleApp    C++        No     Yes
NKPA                            WindowedApp   C++        No     Yes
```

- **Construction du projet** : La construction du projet grâce à la commande
```
jenga build --target MonEssai 
```
c'est déroulé en précisément **0.72s** avec un message de succès en sortie, comme l'indique la preuve ci dessous.

```
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: MonEssai                                                        Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\MonEssai\MonEssai.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.72s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.72s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```