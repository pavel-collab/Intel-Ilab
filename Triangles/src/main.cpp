#include <iostream>
#include "triangles.hpp"

int main() {

    std::cout << "Start of program\n";

    Point<int> A(0, 0, 0);
    Point<int> B(3, 0, 0);
    Point<int> C(0, 4, 0);

    Triangle<int, Point<int>> t(A, B, C);

    std::cout << "P = " << t.GetP() << std::endl;
    std::cout << "S = " << t.GetSquare() << std::endl;

    return 0;
}