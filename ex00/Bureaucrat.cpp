#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name) , _grade(grade)
{
    std::cout << _name << "constractor been called" <<std::endl;
    if()
}

int Bureaucrat::getgrade( void )
{
    return _grade;
}

Bureaucrat::Bureaucrat( void ) : _name("Namles") , _grade(150)
{
    std::cout << _name << "default constractor been called" << std::endl;
}; 
