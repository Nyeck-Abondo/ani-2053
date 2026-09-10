# incompréhensions et analyse: Cas de NKAudio
Ci dessous le fichier jenga de NKaudio annoté lignes par lignes

```py
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
=============================================================================
NKAudio.jenga — Module audio AAA du framework Nkentseu
=============================================================================
"""

from Jenga import *
from jengaconfig import *

with project("NKAudio"):
    language("C++") #choix du langage, ici le c++
    cppdialect("C++17") #choix de la version de c++ utilisée. ici c++17
    location(".") #emplacement du module dans l'arborécence du projet

    pchheader("pch/pch.h") #???????
    pchsource("pch/pch.cpp") #??????

    nkentseudependson(
        #DEPENDANCES
        #Modules à compiler avant de passer à NKAudio
        ["NKPlatform", "NKCore", "NKMemory", "NKContainers", "NKLogger", "NKThreading", "NKFileSystem", "NKStream", "NKMedia"],
        selfexport="NKAudio",
        extra_includes=["src"],
    )

    #SOURCES
    files([ # fichiers sources entrant dans la compilation de NKAudio
        "src/NKAudio/**.cpp",
        "src/NKAudio/**.h",
        "pch/pch.h",
        "pch/pch.cpp",
    ])

    #Emplacement de création de fichiers objets
    objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
    #Emplacement de création des Exécutables
    targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}")

    # ── Configurations ────────────────────────────────────────────────────────

    #bloc à exécuté sur la compilation est lancée en mode Debug
    with filter("config:Debug"):
        defines(["_DEBUG", "DEBUG", "NKENTSEU_DEBUG"]) #???????????????
        optimize("Off") #désactivation des optimisations du code (-02, -03...)
        symbols(True) # ajout des symboles

    #bloc à exécuté sur la compilation est lancée en mode Release
    with filter("config:Release"):
        defines(["NDEBUG", "RELEASE", "NKENTSEU_RELEASE"]) #????????????
        optimize("Speed") #optimisations activée -02
        symbols(False) #Désactivation des symboles

    #FILTRE
    with filter("config:Distribution"): #??????????????????????????
        defines(["NDEBUG", "DISTRIBUTION", "NKENTSEU_DISTRIBUTION"]) #??????????????
        optimize("Speed") #optimisations activée -02
        symbols(False) #Désactivation des symboles

    # ── Toolchains par plateforme ─────────────────────────────────────────────

    #FILTRE
    with filter("system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne"):
        usetoolchain(TC_WINDOWS)
        # WASAPI requiert ole32 + mmdevapi
        links(["ole32", "winmm", "avrt"])

    #FILTRE
    with filter("system:UWP || system:Windows && options:windows-runtime=uwp"): # ???????????????????? sytem::UWP
        usetoolchain("xbox-clang")
        links(["ole32", "mmdevapi", "avrt"])

    #FILTRE
    with filter("system:macOS"):
        usetoolchain("clang-native")
        links([
            "AudioToolbox.framework",
            "CoreAudio.framework",
            "CoreFoundation.framework",
        ])

    #bloc de code à exécuter si le système est IOS
    #FILTRE
    with filter("system:iOS"):
        usetoolchain("clang-native-ios") #utilisation privilégiée de la chaine de compilation IOS
        links([#bibliothèque à ajouter durant l'édition des liens
            "AudioToolbox.framework",
            "AVFoundation.framework",
            "CoreAudio.framework",
        ])

    #FILTRE
    #bloc à exécuter si le système d'exploitation est android
    with filter("system:Android"):
        usetoolchain("android-ndk") #chaine de compilation pour android
        androidminsdk(24)#version minimale du sdk android requise
        links(["dl", "OpenSLES"])#bibliothèque à introduire durant l'édition de lien

    #FILTRE
    #bloc à exécuter si le système d'exploitation est HarmonyOS
    with filter("system:HarmonyOS"):
        # PCH desactive (NDK OHOS clang, meme contrainte qu'Android).
        pchheader("") #?????????????????
        pchsource("") #?????????????????
        usetoolchain("ohos-ndk") #Chaine de compilation harmoyOS

        # Backend audio OHOS via #ifdef. dl pour dlopen/dlsym.
        # ohaudio = capture micro (OH_AudioCapturer). OpenSLES retire (specifique Android).
        links(["dl", "ohaudio"])

    #FILTRE
    with filter("system:Linux"):
        usetoolchain("clang-native")
        links(["asound", "pthread", "m"])  # ALSA + pthreads + math

    #FILTRE
    with filter("system:Web"):
        usetoolchain("emscripten")

    #FILTRE
    with filter("system:XboxSeries || system:XboxOne"):
        usetoolchain("xbox-clang")

    # ── UWP ──────────────────────────────────────────────────────────────────

    #FILTRE
    with filter("system:Windows && options:windows-runtime=uwp"):
        objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}-uwp/%{prj.name}")
        targetdir("%{wks.location}/Build/Lib/%{cfg.buildcfg}-%{cfg.system}-uwp")

    # ── Tests (desktop uniquement) ────────────────────────────────────────────

    #FILTRE
    with filter(
        "(system:Linux || system:macOS || "
        "(system:Windows && !options:windows-runtime=uwp && "
        "!system:XboxSeries && !system:XboxOne)) && !system:Android && !system:iOS"
    ):
        #TESTS
        with test():
            testfiles(["tests/**.cpp"])
            includedirs(["tests"])

```