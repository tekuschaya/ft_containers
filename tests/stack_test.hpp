#pragma once

#include "test.hpp" //убрать

bool empty_stack_test()
{
	std::stack<int, std::list<int> > orig;
	ft::stack<int, ft::list<int> > my;

	if (orig.empty() != my.empty())
	{
		std::cout << "Error empty" << std::endl;
		return false;
	}

	orig.push(5);
	my.push(5);
	if (orig.empty() != my.empty())
	{
		std::cout << "Error empty" << std::endl;
		return false;
	}

	return true;
}

bool pop_stack_test()
{
	std::stack<int, std::list<int> > orig;
	ft::stack<int, ft::list<int> > my;

	orig.push(1);
	my.push(1);
	orig.push(2);
	my.push(2);
	if (orig.size() != my.size())
		return false;
	orig.pop();
	my.pop();
	if (orig.size() != my.size())
		return false;
	orig.pop();
	my.pop();
	if (orig.empty() != my.empty())
		return false;

	return true;
}

bool push_stack_test()
{
	std::stack<int, std::list<int> > orig;
	ft::stack<int, ft::list<int> > my;

	orig.push(1);
	my.push(1);
	orig.push(2);
	my.push(2);
	if (orig.size() != my.size())
		return false;
	orig.pop();
	my.pop();
	if (orig.size() != my.size())
		return false;
	orig.pop();
	my.pop();
	if (orig.empty() != my.empty())
		return false;
	orig.push(25);
	my.push(25);
	if (orig.size() != my.size())
		return false;

	return true;

}
bool size_stack_test()
{
	std::stack<int> orig;
	ft::stack<int> my;
	if (orig.size() != my.size())
		return false;
	for (int i = 0; i < 50; i++)
	{
		orig.push(rand() % 50);
		my.push(rand() % 50);
	}
	if (orig.size() != my.size())
		return false;
	
	return true;
}

bool top_stack_test()
{
	std::stack<int> orig;
	ft::stack<int> my;
	if (orig.size() != my.size())
		return false;
	for (int i = 0; i < 50; i++)
	{
		orig.push(rand() % 50);
		my.push(rand() % 50);
	}
	orig.push(30);
	my.push(30);
	if (orig.top() != my.top())
	{
		std::cout << "\nOrig top = " << orig.top() << std::endl;
		std::cout << "My top = " << my.top() << std::endl;
		return false;
	}
	
	return true;
}

bool relational_stack_test()
{
	std::stack<int> orig1;
	std::stack<int> orig2;
	ft::stack<int> my1;
	ft::stack<int> my2;
	int number1;
	int number2;
	for (int i = 0; i < 20; i++)
	{
		number1 = rand() % 100;
		number2 = rand() % 100;
		orig1.push(number1);
		my1.push(number1);
		orig2.push(number2);
		my2.push(number2);
	}
	//Operator ==
	if ((orig1 == orig2) != (my1 == my2))
	{
		std::cout << "Error operator ==" << std::endl;
		return (false);
	}

	//Operator !=
	if ((orig1 != orig2) != (my1 != my2))
	{
		std::cout << "Error operator !=" << std::endl;
		return (false);
	}
	
	//Operator <
	if ((orig1 < orig2) != (my1 < my2))
	{
		std::cout << "Error operator <" << std::endl;
		return (false);
	}

	//Operator <=
	if ((orig1 <= orig2) != (my1 <= my2))
	{
		std::cout << "Error operator !=" << std::endl;
		return (false);
	}

	//Operator >
	if ((orig1 > orig2) != (my1 > my2))
	{
		std::cout << "Error operator >" << std::endl;
		return (false);
	}

	//Operator >=
	if ((orig1 >= orig2) != (my1 >= my2))
	{
		std::cout << "Error operator >=" << std::endl;
		return (false);
	}
	return (true);
}


void stack_start()
{
	std::cout << BOLDCYAN << "|=================================================================================================|" << std::endl;
	std::cout << "|                                        Stack tests                                              |" << std::endl;
	std::cout << "|=================================================================================================|" << std::endl;

	std::cout << BOLDCYAN << "[empty] \t\t" << ((empty_stack_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[pop] \t\t\t" << ((pop_stack_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[push] \t\t\t" << ((push_stack_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[size] \t\t\t" << ((size_stack_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[top] \t\t\t" << ((top_stack_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[relational_operators]\t" << ((relational_stack_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
}
