#include "Point.hpp"
#include <iostream>

// Example: a(0,0) b(4,0) c(2,4) |  p(2,1)
// [FORMULA] (x2-x1) | (y-y1) - (x-x1) | (y2-y1)
// [AB] = (4 - 0) | (1 - 0) - (2 - 0) | (0 - 0) = (4, 1)-(2, 0) = 4*1 - 2 * 0
// [BC] = (2 - 4) | (1 - 0) - (2 - 4) | (4 - 0) = (-2, 1) - (-2, 4)
// [CA] = (0 - 2) | (1 - 4) - (2 - 2) | (0 - 4) = (-2, -3) - (0, -4)

int computeDoubleTriangleArea(Point const A, Point const B, Point const P)
{
    Point vec1 = Point(B.getXToInt() - A.getXToInt(), P.getYToInt() - A.getYToInt());
    Point vec2 = Point(P.getXToInt() - A.getXToInt(), B.getYToInt() - A.getYToInt());
    return vec1.getSumOfXY() - vec2.getSumOfXY();
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    int cp1 = computeDoubleTriangleArea(a, b, point);
    int cp2 = computeDoubleTriangleArea(b, c, point);
    int cp3 = computeDoubleTriangleArea(c, a, point);

    if ((cp1 > 0 && cp2 > 0 && cp3 > 0) || (cp1 < 0 && cp2 < 0 && cp3 < 0))
        return true;

    return false;
}
