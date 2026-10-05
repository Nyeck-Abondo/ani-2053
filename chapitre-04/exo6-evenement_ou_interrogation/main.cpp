#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

enum EventTypes {
    NONE,
    SPACE_PRESSED,
    SPACE_RELEASE,
    RIGTH_PRESSED,
    RIGTH_RELEASE,
    LEFT_PRESSED,
    LEFT_RELEASE
};

struct Event {
    EventTypes type;
    bool spaceRelease = true;
    bool rightRelease = true;
    bool leftRelease = true;
};

struct FrameEvent {
    std::vector<std::string> strEvent;
    std::vector<Event> ev;
    int nbEvent = 0;

    bool spaceRelease = true;
    bool rightRelease = true;
    bool leftRelease = true;

    friend std::istream& operator>> (std::istream& is, FrameEvent& e) {
        is >> e.nbEvent;
        e.strEvent.resize(e.nbEvent);
        e.ev.resize(e.nbEvent);
        for (int i = 0; i < e.nbEvent; i++) {
            is >> e.strEvent[i] ;
        }
        return is;
    }

    void StringToEventType() {
        for (int i = 0; i < nbEvent; i++) {
            if (strEvent[i] == "+SPACE") {
                ev[i].type = EventTypes::SPACE_PRESSED;
                ev[i].spaceRelease = false;
            }
                
            else if (strEvent[i] == "-SPACE") {
                ev[i].type = EventTypes::SPACE_RELEASE;
                ev[i].spaceRelease = true;
            }
            else if (strEvent[i] == "+RIGHT") {
                ev[i].type = EventTypes::RIGTH_PRESSED;
                ev[i].rightRelease = false;
            }
            else if (strEvent[i] == "-RIGHT") {
                ev[i].type = EventTypes::RIGTH_RELEASE;
                ev[i].rightRelease = true;
            }
            else if (strEvent[i] == "+LEFT") {
                ev[i].type = EventTypes::LEFT_PRESSED;
                ev[i].leftRelease = false;
            }
            else if (strEvent[i] == "-LEFT") {
                ev[i].type = EventTypes::LEFT_RELEASE;
                ev[i].leftRelease = true;
            }
            else
                ev[i].type = EventTypes::NONE;
        }
    }

    int CountEventType(EventTypes tp) {
        int result = 0;
        for (auto& t : ev) {
            if (t.type == tp) {
                result++;
            }
        }
        return result; 
    }
};

struct Carre {
    std::vector<FrameEvent> fevent;
    std::vector<int> xe;
    std::vector<int> xi;
    int jump = 0;
    int jumpInter = 0;
    int v = 0;
    int manque = 0;

    friend std::istream& operator>> (std::istream& is, Carre& c) {
        return is >> c.v;
    }

    void UpdateFramePression() {
        for (int i = 0; i < fevent.size(); i++) {
            if (i == 0) {
                if (fevent[i].CountEventType(EventTypes::LEFT_PRESSED) > 0)
                    fevent[i].leftRelease = false;
                if (fevent[i].CountEventType(EventTypes::RIGTH_PRESSED) > 0)
                    fevent[i].rightRelease = false;
                if (fevent[i].CountEventType(EventTypes::SPACE_PRESSED) > 0)
                    fevent[i].spaceRelease = false;

                auto it = std::remove_if(fevent[i].ev.begin(), fevent[i].ev.end(),
                    [](const Event& e) {
                        return e.type == EventTypes::SPACE_RELEASE ||
                            e.type == EventTypes::LEFT_RELEASE ||
                            e.type == EventTypes::RIGTH_RELEASE;
                    });
                fevent[i].ev.erase(it, fevent[i].ev.end());

                if (fevent[i].CountEventType(EventTypes::SPACE_PRESSED) > 0 && fevent[i].CountEventType(EventTypes::SPACE_RELEASE) > 0)
                    manque += fevent[i].CountEventType(EventTypes::SPACE_PRESSED);
            }
            else {
                fevent[i].leftRelease = fevent[i - 1].leftRelease;
                fevent[i].rightRelease = fevent[i - 1].rightRelease;
                fevent[i].spaceRelease = fevent[i - 1].spaceRelease;

                if (fevent[i - 1].leftRelease == false && fevent[i].CountEventType(EventTypes::LEFT_RELEASE) > 0)
                    fevent[i].leftRelease = true;
                if (fevent[i - 1].rightRelease == false && fevent[i].CountEventType(EventTypes::RIGTH_RELEASE) > 0)
                    fevent[i].rightRelease = true;
                if (fevent[i - 1].spaceRelease == false && fevent[i].CountEventType(EventTypes::SPACE_RELEASE) > 0)
                    fevent[i].spaceRelease = true;
                
                if (fevent[i].CountEventType(EventTypes::SPACE_PRESSED) > 0 && fevent[i].CountEventType(EventTypes::SPACE_RELEASE) > 0)
                    manque += fevent[i].CountEventType(EventTypes::SPACE_PRESSED);
            }
        }
    }


    void UpdateByEvent() {
        xe.resize(fevent.size(), 0);
        for (int j = 0; j < fevent.size(); j++) {
            if (j > 0) xe[j] = xe[j - 1];
            for (int i = 0; i < fevent[j].nbEvent; i++) {
                switch (fevent[j].ev[i].type) {
                case EventTypes::SPACE_PRESSED :
                    jump++;
                    break;
                case EventTypes::SPACE_RELEASE:
                    break;
                case EventTypes::RIGTH_PRESSED :
                    xe[j] += v;
                    break;
                case EventTypes::RIGTH_RELEASE :
                    break;
                case EventTypes::LEFT_PRESSED :
                    xe[j] -= v;
                    break;
                case EventTypes::LEFT_RELEASE :
                    break;
                default:
                    break;
                }
            }
        }
    }

    void UpdateByInterrogation() {
        xi.resize(fevent.size(), 0);
        for (int j = 0; j < fevent.size(); j++) {
            if (j > 0) xi[j] = xi[j - 1];

            if (!fevent[j].leftRelease) xi[j] -= v;
            if (!fevent[j].rightRelease) xi[j] += v;
            if (!fevent[j].spaceRelease) jumpInter++;
        }
    }

    void UpdateLogic() {
        UpdateByEvent();
        UpdateByInterrogation();
    }
};


int main() {
    int n = 0;
    std::string content = "";
    Carre scare;

    std::getline(std::cin, content);
    std::istringstream iss(content);
    iss >> scare >> n;
    content = "";
    scare.fevent.resize(n);
    

    for (int i = 0; i < n; i++) {
        std::getline(std::cin, content);
        std::istringstream str(content);
        str >> scare.fevent[i];
        if (scare.fevent[i].nbEvent > 0)
            scare.fevent[i].StringToEventType();
    }

    scare.UpdateFramePression();
    scare.UpdateLogic();

    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << " " << scare.xe[i] << " " << scare.xi[i] << std::endl;
    }
    std::cout << "SAUTS EVENEMENTS " << scare.jump << std::endl;
    std::cout << "SAUTS INTERROGATION " << scare.jumpInter << std::endl;
    std::cout << "MANQUES " << scare.manque << std::endl;
    return 0;
}