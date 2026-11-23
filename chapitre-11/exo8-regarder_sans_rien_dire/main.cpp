#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string mot;
    int n = 0, m = 0, horsSeance = 0;

    std::vector<std::string> noms;
    std::vector<int> fois;
    std::vector<int> premier;

    std::cin >> mot >> n;
    for (int i = 0; i < n; i++) {
        std::string temps, nom;
        std::cin >> temps >> nom;
        int sec = std::stoi(temps.substr(0, 2)) * 60 + std::stoi(temps.substr(3, 2));

        if (sec > 1200) {
            horsSeance++;
            continue;
        }

        int idx = -1;
        for (size_t k = 0; k < noms.size(); k++) {
            if (noms[k] == nom) { idx = (int)k; break; }
        }
        if (idx == -1) {
            noms.push_back(nom);
            fois.push_back(1);
            premier.push_back(sec);
        } else {
            fois[idx]++;
            if (sec < premier[idx]) premier[idx] = sec;
        }
    }

    std::vector<std::string> dits;
    std::cin >> mot >> m;
    for (int i = 0; i < m; i++) {
        std::string nom;
        std::cin >> nom;
        dits.push_back(nom);
    }

    std::vector<bool> estDit(noms.size(), false);
    for (size_t i = 0; i < noms.size(); i++) {
        for (size_t k = 0; k < dits.size(); k++) {
            if (dits[k] == noms[i]) { estDit[i] = true; break; }
        }
    }

    std::vector<int> ordre;
    for (size_t i = 0; i < noms.size(); i++) ordre.push_back((int)i);
    for (size_t i = 0; i < ordre.size(); i++) {
        for (size_t j = i + 1; j < ordre.size(); j++) {
            int a = ordre[i], b = ordre[j];
            bool echange = false;
            if (fois[b] > fois[a]) echange = true;
            else if (fois[b] == fois[a]) {
                if (premier[b] < premier[a]) echange = true;
                else if (premier[b] == premier[a] && b < a) echange = true;
            }
            if (echange) {
                int tmp = ordre[i];
                ordre[i] = ordre[j];
                ordre[j] = tmp;
            }
        }
    }

    long long total = 0, nonDitFois = 0;
    int nonDits = 0;
    for (size_t i = 0; i < ordre.size(); i++) {
        int id = ordre[i];
        std::cout << noms[id] << " " << fois[id] << (estDit[id] ? " DIT" : " NON_DIT") << std::endl;
        total += fois[id];
        if (!estDit[id]) {
            nonDits++;
            nonDitFois += fois[id];
        }
    }

    long long part = (total == 0) ? 0 : (100 * nonDitFois) / total;

    std::cout << "NON_DITS " << nonDits << std::endl;
    std::cout << "PART_NON_DITE " << part << std::endl;

    std::cout << "DIT_SANS_VU";
    bool aucun = true;
    for (size_t k = 0; k < dits.size(); k++) {
        bool vu = false;
        for (size_t i = 0; i < noms.size(); i++) {
            if (noms[i] == dits[k]) { vu = true; break; }
        }
        if (!vu) {
            std::cout << " " << dits[k];
            aucun = false;
        }
    }
    if (aucun) std::cout << " AUCUN";
    std::cout << std::endl;

    std::cout << "HORS_SEANCE " << horsSeance << std::endl;
    return 0;
}