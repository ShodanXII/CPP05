#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
private:
    const std::string _name;
    bool _signed;
    const int _excutgrade;
    const int _signedgrade;
public:
    AForm();
    AForm(std::string name, int excutgrade, int signedgrade);
    AForm(const AForm& copy);
    AForm& operator=(const AForm& copy);
    ~AForm();

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;


    virtual void	execute(Bureaucrat const & executor) const = 0;
    class	GradeTooHighException : public std::exception
    {
        public:
            const char	*what() const throw();
    };
    class	GradeTooLowException : public std::exception
    {
        public:
            const char	*what() const throw();
    };
    class	NotSignedException : public std::exception
    {
        public:
            const char	*what() const throw();
    };
    void beSigned(const Bureaucrat &b);
};

std::ostream&	operator<<(std::ostream& os, const AForm& f);