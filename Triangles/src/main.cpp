#include <iostream>
#include "../include/triangles.hpp"

int main() {

    std::cout << "Start of program\n";

    Point A(0, 0, 0);
    Point B(3, 0, 0);
    Point C(0, 4, 0);

    Triangle t(A, B, C);

    std::cout << "P = " << t.GetP() << std::endl;
    std::cout << "S = " << t.GetSquare() << std::endl;

    return 0;
}