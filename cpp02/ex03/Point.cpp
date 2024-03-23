#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}
Point::Point(float const x, float const y) : _x(x), _y(y) {}
Point::Point(const Point &p) : _x(p.getX()), _y(p.getY()) {}
Point::~Point() {}

Point &Point::operator=(const Point &rhs)
{
    if (this != &rhs)
    {
        (Fixed) this->_x = rhs.getX();
        (Fixed) this->_y = rhs.getY();
    }
    return *this;
}

Fixed Point::getX() const
{
    return this->_x;
}

Fixed Point::getY() const
{
    return this->_y;
}

int Point::getXToInt() const
{
    return this->_x.toInt();
}

int Point::getYToInt() const
{
    return this->_y.toInt();
}

int Point::getSumOfXY() const
{
    return this->getXToInt() * this->getYToInt();
}

std::ostream &operator<<(std::ostream &out, Point const &rhs)
{
    out << "(" << rhs.getXToInt() << ", " << rhs.getYToInt() << ")";
    return out;
}