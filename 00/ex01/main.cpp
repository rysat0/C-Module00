#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int is_valid_input(const std::string str)
{
	size_t i;

	i = 0;
	while(i < str.length())
	{
		if(str[i] >= '!' && str[i] <= '~')
			return(1);
		i++;
	}
	return(0);
}

bool initiate_contact(Contact &contact)
{
	std::string command;
	while(1)
	{
		std::cout << "input First Name: \n" << std::flush;
		std::getline(std::cin, command);
		if (std::cin.fail() == true)
            return false;
		if(is_valid_input(command) == 1)
		{
			contact.setFirstName(command);
			break;
		}
	}
	while(1)
	{
		std::cout << "input Last Name: \n" << std::flush;
		std::getline(std::cin, command);
		if (std::cin.fail() == true)
            return false;
		if(is_valid_input(command) == 1)
		{
			contact.setLastName(command);
			break;
		}
	}
	while(1)
	{
		std::cout << "input nickname: \n" << std::flush;
		std::getline(std::cin, command);
		if (std::cin.fail() == true)
            return false;
		if(is_valid_input(command) == 1)
		{
			contact.setNickname(command);
			break;
		}
	}
	while(1)
	{
		std::cout << "input Phone Number: \n" << std::flush;
		std::getline(std::cin, command);
		if (std::cin.fail() == true)
            return false;
		if(is_valid_input(command) == 1)
		{
			contact.setPhoneNumber(command);
			break;
		}
	}
	while(1)
	{
		std::cout << "input Yourr Darkest Secret: \n" << std::flush;
		std::getline(std::cin, command);
		if (std::cin.fail() == true)
            return false;
		if(is_valid_input(command) == 1)
		{
			contact.setDarkestSecret(command);
			break;
		}
	}
	return true;
}

int main()
{
	PhoneBook phoneBook;
	std::string command;
	Contact contact;

	while(1)
	{
		std::cout << "input command: \n" << std::flush;
		std::getline(std::cin, command);
		if(std::cin.fail() == 1)
			break;
		else if(command == "ADD")
		{
			if(initiate_contact(contact) == false)
				break;
			phoneBook.addContact(&contact);
		}
		else if(command == "SEARCH")
			phoneBook.searchContact();
		else if(command == "EXIT")
			break;
	}
	return(0);
}
