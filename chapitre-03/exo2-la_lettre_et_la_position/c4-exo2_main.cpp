#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NkEvent/NkKeycodeMap.h"

using namespace nkentseu;

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title       =   "C4-exercice 2";
    cfg.width       =   1280;
    cfg.height      =   720;

    NkWindow win(cfg);
    if(!win.IsOpen()) {
        logger.Error("[Window] : Erreur de creation de la fenêtre");
        return -1;
    }

    while (win.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>())
                win.Close();
            if (auto* key = e->As<NkKeyPressEvent>()) {
                logger.Info("Lettre de la touche: {0} -- Code physique: {1}", NkKeyToString(NkKeycodeMap::NkKeyFromWin32VK(key->GetNativeKey())), (uint32)key->GetScancode());
            }
        }
        
    }
    return 0;
}