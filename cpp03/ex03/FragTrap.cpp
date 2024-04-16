#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "Empty constructor init called fom FragTrap class" << std::endl;
    this->_name = "(No name)";
    this->_hits = 100;
    this->_energy = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Constructor init with string as parameter from FragTrap class" << std::endl;
    this->_name = name;
    this->_hits = 100;
    this->_energy = 100;
    this->_attackDamage = 30;
}
FragTrap::FragTrap(const FragTrap &c): ClapTrap()
{
    std::cout << "Constructor init with FragTrap reference from FragTrap class" << std::endl;
    *this = c;
}
FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
    std::cout << "Constructor init by assignation from FragTrap class" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hits = rhs._hits;
        this->_energy = rhs._energy;
        this->_attackDamage = rhs._attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor of FragTrap class" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " request for high fives"
              << std::endl;
}
