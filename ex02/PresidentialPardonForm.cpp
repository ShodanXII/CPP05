#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) :
AForm("PresidentialPardonForm", 25, 5), target("Default_target")
{
    std::cout << " PresidentialPardonForm default constractor been called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string& _target) : AForm("PresidentialPardonForm", 25, 5), target(_target)
{
    std::cout << AForm::getName() << " constractor been called from PresidentialPardonForm" << std::endl;
}

