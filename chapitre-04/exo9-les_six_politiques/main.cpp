#include <iostream>
#include <sstream>
#include <string>

int Arrondi(int a, int b) {
    return (2 * a + b) / (2 * b);
}

int main() {
    int RW = 0, RH = 0, AW = 0, AH = 0, W = 0, H = 0;
    std::cin >> RW >> RH >> AW >> AH >> W >> H;
    int vx = 0, vy = 0, vw = 0, vh = 0, mw = 0, mh = 0;
    int bandes = 0;
    bool deformation = false;
    
    std::cout << "FOLLOW_WINDOW " << vx << " " << vy << " " << W << " " << H << " " << W << " " << H << "\n";

    if (RW != 0 || RH != 0) {
        std::cout << "STRETCH " << vx << " " << vy << " " << W << " " << H << " " << RW << " " << RH << "\n";
        if (W * RH <= H * RW) {
            vw = W;
            vh = Arrondi(RH * W, RW);
        } else {
            vh = H;
            vw = Arrondi(RW * H, RH);
        }
        vx = (W - vw) / 2;
        vy = (H - vh) / 2;
        std::cout << "FIT_LETTERBOX " << vx << " " << vy << " " << vw << " " << vh << " " << RW << " " << RH << "\n";

        if (vw < W || vh < H) {
            bandes++;
        }

        if (W >= RW && H >= RH) {
            int k = W / RW > H / RH ? Arrondi(H, RH) : Arrondi(W, RW);
            vw = RW * k;
            vh = RH * k;
        } else {
            if (W * RH <= H * RW) {
                vw = W;
                vh = Arrondi(RH * W, RW);
            } else {
                vh = H;
                vw = Arrondi(RW * H, RH);
            }
            vx = (W - vw) / 2;
            vy = (H - vh) / 2;
        }
        std::cout << "INTEGER_SCALE " << vx << " " << vy << " " << vw << " " << vh << " " << RW << " " << RH << "\n";
        if (vw < W || vh < H) {
            bandes++;
        }
        if (W * RH > H * RW) {
            mw = RW;
            mh = Arrondi(RW * H, W);
        } else {
            mw = Arrondi(RH * W, H);
            mh = RH;
        }
        std::cout << "FIT_CROP " << 0 << " " << 0 << " " << W << " " << H << " " << mw << " " << mh << "\n";

        if (W * RH != H * RW) {
            deformation = true;
        }
    }
    else {
        std::cout << "STRETCH " << vx << " " << vy << " " << W << " " << H << " " << W << " " << H << "\n";
        std::cout << "FIT_LETTERBOX " << vx << " " << vy << " " << W << " " << H << " " << W << " " << H << "\n";
        std::cout << "INTEGER_SCALE  " << vx << " " << vy << " " << W << " " << H << " " << W << " " << H << "\n";
        std::cout << "FIT_CROP  " << vx << " " << vy << " " << W << " " << H << " " << W << " " << H << "\n";
    }
    
    std::cout << "MANUAL " << 0 << " " << 0 << " " << AW << " " << AH << " " << AW << " " << AH << "\n";
    if (AW < W || AH < H) {
        bandes++;
    }

    std::cout << "BANDES " << bandes << "\n";
    if (deformation) {
        std::cout << "DEFORMATION OUI\n";
    } else {
        std::cout << "DEFORMATION NON\n";
    }
    return 0;
}