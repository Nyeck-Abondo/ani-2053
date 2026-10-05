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

#include "NKCanvas/Renderer/Resources/NkFont.h"
#include "NKCanvas/Renderer/Resources/NkSprite.h"

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
    nkentseu::NkVector<nkentseu::math::NkRect2f> carre;
    float pos = 100;
    for (int i = 0; i < 30; i++) {
        carre.PushBack({pos, 200, 200, 200});
        pos += 250;
    }
    nkentseu::math::NkRect2f barre {0, 0, static_cast<float>(win.GetSize().width), 100};

    //police pour l'ecriture
    nkentseu::renderer::NkFont font;
    if(!font.LoadFromFile(*target.GetRenderer(), "Where-is-my-Frog.ttf")) {
        logger.Error("Echec de chargement de la police");
        return -3;
    }

    nkentseu::renderer::NkText title(font, "Je suis le titre de l'interface", 32);
    title.SetFillColor(nkentseu::math::NkColor::White);
    title.SetPosition({static_cast<float>(win.GetSize().width / 2), 100});

    //camera
    nkentseu::renderer::NkView2D camera;
    camera.center       =   {static_cast<float>(cfg.width / 2), static_cast<float>(cfg.height / 2)};
    camera.size         =   {1280, 720};

    //interval de log
    nkentseu::float32 logIntervals = 0;
    while (run) {
        nkentseu::float32 dt = clock.Tick().delta;
        while (nkentseu::NkEvent* e = events.PollEvent()) {
            (void)e;
        }
        if (!run)
            break;
        
        target.SetView(camera);
        camera.center = {camera.center.x + dt * 70, camera.center.y};
        target.Clear();
        nkentseu::renderer::NkRenderer2D rd = target.GetRenderer2D();
        for (int i = 0; i < carre.size(); i++) {
            rd.DrawRect(carre[i], {65, 171, 204});
        }
        target.ResetView();
        rd.DrawRect(barre, nkentseu::math::NkColor::SkyBlue);
        target.Draw(title);
        target.Display();
        logIntervals += dt;
        if (logIntervals > 2.f) {
            logger.Info("[Barre de titre] : {0}", barre.x);
            logger.Info("[Camera] : {0}", camera.center);
            logIntervals = 0.f;
        }
    }
    return 0;
}