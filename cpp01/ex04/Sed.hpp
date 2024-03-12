#ifndef SED_H
#define SED_H
#include <fstream>
#include <iostream>

class Sed {

    private:
        std::string _filename;
        std::string _output;
        std::string _strToReplace;
        std::string _newString;
        std::string _replaceOcc(std::string&);

    public:
        Sed(char const *argv[]);
        void copyAndReplaceOcc(void);
};
#endif
