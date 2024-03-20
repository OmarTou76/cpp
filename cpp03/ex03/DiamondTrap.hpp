#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string _name;

public:
    DiamondTrap();
    DiamondTrap(std::string);
    DiamondTrap(DiamondTrap const &);
    DiamondTrap &operator=(const DiamondTrap &rhs);
    ~DiamondTrap();

    using ScavTrap::attack;
    void whoIam(void);
};

#endif