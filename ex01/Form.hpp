#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string _name;
    bool _signed;
    const int _excutgrade;
    const int _signedgrade;
public:
    Form();
    Form(std::string name, int excutgrade, int signedgrade);
    Form(const Form& copy);
    Form& operator=(const Form& copy);
    ~Form();

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

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

    void beSigned(const Bureaucrat &b);
};

std::ostream&	operator<<(std::ostream& os, const Form& f);