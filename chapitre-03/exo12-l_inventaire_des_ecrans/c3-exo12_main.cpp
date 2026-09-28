#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"

using namespace nkentseu;

NKENTSEU_DEFINE_APP_DATA(([] () {
    NkAppData d {};
    d.appName       =   "exercice 12";
    d.appVersion    =   "0.1.0";
    return d;
}) ())

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title       =   "Exercice 12";
    cfg.width       =   1280;
    cfg.height      =   720;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Info("[Window] : Erreur de creation de le den[etre]");
        return -1;
    }

    while (window.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
            if (auto* k = e->As<NkKeyPressEvent>()) {
                if (k->GetKey() == NkKey::NK_G) {
                    logger.Warn("[Fenetre] : {0} \n Identifiant : {1} \n Taille (resolution logique) : {2} x {3}\n Taille physique : {4} x {5} \n  Position : ({6} , {7}) \n Facteur d'échelle : {8}", 
                                window.GetCurrentMonitor().name, window.GetCurrentMonitor().index, window.GetCurrentMonitor().width, window.GetCurrentMonitor().height
                                , window.GetCurrentMonitor().physWidth, window.GetCurrentMonitor().physHeight, window.GetCurrentMonitor().posX, window.GetCurrentMonitor().posY, window.GetCurrentMonitor().dpiScale);
                }
            }
        }
        
    }
    
    return 0;
}