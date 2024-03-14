#include "Fixed.hpp"
#include <cmath>

// CONSTUCTORS

Fixed::Fixed(void) : _fixedValue(0) {}

Fixed::Fixed(const Fixed &f) { *this = f; }

Fixed::Fixed(int const nb)
{
    this->_fixedValue = nb << Fixed::_fractBits;
}

Fixed::Fixed(float const nb)
{
    this->_fixedValue = roundf(nb * (1 << Fixed::_fractBits));
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    if (&rhs != this)
        this->_fixedValue = rhs.getRawBits();
    return *this;
}

// FUNCTIONS

int Fixed::getRawBits(void) const
{
    return this->_fixedValue;
}
void Fixed::setRawBits(int const raw)
{
    this->_fixedValue = raw;
}
float Fixed::toFloat(void) const
{
    return (float)this->_fixedValue / (float)(1 << Fixed::_fractBits);
}
int Fixed::toInt(void) const
{
    return this->_fixedValue >> Fixed::_fractBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a < b ? b : a);
}
Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    return (a < b ? b : a);
}

// OPERATORS

std::ostream &operator<<(std::ostream &out, const Fixed &rhs)
{
    out << rhs.toFloat();
    return out;
}

// COMPARE

bool Fixed::operator>(const Fixed &rhs) const
{
    return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return (this->getRawBits() != rhs.getRawBits());
}

// ARITHMETIC

Fixed Fixed::operator+(const Fixed &rhs)
{
    return Fixed(this->_fixedValue + rhs.getRawBits());
}

Fixed Fixed::operator-(const Fixed &rhs)
{
    return Fixed(this->_fixedValue - rhs.getRawBits());
}

Fixed Fixed::operator*(const Fixed &rhs)
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs)
{
    return Fixed(this->_fixedValue / rhs.getRawBits());
}

// INCREMENT DECREMENT OPERATORS

Fixed &Fixed::operator++(void)
{
    this->_fixedValue++;
    return *this;
}

Fixed &Fixed::operator--(void)
{
    this->_fixedValue--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->_fixedValue++;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->_fixedValue--;
    return tmp;
}
