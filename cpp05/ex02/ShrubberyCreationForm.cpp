#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), _target("No-Name") {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) { *this = copy; }
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    if (this != &rhs)
        this->_target = rhs.getTarget();
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const { return this->_target; }

void ShrubberyCreationForm::execute(Bureaucrat const &b) const
{
    if (!this->isSigned())
        throw FormNotSignedException();
    else if (b.getGrade() > this->getGradeRequiredToExecute())
        throw GradeTooLowException();

    std::ofstream target(std::string(this->_target + "_shrubbery").c_str());
    this->writeAsciiTree(target);
    target.close();
}

void ShrubberyCreationForm::writeAsciiTree(std::ostream &file) const
{
    file << "                      ___"                 << std::endl;
    file << "                _,-'\"\"   \"\"\"\"`--."   << std::endl;
    file << "             ,-'          __,,-- \\"       << std::endl;
    file << "           ,\'    __,--\"\"\"\"dF      )"  << std::endl;
    file << "          /   .-\"Hb_,--\"\"dF      /"     << std::endl;
    file << "        ,\'       _Hb ___dF\"-._,-'"       << std::endl;
    file << "      ,'      _,-\"\"\"\"   \"\"--..__"    << std::endl;
    file << "     (     ,-'                  `."        << std::endl;
    file << "      `._,'     _   _             ;"       << std::endl;
    file << "       ,'     ,' `-'Hb-.___..._,-'"        << std::endl;
    file << "       \\    ,'\"Hb.-\'HH`-.dHF\""         << std::endl;
    file << "        `--\'   \"Hb  HH  dF\""            << std::endl;
    file << "                \"Hb HH dF"                << std::endl;
    file << "                 \"HbHHdF"                 << std::endl;
    file << "                  |HHHF"                   << std::endl;
    file << "                  |HHH|"                   << std::endl;
    file << "                  |HHH|"                   << std::endl;
    file << "                  |HHH|"                   << std::endl;
    file << "                  |HHH|"                   << std::endl;
    file << "                  dHHHb"                   << std::endl;
    file << "                .dFd|bHb.               o" << std::endl;
    file << "      o       .dHFdH|HbTHb.          o /"  << std::endl;
    file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
    file << "##########################################" << std::endl;
}
