#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

NKENTSEU_DEFINE_APP_DATA(([]() {
    NkAppData d{};
    d.appName    = "MonJeu";
    d.appVersion = "0.1.0";
    return d;
})());

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

    //mise plqce du curseur dès le départ
    window.SetCursor(NkWindow::NkCursorType::Hand);
    while(window.IsOpen()) {
        while(NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
        }
    }
    return 0;
}