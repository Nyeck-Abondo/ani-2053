#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

struct Cmds {
    std::string name;
    std::string a, b;
    bool isClosed = false;
};

std::vector<Cmds> commands;

int trouverDecl(const std::string& nom) {
    auto it = std::find_if(commands.begin(), commands.end(), [&] (const Cmds& x) {
        return x.name == "DECL" && x.a == nom;
    });
    return static_cast<int>(it - commands.begin());
}


bool liberer(const std::string& nom, const std::string& prefixe, int limite) {
    int taille = static_cast<int>(commands.size());
    int id = trouverDecl(nom);
    if (id == taille) return false;
    if (commands[id].isClosed) return false;

    for (int j = 0; j < limite; j++) {
        if (commands[j].name == "DEPEND" && commands[j].a == nom) {
            int idb = trouverDecl(commands[j].b);
            if (idb < taille && commands[idb].isClosed) {
                std::cout << "PLANTAGE " << nom << " " << commands[j].b << std::endl;
                return true;
            }
        }
    }
    commands[id].isClosed = true;
    std::cout << prefixe << " " << nom << std::endl;
    return false;
}

int main() {
    std::string line;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        Cmds c;
        iss >> c.name >> c.a;
        if (c.name == "DEPEND")
        iss >> c.b;
        commands.push_back(c);
    }

    int taille = static_cast<int>(commands.size());

    // rejeu des commandes dans l'ordre de lecture
    for (int i = 0; i < taille; i++) {
        if (commands[i].name == "FERME") {
            if (liberer(commands[i].a, "FERME", i)) return 0;
        }

        if (commands[i].name == "}") {
        // recherche de l'accolade ouvrante correspondante
        int profondeur = 0, debut = -1;
        for (int k = i - 1; k >= 0; k--) {
            if (commands[k].name == "}") profondeur++;
        if (commands[k].name == "{") {
                if (profondeur == 0) { debut = k; break; }
                profondeur--;
            }
        }
        // destruction du bloc, du dernier declare au premier
        for (int k = i - 1; k > debut; k--) {
            if (commands[k].name == "DECL") {
                if (liberer(commands[k].a, "DETRUIT", i)) return 0;
            }
        }
    }
}

for (int k = taille - 1; k >= 0; k--) {
    if (commands[k].name == "DECL") {
        if (liberer(commands[k].a, "DETRUIT", taille)) return 0;
    }
}

std::cout << "PROPRE" << std::endl;
return 0;
}