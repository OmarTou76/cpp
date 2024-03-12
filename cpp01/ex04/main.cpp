#include <iostream>
#include <fstream>
#include "Sed.hpp"

int isValidArgs(int argc, char const *argv[])
{
    if (argc != 4)
    {
        std::cout << "[USAGE]: <filename> <string_to_replace> <new_string>" << std::endl;
        return (0);
    }
    std::string str_to_replace = argv[2];
    if (str_to_replace.empty())
        return (0);
    return (1);
}

int main(int argc, char const *argv[])
{
    if (!isValidArgs(argc, argv))
        return 1;
    Sed sed = Sed(argv);
    sed.copyAndReplaceOcc();
    return 0;
}
