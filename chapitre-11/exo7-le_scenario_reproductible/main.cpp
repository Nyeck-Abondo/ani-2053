#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool entier(const std::string& s, long long& v) {
    size_t i = 0;
    if (!s.empty() && (s[0] == '-' || s[0] == '+')) i = 1;
    if (i == s.size()) return false;
    for (size_t k = i; k < s.size(); k++)
        if (s[k] < '0' || s[k] > '9') return false;
    try { v = std::stoll(s); } catch (...) { return false; }
    return true;
}

void decoupe(const std::string& s, char sep, std::vector<std::string>& out) {
    out.clear();
    size_t debut = 0, pos;
    while ((pos = s.find(sep, debut)) != std::string::npos) {
        out.push_back(s.substr(debut, pos - debut));
        debut = pos + 1;
    }
    out.push_back(s.substr(debut));
}

int main() {
    std::string line;
    std::vector<std::string> champs, elems;
    int ignores = 0, gardes = 0, joues = 0;
    long long n = 0;

    bool hasPan = false, hasZoom = false, hasMove = false;
    bool hasPack = false, hasGrid = false, hasExit = false;
    long long panN = 0, zoomN = 0, moveN = 0, packN = 0, gridN = 0, exitN = 0;
    std::string panDx, panDy, zoomF, zoomPx, zoomPy, moveDx, moveDy, gridV;
    std::vector<long long> shots, dropN, clickN;
    std::vector<std::string> dropPx, dropPy, dropPath, clickPx, clickPy;

    // lecture des entrees
    while (std::getline(std::cin, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        size_t eg = line.find('=');
        if (eg == std::string::npos) continue;
        std::string nom = line.substr(0, eg);
        std::string val = line.substr(eg + 1);

        if (nom == "NK_AGENT_EXIT") {
            if (entier(val, n)) { hasExit = true; exitN = n; }
            else ignores++;
        }
        else if (nom == "NK_AGENT_PACK") {
            if (entier(val, n)) { hasPack = true; packN = n; gardes++; }
            else ignores++;
        }
        else if (nom == "NK_AGENT_PAN") {
            decoupe(val, ':', champs);
            if (champs.size() >= 3 && entier(champs[0], n)) {
                hasPan = true; panN = n; panDx = champs[1]; panDy = champs[2]; gardes++;
            } else ignores++;
        }
        else if (nom == "NK_AGENT_ZOOM") {
            decoupe(val, ':', champs);
            if (champs.size() >= 4 && entier(champs[0], n)) {
                hasZoom = true; zoomN = n;
                zoomF = champs[1]; zoomPx = champs[2]; zoomPy = champs[3]; gardes++;
            } else ignores++;
        }
        else if (nom == "NK_AGENT_MOVE") {
            decoupe(val, ':', champs);
            if (champs.size() >= 3 && entier(champs[0], n)) {
                hasMove = true; moveN = n; moveDx = champs[1]; moveDy = champs[2]; gardes++;
            } else ignores++;
        }
        else if (nom == "NK_AGENT_GRID") {
            decoupe(val, ':', champs);
            if (champs.size() >= 2 && entier(champs[0], n)) {
                hasGrid = true; gridN = n; gridV = champs[1]; gardes++;
            } else ignores++;
        }
        else if (nom == "NK_AGENT_SHOT") {
            decoupe(val, ',', elems);
            for (size_t i = 0; i < elems.size(); i++) {
                if (entier(elems[i], n) && shots.size() < 8) {
                    shots.push_back(n); gardes++;
                } else ignores++;
            }
        }
        else if (nom == "NK_AGENT_CLICK") {
            decoupe(val, ';', elems);
            for (size_t i = 0; i < elems.size(); i++) {
                decoupe(elems[i], ':', champs);
                if (champs.size() >= 3 && entier(champs[0], n) && clickN.size() < 8) {
                    clickN.push_back(n); clickPx.push_back(champs[1]); clickPy.push_back(champs[2]);
                    gardes++;
                } else ignores++;
            }
        }
        else if (nom == "NK_AGENT_DROP") {
            decoupe(val, ';', elems);
            for (size_t i = 0; i < elems.size(); i++) {
                decoupe(elems[i], ':', champs);
                if (champs.size() >= 4 && entier(champs[0], n) && dropN.size() < 8) {
                    std::string chemin = champs[3];
                    for (size_t k = 4; k < champs.size(); k++)
                        chemin += ":" + champs[k];
                    dropN.push_back(n); dropPx.push_back(champs[1]); dropPy.push_back(champs[2]);
                    dropPath.push_back(chemin);
                    gardes++;
                } else ignores++;
            }
        }
    }

    // tours ou il se passe quelque chose
    bool limite = hasExit && exitN > 0;
    long long dernier = exitN - 1;
    std::vector<long long> tours;
    if (hasPan  && panN  > 0 && (!limite || panN  <= dernier)) tours.push_back(panN);
    if (hasZoom && zoomN > 0 && (!limite || zoomN <= dernier)) tours.push_back(zoomN);
    if (hasMove && moveN > 0 && (!limite || moveN <= dernier)) tours.push_back(moveN);
    if (hasPack && packN > 0 && (!limite || packN <= dernier)) tours.push_back(packN);
    if (hasGrid && gridN > 0 && (!limite || gridN <= dernier)) tours.push_back(gridN);
    for (size_t i = 0; i < dropN.size(); i++)
        if (dropN[i] > 0 && (!limite || dropN[i] <= dernier)) tours.push_back(dropN[i]);
    for (size_t i = 0; i < clickN.size(); i++)
        if (clickN[i] > 0 && (!limite || clickN[i] <= dernier)) tours.push_back(clickN[i]);
    for (size_t i = 0; i < shots.size(); i++)
        if (shots[i] >= 1 && (!limite || shots[i] - 1 <= dernier)) tours.push_back(shots[i] - 1);

    std::sort(tours.begin(), tours.end());
    tours.erase(std::unique(tours.begin(), tours.end()), tours.end());

    // deroulement
    for (size_t j = 0; j < tours.size(); j++) {
        long long t = tours[j];
        if (t > 0) {
            if (hasPan && panN == t) {
                std::cout << "TOUR " << t << " PAN " << panDx << " " << panDy << "\n"; joues++;
            }
            if (hasZoom && zoomN == t) {
                std::cout << "TOUR " << t << " ZOOM " << zoomF << " " << zoomPx << " " << zoomPy << "\n"; joues++;
            }
            for (size_t i = 0; i < dropN.size(); i++)
                if (dropN[i] == t) {
                    std::cout << "TOUR " << t << " DEPOT " << dropPath[i] << " "
                              << dropPx[i] << " " << dropPy[i] << "\n"; joues++;
                }
            for (size_t i = 0; i < clickN.size(); i++)
                if (clickN[i] == t) {
                    std::cout << "TOUR " << t << " CLIC " << clickPx[i] << " " << clickPy[i] << "\n"; joues++;
                }
            if (hasMove && moveN == t) {
                std::cout << "TOUR " << t << " MOVE " << moveDx << " " << moveDy << "\n"; joues++;
            }
            if (hasPack && packN == t) {
                std::cout << "TOUR " << t << " RANGE\n"; joues++;
            }
            if (hasGrid && gridN == t) {
                std::cout << "TOUR " << t << " GRILLE " << gridV << "\n"; joues++;
            }
        }
        
        for (size_t i = 0; i < shots.size(); i++)
            if (shots[i] == t + 1) {
                std::cout << "TOUR " << t << " CAPTURE\n"; joues++;
            }
    }

    if (limite) std::cout << "ARRET " << dernier << "\n";
    else        std::cout << "SANS_ARRET\n";
    std::cout << "JAMAIS " << gardes - joues << "\n";
    std::cout << "IGNORES " << ignores << "\n";
    return 0;
}