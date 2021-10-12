#define CATCH_CONFIG_MAIN
#include <iostream>

#include "catch.hpp"
#include "../include/triangles.hpp"

TEST_CASE("Squares are computed", "[Square]")
{
    Point<int> A(0, 0, 0);
    Point<int> B(3, 0, 0);
    Point<int> C(0, 4, 0);

    Triangle<int, Point<int>> t(A, B, C);

    REQUIRE(t.GetSquare() == 6);
}

TEST_CASE("Perimeter is computed", "[Perimeter]")
{
    Point<int> A(0, 0, 0);
    Point<int> B(3, 0, 0);
    Point<int> C(0, 4, 0);

    Triangle<int, Point<int>> t(A, B, C);

    REQUIRE(t.GetP() == 12);
}