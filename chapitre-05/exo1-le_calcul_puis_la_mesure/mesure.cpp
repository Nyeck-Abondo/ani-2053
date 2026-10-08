#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKCanvas/App/NkCanvasApp.h"

class App : public nkentseu::renderer::NkCanvasApp {
    private:
    nkentseu::NkImage icone;
    nkentseu::NkImage aplat;
    nkentseu::NkImage phototel;
    nkentseu::NkImage JpegPc;
    nkentseu::NkImage capture;

    public:
    App() {
        Config().title      =   "exercice 1";
        Config().width      =   1280;
        Config().height     =   720;
        Config().clearColor =   {65, 171, 204};
    }

    bool OnKeyPress(const nkentseu::NkKeyPressEvent &event) override {
        if (event.GetKey() == nkentseu::NkKey::NK_C) {
            if (!capture.Load("exo1-le_calcul_puis_la_mesure/ressources/fenetre.jpg", 4))
                logger.Error("[APP] : erreur de chargement de fenetre.jpg");
            else
                logger.Info("[APP] : fenetre.png  - Largeur {0} - Hauteur {1} - BytesPP() : {2} Poids : {3}", capture.Width(), capture.Height(), capture.BytesPP(), capture.Width() * capture.Height() * capture.BytesPP());
        }
        if (event.GetKey() == nkentseu::NkKey::NK_A) {
            if (!aplat.Load("exo1-le_calcul_puis_la_mesure/ressources/aplat.png"))
                logger.Error("[APP] : erreur de chargement de aplat.png");
            else
                logger.Info("[APP] : aplat.png - Largeur {0} - Hauteur {1} - BytesPP() : {2} Poids : {3}", aplat.Width(), aplat.Height(), aplat.BytesPP(), aplat.Width() * aplat.Height() * aplat.BytesPP());
        }
        if (event.GetKey() == nkentseu::NkKey::NK_I) {
            if (!icone.Load("exo1-le_calcul_puis_la_mesure/ressources/icons8-coffee-cup-100 (1).png"))
                logger.Error("[APP] : erreur de chargement de icons8-coffee-cup-100 (1).png");
            else
                logger.Info("[APP] : icons8-coffee-cup-100 (1).png - Largeur {0} - Hauteur {1} - BytesPP() : {2} Poids : {3}", icone.Width(), icone.Height(), icone.BytesPP(), icone.Width() * icone.Height() * icone.BytesPP());
        }
        if (event.GetKey() == nkentseu::NkKey::NK_J) {
            if (!JpegPc.Load("exo1-le_calcul_puis_la_mesure/ressources/errr.jpeg"))
                logger.Error("[APP] : erreur de chargement de errr.jpeg");
            else
                logger.Info("[APP] : errr.jpeg - Largeur {0} - Hauteur {1} - BytesPP() : {2} Poids : {3}", JpegPc.Width(), JpegPc.Height(), JpegPc.BytesPP(), JpegPc.Width() * JpegPc.Height() * JpegPc.BytesPP());
        }
        if (event.GetKey() == nkentseu::NkKey::NK_P) {
            if (!phototel.Load("exo1-le_calcul_puis_la_mesure/ressources/photo.jpeg"))
                logger.Error("[APP] : erreur de chargement de photo.jpeg");
            else
                logger.Info("[APP] : photo.jpeg - Largeur {0} - Hauteur {1} - BytesPP() : {2} Poids : {3}",phototel.Width(), phototel.Height(), phototel.BytesPP(), phototel.Width() * phototel.Height() * phototel.BytesPP());
        }
        return true;
    }
};

int nkmain(const nkentseu::NkEntryState& state) {
    return nkentseu::renderer::NkCanvasApp::Run<App>(state);
}