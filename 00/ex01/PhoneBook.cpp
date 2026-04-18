#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->count = 0;
	this->nextIndex = 0;
}

void PhoneBook::addContact(Contact *contact)
{
	this->contacts[this->nextIndex] = *contact;
	if(this->count < 8)
		this->count++;
	this->nextIndex = (this->nextIndex + 1) % 8;
}

static std::string format_column(std::string str)
{
	if(str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::searchContact() const
{
	int i;
	int index;
	std::string input;

	if(this->count == 0)
	{
		std::cout << "PhoneBook is empty\n" << std::flush;
		return;
	}
	i = 0;
	std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nickname" << std::endl;
	while(i < this->count)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << format_column(this->contacts[i].getFirstName()) << "|" << std::flush;
    	std::cout << std::setw(10) << format_column(this->contacts[i].getLastName()) << "|" << std::flush;
    	std::cout << std::setw(10) << format_column(this->contacts[i].getNickname()) << std::endl;
		i++;
	}

	i = 0;
	std::cout << "Input Index\n" << std::flush;
	std::getline(std::cin, input);
	if(std::cin.fail() == true)
		return;
	if(input.length() != 1 || input[0] < '0' || input[0] > '7')
	{
		std::cout << "Invalid index\n" << std::flush;
    	return;
	}
	index = input[0] - '0';
	if(index >= this->count)
	{
		std::cout << "Invalid index\n" << std::flush;
		return;
	}
	std::cout << "First name: " << this->contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << this->contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << this->contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->contacts[index].getDarkestSecret() << std::endl;
}
