#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>

#define M_PI		3.14159265358979323846

enum RectState {
    NONE,
    ACCEPTED,
    REFUSED
};

struct Vect2 {
    int x = 0, y = 0;
    friend std::istream& operator>> (std::istream& is, Vect2& v) {
        return is >> v.x >> v.y;
    }
    friend std::ostream& operator<< (std::ostream& os, Vect2& v) {
        return os << v.x << " " << v.y;
    }
};

struct Angle {
    int c;
    int s;
    int val = 35000;
    friend std::istream& operator>> (std::istream& is, Angle& a) {
        return is >> a.val;
    }
};

struct Rect {
    std::string nom;
    RectState state = RectState::NONE;
    Vect2 p, o , size, s;
    Angle angle;

    friend std::ostream& operator<<(std::ostream& os, Rect& r) {
        Vect2 p00 = r.FindEdge({0, 0});
        Vect2 p01 = r.FindEdge({0, r.size.y});
        Vect2 p10 = r.FindEdge({r.size.x, 0});
        Vect2 p11 = r.FindEdge({r.size.x, r.size.y});
        Vect2 arry[4] = {p00, p01, p10, p11};
        int minx = arry[0].x, maxx = 0;
        int miny = arry[0].x, maxy = 0;
        
        for (int i = 0; i < 4; i++) {
            if (arry[i].x > maxx)
                maxx = arry[i].x;
            if (arry[i].x < minx)
                minx = arry[i].x;
            if (arry[i].y > maxy)
                maxy = arry[i].y;
            if (arry[i].y < miny)
                miny = arry[i].y;
        }

        return (r.state == RectState::ACCEPTED) ? os << r.nom << " COINS " << p00 << " " << p10 << " " << p11 << " " << p01 << std::endl
                << r.nom << " BOITE " << minx << " "  << miny << " " << maxx << " " << maxy << std::endl : os << r.nom << " ANGLE " << " REFUSE " << std::endl;
    }

    friend std::istream& operator>>(std::istream& is, Rect& r) {
        return is >> r.nom >> r.size >> r.p >> r.o >> r.s >> r.angle;
    }

    Vect2 FindEdge(Vect2 pos) {
        Vect2 result{};
        //calcul du coin local
        Vect2 a = {(pos.x - o.x) * s.x, (pos.y - o.y) * s.y};
        //rotation
        if (angle.val % 90 != 0 || angle.val == 35000) {
            state = RectState::REFUSED;
        } else {
            state = RectState::ACCEPTED;
            if (angle.val > 0)
                angle.val = angle.val % 360;
            else
                angle.val = angle.val % 360 * -1 + 180;
            if (angle.val == 0 || angle.val == 360) {
                    angle.c = 1;
                    angle.s = 0;
            }
            else if (angle.val == 180) {
                angle.c = -1;
                angle.s = 0;
            }
            if (angle.val == 90) {
                angle.c = 0;
                angle.s = 1;
            }
            if (angle.val == 270) {
                angle.c = 0;
                angle.s = -1;
            }
        }
            
        Vect2 r = {a.x * angle.c - a.y * angle.s, a.x * angle.s + a.y * angle.c};
        result = {p.x + r.x, p.y + r.y};
        //position et le coin dans le monde
        return result;
    }
};

int main() {
    int n = 0;
    int refuse = 0;
    std::vector<Rect> allRects;
    std::string content = "";

    std::cin >> n;
    allRects.resize(n);
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, content);
        std::istringstream iss(content);
        iss >> allRects[i];
    }
    for (int i = 0; i < n; i++) {
        std::cout << allRects[i];
        if (allRects[i].state == RectState::REFUSED)
            refuse += 1;
    }
    std::cout << "REFUSES " << refuse << std::endl;
    return 0;
}