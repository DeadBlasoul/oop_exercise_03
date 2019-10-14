#include <figure.hpp>
#include <gtest/gtest.h>

#define TEST_SUIT_NAME Rotation

auto constexpr precision = 0.00000001;

TEST(TEST_SUIT_NAME, RhombusSquare) {
    rhombus fig({ 0, 0 }, 1, 1);
    auto square = fig.square();
    fig.rotate(fig.center(), CONST_PI / 4);
    ASSERT_TRUE(abs(square - fig.square()) < precision);
}

TEST(TEST_SUIT_NAME, PentagonSquare) {
    pentagon fig({ 0, 0 }, 1);
    auto square = fig.square();
    fig.rotate(fig.center(), CONST_PI / 4);
    ASSERT_TRUE(abs(square - fig.square()) < precision);
}

TEST(TEST_SUIT_NAME, HexagonSquare) {
    hexagon fig({ 0, 0 }, 1);
    auto square = fig.square();
    fig.rotate(fig.center(), CONST_PI / 4);
    ASSERT_TRUE(abs(square - fig.square()) < precision);
}
