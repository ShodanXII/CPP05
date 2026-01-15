#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	b1(1, "Abdennour");
		std::cout << b1 << std::endl;
		b1.increment();
		std::cout << b1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-----------------------------------" << std::endl;
	try
	{
		Bureaucrat	b2(150 , "ooohhh ghi mandatory");
		std::cout << b2 << std::endl;
		b2.decremnt();
		std::cout << b2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-----------------------------------" << std::endl;
	try
	{
		Bureaucrat	b3(0 , "test");
		std::cout << b3 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
