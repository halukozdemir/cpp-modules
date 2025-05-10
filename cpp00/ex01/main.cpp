#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

void addContact(PhoneBook& phoneBook)
{
    Contact contact;
    std::cout << "contact'ın addresi: " << &contact<< std::endl;
    std::string input;

    do
    {
        std::cout << "Enter First Name: ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        if (input.empty())
            std::cout << "First Name cannot be empty!" << std::endl;
    }
    while (input.empty());
    contact.setFirstName(input);

    do
    {
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        if (input.empty())
            std::cout << "Last Name cannot be empty!" << std::endl;
    }
    while (input.empty());
    contact.setLastName(input);

    do
    {
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        if (input.empty())
            std::cout << "Nickname cannot be empty!" << std::endl;
    }
    while (input.empty());
    contact.setNickName(input);

    do
    {
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        if (input.empty())
            std::cout << "Phone Number cannot be empty!" << std::endl;
    }
    while (input.empty());
    contact.setPhoneNumber(input);

    do
    {
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        if (input.empty())
            std::cout << "Darkest Secret cannot be empty!" << std::endl;
    }
    while (input.empty());
    contact.setDarkestSecret(input);

    phoneBook.addContact(contact);
    std::cout << "Contact added successfully!" << std::endl;
}

void searchContacts(PhoneBook& phoneBook)
{
    if (phoneBook.getCount() == 0)
    {
        std::cout << "No contacts in the phone book!" << std::endl;
        return;
    }

    phoneBook.displayContacts();

    std::string input;
    int index = -1;
    std::cout << "Enter index to view details: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
        exit(0);
    if (input.empty() || input.find_first_not_of("0123456789") != std::string::npos)
    {
        std::cout << "Invalid input! Please enter a valid number." << std::endl;
        return;
    }
    index = std::stoi(input);
    if (index < 0 || index >= phoneBook.getCount())
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    phoneBook.displayContactDetails(index);
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter Command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        std::cout << "phonebook'un addresi: " << &phoneBook << std::endl;
        if (std::cin.eof())
            break;
        if (command == "ADD")
            addContact(phoneBook);
        else if (command == "SEARCH")
            searchContacts(phoneBook);
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command. Please try again." << std::endl;
    }
    return 0;
}