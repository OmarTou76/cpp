#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    Dog dog;
    std::cout << dog.getType() << std::endl;
    dog.makeSound();
    return 0;
}
