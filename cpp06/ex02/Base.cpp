#include "Base.h"

Base::~Base() {}

Base *generate(void)
{
    std::srand(time(0));
    int rand = std::rand() % 3;
    Base *ret;
    switch (rand)
    {
    case 0:
        ret = new A();
        break;
    case 1:
        ret = new B();
        break;
    case 2:
        ret = new C();
        break;
    }
    return ret;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}
void identify(Base &p)
{
    try
    {
        if (dynamic_cast<A *>(&p))
            std::cout << "A" << std::endl;
        else if (dynamic_cast<B *>(&p))
            std::cout << "B" << std::endl;
        else if (dynamic_cast<C *>(&p))
            std::cout << "C" << std::endl;
    }
    catch (const std::bad_cast &e)
    {
        std::cerr << e.what() << std::endl;
    }
}