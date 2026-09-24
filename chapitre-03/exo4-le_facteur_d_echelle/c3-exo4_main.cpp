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
    cfg.title           =   "Fenêtre ecercice4";
    cfg.width           =   1280;
    cfg.height          =   820;

    NkWindow window;
    if (!window.Create(cfg)) {
        logger.Error("[APP] : Erreur de creation de la fenetre");
        return -1;
    }

    while(window.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
            if (e->Is<NkWindowMoveEvent>())
                logger.Info("[Window] : taille rendue par la fenêtre: {0} x {1} \n [Window] : Taille rendue par la cible de rendu: {2} x {3} \n facteur d'échelle : {4}", window.GetSize().width, window.GetSize().height + 32, window.GetConfig().width, window.GetConfig().height, window.GetDpiScale());
        }
    }
    return 0;
}