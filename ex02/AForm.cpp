#include "AForm.hpp"

AForm::AForm(void)
    : _name("Nameless"),
      _signed(false),
      _excutgrade(150),
      _signedgrade(150)
{
    std::cout << _name << " Default constractor called" << std::endl;
}

AForm::AForm(std::string name, int excutgrade, int signedgrade)
    : _name(name),
      _signed(false),
      _excutgrade(excutgrade),
      _signedgrade(signedgrade)
{
    if (_signedgrade < 1 || _excutgrade < 1)
        throw (AForm::GradeTooHighException());
    else if (_signedgrade > 150 || _excutgrade > 150)
        throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm& copy)
    : _name(copy._name),
      _signed(copy._signed),
      _excutgrade(copy._excutgrade),
      _signedgrade(copy._signedgrade)
{
    std::cout << _name << " copy constractor been called " << std::endl;
}

AForm::~AForm( void )
{
    std::cout << _name << " default destractor been called" << std::endl;
}

bool AForm::getIsSigned( void ) const
{
    return _signed;
}

std::string AForm::getName( void ) const
{
    return _name;
}

int AForm::getExecGrade( void ) const 
{
    return _excutgrade;
}

int AForm::getSignGrade( void ) const 
{
    return _signedgrade;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "grade too low";
}

std::ostream&	operator<<(std::ostream& os, const AForm& f)
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
    if (b.getGrade() > _signedgrade)
        throw (AForm::GradeTooLowException());
    _signed = true;
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

const char	*AForm::NotSignedException::what() const throw()
{
	return ("Form Not Signed!");
}
