#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat high("Alice", 1);
        Bureaucrat mid("Bob", 50);
        Bureaucrat low("Charlie", 150);

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Ford Prefect");

        std::cout << "\n--- ShrubberyCreationForm ---" << std::endl;
        low.signForm(shrub);      // Insufficient authority
        high.signForm(shrub);     // Successful
        low.executeForm(shrub);   // Insufficient authority
        high.executeForm(shrub);  // Successful

        std::cout << "\n--- RobotomyRequestForm ---" << std::endl;
        mid.signForm(robo);       // Insufficient authority
        high.signForm(robo);      // Successful
        mid.executeForm(robo);    // Insufficient authority
        high.executeForm(robo);   // Successful (random)

        std::cout << "\n--- PresidentialPardonForm ---" << std::endl;
        mid.signForm(pardon);     // Insufficient authority
        high.signForm(pardon);    // Successful
        mid.executeForm(pardon);  // Insufficient authority
        high.executeForm(pardon); // Successful

        // Attempt to execute an unsigned form
        ShrubberyCreationForm unsignedForm("fail");
        high.executeForm(unsignedForm);

    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
