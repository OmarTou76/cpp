#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H
#include "contact.hpp"
#define MAX_CONTACTS 8

class Phonebook
{
public:
    Phonebook();
    ~Phonebook();
    void add(void);
    void search(void);

private:
    int _id;
    Contact _contact[MAX_CONTACTS];
    void _displayLine(bool);
    void _displayHeader(void);
    std::string _formatField(std::string);
    void _printField(std::string);
    void _displayGrid(void);
    void _displayContact(std::string);
    void _addField(std::string, std::string &);
};

#endif