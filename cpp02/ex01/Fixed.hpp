#ifndef FIXED_H
#define FIXED_H
#include <iostream>

class Fixed
{

public:
    Fixed(void);
    Fixed(const Fixed &);
    Fixed(int const);
    Fixed(float const);
    ~Fixed();

    Fixed &operator=(const Fixed &);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

private:
    int _fixedValue;
    static const int _fractBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &rhs);

#endif
