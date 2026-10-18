#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKTime/NkClock.h"
#include "NKMemory/NkUniquePtr.h"

using namespace nkentseu;

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title       =   "C4-exercice 3";
    cfg.width       =   1280;
    cfg.height      =   720;

    NkWindow win(cfg);
    if(!win.IsOpen()) {
        logger.Error("[Window] : Erreur de creation de la fenêtre");
        return -1;
    }

    NkEvent* event = nullptr;
    NkClock clock;
    float32 time = 0.f;
    while (win.IsOpen()) {
        float32 dt = clock.Tick().delta;
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>()) {
                win.Close();
            }
            event = NkEvents().PollEvent();
            if (auto* p = event->As<NkKeyPressEvent>()) {
                logger.Warn("Seconde Evenement dans la même frame");
            }
            if (auto* key = e->As<NkKeyPressEvent>()) {
                logger.Info("[App] : touche du clavier");
            }
        }
        time += dt;
    }
    return 0;
}