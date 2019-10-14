#include "figure.hpp"

void rotate(figure<point2d>& fig, point2d vertex, double phi) {
    for (auto& p : fig) {
        p = rotate_point2d(p, vertex, phi);
    }
}
