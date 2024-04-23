#include "Brain.hpp"

Brain::Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Brain constructor by copy called" << std::endl;
    *this = copy;
}

Brain &Brain::operator=(const Brain &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = rhs._ideas[i];
    }
    std::cout << "Brain constructor by assignation called" << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

void Brain::showIdeas(void)
{
    for (int i = 0; i < 100; i++)
    {
        if (!this->_ideas[i].empty())
            std::cout << i << ": " << this->_ideas[i] << std::endl;
    }
}

void Brain::appendIdea(std::string &idea, unsigned int index)
{
    if (index >= 100)
        return;
    this->_ideas[index] = idea;
}