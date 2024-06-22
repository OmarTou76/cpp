#include <iostream>
#include "Base.h"

int main(void)
{
    Base *b(generate());
    identify(*b);
    identify(b);
    delete b;
    return 0;
}
