
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name): _weapon(NULL), _name(name) {}
HumanB::~HumanB() {}
 
void HumanB::attack(void) {
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &w) 
{
    this->_weapon = &w;
}
