#include <Bureaucrat.hpp>
#include <string>

Bureaucrat::Bureaucrat(int grade, const std::string name) : _name(name) , _grade(grade)
{
    std::cout << _name << "constractor been called" <<std::endl;
    if(grade > 150)
        throw 
    else if(grade < 1)
        throw GradeTooLowException
}

int Bureaucrat::getGrade( void )
{
    return _grade;
}

std::string Bureaucrat::getName( void )
{
    return _name;
}

Bureaucrat::~Bureaucrat( void )
{
    std::cout << _name << "Default destractor been called" << std::endl;
}

Bureaucrat::Bureaucrat( void ) : _name("Namles") , _grade(150)
{
    std::cout << _name << "default constractor been called" << std::endl;
}; 

std::ostream& operator<<(std::ostream& os, Bureaucrat& b)
{
	os << b.getName() << ",  bureaucrat grade " << b.getGrade() << ".";
	return (os);
}