#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>

struct Item {
    std::string nom;
    bool choisi = false;
};

int main() {
    std::string line;

    std::vector<Item> dans;

    std::vector<std::string> plancheIndex;
    std::vector<int> gardes;

    std::vector<std::string> plancheId;
    std::vector<std::string> noms;

    while (std::getline(std::cin, line)) {
        std::istringstream is(line);
        std::string name;
        if (!(is >> name)) {
            continue;
        }

        if (name == "AJOUTE") {
            std::string nom;
            is >> nom;
            Item it;
            it.nom = nom;
            dans.push_back(it);
            plancheIndex.push_back(nom);
            plancheId.push_back(nom);
        }

        else if (name == "CLIC") {
            int i;
            is >> i;

            for (int k = 0; k < (int)dans.size(); k++) {
                dans[k].choisi = false;
            }
            if (i >= 0 && i < (int)dans.size()) {
                dans[i].choisi = true;
            }

            gardes.clear();
            if (i >= 0 && i < (int)plancheIndex.size()) {
                gardes.push_back(i);
            }

            noms.clear();
            if (i >= 0 && i < (int)plancheId.size()) {
                noms.push_back(plancheId[i]);
            }
        }

        else if (name == "AJOUTE_SEL") {
            int i;
            is >> i;

            if (i >= 0 && i < (int)dans.size()) {
                dans[i].choisi = true;
            }

            if (i >= 0 && i < (int)plancheIndex.size()) {
                if (std::find(gardes.begin(), gardes.end(), i) == gardes.end()) {
                    gardes.push_back(i);
                }
            }

            if (i >= 0 && i < (int)plancheId.size()) {
                if (std::find(noms.begin(), noms.end(), plancheId[i]) == noms.end()) {
                    noms.push_back(plancheId[i]);
                }
            }
        }

        else if (name == "ECHANGE") {
            int i;
            int j;
            is >> i >> j;

            if (i >= 0 && j >= 0 && i < (int)dans.size() && j < (int)dans.size()) {
                std::swap(dans[i], dans[j]);
            }
            if (i >= 0 && j >= 0 && i < (int)plancheIndex.size() && j < (int)plancheIndex.size()) {
                std::swap(plancheIndex[i], plancheIndex[j]);
            }
            if (i >= 0 && j >= 0 && i < (int)plancheId.size() && j < (int)plancheId.size()) {
                std::swap(plancheId[i], plancheId[j]);
            }
        }

        else if (name == "RETIRE") {
            int i;
            is >> i;

            if (i >= 0 && i < (int)dans.size()) {
                dans.erase(dans.begin() + i);
            }
            if (i >= 0 && i < (int)plancheIndex.size()) {
                plancheIndex.erase(plancheIndex.begin() + i);
            }
            if (i >= 0 && i < (int)plancheId.size()) {
                plancheId.erase(plancheId.begin() + i);
            }
        }

        else if (name == "SUPPRIME") {
            for (int k = (int)dans.size() - 1; k >= 0; k--) {
                if (dans[k].choisi) {
                    dans.erase(dans.begin() + k);
                }
            }

            std::sort(gardes.begin(), gardes.end(), std::greater<int>());
            for (int k = 0; k < (int)gardes.size(); k++) {
                if (gardes[k] < (int)plancheIndex.size()) {
                    plancheIndex.erase(plancheIndex.begin() + gardes[k]);
                }
            }
            gardes.clear();

            for (int k = (int)plancheId.size() - 1; k >= 0; k--) {
                if (std::find(noms.begin(), noms.end(), plancheId[k]) != noms.end()) {
                    plancheId.erase(plancheId.begin() + k);
                }
            }
            noms.clear();
        }
    }

    std::string conceptions[3] = {"DANS_ITEM", "PAR_INDEX", "PAR_ID"};
    std::vector<std::string> planches[3];
    std::vector<std::string> selections[3];

    for (int k = 0; k < (int)dans.size(); k++) {
        planches[0].push_back(dans[k].nom);
        if (dans[k].choisi) {
            selections[0].push_back(dans[k].nom);
        }
    }

    for (int k = 0; k < (int)plancheIndex.size(); k++) {
        planches[1].push_back(plancheIndex[k]);
        if (std::find(gardes.begin(), gardes.end(), k) != gardes.end()) {
            selections[1].push_back(plancheIndex[k]);
        }
    }

    for (int k = 0; k < (int)plancheId.size(); k++) {
        planches[2].push_back(plancheId[k]);
        if (std::find(noms.begin(), noms.end(), plancheId[k]) != noms.end()) {
            selections[2].push_back(plancheId[k]);
        }
    }

    for (int c = 0; c < 3; c++) {
        std::cout << conceptions[c] << " PLANCHE";
        if (planches[c].empty()) {
            std::cout << " AUCUN";
        }
        for (int k = 0; k < (int)planches[c].size(); k++) {
            std::cout << " " << planches[c][k];
        }
        std::cout << "\n";

        std::cout << conceptions[c] << " SELECTION";
        if (selections[c].empty()) {
            std::cout << " AUCUN";
        }
        for (int k = 0; k < (int)selections[c].size(); k++) {
            std::cout << " " << selections[c][k];
        }
        std::cout << "\n";
    }

    std::cout << "FAUX";
    bool aucun = true;
    for (int c = 1; c < 3; c++) {
        if (planches[c] != planches[0] || selections[c] != selections[0]) {
            std::cout << " " << conceptions[c];
            aucun = false;
        }
    }
    if (aucun) {
        std::cout << " AUCUN";
    }
    std::cout << "\n";

    return 0;
}