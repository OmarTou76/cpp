#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const WrongAnimal *i = new WrongCat();
    const Animal *k = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
    k->makeSound();
    i->makeSound();
    meta->makeSound();
    return 0;
}
