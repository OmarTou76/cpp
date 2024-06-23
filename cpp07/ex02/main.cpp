#include <iostream>
#include "Array.h"

int main(void)
{
    Array<int> arr(3);
    for (size_t i = 0; i < arr.size(); i++)
        arr[i] = i + 45;

    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << std::endl;

    std::cout << std::endl;
    Array<std::string> strs(4);
    strs[0] = "Hello";
    strs[1] = "world";
    strs[2] = "from";
    strs[3] = "42";

    for (size_t i = 0; i < strs.size(); i++)
        std::cout << strs[i] << std::endl;

    std::cout << std::endl
              << "Copy ->" << std::endl
              << std::endl;
    Array<std::string> copy = strs;

    for (size_t i = 0; i < strs.size(); i++)
        std::cout << strs[i] << std::endl;

    try
    {
        std::cout << strs[strs.size() * 2] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}