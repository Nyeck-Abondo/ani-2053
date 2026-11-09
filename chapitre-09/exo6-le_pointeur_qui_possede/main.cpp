#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

struct Cmds {
    std::string name;
    std::string a, b;
};

struct Var {
    std::string nom;
    int objet = 0;
};

std::vector<Cmds> commands;
std::vector<Var> vars;
int crees = 0, detruits = 0, nuls = 0;

int trouverVar(const std::string& nom) {
    auto it = std::find_if(vars.begin(), vars.end(), [&] (const Var& x) {
        return x.nom == nom;
    });
    if (it == vars.end()) {
        Var v;
        v.nom = nom;
        vars.push_back(v);
        return static_cast<int>(vars.size()) - 1;
    }
    return static_cast<int>(it - vars.begin());
}

// detruit l'objet s'il existe
void detruire(int objet) {
    if (objet == 0) return;
    std::cout << "DETRUIT " << objet << std::endl;
    detruits++;
}

int main() {
    int N = 0;
    std::cin >> N;
    std::cin.ignore();
    std::string line;

    for (int i = 0; i < N; i++) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        Cmds c;
        iss >> c.name >> c.a;
        if (c.name == "MOVE" || c.name == "COPY")
            iss >> c.b;
        commands.push_back(c);
    }

    bool copie = false;
    for (int i = 0; i < N; i++) {
        if (commands[i].name == "COPY") {
            std::cout << "REFUSE " << i + 1 << std::endl;
            copie = true;
        }
    }
    if (copie) return 0;

    // rejeu des lignes dans l'ordre
    for (int i = 0; i < N; i++) {
        int k = i + 1;

        if (commands[i].name == "NEW") {
            int ia = trouverVar(commands[i].a);
            crees++;
            int ancien = vars[ia].objet;
            vars[ia].objet = crees;
            detruire(ancien);
        }
        else if (commands[i].name == "MOVE") {
            int ia = trouverVar(commands[i].a);
            int ib = trouverVar(commands[i].b);
            int pris = vars[ia].objet;
            vars[ia].objet = 0;
            detruire(vars[ib].objet);
            vars[ib].objet = pris;
        }
        else if (commands[i].name == "RESET") {
            int ia = trouverVar(commands[i].a);
            detruire(vars[ia].objet);
            vars[ia].objet = 0;
        }
        else if (commands[i].name == "USE") {
            int ia = trouverVar(commands[i].a);
            if (vars[ia].objet == 0) {
                std::cout << "NUL " << k << " " << commands[i].a << std::endl;
                nuls++;
            }
        }
    }

    // les variables meurent dans l'ordre inverse de leur apparition
    for (int i = static_cast<int>(vars.size()) - 1; i >= 0; i--)
        detruire(vars[i].objet);

    std::cout << "CREES " << crees << std::endl;
    std::cout << "DETRUITS " << detruits << std::endl;
    std::cout << "NULS " << nuls << std::endl;
    return 0;
}