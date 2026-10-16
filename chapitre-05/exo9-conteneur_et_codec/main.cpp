#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

struct Piste{
    std::string type = "";
    std::string code = "";
    std::string codec = "";

    friend std::istream& operator>> (std::istream& is, Piste& p) {
        return is >> p.type >> p.code;
    }

    void calculateStats() {
        if (code == "mp4a") codec = "aac";
        else if (code == "Opus" || code == "opus") codec = "opus";
        else if (code == "avc1" || code == "avc3") codec = "h264";
        else if (code == "hvc1" || code == "hev1") codec = "h265";
        else if (code == "vp08") codec = "vp8";
        else if (code == "vp09") codec = "vp9";
        else if (code == "mp4v") codec = "mpeg4";
        else if (code == ".mp3") codec = "mp3";
        else if (code == "twos" || code == "sowt" || code == "lpcm") codec = "pcm";
        else codec = code;
    }
};

struct Fichier{
    std::string nom = "";
    std::string hexa = "";
    int nbPistes = 0;
    int nbOctets = 0;
    std::string conteneur = "INCONNU";
    std::vector<int> octets;
    std::vector<Piste> pistes;

    friend std::istream& operator>> (std::istream& is, Fichier& f) {
        is >> f.nom >> f.hexa >> f.nbPistes;
        f.pistes.resize(f.nbPistes);
        for (int k = 0; k < f.nbPistes; k++)
            is >> f.pistes[k];
        return is;
    }

    int hexValue(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'a' && c <= 'f') return c - 'a' + 10;
        return c - 'A' + 10;
    }

    void calculateStats() {
        octets.clear();
        if (hexa != "-") {
            for (int i = 0; i + 1 < (int)hexa.size(); i += 2)
                octets.push_back(hexValue(hexa[i]) * 16 + hexValue(hexa[i + 1]));
        }
        nbOctets = octets.size();

        if (nbOctets >= 12 && octets[4] == 0x66 && octets[5] == 0x74
            && octets[6] == 0x79 && octets[7] == 0x70)
            conteneur = "MP4";
        else if (nbOctets >= 4 && octets[0] == 0x1A && octets[1] == 0x45
            && octets[2] == 0xDF && octets[3] == 0xA3)
            conteneur = "WEBM";
        else if (nbOctets >= 12 && octets[0] == 0x52 && octets[1] == 0x49
            && octets[2] == 0x46 && octets[3] == 0x46
            && octets[8] == 0x57 && octets[9] == 0x41
            && octets[10] == 0x56 && octets[11] == 0x45)
            conteneur = "WAV";
        else if (nbOctets >= 4 && octets[0] == 0x4F && octets[1] == 0x67
            && octets[2] == 0x67 && octets[3] == 0x53)
            conteneur = "OGG";
        else if (nbOctets >= 4 && octets[0] == 0x66 && octets[1] == 0x4C
            && octets[2] == 0x61 && octets[3] == 0x43)
            conteneur = "FLAC";
        else if (nbOctets >= 3 && octets[0] == 0x49 && octets[1] == 0x44
            && octets[2] == 0x33)
            conteneur = "MP3";
        else if (nbOctets >= 2 && octets[0] == 0xFF && octets[1] >= 0xE0)
            conteneur = "MP3";
        else
            conteneur = "INCONNU";

        for (int k = 0; k < nbPistes; k++)
            pistes[k].calculateStats();
    }

    std::string verdict() {
        for (int k = 0; k < nbPistes; k++) {
            if (pistes[k].type == "vide") {
                std::string c = pistes[k].code;
                if (c == "mjpa" || c == "jpeg" || c == "MJPG" || c == "avc1"
                    || c == "avc3" || c == "hvc1" || c == "hev1" || c == "av01")
                    return "LISIBLE";
                else
                    return "ECHEC";
            }
        }
        return "SANS_IMAGE";
    }
};

int main() {
    int n = 0;
    int mp4 = 0, lisibles = 0, inconnus = 0;
    std::vector<Fichier> allFichiers;
    std::cin >> n;

    allFichiers.resize(n);
    for (int i = 0; i < n; i++)
        std::cin >> allFichiers[i];

    for (int i = 0; i < n; i++) {
        allFichiers[i].calculateStats();
        std::cout << allFichiers[i].nom << " " << allFichiers[i].conteneur << std::endl;

        if (allFichiers[i].conteneur == "MP4") {
            mp4++;
            for (int k = 0; k < allFichiers[i].nbPistes; k++) {
                std::cout << allFichiers[i].nom << " PISTE " << k + 1 << " ";
                if (allFichiers[i].pistes[k].type == "vide")
                    std::cout << "VIDEO ";
                else
                    std::cout << "AUDIO ";
                std::cout << allFichiers[i].pistes[k].codec << std::endl;
            }
            std::string v = allFichiers[i].verdict();
            std::cout << allFichiers[i].nom << " LECTEUR " << v << std::endl;
            if (v == "LISIBLE")
                lisibles++;
        }
        else if (allFichiers[i].conteneur == "INCONNU") {
            inconnus++;
        }
    }

    std::cout << "MP4 " << mp4 << std::endl;
    std::cout << "LISIBLES " << lisibles << std::endl;
    std::cout << "INCONNUS " << inconnus << std::endl;

    return 0;
}