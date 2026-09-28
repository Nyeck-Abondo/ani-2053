#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

NKENTSEU_DEFINE_APP_DATA(([]() {
    NkAppData d{};
    d.appName    = "exercice 1";
    d.appVersion = "0.1.0";
    return d;
})());

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title   =   "Fenetre";
    cfg.width   =   1280;
    cfg.height  =   720;

    NkWindow window(cfg);
    NkWindow win02(cfg);
    if (!window.IsOpen() || !win02.IsOpen()) {
        logger.Error("Erreur de création de la fenêtre.");
        return -1;
    }
    while (window.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->As<NkWindowCloseEvent>()) {
                if (e->GetWindowId() == window.GetId())
                    window.Close();
                else 
                    win02.Close();
            }

            if (e->As<NkMouseButtonPressEvent>()) {
                logger.Info("[Clic] : Fenêtre d'identifiant : {0}", e->GetWindowId());
            }
        }
    }
    return 0;
}