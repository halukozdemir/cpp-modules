#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    try {
        Intern someRandomIntern;
        AForm* rrf;
        AForm* scf;
        AForm* ppf;
        AForm* invalid;

        std::cout << "--- Testing Intern makeForm ---" << std::endl;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        scf = someRandomIntern.makeForm("shrubbery creation", "Home");
        ppf = someRandomIntern.makeForm("presidential pardon", "Zaphod");
        invalid = someRandomIntern.makeForm("invalid form", "Target");

        std::cout << "\n--- Testing created forms ---" << std::endl;
        
        Bureaucrat high("Alice", 1);
        
        if (rrf) {
            high.signForm(*rrf);
            high.executeForm(*rrf);
            delete rrf;
        }
        
        if (scf) {
            high.signForm(*scf);
            high.executeForm(*scf);
            delete scf;
        }
        
        if (ppf) {
            high.signForm(*ppf);
            high.executeForm(*ppf);
            delete ppf;
        }

    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
