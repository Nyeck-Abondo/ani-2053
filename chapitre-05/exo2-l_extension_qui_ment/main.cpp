#include <iostream>
#include <vector>
#include <string>
#include <sstream>

enum Format {
    PNG,
    JPEG,
    BMP,
    QOI,
    GIF,
    ICO,
    HDR,
    EXR,
    PBM,
    PGM,
    PPM,
    TGA,
    SVG,
    NONE
};

enum FileState {
    ACCEPTED,
    REFUSED,
    LIE,
    UNKNOW
};

struct File {
    std::string name = "";
    std::string octets = "";
    std::string extention ="";
    Format fr = Format::NONE;
    Format frExt = Format::NONE;
    FileState state = FileState::UNKNOW;
    std::string b[8] = {};
    int taille = 0;

    friend std::istream& operator>> (std::istream& is, File& f) {
        return is >> f.name >> f.taille >> f.octets;
    }

    friend std::ostream& operator<< (std::ostream& os, File& f) {
        std::string r = "";
        switch (f.state) {
            case FileState::ACCEPTED :
                r = " OK";
                break;
            case FileState::LIE :
                r = " MENT";
                break;
            case FileState::REFUSED :
                r = " REFUSE";
            default:
                break;
        }
        return os << f.name << " " << f.FormatToString() << r << std::endl;
    }

    void InitialiseFile() {
        if (octets[0] == '-')
            return;
        b[0] = octets.substr(0, 2);
        b[1] = octets.substr(2, 2);
        b[2] = octets.substr(4, 2);
        b[3] = octets.substr(6, 2);
        b[4] = octets.substr(8, 2);
        b[5] = octets.substr(10, 2);
        b[6] = octets.substr(12, 2);
    }

    void FindExtension() {
        if (name.empty())
            return;
        int counter = 0;
        for (size_t i = 0; i < name.size(); i++) {
            if (name[i] == '.') {
                counter = i;
            }
        }
        for (int i = counter + 1; i < name.size(); i++)
            extention += name[i];
    }

    void ExtensionToFormat() {
        if (extention == "png")
            frExt = Format::PNG;
        else if (extention == "jpg" || extention == "jpeg")
            frExt = Format::JPEG;
        else if (extention == "bmp")
            frExt = Format::BMP;
        else if (extention == "qoi")
            frExt = Format::QOI;
        else if (extention == "gif")
            frExt = Format::GIF;
        else if (extention == "ico" || extention == "cur")
            frExt = Format::ICO;
        else if (extention == "hdr")
            frExt = Format::HDR;
        else if (extention == "exr")
            frExt = Format::EXR;
        else if (extention == "pbm")
            frExt = Format::PBM;
        else if (extention == "pgm")
            frExt = Format::PGM;
        else if (extention == "ppm")
            frExt = Format::PPM;
        else if (extention == "tga")
            frExt = Format::TGA;
        else if (extention == "svg")
            frExt = Format::SVG;
        else {
            frExt = Format::NONE;
            state = FileState::REFUSED;
        }
    }

    std::string FormatToString() {
        switch (fr) {
            case Format::PNG:
                return "PNG";
                break;

            case Format::JPEG:
                return "JPEG";
                break;

            case Format::BMP:
                return "BMP";
                break;

            case Format::QOI:
                return "QOI";
                break;

            case Format::GIF:
                return "GIF";
                break;

            case Format::ICO:
                return "ICO";
                break;

            case Format::HDR:
                return "HDR";
                break;

            case Format::EXR:
                return "EXR";
                break;

            case Format::PBM:
                return "PBM";
                break;

            case Format::PGM:
                return "PGM";
                break;

            case Format::PPM:
                return "PPM";
                break;

            case Format::TGA:
                return "TGA";
                break;

            case Format::SVG:
                return "SVG";
                break;

            case Format::NONE:
                return "";
                break;

            default:
                break;
        }
        return "UNKNOWN";
    }

    void OctetsToFormat() {
        if (octets[0] == '-') {
            fr = Format::NONE;
            state = FileState::REFUSED;
            return;
        }
            
        if (taille < 4) {
            fr = Format::NONE;
            state = FileState::REFUSED;
            return;
        }
        else if (taille >= 8 && b[0] == "89" && b[1] == "50" && b[2] == "4E" && b[3] == "47") {
            fr = Format::PNG;
            state = FileState::ACCEPTED;
        }
        else if (b[0] == "FF" && b[1] == "D8" && b[2] == "FF") {
            fr = Format::JPEG;
            state = FileState::ACCEPTED;
        }
        else if (b[0] == "42" && b[1] == "4D") {
            fr = Format::BMP;
            state = FileState::ACCEPTED;
        }
        else if (b[0] == "71" && b[1] == "6F" && b[2] == "69" && b[3] == "66") {
            fr = Format::QOI;
            state = FileState::ACCEPTED;
        }
        else if (b[0] == "47" && b[1] == "49" && b[2] == "46" && b[3] == "38") {
            fr = Format::GIF;
            state = FileState::ACCEPTED;
        }
        else if (b[0] == "00" && b[1] == "00" && (b[2] == "01" || b[2] == "02") && b[3] == "00") {
            fr = Format::ICO;
            state = FileState::ACCEPTED;
        }
        else if (taille >= 10 && b[0] == "23" && b[1] == "3F") {
            fr = Format::HDR;
            state = FileState::ACCEPTED;
        }
        else if (b[0] == "76" && b[1] == "2F" && b[2] == "31" && b[3] == "01") {
            fr = Format::EXR;
            state = FileState::ACCEPTED;
        }
        else if (b[0] == "50" && (b[1] == "31" || b[1] == "34")) {
            fr = Format::PBM;
            state = FileState::ACCEPTED;
        }
        else if (b[0] == "50" && (b[1] == "32" || b[1] == "35")) {
            fr = Format::PGM;
            state = FileState::ACCEPTED;
        }
        else if (b[0] == "50" && (b[1] == "33" || b[1] == "36")) {
            fr = Format::PPM;
            state = FileState::ACCEPTED;
        }
        else if (b[0] == "EF" && b[1] == "BB" && b[2] == "BF") {
            if (taille >= 7 && b[3] == "20" && b[4] == "09" && b[5] == "0A" && b[6] == "0F") {
                fr = Format::SVG;
                state = FileState::ACCEPTED;
            }
            else {
                fr = Format::NONE;
                state = FileState::REFUSED;
            }
        }
        else if (b[0] == "3C" && b[1] == "3F" && b[2] == "78" && b[3] == "6D" && b[4] == "6C") {
            fr = Format::SVG;
            state = FileState::ACCEPTED;
        }
        else {
            fr = Format::NONE;
            state = FileState::REFUSED;
        }
    }

    bool IsLiying() {
        if (octets[0] == '-')
            return false;
        if (frExt != fr) {
            state = FileState::LIE;
            return true;
        }
        return false;
    }

};

int main() {
    int n = 0;
    int LU = 0, MENSONGES = 0, REFUSE = 0;
    std::string content = "";
    std::vector<File> allFile;

    std::cin >> n;
    allFile.resize(n);
    std::cin.ignore();

    for (int i = 0; i < n; i++) {
        std::getline(std::cin, content);
        std::istringstream iss(content);
        iss >> allFile[i];
        allFile[i].InitialiseFile();
        allFile[i].FindExtension();
        allFile[i].ExtensionToFormat();
        allFile[i].OctetsToFormat();
        if(allFile[i].IsLiying()) {
            LU++;
            MENSONGES++;
        }
        else if (allFile[i].state == FileState::ACCEPTED)
            LU++;
        else if (allFile[i].state == FileState::REFUSED)
            REFUSE++;
    }

    for (int i = 0; i < n; i++) {
        std::cout << allFile[i];
    }
    std::cout << "LUS " << LU << "\n";
    std::cout << "MENSONGES " << MENSONGES << "\n";
    std::cout << "REFUSES " << REFUSE << std::endl;

    return 0;
}