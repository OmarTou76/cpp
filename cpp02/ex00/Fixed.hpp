#ifndef FIXED_H
#define FIXED_H

class Fixed
{

public:
    Fixed(void);
    Fixed(const Fixed &);
    ~Fixed();
    Fixed &operator=(const Fixed &);
    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int _nb;
    static const int _nbBits = 8;
};

#endif
