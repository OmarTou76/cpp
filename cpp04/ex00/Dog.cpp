#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog class: Constructor init without params" << std::endl;
}
Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog class: Constructor init by copy" << std::endl;
}
Dog &Dog::operator=(const Dog &rhs)
{
    if (&rhs != this)
        this->Animal::_type = rhs.Animal::_type;
    std::cout << "Dog class: Constructor init by assignation" << std::endl;
    return *this;
}
Dog::~Dog()
{
    std::cout << "Dog class: Deconstructor" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Dog sound: Miaou !" << std::endl;
}