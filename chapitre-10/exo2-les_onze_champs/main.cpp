#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdint>

struct Image {
    uint64_t id = 0, selectionne = 0;
    double x, y, echelle, rotation, opacite;
    double miroirX, miroirY;
    uint64_t largeur, hauteur;
    std::string path = "-";
    uint64_t octects = 0;

    friend std::istream& operator>> (std::istream& is, Image& i) {
        return is >> i.id >> i.x >> i.y >> i.echelle >> i.rotation >> i.opacite
        >> i.miroirX >> i.miroirY >> i.largeur >> i.hauteur >> i.selectionne
        >> i.path >> i.octects;
    }
};

int main() {
    int N = 0;
    std::vector<Image> imgs;
    std::cin >> N;
    imgs.resize(N);
    int reste = 0, change = 0;
    if (N == 0) {
        std::cout << "RESTENT " << reste << std::endl;
        std::cout << "CHANGES " << change << std::endl;
        return 0;
    }
    //remplissage du tableau
    for (int i = 0; i < N; i++) {
        std::cin >> imgs[i];
    }
    for (int i = 0; i < N; i++) {
        std::cout << "ITEM " << imgs[i].id;
        if (imgs[i].octects == 0) {
            std::cout << " SAUTE" << std::endl;
            continue;
        }
        if (imgs[i].id != 0) {
            std::cout << " " << imgs[i].id << " id";
            change++;
        }
        if (imgs[i].selectionne == 1) {
            std::cout << " selected";
            change++;
        }
        if (imgs[i].path != "-") {
            std::cout << " sourcePath";
            change++;
        }
        if (imgs[i].id == 0 && imgs[i].selectionne == 0 && imgs[i].path == "-") {
            std::cout << " AUCUN";
        }
        std::cout << std::endl;
        reste++;
    }
    std::cout << "RESTENT " << reste << std::endl;
    std::cout << "CHANGES " << change << std::endl;    
    return 0;
}