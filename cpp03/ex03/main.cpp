#include <iostream>
#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap c("John");
    c.takeDamage(6);
    c.attack("Doe");
    c.beRepaired(4);
    c.whoAmI();
    return 0;
}
