#ifndef FRAGTRAP_H
#define FRAGTRAP_H
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
private:
public:
    FragTrap();
    FragTrap(std::string);
    FragTrap(const FragTrap &);
    FragTrap &operator=(const FragTrap &);
    ~FragTrap();

    void highFivesGuys(void);
};

#endif