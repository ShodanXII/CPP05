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

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
: AForm(copy), target(copy.target)
{
    std::cout << AForm::getName() << " copy constructor been called from PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
        target = copy.target;
    }
    std::cout << AForm::getName() << " copy assignment operator been called from PresidentialPardonForm" << std::endl;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << AForm::getName() << " destructor been called from PresidentialPardonForm" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw std::runtime_error("PresidentialPardonForm not signed");
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}