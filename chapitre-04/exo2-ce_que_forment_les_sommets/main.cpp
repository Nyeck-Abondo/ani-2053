#include <iostream>
#include <string>
#include <vector>
#include <sstream>

enum ShapeTypes {
    NOTEXIST,
    TRIANGLES,
    LINE_STRIP,
    TRIANGLE_FAN,
    TRIANGLE_STRIP,
    LINES,
    COUNT
};

enum UnitTypes {
    NONE,
    TRIANGLE,
    SEGMENTS,
    POINTS
};

struct Response {
    std::string types = "";
    ShapeTypes sType = ShapeTypes::NOTEXIST;
    UnitTypes uType = UnitTypes::NONE;
    int sommets = 0;
    int unit = 0;
    int rest = 0;

    //Bilan
    int segments = 0;
    int points = 0;
    int triangles = 0;
    int refuse = 0;

    friend std::istream& operator>> (std::istream& is, Response& r) {
        is >> r.types >> r.sommets;
        return is;
    }
    friend std::ostream& operator<< (std::ostream& os, Response& r) {
        if (r.sType == ShapeTypes::NOTEXIST)
            os << r.types << " " << r.sommets << " " << r.UnitToString()<< std::endl;
        else
            os << r.types << " " << r.sommets << " " << r.unit << " " << r.UnitToString()
            << " " << r.rest << std::endl;
        return os;
    }
    void StringToShapeType() {
        if (types == "TRIANGLES")
            sType = ShapeTypes::TRIANGLES;
        else if (types == "LINE_STRIP")
            sType = ShapeTypes::LINE_STRIP;
        else if (types == "TRIANGLE_FAN")
            sType = ShapeTypes::TRIANGLE_FAN;
        else if (types == "TRIANGLE_STRIP")
            sType = ShapeTypes::TRIANGLE_STRIP;
        else if (types == "LINES")
            sType = ShapeTypes::LINES;
        else sType = ShapeTypes::NOTEXIST;
    }

    bool CanDraw() {
        if (sommets <= 0)
            return false;
        return true;
    }

    std::string UnitToString() {
        switch (uType) {
        case UnitTypes::SEGMENTS :
            return "SEGMENTS";
            break;
        case UnitTypes::TRIANGLE :
            return "TRIANGLES";
            break;
        case UnitTypes::POINTS :
            return "POINTS";
            break;
        case UnitTypes::NONE :
            return "REFUSE";
            break;
        }
    }

    void AssignUnit() {
        switch (sType) {
            case ShapeTypes::LINE_STRIP :
                if (CanDraw()) {
                    if (sommets >= 3)
                        unit = sommets - 1;
                    else {
                        unit = 0;
                        rest = sommets;
                    }
                    segments = unit;
                }
                
                break;

            case ShapeTypes::LINES :
                if (CanDraw()) {
                    unit = sommets / 2;
                    rest = sommets % 2;
                    segments = unit;    
                }
                
                break;
            case ShapeTypes::TRIANGLE_FAN :
                if (CanDraw()) {
                    if (sommets >= 3)
                        unit = sommets - 2;
                    else {
                        unit = 0;
                        rest = sommets;
                    }
                    triangles = unit;    
                }
                
                break;
            case ShapeTypes::TRIANGLE_STRIP :
                if (CanDraw()) {
                    if (sommets >= 3)
                        unit = sommets - 2;
                    else {
                        unit = 0;
                        rest = sommets;
                    }
                    triangles = unit;    
                }
                
                break;
            case ShapeTypes::TRIANGLES :
                if (CanDraw()) {
                    unit = sommets / 3;
                    rest = sommets % 3;
                    triangles = unit;
                }
                
                break;
            case ShapeTypes::NOTEXIST:
                refuse = 1;
                break;
            case ShapeTypes::COUNT :
                break;
        }
    }

    void DefineUnit() {
        switch (sType) {
            case ShapeTypes::LINE_STRIP :
                uType = UnitTypes::SEGMENTS;
                break;
            case ShapeTypes::LINES :
                uType = UnitTypes::SEGMENTS;
                break;
            case ShapeTypes::TRIANGLE_FAN :
                uType = UnitTypes::TRIANGLE;
                break;
            case ShapeTypes::TRIANGLE_STRIP :
                uType = UnitTypes::TRIANGLE;
                break;
            case ShapeTypes::TRIANGLES :
                uType = UnitTypes::TRIANGLE;
                break;
            case ShapeTypes::NOTEXIST :
                uType = UnitTypes::NONE;
            case ShapeTypes::COUNT :
                break;
        }
    }

};

int main() {
    std::vector<Response> allResponses;
    std::string content;
    int lines;
    int totalPoint = 0;
    int totalTriangle = 0;
    int totalSegments = 0;
    int totalRefused = 0;

    std::cin >> lines;
    std::cin.ignore();
    allResponses.resize(lines);
    for (int i = 0; i < lines; i++) {
        std::getline(std::cin, content);
        if (content.empty()) {
            allResponses[i].segments = 0;
            allResponses[i].points = 0;
            allResponses[i].triangles = 0;
            continue;
        }
        else {
            std::istringstream iss(content);
            iss >> allResponses[i].types >> allResponses[i].sommets;
            allResponses[i].StringToShapeType();
            allResponses[i].DefineUnit();
            allResponses[i].AssignUnit();
            totalPoint += allResponses[i].points;
            totalTriangle += allResponses[i].triangles;
            totalSegments += allResponses[i].segments;
            totalRefused += allResponses[i].refuse;
        }
    }
    for (auto& r : allResponses) {
        std::cout << r;
    }
    std::cout << "POINTS " << totalPoint << "\n"
                << "SEGMENTS " << totalSegments << "\n"
                << "TRIANGLES " << totalTriangle << "\n"
                << "REFUSES " << totalRefused << "\n";

    return 0;
}
