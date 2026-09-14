> Ces resultqts sont obtenus sur un DELL inspiron 7501m dot2 de windows 11, le SDK android et harmony et les compilateurs clang++ et g++

# Le depôt entier de nkentseu

commade :

```
jenga build
```


```bash
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKAudio                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 18 source file(s)
✓   [1/18] Compiled: NkAudioEffects.cpp
✓   [2/18] Compiled: NkAudioMixer.cpp
✓   [3/18] Compiled: NkAudioGenerator.cpp
✓   [4/18] Compiled: NkOpusCodec.cpp
✓   [5/18] Compiled: NkAudioLoader.cpp
✓   [6/18] Compiled: NkAudioAnalyzer.cpp
✓   [7/18] Compiled: NkDenoiser.cpp
✓   [8/18] Compiled: NkFLACCodec.cpp
✓   [9/18] Compiled: NkMP3Codec.cpp
✓   [10/18] Compiled: NkAudioBus.cpp
✓   [11/18] Compiled: NkOGGVorbisCodec.cpp
✓   [12/18] Compiled: NkAudioEngineCore.cpp
✓   [13/18] Compiled: NkHrtfDataset.cpp
✓   [14/18] Compiled: NkAudioStream.cpp
✓   [15/18] Compiled: NkContainerAudioStream.cpp
✓   [16/18] Compiled: NkAudioBackends.cpp
✓   [17/18] Compiled: NkAudioCapture.cpp
✓   [18/18] Compiled: NkAudioStreamPlayer.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKAudio.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.21s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCanvas                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 30 source file(s)
✓   [1/30] Compiled: NkSoftwareComputeContext.cpp
✓   [2/30] Compiled: NkDX11ComputeContext.cpp
✓   [3/30] Compiled: NkDX12ComputeContext.cpp
✓   [4/30] Compiled: NkOpenGLContext.cpp
✓   [5/30] Compiled: NkDX11Renderer2D.cpp
✓   [6/30] Compiled: NkDX11Context.cpp
✓   [7/30] Compiled: NkSoftwareContext.cpp
✓   [8/30] Compiled: NkDX12Renderer2D.cpp
✓   [9/30] Compiled: NkOpenGLComputeContext.cpp
✓   [10/30] Compiled: NkDX12Context.cpp
✓   [11/30] Compiled: NkOpenGLRenderer2D.cpp
✓   [12/30] Compiled: NkRenderer2DTypes.cpp
✓   [13/30] Compiled: NkVulkanComputeContext.cpp
✓   [14/30] Compiled: NkGpuPolicy.cpp
✓   [15/30] Compiled: NkBatchRenderer2D.cpp
✓   [16/30] Compiled: NkFont.cpp
✓   [17/30] Compiled: NkShader.cpp
✓   [18/30] Compiled: NkSoftwareRenderer2D.cpp
✓   [19/30] Compiled: NkVulkanContext.cpp
✓   [20/30] Compiled: NkVulkanRenderer2D.cpp
✓   [21/30] Compiled: NkContextFactory.cpp
✓   [22/30] Compiled: NkRenderer2DFactory.cpp
✓   [23/30] Compiled: NkShape.cpp
✓   [24/30] Compiled: NkTexture.cpp
✓   [25/30] Compiled: NkSprite.cpp
✓   [26/30] Compiled: NkRenderTarget.cpp
✓   [27/30] Compiled: NkRenderTexture.cpp
✓   [28/30] Compiled: NkUICanvasBackend.cpp
✓   [29/30] Compiled: NkRenderWindow.cpp
✓   [30/30] Compiled: NkRenderWindowCapture.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKCanvas.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 11.59s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: RendererRHI                                                    Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.06s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKUID                                                          Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: NkUIDemo.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\NKUID\NKUID.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.43s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKUIDemo                                                       Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 2 source file(s)
✓   [1/2] Compiled: NkUINKRHIBackend.cpp
✓   [2/2] Compiled: NkUIDemoNKEngine.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\NKUIDemo\NKUIDemo.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.76s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Model                                                          Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\Model\Model.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.57s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkSWRasterPrimitives                                           Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.08s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkFontDemo                                                     Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.09s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkRHIDemoFullSL                                                Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: NkRHIDemoFullSL.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\NkRHIDemoFullSL\NkRHIDemoFullSL.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 5.56s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKUIIntegration                                                  Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: NkUIRHIBackend.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKUIIntegration.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.27s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkRHIDemoFull                                                  Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: NkRHIDemoFull.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\NkRHIDemoFull\NkRHIDemoFull.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.72s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkRHIDemoFullImage                                             Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: NkRHIDemoFullImage.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\NkRHIDemoFullImage\NkRHIDemoFullImage.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.92s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKGuiIntegration                                                 Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: NkGuiRHIBackend.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKGuiIntegration.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.95s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKTensor                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 3 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.10s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NkRHIDemoText                                                  Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                             Compilation Error: NkRHIDemoText.cpp                             ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:221:10: error: unknown type name 'nk_handle'                            ║
║ 221 |                 static nk_handle Upload(nk_uint32 pageIndex, const nk_uint8 *pixels,   ║
║ nk_size byteSize, nk_uint32 width,                                                           ║
║       |                        ^                                                             ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:222:47: error: unknown type name 'nk_handle'                            ║
║ 222 |                                                                 nk_uint32 height,      ║
║ nk_uint32 channels, nk_handle existingHandle, void *userPtr) {                               ║
║ |                                                                                            ║
║ ^                                                                                            ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:225:12: error: use of undeclared identifier 'NK_INVALID_HANDLE'; did    ║
║ you mean 'nkentseu::core::INVALID_HANDLE'?                                                   ║
║   225 |                                 return NK_INVALID_HANDLE;                            ║
║       |                                        ^~~~~~~~~~~~~~~~~                             ║
║       |                                        nkentseu::core::INVALID_HANDLE                ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Foundation\NKCore\src/NKCore/NkType ║
║ s.h:1016:22: note: 'nkentseu::core::INVALID_HANDLE' declared here                            ║
║  1016 |                 constexpr NkHandle INVALID_HANDLE = 0;                               ║
║       |                                    ^                                                 ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:227:4: error: use of undeclared identifier 'NK_UNUSED'                  ║
║   227 |                         NK_UNUSED(pageIndex);                                        ║
║       |                         ^~~~~~~~~                                                    ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:228:4: error: use of undeclared identifier 'NK_UNUSED'                  ║
║   228 |                         NK_UNUSED(byteSize);                                         ║
║       |                         ^~~~~~~~~                                                    ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:234:26: error: use of undeclared identifier 'NK_INVALID_HANDLE'; did    ║
║ you mean 'nkentseu::core::INVALID_HANDLE'?                                                   ║
║ 234 |                         if (existingHandle == NK_INVALID_HANDLE ||                     ║
║ !ctx->hTexture.IsValid()) {                                                                  ║
║       |                                               ^~~~~~~~~~~~~~~~~                      ║
║       |                                               nkentseu::core::INVALID_HANDLE         ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Foundation\NKCore\src/NKCore/NkType ║
║ s.h:1016:22: note: 'nkentseu::core::INVALID_HANDLE' declared here                            ║
║  1016 |                 constexpr NkHandle INVALID_HANDLE = 0;                               ║
║       |                                    ^                                                 ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:246:13: error: use of undeclared identifier 'NK_INVALID_HANDLE'; did    ║
║ you mean 'nkentseu::core::INVALID_HANDLE'?                                                   ║
║   246 |                                         return NK_INVALID_HANDLE;                    ║
║       |                                                ^~~~~~~~~~~~~~~~~                     ║
║       |                                                nkentseu::core::INVALID_HANDLE        ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Foundation\NKCore\src/NKCore/NkType ║
║ s.h:1016:22: note: 'nkentseu::core::INVALID_HANDLE' declared here                            ║
║  1016 |                 constexpr NkHandle INVALID_HANDLE = 0;                               ║
║       |                                    ^                                                 ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:693:3: error: unknown type name 'NkFontLibrary'                         ║
║   693 |                 NkFontLibrary &fontLib() {                                           ║
║       |                 ^                                                                    ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:710:3: error: unknown type name 'NkFontLibrary'                         ║
║   710 |                 NkFontLibrary mFontLib;                                              ║
║       |                 ^                                                                    ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:711:3: error: unknown type name 'NkTextShaper'; did you mean            ║
║ 'NkTagShader'?                                                                               ║
║   711 |                 NkTextShaper mShaper;                                                ║
║       |                 ^~~~~~~~~~~~                                                         ║
║       |                 NkTagShader                                                          ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkType ║
║ s.h:47:9: note: 'NkTagShader' declared here                                                  ║
║    47 |         struct NkTagShader {};                                                       ║
║       |                ^                                                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:714:3: error: unknown type name 'nk_handle'                             ║
║   714 |                 nk_handle mLastAtlasHandle = NK_INVALID_HANDLE;                      ║
║       |                 ^                                                                    ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:728:3: error: unknown type name 'NkShapeResult'                         ║
║ 728 |                 NkShapeResult mShapeResult2D; ///< Résultat shape 2D — réutilisé       ║
║ chaque frame                                                                                 ║
║       |                 ^                                                                    ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:729:3: error: unknown type name 'NkShapeResult'                         ║
║ 729 |                 NkShapeResult mShapeResult3D; ///< Résultat shape 3D — réutilisé       ║
║ chaque frame                                                                                 ║
║       |                 ^                                                                    ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:730:3: error: unknown type name 'NkShapeResult'                         ║
║   730 |                 NkShapeResult mMeasureResult; ///< Résultat shape mesure HUD         ║
║       |                 ^                                                                    ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:296:5: error: unknown type name 'NkFontLibraryDesc'                     ║
║   296 |                                 NkFontLibraryDesc libDesc;                           ║
║       |                                 ^                                                    ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:310:23: error: use of undeclared identifier 'NK_LOAD_OUTLINES'          ║
║ 310 |                                 nk_uint32 flags = NK_LOAD_OUTLINES | NK_LOAD_KERNING;  ║
║       |                                                   ^~~~~~~~~~~~~~~~                   ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:310:42: error: use of undeclared identifier 'NK_LOAD_KERNING'           ║
║ 310 |                                 nk_uint32 flags = NK_LOAD_OUTLINES | NK_LOAD_KERNING;  ║
║       |                                                                      ^~~~~~~~~~~~~~~ ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:311:5: error: unknown type name 'NkFontResult'; did you mean            ║
║ 'NkRHIResult'?                                                                               ║
║ 311 |                                 NkFontResult fr = mFontLib.LoadFromFile(fontPath,      ║
║ flags, mFontId);                                                                             ║
║       |                                 ^~~~~~~~~~~~                                         ║
║       |                                 NkRHIResult                                          ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Runtime\NKRHI\src/NKRHI/Core/NkType ║
║ s.h:480:13: note: 'NkRHIResult' declared here                                                ║
║   480 |         enum class NkRHIResult : uint32 {                                            ║
║       |                    ^                                                                 ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base ║
║ 03\NkRHIDemoText.cpp:313:9: error: invalid argument type 'NkRHIResult' to unary expression   ║
║   313 |                                 if (!fr) {                                           ║
║       |                                     ^~~                                              ║
║ fatal error: too many errors emitted, stopping now [-ferror-limit=]                          ║
║ 20 errors generated.                                                                         ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

✗ ✗ Compilation failed: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Applications\Sandbox\src\DemoNkentseu\Base03\NkRHIDemoText.cpp

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 2.44s  │
│ Errors: 20  | Failed files: 1                                                                │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  62/171
Failed:         1
Not reached:    108  (arret au premier echec — voir --keep-going)
Errors:         20
Time:           1m7.8s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ NkRHIDemoText
```

# pong sur HarmonyOS

```bash
 jenga build --platform HarmonyOS --target Pong  
```

```bash
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
Target:        HarmonyOS x86_64
Toolchain:     ohos-ndk

Build Order (21 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKGlad [STATIC_LIB] → 
  3. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  4. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  5. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  6. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  7. NKThreading [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  8. NKLogger [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform, NKThreading) → 
  9. NKFileSystem [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  10. NKFont [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  11. NKTime [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  12. NKStream [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  13. NKNetwork [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  14. NKEvent [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  15. NKImage [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading) → 
  16. NKWindow [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  17. NKUI [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  18. NKMedia [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  19. NKCanvas [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKUI, NKWindow) → 
  20. NKAudio [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading) → 
  21. Pong [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKNetwork, NKPlatform, NKStream, NKThreading, NKTime, NKUI, NKWindow)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkArchDetect.cpp
✓   [2/7] Compiled: NkCGXDetect.cpp
✓   [3/7] Compiled: NkCompilerDetect.cpp
✓   [4/7] Compiled: NkCPUFeatures.cpp
✓   [5/7] Compiled: NkEndianness.cpp
✓   [6/7] Compiled: NkPlatformConfig.cpp
✓   [7/7] Compiled: NkEnv.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKPlatform.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.33s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKGlad                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

No source files found for project NKGlad

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkAssert.cpp
✓   [2/5] Compiled: NkLimits.cpp
✓   [3/5] Compiled: NkBits.cpp
✓   [4/5] Compiled: NkTraits.cpp
✓   [5/5] Compiled: NkPlatform.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKCore.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.30s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkFunction.cpp
✓   [2/14] Compiled: NkContainerAllocator.cpp
✓   [3/14] Compiled: NkGlobalOperators.cpp
✓   [4/14] Compiled: NkAllocator.cpp
✓   [5/14] Compiled: NkFunctionSIMD.cpp
✓   [6/14] Compiled: NkGc.cpp
✓   [7/14] Compiled: NkHash.cpp
✓   [8/14] Compiled: NkMemory.cpp
✓   [9/14] Compiled: NkMultiLevelAllocator.cpp
✓   [10/14] Compiled: NkProfiler.cpp
✓   [11/14] Compiled: NkPoolAllocator.cpp
✓   [12/14] Compiled: NkUtils.cpp
✓   [13/14] Compiled: NkTracker.cpp
✓   [14/14] Compiled: NkTag.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKMemory.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.67s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 42 source file(s)
✓   [1/42] Compiled: NkFunction.cpp
✓   [2/42] Compiled: NkBinaryTree.cpp
✓   [3/42] Compiled: NkPool.cpp
✓   [4/42] Compiled: NkEncoding.cpp
✓   [5/42] Compiled: NkASCII.cpp
✓   [6/42] Compiled: NkContainers.cpp
✓   [7/42] Compiled: NkRingBuffer.cpp
✓   [8/42] Compiled: NkTuple.cpp
✓   [9/42] Compiled: NkGraph.cpp
✓   [10/42] Compiled: NkDoubleList.cpp
✓   [11/42] Compiled: NkBTree.cpp
✓   [12/42] Compiled: NkMap.cpp
✓   [13/42] Compiled: NkPair.cpp
✓   [14/42] Compiled: NkUTF16.cpp
✓   [15/42] Compiled: NkPriorityQueue.cpp
✓   [16/42] Compiled: NkUnorderedMap.cpp
✓   [17/42] Compiled: NkSet.cpp
✓   [18/42] Compiled: NkVector.cpp
✓   [19/42] Compiled: NkList.cpp
✓   [20/42] Compiled: NkUTF32.cpp
✓   [21/42] Compiled: NkQuadTree.cpp
✓   [22/42] Compiled: NkDeque.cpp
✓   [23/42] Compiled: NkArray.cpp
✓   [24/42] Compiled: NkTrie.cpp
✓   [25/42] Compiled: NkUnorderedSet.cpp
✓   [26/42] Compiled: NkFunctional.cpp
✓   [27/42] Compiled: NkHashMap.cpp
✓   [28/42] Compiled: NkUTF8.cpp
✓   [29/42] Compiled: NkBasicString.cpp
✓   [30/42] Compiled: NkStringHash.cpp
✓   [31/42] Compiled: NkBind.cpp
✓   [32/42] Compiled: NkString.cpp
✓   [33/42] Compiled: NkStringBuilder.cpp
✓   [34/42] Compiled: NkInitializerList.cpp
✓   [35/42] Compiled: NkIterator.cpp
✓   [36/42] Compiled: NkSpan.cpp
✓   [37/42] Compiled: NkStringView.cpp
✓   [38/42] Compiled: NkStringUtils.cpp
✓   [39/42] Compiled: NkFormat.cpp
✓   [40/42] Compiled: NkOptional.cpp
✓   [41/42] Compiled: NkResult.cpp
✓   [42/42] Compiled: NkVariant.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKContainers.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.63s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkFunctions.cpp
✓   [2/12] Compiled: NkAngle.cpp
✓   [3/12] Compiled: NkSIMD.cpp
✓   [4/12] Compiled: NkEulerAngle.cpp
✓   [5/12] Compiled: NkMat.cpp
✓   [6/12] Compiled: NkQuat.cpp
✓   [7/12] Compiled: NkRange.cpp
✓   [8/12] Compiled: NkRandom.cpp
✓   [9/12] Compiled: NkRectangle.cpp
✓   [10/12] Compiled: NkColor.cpp
✓   [11/12] Compiled: NkSegment.cpp
✓   [12/12] Compiled: NkVec.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKMath.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.55s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKThreading                                                      Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkConditionVariable.cpp
✓   [2/12] Compiled: NkSpinLock.cpp
✓   [3/12] Compiled: NkMutex.cpp
✓   [4/12] Compiled: NkSemaphore.cpp
✓   [5/12] Compiled: NkRecursiveMutex.cpp
✓   [6/12] Compiled: NkSharedMutex.cpp
✓   [7/12] Compiled: NkBarrier.cpp
✓   [8/12] Compiled: NkEvent.cpp
✓   [9/12] Compiled: NkThread.cpp
✓   [10/12] Compiled: NkLatch.cpp
✓   [11/12] Compiled: NkReaderWriterLock.cpp
✓   [12/12] Compiled: NkThreadPool.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKThreading.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.62s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKLogger                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkLog.cpp
✓   [2/14] Compiled: NkLogLevel.cpp
✓   [3/14] Compiled: NkLogMessage.cpp
✓   [4/14] Compiled: NkLoggerFormatter.cpp
✓   [5/14] Compiled: NkSink.cpp
✓   [6/14] Compiled: NkLogger.cpp
✓   [7/14] Compiled: NkRegistry.cpp
✓   [8/14] Compiled: NkConsoleSink.cpp
✓   [9/14] Compiled: NkDailyFileSink.cpp
✓   [10/14] Compiled: NkAsyncSink.cpp
✓   [11/14] Compiled: NkDistributingSink.cpp
✓   [12/14] Compiled: NkFileSink.cpp
✓   [13/14] Compiled: NkNullSink.cpp
✓   [14/14] Compiled: NkRotatingFileSink.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKLogger.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.01s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFileSystem                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkDirectory.cpp
✓   [2/5] Compiled: NkFile.cpp
✓   [3/5] Compiled: NkFileSystem.cpp
✓   [4/5] Compiled: NkFileWatcher.cpp
✓   [5/5] Compiled: NkPath.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKFileSystem.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.44s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKFont                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 8 source file(s)
✓   [1/8] Compiled: NkFontDetect.cpp
✓   [2/8] Compiled: NkFontSizeCache.cpp
✓   [3/8] Compiled: NkFontRasterizer.cpp
✓   [4/8] Compiled: NkFontParser.cpp
✓   [5/8] Compiled: NkUtils.cpp
✓   [6/8] Compiled: NkFontMesh.cpp
✓   [7/8] Compiled: NkFontAtlas.cpp
✓   [8/8] Compiled: NkFontEmbedded.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKFont.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.92s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKTime                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkChrono.cpp
✓   [2/7] Compiled: NkClock.cpp
✓   [3/7] Compiled: NkDate.cpp
✓   [4/7] Compiled: NkDuration.cpp
✓   [5/7] Compiled: NkTimeSpan.cpp
✓   [6/7] Compiled: NkTimeZone.cpp
✓   [7/7] Compiled: NkTimes.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKTime.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.48s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKStream                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 4 source file(s)
✓   [1/4] Compiled: NkBinaryStream.cpp
✓   [2/4] Compiled: NkConsoleStream.cpp
✓   [3/4] Compiled: NkStream.cpp
✓   [4/4] Compiled: NkFileStream.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKStream.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.33s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKNetwork                                                        Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 9 source file(s)
✓   [1/9] Compiled: NkNetDefines.cpp
✓   [2/9] Compiled with warnings: NkReliableUDP.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                  Warning: NkReliableUDP.cpp                                  ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport\NkReliableUDP.cpp:483:6: warning: ignoring return value of function declared with      ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║ mSocket->SendTo(buffer, NkRUDPHeader::kSize + entry->size, mRemote);                         ║
║ ^~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                           ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport\NkReliableUDP.cpp:509:6: warning: ignoring return value of function declared with      ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║ mSocket->SendTo(buffer, NkRUDPHeader::kSize + entry->size, mRemote);                         ║
║ ^~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                           ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport\NkReliableUDP.cpp:520:5: warning: ignoring return value of function declared with      ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║                                 SendACK();                                                   ║
║                                 ^~~~~~~                                                      ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport\NkReliableUDP.cpp:543:5: warning: ignoring return value of function declared with      ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║                                 mSocket->SendTo(buffer, NkRUDPHeader::kSize, mRemote);       ║
║                                 ^~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         ║
║ 4 warnings generated.                                                                        ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✓   [3/9] Compiled with warnings: NkSocket.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                    Warning: NkSocket.cpp                                     ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport\NkSocket.cpp:571:4: warning: ignoring return value of function declared with           ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║                         SetSendBufferSize(kNkSendBufferSize);                                ║
║                         ^~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                                  ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Tran ║
║ sport\NkSocket.cpp:572:4: warning: ignoring return value of function declared with           ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║                         SetRecvBufferSize(kNkRecvBufferSize);                                ║
║                         ^~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                                  ║
║ 2 warnings generated.                                                                        ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✓   [4/9] Compiled: NkBitStream.cpp
✓   [5/9] Compiled: NkRPC.cpp
✓   [6/9] Compiled: NkNetWorld.cpp
✓   [7/9] Compiled with warnings: NkLobby.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                     Warning: NkLobby.cpp                                     ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Lobb ║
║ y\NkLobby.cpp:581:4: warning: ignoring return value of function declared with 'nodiscard'    ║
║ attribute [-Wunused-result]                                                                  ║
║ mConnMgr.Broadcast(buffer, totalSize, NkNetChannel::NK_NET_CHANNEL_RELIABLE_ORDERED);        ║
║                         ^~~~~~~~~~~~~~~~~~                                                   ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Lobb ║
║ y\NkLobby.cpp:699:4: warning: ignoring return value of function declared with 'nodiscard'    ║
║ attribute [-Wunused-result]                                                                  ║
║ mSession.GetConnMgr()->Broadcast(buffer, NkLobbyMessageHeader::kSize +                       ║
║ writer.BytesWritten(),                                                                       ║
║                         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Lobb ║
║ y\NkLobby.cpp:770:4: warning: ignoring return value of function declared with 'nodiscard'    ║
║ attribute [-Wunused-result]                                                                  ║
║ mSession.GetConnMgr()->Broadcast(buffer, NkLobbyMessageHeader::kSize +                       ║
║ writer.BytesWritten(),                                                                       ║
║                         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                     ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Lobb ║
║ y\NkLobby.cpp:927:4: warning: ignoring return value of function declared with 'nodiscard'    ║
║ attribute [-Wunused-result]                                                                  ║
║                         socket.SetBroadcast(true);                                           ║
║                         ^~~~~~~~~~~~~~~~~~~ ~~~~                                             ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Lobb ║
║ y\NkLobby.cpp:968:4: warning: ignoring return value of function declared with 'nodiscard'    ║
║ attribute [-Wunused-result]                                                                  ║
║                         socket.SetBroadcast(true);                                           ║
║                         ^~~~~~~~~~~~~~~~~~~ ~~~~                                             ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Lobb ║
║ y\NkLobby.cpp:969:4: warning: ignoring return value of function declared with 'nodiscard'    ║
║ attribute [-Wunused-result]                                                                  ║
║                         socket.SetNonBlocking(true);                                         ║
║                         ^~~~~~~~~~~~~~~~~~~~~ ~~~~                                           ║
║ 6 warnings generated.                                                                        ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✓   [8/9] Compiled with warnings: NkConnection.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                  Warning: NkConnection.cpp                                   ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Prot ║
║ ocol\NkConnection.cpp:820:4: warning: ignoring return value of function declared with        ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║ mRUDP.Send(buffer, NkSystemHeader::kSize, NkNetChannel::NK_NET_CHANNEL_UNRELIABLE);          ║
║ ^~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~            ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Prot ║
║ ocol\NkConnection.cpp:840:4: warning: ignoring return value of function declared with        ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║ mRUDP.Send(buffer, NkSystemHeader::kSize, NkNetChannel::NK_NET_CHANNEL_UNRELIABLE);          ║
║ ^~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~            ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Prot ║
║ ocol\NkConnection.cpp:916:4: warning: ignoring return value of function declared with        ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║                         mSocket.SetNonBlocking(true);                                        ║
║                         ^~~~~~~~~~~~~~~~~~~~~~ ~~~~                                          ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Prot ║
║ ocol\NkConnection.cpp:917:4: warning: ignoring return value of function declared with        ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║                         mSocket.SetRecvBufferSize(kNkRecvBufferSize);                        ║
║                         ^~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                          ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Prot ║
║ ocol\NkConnection.cpp:918:4: warning: ignoring return value of function declared with        ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║                         mSocket.SetSendBufferSize(kNkSendBufferSize);                        ║
║                         ^~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                          ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Prot ║
║ ocol\NkConnection.cpp:954:4: warning: ignoring return value of function declared with        ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║                         mSocket.SetNonBlocking(true);                                        ║
║                         ^~~~~~~~~~~~~~~~~~~~~~ ~~~~                                          ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Prot ║
║ ocol\NkConnection.cpp:955:4: warning: ignoring return value of function declared with        ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║                         mSocket.SetRecvBufferSize(kNkRecvBufferSize);                        ║
║                         ^~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                          ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Prot ║
║ ocol\NkConnection.cpp:956:4: warning: ignoring return value of function declared with        ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║                         mSocket.SetSendBufferSize(kNkSendBufferSize);                        ║
║                         ^~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~                          ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Prot ║
║ ocol\NkConnection.cpp:1133:5: warning: ignoring return value of function declared with       ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║                                 conn->Disconnect(reason);                                    ║
║                                 ^~~~~~~~~~~~~~~~ ~~~~~~                                      ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\Prot ║
║ ocol\NkConnection.cpp:1142:6: warning: ignoring return value of function declared with       ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║                                         mConnections[i]->Disconnect(reason);                 ║
║                                         ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~                   ║
║ 10 warnings generated.                                                                       ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✓   [9/9] Compiled with warnings: NkHTTPClient.cpp
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                  Warning: NkHTTPClient.cpp                                   ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\HTTP ║
║ \NkHTTPClient.cpp:891:4: warning: ignoring return value of function declared with            ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║                         ParseURL(req.url, scheme, host, port, path);                         ║
║                         ^~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                           ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\HTTP ║
║ \NkHTTPClient.cpp:1316:4: warning: ignoring return value of function declared with           ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║                         mHttp.SendAsync(req, [cb](const NkHTTPResponse &resp) {              ║
║                         ^~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\HTTP ║
║ \NkHTTPClient.cpp:1333:4: warning: ignoring return value of function declared with           ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║                         mHttp.SendAsync(req, [cb](const NkHTTPResponse &resp) {              ║
║                         ^~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              ║
║ C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\System\NKNetwork\src\NKNetwork\HTTP ║
║ \NkHTTPClient.cpp:1354:4: warning: ignoring return value of function declared with           ║
║ 'nodiscard' attribute [-Wunused-result]                                                      ║
║                         mHttp.SendAsync(req, [cb](const NkHTTPResponse &resp) {              ║
║                         ^~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              ║
║ 4 warnings generated.                                                                        ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKNetwork.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.75s  │
│ Warnings: 26                                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKEvent                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 10 source file(s)
✓   [1/10] Compiled: NkEvent.cpp
✓   [2/10] Compiled: NkDropSystem.cpp
✓   [3/10] Compiled: NkEventState.cpp
✓   [4/10] Compiled: NkKeyboardEvent.cpp
✓   [5/10] Compiled: NkGamepadMappingPersistence.cpp
✓   [6/10] Compiled: NkMouseEvent.cpp
✓   [7/10] Compiled: NkEventDispatcher.cpp
✓   [8/10] Compiled: NkWindowEvent.cpp
✓   [9/10] Compiled: NkEventSystem.cpp
✓   [10/10] Compiled: NkGamepadSystem.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKEvent.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.44s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKImage                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 13 source file(s)
✓   [1/13] Compiled: NkBMPCodec.cpp
✓   [2/13] Compiled: NkICOCodec.cpp
✓   [3/13] Compiled: NkHDRCodec.cpp
✓   [4/13] Compiled: NkGIFCodec.cpp
✓   [5/13] Compiled: NkPNGCodec.cpp
✓   [6/13] Compiled: NkPPMCodec.cpp
✓   [7/13] Compiled: NkEXRCodec.cpp
✓   [8/13] Compiled: NkQOICodec.cpp
✓   [9/13] Compiled: NkJPEGCodec.cpp
✓   [10/13] Compiled: NkTGACodec.cpp
✓   [11/13] Compiled: NkSVGCodec.cpp
✓   [12/13] Compiled: NkWebPCodec.cpp
✓   [13/13] Compiled: NkImage.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKImage.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.34s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKWindow                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 9 source file(s)
✓   [1/9] Compiled: NkLauncher.cpp
✓   [2/9] Compiled: NkHarmonyEventSystem.cpp
✓   [3/9] Compiled: NkContext.cpp
✓   [4/9] Compiled: NkDialogs.cpp
✓   [5/9] Compiled: NkWindowCursor.cpp
✓   [6/9] Compiled: NkWindowClipboard.cpp
✓   [7/9] Compiled: NkHarmonyGamepad.cpp
✓   [8/9] Compiled: NkWESystem.cpp
✓   [9/9] Compiled: NkHarmonyWindow.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKWindow.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.36s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKUI                                                             Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 17 source file(s)
✓   [1/17] Compiled: NkUIAnimation.cpp
✓   [2/17] Compiled: NkUIContext.cpp
✓   [3/17] Compiled: NkUIDrawList.cpp
✓   [4/17] Compiled: NkUIMath.cpp
✓   [5/17] Compiled: NkUIDock.cpp
✓   [6/17] Compiled: NkUILayout.cpp
✓   [7/17] Compiled: NkUIFontBridge.cpp
✓   [8/17] Compiled: NkUIFont.cpp
✓   [9/17] Compiled: NkUILayout2.cpp
✓   [10/17] Compiled: NkUIMenu.cpp
✓   [11/17] Compiled: NkUIRenderer.cpp
✓   [12/17] Compiled: NkUIWindow.cpp
✓   [13/17] Compiled: NkUIGizmo.cpp
✓   [14/17] Compiled: NkUIWidgets.cpp
✓   [15/17] Compiled: NkUITree.cpp
✓   [16/17] Compiled: NkUIViewport3D.cpp
✓   [17/17] Compiled: NkUIFileBrowser.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKUI.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.97s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMedia                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 71 source file(s)
✓   [1/71] Compiled: NkSilkGains.cpp
✓   [2/71] Compiled: NkH264Transform.cpp
✓   [3/71] Compiled: NkAacHuffman.cpp
✓   [4/71] Compiled: NkCeltLaplace.cpp
✓   [5/71] Compiled: NkSilkDecoder.cpp
✓   [6/71] Compiled: NkCeltMdct.cpp
✓   [7/71] Compiled: NkMpeg1Tables.cpp
✓   [8/71] Compiled: NkMpeg1Encoder.cpp
✓   [9/71] Compiled: NkMpeg2Decoder.cpp
✓   [10/71] Compiled: NkSilkNlsf.cpp
✓   [11/71] Compiled: NkHevcCabac.cpp
✓   [12/71] Compiled: NkCeltDeemphasis.cpp
✓   [13/71] Compiled: NkH264Decoder.cpp
✓   [14/71] Compiled: NkCeltQuantBands.cpp
✓   [15/71] Compiled: NkAacHuffmanTables.cpp
✓   [16/71] Compiled: NkCeltDenorm.cpp
✓   [17/71] Compiled: NkCeltVq.cpp
✓   [18/71] Compiled: NkCeltEnergy.cpp
✓   [19/71] Compiled: NkH264Encoder.cpp
✓   [20/71] Compiled: NkCeltAntiCollapse.cpp
✓   [21/71] Compiled: NkAacFilterbank.cpp
✓   [22/71] Compiled: NkSilkLtpTables.cpp
✓   [23/71] Compiled: NkSilkResampler.cpp
✓   [24/71] Compiled: NkAacIcs.cpp
✓   [25/71] Compiled: NkCeltPvq.cpp
✓   [26/71] Compiled: NkVp9Itxfm.cpp
✓   [27/71] Compiled: NkCeltBands.cpp
✓   [28/71] Compiled: NkCeltAlloc.cpp
✓   [29/71] Compiled: NkOpusDecoder.cpp
✓   [30/71] Compiled: NkH264Cavlc.cpp
✓   [31/71] Compiled: NkAacDequant.cpp
✓   [32/71] Compiled: NkAv1Decoder.cpp
✓   [33/71] Compiled: NkSilkExcitationTables.cpp
✓   [34/71] Compiled: NkSilkNlsfTables.cpp
✓   [35/71] Compiled: NkAacDecoder.cpp
✓   [36/71] Compiled: NkSilkLtp.cpp
✓   [37/71] Compiled: NkOpusPacket.cpp
✓   [38/71] Compiled: NkSilkFrameType.cpp
✓   [39/71] Compiled: NkAacTns.cpp
✓   [40/71] Compiled: NkOpusRange.cpp
✓   [41/71] Compiled: NkSilkLpc.cpp
✓   [42/71] Compiled: NkAacBitReader.cpp
✓   [43/71] Compiled: NkSilkExcitation.cpp
✓   [44/71] Compiled: NkWavWriter.cpp
✓   [45/71] Compiled: NkSilkIndices.cpp
✓   [46/71] Compiled: NkCeltDecoder.cpp
✓   [47/71] Compiled: NkCeltRate.cpp
✓   [48/71] Compiled: NkSilkSynthesis.cpp
✓   [49/71] Compiled: NkMediaDemux.cpp
✓   [50/71] Compiled: NkHevcDecoder.cpp
✓   [51/71] Compiled: NkOpusFile.cpp
✓   [52/71] Compiled: NkSilkMath.cpp
✓   [53/71] Compiled: NkCeltSplit.cpp
✓   [54/71] Compiled: NkSilkTop.cpp
✓   [55/71] Compiled: NkSilkIndicesTables.cpp
✓   [56/71] Compiled: NkAacTables.cpp
✓   [57/71] Compiled: NkTheoraDecoder.cpp
✓   [58/71] Compiled: NkHevcCtu.cpp
✓   [59/71] Compiled: NkAviWriter.cpp
✓   [60/71] Compiled: NkH264IntraDecoder.cpp
✓   [61/71] Compiled: NkVp8Decoder.cpp
✓   [62/71] Compiled: NkMediaProbe.cpp
✓   [63/71] Compiled: NkMovWriter.cpp
✓   [64/71] Compiled: NkWebmWriter.cpp
✓   [65/71] Compiled: NkMp4H264Writer.cpp
✓   [66/71] Compiled: NkVp9Decoder.cpp
✓   [67/71] Compiled: NkVideoRecorder.cpp
✓   [68/71] Compiled: NkImageSequenceWriter.cpp
✓   [69/71] Compiled: NkVideoConverter.cpp
✓   [70/71] Compiled: NkVideoWriter.cpp
✓   [71/71] Compiled: NkVideoReader.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKMedia.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 4.43s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCanvas                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 30 source file(s)
✓   [1/30] Compiled: NkDX11ComputeContext.cpp
✓   [2/30] Compiled: NkDX12ComputeContext.cpp
✓   [3/30] Compiled: NkDX11Renderer2D.cpp
✓   [4/30] Compiled: NkDX11Context.cpp
✓   [5/30] Compiled: NkDX12Renderer2D.cpp
✓   [6/30] Compiled: NkDX12Context.cpp
✓   [7/30] Compiled: NkOpenGLContext.cpp
✓   [8/30] Compiled: NkSoftwareComputeContext.cpp
✓   [9/30] Compiled: NkOpenGLComputeContext.cpp
✓   [10/30] Compiled: NkSoftwareContext.cpp
✓   [11/30] Compiled: NkOpenGLRenderer2D.cpp
✓   [12/30] Compiled: NkVulkanComputeContext.cpp
✓   [13/30] Compiled: NkSoftwareRenderer2D.cpp
✓   [14/30] Compiled: NkGpuPolicy.cpp
✓   [15/30] Compiled: NkContextFactory.cpp
✓   [16/30] Compiled: NkRenderer2DTypes.cpp
✓   [17/30] Compiled: NkVulkanContext.cpp
✓   [18/30] Compiled: NkVulkanRenderer2D.cpp
✓   [19/30] Compiled: NkBatchRenderer2D.cpp
✓   [20/30] Compiled: NkFont.cpp
✓   [21/30] Compiled: NkRenderer2DFactory.cpp
✓   [22/30] Compiled: NkShader.cpp
✓   [23/30] Compiled: NkSprite.cpp
✓   [24/30] Compiled: NkTexture.cpp
✓   [25/30] Compiled: NkShape.cpp
✓   [26/30] Compiled: NkRenderTarget.cpp
✓   [27/30] Compiled: NkRenderTexture.cpp
✓   [28/30] Compiled: NkRenderWindow.cpp
✓   [29/30] Compiled: NkRenderWindowCapture.cpp
✓   [30/30] Compiled: NkUICanvasBackend.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKCanvas.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 7.00s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKAudio                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 19 source file(s)
✓   [1/19] Compiled: NkAudioBackends.cpp
✓   [2/19] Compiled: NkOpusCodec.cpp
✓   [3/19] Compiled: NkAudioAnalyzer.cpp
✓   [4/19] Compiled: NkFLACCodec.cpp
✓   [5/19] Compiled: pch.cpp
✓   [6/19] Compiled: NkMP3Codec.cpp
✓   [7/19] Compiled: NkAudioBus.cpp
✓   [8/19] Compiled: NkAudioEffects.cpp
✓   [9/19] Compiled: NkAudioGenerator.cpp
✓   [10/19] Compiled: NkAudioLoader.cpp
✓   [11/19] Compiled: NkAudioCapture.cpp
✓   [12/19] Compiled: NkOGGVorbisCodec.cpp
✓   [13/19] Compiled: NkAudioMixer.cpp
✓   [14/19] Compiled: NkDenoiser.cpp
✓   [15/19] Compiled: NkAudioEngineCore.cpp
✓   [16/19] Compiled: NkHrtfDataset.cpp
✓   [17/19] Compiled: NkAudioStream.cpp
✓   [18/19] Compiled: NkContainerAudioStream.cpp
✓   [19/19] Compiled: NkAudioStreamPlayer.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-HarmonyOS\libNKAudio.a

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.26s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Pong                                                           Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 24 source file(s)
✓   [1/24] Compiled: AIController.cpp
✓   [2/24] Compiled: NetworkDiscovery.cpp
✓   [3/24] Compiled: AfricaPlaces.cpp
✓   [4/24] Compiled: ParticleSystem.cpp
✓   [5/24] Compiled: AudioManager.cpp
✓   [6/24] Compiled: PowerUpSystem.cpp
✓   [7/24] Compiled: ObstacleSystem.cpp
✓   [8/24] Compiled: FontAtlas.cpp
✓   [9/24] Compiled: NetworkSession.cpp
✓   [10/24] Compiled: SafeArea.cpp
✓   [11/24] Compiled: PongApp.cpp
✓   [12/24] Compiled: Apps.cpp
✓   [13/24] Compiled: SceneManager.cpp
✓   [14/24] Compiled: NogeIntroScene.cpp
✓   [15/24] Compiled: SplashScene.cpp
✓   [16/24] Compiled: MainMenuScene.cpp
✓   [17/24] Compiled: OptionsScene.cpp
✓   [18/24] Compiled: RihenIntroScene.cpp
✓   [19/24] Compiled: NetworkLobbyScene.cpp
✓   [20/24] Compiled: RulesScene.cpp
✓   [21/24] Compiled: GameplayScene.cpp
✓   [22/24] Compiled: SelectModeScene.cpp
✓   [23/24] Compiled: SelectMatchConfigScene.cpp
✓   [24/24] Compiled: SupporterScene.cpp
ℹ Linking...
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                Compilation Error: Link Failed                                ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ clang++: error: no such file or directory:                                                   ║
║ 'C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Lib\Debug-HarmonyOS\libNKGlad.a'    ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✗ Link failed: Build\Bin\Debug-HarmonyOS\Pong\libPong.so

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 5.65s  │
│ Errors: 1  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  20/21
Failed:         1
Errors:         1
Warnings:       26
Time:           45.51s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ Pong
```

Echec causé par l'abscence d'une bibliothèque. Tous les projets compilent sauf le dernier.

# PONG SUR ANDROID

Resultat:

```bash
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Pong                                                           Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 24 source file(s)
✓   [1/24] Compiled: AIController.cpp
✓   [2/24] Compiled: NetworkDiscovery.cpp
✓   [3/24] Compiled: AfricaPlaces.cpp
✓   [4/24] Compiled: ParticleSystem.cpp
✓   [5/24] Compiled: AudioManager.cpp
✓   [6/24] Compiled: PowerUpSystem.cpp
✓   [7/24] Compiled: ObstacleSystem.cpp
✓   [8/24] Compiled: FontAtlas.cpp
✓   [9/24] Compiled: NetworkSession.cpp
✓   [10/24] Compiled: SafeArea.cpp
✓   [11/24] Compiled: PongApp.cpp
✓   [12/24] Compiled: Apps.cpp
✓   [13/24] Compiled: SceneManager.cpp
✓   [14/24] Compiled: NogeIntroScene.cpp
✓   [15/24] Compiled: RihenIntroScene.cpp
✓   [16/24] Compiled: MainMenuScene.cpp
✓   [17/24] Compiled: SplashScene.cpp
✓   [18/24] Compiled: OptionsScene.cpp
✓   [19/24] Compiled: NetworkLobbyScene.cpp
✓   [20/24] Compiled: GameplayScene.cpp
✓   [21/24] Compiled: RulesScene.cpp
✓   [22/24] Compiled: SelectModeScene.cpp
✓   [23/24] Compiled: SelectMatchConfigScene.cpp
✓   [24/24] Compiled: SupporterScene.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Android-x86_64\Pong\libPong.so

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 6.29s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  21/21
Warnings:       30
Time:           50.43s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

✓   ✓ x86_64 compiled (2 libs)
ℹ Assembling universal APK with 4 ABIs
ℹ App icon Android genere : C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Bin\Debug-Android\Pong\android-build-universal\app-icon-res
ℹ   Adding 2 libs for armeabi-v7a
ℹ   Adding 2 libs for arm64-v8a
ℹ   Adding 2 libs for x86
ℹ   Adding 2 libs for x86_64
✓ Universal APK generated: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Bin\Debug-Android\Pong\android-build-universal\Pong-Debug.apk
```

succès de la compilation SDK Android présent

# PONG LINUX

```
 jenga build --platform Linux-x86_64 --target Pong 
```
```BASH
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
Target:        Linux x86_64
Toolchain:     clang-cross-linux

Build Order (21 projects):
  1. NKPlatform [STATIC_LIB] → 
  2. NKGlad [STATIC_LIB] → 
  3. NKCore [STATIC_LIB] (depends: NKPlatform) → 
  4. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) → 
  5. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) → 
  6. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  7. NKThreading [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform) → 
  8. NKLogger [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform, NKThreading) → 
  9. NKFileSystem [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  10. NKFont [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  11. NKTime [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  12. NKStream [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMemory, NKPlatform, NKThreading) → 
  13. NKNetwork [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  14. NKEvent [STATIC_LIB] (depends: NKContainers, NKCore, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  15. NKImage [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading) → 
  16. NKWindow [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading, NKTime) → 
  17. NKUI [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKThreading) → 
  18. NKMedia [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime) → 
  19. NKCanvas [STATIC_LIB] (depends: NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMemory, NKPlatform, NKStream, NKThreading, NKTime, NKUI, NKWindow) → 
  20. NKAudio [STATIC_LIB] (depends: NKContainers, NKCore, NKFileSystem, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKPlatform, NKStream, NKThreading) → 
  21. Pong [WINDOWED_APP] (depends: NKAudio, NKCanvas, NKContainers, NKCore, NKEvent, NKFileSystem, NKFont, NKGlad, NKImage, NKLogger, NKMath, NKMedia, NKMemory, NKNetwork, NKPlatform, NKStream, NKThreading, NKTime, NKUI, NKWindow)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝


════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  0/21
Failed:         1
Not reached:    20  (arret au premier echec — voir --keep-going)
Time:           0.07s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ NKPlatform
```

Echec direct. chqine de compilation abscente

# pong packaging windows

commande:

```
jenga build --target Pong --config Release   

jenga package --platform windows --type exe --project Pong -o ./dist
```

resultat:

```bash
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


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Pong                                                           Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 24 source file(s)
✓   [1/24] Compiled: AIController.cpp
✓   [2/24] Compiled: ParticleSystem.cpp
✓   [3/24] Compiled: AfricaPlaces.cpp
✓   [4/24] Compiled: AudioManager.cpp
✓   [5/24] Compiled: ObstacleSystem.cpp
✓   [6/24] Compiled: PowerUpSystem.cpp
✓   [7/24] Compiled: NetworkDiscovery.cpp
✓   [8/24] Compiled: FontAtlas.cpp
✓   [9/24] Compiled: Apps.cpp
✓   [10/24] Compiled: NetworkSession.cpp
✓   [11/24] Compiled: PongApp.cpp
✓   [12/24] Compiled: SafeArea.cpp
✓   [13/24] Compiled: SceneManager.cpp
✓   [14/24] Compiled: NogeIntroScene.cpp
✓   [15/24] Compiled: MainMenuScene.cpp
✓   [16/24] Compiled: OptionsScene.cpp
✓   [17/24] Compiled: RihenIntroScene.cpp
✓   [18/24] Compiled: NetworkLobbyScene.cpp
✓   [19/24] Compiled: GameplayScene.cpp
✓   [20/24] Compiled: SplashScene.cpp
✓   [21/24] Compiled: RulesScene.cpp
✓   [22/24] Compiled: SelectModeScene.cpp
✓   [23/24] Compiled: SelectMatchConfigScene.cpp
✓   [24/24] Compiled: SupporterScene.cpp
[Windows:icon] compilation du .rc echouee (windres). L'executable sera produit sans icone. Verifier rc.exe/llvm-rc dans le PATH.
ℹ Linking...
✓ Built: Build\Bin\Release-Windows\Pong\Pong.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 10.09s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘
Inno Setup 6 Command-Line Compiler
Copyright (C) 1997-2026 Jordan Russell. All rights reserved.
Portions Copyright (C) 2000-2026 Martijn Laan. All rights reserved.
Portions Copyright (C) 2001-2004 Alex Yackimoff. All rights reserved.
https://www.innosetup.com

Compiler engine version: Inno Setup 6.7.3
Non-commercial use only

Preprocessing
   Reading file: C:\Program Files (x86)\Inno Setup 6\ISPPBuiltins.iss
Parsing [Setup] section, line 3
Parsing [Setup] section, line 4
Parsing [Setup] section, line 5
Parsing [Setup] section, line 6
Parsing [Setup] section, line 7
Parsing [Setup] section, line 8
Parsing [Setup] section, line 9
Parsing [Setup] section, line 10
Parsing [Setup] section, line 11
Parsing [Setup] section, line 12
Parsing [Setup] section, line 13
Parsing [Setup] section, line 14
Parsing [Setup] section, line 15
Reading file (LicenseFile)
Reading file (WizardImageFile)
Reading file (WizardSmallImageFile)
Preparing Setup program executable
   Verification successful
   Updating icons (Setup.e32)
   Updating version info (Setup.e32)
Determining language code pages
   Reading file: C:\Program Files (x86)\Inno Setup 6\Default.isl
   Messages in script file
Reading default messages from Default.isl
Parsing [LangOptions], [Messages], and [CustomMessages] sections
   Reading file: C:\Program Files (x86)\Inno Setup 6\Default.isl
   Messages in script file
Reading [Code] section
Parsing [Tasks] section, line 18
Parsing [Icons] section, line 199
Parsing [Icons] section, line 200
Parsing [Run] section, line 204
Parsing [Files] section, line 21
   Reading version info: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Build\Bin\Release-Windows\Pong\Pong.exe
Parsing [Files] section, line 22
   Reading version info: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Resources\Pong\Audio\bleep.wav
Parsing [Files] section, line 23
   Reading version info: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Resources\Pong\Audio\powerup.wav
Parsing [Files] section, line 24
   Reading version info: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Resources\Pong\Audio\solid.wav
Parsing [Files] section, line 25
   Reading version info: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Resources\Pong\Gif\01.gif
Parsing [Files] section, line 26
   Reading version info: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Resources\Pong\Gif\02.gif
Parsing [Files] section, line 27
   Reading version info: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Resources\Pong\Gif\gifanime.gif
Parsing [Files] section, line 28
   Reading version info: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Resources\Pong\Gif\gif_01.gif
Parsing [Files] section, line 29
   Reading version info: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Resources\Pong\Textures\logo.png
Parsing [Files] section, line 30
   Reading version info: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Resources\Pong\Textures\logo.svg
Parsing [Files] section, line 31
   Reading version info: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Resources\Pong\Textures\animrihen\rihen_00000.png
Parsing [Files] section, line 32
   Reading version info: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Resources\Pong\Textures\animrihen\rihen_00001.png
Parsing [Files] section, line 33
   Reading version info: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Resources\Pong\Textures\animrihen\rihen_00002.png
Parsing [Files] section, line 34
   Reading version info: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Resources\Pong\Textures\animrihen\rihen_00003.png
Parsing [Files] section, line 35
   Reading version info: C:\Users\Administrator\Documents\Git_pro\Nkentseu\Resources\Pong\Textures\animrihen\rihen_00004.png

   Compressing Setup program executable
   Updating version info (Setup.exe)
   Updating manifest (Setup.exe)

Warning: Constant "pf" has been renamed. Use "commonpf" instead or consider using its "auto" form.
Warning: The [Setup] section directive "PrivilegesRequired" is set to "admin" but per-user areas (userdesktop) are used by the script. Regardless of the version of Windows, if the installation is running in administrative install mode then you should be careful about making any per-user area changes: such changes may not achieve what you are intending. See the "UsedUserAreasWarning" topic in help file for more information.

Successful compile (3.828 sec). Resulting Setup program filename is:
C:\Users\Administrator\Documents\Git_pro\Nkentseu\dist\Pong_setup.exe
EXE installer: C:\Users\Administrator\Documents\Git_pro\Nkentseu\dist\Pong_setup.exe
```

# OUTILS PRESENTS ET ABSENTS

- **outils presents** : SDK Android, clang++/g++, inno setup 6

- **outils absents** : SDK HarmoyOS, llvm-rc pour les icones 