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

    NkKeyPressEvent* event = nullptr;
    NkClock clock;
    float32 time = 0.f;
    while (win.IsOpen()) {
        float32 dt = clock.Tick().delta;
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>()) {
                win.Close();
            }
            if (auto* key = e->As<NkKeyPressEvent>()) {
                event = key;
                logger.Info("[App] : touche du clavier");
            }
            if(time > 5) {
                logger.Warn("[App] : Utilisation de la copie de l'évènement {0}", NkScancodeToString(event->GetScancode()));
                time = 0.f;
            }
        }
        time += dt;
    }
    return 0;
}