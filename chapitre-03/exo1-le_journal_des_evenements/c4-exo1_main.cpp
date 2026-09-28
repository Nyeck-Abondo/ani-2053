#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKTime/NkClock.h"

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

    NkClock clock;
    float64 time = 0.0f;
    while (window.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            float32 dt = clock.Tick().delta;
            if (e->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
            if (auto* mouse = e->As<NkMouseMoveEvent>()) {
                logger.Info("[Famille] : Evènement souris  - [Type] : {0}", mouse->GetTypeStr());
            }
            if (auto* key = e->As<NkKeyPressEvent>()) {
                logger.Info("[Famille] : Evènement Clavier  - [Type] : {0}", key->GetTypeStr());
            }
            if (auto* size = e->As<NkWindowResizeEvent>()) {
                logger.Info("[Famille] : Evènement Fenêtre  - [Type] : {0}", size->GetTypeStr());
            }
            if (auto* drop = e->As<NkDropFileEvent>()) {
                const auto& fileData = drop->data;
                const uint32 fileCount = fileData.Count();

                logger.Info("[Famille] : Evènement input - [Type] : {} \n Fichiers déposés : {} fichier(s) à la position ({},{})",
                    drop->GetTypeStr(), fileCount, fileData.x, fileData.y  
                );
            }
            time += dt;
            if (time >= 1.0f) {
                logger.Info("{0}",dt);
                logger.Warn("[NkEventSystem] : [Total d'évènements] - {0} ", NkEvents().GetTotalEventCount());
                time = 0.0f;
            }
        }
    }
    return 0;
}