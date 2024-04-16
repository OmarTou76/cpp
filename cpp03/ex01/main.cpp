#include <iostream>
#include "ScavTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap c("John");
    c.takeDamage(6);
    c.attack("Doe");
    c.beRepaired(4);
    c.guardGate();
}
