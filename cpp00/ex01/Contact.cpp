#include "Contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret("")
{
    
}

void Contact::setFirstName(const std::string& fn)
{
    firstName = fn;
}

void Contact::setLastName(const std::string& ln)
{
    lastName = ln;
}

void Contact::setNickName(const std::string& nn)
{
    nickName = nn;
}

void Contact::setPhoneNumber(const std::string& pn)
{
    phoneNumber = pn;
}

void Contact::setDarkestSecret(const std::string& ds)
{
    darkestSecret = ds;
}

std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickName() const
{
    return nickName;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}
