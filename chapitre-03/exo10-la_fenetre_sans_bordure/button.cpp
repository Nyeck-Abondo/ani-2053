#include "button.h"

namespace nkentseu {
    using namespace math;

    void Button::Update(NkEvent* event) {
        if (auto* m = event->As<NkMouseMoveEvent>()) {
            NkVec2 mousePos = { static_cast<float>(m->GetX()), static_cast<float>(m->GetY()) };
            state = IsInside(mousePos) ? ComponentState::HOVER : ComponentState::NONE;
        }
        if (IsClicked(*event))
            state = ComponentState::CLICKED;
        if (auto* m = event->As<NkMouseButtonReleaseEvent>()) {
            state = ComponentState::NONE;
        }
    }

    bool Button::IsClicked(NkEvent& e) {
        if (auto * ms = e.As<NkMouseButtonPressEvent>()) {
            if (ms->IsLeft() && IsInside({static_cast<float>(ms->GetX()),static_cast<float>(ms->GetY())})) {
                return true;
            }
        }
        return false;
    }

    bool Button::IsInside(NkVec2 mousePos) {
        return size.Contains(mousePos);
    }
    
    void CrossBtn::DrawButton(HDC& hdc ,HBRUSH& brush, HPEN& pen) {
        FillRect(hdc, &buttonSize, brush);
        HPEN holdPen = (HPEN)SelectObject(hdc, pen);
        MoveToEx(hdc, size.x + 7, size.y + 3, nullptr);
        LineTo(hdc, size.x + size.width - 7, size.y + size.height - 3);
        MoveToEx(hdc, size.x + size.width - 7, size.y + 3, nullptr);
        LineTo(hdc, size.x + 7, size.y + size.height - 3);

        SelectObject(hdc, holdPen);
    }

    //===========================
    //BOUTON MAXIMISER
    //===========================
    void MaxBtn::DrawButton(HDC& hdc ,HBRUSH& brush, HPEN& pen) {
        FillRect(hdc, &buttonSize, brush);
        HPEN holdPen = (HPEN)SelectObject(hdc, pen);
        Rectangle(hdc, size.x + 7, size.y + 7, size.x + size.width - 7, size.y + size.height - 7);

        SelectObject(hdc, holdPen);
    }
    
    //==========================
    //BOUTON MINIMISER
    //+++++++++++++++++++++++++
    void MinBtn::DrawButton(HDC& hdc ,HBRUSH& brush, HPEN& pen) {
        FillRect(hdc, &buttonSize, brush);
        HPEN holdPen = (HPEN)SelectObject(hdc, pen);
        Rectangle(hdc, size.x + 7, size.y + size.width / 2 - 10, size.x + size.w - 7 , size.y + size.w / 2 - 9);
        SelectObject(hdc, holdPen);
    }

} // namespace nkentseu
