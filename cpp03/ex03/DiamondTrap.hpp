#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string _name;

public:
};

#endif