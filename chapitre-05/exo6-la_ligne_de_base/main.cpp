#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
#include <cstdint>
#include <string>

struct Glyph {
    int64_t avance;
    int64_t x0, y0, x1, y1;
    
    friend std::istream& operator>> (std::istream& is, Glyph& g) {
        return is >> g.avance >> g.x0 >> g.y0 >> g.x1 >> g.y1;
    }
};

struct Text {
    std::map<char, Glyph> caracter;
    std::map<std::string, int64_t> caracterKern;
    std::string content;
    int64_t ox = 0, oy = 0;
    
    void Result() {
        int64_t x = ox;
        int64_t rx0 = INT64_MAX, rx1 = INT64_MIN, ry0 = INT64_MAX, ry1 = INT64_MIN;
        int abscents = 0;
        
        for (int i = 0; i < content.size(); i++) {
            auto it = caracter.find(content[i]);
            if (it == caracter.end()) {
                std::cout << content[i] << " ABSENT\n";
                abscents++;
                continue;
            }
            Glyph& g = it->second;
            std::cout << content[i] << " " << x << "\n";
            if (g.x1 > g.x0 && g.y1 > g.y0) {
                rx0 = std::min(rx0, x + g.x0);
                ry0 = std::min(ry0, oy + g.y0);
                rx1 = std::max(rx1, x + g.x1);
                ry1 = std::max(ry1, oy + g.y1);
            }
            x += g.avance;
            if (i != content.size() - 1) {
                std::string k = content.substr(i, 2);
                auto it2 = caracterKern.find(k);
                if (it2 != caracterKern.end())
                x += it2->second;
            }
        }
        
        int64_t m = (ry0 < oy) ? oy - ry0 : 0;
        int64_t d = (ry1 > oy) ? ry1 - oy : 0;
        std::string screen = (ry1 <= 0) ? "HORS" : (ry0 < 0) ? "COUPE" : "VISIBLE";
        std::cout << "CURSEUR " << x << "\n";
        std::cout << "BOITE " << rx0 << " " << ry0 << " " << rx1 << " " << ry1 << "\n";
        std::cout << "MONTE " << m << "\n";
        std::cout << "DESCEND " << d << "\n";
        std::cout << "ECRAN " << screen << "\n";
        std::cout << "ABSENTS " << abscents << std::endl;
    }
};

int main() {
    int n = 0;
    Text sentence;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        Glyph g;
        std::cin >> c >> g;
        sentence.caracter.insert({c, g});
    }
    n = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string s;
        int64_t v;
        std::cin >> s >> v;
        sentence.caracterKern.insert({s, v});
    }
    std::cin >> sentence.content >> sentence.ox >> sentence.oy;
    sentence.Result();
    
    return 0;
}
