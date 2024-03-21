#ifndef BRAIN_H
#define BRAIN_H
#include <iostream>

class Brain
{
private:
    std::string _ideas[100];

public:
    Brain();
    Brain(const Brain &);
    Brain &operator=(const Brain &);
    ~Brain();

    void showIdeas(void);
    void appendIdea(std::string &idea, unsigned int index);
};

#endif