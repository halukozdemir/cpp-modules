#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nextIndex(0), count(0)
{
}

int PhoneBook::getCount() const
{
    return count;
}

void PhoneBook::addContact(const Contact& contact)
{
    contacts[nextIndex] = contact;
    std::cout <<"referansin addresi: "<< &contact << std::endl;
    nextIndex = (nextIndex + 1) % 8;
    if (count < 8)
        count++;
}

void PhoneBook::displayContacts() const
{
    std::cout << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << i << "|"
                    << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
                    << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
                    << std::setw(10) << truncate(contacts[i].getNickName()) << std::endl;
    }
}

std::string PhoneBook::truncate(const std::string& str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::displayContactDetails(int index) const
{
    if (index < 0 || index >= count)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    const Contact& contact = contacts[index];
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickName() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}