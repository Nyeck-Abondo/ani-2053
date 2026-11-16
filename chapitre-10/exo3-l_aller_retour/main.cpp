#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <string>
#include <sstream>
#include <iomanip>

struct Vec2 {
    double x, y;
    friend std::ostream& operator<<(std::ostream& os, Vec2& c) {
        if (c.x > -0.005 && c.x < 0.005) c.x = 0.0;   // évite "-0.00"
        if (c.y > -0.005 && c.y < 0.005) c.y = 0.0;
        return os << c.x << " " << c.y <<std::endl;
    }
};

struct Commands {
    std::string name;
    double x, y, m, f;
    friend std::istream& operator>>(std::istream& is, Commands& c) {
        is >> c.name;
        if (c.name == "ZOOM") {
            is >> c.f;
        }
        else if (c.name == "ORIGINE") {
            return is;
        }
        else if (c.name == "GRILLE") {
            return is >> c.m;
        }
        is >> c.x >> c.y;
        return is;
    }
};

int main() {
    int w, h;
    double z = 1.0, s = 1.0;
    Vec2 center {0, 0};
    std::vector<Commands> cmds;
    std::cin >> w >> h;

    std::string line;
    std::cin.ignore();

    while (std::getline(std::cin, line)) {
        std::istringstream is(line);
        Commands c;
        is >> c;
        cmds.push_back(c);
    }

    for (auto c : cmds) {
        if (c.name == "VERS_MONDE") {
            Vec2 pos;
            pos.x = center.x + (c.x - w / 2.0) / z;
            pos.y = center.y + (c.y - h / 2.0) / z;
            std::cout << "MONDE " << std::fixed << std::setprecision(2) << pos;
        }
        else if (c.name == "VERS_PIXEL") {
            Vec2 pos;
            pos.x = (c.x - center.x) * z + w / 2.0;
            pos.y = (c.y - center.y) * z + h / 2.0;
            std::cout << "PIXEL " << std::fixed << std::setprecision(2) << pos;
        }
        else if (c.name == "ZOOM") {
            Vec2 pos;
            pos.x = center.x + (c.x - w / 2.0) / z;
            pos.y = center.y + (c.y - h / 2.0) / z;
            z *= c.f;
            if (z < 0.02)
            z = 0.02;
            if (z > 64)
            z = 64;
            center.x = pos.x - (c.x - w / 2.0) / z;
            center.y = pos.y - (c.y - h / 2.0) / z;
        }
        else if (c.name == "DEPLACE") {
            center.x = center.x - c.x / z;
            center.y = center.y - c.y / z;
        }
        else if (c.name == "GRILLE") {
            s = 1;
            while (s * z < c.m) {
                s *= 2.0;
            }
            while (s * 0.5 * z >= c.m) {
                s /= 2.0;
            }
            std::cout << "GRILLE " << std::fixed << std::setprecision(6) << s << std::endl;
        }
        else if (c.name == "ORIGINE") {
            center = {0.0, 0.0};
            z = 1;
        }

    }

    std::cout << "CENTRE " << std::setprecision(2) << center;
    std::cout << "ZOOM " << std::fixed << z << std::endl;

    return 0;
}