#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
    std::cout << std::endl
              << std::endl;

    ClapTrap c("Omar");
    c.takeDamage(6);
    c.attack("weapons");
    c.beRepaired(4);

    std::cout << std::endl
              << std::endl;

    ClapTrap b;
    b.takeDamage(6);
    b.attack("weapons");
    b.beRepaired(4);

    std::cout << std::endl
              << std::endl;

    ClapTrap a = b;
    a.takeDamage(6);
    a.attack("weapons");
    a.beRepaired(4);

    std::cout << std::endl
              << std::endl;

    ClapTrap d(c);
    d.takeDamage(6);
    d.attack("weapons");
    d.beRepaired(4);

    std::cout << std::endl
              << std::endl;
    return 0;
}
