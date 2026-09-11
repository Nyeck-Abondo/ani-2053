#include "world.h"

namespace simul {

    void World::Init(math::Vec2 size, float population) {
        mworldSize = size;
        mentityCount = population;
        for (int i = 0; i < mentityCount; i++) {
            std::uniform_real_distribution<float> dist(16, 100);
            mpopulation.push_back({dist(mrandomGen), {dist(mrandomGen), 15}});
        }
    }

    void World::applyRandomMove() {
        for (auto& unit : mpopulation) {
            std::uniform_real_distribution<float> dist(mworldSize.x, mworldSize.y);
            std::uniform_real_distribution<float> dist2(mworldSize.x, mworldSize.y);
            unit.Move({static_cast<float>(dist(mrandomGen)), static_cast<float>(dist2(mrandomGen))});
        }
    }

    void World::RandomSuicide() {
        std::uniform_real_distribution<float> dist(0, mpopulation.size() - 1);
        mpopulation[dist(mrandomGen)].Suicide();
    }

    void World::ShowAllPosition() {
        for (int i = 0; i < mpopulation.size(); i++) {
            std::cout << "Entity-" << i << ": " << mpopulation[i].GetPosition() << mpopulation[i].GetHealth();
            std::cout << std::endl;
        }
    }
    
} // namespace simul
