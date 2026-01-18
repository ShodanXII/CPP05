#pragma  once


#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
private:
    const std::string   _name;
    bool                _signed;
    const int           _signGrade;
    const int           _execGrade;

public:
    AForm(void);
    AForm(std::string name, int signGrade, int execGrade);
    AForm(const AForm& copy);
    virtual ~AForm(void);
    AForm& operator=(const AForm& copy);

    std::string getName(void) const;
    bool getIsSigned(void) const;
    int getSignGrade(void) const;
    int getExecGrade(void) const;

    void beSigned(const Bureaucrat& b);
    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);
