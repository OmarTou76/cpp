#ifndef CAT_H
#define CAT_H
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *_brain;

public:
    Cat();
    Cat(const Cat &);
    Cat &operator=(const Cat &);
    ~Cat();

    virtual void makeSound(void) const;
    void addIdea(std::string, unsigned int);
    void displayIdeas();
};

#endif