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
Par ailleurs, on observe une erreure au niveau de l'édition de lien dans le cas où le projet compilé dépendait d'autres projets du type **staticlib** ou **sharedlib**.

```
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Simulation                                                      Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                Compilation Error: Link Failed                                ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-01\exo6-les_deux_erreurs_d ║
║ e_dependance\MyProject\Build\Obj\Debug-Windows\Simulation\src_main.obj: in function `main':  ║
║ C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-01\exo6-les_deux_erreurs_d ║
║ e_dependance\MyProject\src/main.cpp:11:(.text+0x65): undefined reference to                  ║
║ `simul::World::Init(simul::math::Vec2, float)'                                               ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-01\exo6-les_deux_erreurs_d ║
║ e_dependance\MyProject\src/main.cpp:17:(.text+0xe8): undefined reference to                  ║
║ `simul::World::applyRandomMove()'                                                            ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-01\exo6-les_deux_erreurs_d ║
║ e_dependance\MyProject\src/main.cpp:18:(.text+0xf2): undefined reference to                  ║
║ `simul::World::ShowAllPosition()'                                                            ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-01\exo6-les_deux_erreurs_d ║
║ e_dependance\MyProject\src/main.cpp:21:(.text+0x127): undefined reference to                 ║
║ `simul::World::RandomSuicide()'                                                              ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-01\exo6-les_deux_erreurs_d ║
║ e_dependance\MyProject\src/main.cpp:22:(.text+0x131): undefined reference to                 ║
║ `simul::World::ShowAllPosition()'                                                            ║
║ clang++: error: linker command failed with exit code 1 (use -v to see invocation)            ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✗ Link failed: Build\Bin\Debug-Windows\Simulation\Simulation.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 0.85s  │
│ Errors: 6  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/4
Failed:         1
Not reached:    2  (arret au premier echec — voir --keep-going)
Errors:         6
Time:           1.42s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ Simulation
```

Dans un autre projet créé depuis nkentseu, on observe le même comportement lorque l'on relance la constrution du projet après suppression préalable du dossier **Build**. Cela révèle deux points important dans le rôle de `dependson`. Le premier, l'omission de dépendson dans un prjet précis du workspace n'influence pas le succès de la compilation des projets qui ont une priorité supérieure à lui, mais les erreurs sont rencontrées plus tard dès la construction du projet concerné. Et deuxièment **dependson** inclu dans la commande de compilation du projet qui l'appel les résultat de la construction des projets mentionnés dans la liste qu'il acceuille (les **staticlib** ou les **sharedlib** par exemple). Ce qui justifie l'erreur de linking.

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
║                                Compilation Error: Link Failed                                ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKCanvas.lib(src_N ║
║ KCanvas_Backend_DirectX_NkDX11ComputeContext.obj): in function                               ║
║ `nkentseu::NkDX11ComputeContext::CreateShaderFromSource(char const*, char const*)':          ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Runtime\NKCanvas\src\NKCanvas\Backe ║
║ nd\DirectX/NkDX11ComputeContext.cpp:188:(.text+0xaae): undefined reference to `D3DCompile'   ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKCanvas.lib(src_N ║
║ KCanvas_Backend_DirectX_NkDX12ComputeContext.obj): in function                               ║
║ `nkentseu::NkDX12ComputeContext::CreateShaderFromSource(char const*, char const*)':          ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Runtime\NKCanvas\src\NKCanvas\Backe ║
║ nd\DirectX/NkDX12ComputeContext.cpp:259:(.text+0x115e): undefined reference to `D3DCompile'  ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKCanvas.lib(src_N ║
║ KCanvas_Backend_DirectX_NkDX12Renderer2D.obj): in function                                   ║
║ `nkentseu::renderer::NkDX12Renderer2D::CreatePSOs()':                                        ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Runtime\NKCanvas\src\NKCanvas\Backe ║
║ nd\DirectX/NkDX12Renderer2D.cpp:720:(.text+0x2799): undefined reference to `D3DCompile'      ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Runtime\NKCanvas\src\NKCanvas\Backe ║
║ nd\DirectX/NkDX12Renderer2D.cpp:727:(.text+0x29b0): undefined reference to `D3DCompile'      ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKCanvas.lib(src_N ║
║ KCanvas_Backend_DirectX_NkDX11Renderer2D.obj): in function                                   ║
║ `nkentseu::renderer::NkDX11Renderer2D::CreateShaders()':                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Runtime\NKCanvas\src\NKCanvas\Backe ║
║ nd\DirectX/NkDX11Renderer2D.cpp:323:(.text+0xdc9): undefined reference to `D3DCompile'       ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKCanvas.lib(src_N ║
║ KCanvas_Backend_DirectX_NkDX11Renderer2D.obj):C:\Users\Administrator\Documents\Git_pro\Nkent ║
║ seu\Kernel\Runtime\NKCanvas\src\NKCanvas\Backend\DirectX/NkDX11Renderer2D.cpp:329: more      ║
║ undefined references to `D3DCompile' follow                                                  ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Core_NkNetDefines.obj): in function `nkentseu::net::NkHToN16(unsigned short)':     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Core ║
║ /NkNetDefines.cpp:189:(.text+0x601): undefined reference to `__imp_htons'                    ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Core_NkNetDefines.obj): in function `nkentseu::net::NkHToN32(unsigned int)':       ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Core ║
║ /NkNetDefines.cpp:209:(.text+0x65f): undefined reference to `__imp_htonl'                    ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Core_NkNetDefines.obj): in function `nkentseu::net::NkHToN64(unsigned long long)': ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Core ║
║ /NkNetDefines.cpp:229:(.text+0x6b0): undefined reference to `__imp_htonl'                    ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Core ║
║ /NkNetDefines.cpp:230:(.text+0x6d2): undefined reference to `__imp_htonl'                    ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function                                               ║
║ `nkentseu::net::NkAddress::NkAddress(sockaddr_in const&)':                                   ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:190:(.text+0x336): undefined reference to `__imp_ntohs'                   ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function                                               ║
║ `nkentseu::net::NkAddress::NkAddress(sockaddr_in6 const&)':                                  ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:202:(.text+0x3d6): undefined reference to `__imp_ntohs'                   ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function                                               ║
║ `nkentseu::net::NkAddress::ToSockAddr(sockaddr_storage&, int&) const':                       ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:217:(.text+0x477): undefined reference to `__imp_htons'                   ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:227:(.text+0x4e3): undefined reference to `__imp_htons'                   ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function `nkentseu::net::NkAddress::Resolve(char       ║
║ const*, unsigned short, nkentseu::net::NkAddress::Family)':                                  ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:307:(.text+0x7d9): undefined reference to `__imp_getaddrinfo'             ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:327:(.text+0x930): undefined reference to `__imp_freeaddrinfo'            ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function `nkentseu::net::NkSocket::Close()':           ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:580:(.text+0x1054): undefined reference to `__imp_closesocket'            ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function                                               ║
║ `nkentseu::net::NkSocket::Create(nkentseu::net::NkAddress const&,                            ║
║ nkentseu::net::NkSocket::Type)':                                                             ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:538:(.text+0x121b): undefined reference to `__imp_socket'                 ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:561:(.text+0x1358): undefined reference to `__imp_bind'                   ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function `NkGetLastSocketError()':                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:48:(.text+0x1457): undefined reference to `__imp_WSAGetLastError'         ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function                                               ║
║ `nkentseu::net::NkSocket::SetSendBufferSize(unsigned int)':                                  ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:679:(.text+0x14c4): undefined reference to `__imp_setsockopt'             ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function                                               ║
║ `nkentseu::net::NkSocket::SetRecvBufferSize(unsigned int)':                                  ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:692:(.text+0x1544): undefined reference to `__imp_setsockopt'             ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function                                               ║
║ `nkentseu::net::NkSocket::SetNonBlocking(bool)':                                             ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:597:(.text+0x15c1): undefined reference to `__imp_ioctlsocket'            ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function                                               ║
║ `nkentseu::net::NkSocket::SetBroadcast(bool)':                                               ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:631:(.text+0x168b): undefined reference to `__imp_setsockopt'             ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function `nkentseu::net::NkSocket::SetNoDelay(bool)':  ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:647:(.text+0x1738): undefined reference to `__imp_setsockopt'             ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function                                               ║
║ `nkentseu::net::NkSocket::SetReuseAddr(bool)':                                               ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:663:(.text+0x17db): undefined reference to `__imp_setsockopt'             ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function `nkentseu::net::NkSocket::SendTo(void const*, ║
║ unsigned int, nkentseu::net::NkAddress const&)':                                             ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:731:(.text+0x1af2): undefined reference to `__imp_sendto'                 ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function `nkentseu::net::NkSocket::RecvFrom(void*,     ║
║ unsigned int, unsigned int&, nkentseu::net::NkAddress&)':                                    ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:782:(.text+0x1f98): undefined reference to `__imp_recvfrom'               ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function `nkentseu::net::NkSocket::Listen(unsigned     ║
║ int)':                                                                                       ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:850:(.text+0x2363): undefined reference to `__imp_listen'                 ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function                                               ║
║ `nkentseu::net::NkSocket::Connect(nkentseu::net::NkAddress const&)':                         ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:867:(.text+0x2455): undefined reference to `__imp_connect'                ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function                                               ║
║ `nkentseu::net::NkSocket::Accept(nkentseu::net::NkSocket&, nkentseu::net::NkAddress&)':      ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:895:(.text+0x255d): undefined reference to `__imp_accept'                 ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function `nkentseu::net::NkSocket::Send(void const*,   ║
║ unsigned int)':                                                                              ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:939:(.text+0x2733): undefined reference to `__imp_send'                   ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function `nkentseu::net::NkSocket::Recv(void*,         ║
║ unsigned int, unsigned int&)':                                                               ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:961:(.text+0x27f4): undefined reference to `__imp_recv'                   ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function `nkentseu::net::NkSocket::PlatformInit()':    ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:1008:(.text+0x28eb): undefined reference to `__imp_WSAStartup'            ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:1018:(.text+0x2a0e): undefined reference to `__imp_WSACleanup'            ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function                                               ║
║ `nkentseu::net::NkSocket::PlatformShutdown()':                                               ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:1031:(.text+0x2a47): undefined reference to `__imp_WSACleanup'            ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-Windows\NKNetwork.lib(src_ ║
║ NKNetwork_Transport_NkSocket.obj): in function                                               ║
║ `nkentseu::net::NkSocket::Select(nkentseu::NkSpan<nkentseu::net::NkSocket*>, unsigned int,   ║
║ nkentseu::NkVector<unsigned int, nkentseu::memory::NkAllocator>&)':                          ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:1092:(.text+0x2cef): undefined reference to `__imp_select'                ║
║ C:/msys64/ucrt64/bin/ld:                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport/NkSocket.cpp:1119:(.text+0x2e47): undefined reference to `__WSAFDIsSet'                ║
║ clang++: error: linker command failed with exit code 1 (use -v to see invocation)            ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✗ Link failed: Build\Bin\Debug-Windows\ChatChat-Kongossa\ChatChat-Kongossa.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 3.48s  │
│ Errors: 38  | Failed files: 1                                                                │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  21/22
Failed:         1
Errors:         38
Warnings:       27
Time:           1m12.4s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ ChatChat-Kongossa
```

On observe la répétition d'erreurs venant de la part de l'éditeur de lien concernant les fonctions de la bibliothèque `winsock` et DirectX. Link sert donc à la liaison de bibliothèque déjà existantes dans la commande de compilation finale du projet. Elle n'a pas recour au resultat de la construction d'un projet inérant au workspace, mais plutôt à des bibliothèques **statiques** ou **dynamiques** déjà présentes avant dans la construction dans le disque de la machine.