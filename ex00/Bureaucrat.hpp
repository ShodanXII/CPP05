#pragma once 

#include <string>
#include <iostream>

class Bureaucrat 
{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat( void );
    Bureaucrat(int grade, std::string name);
    Bureaucrat( Bureaucrat& copy);
    std::string getname( void );
    int    getgrade( void );
    void set(int grade, std::string name);
};