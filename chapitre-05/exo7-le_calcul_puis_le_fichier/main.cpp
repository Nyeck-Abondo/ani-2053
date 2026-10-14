#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdint>

enum Mode {
    MEMOIRE,
    FLUX,
    NONE
};

enum State {
    ACCEPTED,
    REFUSED
};

struct Audio {
      std::string name;
      uint64_t frequence;
      uint64_t canaux;
      int bits;
      int pourcent = 0;
      uint64_t duree;
      uint64_t fichiers;
      uint64_t brut;
      Mode amod = Mode::NONE;
      State aSt = State::REFUSED;
      
      friend std::istream& operator>> (std::istream& is, Audio& a) {
          return is >> a.name >> a.frequence >> a.canaux >> a.bits >> a.duree >> a.fichiers;
      }
      friend std::ostream& operator<< (std::ostream& os, Audio& a) {
          if (a.amod == Mode::FLUX && a.aSt == State::ACCEPTED)
              return os << a.name << " "  << a.brut << " " << a.pourcent << " FLUX" << std::endl;
          if (a.amod == Mode::MEMOIRE && a.aSt == State::ACCEPTED)
              return os << a.name << " "  << a.brut << " " << a.pourcent << " FLUX" << std::endl;
          return os << a.name << " REFUSES" << std::endl;
      }
      
      void Evaluate() {
          if (bits == 8) {
              aSt = State::ACCEPTED;
              return;
          }
          else if (bits == 16) {
              aSt = State::ACCEPTED;
              return;
          }
          else if (bits == 24) {
              aSt = State::ACCEPTED;
              return;
          }
          else if (bits == 32) {
              aSt = State::ACCEPTED;
              return;
          }
          aSt = State::REFUSED;
      }
      
      void Update(uint64_t s) {
          if (aSt == State::REFUSED)
              return;
          brut = (frequence * canaux * bits * duree) / (1000 * 8);
          pourcent = fichiers * 100 / brut;
          if (brut > s)
              amod = Mode::FLUX;
          else
              amod = Mode::MEMOIRE;
      }
};

int main() {
    int N = 0;
    uint64_t S = 0;
    std::vector<Audio> allAudio;
    uint64_t MEMORY = 0;
    uint64_t F = 0, REFUSE = 0;
    std::cin >> S;
    std::cin >> N;
    allAudio.resize(N);
    
    for (int i = 0; i < N; i++) {
        std::cin >> allAudio[i];
    }
    
    for (int i = 0; i < N; i++) {
        allAudio[i].Evaluate();
        allAudio[i].Update(S);
        std::cout << allAudio[i];
        if (allAudio[i].aSt == State::REFUSED) {
            REFUSE++;
        }
        if (allAudio[i].amod == Mode::FLUX) {
            F++;
        }
        else
            MEMORY += allAudio[i].brut;
    }
    std::cout << "MEMOIRE " << MEMORY << std::endl;
    std::cout << "FLUX " << F << std::endl;
    std::cout << "REFUSES " << REFUSE << std::endl;

    return 0;
}
