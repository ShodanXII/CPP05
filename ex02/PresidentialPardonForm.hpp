#pragma once

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm(const std::string& _target);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();
		void	execute(Bureaucrat const & executor) const;
};