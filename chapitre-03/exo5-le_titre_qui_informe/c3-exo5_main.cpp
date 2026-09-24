#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEvent.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

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
            if (e->As<NkWindowMoveEvent>()) {
                modified = true;
                window.SetTitle("exo5-le_titre_qui_informe * " + window.GetSize().ToString());
            }
            if (e->Is<NkWindowResizeEndEvent>()) {
                size = window.GetSize();
                modified = true;
            }
            if (e->Is<NkWindowDpiEvent>()) modified = true;
            if (e->Is<NkWindowFocusGainedEvent>()) modified = true;
            if (e->Is<NkWindowPaintEvent>()) modified = true;
            if (e->Is<NkWindowShownEvent>()) modified = true;
            if (e->Is<NkWindowFocusLostEvent>()) modified = true;
            if (e->Is<NkWindowMoveEndEvent>()) modified = true;

            if (modified) {
                window.SetTitle("exo5-le_titre_qui_informe " + size.ToString() + "  * ");
            } else {
                window.SetTitle("exo5-le_titre_qui_informe " + size.ToString());
            }
            modified = false;
        }
    }
    return 0;
}