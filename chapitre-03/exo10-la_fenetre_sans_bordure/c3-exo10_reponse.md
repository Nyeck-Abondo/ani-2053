# REPONSE DE L'EXERCICE 10

> Cet exercice est divisé en trois principaux projets. Le chronométrage de valeurs temps mis est pris depuis l'engagement sur l'exercice en excluant les périodes de repos. L'outil utilisé ici pour le dessin personnalisé est l'API win32 et le hdc.

## Etat du dossier de l'exercice

Le dossier de l'exercie se présente sous l'arbre suivant, obtenu grâce à la commande `tree /f`.

```
Folder PATH listing for volume Windows
Volume serial number is 8889-2147
C:.
│   .gitignore
│   c3-exo10_main.cpp
│   c3-exo10_reponse.md
│   exo10-la_fenetre_sans_bordure.jenga
│   pyrightconfig.json
│   
├───.jenga
├───.jenga-typings
│       jengaconfig.py
│       jengaconfig.pyi
│       
├───Button
│       button.cpp
│       button.h
│       
├───logs
│       app.log
│       app_2026-09-27_153340_21812.log
│       
└───TitleBar
        TitleBar.cpp
        TitleBar.h
```

L'exercice présente deux modules suplémentaires que sont `Button` et `TitleBar` qui sont chargés du dessin des différentes composantes de la barre de titre. Ce choix de conception entraine que le fichier `c3-exo10_main.cpp` ne représente que le fichier d'assemblages des modules de l'exercice. l'essentiel de la logique de la barre de titre état implémentée dans ceux ci.

## Dessin des boutons

Avant de commencer l'affichage de la barre de titre, li est important de d'abord définir les boutons qui la composeront. Ici, on a décidé de partir sur une interface en mode retenu avec définition d'une classe abstraite donnant le comportement général des différents types de boutons. Le module de bouton se présente donc comme suit.

- **Présentation du module** :

    - **Les enumérations d'états et de composants** : LE module subdivise les boutons en types et pour la gestion aisée des évènements définit des états de ceux ci.

    ```cpp
    #include "NKWindow/NKWindow.h"
    #include "NKEvent/NkEventSystem.h"
    #include "NKEvent/NkMouseEvent.h"
    #include "NKMath/NKMath.h"

    namespace nkentseu {
        using namespace math;

        enum ComponentType {
            CROSS,
            MAXIMIZE,
            MINIMIZE,
            LOGO,
        };

        enum ComponentState {
            NONE,
            HOVER,
            CLICKED,
        };
    ```

    - **Les différents types de bouton:** LEs différents tupes de boutons héritent tous d'un type générique venant d'une classe abstraite nommée `Button`. Celle ci défini le comportement de base des bouton. Leurs façon de se mettre à jour, de se contruire.
        ```cpp
        class Button {
            protected :
            RECT buttonSize;
            NkRect2i size;
            ComponentState state;

            public :

            Button(NkRect2i s) {
                size = s;
                buttonSize = {s.x, s.y, s.x + s.w, s.y + s.h};
                logger.Info("[button] size : {0}", size);
                state = ComponentState::NONE;
            }

            RECT GetButtonsize() { return buttonSize; }
            NkRect2i GetSize() { return size; }

            void SetState(ComponentState st) { state = st;}

            bool IsInside(NkVec2 mousePos);
            bool IsClicked(NkEvent& e);
            void Update(NkEvent* event);

            ComponentState GetState() { return state; }

            virtual void DrawButton(HDC& hdc ,HBRUSH& brush, HPEN& pen) = 0;
            virtual ComponentType GetType() = 0;
        };
        ```

        - `CrossBtn` : C'est la classe en charge non suelement du dessin, mais du mécanisme derrière le bouton de fermeture. Elle comme toutes les autres classe boutton, héritent de la classe `Button` et ne redéfinit que la méthode `DrawButton`. CEtte fonction utilise le HDC de l'API Win32 pour dessiner deux segmensts de droites obliques au dessus d'un rectangle aux couleurs de la barre de titre. La mise à jour de celle ci étant faite de façon globale dans la classe `Button`.
            ```cpp
            class CrossBtn : public Button {
                    private:
                    ComponentType type;

                    public:
                    CrossBtn(NkRect2i s) : Button(s), type(ComponentType::CROSS) { }
                    ~CrossBtn() = default;

                    void DrawButton(HDC& hdc ,HBRUSH& brush, HPEN& pen) override;

                    ComponentType GetType() override { return type; }
            };
            ```
            - **Sa méthode de dessin** : La méthode de dessin de cette classe repose sur le dessin de trois éléments. Le premier est un rectangle qui sert de conteneur au motif u bouton de fermeture. Ce dessin est assuré par la méthode `FillRect`m aui dessine un rectqngle plein. Et enfin le dessin de deux segments perpendiculaires et obliques. les valuers constantes placée dans `MoveToEx` et `LineTo` représentant les points de départ et d'arrivé des lignes:
            ```cpp
                void CrossBtn::DrawButton(HDC& hdc ,HBRUSH& brush, HPEN& pen) {
                    FillRect(hdc, &buttonSize, brush);
                    HPEN holdPen = (HPEN)SelectObject(hdc, pen);
                    MoveToEx(hdc, size.x + 7, size.y + 3, nullptr);
                    LineTo(hdc, size.x + size.width - 7, size.y + size.height - 3);
                    MoveToEx(hdc, size.x + size.width - 7, size.y + 3, nullptr);
                    LineTo(hdc, size.x + 7, size.y + size.height - 3);

                    SelectObject(hdc, holdPen);
                }
            ``

        - `MaxBtn` : La classe MaxBtn elle définit le dessin et la mise à jour de l'état du bouton de maximisation. Il hérite aussi de la classe **Button** et redéfinit la méthode `DrawButton`. Sa fonction à lui se présente comme suit.
            ```cpp
            /**
            * @brief
            */
            class MaxBtn : public Button {
                private:
                ComponentType type;

                public:
                MaxBtn(NkRect2i s) : Button(s), type(ComponentType::MAXIMIZE) { }
                ~MaxBtn() = default;

                void DrawButton(HDC& hdc ,HBRUSH& brush, HPEN& pen) override;

                ComponentType GetType() override { return type; }
            };
            ```
            - **Sa méthode de dessin** : Elle prend en paramètre la brush qui convient à l'état dans lequel se trouve le bouton de maximisation ainsi qu'un stylo pour les contours et son hdc. LA méthode est simple. Elle utilise le hdc pour dessiner un rectangle à l'endroit indiqué par le thème de la barre de titre.
                ```cpp
                //===========================
                //BOUTON MAXIMISER
                //===========================
                void MaxBtn::DrawButton(HDC& hdc ,HBRUSH& brush, HPEN& pen) {
                    FillRect(hdc, &buttonSize, brush);
                    HPEN holdPen = (HPEN)SelectObject(hdc, pen);
                    Rectangle(hdc, size.x + 7, size.y + 7, size.x + size.width - 7, size.y + size.height - 7);

                    SelectObject(hdc, holdPen);
                }
                ```

        - `MinBtn` : CEtte clase ne gère que le bouton de minimisation. Sa fonction de desssin se comporte littéralement de la même manière que celle de la classe du bouton de fermeture, ç la seule différence qu'elle ne dessine qu'une seule ligne horizontale.

            ```cpp
            class MinBtn : public Button {
            private:
                ComponentType type;

                public:
                MinBtn(NkRect2i s) : Button(s), type(ComponentType::MINIMIZE) { }
                ~MinBtn() = default;

                void DrawButton(HDC& hdc ,HBRUSH& brush, HPEN& pen) override;

                ComponentType GetType() override { return type; }
            };
            ```

## Dessin de la barre de titre

Le dessin de la barre de titre est assurée par le module `TitleBar` Ce module regroupe une structure de thème pour la personnalisation ultérieure de la barre de titre, et la configuration de certaines dimensions des composants. Les strutures employées pour cette tâche sont présentées comme suit:

```cpp
#include "NKWindow/NKWindow.h"
#include "NKMath/NkMat.h"
#include "button.h"

namespace nkentseu {
    using namespace math;

    struct TitleBarTheme {
        RECT barreSize;
        NkRect2i buttonSize;

        NkColor TitleBarcolor {39, 44, 48};

        NkColor CloseColorhover = {196, 4, 70};
        NkColor closeColorClicked = {227, 4, 81};
        NkColor maximizeColorHover = {21, 23, 26};
        NkColor maximizeColorClicked = {31, 35, 38};
        NkColor mimizeColorHover = {21, 23, 26};
        NkColor mimizeColorClicked = {31, 35, 38};

        NkColor componentColor = {252, 252, 251};
        NkColor componentColorHovered = {255, 255, 255};

        int32 btnOffset = 70;
    };

    struct TitleBar {
        TitleBarTheme theme;

        CrossBtn cross;
        MaxBtn maximize;
        MinBtn minimize;

        HBRUSH brush, hoverBrush, clickedBrush;
        HBRUSH hoverMaxBrush, clickedMaxBrush;
        HBRUSH hoverMinBrush, clickedMinBrush;
        HPEN pen, penHover;
        HFONT font;

        bool followMouse;

        NkWindow& window;

        TitleBar(TitleBarTheme& Bartheme, NkWindow& win);
        ~TitleBar();

        bool IsInside(NkVec2 mouse, NkWindow& window);
        
        void SetTheme(TitleBarTheme& Bartheme) { theme = Bartheme; }
        void RenderBar(NkWindow& window, NkEvent* event);
        void Update(NkEvent* event, float dt);
    };
        
} // namespace nkentseu

```

- **`TitleBarTheme`** :
```cpp
struct TitleBarTheme {
        RECT barreSize;
        NkRect2i buttonSize;

        NkColor TitleBarcolor {39, 44, 48};

        NkColor CloseColorhover = {196, 4, 70};
        NkColor closeColorClicked = {227, 4, 81};
        NkColor maximizeColorHover = {21, 23, 26};
        NkColor maximizeColorClicked = {31, 35, 38};
        NkColor mimizeColorHover = {21, 23, 26};
        NkColor mimizeColorClicked = {31, 35, 38};

        NkColor componentColor = {252, 252, 251};
        NkColor componentColorHovered = {255, 255, 255};

        int32 btnOffset = 70;
    };
```
Cette structure présente les caractéristiques esthétiques des composants de la barre de titre : coouleur du bouton de fermeture, de minimisation et d'agrandissement dans les différents états qu'il sont capables d'avoir: survolé, cliqué et rien. Elle définit aussi les dimesions de la majorité des composants: **Espacement**, **dimension de bouton**, **Taille de la barre** .

- **`TitleBar`** : 

```cpp
struct TitleBar {
        TitleBarTheme theme;

        CrossBtn cross;
        MaxBtn maximize;
        MinBtn minimize;

        HBRUSH brush, hoverBrush, clickedBrush;
        HBRUSH hoverMaxBrush, clickedMaxBrush;
        HBRUSH hoverMinBrush, clickedMinBrush;
        HPEN pen, penHover;
        HFONT font;

        bool followMouse;

        NkWindow& window;

        TitleBar(TitleBarTheme& Bartheme, NkWindow& win);
        ~TitleBar();

        bool IsInside(NkVec2 mouse, NkWindow& window);
        
        void SetTheme(TitleBarTheme& Bartheme) { theme = Bartheme; }
        void RenderBar(NkWindow& window, NkEvent* event);
        void Update(NkEvent* event, float dt);
    };
```

C'est la structure même qui dessine la barre de titre. Par souci de rapidité, elle a été crée en mode retenu pour éviter la mise en place de calculs complexes. Son constructeur prend en paramètre le thème de la barre, par analogie à `NkWindow` et sa structurre de configuration.

Elle prends par ailleurs dans la liste de ses champs, une référence à la fenêtre à laquelle elle est acrochée. L'accès par référence de la fenêtre est utile pour ce qui est de l'application des transformations de la fenêtre.

## Gestion des évènements associers à la barre de titre

- La classe Button abstraite: Dans la gèstion des évènements la calsse abstraite des boutons joue un grad rôle. Elle fourni la méthode commune utilisée par les bouton pour mettre à jour en direct leur état courant. Il s'agit ici de :

    ```cpp
    bool IsInside(NkVec2 mousePos);
    bool IsClicked(NkEvent& e);
    void Update(NkEvent* event);
    ```
    - `IsInside`: Elle permet vérifier que le curseur de la souris se trouve effectivement dans la boundingbox du bouton. Elle renvoie true si oui et fase si non. Elle est utilisée principalement par `Update` pour changer en temps réel l'état du bouton.

    - `IsClicked` : CEtte fonction permet de vérifier si le clic de la souris s'effectivement produit à la surface du bouton. C'est une fonction booléenne qui définit aussi un état dans la méthode `Update`.

    - `Update` : Cette méthode ne fait que ce que son nom indique: Mettre à jour. Elle met à jours l'état du bouton à l'aide des méthodes facilitatrices indiquée plus haut. Le bouton passe ainsi d'un état `NONE` à un état `HOVER` ou `CLICKED`. Les états sont les mêmes pour tous les boutons.

- **Le bouton de fermeture** : Le bouton de fermeture permet la femeture propre de la fenêtre.  Dqns `TitleBar.cpp`, la méthode `RenderBar` en fonction de l'état du bouton de fermeture le dessine, puis exécute la méthode qui y est associé s'il y en a une. Dans le cas échéant, la métho de fermeture `Close` de la fenêtre est appelée lorsque l'état passe à **clicked**.

    ```cpp
    // - croix
        switch (cross.GetState()) {
            case ComponentState::HOVER:
                cross.DrawButton(hdc, hoverBrush, penHover);
                logger.Warn("[cross] : state : Hover");
                break;
            case ComponentState::CLICKED:
            logger.Warn("[cross] : state : clicked");
                cross.DrawButton(hdc, clickedBrush, penHover);
                window.Close();
                break;
            case ComponentState::NONE :
            logger.Warn("[cross] : state : none");
                cross.DrawButton(hdc, brush, penHover);
                break;
        }
    ```


- le bouton de maximisation : Le comporement ici est analogue. un état, une mise en forme du bouton et une action qui est exécuté à l'état **clicked**. L'action exécutée ici est la maximisation de la fenêtre au moyen de la méthode `Maximize()`  l'objet de type NkWindow passé en référence au constructeur de la barre de titre.

    ```cpp
    // - maximize
        switch (maximize.GetState()) {
            case ComponentState::HOVER:
                maximize.DrawButton(hdc, hoverMaxBrush, penHover);
                logger.Warn("[maximize] : state : Hover");
                break;
            case ComponentState::CLICKED:
            logger.Warn("[maximize] : state : clicked");
                maximize.DrawButton(hdc, clickedMaxBrush, penHover);
                window.Maximize();
                maximize.SetState(ComponentState::NONE);
                break;
            case ComponentState::NONE :
            logger.Warn("[maximize] : state : none");
                maximize.DrawButton(hdc, brush, penHover);
                break;
        }
    ```

- Le bouton de minimisation : Le bouton de minimisation est ici le dernier présenté. Il a la même mise en forme générale que le bouton de maximisatoin dans les états, **clicked** et **hover**. SA différence est que son été **clicked** appelle la méthode de minimisation de la fenêtre.

    ```cpp
        // - minimize
        switch (minimize.GetState()) {
            case ComponentState::HOVER:
                minimize.DrawButton(hdc, hoverMinBrush, penHover);
                logger.Warn("[minimize] : state : Hover");
                minimize.SetState(ComponentState::NONE);
                break;
            case ComponentState::CLICKED:
            logger.Warn("[minimize] : state : clicked");
                minimize.DrawButton(hdc, clickedMinBrush, penHover);
                window.Minimize();
                minimize.SetState(ComponentState::NONE);
                break;
            case ComponentState::NONE :
            logger.Warn("[minimize] : state : none");
                minimize.DrawButton(hdc, brush, penHover);
                break;
        }
    ```

## LE Déplacement de la fenêtre grâce à la barre de titre

Le déplacement de la fenêtre grâce à un double clic sur la barre de titre se fait grâce à des tests sur la position du curseur de la souri. Cette action obéi à des règles strictes:

- La fenêtre n'est déplaceable que lorsque le curseur se trouve sur la barre de titre. Null par ailleurs

- Seul un double clic déclenche ce déplacement de la souris

- lors du déplacement le curseur se positonne au milieu de la fenêtre (ce n'est pas obligatoire en réalité. Mais c'est le meilleur resultat obtenu durant les tests, et c'est celui qui a été conservé).

Toute cette logique est implémentée dans un seul bolc du module de barre de titre:

```cpp
if (auto* mouse = e->As<NkMouseButtonPressEvent>()) {
                if (mouse->IsLeft() && IsInside({static_cast<float>(mouse->GetX()),static_cast<float>(mouse->GetY())}, window)) {
                    if (cross.IsInside({static_cast<float>(mouse->GetX()),static_cast<float>(mouse->GetY())})) {
                        followMouse = false;
                    } if (maximize.IsInside({static_cast<float>(mouse->GetX()),static_cast<float>(mouse->GetY())})) {
                        followMouse = false;
                    } if (minimize.IsInside({static_cast<float>(mouse->GetX()),static_cast<float>(mouse->GetY())})) {
                        followMouse = false;
                    } else {
                        if (mouse->GetClickCount() == 2) {
                            if (window.IsMaximized())
                            window.Minimize();
                            else window.Maximize();
                        } else
                            followMouse = true;
                    }
                }
            }
            if (auto* mouse = e->As<NkMouseMoveEvent>()) {
                if (followMouse) {
                    NkVec2 mousePos {};
                    int32 x = mouse->GetScreenX() - window.GetSize().width / 2;
                    int32 y = mouse->GetScreenY() - 20; 
                    mousePos = {static_cast<float>(x), static_cast<float>(y)};
                    window.SetPosition(mousePos);
                }
            }
            if (auto* mouse = e->As<NkMouseButtonReleaseEvent>()) {
                if (mouse->IsLeft()) followMouse = false;
            }
```
- **Le principe** : On commence tout d'abord par identifier l'apparition d'un évènement de pression de la souris, puis on identifie le bouton source de celui ci. 
    - si c'est le clic du bouton gauche, alors on isole trois positions sur la barre de titre qui ne permettrons pas son déplacement : Les trois boutons de **maximisation**, **réduction**, et de **fermeture**. 
    - On vérifie ensuite s'il s'agit d'un double clic. Si oui, selon l'état de la fefnêtre (maximisé ou minimisé), le double clic appliquera la méthode `Minimize` ou `Maximize` de l'objet window. Dans le cas contraire, s'il ne s'agis que d'un seul cloc maintenu, alors il s'agit d'un déplacement de la fenêtre et le booléen qui en avise (`followMouse`) prends immédiatement la valeur `true`.

## Construction et exécution du programme

- **construction du programme** : Comme énoncé plus haut, l'exercice repose sur la construction de trois projets: celui de l'exercice, qui est le projet principal, celui de la barre de titre qui a un rdre d'importance intermédiaire, et enfin celui des boutons.

```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo10-la_fenetre_sans_bordure> jenga build

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
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (3 projects):
  1. Button [STATIC_LIB] → 
  2. TitleBar [STATIC_LIB] (depends: Button) → 
  3. exercice-10 [WINDOWED_APP] (depends: Button, TitleBar)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: Button                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.06s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: TitleBar                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: TitleBar.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\TitleBar\TitleBar.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.25s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exercice-10                                                    Kind: WINDOWED_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: c3-exo10_main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exercice-10\exercice-10.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 3.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  3/3
Time:           5.35s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```
Trois projets construism le resultat de succes est là.

- **Lancement du programme** :
```
PS C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo10-la_fenetre_sans_bordure> jenga run

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


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  exercice-10.exe
     C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo10-la_fenetre_sans_bordure\Build\Bin\Debug-Windows\exercice-10\exercice-10.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[NKLogger] niveau=info | console=debug | journal=C:\Users\Administrator\Documents\Github\Sprints\ani-2053\chapitre-03\exo10-la_fenetre_sans_bordure\logs\app.log
[NKLogger] trace/debug sont SOUS le niveau : NK_LOG_LEVEL=debug pour les voir ; NK_LOG_CONSOLE=1 pour tout mettre a l'ecran ; NK_LOG_QUIET=1 pour taire ces deux lignes.
[2026-09-27 19:09:02.584] [INF] [default] [c3-exo10_main.cpp:40 in nkmain] -> [window] : (312, 160)
[2026-09-27 19:09:02.585] [INF] [default] [button.h:33 in Button] -> [button] size : NkRectT[pos(1130, 10); size(40, 30)]
[2026-09-27 19:09:02.585] [INF] [default] [button.h:33 in Button] -> [button] size : NkRectT[pos(1060, 10); size(40, 30)]
[2026-09-27 19:09:02.585] [INF] [default] [button.h:33 in Button] -> [button] size : NkRectT[pos(1020, 10); size(40, 30)]
[2026-09-27 19:09:02.585] [INF] [default] [c3-exo10_main.cpp:43 in nkmain] -> [button] : RECT : (1130, 10) (1170, 40)
[2026-09-27 19:09:02.587] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:02.587] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:02.587] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:02.587] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:02.588] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:02.588] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
.
...
...
...
...
...
[2026-09-27 19:09:05.768] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:05.768] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.769] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.774] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:05.774] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.775] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.775] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:05.776] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.776] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.781] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:05.782] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.782] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.783] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:05.783] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.784] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.788] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:05.788] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.789] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.789] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:05.789] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.789] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.795] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:05.795] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.796] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.796] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:05.796] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.797] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.802] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:05.802] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.802] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.803] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:05.803] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.803] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.809] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:05.809] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.810] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.810] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:05.810] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.811] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.816] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:05.816] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.816] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.817] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:05.817] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.818] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.823] [WRN] [default] [TitleBar.cpp:81 in RenderBar] -> [cross] : state : none
[2026-09-27 19:09:05.823] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.823] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.824] [WRN] [default] [TitleBar.cpp:73 in RenderBar] -> [cross] : state : Hover
[2026-09-27 19:09:05.824] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.825] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.830] [WRN] [default] [TitleBar.cpp:73 in RenderBar] -> [cross] : state : Hover
[2026-09-27 19:09:05.830] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.830] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.831] [WRN] [default] [TitleBar.cpp:73 in RenderBar] -> [cross] : state : Hover
[2026-09-27 19:09:05.831] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:05.831] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:05.837] [WRN] [default] [TitleBar.cpp:73 in RenderBar] -> [cross] : state : Hover
[2026-09-27 19:09:06.930] [WRN] [default] [TitleBar.cpp:76 in RenderBar] -> [cross] : state : clicked
[2026-09-27 19:09:07.030] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:07.097] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none
[2026-09-27 19:09:07.197] [WRN] [default] [TitleBar.cpp:76 in RenderBar] -> [cross] : state : clicked
[2026-09-27 19:09:07.298] [WRN] [default] [TitleBar.cpp:99 in RenderBar] -> [maximize] : state : none
[2026-09-27 19:09:07.364] [WRN] [default] [TitleBar.cpp:118 in RenderBar] -> [minimize] : state : none

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (4.93s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

LEs messages de log de l'état des boutons étant êtremement longs l'exécution se devait d'être brève pour permettre la capture de la baniètre et du début de l'horodatage. Mais on peut remarquer parmis les messages de log le passage d'état des boutons survolés.

## Le temps mis pour la réalisation de ce travail

Le temps mis en seconde n'a pas été exactement chronométré, mais peut être exactement calculé en se basantsur la routine quotidienne adoptée depuis chaque exercices.

- date d'engagement de l'exercice: l'exercice a été engagé il y a exactement deux jours, soit vendredi 25 septembre 2026 dans les alentours de 22h. Ce premier jour a été marqué par un ensemble des recherches quant à la compréhension de l'exercice. cette phase s'est poursuivie jusqu'à Samedi 26 septembre à 3h du matin. temps estimé ici à **3h**. Du temps perdu à cause d'assistance porté à divers camarades. 

- plage de travail intermédiaire : le travail s'est ainsi poursuivi Samedi avec la conception de la barre de titre, puis l'implémentation. Les sites consultés étant ceux de Microsoft learn présents aux adresses suivantes : [https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-rectangle] , [https://learn.microsoft.com/fr-fr/windows/win32/api/windef/ns-windef-rect] , [https://learn.microsoft.com/fr-fr/windows/win32/gdi/drawing-a-custom-window-background] . Pour ne citer que ceux là. la période de travaille s'est étendue ainsi de 10h à 4h en comptant les pauses et les indisponibilitées momentanées. le temps de travail estimé redescend à environ **10h**. De nombreux bugs ont été résolus durant cette période, avec des hésitations notemment sur le choix d'utiliser les méthodes de l'API ou écrire directement les mienne en redu software. Les deux approches ont été explorées. Et l'utilisation de l'API a finalement été retenue.

- Date d'achèvement : Dimanche 27/09/2026 à 19:09, comme indiqué sur les messages de Log. C'était la phase des derniers tests. et de rédaction de la réponse. Ici, le travail a commencé à 12h pour se terminer contraitement à 19h avec les périodes de repos incluse. Le tout, pour un temps de travail estimé à **5h**.

Le temps total de travail estimé est donc de : **18h** . Et il est assumé pour une période de deux jours.

> Les preuves se trouvent dqns le dossier Preuves joint avec l'exercice. Il comprend une vidéo de démonstration de quelques secondes et des images de test.