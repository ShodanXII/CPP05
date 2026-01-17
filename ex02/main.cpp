#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    try
    {
        // Create bureaucrats
        Bureaucrat boss(1, "Boss");
        Bureaucrat intern(150, "Intern");
        
        std::cout << boss << std::endl;
        std::cout << intern << std::endl;
        
        // Create forms with different targets
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Arthur");
        
        std::cout << "\n" << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;
        
        // Test 1: ShrubberyCreationForm
        std::cout << "\n--- Testing ShrubberyCreationForm ---" << std::endl;
        boss.signForm(shrubbery);
        boss.executeForm(shrubbery);
        
        // Test 2: RobotomyRequestForm  
        std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
        boss.signForm(robotomy);
        boss.executeForm(robotomy);
        boss.executeForm(robotomy);  // Try again for 50% chance
        
        // Test 3: PresidentialPardonForm
        std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
        boss.signForm(pardon);
        boss.executeForm(pardon);
        
        // Test 4: Error - unsigned form
        std::cout << "\n--- Testing Error: Unsigned Form ---" << std::endl;
        PresidentialPardonForm pardon2("Ford");
        boss.executeForm(pardon2);  // Should throw exception
        
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return (0);
}