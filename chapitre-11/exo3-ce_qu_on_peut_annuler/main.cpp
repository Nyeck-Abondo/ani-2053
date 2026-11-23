#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::string line;
    std::vector<std::string> pile;
    std::vector<int> traits;
    int nbTrait = 0, k = 0;
    int justes = 0, riens = 0, trahis = 0, o = 0, a = 0;

    while (std::getline(std::cin, line)) {
        std::istringstream is(line);
        std::string op, nom;
        is >> op >> nom;
        if (op.empty()) continue;

        if (op == "ANNULE") {
            k++;
            std::string x = pile.empty() ? "AUCUNE" : pile.back();
            if (!pile.empty()) pile.pop_back();

            std::string y;
            if (traits.empty()) {
                y = "RIEN";
            } else {
                y = "TRAIT " + std::to_string(traits.back());
                traits.pop_back();
            }

            std::string verdict;
            if (y == "RIEN") {
                if (x == "AUCUNE") { verdict = "JUSTE"; justes++; }
                else               { verdict = "RIEN";  riens++;  }
            } else if (y == x) {
                verdict = "JUSTE"; justes++;
            } else {
                verdict = "TRAHI"; trahis++;
            }

            std::cout << "ANNULE " << k << " ATTENDU " << x
                      << " OBTENU " << y << " " << verdict << "\n";
        }
        else if (op == "TRAIT") {
            nbTrait++;
            traits.push_back(nbTrait);
            pile.push_back("TRAIT " + std::to_string(nbTrait));
            o++; a++;
        }
        else if (op == "EFFACE") {
            traits.clear();
            pile.push_back("EFFACE");
            o++;
        }
        else if (op == "RANGE") {
            pile.push_back("RANGE");
            o++;
        }
        else { // DEPOSE, DEPLACE, SUPPRIME, MIROIR
            pile.push_back(op + " " + nom);
            o++;
        }
    }

    std::cout << "JUSTES " << justes << "\n"
              << "RIENS " << riens << "\n"
              << "TRAHIS " << trahis << "\n"
              << "ANNULABLES " << a << " SUR " << o << "\n";
    return 0;
}