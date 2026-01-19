#include "Intern.hpp"

Intern::Intern( void )
{
    std::cout << " Intern default constractor been called" << std::endl;
}

Intern::Intern( const Intern& copy)
{
    *this = copy;
    std::cout << " Intern copy constractor been called" << std::endl;
}

Intern::~Intern( void )
{
    std::cout << " Intern default destractor been called" << std::endl;
}

