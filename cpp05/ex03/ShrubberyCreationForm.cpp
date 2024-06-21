#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

// Constructeurs et destructeur
ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery", 145, 137), _target("No-Name") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("Shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) 
    : AForm(copy) {
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs); // Copier les parties de la classe de base
        this->_target = rhs.getTarget();
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Getter
std::string ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

// Méthodes
void ShrubberyCreationForm::execute(Bureaucrat const &b) const {
    if (!this->isSigned())
        throw FormNotSignedException();
    else if (b.getGrade() > this->getGradeRequiredToExecute())
        throw GradeTooLowException();

    std::string filename = this->_target + "_shrubbery"; 
    std::ofstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }
    this->writeAsciiTree(file);
    file.close();
}

void ShrubberyCreationForm::writeAsciiTree(std::ostream &file) const {
    file << "                      ___" << std::endl;
    file << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
    file << "             ,-'          __,,-- \\" << std::endl;
    file << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
    file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
    file << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
    file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
    file << "     (     ,-'                  `." << std::endl;
    file << "      `._,'     _   _             ;" << std::endl;
    file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
    file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
    file << "        `--\'   \"Hb  HH  dF\"" << std::endl;
    file << "                \"Hb HH dF" << std::endl;
    file << "                 \"HbHHdF" << std::endl;
    file << "                  |HHHF" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  dHHHb" << std::endl;
    file << "                .dFd|bHb.               o" << std::endl;
    file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
    file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
    file << "##########################################" << std::endl;
}

