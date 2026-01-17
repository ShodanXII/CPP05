#pragma once 


#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
public:
    RobotomyRequestForm( void );
    RobotomyRequestForm( const RobotomyRequestForm& copy);
    RobotomyRequestForm( std::string target);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
    ~RobotomyRequestForm( void );
    void execute(Bureaucrat const &executer) const;
};
