#include <iostream>
#include "Base.h"

int main(void)
{
    Base *b(generate());
    identify(*b);
    identify(b);
    identify(NULL);
    delete b;
    return 0;
}
