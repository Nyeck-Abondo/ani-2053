#include "NKWindow/NKWindow.h"
#include "NKMath/NkMat.h"
#include "Button/button.h"

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

        bool followMouse = false;

        NkWindow& window;
        NkVec2f mouseOldPos {};

        TitleBar(TitleBarTheme& Bartheme, NkWindow& win);
        ~TitleBar();

        bool IsInside(NkVec2 mouse, NkWindow& window);
        
        void SetTheme(TitleBarTheme& Bartheme) { theme = Bartheme; }
        void RenderBar(NkWindow& window, NkEvent* event);
        void Update(NkEvent* event, float dt);
    };
        
} // namespace nkentseu

