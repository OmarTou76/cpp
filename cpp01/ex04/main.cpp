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

void copyFile(char const *argv) 
{ 
    std::string filename = argv;
    std::string output =  filename + std::string(".replace");
    std::ifstream file(argv);
    std::ofstream copy(output.c_str());
    std::string read;
    while (std::getline(file, read))
        copy << read << std::endl;

    file.close();
    copy.close();
}

int main(int argc, char const *argv[])
{
    if (!isValidArgs(argc, argv))
        return 1;
    Sed sed = Sed(argv);
    sed.copyAndReplaceOcc();
    return 0;
}
