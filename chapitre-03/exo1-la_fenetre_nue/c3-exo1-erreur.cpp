#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

using namespace nkentseu;

NKENTSEU_DEFINE_APP_DATA(([]() {
    NkAppData d{};
    d.appName    = "MonJeu";
    d.appVersion = "0.1.0";
    return d;
})());

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title   =   "Fenetre";
    cfg.width   =   1280;
    cfg.height  =   720;

    cfg.canFullscreen   =   true;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("Erreur de création de la fenêtre.");
        return -1;
    }
    while (window.IsOpen()) {}
    return 0;
}