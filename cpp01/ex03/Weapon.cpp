#include "Weapon.hpp"

Weapon::Weapon(void) {}
Weapon::Weapon(std::string type): _type(type) {}
Weapon::~Weapon() {}

void Weapon::setType(std::string newType)
{
    this->_type = newType;
}

std::string const &Weapon::getType(void)
{
    return this->_type;
}

