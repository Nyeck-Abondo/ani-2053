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

int main() {
    std::vector<Cmds> commands;
    Cmds c;
    std::string line;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        iss >> c.name >> c.a;
        if (c.name == "DEPEND")
        iss >> c.b;
        commands.push_back(c);
    }
    
    // objets - detruire normalement
    std::vector<std::string> obj;

    //Fermeture
    for (int i = 0; i < commands.size(); i++) {
        if (commands[i].name == "FERME") {
            for (int j = 0; j < commands.size(); j++) {
                if (commands[j].name == "DEPEND") {
                    auto it = std::find_if(commands.begin(), commands.end(), [&] (Cmds& c) {
                        return commands[j].a == commands[i].a; 
                    });
                    auto it1 = std::find_if(commands.begin(), commands.end(), [&] (Cmds& c) {
                        return commands[j].b == commands[i].a; 
                    });
                    // indices des appels des commandes de Fermeture
                    int ida = it - commands.begin();
                    int idb = it1 - commands.begin();

                    if (idb < ida) {
                        std::cout << "FERME " << commands[i].b << std::endl;
                        std::cout << "PLANTAGE " << commands[j].a << " " << commands[j].b << std::endl;
                        return 0;
                    }
                    else
                        std::cout << "FERME " << commands[i].a << std::endl;
                    commands[i].isClosed = true;
                }

                //objet a fermer par defaut
                if (commands[j].name == "DECL") {
                    if (commands[j].a != commands[i].a)
                        obj.push_back(commands[j].a);
                }
            }
        }
    }
    if (!obj.empty()) {
        for (auto & o : obj)
            std::cout << "DETRUIT " << o << std::endl;
        std::cout << "PROPRE" << std::endl;
    }
    return 0;
}