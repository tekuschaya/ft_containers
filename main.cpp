#include "tests/list_test.hpp"
#include "tests/vector_test.hpp"
#include "tests/map_test.hpp"
#include "tests/multimap_test.hpp"
#include "tests/set_test.hpp"
#include "tests/multiset_test.hpp"
#include "tests/deque_test.hpp"
#include "tests/queue_test.hpp"
#include "tests/stack_test.hpp"
#include "tests/test.hpp"

enum containers {
	Exit,
	List,
	Vector,
	Map,
	Multimap,
	Stack,
	Queue,
	Deque,
	Set,
	Multiset,
	All
};

int main()
{
	int number;
	while (true)
	{
		std::cout << BOLDGREEN << "\nSelect number to run test: \n" << std::endl;

		std::cout << BOLDCYAN << "1.  " << BOLDCYAN << "List" <<std::endl;
		std::cout << BOLDCYAN << "2.  " << BOLDCYAN << "Vector" << std::endl;
		std::cout << BOLDCYAN << "3.  " << BOLDCYAN << "Map" << std::endl;
		std::cout << BOLDCYAN << "4.  " << BOLDCYAN << "Multimap" << std::endl;
		std::cout << BOLDCYAN << "5.  " << BOLDCYAN << "Stack" << std::endl;
		std::cout << BOLDCYAN << "6.  " << BOLDCYAN << "Queue" << std::endl;
		std::cout << BOLDCYAN << "7.  " << BOLDCYAN << "Deque" << std::endl;
		std::cout << BOLDCYAN << "8.  " << BOLDCYAN << "Set" << std::endl;
		std::cout << BOLDCYAN << "9.  " << BOLDCYAN << "Multiset" << std::endl;
		std::cout << BOLDCYAN << "10. " << BOLDCYAN << "All" << std::endl;
		std::cout << RED << "0.  " << RED << "Exit\n" << std::endl;

		std::cout << BOLDGREEN << "Enter number: ";
			std::cin >> number;
		switch (number)
		{
		case List:
			list_start();
			break;
		case Vector:
			vector_start();
			break;
		case Map:
			map_start();
			break;
		case Multimap:
			multimap_start();
			break;
		case Stack:
			stack_start();
			break;
		case Queue:
			queue_start();
			break;
		case Deque:
			deque_start();
			break;
		case Set:
			set_start();
			break;
		case Multiset:
			multiset_start();
			break;
		case All:
			list_start();
			vector_start();
			map_start();
			multimap_start();
			stack_start();
			queue_start();
			deque_start();
			set_start();
			multiset_start();
			break;
		case Exit:
			return 0;
		default:
			std::cout << RED << "Incorrect number" << std::endl;
		}
	}
	return 0;
}