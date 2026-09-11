#include "../maths/maths.h"

namespace simul {

    namespace core {

        class Entity {
        private:
            math::Vec2 mpos;
            float mhealth;
        public:
            Entity() : mhealth(20.f), mpos({10, 10}) { }
            Entity(float health, math::Vec2 pos): mhealth(health), mpos(pos) {}
            ~Entity() = default;

            //getters
            math::Vec2 GetPosition() { return mpos; }
            float GetHealth() { return mhealth; }
            //methodes
            void Move(math::Vec2 side);
            void Suicide();
        };
        
    } // namespace core
    
    
} // namespace simul
