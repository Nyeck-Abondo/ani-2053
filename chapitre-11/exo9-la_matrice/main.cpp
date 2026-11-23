#include <iostream>
#include <vector>
#include <string>

int main() {
    int n = 0;
    std::cin >> n;

    std::vector<std::string> nom, etiq, genre, cible, raison;
    std::vector<int> val, cost;
    std::vector<bool> garde;

    // lecture des entrees
    for (int i = 0; i < n; i++) {
        std::string nm, et, ge, ci;
        int v, c;
        std::cin >> nm >> v >> c >> et >> ge;
        if (ge == "SOCLE") std::cin >> ci;

        nom.push_back(nm);
        val.push_back(v);
        cost.push_back(c);
        etiq.push_back(et);
        genre.push_back(ge);
        cible.push_back(ci);

        if (ge == "REECRITURE") {
            garde.push_back(false);
            raison.push_back("reecriture");
        } else if (ge == "CHOIX") {
            garde.push_back(false);
            raison.push_back("choix");
        } else if (et == "-") {
            garde.push_back(false);
            raison.push_back("sans_etiquette");
        } else {
            garde.push_back(true);
            raison.push_back("");
        }
    }

    // valeur effective : un socle prend la valeur de sa cible MANQUE gardee
    std::vector<int> valeur = val;
    for (int i = 0; i < n; i++) {
        if (garde[i] && genre[i] == "SOCLE") {
            for (int j = 0; j < n; j++) {
                if (garde[j] && genre[j] == "MANQUE" && nom[j] == cible[i]) {
                    if (val[j] > valeur[i]) valeur[i] = val[j];
                    break;
                }
            }
        }
    }

    // case et rang d'etiquette
    std::vector<int> cas(n, 0), rang(n, 0);
    for (int i = 0; i < n; i++) {
        bool forte = valeur[i] >= 3;
        bool eleve = cost[i] >= 3;
        if (forte && !eleve) cas[i] = 0;
        else if (forte && eleve) cas[i] = 1;
        else if (!forte && !eleve) cas[i] = 2;
        else cas[i] = 3;

        if (etiq[i] == "MESUREE") rang[i] = 0;
        else if (etiq[i] == "OBSERVEE") rang[i] = 1;
        else rang[i] = 2;
    }

    // tri des entrees gardees
    std::vector<int> ordre;
    for (int i = 0; i < n; i++)
        if (garde[i]) ordre.push_back(i);

    for (size_t i = 0; i < ordre.size(); i++) {
        for (size_t j = i + 1; j < ordre.size(); j++) {
            int a = ordre[i], b = ordre[j];
            bool echange = false;
            if (cas[b] != cas[a]) echange = cas[b] < cas[a];
            else if (rang[b] != rang[a]) echange = rang[b] < rang[a];
            else if (valeur[b] != valeur[a]) echange = valeur[b] > valeur[a];
            else if (cost[b] != cost[a]) echange = cost[b] < cost[a];
            else echange = b < a;
            if (echange) {
                int tmp = ordre[i];
                ordre[i] = ordre[j];
                ordre[j] = tmp;
            }
        }
    }

    // affichage
    std::string noms[4] = {"MAINTENANT", "DECOUPER", "EN_PASSANT", "ON_NE_LE_FAIT_PAS"};
    bool refus = false;
    for (size_t i = 0; i < ordre.size(); i++) {
        int id = ordre[i];
        std::cout << noms[cas[id]] << " " << nom[id] << " " << etiq[id] << "\n";
        if (cas[id] == 3) refus = true;
    }
    for (int i = 0; i < n; i++) {
        if (!garde[i])
        std::cout << "HORS_LISTE " << nom[i] << " " << raison[i] << "\n";
    }
    std::cout << "VERDICT " << (refus ? "HONNETE" : "COMPLAISANT") << "\n";
    return 0;
}