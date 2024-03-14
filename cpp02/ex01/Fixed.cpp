#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// CONSTRUCTORS

Fixed::Fixed(void) : _fixedValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &base)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = base;
}

Fixed::Fixed(int const nb)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedValue = nb << Fixed::_fractBits;
}

Fixed::Fixed(float const nb)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedValue = roundf(nb * (1 << Fixed::_fractBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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

// OPERATORS

Fixed &Fixed::operator=(const Fixed &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        this->_fixedValue = f.getRawBits();
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &rhs)
{
    out << rhs.toFloat();
    return out;
}