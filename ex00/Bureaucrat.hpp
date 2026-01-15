#pragma once 

#include <string>
#include <exception>
#include <iostream>
#include <strstream>

class Bureaucrat 
{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat( void );
    Bureaucrat(int grade, const std::string name);   
    Bureaucrat( Bureaucrat& copy);
    Bureaucrat& operator=(const Bureaucrat& copy);
    ~Bureaucrat( void );
    std::string getName( void );
    int    getGrade( void );
    void set(int grade, std::string name);
    class GradeTooHighException : public std::exception
    {
        public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
        const char *what() const throw();
    };

    void increment( void );
    void decremnt( void );
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& Bureaucrat);