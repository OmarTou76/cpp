#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    this->_name = "No name";
    this->_hits = FragTrap::_hits;
    this->_energy = ScavTrap::_energy;
    this->_attackDamage = FragTrap::_attackDamage;
    this->ClapTrap::_name = this->_name + "_clap_name";
    std::cout << "Empty constructor init called from Diamond class" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    this->_name = name;
    this->_hits = FragTrap::_hits;
    this->_energy = ScavTrap::_energy;
    this->_attackDamage = FragTrap::_attackDamage;
    this->ClapTrap::_name = this->_name + "_clap_name";
    std::cout << "Constructor init with string as parameter from Diamond class" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &d) : ClapTrap(d), ScavTrap(d), FragTrap(d)
{
    this->_name = d._name;
    std::cout << "Constructor init with DiamondTrap reference from FragTrap class" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hits = rhs._hits;
        this->_energy = rhs._energy;
        this->_attackDamage = rhs._attackDamage;
        this->ClapTrap::_name = rhs.ClapTrap::_name;
    }
    std::cout << "Constructor init by assignation from DiamondTrap" << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Deconstructor of DiamondTrap" << std::endl;
}

void DiamondTrap::whoIam(void)
{
    std::cout << "Name of DiamondTrap: " << this->_name << " and ClapTrap name is: " << this->ClapTrap::_name << std::endl;
}