#include "Form.hpp"

Form::Form( void ) : _name("Nameless") , _signed(false), _signedgrade(150), _excutgrade(150)
{
    std::cout << _name << " Default constractor called" << std::endl;
}

Form::Form(std::string name, int excutgrade, int signedgrade) : _name(name), _signedgrade(signedgrade), _excutgrade(excutgrade), _signed(false)
{
    if (_signed < 1 || _excutgrade < 1)
        throw (Form::GradeTooHighException());
    else if (_signedgrade > 150 || _excutgrade > 150)
        throw (Form::GradeTooLowException());
    std::cout << _name <<" constructor called" << std::endl;
}

Form::Form(const Form& copy) : _name(copy._name), _excutgrade(copy._excutgrade), _signed(false), _signedgrade(copy._signedgrade)
{
    std::cout << _name << " copy constractor been called " << std::endl;
}

Form::~Form( void )
{
    std::cout << _name << " default destractor been called" << std::endl;
}

bool Form::getIsSigned( void ) const
{
    return _signed;
}

std::string Form::getName( void ) const
{
    return _name;
}

int Form::getExecGrade( void ) const 
{
    return _excutgrade;
}

int Form::getSignGrade( void ) const 
{
    return _signedgrade;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "grade too low";
}

std::ostream&	operator<<(std::ostream& os, const Form& f)
{
    os << "Form " << f.getName();
    os << ", Sign grade: " << f.getSignGrade();
    os << ", Exec grade: " << f.getExecGrade();
    os << ", Is signed: ";

    if (f.getIsSigned())
        os << "Yes";
    else
        os << "No";

    return os;
}

Form &operator=(const Form &copy)
{
    
}