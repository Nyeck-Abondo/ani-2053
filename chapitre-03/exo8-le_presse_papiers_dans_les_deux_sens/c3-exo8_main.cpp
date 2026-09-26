#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkKeyboardEvent.h"

using namespace nkentseu;

NKENTSEU_DEFINE_APP_DATA(([] () {
    NkAppData d {};
    d.appName       =   "Exercice8";
    d.appVersion    =   "0.1.0";
    return d;
})())

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title       =   "Exercice 8";
    cfg.width       =   1280;
    cfg.height      =   720;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        logger.Info("[FENETRE] : Erreur d'initialisation de la fenêtre !");
        return -1;
    }

    //variable de stockage des tests
    NkString text;
    NkClipboardImage image {};

    while (window.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
            if (auto* key = e->As<NkKeyPressEvent>()) {
                if (key->GetKey() == NkKey::NK_G && key->HasCtrl()) {
                    text = window.GetClipboardText();
                    window.SetClipboardText(text.ToUpper());
                    logger.Info("[CLIPBOARD TEXT] : convertion en majuscule tu texte \"{0}\"", text.ToLower());
                }
                if (key->GetKey() == NkKey::NK_I && key->HasCtrl()) {
                    if (window.GetClipboardImage(image)) {
                        logger.Info("[CLIPBORD IMAge] : Récupération de l'image du presse papier");
                    } else {
                        logger.Error("[CLIPBORD IMAge] : Impossible de recupérer l'image du presse papier");
                    }
                    for (int i = 0; i < image.pixels.size(); i++) {
                        if (i % 4 == 0) continue;
                        image.pixels[i] = 255u - image.pixels[i];
                    }
                    if (window.SetClipboardImage(image)) {
                        logger.Info("[CLIPBORD IMAge] : Reussite de changement de l'image");
                    } else {
                        logger.Error("[CLIPBORD IMAge] : Echec , image invalide par l'OS");
                    }
                }
            }
        }
    }
    

    return 0;
}