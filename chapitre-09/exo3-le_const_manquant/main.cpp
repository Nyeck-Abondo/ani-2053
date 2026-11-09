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
    
    //vérification de la possibilité de passage à const
    for (int i = 0; i < N; i++) {
        if (functions[i].declare == "const" || functions[i].modifie == 0) {
            for (int j = 0; j < functions[i].otherMethods.size(); j++) {
                auto it = std::find_if(functions.begin(), functions.end(), [&] (Methode& m) {
                    return m.nom == functions[i].otherMethods[j]; 
                });
                if (it != functions.end()) {
                    
                }
            }
        }
    }
    return 0;
}