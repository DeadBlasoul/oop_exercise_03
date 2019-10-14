#include <point.hpp>
#include <figure.hpp>
#include <iostream>

int main() {
    rhombus r({ 0, 0 }, 1, 1);
    auto square = r.square();
    r.rotate(r.center(), CONST_PI / 4);
    if (square == r.square()) {
        std::cout << square << " " << r.square();
    }

    return 0;
}
