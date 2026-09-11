#include "../2DEntity/Entity.h"
#include <random>
#include <iostream>

namespace simul {

    class World {
    private:
        math::Vec2 mworldSize;
        float mentityCount;
        std::vector<core::Entity> mpopulation;
        std::mt19937 mrandomGen;

    public:
        World() : mrandomGen(std::random_device{}()) { }
        ~World() = default;

        //getters
        float GetPopulationCount() { return mentityCount; }
        void Init(math::Vec2 size, float population);
        void applyRandomMove();
        void RandomSuicide();
        void ShowAllPosition();
    };
    
} // namespace simul
