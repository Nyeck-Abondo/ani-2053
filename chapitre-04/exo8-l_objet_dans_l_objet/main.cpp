#include <iostream>
#include <string>
#include <vector>

struct object {
    std::string name = "";
    std::string parent = "";
    int tx = 0, ty = 0;
    int angle = 0;
    int echelle = 1;
    int level = 1;
    object* elder = nullptr;
    bool hasParent = false;

    void updateStatistics() {
        if (parent == "-") {
            hasParent = false;
            level = 1;
            angle = ((angle % 360) + 360) % 360;
        } else {
            hasParent = true;
            tx *= elder->echelle;
            ty *= elder->echelle;
            
            int c = 0, s = 0;
            switch (elder->angle) {
                case 0 :
                    c = 1;
                    s = 0;
                break;
                case 90 :
                    c = 0;
                    s = 1;
                break;
                case 180 :
                    c = -1;
                    s = 0;
                break;
                default :
                    c = 0;
                    s = -1;
                break;
            }
            int rx = tx * c - ty * s;
            int ry = tx * s + ty * c;

            tx += elder->tx + rx;
            ty += elder->ty + ry;

            angle = ((elder->angle + angle) % 360 + 360) % 360;

            echelle = elder->echelle * echelle;
            level = elder->level + 1;
        }
    }

    friend std::istream& operator>> (std::istream& is, object& obj) {
        return is >> obj.name >> obj.parent >> obj.tx >> obj.ty >> obj.angle >> obj.echelle;
    }

    friend std::ostream& operator<< (std::ostream& os, object& obj) {
        return os << obj.name << " " << obj.tx << " " << obj.ty << " " << obj.angle << " " << obj.echelle << std::endl;
    }

    void Findparent(std::vector<object>& obj) {
        for (auto& o : obj) {
            if (parent == o.name) {
                elder = &o;
                level = o.level + 1;
            }
        }
    }
};



int main() {
    int N = 0;                                          // AJOUTER
    std::cin >> N;
    std::vector<object> objs(N);                        // taille finale : pas de réallocation
    int profondeur = 0;

    for (int i = 0; i < N; i++) {
        std::cin >> objs[i];
        objs[i].Findparent(objs);
        objs[i].updateStatistics();

        if (objs[i].level > profondeur) {
            profondeur = objs[i].level;
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << objs[i];
    }

    std::cout << "PROFONDEUR " << profondeur << std::endl;
    return 0;
}