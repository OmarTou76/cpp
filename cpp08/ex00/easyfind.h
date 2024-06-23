#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
int easyfind(T container, int target)
{
    typename T::const_iterator found = std::find(container.begin(), container.end(), target);
    if (found != container.end())
    {
        int index = std::distance<typename T::const_iterator>(container.begin(), found);
        return index;
    }
    return -1;
}