#include "Zombie.hpp"
Zombie::Zombie(void) {}

Zombie::Zombie(std::string zombieName): _name(zombieName) {}

Zombie::~Zombie(void) {
    std::cout << "Destructor: " << this->_name << std::endl;
}

void Zombie::annonce(void)
{
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}