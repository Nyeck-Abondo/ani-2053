#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKCanvas/App/NkCanvasApp.h"
#include "NKThreading/NkThreadPool.h"
#include "NKThreading/NkFuture.h"

class future : public nkentseu::renderer::NkCanvasApp {
    private:
    nkentseu::math::NkVec2f scarePos {300, 500};
    nkentseu::renderer::NkVec2f scareSize {100, 100};
    nkentseu::math::NkColor scareColor {103, 191, 177};

    bool hasLoaded;
    int framCount;

    nkentseu::threading::NkThreadPool pool;
    nkentseu::threading::NkPromise<nkentseu::NkImage> promesse;
    nkentseu::threading::NkFuture<nkentseu::NkImage> futur = promesse.GetFuture();
    public:
    future() {
        Config().clearColor        =    {44, 80, 191};
        Config().width             =    1280;
        Config().height            =    720;

        hasLoaded    =    false;
        framCount    =    0;
    }

    bool OnInit() override {

        return true;
    }
    void OnUpdate(nkentseu::float32 deltaTime) override {
        scarePos.x += 1.f;
        framCount++;
        nkentseu::NkChrono chrono;
        //calcul de la trame courante
        if (framCount == 60) {
            pool.Enqueue([&] () {
                nkentseu::NkImage img;
                img.Load("exo5-le_futur_qui_ne_bloque_pas/map.png");
                promesse.SetValue(nkentseu::traits::NkMove(img));
            });
            logger.Info("Chargement en VERSION 02");
            (void)futur.Get();
            logger.Info("[VERSION 02] : Chargement reussi temps : {0} -- trame : {1}", framCount);
        }
        nkentseu::float32 time = chrono.Reset().milliseconds;
            
        //version IsReady()
        // if (futur.IsReady()) {
            // (void)futur.Get();
            // logger.Info("[VERSION 01] : Chargement reussi -- trame : {0}", framCount);   
        // }
        
        //Version avec Juste Get
        
        logger.Warn("[VERSION 02] : temps coule : {0} -- Frame : {1}", time, framCount);
    }

    void OnRender(nkentseu::renderer::NkRenderWindow &target) override {
        nkentseu::renderer::NkRenderer2D rd = target.GetRenderer2D();
        rd.DrawRect({scarePos, scareSize}, scareColor);
    }
};

int nkmain(const nkentseu::NkEntryState& state) {
    return nkentseu::renderer::NkCanvasApp::Run<future>(state);
}