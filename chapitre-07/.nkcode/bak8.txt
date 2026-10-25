#include "NKWindow/NkWindow.h"
#include "NKWindow/NkMain.h"
#include "NKCanvas/App/NkCanvasApp.h"

class Dessin : public nkentseu::renderer::NkDrawable {
    public:
    Dessin(nkentseu::math::NkColor color) : mColor(color) { }
    void Draw(nkentseu::renderer::NkRenderTarget &target, const nkentseu::renderer::NkRenderStates &states) const override {
        nkentseu::renderer::NkVertex vk[6];
        auto makeVk = [&] (nkentseu::float32 x, nkentseu::float32 y) {
            nkentseu::renderer::NkVertex v;
            v.x = x;
            v.y = y;
            v.r = mColor.r;
            v.g = mColor.g;
            v.b = mColor.b;
            v.a = mColor.a;
            
            return v;
        };
        vk[0] = makeVk(100.f, 300.f);
        vk[1] = makeVk(200.f, 400.f);
        vk[2] = makeVk(200.f, 400.f);
        vk[3] = makeVk(350.f, 200.f);
        vk[4] = makeVk(350.f, 200.f);
        vk[5] = makeVk(100.f, 300.f);        
        target.Draw(vk, 6, nkentseu::renderer::NkPrimitiveType::NK_LINES, states);
    }
    
    private:
    nkentseu::math::NkColor mColor;
};

class App : public nkentseu::renderer::NkCanvasApp {
    public:
    App() : mObj({3, 74, 97}) {
        Config().title        =    "Exercice 5 chap 7";
        Config().width        =    1280;
        Config().height       =    720;
        Config().clearColor   =    {43, 97, 81};
    }
    void OnRender(nkentseu::renderer::NkRenderWindow &target) override {
        target.Draw(mObj);
    }
    private:
    Dessin mObj;
};

int nkmain(const nkentseu::NkEntryState& state) {
    return nkentseu::renderer::NkCanvasApp::Run<App>(state);
}