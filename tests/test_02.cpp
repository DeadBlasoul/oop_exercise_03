#include <figure.hpp>
#include <gtest/gtest.h>

#define TEST_SUIT_NAME Generalized

auto constexpr precision = 0.00000001;

using figure2d = figure<point2d>;

TEST(TEST_SUIT_NAME, Indetification) {
    figure2d* fig1 = new hexagon;
    figure2d* fig2 = new pentagon;
    ASSERT_TRUE(strcmp(typeid(*fig1).name(), typeid(*fig2).name()));

    figure2d* fig3 = new rhombus;
    figure2d* fig4 = new rhombus;
    ASSERT_TRUE(!strcmp(typeid(*fig3).name(), typeid(*fig4).name()));

    delete fig1;
    delete fig2;
    delete fig3;
    delete fig4;
}
