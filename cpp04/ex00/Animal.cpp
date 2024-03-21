#include "Animal.hpp"

Animal::Animal() : _type("")
{
    std::cout << "Animal class: Constructor init without type" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal class: Constructor init with type " << this->_type << std::endl;
}
Animal::Animal(const Animal &copy)
{
    *this = copy;
    std::cout << "Animal class: Constructor init by copy with type " << this->_type << std::endl;
}
Animal &Animal::operator=(const Animal &rhs)
{
    if (this != &rhs)
        this->_type = rhs._type;
    std::cout << "Animal class: Constructor init by assignation with type " << this->_type << std::endl;
    return (*this);
}
Animal::~Animal()
{
    std::cout << "Animal class: Deconstructor" << std::endl;
}

std::string Animal::getType(void) const
{
    return this->_type;
}

void Animal::makeSound(void) const
{
    std::cout << "Animal sound" << std::endl;
}
