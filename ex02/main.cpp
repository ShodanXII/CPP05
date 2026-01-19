#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat boss(1, "Boss");
    Bureaucrat worker(150, "Worker");

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Marvin");

    std::cout << "\n--- Signing tests ---\n" << std::endl;

    worker.signForm(shrub);    // should fail
    boss.signForm(shrub);      // should succeed

    boss.signForm(robot);
    boss.signForm(pardon);

    std::cout << "\n--- Execution tests ---\n" << std::endl;

    try {
        worker.executeForm(shrub);   // should fail
        boss.executeForm(shrub);     // should succeed

        boss.executeForm(robot);     // random success/fail
        boss.executeForm(pardon);    // should succeed
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
