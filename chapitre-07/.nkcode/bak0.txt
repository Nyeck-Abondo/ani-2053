#pragma once

#include "NKCanvas/Renderer/Resources/NkSprite.h"
#include "NKCanvas/App/NkCanvasApp.h"

class fenetre : public nkentseu::renderer::NkCanvasApp {
    public:
        fenetre();
        ~fenetre();
        void OnRender(nkentseu::renderer::NkRenderWindow &target) override;
    private:
    nkentseu::renderer::NkSprite sp;
};