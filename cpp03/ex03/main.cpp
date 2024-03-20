#include <iostream>
#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << std::endl
              << std::endl;

    DiamondTrap c("Omar");
    c.takeDamage(6);
    c.attack("weapons");
    c.beRepaired(4);
    c.whoAmI();
    std::cout << std::endl
              << std::endl;

    DiamondTrap b;
    b.takeDamage(6);
    b.attack("weapons");
    b.beRepaired(4);
    b.whoAmI();
    std::cout << std::endl
              << std::endl;

    DiamondTrap a = b;
    a.takeDamage(6);
    a.attack("weapons");
    a.beRepaired(4);
    a.whoAmI();
    std::cout
        << std::endl
        << std::endl;

    DiamondTrap d(c);
    d.takeDamage(6);
    d.attack("weapons");
    d.beRepaired(4);
    d.whoAmI();
    std::cout << std::endl
              << std::endl;
    return 0;
}
