#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdint>

enum FormatType {
    GRAY8,
    GRAY_A16,
    RGB24,
    RGBA32,
    RGB96F,
    RGBA128F,
    UNKNOW
};

struct Format {
    FormatType ftype = FormatType::UNKNOW;
    bool color = false;
    bool opacity = false;
    bool floats = false;

    void UpdateCaracteristics() {
        switch (ftype) {
            case FormatType::GRAY8 :
                color = false;
                opacity = false;
                floats = false;
                break;

            case FormatType::GRAY_A16 :
                color = false;
                opacity = true;
                floats = false;
                break;

            case FormatType::RGB24 :
                color = true;
                opacity = false;
                floats = false;
                break;

            case FormatType::RGBA32 :
                color = true;
                opacity = true;
                floats = false;
                break;

            case FormatType::RGB96F :
                color = true;
                opacity = false;
                floats = true;
                break;

            case FormatType::RGBA128F :
                color = true;
                opacity = true;
                floats = true;
                break;

            default:
                color = false;
                opacity = false;
                floats = false;
                break;
        }
    }

    int BytesPP() {
        switch (ftype) {
            case FormatType::GRAY8 :
                return 1;
                break;
            case FormatType::GRAY_A16 :
                return 2;
                break;
            case FormatType::RGB24 :
                return 3;
                break;
            case FormatType::RGB96F :
                return 12;
                break;
            case FormatType::RGBA128F :
                return 16;
                break;
            case FormatType::RGBA32 :
                return 4;
                break;
            case FormatType::UNKNOW :
                return 0;
                break;
        }
        return 0;
    }
};


struct Image {
    std::string source = "";
    std::string target = "";
    int w = 1, h = 1;
    Format fr;
    Format targetFr;

    bool loseColor = false;
    bool loseOpacity = false;
    bool loseFloats = false;

    friend std::istream& operator>> (std::istream& is, Image& i) {
        return is >> i.source >> i.target;
    }

    friend std::ostream& operator<< (std::ostream& os, Image& i) {
        std::string result = "";
        if (i.loseOpacity)
            result += " TRANSPARENCE";
        if (i.loseColor) {
            if (!result.empty())
                result += "+";
            result += "COULEUR";
        }
        if (i.loseFloats) {
            if (!result.empty())
                result += "+";
            result += "ETENDU";
        }
        if (result.empty())
            result = "AUCUNE";

        return (i.targetFr.ftype != FormatType::UNKNOW) ? os << i.source << " " << i.target << " " << i.SizeOfImageWithSource() << " " << i.SizeOfImageWithTarget() << " " << result << std::endl :
                     os << i.source << " " << i.target << " REFUSE" << std::endl;
    }

    FormatType StringToType(const std::string& s) {
        if (s == "GRAY8")
            return FormatType::GRAY8;
        else if (s == "GRAY_A16")
            return FormatType::GRAY_A16;
        else if (s == "RGB24")
            return FormatType::RGB24;
        else if (s == "RGBA32")
            return FormatType::RGBA32;
        else if (s == "RGB96F")
            return FormatType::RGB96F;
        else if (s == "RGBA128F")
            return FormatType::RGBA128F;
        return FormatType::UNKNOW;
    }

    void StringToFormat() {
        fr.ftype = StringToType(source);
        targetFr.ftype = StringToType(target);
    }

    uint64_t SizeOfImageWithSource() {
        if (fr.ftype == FormatType::UNKNOW)
            return 0;
        return w * h * fr.BytesPP();
    }

    uint64_t SizeOfImageWithTarget() {
        if (targetFr.ftype == FormatType::UNKNOW)
            return 0;
        return w * h * targetFr.BytesPP();
    }

    void EvaluateCaracteristics() {
        fr.UpdateCaracteristics();
        targetFr.UpdateCaracteristics();

        if (fr.opacity && !targetFr.opacity)
            loseOpacity = true;
        if (fr.color && !targetFr.color)
            loseColor = true;
        if (fr.floats && !targetFr.floats)
            loseFloats = true;
    }
};

int main() {
    int n = 0;
    int w = 1, h = 1;
    int TOTAL = 0, SANSPERTE = 0, REFUSE = 0;
    std::string content;
    std::vector<Image> allimg;

    std::cin >> w >> h;
    std::cin >> n;
    allimg.resize(n);
    std::cin.ignore();

    for (int i = 0; i < n; i++) {
        std::getline(std::cin, content);
        std::istringstream iss(content);
        iss >> allimg[i];
        allimg[i].StringToFormat();
        allimg[i].EvaluateCaracteristics();
        allimg[i].w = w;
        allimg[i].h = h;

        if (allimg[i].targetFr.ftype == FormatType::UNKNOW)
            REFUSE++;
        if (!allimg[i].loseColor && !allimg[i].loseOpacity && !allimg[i].loseFloats)
            SANSPERTE++;
    }

    for (int i = 0; i < n; i++) {
        std::cout << allimg[i];
        TOTAL += allimg[i].SizeOfImageWithTarget();
    }

    std::cout << "TOTAL " << TOTAL << "\n";
    std::cout << "SANS_PERTE " << SANSPERTE << "\n";
    std::cout << "REFUSE " << REFUSE << "\n";
    return 0;
}