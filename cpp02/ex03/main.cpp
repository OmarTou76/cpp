#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

void printResult(Point p, bool ret)
{
    std::cout << p << " is " << (ret ? "" : "not ") << "inside triangle " << (ret ? "    ✅" : "❌") << std::endl;
}

int main(void)
{
    Point a = Point(1, 1);
    Point b = Point(4, 5);
    Point c = Point(7, 2);
    Point p1 = Point(3, 4);
    Point p2 = Point(3, 2);
    Point p3 = Point(6, 2);
    Point p4 = Point(5, 4);
    Point p5 = Point(6, 1);

    printResult(p1, bsp(a, b, c, p1));
    printResult(p2, bsp(a, b, c, p2));
    printResult(p3, bsp(a, b, c, p3));
    printResult(p4, bsp(a, b, c, p4));
    printResult(p5, bsp(a, b, c, p5));
    return 0;
}
