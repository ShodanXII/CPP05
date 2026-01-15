#include "Bureaucrat.hpp"

int	main(void)
{
	/* ===== Test 1: Increment from valid grade ===== */
	try
	{
		Bureaucrat	b1(2, "Abdennour");
		std::cout << b1 << std::endl;
		b1.increment();
		std::cout << b1 << std::endl;
		b1.increment(); // should throw
		std::cout << b1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-----------------------------------" << std::endl;

	/* ===== Test 2: Decrement from valid grade ===== */
	try
	{
		Bureaucrat	b2(149, "Mandatory Test");
		std::cout << b2 << std::endl;
		b2.decremnt();
		std::cout << b2 << std::endl;
		b2.decremnt(); // should throw
		std::cout << b2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-----------------------------------" << std::endl;

	/* ===== Test 3: Grade too high at construction ===== */
	try
	{
		Bureaucrat	b3(0, "Too High");
		std::cout << b3 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-----------------------------------" << std::endl;

	/* ===== Test 4: Grade too low at construction ===== */
	try
	{
		Bureaucrat	b4(151, "Too Low");
		std::cout << b4 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "-----------------------------------" << std::endl;

	/* ===== Test 5: Normal usage ===== */
	try
	{
		Bureaucrat	b5(75, "Normal Guy");
		std::cout << b5 << std::endl;
		b5.increment();
		b5.decremnt();
		std::cout << b5 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
