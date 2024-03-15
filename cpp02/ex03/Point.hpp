#ifndef POINT_H
#define POINT_H
#include <iostream>
#include "Fixed.hpp"

class Point
{
private:
    Fixed const _x;
    Fixed const _y;

public:
    Point();
    Point(float const, float const);
    Point(const Point &);
    Point &operator=(const Point &);
    ~Point();

    Fixed getX() const;
    Fixed getY() const;
    int getXToInt() const;
    int getYToInt() const;
    int getSumOfXY() const;
};

std::ostream &operator<<(std::ostream &out, Point const &rhs);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
