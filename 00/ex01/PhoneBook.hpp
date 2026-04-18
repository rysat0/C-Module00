#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		count;
		int		nextIndex;

	public:
		PhoneBook();
		void addContact(Contact *contact);
		void searchContact() const;
};

#endif
