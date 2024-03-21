#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("")
{
    std::cout << "AAnimal class: Constructor init without type" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
    std::cout << "AAnimal class: Constructor init with type " << this->_type << std::endl;
}
AAnimal::AAnimal(const AAnimal &copy)
{
    *this = copy;
    std::cout << "AAnimal class: Constructor init by copy with type " << this->_type << std::endl;
}
AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
    if (this != &rhs)
        this->_type = rhs._type;
    std::cout << "AAnimal class: Constructor init by assignation with type " << this->_type << std::endl;
    return (*this);
}
AAnimal::~AAnimal()
{
    std::cout << "AAnimal class: Deconstructor" << std::endl;
}

std::string AAnimal::getType(void) const
{
    return this->_type;
}

void AAnimal::makeSound(void) const
{
    std::cout << "AAnimal sound" << std::endl;
}
