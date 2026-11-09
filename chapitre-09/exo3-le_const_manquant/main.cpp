#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

struct Methode {
    std::string nom;
    std::string declare;
    int modifie = 0;
    int callcount = 0;
    std::vector<std::string> otherMethods;
    int niveau = -2;
    bool canConst = false;

    friend std::istream& operator>> (std::istream& is, Methode& m) {
        is >> m.nom >> m.declare >> m.modifie >> m.callcount;
        return is;
    }
};

// variable globale de fonctions à remplir
std::vector<Methode> functions;

int CalculNiveau(int i) {
    Methode& m = functions[i];
    if (m.niveau != -2) return m.niveau;
    if (m.declare == "const") return m.niveau = 0;
    if (m.modifie == 1) return m.niveau = -1;

    int mx = 0;
    //calcul du niveau de chaque fonctions appelee par lea ;ethode courantes
    for (auto& appel : functions[i].otherMethods) {
        auto it = std::find_if(functions.begin(), functions.end(), [&] (Methode& m) {
            return m.nom == appel;
        });
        int level = 0, index = 0;
        if (it != functions.end()) {
            index = it - functions.begin();
        }
        level = CalculNiveau(index);
        if (level < 0) return m.niveau = -1;
        mx = std::max(mx, level);
    }
    m.canConst = true;
    return m.niveau = mx + 1;
}

void afficher(const std::string& titre, const std::vector<std::string>& noms) {
    std::cout << titre;
    if (noms.empty()) std::cout << " AUCUN";
    for (const auto& n : noms) std::cout << ' ' << n;
    std::cout << '\n';
}


int main() {
    int N = 0;

    std::cin >> N;
    functions.resize(N);
    std::cin.ignore();
    std::string line;

    for (int i = 0; i < N; i++) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        iss >> functions[i];

        std::string fc;
        while (iss >> fc) {
            functions[i].otherMethods.push_back(fc);
        }
    }

    std::vector<std::string> pourrait, racines;
    int passes = 0;

    for (int i = 0; i < N; i++) {
        int level = CalculNiveau(i);
        if (functions[i].declare != "const" && level >= 1) {
            pourrait.push_back(functions[i].nom);
            if (level == 1)
                racines.push_back(functions[i].nom);
            passes = std::max(passes, level);
        }
    }

    afficher("POURRAIT", pourrait);
    afficher("RACINES", racines);
    std::cout << "PASSES " << passes << '\n';
    
    return 0;
}