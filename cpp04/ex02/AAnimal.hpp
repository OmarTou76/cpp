#ifndef AAAnimal_H
#define AAAnimal_H
#include <iostream>

class AAnimal
{
protected:
    std::string _type;

public:
    AAnimal();
    AAnimal(std::string);
    AAnimal(const AAnimal &);
    AAnimal &operator=(const AAnimal &);
    virtual ~AAnimal();

    std::string getType(void) const;

    virtual void makeSound(void) const = 0;
};

#endif