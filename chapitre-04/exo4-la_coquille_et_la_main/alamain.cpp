#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKWindow/Core/NkWindowConfig.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKTime/NkTime.h"
#include "NKLogger/NkLog.h"
#include "NKMath/NkColor.h"
#include "NKMath/NKMath.h"

#include "NKCanvas/Core/NkContextDesc.h"
#include "NKCanvas/Core/NkGraphicsApi.h"
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
#include "NKCanvas/Renderer/Core/NkRenderer2D.h"

int nkmain(const nkentseu::NkEntryState& state) {
    //config de la fen[etre]
    nkentseu::NkWindowConfig cfg;
    cfg.title           =   "A la main";
    cfg.width           =   1280;
    cfg.height          =   720;
    
    //creation de la fenetre
    nkentseu::NkWindow win(cfg);
    if (!win.IsOpen()) {
        logger.Error("[Window] : ERREUR DE CREATION DE LA FENETRE");
        return -1;
    }

    nkentseu::NkContextDesc desc;
    desc.api = nkentseu::NkGraphicsApi::NK_GFX_API_OPENGL;
    nkentseu::renderer::NkRenderWindow target(win, desc);
    if (!target.IsValid()) {
        logger.Error("[Target] : renderrerWindow invalide");
        return -2;
    }

    bool run = true;
    auto& events = nkentseu::NkEvents();
    events.AddEventCallback<nkentseu::NkWindowCloseEvent>([&] (nkentseu::NkWindowCloseEvent *) {
        run = false;
    });

    nkentseu::NkClock clock;
    nkentseu::math::NkRect2f carre {200, 250, 100, 100};
    float speed = 100;
    while (run) {
        nkentseu::float32 dt = clock.Tick().delta;
        while (nkentseu::NkEvent* e = events.PollEvent()) {
            (void)e;
        }
        if (!run)
            break;
        carre.x += speed * dt;
        target.Clear();
        nkentseu::renderer::NkRenderer2D rd = target.GetRenderer2D();
        rd.DrawRect(carre, {165, 20, 20});
        target.Display();
    }
    return 0;
}