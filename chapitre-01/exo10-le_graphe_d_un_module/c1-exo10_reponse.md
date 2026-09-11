# REPONSES A L'EXERCICE 10

## Identifications des dépendances de `NkCanvas`

D'après la ligne 
```py
_canvasDeps = ["NKWindow", "NKFont", "NKImage", "NKStream", "NKTime", "NKGlad", "NKThreading"]
```
le module `NkCanvas` dépend de façon directe de **7** modules différents: **NKWindow**, **NKFont**, **NKImage**, **NKStream**, **NKTime**, **NKGlad** et enfin **NKThreading**

## Identification des dépendances des dépendances de `NkCanvas`

- **Cas de `NKWindow`** : d'après les modules identifiers entre les lignes **56** et **60** du NKWindow.jenga

```py
nkentseudependson(
        ["NKPlatform", "NKCore", "NKLogger", "NKMath", "NKTime", "NKContainers", "NKMemory", "NKThreading", "NKEvent", "NKFileSystem"],
        selfexport="NKWindow",
        extra_includes=["src", "%{wks.location}/Externals"],
    )
```
on constqte aue NKWindow dépend de 10 modules: **NKPlatform**, **NKCore**, **NKLogger**, **NKMath**, **NKTime**, **NKContainers**, **NKMemory**, **NKThreading**, **NKEvent**, **NKFileSystem**

- **cas de `NKFont`** : lui d'après les modules identifiers dans NKFont.jenga entre les lignes **35** et **39**, NKFont dépend de : **NKPlatform**, **NKCore**, **NKMemory**; **NKMath**, **NKContainers**, **NKThreading**, **NKLogger**
```py
nkentseudependson(
        ["NKPlatform", "NKCore", "NKMemory", "NKMath", "NKContainers", "NKThreading", "NKLogger"],
        selfexport="NKFont",
        extra_includes=["src"],
    )
```

- **cas de `NKImage`** : son .Jenga quadn à lui laisse transparaître 9 dépendances, que sont : **NKPlatform**, **NKCore**, **NKMemory**, **NKMath**, **NKContainers**, **NKLogger**, **NKThreading**, **NKFileSystem**, **NKStream**

```py
nkentseudependson(
        ["NKPlatform", "NKCore", "NKMemory", "NKMath", "NKContainers", "NKLogger", "NKThreading", "NKFileSystem", "NKStream"],
        selfexport="NKImage",
        extra_includes=["src"],
    )
```
- **cas de `NKStream`**: NKStream présente 7 dépendances qui sont : **NKCore**, **NKPlatform**, **NKLogger**, **NKMemory**,
**NKContainers**, **NKThreading**, **NKFileSystem**. Tel que présenté entre les lignes 21 et 25 de son fichier .jenga

```py
nkentseudependson(
        ["NKCore", "NKPlatform", "NKLogger", "NKMemory", "NKContainers", "NKThreading", "NKFileSystem"],
        selfexport="NKStream",
        extra_includes=["src", "pch"],
    )
```

- **cas de `NKTime`** : `NKTime` possède 5 dépendances distinctes. **NKContainers**, **NKMemory**, **NKLogger**, **NKCore** et **NKPlatform**, tel que présenté de la ligne **22** à **26** de `NKTime.jenga`.

```py
nkentseudependson(
        ["NKContainers", "NKMemory", "NKLogger", "NKCore", "NKPlatform"],
        selfexport="NKTime",
        extra_includes=["src", "pch"],
    )
```

- **Cas de `NKGlad`** : `NKGlad` pour sa part ne compte aucune dépendance. Son NKGlad.Jenga ne présente aucune liste du genre dans un `dependson`.

- **cas de `NKThreading`** : s'agissant de ce module, le nombre de dépendance que son fichier point jenga met en évidence est de
**4**: **NKCore**, **NKPlatform**, **NKMemory** et **NKContainers**.

```py
nkentseudependson(
        ["NKCore", "NKPlatform", "NKMemory", "NKContainers"],
        selfexport="NKThreading",
        extra_includes=["src", "pch"],
    )
```

## Dessin du graphe de `NKCanvas`

```
                                                                     ┌────────────────┐
                                ┌───────────────────────────┬───────►│    NKCANVAS    │◄───────────────────────────────┬─────────────────────┐
                                │                           │        └────────────────┘                                │                     │
                                │                           │                                                          │                     │ 
                                │                           │                                                          │                     │
                                │                           │                                                          │                     │
                        ┌────────────────┐           ┌────────────────┐                                        ┌────────────────┐    ┌────────────────┐
                ┌──────►│    NKWINDOW    │           │    NKIMAGE     │                                        │   NKFONT       │    │     NKGLAD     │
                │       └────────────────┘           └────────────────┘                                        └────────────────┘    └────────────────┘
                │                   ▲                             ▲                                                     ▲                                                
                │                   │                             │                                                     │
                │                   │                             │                                                     │
        ┌────────────────┐          │                             │              ┌────────────────┐                     │                
   ┌───►│    NKTIME      │          │                             ├──────────────│    NKSTREAM    │◄────┐               │
   │    └────────────────┘          │                             │              └────────────────┘     │               │ 
   │                                │                             │                     ▲               │               │
   │                                └─────────────────────────────┼─────────────────────┼───────────────│───────────────┘
   │    ┌────────────────┐                                        │                     │      ┌────────────────┐                
   │    │    NKLOGGER    │────────────────────────────────────────│────────────────────────────│  NKTHREADING   │                    
   │    └────────────────┘                ┌────────────────┐      │                     │      └────────────────┘                            
   │                                      │   NKMATH       │──────┤                     │                                  
   │                                      └────────────────┘      │                     │                                   
   │                                                              │                     │                                           
   │                                                              │              ┌────────────────┐                                        
   │                                                              ├──────────────│  NKFILESYSTEM  │
   │                                                              │              └────────────────┘
   │                                                              │
   │                                                              │
   └──────────────────────────────────────────────────────────────┤                           
                                                                  │
                                                                  │
                                                                  │
            ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐           
            │                                   │                                     │                                      │
        ┌────────────────┐                ┌────────────────┐                   ┌────────────────┐                       ┌────────────────┐
        │  NKPLATFORM    │                │    NKMEMORY    │                   │    NKCORE      │                       │  NKCONTAINERS  │
        └────────────────┘                └────────────────┘                   └────────────────┘                       └────────────────┘
```