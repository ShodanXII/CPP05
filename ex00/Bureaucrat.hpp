#pragma once 

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
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat& operator=(const Bureaucrat& copy);
    ~Bureaucrat( void );
    std::string getName( void ) const ;
    int    getGrade( void ) const ;
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);