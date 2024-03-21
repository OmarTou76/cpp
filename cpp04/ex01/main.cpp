#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
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

    Cat *cat = new Cat();
    cat->addIdea("Eating", 10);
    Cat *dCopy = new Cat(*cat);
    dCopy->addIdea("Sleeping", 1);
    cat->addIdea("Sleeping", 99);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    dCopy->displayIdeas();
    cat->displayIdeas();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    delete cat;
    delete dCopy;
    return 0;
}
