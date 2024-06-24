#include <iostream>
#include "easyfind.h"

int main(void)
{
    size_t size = 10;
    int target = 27;
    std::vector<int> values(size);

    for (size_t i = 0; i < size; i++)
        values[i] = i * 3;

    int index = easyfind(values, target);
    if (index > -1)
    {
        std::cout
            << values.at(index) << " was found in the container at index " << index << std::endl;
    }
    else
        std::cout << target << " was NOT found in the container !" << std::endl;
}
