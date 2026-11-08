#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

enum State {
    ECRIT,
    DEFAUT,
    SUPPRIME,
    ABSENT
};

enum Type {
    DESTRUCTEUR,
    COPIE,
    AFFECTATION_COPIE,
    DEPLACEMENT,
    AFFECTATION_DEPLACEMENT
};

struct Response {
    std::string line;
    State st = State::ABSENT;
    Type tp = Type::DESTRUCTEUR;

    Response(std::string s) : line(s) {

    }
    std::string StateToString() {
        switch (st) {
            case State::ABSENT:
            return "ABSENT";
            break;

            case State::DEFAUT:
            return "DEFAUT";
            break;

            case State::ECRIT:
            return "ECRIT";
            break;

            case State::SUPPRIME:
            return "SUPPRIME";
            break;

            default:
            break;
        }
        return "";
    }
};

int main() {
    std::string c;
    std::string commentaire = "//";
    std::vector<Response> response;
    response.reserve(20000);

    std::getline(std::cin, c);
    c.erase(std::remove_if(c.begin(), c.end(), [](char ch) { return ch == ' ' || ch == '\r'; }), c.end());


    //lecture des differentes lignes
    std::string ligne;
    while (std::getline(std::cin, ligne)) {
        // 1. retrait des commentaires s'il y en a
        size_t commentPos = ligne.find(commentaire);
        if (commentPos != std::string::npos) {
            ligne = ligne.substr(0, commentPos);
        }
        // 2. retrait des espaces (et du \r eventuel)
        ligne.erase(std::remove_if(ligne.begin(), ligne.end(), [](char ch) { return ch == ' ' || ch == '\r'; }), ligne.end());
        // lignes vides ignorees
        if (ligne.empty())
        continue;
        response.emplace_back(ligne);
    }

    for (int i = 0; i < response.size(); i++){
        std::string& l = response[i].line;

        State etat = State::ECRIT;
        if (l.size() >= 8 && l.compare(l.size() - 8, 8, "=delete;") == 0)
        etat = State::SUPPRIME;
        else if (l.size() >= 9 && l.compare(l.size() - 9, 9, "=default;") == 0)
        etat = State::DEFAUT;

        std::string motif;
        size_t pos;

        //DESTRUCTEUR
        pos = l.find("~" + c + "(");
        if (pos != std::string::npos) {
            response[i].st = etat;
            response[i].tp = Type::DESTRUCTEUR;
        }

        //COPIE
        if (response[i].st != State::ABSENT)
        continue;

        motif = c + "(const" + c + "&";
        pos = l.find(motif);
        if (pos == 0 && !(l.size() > motif.size() && l[motif.size()] == '&')) {
            response[i].st = etat;
            response[i].tp = Type::COPIE;
        }

        //AFFECTATION_COPIE
        if (response[i].st != State::ABSENT)
        continue;

        motif = c + "&operator=(const" + c + "&";
        pos = l.find(motif);
        if (pos == 0 && !(l.size() > motif.size() && l[motif.size()] == '&')) {
            response[i].st = etat;
            response[i].tp = Type::AFFECTATION_COPIE;
        }

        //DEPLACEMENT
        if (response[i].st != State::ABSENT)
        continue;

        pos = l.find(c + "(" + c + "&&");
        if (pos == 0) {
            response[i].st = etat;
            response[i].tp = Type::DEPLACEMENT;
        }

        //AFFECTATION_DEPLACEMENT
        if (response[i].st != State::ABSENT)
        continue;

        pos = l.find(c + "&operator=(" + c + "&&");
        if (pos == 0) {
            response[i].st = etat;
            response[i].tp = Type::AFFECTATION_DEPLACEMENT;
        }
    }

    //recouvrement des ele,entseu
    int rules = 0;

    auto it = std::find_if(response.begin(), response.end(), [&] (Response& r) {
        return r.st != State::ABSENT &&  r.tp == Type::DESTRUCTEUR;
    });
    if (it != response.end()) {
        std::cout << "DESTRUCTEUR " << it->StateToString() << std::endl;
        rules++;
    }
    else {
        std::cout << "DESTRUCTEUR ABSENT" << std::endl;
    }

    auto ite = std::find_if(response.begin(), response.end(), [&] (Response& r) {
        return r.st != State::ABSENT &&  r.tp == Type::COPIE;
    });
    if (ite != response.end()) {
        std::cout << "COPIE " << ite->StateToString() << std::endl;
        rules++;
    }
    else {
        std::cout << "COPIE ABSENT" << std::endl;
    }

    auto i = std::find_if(response.begin(), response.end(), [&] (Response& r) {
        return r.st != State::ABSENT && r.tp == Type::AFFECTATION_COPIE;
    });
    if (i != response.end()) {
        std::cout << "AFFECTATION_COPIE " << i->StateToString() << std::endl;
        rules++;
    }
    else {
        std::cout << "AFFECTATION_COPIE ABSENT " << std::endl;
    }

    auto p = std::find_if(response.begin(), response.end(), [&] (Response& r) {
        return r.st != State::ABSENT && r.tp == Type::DEPLACEMENT;
    });
    if (p != response.end()) {
        std::cout << "DEPLACEMENT " << p->StateToString() << std::endl;
        rules++;
    }
    else {
        std::cout << "DEPLACEMENT ABSENT" << std::endl;
    }

    auto d = std::find_if(response.begin(), response.end(), [&] (Response& r) {
        return r.st != State::ABSENT && r.tp == Type::AFFECTATION_DEPLACEMENT;
    });
    if (d != response.end()) {
        std::cout << "AFFECTATION_DEPLACEMENT " << d->StateToString() << std::endl;
        rules++;
    }
    else {
        std::cout << "AFFECTATION_DEPLACEMENT ABSENT" << std::endl;
    }

    if (rules == 0) {
        std::cout << "REGLE ZERO" << std::endl;
    }
    else if (rules == 5) {
        std::cout << "REGLE CINQ" << std::endl;
    }
    else if (it != response.end() && ite != response.end() && i != response.end()
    && p == response.end() && d == response.end()) {
        std::cout << "REGLE TROIS" << std::endl;
    }
    else {
        std::cout << "REGLE INCOMPLETE" << std::endl;
        if (it == response.end())
        std::cout << "MANQUE DESTRUCTEUR" << std::endl;
        if (ite == response.end())
        std::cout << "MANQUE COPIE" << std::endl;
        if (i == response.end())
        std::cout << "MANQUE AFFECTATION_COPIE" << std::endl;
        // les deux derniers ne sont cites que si un deplacement est declare
        if (p != response.end() || d != response.end()) {
            if (p == response.end())
            std::cout << "MANQUE DEPLACEMENT" << std::endl;
            if (d == response.end())
            std::cout << "MANQUE AFFECTATION_DEPLACEMENT" << std::endl;
        }
    }

    std::cout << "POSSEDE " << ((it != response.end() && it->st == State::ECRIT) ? "OUI" : "NON") << std::endl;
    std::cout << "UNIQUE " << ((ite != response.end() && ite->st == State::SUPPRIME
    && p != response.end() && (p->st == State::DEFAUT || p->st == State::ECRIT)) ? "OUI" : "NON") << std::endl;
    return 0;
}