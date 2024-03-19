#include "contact.hpp"
#include <iostream>

Contact::Contact(void) {}
Contact::~Contact(void) {}
Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darksetSecret) : _firstName(firstName), _lastName(lastName), _nickname(nickname), _phoneNumber(phoneNumber), _darksetSecret(darksetSecret) {}


void Contact::printContact(void)
{
    std::cout << "First name: " << this->_firstName << std::endl;
    std::cout << "Last name: " << this->_lastName << std::endl;
    std::cout << "Nickname: " << this->_nickname << std::endl;
    std::cout << "Phone number: " << this->_phoneNumber << std::endl;
    std::cout << "Darkset secret: " << this->_darksetSecret << std::endl;
}

std::string Contact::getFirstName(void)
{
    return this->_firstName;
}

std::string Contact::getLastName(void)
{
    return this->_lastName;
}

std::string Contact::getNickname(void)
{
    return this->_nickname;
}
