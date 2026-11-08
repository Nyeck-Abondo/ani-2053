#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int S = 0, V = 0, F = 0;
    int ids = 0, N = 0;
    std::vector<int> perdues;
    std::vector<int> planche;

    std::cin >> S >> V >> F;
    std::cin >> N;

    for (int k = 1; k <= N; k++) {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "AJOUTE") {
            perdues.push_back(++ids);
        }
        else if (cmd == "SUPPRIME") {
            int index = 0;
            std::cin >> index;
            int texture = planche[index];
            if (S > 1) {
                std::cout << "PLANTAGE " << k << " TEXTURE " << texture << std::endl;
                return 0;
            }
            else if (S == 0) {
                perdues.push_back(texture);
            }
            planche.erase(planche.begin() + index);
        }
        else if (cmd == "VIDE") {
            for (int t : planche) {
                if (V == 2) {
                    std::cout << "PLANTAGE " << k << " TEXTURE " << t << std::endl;
                    return 0;
                }
                if (V == 0)
                perdues.push_back(t);
            }
            planche.clear();
        }
    }

    for (int t : planche) {
        if (F == 2) {
            std::cout << "PLANTAGE FIN TEXTURE " << t << std::endl;
            return 0;
        }
        if (F == 0)
        perdues.push_back(t);
    }

    std::sort(perdues.begin(), perdues.end());

    std::cout << "CREEES " << ids << std::endl;
    std::cout << "FUITES " << perdues.size() << std::endl;
    if (perdues.empty()) {
        std::cout << "PERDUES AUCUN" << std::endl;
    } else {
        std::cout << "PERDUES";
        for (int t : perdues)
            std::cout << " " << t;
        std::cout << std::endl;
    }

    return 0;
}
