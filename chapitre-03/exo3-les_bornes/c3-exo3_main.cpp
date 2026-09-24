#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
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
    cfg.title       =   "Fenetre de l'exercice 3";
    cfg.width       =   1400;
    cfg.height      =   800;
    cfg.minHeight   =   600;
    cfg.minWidth    =   800;

    NkWindow window;
    if (!window.Create(cfg)) {
        logger.Error("[APP] : Erreur de creation de la fenetre");
        return -1;
    }

    while(window.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
            if (e->Is<NkWindowResizeBeginEvent>())
                logger.Info("[Window] : width = {0}     height = {1}", window.GetSize().width, window.GetSize().height);
        }
    }

    return 0;
}