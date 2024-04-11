#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap c("John");
    c.attack("Doe");
    c.takeDamage(5);
    c.takeDamage(2);
    c.beRepaired(4);
    c.attack("TesT");
    return 0;
}
