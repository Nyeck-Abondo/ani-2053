# Réponses à l'exercice 6

## Retrait de `dependson`

Suite au retrait de `dependson`  du fichier MyApp.jenga au niveau du projet **Simulation**, on observe un changement de l'ordre de compilation, le faisant passer du dernier projet à compiler au second (définit par ordre alphabétique).

- message avec `dependson`:

```
Build Order (4 projects):
  1. maths [STATIC_LIB] → 
  2. Entity [STATIC_LIB] (depends: maths) → 
  3. world [STATIC_LIB] (depends: maths, Entity) → 
  4. Simulation [CONSOLE_APP] (depends: maths, Entity, world)
```
- message sans `dependson`:
```
Build Order (4 projects):
  1. maths [STATIC_LIB] → 
  2. Simulation [CONSOLE_APP] → 
  3. Entity [STATIC_LIB] (depends: maths) → 
  4. world [STATIC_LIB] (depends: maths, Entity)
```

Dans un autre projet créé depuis nkentseu, on observe juste que la compilation du projet à réussie.

contenu du .jenga du projet avant le build
```py
import os
from Jenga import *
from jengaconfig import *
from Jenga.GlobalToolchains import RegisterJengaGlobalToolchains

with project("ChatChat-Kongossa"):
    windowedapp()
    language("C++")
    cppdialect("C++17")
    location(".")
    appicon("ressource/vecteezy_speech-bubble-icon-design_31738239.png")
    

    files([
        
        "UI/**.cpp",
        "src/**.cpp",
        "./main.cpp",
        "Net/**.cpp"
    ])
    includedirs([
        "UI",
        "Net",
        "src", 
        "%{NKNetwork.location}/src",
        "%{NKTime.location}/src",
        "%{NKFileSystem.location}/src",
        "%{NKStream.location}/src",
        "%{NKMath.location}/src",
        "%{NKLogger.location}/src",
        "%{NKThreading.location}/src",
        "%{NKContainers.location}/src",
        "%{NKMemory.location}/src",
        "%{NKCore.location}/src",
        "%{NKPlatform.location}/src",
    ])

    dependfiles(["ressource"])

    nkentseudependson(
        [
            "NKGui", "NKCanvas", "NKWindow", "NKEvent", "NKGlad",
            "NKFont", "NKImage", "NKAudio", "NKMedia", "NKStream",
            "NKFileSystem", "NKLogger", "NKMath", "NKTime", "NKContainers",
            "NKMemory", "NKCore", "NKPlatform", "NKThreading", "NKNetwork"
        ]
    )

    with filter("system:Windows"):
        windowedapp()
        defines(["WIN32_LEAN_AND_MEAN", "_UNICODE", "UNICODE"])
        
```

- message post compilation de Jenga:

```
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Nyeck                                                          Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: mediaTest.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\Nyeck\Nyeck.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.02s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  22/22
Time:           2m4.6s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```