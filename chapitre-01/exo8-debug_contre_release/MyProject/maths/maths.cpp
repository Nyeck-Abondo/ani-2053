#include "maths.h"

namespace simul {
    
    namespace math {

        std::ostream& operator<<(std::ostream& os, const Vec2& v) {
            os << "< " << v.x << " ; " << v.y << " >";
            return os;
        }

        float Vec2::DotProduct(Vec2& other) {
            return x * other.x + y * other.y;
        }

        float Vec2::Magnitude() {
            return std::sqrt(x * x + y * y);
        }

        float Vec2::Distance(Vec2& other) {
            return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
        }
        Vec2 Vec2::UnitVector() {
            return *this * static_cast<float>(1.f / Magnitude()); 
        }
        
    } // namespace math
    

} // namespace simul
