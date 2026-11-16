#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>

int main() {
    int N;
    std::string line;
    std::vector<int> planche;
    int newId = 1;
    int occasions = 0;
    int repercutes = 0;
    int recherches = 0;

    std::cin >> N;
    std::cin.ignore();

    for (int i = 0; i < N; i++) {
        std::getline(std::cin, line);
        std::istringstream is(line);
        std::string name;
        is >> name;

        if (name == "AJOUTE") {
            planche.push_back(newId);
            newId++;
        }

        else if (name == "SUPPRIME") {
            int c;
            is >> c;
            std::vector<int> index;
            for (int j = 0; j < c; j++) {
                int val;
                is >> val;
                index.push_back(val);
            }
            std::sort(index.begin(), index.end(), std::greater<int>());

            for (int k = 0; k < c; k++) {
                planche.erase(planche.begin() + index[k]);
            }
            occasions ++;
            repercutes += 2 * c;
        }

        else if (name == "MONTE" || name == "DESCEND") {
            int a;
            is >> a;
            int b = (name == "MONTE") ? a + 1 : a - 1;
            if (b >= 0 && b < planche.size()) {
                std::swap(planche[a], planche[b]);
                occasions++;
                repercutes += 2;
            }

        }

        else if (name == "DESSINE") {
            recherches += planche.size();
        }
    }

    std::cout << "ORDRE";
    if (planche.empty()) {
        std::cout << " AUCUN";
    }
    for (int i = 0; i < planche.size(); i++) {
        std::cout << " " << planche[i];
    }
    std::cout << "\n";
    std::cout << "OCCASIONS " << occasions << "\n";
    std::cout << "REPERCUTES " << repercutes << "\n";
    std::cout << "RECHERCHES " << recherches << "\n";

    return 0;
}