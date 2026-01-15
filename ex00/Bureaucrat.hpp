#pragma once 

#include <string>
#include <exception>
#include <iostream>

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
    void GradeTooLowException( void );
    void GradeTooHighException( void );
};