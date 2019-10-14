#pragma once

#include <cstddef>
#include <cassert>
#include <cmath>

template<typename _Type, size_t _Dimensions>
struct point {
    static_assert(_Dimensions != 0, "can not create 0d point");

    using type            = _Type;
    using reference       = type&;
    using const_reference = const type&;
    using pointer         = type*;
    using const_pointer   = const type*;

    using iterator       = pointer;
    using const_iterator = const_pointer;

    type dots[_Dimensions];

    type& operator[](size_t ix) noexcept {
        return dots[ix];
    }

    const type& operator[](size_t ix) const noexcept {
        return const_cast<point&>(*this).operator[](ix);
    }

    iterator begin() noexcept {
        return &dots[0];
    }
    
    const_iterator begin() const noexcept {
        return const_cast<point&>(*this).begin();
    }

    iterator end() noexcept {
        return &dots[_Dimensions];
    }

    const_iterator end() const noexcept {
        return const_cast<point&>(*this).end();
    }

    static constexpr size_t size() noexcept {
        return _Dimensions;
    }

    point operator+(const point& other) {
        point result = *this;

        for (size_t i = 0; i < result.size(); i++) {
            result[i] += other[i];
        }

        return result;
    }

    point operator-(const point& other) {
        point result = *this;

        for (size_t i = 0; i < result.size(); i++) {
            result[i] -= other[i];
        }

        return result;
    }
};

// Examples:
using point2d = point<double, 2>;

point2d rotate_point2d(point2d p, point2d vertex, double phi);