#include <iostream>
#include <gtest/gtest.h>

#include "../triangles.hpp"

TEST(Triangles, PointEqual) {
    Point<int> p1(1, 2, 1);
    Point<int> p2(1, 2, 1);

    ASSERT_EQ(p1, p2);
}