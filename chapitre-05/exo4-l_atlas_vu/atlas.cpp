#include "NkWindow/NKWindow.h"
#include "NKWindow/nkmain.h"
#include "NkFont/NkFont.h"
#include "NkCanvas/Renderer/Resources/NkTexture.h"
#include "NkImage/NkImage.h"

int nkmain(const nkentseu::NkEntryState& state) {
    nkentseu::NkFontAtlas atlas;
    nkentseu::NkFont* font = nullptr; 
    font = atlas.AddFontFromFile("exo4-l_atlas_vu/Where-is-my-Frog.ttf", 48.f);
    if (!atlas.Build()) {
        logger.Error("Echec de construction de l'atlas");
        return -1;
    }
    if (font == nullptr) {
        logger.Error("Echeg le lecture de la font");
        return -1;
    }
    nkentseu::uint8* pixels = nullptr;
    nkentseu::int32 largeur = 0, hauteur = 0;
    atlas.GetTexDataAsRGBA32(&pixels, &largeur, &hauteur);
    if (pixels == nullptr) {
        logger.Error("Erreur de remplissage des infos");
        return -2;
    }
    nkentseu::NkImage img = nkentseu::NkImage::Wrap(pixels, largeur, hauteur, nkentseu::NkImagePixelFormat::NK_RGBA32);
    if (!img.SavePNG("exo4-l_atlas_vu/atlas.png")) {
        logger.Error("Impossible de sauvegarder l'image");
        return -3;
    }
    logger.Info("sauvegarde de l'atlas count: {0}", font->glyphCount);
    return 0;
}