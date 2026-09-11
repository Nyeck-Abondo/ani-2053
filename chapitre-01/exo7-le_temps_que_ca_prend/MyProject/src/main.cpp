#include <iostream>
#include <vector>
#include "../world/world.h"

namespace simulation = simul::core;
namespace simmath = simul::math;

int main(int argc, char** argv) {
    //debut de la simulation avec un nombre prédefini d'entité en ligne de commasnde
    simul::World area;
    area.Init({150, 500} , 5);
    
    std::cout << "Population : " << area.GetPopulationCount() << std::endl;

    //MOUVEMENT DANS LA ZONE
    std::cout << " \n===MOUVEMENT ALEATOIRE===" << std::endl;
    area.applyRandomMove();
    area.ShowAllPosition();

    std::cout <<"\n \n===SUICIDE ALEATOIRE===" << std::endl;
    area.RandomSuicide();
    area.ShowAllPosition();
    
    return 0;
}