#include <iostream>
#include <vector>
#include <cstdint>
#include <cstring>
#include <sstream>
#include <iomanip>

int main() {
    int T;
    std::cin >> T;
    std::vector<uint8_t> octects;
    unsigned int v;
    for (int i = 0; i < T; i++) {
        std::cin >> std::hex >> v;
        octects.push_back(v);
    }
    //utilistaires de lectures
    int index = 0;
    auto need = [&] (int val) {
        return octects.size() >= val + index;
    };

    auto u8 = [&] () { return octects[index++]; };
    auto u32 = [&] () {
        uint32_t r = octects[index] | (octects[index + 1] << 8) | (octects[index + 2] << 16) | (octects[index + 3] << 24);
        index +=4;
        return r;
    };
    auto f32 = [&] () {
        uint32_t r = u32();
        float f;
        std::memcpy(&f, &r, 4);
        return f;
    };

    if (!need(4)) {
        std::cout << "TRONQUE" << std::endl;
        return 0;
    }
    //verification de la version
    if (octects[0] != 0x4E && octects[1] != 0x4B && octects[2] != 0x52 && octects[3] != 0x46) {
        std::cout << "PAS_UNE_PLANCHE" << std::endl;
        return 0;
    }

    index = 4;
    uint32_t version = u32();
    if (version != 1) {
        std::cout << "VERSION_INCONNUE " << version;
    }

    //les trois F32
    if (!need(12)) {
        std::cout << "TRONQUE" << std::endl;
        return 0;
    }
    float cx = f32(), cy = f32();
    float zoom = f32();

    //theme + grille
    if (!need(4)) {
        std::cout << "TRONQUE" << std::endl;
        return 0;
    }
    uint8_t theme = u8();
    uint8_t grille = u8();
    index += 2;

    std::cout << "VUE " << std::fixed << std::setprecision(2) << cx << " " << cy << " " << zoom << std::endl;
    std::cout << "THEME " << ((theme == 1) ? "SOMBRE" : "CLAIR") << std::endl;
    std::cout << "GRILLE " << (grille == 0 ? "AFFICHEE" : "IGNOREE") << std::endl;

    // les images
    if (!need(4)) {
        std::cout << "TRONQUE" << std::endl;
        return 0;
    }
    uint32_t nbImg = u32();
    std::cout << "IMAGES " << nbImg << std::endl;
    for (int i = 1; i <= nbImg; i++) {
        if (!need(36)) {
            std::cout << "TRONQUE" << std::endl;
            return 0;
        }
        float x = f32(), y = f32(), scale = f32(), rotation = f32(), opacite = f32();
        uint8_t mx = u8(), my = u8();
        //ignore les u8
        index += 2;
        uint32_t w = u32(), h = u32(), size = u32();

        if (!need(size)) {
            std::cout << "TRONQUE" << std::endl;
            return 0;
        }
        // saut de size octects source
        index += size;

        std ::cout << "IMAGE " << i << std::fixed << std::setprecision(2) << " " << x << " " << y << " " << scale << " " << rotation << " "
        << opacite << " " << (mx != 0 ? 1 : 0) << " " << (my != 0 ? 1 : 0) << " " << w << " " << h << " " << size << std::endl;

    }

    // les Traits
    if (!need(4)) {
        std::cout << "TRONQUE" << std::endl;
        return 0;
    }
    uint32_t nbTraits = u32();
    std::cout << "TRAITS " << std::fixed << std::setprecision(2) << nbTraits << std::endl;
    for (int i = 1; i <= nbTraits; i++) {
        if (!need(12)) {
            std::cout << "TRONQUE" << std::endl;
            return 0;
        }
        int r = u8(), g = u8(), b = u8(), a = u8();
        float e = f32();
        uint32_t nbPoints = u32();


        std::cout << "TRAIT " << std::fixed << std::setprecision(2) << i << " " << r << " " << g << " " << b << " "
        << a << " " << e << " " << nbPoints << std::endl;
        for (int j = 1 ; j <= nbPoints; j++) {
            if (!need(8)) {
                std::cout << "TRONQUE" << std::endl;
                return 0;
            }
            float x = f32(), y = f32();
            std::cout << "POINT " << std::fixed << std::setprecision(2) << x << " " << y << std::endl; 
        }
    }

    return 0;
}