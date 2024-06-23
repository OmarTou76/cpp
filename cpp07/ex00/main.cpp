#include <iostream>
#include "whatever.h"

int main(void)
{
    std::string a("Hello ");
    std::string b("World ");
    std::cout << a << b << std::endl;
    swap(a, b);
    std::cout << a << b << std::endl
              << std::endl;

    int first = 42;
    int second = 21;
    std::cout << "Greatest -> " << max(first, second) << std::endl;
    std::cout << "Smallest -> " << min(first, second) << std::endl;
    return 0;
}