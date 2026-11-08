#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

enum Operation {
    AJOUTE,
    SUPPRIME,
    VIDE    
};

struct Texture {
    int value;
    static int ids;

    Texture () { value = ++ids;}
};

int Texture::ids = 0;

struct Command {
    int id;
    std::string cmd;
    Operation op = Operation::AJOUTE;

    void StringToCmd() {
        if (cmd == "AJOUTE")
        op = Operation::AJOUTE;
        else if (cmd == "SUPPRIME")
        op = Operation::SUPPRIME;
        else if (cmd == "VIDE")
        op = Operation::VIDE; 
    }
};

int main() {
    int S = 0, V = 0, F = 0;
    int N = 0;
    std::vector<Command> operations;
    std::vector<Texture> planche;

    std::cin >> S >> V >> F;
    std::cin >> N;
    operations.resize(N);

    for (int i = 0; i < N; i++) {
        std::cin >> operations[i].cmd;
        operations[i].StringToCmd();
        if (operations[i].op == Operation::SUPPRIME)
        std::cin >> operations[i].id;
    }

    // process des operations
    int c = 0, f = 0;
    std::vector<int> suppressed;

    for (int i = 0; i < N; i++) {
        if (operations[i].op == Operation::AJOUTE) {
            planche.emplace_back();
            c++;
        }
        if (operations[i].op == Operation::SUPPRIME) {
            int index = operations[i].id;
            Texture it = planche[index];

            if (S == 0) {
                f++;
                suppressed.emplace_back(it.value);
            }
            else if (S > 1) {
                std::cout << "PLANTAGE " << i << " TEXTURE " << planche[i].value << std::endl;
                return 0;
            }
            planche.erase(planche.begin() + index);
        }

        if (operations[i].op == Operation::VIDE) {
            if (V == 0) {
                f += planche.size();
                for (auto t : planche)
                    suppressed.emplace_back(t.value);
            }
            else if (V > 1) {
                std::cout << "PLANTAGE " << i << " TEXTURE " << planche[i].value << std::endl;
                return 0;
            }
            planche.clear();

        }
    }

    std::cout << "CREEES " << c << std::endl;
    std::cout << "FUITES " << f << std::endl;
    std::cout << "PERDUES";
    for (auto t : suppressed)
    std::cout << " " << t;
    std::cout << std::endl;

    return 0;
}
