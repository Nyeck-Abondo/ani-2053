#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEvent.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkKeyboardEvent.h"

using namespace nkentseu;

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title           =   "Fentre c3 exo2";
    cfg.width           =   1280;
    cfg.height          =   720;
    cfg.resizable       =   true;
    cfg.movable         =   true;
    cfg.centered        =   true;
    cfg.closable        =   true;
    cfg.minimizable     =   true;
    cfg.maximizable     =   true;
    cfg.canFullscreen   =   false;
    cfg.fullscreen      =   true;
    
    NkWindow window;
    if (!window.Create(cfg)) {
        logger.Error("Erreur de création de la fenêtre");
        return -1;
    }
    while (window.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (auto* key = e->As<NkKeyPressEvent>()) {
                if (key->GetKey() == NkKey::NK_F)
                    window.Close();
            }
        }
    }
    return 0;
}
