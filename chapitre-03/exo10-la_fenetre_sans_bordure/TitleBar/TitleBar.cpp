#include "TitleBar.h"

namespace nkentseu {
    using namespace math;

    TitleBar::TitleBar(TitleBarTheme& Bartheme, NkWindow& win) 
    : theme(Bartheme), cross(Bartheme.buttonSize), maximize({theme.buttonSize.x - theme.btnOffset, theme.buttonSize.y, theme.buttonSize.w, theme.buttonSize.h}),
    minimize({(int32)(theme.buttonSize.x - theme.buttonSize.w - theme.btnOffset), theme.buttonSize.y, theme.buttonSize.w, theme.buttonSize.h}),
    window(win) {
        
        //BRUSH DE REMPLISSAGE
        brush = CreateSolidBrush(RGB(theme.TitleBarcolor.r, theme.TitleBarcolor.g, theme.TitleBarcolor.b));
        clickedBrush = CreateSolidBrush(RGB(theme.closeColorClicked.r, theme.closeColorClicked.g, theme.closeColorClicked.b));
        hoverBrush = CreateSolidBrush(RGB(theme.CloseColorhover.r, theme.CloseColorhover.g, theme.CloseColorhover.b));

        //brush maxBTN
        hoverMaxBrush = CreateSolidBrush(RGB(theme.maximizeColorHover.r, theme.maximizeColorHover.g, theme.maximizeColorHover.b));
        clickedMaxBrush = CreateSolidBrush(RGB(theme.maximizeColorClicked.r, theme.maximizeColorClicked.g, theme.maximizeColorClicked.b));

        // BRUSH MINIMIZE
        hoverMinBrush = CreateSolidBrush(RGB(theme.mimizeColorHover.r, theme.mimizeColorHover.g, theme.mimizeColorHover.b));
        clickedMinBrush = CreateSolidBrush(RGB(theme.mimizeColorClicked.r, theme.mimizeColorClicked.g, theme.mimizeColorClicked.b));

        //POLICE
        font = CreateFontA(
            32,
            0,
            0, 0,
            FW_NORMAL,
            FALSE,FALSE, FALSE,
            DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS,
            CLEARTYPE_QUALITY,
            DEFAULT_PITCH | FF_SWISS,
            "Segoe UI"
        );

        pen = CreatePen(PS_SOLID, 2, RGB(theme.TitleBarcolor.r, theme.TitleBarcolor.g, theme.TitleBarcolor.b));
        penHover = CreatePen(PS_SOLID, 2, RGB(theme.componentColorHovered.r, theme.componentColorHovered.g, theme.componentColorHovered.b));
    }

    TitleBar::~TitleBar() {
        DeleteObject(brush);
        DeleteObject(hoverBrush);
        DeleteObject(clickedBrush);
        DeleteObject(hoverMaxBrush);
        DeleteObject(hoverMinBrush);
        DeleteObject(clickedMaxBrush);
        DeleteObject(clickedMinBrush);
        DeleteObject(pen);
        DeleteObject(font);
        DeleteObject(penHover);
    }

    bool TitleBar::IsInside(NkVec2 mouse, NkWindow& window) {
        NkRect2i rect {static_cast<int>(theme.barreSize.left), static_cast<int>(theme.barreSize.top), static_cast<int>(window.GetSize().width), static_cast<int>(theme.barreSize.bottom - theme.barreSize.top)};
        return rect.Contains(mouse);
    }

    void TitleBar::RenderBar(NkWindow& window, NkEvent* event) {

        HDC hdc = GetDC(window.GetSurfaceDesc().hwnd);

        //rectangle de la barre te titre
        FillRect(hdc, &theme.barreSize, brush);
        
        //Composants de la barre de titre
        // - croix
        switch (cross.GetState()) {
            case ComponentState::HOVER:
                cross.DrawButton(hdc, hoverBrush, penHover);
                break;
            case ComponentState::CLICKED:
                cross.DrawButton(hdc, clickedBrush, penHover);
                window.Close();
                break;
            case ComponentState::NONE :
                cross.DrawButton(hdc, brush, penHover);
                break;
        }

        // - maximize
        switch (maximize.GetState()) {
            case ComponentState::HOVER:
                maximize.DrawButton(hdc, hoverMaxBrush, penHover);
                break;
            case ComponentState::CLICKED:
                maximize.DrawButton(hdc, clickedMaxBrush, penHover);
                window.Maximize();
                maximize.SetState(ComponentState::NONE);
                break;
            case ComponentState::NONE :
                maximize.DrawButton(hdc, brush, penHover);
                break;
        }

        // - minimize
        switch (minimize.GetState()) {
            case ComponentState::HOVER:
                minimize.DrawButton(hdc, hoverMinBrush, penHover);
                minimize.SetState(ComponentState::NONE);
                break;
            case ComponentState::CLICKED:
                minimize.DrawButton(hdc, clickedMinBrush, penHover);
                window.Minimize();
                minimize.SetState(ComponentState::NONE);
                break;
            case ComponentState::NONE :
                minimize.DrawButton(hdc, brush, penHover);
                break;
        }

        //DESSIN DU TITRE DE LA FENETRE
        SetTextColor(hdc, RGB(255, 255, 255));
        SetBkMode(hdc, TRANSPARENT);
        HFONT oldFont = (HFONT)SelectObject(hdc, font);
        TextOutA(hdc, 280, 20, window.GetTitle().CStr(), window.GetTitle().Length());
        SelectObject(hdc, oldFont);

        ReleaseDC(window.GetSurfaceDesc().hwnd, hdc);
    }

    void TitleBar::Update(NkEvent* e, float dt) {
        cross.Update(e);
        minimize.Update(e);
        maximize.Update(e);

        if (auto* mouse = e->As<NkMouseButtonPressEvent>()) {
                if (mouse->IsLeft() && IsInside({static_cast<float>(mouse->GetX()),static_cast<float>(mouse->GetY())}, window)) {
                    if (cross.IsInside({static_cast<float>(mouse->GetX()),static_cast<float>(mouse->GetY())})) {
                        followMouse = false;
                    }  if (maximize.IsInside({static_cast<float>(mouse->GetX()),static_cast<float>(mouse->GetY())})) {
                        followMouse = false;
                    } if (minimize.IsInside({static_cast<float>(mouse->GetX()),static_cast<float>(mouse->GetY())})) {
                        followMouse = false;
                    } else {
                        if (mouse->GetClickCount() == 2) {
                            if (window.IsMaximized())
                            window.Restore();
                            else window.Maximize();
                        } else{
                            followMouse = true;
                            mouseOldPos = {static_cast<float>(mouse->GetX()), static_cast<float>(mouse->GetX())};
                            logger.Info("[follow mouse ok] : {0}", mouseOldPos);}
                    }
                }
            }
            if (auto* mouse = e->As<NkMouseMoveEvent>()) {
                if (followMouse) {
                    NkVec2 mousePos {};
                    NkVec2 winPos = window.GetPosition();
                    int32 sx = mouse->GetScreenX();
                    int32 sy = mouse->GetScreenY();
                    int32 x = mouse->GetX();
                    int32 y = mouse->GetY();

                    mousePos = {static_cast<float>(sx), static_cast<float>(sy)};
                    NkVec2 mouseWinPos = {static_cast<float>(x), static_cast<float>(y)};
                    static NkVec2  msdelta = {mousePos.x - mouseWinPos.x, mousePos.y};
                    NkVec2  offset = {mousePos.x - msdelta.x, mousePos.y - 20};
                    window.SetPosition(offset);

                    logger.Info("mouseOldPos : {0} \n mousePos : {1}; delta: {2}", mouseWinPos, mousePos, msdelta);
                }
            }
            if (auto* mouse = e->As<NkMouseButtonReleaseEvent>()) {
                if (mouse->IsLeft()) followMouse = false;
            }
    }
    
} // namespace nkentseu
