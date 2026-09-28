#include "NKWindow/NKMain.h"
#include "NKTime/NkClock.h"
#include "TitleBar/TitleBar.h"

using namespace nkentseu;
using namespace nkentseu::math;

NKENTSEU_DEFINE_APP_DATA(([] () {
    NkAppData d {};
    d.appName       =   "exercice 10";
    d.appVersion    =   "0.1.0";
    return d;
}) ())

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title       =   "Fenetre";
    cfg.width       =   1280;
    cfg.height      =   720;
    cfg.centered    =   true;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Error("Erreur de création de la fenêtre.");
        return -1;
    }

    window.SetDecorated(false);

    //BARRE DE TITRE
    //DEFINITION DU THEME DE LA BARRE
    TitleBarTheme theme;
    int32 left = window.GetPosition().x - window.GetSize().x / 2;
    int32 top = window.GetPosition().y - 160;
    int32 right = window.GetSize().width + window.GetPosition().x;
    int32 bottom = window.GetPosition().y - 110;
    theme.barreSize = {static_cast<LONG>(left), static_cast<LONG>(top), static_cast<LONG>(right), static_cast<LONG>(bottom)};
    theme.buttonSize = {static_cast<int>(window.GetSize().width + theme.barreSize.left + 170), static_cast<int>(theme.barreSize.top + 10), 40, 30};

    logger.Info("[window] : {0}", window.GetPosition());

    TitleBar TB(theme, window);
    logger.Info("[button] : RECT : ({0}, {1}) ({2}, {3})", TB.cross.GetButtonsize().left, TB.cross.GetButtonsize().top, TB.cross.GetButtonsize().right, TB.cross.GetButtonsize().bottom);

    NkClock clock;
    while (window.IsOpen()) {
        float32 dt = clock.GetTime().delta;
        while (NkEvent* e = NkEvents().PollEvent()) {
            TB.Update(e, dt);
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
                
            TB.RenderBar(window, e);
        }
    }
    return 0;
}