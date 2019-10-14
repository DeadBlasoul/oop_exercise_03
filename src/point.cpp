#include "point.hpp"

point2d rotate_point2d(point2d p, point2d vertex, double phi) {
    auto constexpr x = 0;
    auto constexpr y = 1;

    point2d vector = p - vertex;
    vector = {
        vector[x] * std::cos(phi) - vector[y] * std::sin(phi),
        vector[x] * std::sin(phi) + vector[y] * std::cos(phi)
    };

    return vector + vertex;
}
