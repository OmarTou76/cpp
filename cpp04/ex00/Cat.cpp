#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat class: Constructor init without params" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Cat class: Constructor init by copy" << std::endl;
    *this = copy;
}

Cat &Cat::operator=(const Cat &rhs)
{
    if (&rhs != this)
        this->Animal::_type = rhs.Animal::_type;
    std::cout << "Cat class: Constructor init by assignation" << std::endl;
    return *this;
}

Cat::~Cat() 
{
    std::cout << "Dog class: Destructor" << std::endl;
}


void Cat::makeSound(void) const
{
    std::cout << "Cat sound: Miaou !" << std::endl;
}