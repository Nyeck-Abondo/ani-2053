#pragma once

#include "NKCanvas/App/NkCanvasApp.h"

class fenetre : public nkentseu::renderer::NkCanvasApp {
    public:
        fenetre();
        ~fenetre();
        void OnRender(nkentseu::renderer::NkRenderWindow &target) override;
    private:
};