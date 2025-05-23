#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
    private:
        Contact contacts[8];
        int nextIndex;
        int count;
    public:
        PhoneBook();
        void addContact(const Contact& contact);
        void displayContacts() const;
        void displayContactDetails(int index) const;
        int getCount() const;
        std::string truncate(const std::string& str) const;
};
#endif