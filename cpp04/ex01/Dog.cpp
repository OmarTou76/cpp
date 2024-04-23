#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
    std::cout << "Dog class: Constructor init without params" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    this->_brain = new Brain();
    *this = copy;
    std::cout << "Dog class: Constructor init by copy" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
    if (&rhs != this)
    {
        this->_type = rhs.getType();
        this->_brain = new Brain(*rhs._brain);
    }
    std::cout << "Dog class: Constructor init by assignation" << std::endl;
    return *this;
}
Dog::~Dog()
{
    std::cout << "Dog class: Destructor" << std::endl;
    delete this->_brain;
}

void Dog::makeSound(void) const
{
    std::cout << "Dog sound: Waff !" << std::endl;
}