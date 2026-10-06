#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"

#include "NKCanvas/App/NkCanvasApp.h"
#include "NKCanvas/Renderer/Targets/NkRenderWindow.h"
#include "NKCanvas/Renderer/Core/NkRenderer2D.h"
#include "NKCanvas/Core/NkContextDesc.h"
#include "NKCanvas/Core/NkGraphicsApi.h"

#include "NKMath/NkMat.h"
#include "NKMath/NkColor.h"
#include "NKTime/NkTime.h"

class coquille : public nkentseu::renderer::NkCanvasApp {
    private:
    nkentseu::math::NkRectf carre {200, 250, 100, 100};
    int speed = 100;
    
    public:
    coquille() {
        Config().title      =   "Exercice 4";
        Config().width      =   1280;
        Config().height     =   720;
        Config().clearColor =   {45, 45, 45};
    }

    void OnRender(nkentseu::renderer::NkRenderWindow &target) override {
        nkentseu::renderer::NkRenderer2D rd = target.GetRenderer2D();
        rd.DrawRect(carre, {165, 20, 20});
    }

    void OnUpdate(nkentseu::float32 deltaTime) override {
        carre.x += speed * deltaTime;
    }
};

int nkmain(const nkentseu::NkEntryState& state) {
    return nkentseu::renderer::NkCanvasApp::Run<coquille>(state);
}