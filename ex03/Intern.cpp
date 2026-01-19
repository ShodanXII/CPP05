#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void )
{
    std::cout << "Intern default constractor been called" << std::endl;
}

Intern::Intern( const Intern& copy)
{
    *this = copy;
    std::cout << "Intern copy constractor been called" << std::endl;
}

Intern::~Intern( void )
{
    std::cout << "Intern default destractor been called" << std::endl;
}

Intern& Intern::operator=( const Intern& copy)
{
	(void)copy;
	std::cout << "Intern copy assignment constractor " << std::endl;
	return *this;
}

static	AForm	*create_Shrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

static	AForm	*create_RobotomyRequest(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

static	AForm	*create_PresidentialPardon(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	const std::string	formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm				*(*creators[3])(const std::string& target) = {&create_Shrubbery, &create_RobotomyRequest, &create_PresidentialPardon};

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (creators[i](target));
		}
	}
	std::cout << "Intern couldn't create form: " << name << std::endl;
	return (NULL);
}