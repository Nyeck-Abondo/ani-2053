#include "Entity.h"

namespace simul {

    namespace core {

        void Entity::Move(math::Vec2 side) {
            mpos += side;
        }

        void Entity::Suicide() {
            mhealth = 0.f;
        }

    } // namespace core
    
    
} // namespace simul
