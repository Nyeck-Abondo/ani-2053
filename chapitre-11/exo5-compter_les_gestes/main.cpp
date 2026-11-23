#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int t = 0, tDebut = 0, min = 0, parjour = 0, waitTime;
    std::string action, nom, line;
    int g = 0, e = 0, d = 0, m = 0, ss = 0, a = 0;
    int totalJour = 0;
    bool finished = false;
    int taskCount = 0;
    std::vector<std::string> response;

    while(std::getline(std::cin, line)) {
        std::istringstream is(line);
        is >> t >> action;
        if (action == "DEBUT") {
            tDebut = t;
            g = e = d = a = 0;
            if (taskCount > 0 && !finished)
                response.push_back(nom + " INACHEVEE");
            is >> nom >> min >> parjour;
            taskCount++;
        }
        else if (action == "CLIC"|| action == "TOUCHE" || action == "MOLETTE" || action == "GLISSE") {
            g++;
        }
        else if (action == "ATTENTE") {
            is >> waitTime;
            a += waitTime;
            totalJour += waitTime;
        }
        else if (action == "FIN") {
            finished = true;
            d  = t - tDebut;
            e = (g > min) ? g - min : 0;
            //JOUR
            int totalTime = a * parjour;
            m = totalTime / 60000;
            ss = (totalTime / 1000) % 60;
            std::string msg = nom + " GESTES " + std::to_string(g).c_str() + " EN_TROP " + std::to_string(e).c_str() + " DUREE " + std::to_string(d).c_str() + " ATTENTE " + std::to_string(a);
            msg += " JOUR " + std::to_string(m) + ":" + std::to_string(ss).c_str();
            std::cout << msg << std::endl;
            g = e = d = a = 0;
        }
    }
    for (auto m : response) {
        std::cout << m << std::endl;
    }
    int totalTime = totalJour * parjour;
    std::cout << "TOTAL_JOUR " << totalTime / 60000 << ":" << (totalTime / 1000) % 60 << std::endl;
    return 0;
}