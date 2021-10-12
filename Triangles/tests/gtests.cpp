#include <iostream>
#include <gtest/gtest.h>
#include "../include/triangles.hpp"

TEST(Triangles, GetSquare) {
    Point<int> A(0, 0, 0);
    Point<int> B(3, 0, 0);
    Point<int> C(0, 4, 0);

    Triangle<int, Point<int>> t(A, B, C);
    
    ASSERT_EQ(t.GetSquare(), 6);
}