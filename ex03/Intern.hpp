#pragma once 

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Intern
{
public:
    Intern( void );
    Intern( const Intern& copy);
    ~Intern( void );
    Intern& operator=(const Intern& copy);
    AForm	*makeForm(std::string name, std::string target);
};
