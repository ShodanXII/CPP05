#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(void)
    : _name("Nameless"),
      _signed(false),
      _signGrade(150),
      _execGrade(150)
{
    std::cout << _name << " Default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade)
    : _name(name),
      _signed(false),
      _signGrade(signGrade),
      _execGrade(execGrade)
{
    if (_signGrade < 1 || _execGrade < 1)
        throw (AForm::GradeTooHighException());
    else if (_signGrade > 150 || _execGrade > 150)
        throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm& copy)
    : _name(copy._name),
      _signed(copy._signed),
      _signGrade(copy._signGrade),
      _execGrade(copy._execGrade)
{
    std::cout << _name << " copy constructor been called" << std::endl;
}

AForm::~AForm(void)
{
    std::cout << _name << " default destructor been called" << std::endl;
}

bool AForm::getIsSigned(void) const
{
    return _signed;
}

std::string AForm::getName(void) const
{
    return _name;
}

int AForm::getExecGrade(void) const 
{
    return _execGrade;
}

int AForm::getSignGrade(void) const 
{
    return _signGrade;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char *AForm::NotSignedException::what() const throw()
{
    return ("Form Not Signed!");
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "AForm " << f.getName();
    os << ", Sign grade: " << f.getSignGrade();
    os << ", Exec grade: " << f.getExecGrade();
    os << ", Is signed: ";

    if (f.getIsSigned())
        os << "Yes";
    else
        os << "No";

    return os;
}

AForm& AForm::operator=(const AForm& copy)
{
    if (this != &copy)
        _signed = copy._signed;
    std::cout << "AForm Copy assignment operator called" << std::endl;
    return (*this);
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > _signGrade)
        throw (AForm::GradeTooLowException());
    _signed = true;
}