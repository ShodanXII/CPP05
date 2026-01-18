#pragma once


#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;
    
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
    ~ShrubberyCreationForm();
    
    void execute(Bureaucrat const &executer) const;
};

