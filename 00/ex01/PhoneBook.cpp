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

void PhoneBook::searchContact() const
{

}
