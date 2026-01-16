#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	bureaucrat(1, "Abdennour");
		Form		form("My_Form", 1, 1);

		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;

		bureaucrat.decremnt();
		std::cout << bureaucrat << std::endl;
		
		bureaucrat.signForm(form);
		
		std::cout << form << std::endl;

		bureaucrat.increment();
		
		std::cout << bureaucrat << std::endl;
		
		bureaucrat.signForm(form);
		
		std::cout << form << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}