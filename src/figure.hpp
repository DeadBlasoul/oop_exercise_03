#pragma once

#include <utility>
#include <tuple>
#include <vector>
#include <iostream>

#include "point.hpp"

auto constexpr CONST_PI = 3.141592653589793238462643383279502884L;

template<typename _Point>
struct figure {
    using point         = _Point;
    using pointer       = point*;
    using const_pointer = const point*;

    using iterator       = pointer;
    using const_iterator = const_pointer;

    virtual void rotate(point vertex, double angle) = 0;

    /* Returns center of figure
        Has no overflow guard
    */
    virtual point center() const {
        constexpr size_t point_size = point::size();

        auto   begin = this->begin();
        auto   end   = this->end();
        size_t size  = this->size();

        point result = *begin;
        for (auto it = begin + 1; it < end; ++it) {
            for (size_t i = 0; i < point_size; ++i) {
                result[i] += (*it)[i];
            }
        }
        for (size_t i = 0; i < point_size; ++i) {
            result[i] /= size;
        }

        return result;
    }

    virtual double square() {
        auto constexpr x = 0;
        auto constexpr y = 1;

        auto begin = this->begin();
        auto end = this->end();

        double result = 0.0;

        for (auto it = begin + 1; it < end - 1; ++it) {
            result += (*it)[x] * ((*(it + 1))[y] - (*(it - 1))[y]);
        }
        auto first = begin;
        auto last = end - 1;
        result += (*first)[x] * ((*(first + 1))[y] - (*last)[y]);
        result += (*last)[x] * ((*first)[y] - (*(last - 1))[y]);
        result /= 2;

        return result;
    }

    virtual iterator begin() = 0;
    virtual const_iterator begin() const { return const_cast<figure&>(*this).begin(); }

    virtual iterator end() = 0;
    virtual const_iterator end() const { return const_cast<figure&>(*this).end(); }

    size_t size() const {
        return size_t(end() - begin());
    }
};

template<typename _Type>
std::ostream& operator<<(std::ostream& stream, const figure<_Type>& fig) {
    stream << "\"" << typeid(fig).name() << "\":{ ";
    for (const auto& p : fig) {
        stream << p << " ";
    }
    stream << "}";

    return stream;
}

template<typename _Type>
std::istream& operator>>(std::istream& stream, figure<_Type>& fig) {
    for (auto& p : fig) {
        stream >> p;
    }
    return stream;
}

// Examples:
void rotate(figure<point2d>& fig, point2d vertex, double phi);

struct rhombus final : public figure<point2d> {
    using point    = figure::point;
    using iterator = figure::iterator;

    point points[4];

    rhombus()
        : points{0}
    {}

    rhombus(point2d center, double horizontal, double vertical) {
        constexpr size_t x = 0;
        constexpr size_t y = 1;

        points[0] = { center[x], center[y] + vertical / 2 };
        points[1] = { center[x] - horizontal / 2, center[y] };
        points[2] = { center[x], center[y] - vertical / 2 };
        points[3] = { center[x] + horizontal / 2, center[y] };
    }

    void rotate(point vertex, double angle) override {
        ::rotate(*this, vertex, angle);
    }

    iterator begin() override {
        return &points[0];
    }

    iterator end() override {
        return &points[sizeof(points) / sizeof(*points)];
    }
};

std::istream& operator<<(std::istream& stream, rhombus& fig);

template<size_t _Num>
struct ngon final : figure<point2d> {
    using point = figure::point;
    using iterator = figure::iterator;

    point points[_Num];

    ngon()
        : points{ 0 }
    {}

    ngon(point center, double radius)
        : points{ 0 } {
        auto constexpr x = 0;
        auto constexpr y = 1;

        double angle = 0.0;
        double phi = (2 * CONST_PI) / _Num;

        for (auto& p : points) {
            p = rotate_point2d({ center[x], center[y] + radius }, center, angle);
            angle += phi;
        }
    }

    void rotate(point vertex, double angle) override {
        ::rotate(*this, vertex, angle);
    }

    iterator begin() override {
        return &points[0];
    }

    iterator end() override {
        return &points[sizeof(points) / sizeof(*points)];
    }
};

template<size_t _Num>
std::istream& operator>>(std::istream& stream, ngon<_Num>& fig) {
    double x, y, r;
    stream >> x >> y >> r;
    fig = ngon<_Num>({ x, y }, r);

    return stream;
}

using pentagon = ngon<5>;
using hexagon = ngon<6>;
