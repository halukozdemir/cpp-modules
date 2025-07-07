#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat high("Alive", 1);
        Bureaucrat low("Bob", 150);
        Form easy("EasyForm", 150, 150);
        Form hard("HardForm", 1, 1);
        
        std::cout << high << std::endl;
        std::cout << low << std::endl;
        std::cout << easy << std::endl;
        std::cout << hard << std::endl;

        low.signForm(easy);
        low.signForm(hard);
        high.signForm(hard);
        high.signForm(hard);

        Form invalid("invalidForm", 0, 10);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
