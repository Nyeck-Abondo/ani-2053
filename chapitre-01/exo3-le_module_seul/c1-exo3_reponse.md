# Dépendances de NKMath
 > NKMath dépends très exactement de quatres modules dont la représentation se scématise comme suit :

```
                        ╔═════════════════════════════╗
                        ║                             ║
   ╔═══════════════════►║            NKMATH           ║ //(depends: NKContainers, NKCore, NKMemory, NKPlatform)
   ║                    ╚═════════════════════════════╝
   ║                                    ▲
   ║                                    ║
   ║                                    ║
   ║                    ╔═════════════════════════════╗
   ║                    ║                             ║
   ║         ╔═════╔═══►║         NKCONTAINERS        ║ //< depends: NKCore, NKMemory, NKPlatform
   ║         ║     ║    ╚═════════════════════════════╝
   ║         ║     ║                    ▲
   ║         ║     ║                    ║
   ║         ║     ║                    ║
   ║         ║     ║    ╔═════════════════════════════╗
   ║         ║     ║    ║                             ║ //< depends: NKCore, NKPlatform
   ║         ║     ╚════║          NKMEMORY           ║◄═══════╗
   ║         ║          ╚═════════════════════════════╝        ║
   ║         ║                          ▲                      ║
   ║         ║                          ║                      ║ 
   ║         ║                          ║                      ║
   ║         ║          ╔═════════════════════════════╗        ║
   ╚═════════╚══════════║                             ║        ║
   ║                    ║            NKCORE           ║        ║ //< depends: NKPlatform
   ║                    ╚═════════════════════════════╝        ║
   ║                                    ▲                      ║
   ║                                    ║                      ║
   ║                                    ║                      ║
   ║                    ╔═════════════════════════════╗        ║
   ╚════════════════════║                             ║        ║
                        ║          NKPLATFORM         ║════════╝
                        ╚═════════════════════════════╝
```