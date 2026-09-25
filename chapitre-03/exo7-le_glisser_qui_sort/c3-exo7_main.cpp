#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkMouseEvent.h"
#include "NKEvent/NkKeyboardEvent.h"
#include "NKTime/NkClock.h"

using namespace nkentseu;

NKENTSEU_APP_DATA_DEFINED(([] () {
    NkAppData d {};
    d.appName   =   "Exercice 7";
    d.appVersion    =   "0.1.0";
    return d;
})())

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title       =   "Exercice 7";
    cfg.width       =   1280;
    cfg.height      =   720;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("[APP] : Erreur de creation de la fenetre");
        return -1;
    }
    bool isDraging = false;
    NkClock clock;
    float32 logInterval = 0.f;
    while (window.IsOpen()) {
        while(NkEvent* e = NkEvents().PollEvent()) {
            float32 dt = clock.Tick().delta;
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
            if (auto* press = e->As<NkMouseButtonPressEvent>()){
                if (press->IsRight()) {
                    //window.CaptureMouse(true);
                    isDraging = true;
                }
            }
            if (auto* move = e->As<NkMouseMoveEvent>()) {
                if (logInterval > 2) {
                    logger.Info("position curseur: ({0} ; {1})", move->GetX(), move->GetY());
                    logInterval = 0.f;
                }
            }
            if (auto* key = e->As<NkKeyPressEvent>()) {
                if (key->GetKey() == NkKey::NK_F) {
                    window.Close();
                }
            }
            logInterval += dt;
        }
    }
    return 0;
}