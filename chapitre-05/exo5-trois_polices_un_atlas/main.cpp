#include <iostream>
#include <sstream>
#include <vector>
#include <cstdint>
#include <string>
#include <algorithm>

struct Cursor {
    uint32_t x = 0, y = 0;
    int64_t e;
};

struct GlyphGroup {
    std::string name;
    int count;
    int w = 1;
    int h = 1;
    int x0 = 0, y0 = 0;
    int x1 = 0, y1 = 0;
    
    friend std::istream& operator>> (std::istream& is, GlyphGroup& g) {
        return is >> g.name >> g.count >> g.w >> g.h;
    }
    
    friend std::ostream& operator<< (std::ostream& os, GlyphGroup& g) {
        return os << g.name << " " << g.x0 << " " << g.y0 << " " << g.x1 << " " << g.y1 << std::endl;
    }
};

struct AtlasPacker {
    int p = 0;
    int L = 0;
    int64_t W = 0, H = 0;
    uint32_t occupe = 0, perdu = 0;
    std::vector<GlyphGroup> groups;
    Cursor cr;
    
    friend std::istream& operator>> (std::istream& is, AtlasPacker& a) {
        return is >> a.p >> a.L;
    }
    
    void Initialize() {
        if (L > 0)
            W = H = L;
        if (L == 0) {
            W = 512;
            int need = 0;
            //calcul du besoin Total
            for (auto& g : groups) {
                need += (uint64_t)g.count * (g.w + p) * (g.h + p);
            }
            while (W * W < 2 * need && W < 4096)
                W = W * 2;
            H = W;
        }
    }
    
    bool PackGroup() {
        cr.x = p;
        cr.y = p;
        cr.e = 0;
        for (auto& g : groups) {
            for (int i = 0; i < g.count; i++) {
                int64_t rw = g.w + p;
                int64_t rh = g.h + p;
                if (cr.x + rw > W - p) {
                    cr.x = p;
                    cr.y = cr.y + cr.e + p;
                    cr.e = 0;
                }
                if (cr.x + rw > W - p || cr.y + rh > H - p) {
                    return false;
                }
                if (i == 0) {
                    g.x0 = cr.x;
                    g.y0 = cr.y;
                }
                if (i == g.count - 1) {
                    g.x1 = cr.x;
                    g.y1 = cr.y;
                }
                
                cr.x += rw;
                cr.e = std::max(cr.e, rh);
            }
        }
        return true;
    }

};

int main() {
    int G = 0;
    AtlasPacker parcker;
    
    std::cin >> parcker;
    std::cin>> G;
    if (G == 0) {
        std::cout << "AUCUN" << std::endl;
        return 0;
    }
    parcker.groups.resize(G);
    for (auto& g : parcker.groups)
        std::cin >> g;
    parcker.Initialize();
    
    int succesTry = -1;
    for (int i = 1; i <= 8; ++i) {
         if (parcker.PackGroup()) {
             succesTry = i;
             break;
         }
         if (parcker.W == parcker.H) {
             parcker.W *= 2;
         }
         else
             parcker.H = parcker.W;
    }
    
    if (succesTry == -1) {
        std::cout << "ESSAIS 8\nECHEC" << std::endl;
        return 0;
    }
    uint64_t occupe = 0;
    for (const auto& g : parcker.groups) {
        occupe += (uint64_t)g.count * static_cast<uint64_t>(g.w * g.h);
    }

    uint64_t totalArea = parcker.W * parcker.H;
    uint64_t perdu = ((totalArea - occupe) * 100) / totalArea;

    // Affichage des résultats
    std::cout << "ESSAIS " << succesTry << "\n";
    std::cout << "TEXTURE " << parcker.W << " " << parcker.H << "\n";
    for (auto& g : parcker.groups) {
        std::cout << g;
    }
    std::cout << "OCCUPE " << occupe << "\n";
    std::cout << "PERDU " << perdu << "\n";
    return 0;
}