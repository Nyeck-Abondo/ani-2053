#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>

const double pi = 3.141592653589793;

enum Visibility {
    NONE,
    VISIBLES,
    INVISIBLE
};

enum PolygonState {
    NO,
    ACCEPTED,
    REFUSES
};

enum GapState {
    DEFAULT,
    NEVER,
    POSSIBLE
};

struct Circle {
    double r;
    int n;
    double gap;
    double zoom;
    Visibility vis = Visibility::NONE;
    PolygonState ps = PolygonState::NO;
    GapState gs = GapState::DEFAULT;

    friend std::istream& operator>> (std::istream& is, Circle& c) {
        return is >> c.r >> c.n;
    }

    friend std::ostream& operator<< (std::ostream& os, Circle& c) {
        if (c.ps == PolygonState::REFUSES)
            return os << c.r << " " << c.n << " REFUSE\n";
        if (c.gs == GapState::NEVER)
            return os << c.r << " " << c.n << " " << c.gap << " JAMAIS\n";
        if (c.vis == Visibility::INVISIBLE)
            return os << c.r << " " << c.n << " " << c.gap << " " << c.zoom << " INVISIBLE\n";
        return os << c.r << " " << c.n << " " << c.gap << " " << c.zoom << " VISIBLE" << std::endl;
    }

    void UpdateCircle() {
        if (n < 3)
            ps = PolygonState::REFUSES;
        else {
            double g = r * (1 - cos(pi / n));
            gap = std::floor(1000 * g);
            if (g == 0) {
                gs = GapState::NEVER;
                zoom = 500;
            }
            else
                zoom = std::ceil(100 / g);
            if (zoom <= 100)
                vis = Visibility::VISIBLES;
            else
                vis = Visibility::INVISIBLE;
        }
    }
};

int main() {
    int visible = 0;
    int refuse = 0;
    int n = 0;
    std::vector<Circle> allCircle;
    std::string content;

    std::cin >> n;
    allCircle.resize(n);
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, content);
        std::istringstream iss(content);
        iss >> allCircle[i];
        allCircle[i].UpdateCircle();
    }
    for (int i = 0; i < n; i++) {
        std::cout << allCircle[i];
        if (allCircle[i].vis == Visibility::VISIBLES)
            visible += 1;
        if (allCircle[i].ps == PolygonState::REFUSES)
            refuse += 1;
    }
    std::cout << "VISIBLES " << visible << "\n";
    std::cout << "REFUSES " << refuse << std::endl;
    return 0;
}
