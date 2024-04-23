#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    // Multiple animals
    int nAnimals = 20;
    int index = 0;
    const Animal *animals[20];
    for (; index < nAnimals; index++)
    {
        if (index % 2 == 0)
            animals[index] = new Dog();
        else
            animals[index] = new Cat();
    }

    for (int i = 0; i < nAnimals; i++)
        animals[i]->makeSound();

    for (int i = 0; i < nAnimals; i++)
        delete animals[i];

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    // Deep copy

    Cat cat;
    cat.addIdea("Eating", 10);
    std::cout << std::endl;
    Cat dCopy(cat);
    dCopy.addIdea("Sleeping", 1);
    cat.addIdea("Sleeping", 99);
    std::cout << std::endl;
    
    dCopy.displayIdeas();
    std::cout << std::endl;
    cat.displayIdeas();
    std::cout << std::endl;
    return 0;
}
