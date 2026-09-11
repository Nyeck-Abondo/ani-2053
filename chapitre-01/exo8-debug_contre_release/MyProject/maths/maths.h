#include <cmath>
#include <ostream>

namespace simul {
    namespace math {
        
        struct Vec2 {
            float x, y;
            
            Vec2 operator=(Vec2& other) {
                x = other.x;
                y = other.y;
                return *this;
            }

            Vec2 operator/(Vec2& other) {
                x /= other.x;
                y /= other.y;
                return *this;
            }

            Vec2 operator*(float scalar) {
                x *= scalar;
                y *= scalar;
                return *this;
            }

            Vec2 operator+(Vec2& other) {
                return {other.x + x, other.y + y};
            }

            Vec2 operator+=(Vec2& other) {
                return {other.x + x, other.y + y};
            }

            Vec2 operator-(Vec2& other) {
                return {x - other.x, y - other.y};
            }

            friend std::ostream& operator<<(std::ostream& os, const Vec2& v);

            float Magnitude();
            float DotProduct(Vec2& other);
            float Distance(Vec2& other);
            Vec2 UnitVector();
        };

    } // namespace math
    
} // namespace simul
