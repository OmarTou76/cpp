#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat class: Constructor init without params" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    std::cout << "WrongCat class: Constructor init by copy" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
    if (&rhs != this)
        this->WrongAnimal::_type = rhs.WrongAnimal::_type;
    std::cout << "WrongCat class: Constructor init by assignation" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {}