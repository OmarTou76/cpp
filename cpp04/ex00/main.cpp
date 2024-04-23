#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *k = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
    k->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete k;

    std::cout << std::endl << std::endl;

    const WrongAnimal *i = new WrongCat();
    std::cout << "Type is : "<< i->getType() << std::endl;
    i->makeSound();
    delete i;

    return 0;
}
