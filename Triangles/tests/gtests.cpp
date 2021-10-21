#include <iostream>
#include <gtest/gtest.h>
#include "../include/triangles.hpp"

TEST(Triangles, GetSquare) {
    Point A(0, 0, 0);
    Point B(3, 0, 0);
    Point C(0, 4, 0);

    Triangle t(A, B, C);
    
    ASSERT_EQ(t.GetSquare(), 6);
}