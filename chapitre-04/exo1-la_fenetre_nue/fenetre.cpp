#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"

#include "NKCanvas/App/NkCanvasApp.h"

class fenetre : public nkentseu::renderer::NkCanvasApp {
    public:
    fenetre() {
        Config().title  =   "fenetre exerceice 1";
        Config().width  =   1280;
        Config().height =   720;
        Config().clearColor =   {65, 171, 204};
    }
};

int nkmain(const nkentseu::NkEntryState& state) {

    return nkentseu::renderer::NkCanvasApp::Run<fenetre>(state);
}