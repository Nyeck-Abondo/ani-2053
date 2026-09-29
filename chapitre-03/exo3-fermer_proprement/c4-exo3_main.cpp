#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"

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

    while (win.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>()) {
                logger.Info("[window] : femeture de la fenetre");
                win.Close();
            }
        }
        
    }
    return 0;
}