#include "Sed.hpp"


Sed::Sed(char const *argv[])
{
    this->_filename = std::string(argv[1]);
    this->_output = this->_filename + std::string(".replace");
    this->_strToReplace = std::string(argv[2]);
    this->_newString = std::string(argv[3]);
}

Sed::~Sed() {}

std::string Sed::_replaceOcc(std::string &line)
{
    std::size_t found;
    found = line.find(this->_strToReplace);
    if (this->_strToReplace.empty())
        return line;
    while  (found != std::string::npos)
    {
        line = line.substr(0, found) + this->_newString + line.substr(found + this->_strToReplace.length());
        found = line.find(this->_strToReplace);
    }
    return line;
}

void Sed::copyAndReplaceOcc(void)
{
    std::string line;
    std::ifstream input(this->_filename.c_str());
    if (input.fail())
    {
        std::cout << "Impossible to open file: " << this->_filename << std::endl;
        return;
    }
    std::ofstream output(this->_output.c_str());
    if (output.fail())
    {
        std::cout << "Impossible to open file: " << this->_output << std::endl;
        return;
    }
    while (std::getline(input, line))
        output << this->_replaceOcc(line) << std::endl;

    input.close();
    output.close();
}
