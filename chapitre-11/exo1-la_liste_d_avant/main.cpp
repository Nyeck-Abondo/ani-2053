#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>

struct Input {
    std::string name;
    std::string state = " ";
    static int position;
    int p;
    bool operator==(Input& other) {
        return name == other.name;
    }
    Input(std::string s) {
        position++;
        p = position;
        name = s;
    }
};
int Input::position = 0;

int main() {
    std::string line;
    int n, c, a;
    std::string avant, corrige, apres;
    int vrai = 0, fausse = 0, oublies = 0;
    int nouvelles = 0, part = 0;
    std::vector<Input> errors;

    auto insert = [&] (std::string& s, int& num) {
        std::getline(std::cin, line);
        std::istringstream is(line);
        is >> s >> num;
        if (num < 0) num = 0;

        for (int i = 0; i < num; i++) {
            std::string s;
            std::cin >> s;
            errors.push_back(s);
        }
        std::cin.ignore();
    };

    auto afficherFin = [&] () {
        std::cout << "VRAIES " << vrai << std::endl;
        std::cout << "FAUSSES " << fausse << std::endl;
        std::cout << "OUBLIEES " << oublies << std::endl;
        std::cout << "NOUVELLES " << nouvelles << std::endl;
        std::cout << "PART_OUBLIEE " << part << std::endl;
    };

    insert(avant, n);
    insert(corrige, c);
    insert(apres, a);

    if (avant != "AVANT" && corrige != "AVANT" && apres != "AVANT") {
        afficherFin();
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = n; j < n + c; j++) {
            if (errors[i] == errors[j]) {
                errors[i].state = "DEVENUE_FAUSSE";
                fausse++;
            }
        }
        for (int j = n + c; j < n + c + a; j++) {
            if (errors[i] == errors[j]) {
                if (errors[i].state != "DEVENUE_FAUSSE") {
                    errors[i].state = "ENCORE_VRAIE";
                    vrai++;
                }
            }
        }
        if (errors[i].state != "DEVENUE_FAUSSE" && errors[i].state != "ENCORE_VRAIE") {
            errors[i].state = "OUBLIEE";
            oublies++;
        }
    }

    //NOUVELLES
    for (int j = n + c; j < n + c + a; j++) {
        auto end = errors.begin() + n;
        auto it = std::find_if(errors.begin(), end, [&] (Input i){
            return i.name == errors[j].name;
        });
        if (it != end)
        continue;
        else
        nouvelles++;
    }
    //PART OUBLIEES
    part = std::floor(100 * oublies / (vrai + oublies));

    if (n != 0) {
        for (int i = 0; i < n; i++) {
            std::cout << errors[i].p << " " << errors[i].name << " " << errors[i].state << std::endl;
        }
    }

    afficherFin();

    return 0;
}