#include "figure.hpp"

void rotate(figure<point2d>& fig, point2d vertex, double phi) {
    for (auto& p : fig) {
        p = rotate_point2d(p, vertex, phi);
    }
}

std::istream& operator>>(std::istream& stream, rhombus& fig) {
    double x, y, h, v;
    stream >> x >> y >> h >> v;
    fig = rhombus({ x, y }, h, v);

    return stream;
}
