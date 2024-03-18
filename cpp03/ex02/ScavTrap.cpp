#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Empty constructor init called fom ScavTrap class" << std::endl;
    this->_name = "(No name)";
    this->_hits = 100;
    this->_energy = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "Constructor init with string as parameter from ScapTrap class" << std::endl;
    this->_name = name;
    this->_hits = 100;
    this->_energy = 50;
    this->_attackDamage = 20;
}
ScavTrap::ScavTrap(const ScavTrap &c)
{
    std::cout << "Constructor init with ScavTrap reference from ScavTrap class" << std::endl;
    *this = c;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
    std::cout << "Constructor init by assignation from ScavTrap class" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hits = rhs._hits;
        this->_energy = rhs._energy;
        this->_attackDamage = rhs._attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Deconstructor of ScavTrap class" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (!this->_energy)
        return;
    std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage (from ScavTrap class)" << std::endl;
    this->_energy--;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->_name << " is now in Gtae keeper mode."
              << std::endl;
}
