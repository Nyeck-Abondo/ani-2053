#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkKeyboardEvent.h"

using namespace nkentseu;

NKENTSEU_DEFINE_APP_DATA(([]() {
    NkAppData d{};
    d.appName    = "MonJeu";
    d.appVersion = "0.1.0";
    return d;
})());

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title       =   "exo5-le_titre_qui_informe";
    cfg.width       =   1280;
    cfg.height      =   720;

    NkWindow window;
    if (!window.Create(cfg)) {
        logger.Error("[APP] : Erreur de creation de la fenetre");
        return -1;
    }

    math::NkVec2u size = window.GetSize();
    bool modified = false;

    while (window.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
            if (e->Is<NkWindowResizeEndEvent>()) {
                size = window.GetSize();
                modified = true;
            }
            if (e->As<NkWindowMoveEvent>()) modified = true;
            if (e->Is<NkWindowDpiEvent>()) modified = true;
            if (e->Is<NkWindowPaintEvent>()) modified = true;
            if (e->Is<NkWindowMoveEndEvent>()) modified = true;

            if (modified) {
                window.SetTitle("exo5-le_titre_qui_informe " + size.ToString() + "  * ");
            } else {
                window.SetTitle("exo5-le_titre_qui_informe " + size.ToString());
            }

            //retire l'état modifié par un enregistrementavec CTRL + S
            if (auto* key = e->As<NkKeyPressEvent>()) {
                if (key->GetKey() == NkKey::NK_S && key->HasCtrl())
                modified = false;
            }
        }
    }
    return 0;
}