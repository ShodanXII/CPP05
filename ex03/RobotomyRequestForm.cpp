#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

static bool srand_called = false;

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request Form", 72, 45), _target("default_target")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy Request Form", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor called for target: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
    : AForm(copy), _target(copy._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executer) const
{
    if (!getIsSigned())
        throw AForm::NotSignedException();
    
    if (executer.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    
    std::cout << "Drrrrrrr... Brrrrrr... Vzzzzzt..." << std::endl;
    
    if (!srand_called)
    {
        std::srand(std::time(NULL));
        srand_called = true;
    }
    
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy on " << _target << " failed." << std::endl;
}