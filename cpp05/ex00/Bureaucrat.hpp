#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &other);
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
}

#endif
