#pragma once

#include "test.hpp"

bool back_queue_test()
{
	std::queue<int> orig;
	ft::queue<int> my;
	if (orig.size() != my.size())
		return false;
	orig.push(15);
	my.push(15);
	for (int i = 0; i < 50; i++)
	{
		orig.push(rand() % 50);
		my.push(rand() % 50);
	}
	orig.push(30);
	my.push(30);
	if (orig.back() != my.back())
	{
		std::cout << "\nOrig back = " << orig.back() << std::endl;
		std::cout << "My back = " << my.back() << std::endl;
		return false;
	}
	
	return true;
}

bool empty_queue_test()
{
	std::queue<int, std::list<int> > orig;
	ft::queue<int, ft::list<int> > my;

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

bool front_queue_test()
{
	std::queue<int> orig;
	ft::queue<int> my;
	if (orig.size() != my.size())
		return false;
	orig.push(15);
	my.push(15);
	for (int i = 0; i < 50; i++)
	{
		orig.push(rand() % 50);
		my.push(rand() % 50);
	}
	orig.push(30);
	my.push(30);
	if (orig.front() != my.front())
	{
		std::cout << "\nOrig front = " << orig.front() << std::endl;
		std::cout << "My front = " << my.front() << std::endl;
		return false;
	}
	
	return true;
}

bool pop_queue_test()
{
	std::queue<int, std::list<int> > orig;
	ft::queue<int, ft::list<int> > my;

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

bool push_queue_test()
{
	std::queue<int, std::list<int> > orig;
	ft::queue<int, ft::list<int> > my;

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
bool size_queue_test()
{
	std::queue<int> orig;
	ft::queue<int> my;
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

bool relational_queue_test()
{
	std::queue<int> orig1;
	std::queue<int> orig2;
	ft::queue<int> my1;
	ft::queue<int> my2;
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


void queue_start()
{
	std::cout << BOLDCYAN << "|=================================================================================================|" << std::endl;
	std::cout << "|                                        Queue tests                                              |" << std::endl;
	std::cout << "|=================================================================================================|" << std::endl;

	std::cout << BOLDCYAN << "[back] \t\t\t" << ((back_queue_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[empty] \t\t" << ((empty_queue_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[front] \t\t" << ((front_queue_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[pop] \t\t\t" << ((pop_queue_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[push] \t\t\t" << ((push_queue_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[size] \t\t\t" << ((size_queue_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[relational_operators]\t" << ((relational_queue_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
}
