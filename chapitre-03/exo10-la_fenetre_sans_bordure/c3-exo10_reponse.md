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
        bool firstClick = false;
        bool doubleClicked = false;
        float clickTimeEllapsed =0.0f;

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

```
> Les preuves se trouvent dqns le dossier Preuves joint avec l'exercice. Il comprend une vidéo de démonstration de quelques secondes et des images de test.