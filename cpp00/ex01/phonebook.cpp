#include "phonebook.hpp"
#include <iomanip>
#include <iostream>
#include <string>

Phonebook::~Phonebook(void)
{
}

Phonebook::Phonebook(void)
{
	this->_id = 0;
}

void Phonebook::_addField(std::string label, std::string &field)
{
	while (field.empty())
	{
		std::cout << label;
		std::getline(std::cin, field);
	}
}

void Phonebook::add(void)
{
	std::string firstName, lastName, nickname, phoneNumber, darksetSecret;
	std::cout << "ADD CONTACT" << std::endl << std::endl;
	this->_addField("First name: ", firstName);
	this->_addField("Last name: ", lastName);
	this->_addField("Nickname: ", nickname);
	this->_addField("Phone number: ", phoneNumber);
	this->_addField("Darkset secret: ", darksetSecret);
	std::cout << std::endl;
	this->_contact[this->_id++ % MAX_CONTACTS] = Contact(firstName, lastName,
			nickname, phoneNumber, darksetSecret);
}

void Phonebook::_displayLine(bool withSeparator)
{
	if (withSeparator)
		std::cout << "|__________|__________|__________|__________|" << std::endl;
	else
		std::cout << "_____________________________________________" << std::endl;
}

void Phonebook::_displayHeader(void)
{
	this->_displayLine(false);
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	this->_displayLine(true);
}

std::string Phonebook::_formatField(std::string field)
{
	int	size;

	size = field.size();
	if (size > 10)
	{
		field.resize(9);
		field.append(".");
		return (field);
	}
	return (field);
}

void Phonebook::_printField(std::string field)
{
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << field;
}

void Phonebook::_displayGrid(void)
{
	this->_displayHeader();
	for (int i = 0; i < this->_id && i < MAX_CONTACTS; i++)
	{
		std::string index;
		index.push_back(i + '0');
		this->_printField(index);
		this->_printField(this->_formatField(this->_contact[i].getFirstName()));
		this->_printField(this->_formatField(this->_contact[i].getLastName()));
		this->_printField(this->_formatField(this->_contact[i].getNickname()));
		std::cout << "|" << std::endl;
		this->_displayLine(true);
	}
	std::cout << std::endl;
}

void Phonebook::_displayContact(std::string query)
{
	int	index;

	try
	{
		index = query[0] - '0';
		if (query.length() > 1 || (query[0] < '0' && query[0] > '7')
			|| index >= this->_id)
			throw std::out_of_range("Invalid index");
		this->_contact[index].printContact();
	}
	catch (const std::out_of_range &)
	{
		std::cout << "Invalid index" << std::endl;
	}
	catch (...)
	{
		std::cout << "Invalid input" << std::endl;
	}
}

void Phonebook::search(void)
{
	std::string query;
	this->_displayGrid();
	std::cout << "SELECT INDEX TO DISPLAY: ";
	std::getline(std::cin, query);
	this->_displayContact(query);
}