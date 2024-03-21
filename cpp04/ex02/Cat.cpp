#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), _brain(new Brain())
{
    std::cout << "Cat class: Constructor init without params" << std::endl;
}
Cat::Cat(const Cat &copy) : AAnimal()
{
    *this = copy;
    std::cout << "Cat class: Constructor init by copy" << std::endl;
}
Cat &Cat::operator=(const Cat &rhs)
{
    if (&rhs != this)
    {
        this->_type = rhs.getType();
        this->_brain = new Brain(*rhs._brain);
    }
    std::cout << "Cat class: Constructor init by assignation" << std::endl;
    return *this;
}
Cat::~Cat()
{
    std::cout << "Cat class: Deconstructor" << std::endl;
    delete this->_brain;
}

void Cat::makeSound(void) const
{
    std::cout << "Cat sound: Miaou !" << std::endl;
}

void Cat::addIdea(std::string idea, unsigned int index)
{
    this->_brain->appendIdea(idea, index);
}

void Cat::displayIdeas()
{
    this->_brain->showIdeas();
}