#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEvent.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title   =   "Fenetre";
    cfg.width   =   1280;
    cfg.height  =   720;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("Erreur de création de la fenêtre.");
        return -1;
    }
    while (window.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
        }
    }
    return 0;
}
