#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

struct Files {
    std::string name;
    int headerCount = 0;
    std::vector<std::string> headers;
    std::vector<int> includedBy;     // indices des fichiers qui m'incluent
    bool visited = false;
};

std::vector<Files> allFiles;

// vrai si s se termine par suf
bool finitPar(const std::string& s, const std::string& suf) {
    return s.size() >= suf.size() &&
           s.compare(s.size() - suf.size(), suf.size(), suf) == 0;
}

// indice du fichier nom, -1 s'il n'est pas dans la liste
int trouverFichier(const std::string& nom) {
    auto it = std::find_if(allFiles.begin(), allFiles.end(), [&] (const Files& f) {
        return f.name == nom;
    });
    if (it == allFiles.end()) return -1;
    return static_cast<int>(it - allFiles.begin());
}

// nombre de .cpp atteints en remontant depuis i (i compris)
int compter(int i) {
    if (allFiles[i].visited) return 0;           // deja compte par un autre chemin
    allFiles[i].visited = true;

    int total = finitPar(allFiles[i].name, ".cpp") ? 1 : 0;
    for (int p : allFiles[i].includedBy)
        total += compter(p);
    return total;
}

int combien(int i) {
    for (auto& f : allFiles) f.visited = false;
    return compter(i);
}

int main() {
    int N = 1;
    std::cin >> N;
    allFiles.resize(N);
    std::cin.ignore();
    std::string line;

    for (int i = 0; i < N; i++) {
        std::getline(std::cin, line);
        std::istringstream is(line);
        is >> allFiles[i].name >> allFiles[i].headerCount;
        std::string h;
        while (is >> h) {
            allFiles[i].headers.push_back(h);
        }
    }

    // graphe inverse : pour chaque inclusion connue, j est inclus par i
    for (int i = 0; i < N; i++) {
        for (auto& h : allFiles[i].headers) {
            int j = trouverFichier(h);
            if (j >= 0)                          // les noms inconnus sont ignores
                allFiles[j].includedBy.push_back(i);
        }
    }

    // questions
    int Q = 0;
    std::cin >> Q;
    for (int q = 0; q < Q; q++) {
        std::string nom;
        std::cin >> nom;
        int idx = trouverFichier(nom);
        std::cout << nom << " " << combien(idx) << std::endl;
    }

    // en-tete le plus lourd, le premier gagne en cas d'egalite
    int meilleur = -1, nbMeilleur = -1;
    for (int i = 0; i < N; i++) {
        if (finitPar(allFiles[i].name, ".h")) {
            int r = combien(i);
            if (r > nbMeilleur) {                // strictement : garde le premier
                nbMeilleur = r;
                meilleur = i;
            }
        }
    }

    if (meilleur < 0)
        std::cout << "PLUS_LOURD AUCUN" << std::endl;
    else
        std::cout << "PLUS_LOURD " << allFiles[meilleur].name << " " << nbMeilleur << std::endl;

    return 0;
}