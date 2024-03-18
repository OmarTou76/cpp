#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("(No name)"), _hits(10), _energy(10), _attackDamage(0)
{
    std::cout << "Empty constructor init called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hits(10), _energy(10), _attackDamage(0)
{
    std::cout << "Constructor init with string as parameter" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &c)
{
    std::cout << "Constructor init with ClapTrap reference" << std::endl;
    *this = c;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
    std::cout << "Constructor init by assignation" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hits = rhs._hits;
        this->_energy = rhs._energy;
        this->_attackDamage = rhs._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Deconstructor of ClapTrap" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (!this->_energy)
        return;
    std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
    this->_energy--;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->_energy)
        return;
    this->_hits += amount;
    std::cout << "ClapTrap " << this->_name << " repaired " << amount << " hits points, still " << this->_hits << " hits points." << std::endl;
    this->_energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hits -= amount;
    if (this->_hits < 0)
        this->_hits = 0;
    std::cout << "ClapTrap " << this->_name << " take " << amount
              << " damages, still " << this->_hits << " hits points" << std::endl;
}
