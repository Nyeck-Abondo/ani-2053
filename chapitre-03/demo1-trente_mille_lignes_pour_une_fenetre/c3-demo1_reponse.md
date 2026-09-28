# REPONSE DE LA DEMO 1

> Cet execice a pour but de faire l'analyse du module NKWindow au travers de différentes observations qui seront parcourues ci dessous.

## Nombre de lignes du module

Le nombre de lignes du module a été compté à l'aide de l'outil Cloc-2.1.0 .
- La commande exécuté et sa sortie : 

```
PS C:\Users\Administrator\Documents\Git_pro\Nkentseu\Kernel\Runtime\NKWindow>  C:\Users\Administrator\Downloads\cloc\cloc-2.10.exe . --match-f="\.(cpp|h)$"                    
     111 text files.
     111 unique files.                                          
       0 files ignored.

github.com/AlDanial/cloc v 2.10  T=0.43 s (259.5 files/s, 76021.9 lines/s)
-------------------------------------------------------------------------------
Language                     files          blank        comment           code
-------------------------------------------------------------------------------
C++                             36           2635           3166          14277
C/C++ Header                    75           1697           3940           6809
-------------------------------------------------------------------------------
SUM:                           111           4332           7106          21086
-------------------------------------------------------------------------------
```
- Ce aui en ressort :
    - Le nombre de fichiers : **36** ficihers sources et **75** fichiers entêtes, pour un total de **111** fichiers au total.
    -Le nombre de lignes de code : 14277 dans les fichiers sources, et 6809 dans les fichiers entête. Le tout pour un total de **21086** lignes de code.

## Liste des backends de plateforme

| Backend| Matériel/plateforme cible 
|--|--
Android| mobiles avec système Android
Cocoa| cible le MAcOS
Emscripten| le Web
HarmonyOS| les appareils HWawei muni du système Harmony
Linux| Le Gamepad sous linux
Noop| N'effectue aucun traitement réel de l'information
UIkit| Cible les Iphones
Wayland| Linux
Win32| windows
Xbox| console Xbox
XCB| Linux
XLib| Linux

Le dossier `Common` ne se présentant que comme un helper, on peut donc conclure que le module présente en fait **13** backends différents.

## Choix et comparaison d'appel d'interface publique

L'interface choisie ici est **NKWindow** avec l'appel de la méthode de passage de la fenêtre en plein écran `SetFullscreen()`. Les backends choisi ici seront donc Win23 et XCB.

- Dans win32:

```cpp
void NkWindow::SetFullscreen(bool fs) {
		mConfig.fullscreen = fs;

		if (fs) {
			SetWindowLongW(mData.mHwnd, GWL_STYLE, WS_POPUP | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);
			SetWindowPos(mData.mHwnd, HWND_TOP, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN),
						 SWP_FRAMECHANGED);

			// Mettre à jour la taille
			mConfig.width = GetSystemMetrics(SM_CXSCREEN);
			mConfig.height = GetSystemMetrics(SM_CYSCREEN);
		} else {
			SetWindowLongW(mData.mHwnd, GWL_STYLE, (LONG)mData.mDwStyle);
			SetWindowPos(mData.mHwnd, nullptr, mConfig.x, mConfig.y, (int)mConfig.width, (int)mConfig.height,
						 SWP_FRAMECHANGED | SWP_NOZORDER);
		}
	}
```

- Dans XCB :

```cpp
void NkWindow::SetFullscreen(bool fullscreen) {
		if (!mData.mConnection || !mData.mWindow || !sDefaultScreen)
			return;

		mConfig.fullscreen = fullscreen;

		xcb_atom_t wmState = NkXCBInternAtom(mData.mConnection, "_NET_WM_STATE");
		xcb_atom_t wmFs = NkXCBInternAtom(mData.mConnection, "_NET_WM_STATE_FULLSCREEN");

		xcb_client_message_event_t ev{};
		ev.response_type = XCB_CLIENT_MESSAGE;
		ev.format = 32;
		ev.window = mData.mWindow;
		ev.type = wmState;
		ev.data.data32[0] = fullscreen ? 1 : 0;
		ev.data.data32[1] = wmFs;

		xcb_send_event(mData.mConnection, 0, sDefaultScreen->root,
					   XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT | XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY, (const char *)&ev);
		xcb_flush(mData.mConnection);

		// Mettre à jour la taille
		if (fullscreen) {
			mConfig.width = sDefaultScreen->width_in_pixels;
			mConfig.height = sDefaultScreen->height_in_pixels;
		} else {
			xcb_get_geometry_cookie_t c = xcb_get_geometry(mData.mConnection, mData.mWindow);
			xcb_get_geometry_reply_t *r = xcb_get_geometry_reply(mData.mConnection, c, nullptr);
			if (r) {
				mConfig.width = r->width;
				mConfig.height = r->height;
				platform::NkXcbFree(r);
			}
		}
	}
```

- Ce qui est identique : le seul point commun que l'on retrouve aux deux backends est l'entête de la fonction `void NkWindow::SetFullscreen(bool fullscreen)`.

- Ce qui change : Ce qui change par contre et qui se présente comme étant flagrand est l'inplémentation de la méthode dans les deux baxkends. Celle de Win32 utilise des fonctions différentes de celles de XCB. Ce qui fait en sorte que le code du deuxième backends soit prêt de deux fois plus long que celui de Win32 pour la même opération sur la fenêtre.

On remarque donc que le module masque la complexité et les différences d'implémentations d'une fonctionnalité d'une plateforme à l'autre. Il fourni une abstration de chaque backend au travers d'appel de méthodes simplifiés.