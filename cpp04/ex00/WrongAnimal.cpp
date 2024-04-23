#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "WrongAnimal class: Constructor init without type" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal class: Constructor init with type " << this->_type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    *this = copy;
    std::cout << "WrongAnimal class: Constructor init by copy with type " << this->_type << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    std::cout << "WrongAnimal class: Constructor init by assignation with type " << this->_type << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal class: Destructor" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return this->_type;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "Wrong Animal sound" << std::endl;
}
