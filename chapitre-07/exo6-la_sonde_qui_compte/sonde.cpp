#include "NKWindow/NkMain.h"
#include "NKWindow/NKWindow.h"
#include "NKCanvas/App/NKCanvasApp.h"
#include "NKStream/NkFileStream.h"
#include "NKMath/NkMath.h"

class Sonde : public nkentseu::renderer::NkCanvasApp {
    public:
    Sonde() {
        Config().title                =    "Exercice 6 chap 7";
        Config().width                =    1280;
        Config().height               =    720;
        Config().clearColor           =    {43, 97, 81};
        Config().imagesParSeconde    =     0;

        count = 0;
    }

    void OnRender(nkentseu::renderer::NkRenderWindow &target) override {
        count++;
        //logger.Info("[SONDE] : Compteur : {0} --- Time : {1}", count, Time());
        if (Time() >= 10) {
            //creation du fichier
            nkentseu::uint64 mode = nkentseu::NkFileStream::OpenMode::NK_WRITE_MODE;
            if (!fs.Open("Registre.txt", mode)) {
                logger.Warn("[SONDE] : Echec d'ouverture du fichier");
                Quit();
            }
            if (fs.IsOpen()) {
                nkentseu::NkString text = nkentseu::NkString::Fmt("[SONDE] compteur : {0} -- Temps : {1}", count, Time());
                fs.WriteRaw(text.Data(), text.Size());
                Quit();
            }
        }
    }
    private:
    nkentseu::uint64 count;
    nkentseu::NkFileStream fs;
};

int nkmain(const nkentseu::NkEntryState& state) {
    return nkentseu::renderer::NkCanvasApp::Run<Sonde>(state);
}