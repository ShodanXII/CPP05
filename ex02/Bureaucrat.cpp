#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(int grade, const std::string name) : _name(name) , _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << _name << " constractor been called" <<std::endl;
}

int Bureaucrat::getGrade( void ) const 
{
    return _grade;
}

std::string Bureaucrat::getName( void ) const 
{
    return _name;  
}

Bureaucrat::~Bureaucrat( void )
{
    std::cout << _name << " Default destractor been called" << std::endl;
}

Bureaucrat::Bureaucrat( void ) : _name("Namles") , _grade(150)
{
    std::cout << _name << " Default constractor been called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name) , _grade(copy._grade)
{
    std::cout << _name << " copy constractor been called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}

void Bureaucrat::increment()
{
	if (_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
    std::cout <<"increment" << std::endl;
	_grade--;
}

void Bureaucrat::decremnt( void )
{
	if (_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
    std::cout <<"decrement" << std::endl;
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " couldn’t execute " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}

void	Bureaucrat::signForm(AForm& f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " couldn’t sign " << f.getName() << " because " << e.what() << "." << std::endl;
	}
}