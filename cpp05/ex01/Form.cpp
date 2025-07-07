#include "Form.hpp"
#include "Bureaucrat.hpp"

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->_signGrade)
        throw GradeTooLowException();
    this->_isSigned = true;
}

Form::Form(const std::string& name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{

}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form()
{

}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << f._name << ", form sign grade " << f._signGrade << ", exec grade " << f._execGrade << ", signed: " << (f._isSigned ? "yes" : "no");
    return os;
}
