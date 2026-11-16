#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

struct OperationT {
    std::string name;
    std::vector<std::string> tableau;
};

struct OperationImg {
    std::string name, picture;
    int n;
    std::vector<int> index;
};

int main() {
    std::vector<OperationT> tabOp;
    std::vector<std::string> modele, texture, sources;
    int N;
    std::string line;
    for(int i = 0; i < 3; i++) {
        std::getline(std::cin, line);
        std::istringstream is (line);
        OperationT op;
        is >> op.name;
        std::string tab;
        while (is >> tab) {
            op.tableau.push_back(tab);
        }
        tabOp.push_back(op);
    }

    std::cin >> N;
    std::cin.ignore();
    std::vector<OperationImg> imgOp;
    for (int i = 0; i < N; i++) {
        OperationImg op;
        std::getline(std::cin, line);
        std::istringstream is(line);
        is >> op.name;
        if (op.name == "MONTE") {
            is >> op.n;
        }
        else if (op.name == "SUPPRIME") {
            int id;
            while (is >> id) {
                op.index.push_back(id);
            }
        }
        imgOp.push_back(op);
    }

    for (int i = 0; i < imgOp.size(); i++) {
        if (imgOp[i].name == "AJOUTE") {
            modele.push_back(imgOp[i].picture);
            for (int j = 0; j < tabOp[0].tableau.size(); j++) {
                if (tabOp[0].tableau[j] == "textures") {
                    texture.push_back(imgOp[i].picture);
                }
                if (tabOp[0].tableau[j] == "sources") {
                    sources.push_back(imgOp[i].picture);
                }
            }

        }
        if (imgOp[i].name == "SUPPRIME") {
            std::sort(imgOp[i].index.begin(), imgOp[i].index.end(), std::greater<int>());

            for (int k = 0; k < imgOp[i].index.size(); k++) {
                if (imgOp[i].index[k] >= modele.size())
                    continue;
                auto it = modele.begin() + imgOp[i].index[k];
                modele.erase(it);
            }

            for (int j = 0; j < tabOp[1].tableau.size(); j++) {
                if (tabOp[1].tableau[j] == "textures") {
                    for (int k = 0; k < imgOp[i].index.size(); k++) {
                        if (imgOp[i].index[k] >= texture.size())
                            continue;
                        auto it = texture.begin() + imgOp[i].index[k];
                        texture.erase(it);
                    }
                }

                else if (tabOp[1].tableau[j] == "sources") {
                    for (int k = 0; k < imgOp[i].index.size(); k++) {
                        if (imgOp[i].index[k] >= sources.size())
                            continue;
                        auto it = sources.begin() + imgOp[i].index[k];
                        sources.erase(it);
                    }
                }
            }
            
            if (imgOp[i].name == "MONTE" || imgOp[i].name == "DESCEND") {
                int a = imgOp[i].n;
                int b = (imgOp[i].name == "MONTE") ? a + 1 : a - 1;
                if (b < 0 || b >= modele.size())
                    continue;
                std::swap(modele[a], modele[b]);
                for (int j = 0; j < tabOp[2].tableau.size(); j++) {
                    if (tabOp[2].tableau[j] == "textures" && a < texture.size() && b < texture.size()) {
                        std::swap(texture[a], texture[b]);
                    }
                    if (tabOp[2].tableau[j] == "sources" && a < sources.size() && b < sources.size()) {
                        std::swap(sources[a], sources[b]);
                    }
                }
            }
        }
    }
    
    int L = std::max({modele.size(), texture.size(), sources.size()});
    int decales = 0;
    for (int i = 0; i < L; i++) {
        std::string m = (i < modele.size()) ? modele[i] : "-";
        std::string t = (i < texture.size()) ? texture[i] : "-";
        std::string s = (i < sources.size()) ? sources[i] : "-";
        std::cout << i << " " << m << " " << t << " " << s << "\n";
        if (m != t || m != s)
            decales++;
    }
    std::cout << "DECALES " << decales << "\n";
    
    return 0;
}