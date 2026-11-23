#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

struct Input {
    std::string hash;
    std::string action;
    std::vector<std::string> functions;
    bool retracted = false;
    int size;
};

struct Anounce {
    std::string hash;
    std::string action;
    std::string function;
};

struct Info {
    std::string hash;
    std::string function;
};

int main() {
    std::string line;
    std::vector<Input> commits;
    std::vector<Anounce> ans;
    int n = 0, mensonges = 0;
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; i++) {
        std::getline(std::cin, line);
        std::istringstream is(line);
        Input com;
        is >> com.hash >> com.action >> com.size;
        std::string func;
        while (is >> func) {
            com.functions.push_back(func);
        }
        commits.push_back(com);
    }

    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; i++) {
        std::getline(std::cin, line);
        std::istringstream is(line);
        Anounce a;
        is >> a.hash >> a.action >> a.function;
        ans.push_back(a);
    }

    std::vector<Info> infs;
    //remplissage du tableau d'info avec index
    infs.push_back({commits[0].hash, commits[0].functions[0]});
    for (int i = 0; i < commits.size(); i++) {
        for (int j = 0; j < commits[i].functions.size(); j++) {
            auto it = std::find_if(infs.begin(), infs.end(), [&] (Info& inf) {
                return  inf.function == commits[i].functions[j];
            });
            if (it == infs.end()) {
                infs.push_back({commits[i].hash, commits[i].functions[j]});
            }
        }
    }

    // trie en fonction de l'qjout et du retrait
    for (int i = 0; i < commits.size(); i++) {
        if (commits[i].action == "AJOUTE")
        continue;
        else if (commits[i].action == "RETIRE") {
            for (int j = 0; j < commits[i].functions.size(); j++) {
                auto it = std::find_if(infs.begin(), infs.end(), [&] (Info inf) {
                    return inf.function == commits[i].functions[j];
                });
                if (it != infs.end()) {
                    infs.erase(it);
                }
            }
        }
    }

    // pqrcour du tableua d'annonces a la recherche des menteurs
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].action == "DISPONIBLE") {
            // verification de la presence dans les commits de la fontion de l'annonce
            auto it = find_if(infs.begin(), infs.end(), [&] (Info inf) {
                return inf.function == ans[i].function;
            });
            //retrouve le hash
            if (it != infs.end()) {
                std::cout << "ANNONCE " << i + 1 << " VRAI" << std::endl;
            }
            else {
                for (int j = commits.size() - 1; j >= 0; j--) {
                    auto op = std::find_if(commits[j].functions.begin(), commits[j].functions.end(), [&] (std::string s) {
                        return s == ans[i].function;
                    });
                    if (op != commits[j].functions.end()) {
                        mensonges++;
                        std::cout << "ANNONCE " << i + 1 << " MENT " << commits[j].hash << std::endl;
                        break;
                    } else {
                        mensonges++;
                        std::cout << "ANONCE " << i + 1 << " MENT " << ans[i].hash << std::endl;
                        break;
                    }
                }
            }
        }
        else if (ans[i].action == "A_VENIR") {
            auto it = find_if(infs.begin(), infs.end(), [&] (Info inf) {
                return inf.function == ans[i].function;
            });
            if (it == infs.end()) {
                std::cout << "ANNONCE " << i + 1 << " VRAI" << std::endl;
            }
            else {
                for (int j = 0; j < commits.size(); j++) {
                    auto op = std::find_if(commits[j].functions.begin(), commits[j].functions.end(), [&] (std::string& s) {
                        return s == ans[i].function;
                    });
                    if (op != commits[j].functions.end()) {
                        mensonges++;
                        std::cout << "ANNONCE " << i + 1 << " MENT " << commits[j].hash << std::endl;
                    }
                }
            }
        }
    }

    std::cout << "MENSONGES " << mensonges << std::endl;

    return 0;
}