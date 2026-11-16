#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <cmath>

struct Vec2 {
    float x, y;
    friend std::istream& operator>> (std::istream& is, Vec2& v) {
        return is >> v.x >> v.y;
    }
    bool touched = false;
};

struct Image {
    std::string name;
    Vec2 pos;
    uint32_t w, h;
    float scale = 1;
    friend std::istream& operator>> (std::istream& is, Image& i) {
        return is >> i.name >> i.pos >> i.w >> i.h >> i.scale;
    }

    bool IsTouched(Vec2 p) {
        float dWidth = w * scale / 2;
        float dHeight = h * scale / 2;
        float wDelta = std::fabs(p.x - pos.x);
        float hDelta = std::fabs(p.y - pos.y);

        if (wDelta <= dWidth && hDelta <= dHeight)
        return true;
        return false;
    }
};

int main() {
    int N, Q, error = 0;
    std::vector<Image> imgs;
    std::vector<Vec2> clics;
    std::cin >> N;
    imgs.resize(N);

    for (int i = 0; i < N; i++) {
        std::cin >> imgs[i];
    }

    std::cin >> Q;
    clics.resize(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> clics[i];
    }

    std::vector<std::string> rebour(Q, "AUCUN"), endroit(Q, "AUCUN");
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < N; j++) {
            if (imgs[j].IsTouched(clics[i])) {
                endroit[i] = imgs[j].name;
                clics[i].touched = true;
                break;
            }
        }

    }

    for (int i = 0; i < Q; i++) {
        for (int j = N - 1; j >= 0; --j) {
            if (imgs[j].IsTouched(clics[i])) {
                rebour[i] = imgs[j].name;
                clics[i].touched = true;
                break;
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        std::cout << "CLIC " << i + 1 << " " << rebour[i] << " " << endroit[i] << std::endl;
        if (rebour[i] != endroit[i]) error++;
    }

    std::cout << "ERREURS " << error << std::endl;

    return 0;
}