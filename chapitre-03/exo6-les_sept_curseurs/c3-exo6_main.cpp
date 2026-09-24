#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.width   =   1280;
    cfg.height  =   720;
    cfg.title   =   "exerceice6";

    NkWindow window;
    if(!window.Create(cfg)) {
        logger.Error("[APP] : Erreur de creation de la fenetre");
        return -1;
    }

    while (window.IsOpen()) {
        while(NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
            if(auto* mouse = e->As<NkMouseMoveEvent>()) {
                if (mouse->GetX() < window.GetSize().width / 7) {
                    window.SetCursor(NkWindow::NkCursorType::Arrow);
                }
                if (mouse->GetX() >= window.GetSize().width / 7 && mouse->GetX() < window.GetSize().width * 2 / 7) {
                    window.SetCursor(NkWindow::NkCursorType::Hand);
                }
                if (mouse->GetX() >= window.GetSize().width * 2 / 7 && mouse->GetX() < window.GetSize().width * 3 / 7) {
                    window.SetCursor(NkWindow::NkCursorType::Arrow);
                }
                if (mouse->GetX() >= window.GetSize().width * 3 / 7 && mouse->GetX() < window.GetSize().width * 4 / 7) {
                    window.SetCursor(NkWindow::NkCursorType::Arrow);
                }
                if (mouse->GetX() >= window.GetSize().width * 4 / 7 && mouse->GetX() < window.GetSize().width * 5 / 7) {
                    window.SetCursor(NkWindow::NkCursorType::Arrow);
                }
                if (mouse->GetX() >= window.GetSize().width * 5 / 7 && mouse->GetX() < window.GetSize().width * 6 / 7) {
                    window.SetCursor(NkWindow::NkCursorType::Arrow);
                }
            }
        }
    }
    

    return 0;
}