#include <iostream>
#include <string>
#include "copie/NkRef/NkRefView.h"
#include "NKMath/NkMAth.h"

using nkentseu::math::NkVec2f;

bool aller_retour() {
    NkVec2f p {2, 0}, vp {800, 600};
    nkref::NkRefView view;
    view.zoom = 2.5f;
    view.center = {10.f, 0.5f};
    NkVec2f r = view.WorldToPixel(view.PixelToWorld(p, vp), vp);
    if (nkentseu::math::NkAbs(r.x - p.x) < 0.001f && nkentseu::math::NkAbs(r.y - p.y) < 0.001f)
        return true;
    return false;
}

bool point_fixe() {
    NkVec2f p {2, 0}, vp {800, 600}, j {2, 0};
    nkref::NkRefView view;
    NkVec2f avant = view.PixelToWorld(p, vp);
    view.ZoomAtPixel(2.f, p, vp);
    NkVec2f apres = view.PixelToWorld(p, vp);
    if (nkentseu::math::NkAbs(apres.x - avant.x) < 0.001 && nkentseu::math::NkAbs(apres.y - avant.y) < 0.001)
        return true;
    return false;
}

bool bornes() {
    NkVec2f p {2, 0}, vp {800, 600}, j {2, 0};
    nkref::NkRefView view;
    nkentseu::float32 z = 1000;
    view.ZoomAtPixel(1000.0, p, vp);
    if (view.zoom < view.kZoomMin || view.zoom > view.kZoomMax)
        return false;
    view.ZoomAtPixel(0.00001, p, vp);
    if (view.zoom < view.kZoomMin || view.zoom > view.kZoomMax)
        return false;
    return true;
}

bool grille() {
    nkentseu::float32 m = 2.f, gp1 = 0.f, gp2 = 0.f;
    nkref::NkRefView view;
    view.zoom = 3.f;
    gp1 = view.GridSpacing(m);
    view.zoom = 1.f;
    gp2 = view.GridSpacing(m);

    if (gp1 - gp2 <= 0.0001) {
        return true;
    }
    return false;
}

bool origine() {
    NkVec2f p {2, 0}, vp {800, 600};
    nkref::NkRefView view;
    view.ZoomAtPixel(2.f, p, vp);
    view.PanByPixels(30.f, 40.f);
    view.Reset();
    if (nkentseu::math::NkAbs(view.zoom - 1.f) < 0.001f && nkentseu::math::NkAbs(view.center.x) < 0.001f && nkentseu::math::NkAbs(view.center.y) < 0.001f)
        return true;
    return false;
}

int main() {
    if (aller_retour()){
        std::cout << "TEST aller_retour : OK\n";
    } else {
        std::cout << "TEST aller_retour : ECHEC\n";
    }
    if (point_fixe()) {
        std::cout << "TEST point_fixe : OK \n";
    }
    else {
        std::cout << "TEST point_fixe : ECHEC\n";
    }
    if (bornes()) {
        std::cout << "TEST bornes : OK\n";
    }
    else {
        std::cout << "TEST bornes : ECHEC\n";
    }
    if (grille()) {
        std::cout << "TEST grille : OK\n";
    }
    else {
        std::cout << "TEST grille : ECHEC\n";
    }
    if (origine()) {
        std::cout << "TEST origine : OK\n";
    }
    else {
        std::cout << "TEST origine : ECHEC\n";
    }
    return 0;
}