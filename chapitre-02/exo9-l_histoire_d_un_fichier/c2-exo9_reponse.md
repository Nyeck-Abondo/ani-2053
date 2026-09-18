# REPONSE DE L'EXERCICE 9

Le fichier qui a été choisi pour l'étude de cas ici est le fichier `NkAudioBackends.cpp` contenu dans `Kernel\Runtime\NKAudio\src\NKAudio\NkAudioBackends.cpp`

## RECONSTRUCTION DE LA CREATION

En tapant la commande `git log --oneline --graoh --decorate -- Kernel\Runtime\NKAudio\src\NKAudio\NkAudioBackends.cpp` dans le terminal, à la racine du dépôt de nkentseu, on obtien un légé historique de commit venant du fichier `NkAudioBackends.cpp`

```
* addf709d NKCode beta.8 a beta.11 : la ligne publiee rejoint enfin main (#86)

* 017ec0ca (origin/feat/nkcode-panneaux) feat(harmonyos): backend audio OHAudio — le son existe enfin sur OHOS

* 3f32fb11 fix(harmonyos): Mou et Pong demarrent enfin leur code natif

* 50ff3b5b GLES/MEmu : ecran noir corrige ; UBO clampe ; 33 operateurs JS restaures

* 9fc9f5f6 fix(nkaudio): ROOT CAUSE du son ralenti/bruite/intermittent - mixBuffer sous-dimensionne vs buffer device REEL. WASAPI demande jusqu'a bufferFrames (mesure: 1056 frames a 48000) par reveil callback, mais l'engine dimensionnait mixBuffer sur config.bufferSize=256 -> AudioCallback clampait frameCount (256/1056=24%) -> buffer device rempli a 24%, 76% silence -> dropouts massifs percus comme 'ralenti + bruit + pas toujours correct'. Fix: (1) WASAPI GetBufferSize() renvoie la VRAIE taille (mBufferSize=bufferFrames) au lieu du 256 demande ; (2) AudioEngine::Initialize resynchronise config (sampleRate/channels/frames) sur le format REELLEMENT negocie par le device et (re)dimensionne mixBuffer a max(bufferSize, framesReels)*channels. Corrige aussi le cas taux/canaux device != demande (resample vers le mauvais taux). NkAudioPlayer affiche desormais le format device reel.

* bdda350a style: reformatage clang-format repo-wide (Kernel/Engine/Applications)

* d4fce7ee feat(render): grille infinie reutilisable + fix ombres GL (glClipControl/clipZ01) + fix freeze DX11 (ResizeBuffers/command list) + NkInput cross-platform + cap FPS/vsync + pool object-UBO dynamique + ombres instanciees ; consolidation WIP multi-modules (NKCode, Noge, ...) (#19)

* 15156667 chore(runtime): audit NKMemory complet + fix portabilite NkHash LP64 (#5)

* 1f26ef96 Session 2026-05-29 — D-NkImage, Android APK restauré, Harmony compile

* bcc7c99d update
* commit bcc7c99d438f0103944d5bb712bf7e958790d3a5
| Author: LeTeguis <teuguiasederis@gmail.com>
| Date:   Thu May 21 13:36:03 2026 +0100
| 
|     update
| 
* commit d557314e707baf17e53029b9d9cae2c5164dd417
  Author: LeTeguis <teuguiasederis@gmail.com>
  Date:   Tue May 5 20:04:22 2026 +0100
  
      update
```

Cet historiaue réduit nous permet de retracer la vie de ce fichier comme suit

- **date de création** : Jeudi 5 mai 2026 à 20:04:22
- **dernière modification en date** : septembre 2026

## LES MOMENTS OU LE FICHIER A LE PLUS CHANGE
commande exécutée pour avoir accès à l'historique spécifique au fichier:

```
git log --decorate --graph -- Kernel\Runtime\NKAudio\src\NKAudio\NkAudioBackends.cpp
```

> le résultat de la commande est découpé car trop long pour être entièrement collé. Ci dessous se trouve uniquement les commits les plus interressants pour l'analyse des modifications majeures.

Après lescture des commits trouvés dans l'historique propre du fichier, on remarque que le fichier NKAudioBackend.cpp a changé principalement en trois endroits. Des modifications toutes majoritairement lié à la plateforme HArmony :

```
commit 017ec0ca3ac175a152b90c145fe69b59f487f5db (origin/feat/nkcode-panneaux)
| Author: LeTeguis <teuguiasederis@gmail.com>
| Date:   Tue Aug 11 18:39:35 2026 +0100
| 
|     feat(harmonyos): backend audio OHAudio — le son existe enfin sur OHOS
|     
|     Le silence total avait 2 etages, tous muets :
|     
|     1. AUCUN backend OHOS n'existait : HarmonyOS herite de PLATFORM_LINUX,
|        la selection AUTO choisissait "ALSA" (exclu de la compilation ET de
|        l'enregistrement sur OHOS) -> fallback Null = silence simule.
|        Nouveau OHAudioBackend (OH_AudioRenderer, miroir d'AAudio dont
|        l'API est un quasi-clone) + branche HARMONYOS AVANT LINUX dans la
|        selection AUTO.
|     
|     2. Deux pieges de l'emulateur NEXT (image 5.0.0.25), factures en
|        jscrash/hilog seulement :
|        - sa libohaudio.so n'exporte PAS les setters de callback modernes
|          (SetRendererWriteDataCallback / SetCapturerReadDataCallback,
|          API 12) : le symbole manquant fait echouer le dlopen de l'app EN
|          SILENCE, l'ArkTS recoit undefined ("Cannot read property
|          nkSetResMgr of undefined"). -> API STRUCT (API 10, depreciee de
|          tete mais ABI exportee partout), capture BASCULEE AUSSI (meme
|          mine des que NkAudioCapture.o est tire dans une app).
|        - son serveur audio REFUSE le format F32LE ("Unsupported audio
|          parameter", format: 4) -> F32LE d'abord (appareils reels), repli
|          S16LE avec conversion clamp du mixeur float dans le callback
|          (meme strategie que le backend OpenSL ES Android).
|     
|     Verifie sur emulateur : SetAudioStreamInfo Succeeded (format: 1),
|     StartAudioStream Start SUCCESS, WriteCallbackFunc actif.
|     Non-regression Windows NKAudio Debug + Release OK.
│

....
....

* commit 9fc9f5f6b6fee59a8a43af4a1e91c342b9ecd910
| Author: LeTeguis <teuguiasederis@gmail.com>
| Date:   Mon Jul 13 17:08:43 2026 +0100
| 
|     fix(nkaudio): ROOT CAUSE du son ralenti/bruite/intermittent - mixBuffer sous-dimensionne vs buffer device REEL. WASAPI demande jusqu'a bufferFrames (mesure: 1056 frames a 48000) par reveil callback, mais l'engine dimensionnait mixBuffer sur config.bufferSize=256 -> AudioCallback clampait frameCount (256/1056=24%) -> buffer device rempli a 24%, 76% silence -> dropouts massifs percus comme 'ralenti + bruit + pas toujours correct'. Fix: (1) WASAPI GetBufferSize() renvoie la VRAIE taille (mBufferSize=bufferFrames) au lieu du 256 demande ; (2) AudioEngine::Initialize resynchronise config (sampleRate/channels/frames) sur le format REELLEMENT negocie par le device et (re)dimensionne mixBuffer a max(bufferSize, framesReels)*channels. Corrige aussi le cas taux/canaux device != demande (resample vers le mauvais taux). NkAudioPlayer affiche desormais le format device reel.
| 

.....
.....

* commit 1f26ef965a87aaca651cb57ed1c2d11230ecc5ec
| Author: Rihen <rihen.universe@gmail.com>
| Date:   Fri May 29 23:36:49 2026 +0100
| 
|     Session 2026-05-29 — D-NkImage, Android APK restauré, Harmony compile
|     
|     D — NkImage hérite de NKIResource (NKStream/NKIResource.h)
|       * 9 overrides : LoadFromFile/Memory(2args)/Stream, SaveToFile/Memory/Stream,
|         IsValid, Unload. Retrait du =0 par défaut des LoadFromMemory(d,s,channels)
|         pour éviter ambiguïté 2-args vs 3-args.
|       * NKImage.jenga : +NKStream src + dependson NKStream.
|       * Cascade transitive : NKCanvas/NKCamera/NKEvent/NKRenderer compilent sans
|         toucher leurs jengas (propagation includedirs via dependson).
|     
|     Hot-plug/DPI Phase 2 — 9 backends NKWindow livrés
|       * XLib/XCB (XRandR + hot-plug), Wayland (wl_output multi), Cocoa/UIKit
|         (NSScreen/UIScreen + observers), Android (AConfiguration + JNI),
|         Emscripten (devicePixelRatio), HarmonyOS (OH_NativeDisplayManager_*),
|         Noop (factice). API NkWindow::EnumerateMonitors/GetCurrentMonitor/
|         GetMonitorCount + events NkSystemDisplayEvent + NkWindowDpiEvent.
|     
|     Harmony — NKWindow + chaîne kernel compile pour --platform harmony
|       * NkHarmonyGamepad : réécrit en stub aligné NkIGamepad (snapshot vide).
|       * NkHarmonyEventSystem.cpp stubbé (SDK header retiré + types obsolètes).
|       * NkHarmonyWindow.cpp : nativeWindow -> ohNativeWindow.
|       * NKAudio : ALSA exclu PLATFORM_LINUX si HARMONYOS/ANDROID ; climits
|         ajouté à NkOGGVorbisCodec (UINT_MAX).
|       * NKCanvas/OpenGL : 17 sites WAYLAND||ANDROID reçoivent ||HARMONYOS ;
|         macro NK_NATIVE_WIN(s) pour gérer s.nativeWindow vs s.ohNativeWindow.
|     
|     Cleanup
|       * NkUIFontBridge.h:221-223 : 3 lignes PowerShell collées par accident
|         en queue de fichier retirées.
|       * NKImage/ROADMAP.md + NKWindow/ROADMAP.md actualisés.
|     
|     À reprendre prochaine session
|       * Noge ECS includes obsolètes (NkGameObjectFactory.h, NkECSDefines.h).
|       * Pong : refonte sur NKCanvas (chantier A) résorbera NkSafeArea include.
|       * NkFont module : implémenter NKIResource (atlas-centric à évaluer).
| 
```

### La création du fichier

En se basant sur le commit le plus bas de la liste: celui d'indice **d557314e707baf17e53029b9d9cae2c5164dd417** , on peut conclure que le fichier **NkAudioBackends.cpp** a été créé un **jeudi 5 Mai 2026** à exactement 20:04:22.

### Les moments où il a le plus changé

Le fichier à principalement changé à trois moments précis. Ces instants sont repérables grace au hash des commits suivant : 

- Le premier commit le plus interressant ici est **017ec0ca3ac175a152b90c145fe69b59f487f5db** : C'est le premier cité dans la liste, et celui qui en lisant vers le bas présente l'évolution la plus marquante du `NKAudioBackend.cpp`.
  - Le sujet : Ce commit présente uniquement la création du backend audio pour le système harmonyOS.

  - Le Pourquoi : Le message du commit explique que le backend audio sous harmony n'exitait pas et que lors des exécutions des tests, la Selection automatique des platformes choisissait ALSA ce qui entrainait un silence simulé.

  - Les modifications apportées : La modificaition majeure apporté au fichier étudié ici est l'ajout fonctoinnel d'un backend audio fonctionnel pour permettre l'émission et l'enregistrement audio sous les systèmes harmony.

- le second commit **9fc9f5f6b6fee59a8a43af4a1e91c342b9ecd910** : C'est la dernière modification répertorié dans l'historique de ma version locale du dépôt, et celle qui indique aussi le plus de changement. Elle présente deux résolutions majeurs de bugs relatifs à l'ensemble des fichiers du modules NkAudio, et donc `NkAudioBackends.cpp`.
  - Le sujet : Le message du commit rend compte de la résolution de la cause centrale du son ralenti, bruite et intermitent et du mixbuffer sous-dimensionné par rapport au buffer device REEL.

  - Le pourquoi : Le message du commit justifie cette correction en expliquant que WASAPI demandait jusqu'à bufferFrame mais le moteur dimensionnait mixBuffer sur config.bufferSize=25 ce qui entrainait un clamping de frameCount à 24%. Les 76% de silence eux étaient donc responsable des trois anomalie que sont: les **ralenti**, et le **bruit pas toujours correcte** .

  - Les modifications apportées : Deux fix majeurs au total. LA correction de **WASAPI GetBufferSize()**, qui retourne la vrai taille du buffer; et la synchronise les configs.

- LE second commit **1f26ef965a87aaca651cb57ed1c2d11230ecc5ec** : Il traite de la chaine de compilation pour android et HarmonyOS.

  - **Le pourquoi** : Nentseu avant ce commit n'était pas encore capable de compiler pur la plateforme HarmonyOS. Le module audio et principalement le fichier étudié on vécu leur seconde modification.


- Le troisième commit **1f26ef965a87aaca651cb57ed1c2d11230ecc5ec** : C'est le troisième cité dans la liste des commits. Il apparait en temps normal presque avant dernier dans l'historique.

  - Le sujet : il introduit la phase que l'auteur nomme la session D. Celle dans laquelle il restaure l'APK Android et garanti la compilation pour le système harmony.

  - Le pourquoi: Dans le cadre de l'étude de notre fichier appartenant au module NKAudio, ce commit a influencé NKAudioBackend.cpp car ALSA n'excluait pas encore la macro PLATFORM_LINUX et que Le format de compression audio numérique **Ogg Vorbis** n'avait pas encore été implémenté dans le module audio.

  - Les modifications apportées : ICi, les modifications apportées identifiées par le commit sont au nombre de 2. L'exclusion de la macro d'identification de la plateforme linux par ALSA, mais aussi l'ajout de l'encodage audio numérique libre **Ogg Vorbis**.