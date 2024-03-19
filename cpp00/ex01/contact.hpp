#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H
#include <iostream>
class Contact
{

public:
    Contact(void);
    ~Contact(void);
    Contact(std::string, std::string, std::string, std::string, std::string);
    std::string getFirstName(void);
    std::string getLastName(void);
    std::string getNickname(void);
    void printContact(void);

private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darksetSecret;
};

#endif