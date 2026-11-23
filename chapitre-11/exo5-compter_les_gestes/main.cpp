#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int t = 0, tDebut = 0, min = 0, parjour = 0, waitTime = 0;
    std::string action, nom, line;
    int g = 0, e = 0, d = 0;
    long long a = 0, m = 0, ss = 0;
    long long totalJour = 0;
    bool finished = true;   // true = aucune tâche en cours
    std::vector<std::string> response;

    while(std::getline(std::cin, line)) {
        std::istringstream is(line);
        action.clear();
        is >> t >> action;
        if (action == "DEBUT") {
            tDebut = t;
            g = e = d = 0;
            a = 0;
            is >> nom >> min >> parjour;
            finished = false;
        }
        else if (action == "CLIC"|| action == "TOUCHE" || action == "MOLETTE" || action == "GLISSE") {
            if (!finished)
                g++;
        }
        else if (action == "ATTENTE") {
            is >> waitTime;
            if (!finished)
                a += waitTime;
        }
        else if (action == "FIN") {
            finished = true;
            d = t - tDebut;
            e = (g > min) ? g - min : 0;
            //JOUR
            long long secondes = (a * parjour) / 1000;
            totalJour += secondes;
            m = secondes / 60;
            ss = secondes % 60;
            std::string msg = nom + " GESTES " + std::to_string(g) + " EN_TROP " + std::to_string(e)
                            + " DUREE " + std::to_string(d) + " ATTENTE " + std::to_string(a);
            msg += " JOUR " + std::to_string(m) + ":" + (ss < 10 ? "0" : "") + std::to_string(ss);
            std::cout << msg << std::endl;
            g = e = d = 0;
            a = 0;
        }
    }
    if (!finished)
        response.push_back(nom + " INACHEVEE");
    for (auto r : response) {
        std::cout << r << std::endl;
    }
    m = totalJour / 60;
    ss = totalJour % 60;
    std::cout << "TOTAL_JOUR " << m << ":" << (ss < 10 ? "0" : "") << ss << std::endl;
    return 0;
}