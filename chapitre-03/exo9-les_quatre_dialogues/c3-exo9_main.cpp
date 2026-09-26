#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkKeyboardEvent.h"

using namespace nkentseu;

NKENTSEU_DEFINE_APP_DATA(([]() {
    NkAppData d{};
    d.appName    = "exercice 1";
    d.appVersion = "0.1.0";
    return d;
})());

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title   =   "Fenetre";
    cfg.width   =   1280;
    cfg.height  =   720;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("Erreur de création de la fenêtre.");
        return -1;
    }

    //boite de dialiogue
    NkDialogs boxe;

    while (window.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
            if (auto* key = e->As<NkKeyPressEvent>()) {
                switch (key->GetKey()) {
                    case NkKey::NK_F :
                        boxe.OpenFileDialog();
                    break;
                    case NkKey::NK_D :
                        boxe.OpenFolderDialog();
                    break;
                    case NkKey::NK_M :
                        boxe.OpenMessageBox("Ceci est une boite de message", "Message", 1);
                    break;
                    case NkKey::NK_S :
                        boxe.SaveFileDialog(".mp4");
                    break;
                    case NkKey::NK_L :
                        window.Close();
                    break;
                }
            }
        }
    }
    return 0;
}