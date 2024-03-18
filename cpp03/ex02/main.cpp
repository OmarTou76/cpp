#include <iostream>
#include "FragTrap.hpp"

int main(void)
{
    std::cout << std::endl
              << std::endl;

    FragTrap c("Omar");
    c.takeDamage(6);
    c.attack("weapons");
    c.beRepaired(4);
    c.highFivesGuys();

    std::cout << std::endl
              << std::endl;

    FragTrap b;
    b.takeDamage(6);
    b.attack("weapons");
    b.beRepaired(4);
    b.highFivesGuys();
    std::cout << std::endl
              << std::endl;

    FragTrap a = b;
    a.takeDamage(6);
    a.attack("weapons");
    a.beRepaired(4);
    a.highFivesGuys();
    std::cout << std::endl
              << std::endl;

    FragTrap d(c);
    d.takeDamage(6);
    d.attack("weapons");
    d.beRepaired(4);
    d.highFivesGuys();
    std::cout << std::endl
              << std::endl;
    return 0;
}
