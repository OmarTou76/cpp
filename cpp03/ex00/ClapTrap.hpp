#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <iostream>

class ClapTrap
{
private:
    std::string _name;
    int _hits;
    int _energy;
    int _attackDamage;

public:
    ClapTrap();
    ClapTrap(std::string);
    ClapTrap(const ClapTrap &);
    ClapTrap &operator=(const ClapTrap &);
    ~ClapTrap();

    void attack(const std::string &target);
    void takeDamage(unsigned int amout);
    void beRepaired(unsigned int amout);
};

#endif
