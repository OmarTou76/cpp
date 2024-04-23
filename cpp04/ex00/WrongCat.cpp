#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat class: Constructor init without params" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    std::cout << "WrongCat class: Constructor init by copy" << std::endl;
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
    if (&rhs != this)
        this->WrongAnimal::_type = rhs.WrongAnimal::_type;
    std::cout << "WrongCat class: Constructor init by assignation" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat class: Destructor" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat class: Wrong miaou" << std::endl;
}