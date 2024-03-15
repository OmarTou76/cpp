#ifndef FIXED_H
#define FIXED_H
#include <iostream>

class Fixed
{
private:
    int _fixedValue;
    static const int _fractBits = 8;

public:
    Fixed(void);
    Fixed(const Fixed &);
    Fixed(int const);
    Fixed(float const);
    ~Fixed();

    Fixed &operator=(const Fixed &);
    Fixed operator+(const Fixed &);
    Fixed operator*(const Fixed &);
    Fixed operator-(const Fixed &);
    Fixed operator/(const Fixed &);

    Fixed &operator++(void);
    Fixed &operator--(void);
    Fixed operator++(int);
    Fixed operator--(int);

    bool operator>(const Fixed &) const;
    bool operator<(const Fixed &) const;
    bool operator>=(const Fixed &) const;
    bool operator<=(const Fixed &) const;
    bool operator==(const Fixed &) const;
    bool operator!=(const Fixed &) const;

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    static Fixed &min(Fixed &, Fixed &);
    static Fixed const &min(Fixed const &, Fixed const &);
    static Fixed &max(Fixed &, Fixed &);
    static Fixed const &max(Fixed const &, Fixed const &);
};

std::ostream &operator<<(std::ostream &out, const Fixed &rhs);

#endif