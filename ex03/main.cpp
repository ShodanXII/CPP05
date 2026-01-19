#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss(1, "Boss");

    AForm* f1 = NULL;
    AForm* f2 = NULL;
    AForm* f3 = NULL;
    AForm* f4 = NULL;

    try {
        f1 = someRandomIntern.makeForm("shrubbery creation", "home");
        f2 = someRandomIntern.makeForm("robotomy request", "Bender");
        f3 = someRandomIntern.makeForm("presidential pardon", "Marvin");
        f4 = someRandomIntern.makeForm("unknown form", "Nobody");
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    if (f1)
    {
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;
    }
    if (f2)
    {
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete f2;
    }
    if (f3)
    {
        boss.signForm(*f3);
        boss.executeForm(*f3);
        delete f3;
    }
    if (f4)
        delete f4;

    return 0;
}
