#pragma once

#include "test.hpp" //убрать

template<typename T>
bool check_size(std::list<T> &orig, ft::list<T> &my)
{
	if (orig.size() == my.size())
		return true;
	std::cout << "\nOrig size = " << orig.size() << std::endl;
	std::cout << "My size = " << my.size() << std::endl;
	return false;
}

template<typename T>
bool check_list(std::list<T> &orig, ft::list<T> &my)
{
	typename std::list<T>::iterator orig_begin = orig.begin();
	typename std::list<T>::iterator orig_end = orig.end();
	typename ft::list<T>::iterator my_begin = my.begin();
	typename ft::list<T>::iterator my_end = my.end();

	while (orig_begin != orig_end)
	{
		if (*orig_begin != *my_begin)
		{
			std::cout << "\norig elem = " << *orig_begin << " my elem = " << *my_begin << std::endl;
			return (false);
		}
		++orig_begin;
		++my_begin;
	}

	typename std::list<T>::reverse_iterator orig_rbegin = orig.rbegin();
	typename std::list<T>::reverse_iterator orig_rend = orig.rend();
	typename ft::list<T>::reverse_iterator my_rbegin = my.rbegin();
	typename ft::list<T>::reverse_iterator my_rend = my.rend();
	while (orig_rbegin != orig_rend)
	{
		if (*orig_rbegin != *my_rbegin)
		{
			std::cout << "\norig elem = " << *orig_begin << " my elem = " << *my_begin << std::endl;
			return (false);
		}
		++orig_rbegin;
		++my_rbegin;
	}
	return (true);
}

bool constructor_list_test()
{
	//default constructor
	std::list<int> orig;
	ft::list<int> my;
	if (!check_size(orig, my))
		return (false);
	if (!check_list(orig, my))
		return (false);

	//fill constructor
	std::list<int> orig1(10, 15);
	ft::list<int> my1(10, 15);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	std::list<char> orig2(15, 'A');
	ft::list<char> my2(15, 'A');
	if (!check_size(orig2, my2))
		return (false);
	if (!check_list(orig2, my2))
		return (false);

	std::list<std::string> orig3(10, "Hello!");
	ft::list<std::string> my3(10, "Hello!");
	if (!check_size(orig3, my3))
		return (false);
	if (!check_list(orig3, my3))
		return (false);

	//range constructor 
	//from std::list
	std::list<int> orig4(g_ls.begin(), g_ls.end());
	ft::list<int> my4(g_ls.begin(), g_ls.end());
	if (!check_size(orig4, my4))
		return (false);
	if (!check_list(orig4, my4))
		return (false);

	//from std::vector
	std::list<int> orig5(g_vc.begin(), g_vc.end());
	ft::list<int> my5(g_vc.begin(), g_vc.end());		
	if (!check_size(orig5, my5))
		return (false);
	if (!check_list(orig5, my5))
		return (false);

	//copy constructor
	std::list<int> orig6(orig4);
	ft::list<int> my6(my4);
	if (!check_size(orig6, my6))
		return (false);
	if (!check_list(orig6, my6))
		return (false);

	return true;
}

bool assigment_operator_list_test()
{
	std::list<char> orig1(15, 'A');
	ft::list<char> my1(15, 'A');

	std::list<std::string> orig2(10, "Hello!");
	ft::list<std::string> my2(10, "Hello!");

	std::list<int> orig3(10, 15);
	ft::list<int> my3(10, 15);

	std::list<char> orig4 = orig1;
	ft::list<char> my4 = my1;
	if (!check_size(orig4, my4))
		return (false);
	if (!check_list(orig4, my4))
		return (false);

	std::list<std::string> orig5 = orig2;
	ft::list<std::string> my5 = my2;
	if (!check_size(orig5, my5))
		return (false);
	if (!check_list(orig5, my5))
		return (false);

	std::list<int> orig6 = orig3;
	ft::list<int> my6 = my3;
	if (!check_size(orig6, my6))
		return (false);
	if (!check_list(orig6, my6))
		return (false);

	return true;
}
bool begin_end_list_test()
{
	std::list<int> orig(g_ls.begin(), g_ls.end());
	ft::list<int> my(g_ls.begin(), g_ls.end());
	if (!check_size(orig, my))
		return (false);
	if (!check_list(orig, my))
		return (false);

	std::list<int>::iterator it = orig.begin();
	std::list<int>::iterator ite = orig.end();
	ft::list<int>::iterator myit = my.begin();
	ft::list<int>::iterator myite = my.end();
	*it = 123;
	*myit = 123;
	*(--ite) = 321;
	*(--myite) = 321;
	if (!check_list(orig, my))
		return (false);

	return true;
}
bool rbegin_rend_list_test()
{
	std::list<int> orig(g_ls.begin(), g_ls.end());
	ft::list<int> my(g_ls.begin(), g_ls.end());
	if (!check_size(orig, my))
		return (false);
	if (!check_list(orig, my))
		return (false);

	std::list<int>::reverse_iterator it = orig.rbegin();
	std::list<int>::reverse_iterator ite = --orig.rend();
	ft::list<int>::reverse_iterator myit = my.rbegin();
	ft::list<int>::reverse_iterator myite = --my.rend();
	*it = 123;
	*myit = 123;
	*ite = 321;
	*myite = 321;
	if (!check_list(orig, my))
		return (false);

	return true;
}
bool front_back_list_test()
{
	std::list<int> orig;
	ft::list<int> my;
	int number;
	for (int i = 0; i < 20; i++)
	{
		number = rand() % 100;
		orig.push_back(number);
		my.push_back(number);
	}
	if (orig.back() != my.back())
	{
		std::cout << "Error back" << std::endl;
		return false;
	}
	if (orig.front() != my.front())
	{
		std::cout << "Error front" << std::endl;
		return false;
	}
	return true;
}
bool clear_list_test()
{
	std::list<int> orig(g_ls.begin(), g_ls.end());
	ft::list<int> my(g_ls.begin(), g_ls.end());
	if (!check_size(orig, my))
		return (false);
	if (!check_list(orig, my))
		return (false);

	orig.clear();
	my.clear();
	if (!check_size(orig, my))
		return (false);
	if (!check_list(orig, my))
		return (false);

	orig.clear();
	my.clear();
	if (!check_size(orig, my))
		return (false);
	if (!check_list(orig, my))
		return (false);

	return true;
}
bool empty_list_test()
{
	std::list<int> orig;
	ft::list<int> my;

	if (orig.empty() != my.empty())
	{
		std::cout << "Error empty" << std::endl;
		return false;
	}
	
	return true;
}
bool assign_list_test()
{
	//assign range
	std::list<int> orig;
	ft::list<int> my;
	orig.assign(g_ls.begin(), g_ls.end());
	my.assign(g_ls.begin(), g_ls.end());
	if (!check_size(orig, my))
		return (false);
	if (!check_list(orig, my))
		return (false);

	orig.assign(g_vc.begin(), g_vc.end());
	my.assign(g_vc.begin(), g_vc.end());
	if (!check_size(orig, my))
		return (false);
	if (!check_list(orig, my))
		return (false);

	//assign fill
	std::list<int> orig1;
	ft::list<int> my1;
	orig1.assign(15, 90);
	my1.assign(15, 90);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	std::list<double> orig2;
	ft::list<double> my2;
	orig2.assign(20, 100.);
	my2.assign(20, 100.);
	if (!check_size(orig2, my2))
		return (false);
	if (!check_list(orig2, my2))
		return (false);

	std::list<std::string> orig3;
	orig3.assign(5, "Hello!");
	ft::list<std::string> my3;
	my3.assign(5, "Hello!");
	if (!check_size(orig3, my3))
		return (false);
	if (!check_list(orig3, my3))
		return (false);
	return true;
}
bool erase_list_test()
{
	std::list<int> orig1(g_ls.begin(), g_ls.end());
	ft::list<int> my1(g_ls.begin(), g_ls.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	orig1.erase(++(orig1.begin()));
	my1.erase(++(my1.begin()));
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	orig1.erase(--(orig1.end()));
	my1.erase(--(my1.end()));
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	orig1.erase(++(orig1.begin()), orig1.end());
	my1.erase(++(my1.begin()), my1.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);
	return true;
}
bool insert_list_test()
{
	std::list<int> orig1(g_ls.begin(), g_ls.end());
	ft::list<int> my1(g_ls.begin(), g_ls.end());

	// insert (iterator position, const value_type& val)
	orig1.insert(++(orig1.begin()), 100);
	my1.insert(++(my1.begin()), 100);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	// insert (iterator position, size_type n, const value_type& val)
	orig1.insert(++(orig1.begin()), 18, 35);
	my1.insert(++(my1.begin()), 18, 35);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	// insert (iterator position, InputIterator first, InputIterator last)
	orig1.insert(orig1.begin(), g_ls.begin(), g_ls.end());
	my1.insert(my1.begin(), g_ls.begin(), g_ls.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);
	
	return true;

}
bool max_size_list_test()
{
	std::list<int> orig(5, 10);
	ft::list<int> my(5, 10);
	if (orig.max_size() != my.max_size())
	{
		std::cout << "Error max_size" << std::endl;
		return false;
	}
	return true;
}
bool mycomp (int first, int second)
{
	return (first < second);
}
bool merge_list_test()
{
	std::list<int> list1;
	std::list<int> list2;
	for (int i = 0; i < 10; i++)
	{
		list1.push_back(rand() % 100);
		list2.push_back(rand() % 100);
	}
	std::list<int> orig1(list1.begin(), list1.end());
	std::list<int> orig2(list2.begin(), list2.end());
	ft::list<int> my1(list1.begin(), list1.end());
	ft::list<int> my2(list2.begin(), list2.end());
	orig1.sort();
	orig2.sort();
	my1.sort();
	my2.sort();

	orig1.merge(orig2);
	my1.merge(my2);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	// merge compare
	orig2.assign(list1.begin(), list1.end());
	my2.assign(list1.begin(), list1.end());
	orig2.sort();
	my2.sort();
	orig1.merge(orig2, mycomp);
	my1.merge(my2, mycomp);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	return true;
}

bool pop_back_list_test()
{
	std::list<int> orig1(g_ls.begin(), g_ls.end());
	ft::list<int> my1(g_ls.begin(), g_ls.end());

	orig1.pop_back();
	my1.pop_back();
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	orig1.pop_back();
	my1.pop_back();
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	return true;
}
bool pop_front_list_test()
{
	std::list<int> orig1(g_ls.begin(), g_ls.end());
	ft::list<int> my1(g_ls.begin(), g_ls.end());

	orig1.pop_front();
	my1.pop_front();
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);
	
	orig1.pop_front();
	my1.pop_front();
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	return true;
}
bool push_back_list_test()
{
	std::list<int> orig1(g_ls.begin(), g_ls.end());
	ft::list<int> my1(g_ls.begin(), g_ls.end());

	orig1.push_back(5);
	my1.push_back(5);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	orig1.push_back(1000);
	my1.push_back(1000);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);
	
	return true;

}
bool push_front_list_test()
{
	std::list<int> orig1(g_ls.begin(), g_ls.end());
	ft::list<int> my1(g_ls.begin(), g_ls.end());

	orig1.push_front(156);
	my1.push_front(156);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);
	
	orig1.push_front(500);
	my1.push_front(500);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	return true;
	
}
bool remove_list_test()
{
	std::list<int> orig1(g_ls.begin(), g_ls.end());
	ft::list<int> my1(g_ls.begin(), g_ls.end());

	orig1.remove(5);
	my1.remove(5);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	orig1.remove(222);
	my1.remove(222);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	return true;
}
bool little_digit (const int& value) { return (value < 10); }
bool remove_if_list_test()
{
	std::list<int> orig1;
	for (int i = 0; i < 50; i++)
		orig1.push_back(rand() % 100);
	ft::list<int> my1(orig1.begin(), orig1.end());

	orig1.remove_if(little_digit);
	my1.remove_if(little_digit);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	return true;
}
bool resize_list_test()
{
	std::list<int> orig1;
	ft::list<int> my1;

	orig1.resize(15, 1);
	my1.resize(15, 1);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	orig1.resize(17, 100);
	my1.resize(17, 100);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	orig1.resize(8, 5);
	my1.resize(8, 5);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	return true;
}
bool reverse_list_test()
{
	std::list<int> orig1;
	ft::list<int> my1;

	orig1.reverse();
	my1.reverse();
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	orig1.assign(g_ls.begin(), g_ls.end());
	my1.assign(g_ls.begin(), g_ls.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	orig1.reverse();
	my1.reverse();
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	return true;
}
bool size_list_test()
{
	std::list<int> orig1;
	ft::list<int> my1;
	if (!check_size(orig1, my1))
		return (false);

	std::list<int> orig2(15, 20);
	ft::list<int> my2(15, 20);
	if (!check_size(orig1, my1))
		return (false);

	return true;
}
bool sort_list_test()
{
	std::list<int> list1;
	for (int i = 0; i < 10; i++)
		list1.push_back(rand() % 100);
	std::list<int> orig1(list1.begin(), list1.end());
	ft::list<int> my1(list1.begin(), list1.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	orig1.sort();
	my1.sort();
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	std::list<int> orig2(list1.begin(), list1.end());
	ft::list<int> my2(list1.begin(), list1.end());
	orig2.sort(mycomp);
	my2.sort(mycomp);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	return true;
}
bool splice_list_test()
{
	// splice (iterator position, list& x)
	std::list<int> orig1(g_ls.begin(), g_ls.end());
	std::list<int> orig2(g_ls.begin(), g_ls.end());

	ft::list<int> my1(g_ls.begin(), g_ls.end());
	ft::list<int> my2(g_ls.begin(), g_ls.end());

	orig1.splice(++(orig1.begin()), orig2);
	my1.splice(++(my1.begin()), my2);

	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	if (!check_size(orig2, my2))
		return (false);
	if (!check_list(orig2, my2))
		return (false);

	// splice (iterator position, list& x, iterator i)
	orig2.assign(g_ls.begin(), g_ls.end());
	my2.assign(g_ls.begin(), g_ls.end());

	orig1.splice(orig1.begin(), orig2, ++(orig2.begin()));
	my1.splice(my1.begin(), my2, ++(my2.begin()));

	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	if (!check_size(orig2, my2))
		return (false);
	if (!check_list(orig2, my2))
		return (false);

	// splice (iterator position, list& x, iterator first, iterator last)
	orig2.assign(g_ls.begin(), g_ls.end());
	my2.assign(g_ls.begin(), g_ls.end());

	orig1.splice(orig1.begin(), orig2, orig2.begin(), orig2.end());
	my1.splice(my1.begin(), my2, my2.begin(), my2.end());

	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	if (!check_size(orig2, my2))
		return (false);
	if (!check_list(orig2, my2))
		return (false);

	return true;
}
bool swap_list_test()
{
	std::list<int> orig1(g_ls.begin(), g_ls.end());
	std::list<int> orig2(g_vc.begin(), g_vc.end());
	ft::list<int> my1(g_ls.begin(), g_ls.end());
	ft::list<int> my2(g_vc.begin(), g_vc.end());

	orig1.swap(orig2);
	my1.swap(my2);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	if (!check_size(orig2, my2))
		return (false);
	if (!check_list(orig2, my2))
		return (false);

	return true;
}
bool mypred(int first, int second)
{
	return (first == second);
}
bool unique_list_test()
{
	std::list<int> list1;
	for (int i = 0; i < 50; i++)
		list1.push_back(rand() % 10);

	std::list<int> orig1(list1.begin(), list1.end());
	ft::list<int> my1(list1.begin(), list1.end());

	orig1.unique();
	my1.unique();
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	std::list<int> orig2(list1.begin(), list1.end());
	ft::list<int> my2(list1.begin(), list1.end());
	orig1.unique(mypred);
	my1.unique(mypred);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	return true;
}
bool relational_list_test()
{
	std::list<int> list1;
	std::list<int> list2;
	for (int i = 0; i < 20; i++)
	{
		list1.push_back(rand() % 100);
		list2.push_back(rand() % 100);
	}
	std::list<int> orig1(list1.begin(), list1.end());
	std::list<int> orig2(list2.begin(), list2.end());
	ft::list<int> my1(list1.begin(), list1.end());
	ft::list<int> my2(list2.begin(), list2.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);
	if (!check_size(orig2, my2))
		return (false);
	if (!check_list(orig2, my2))
		return (false);

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
bool swap_list_list_test()
{
	std::list<int> orig1(g_ls.begin(), g_ls.end());
	std::list<int> orig2(g_vc.begin(), g_vc.end());
	ft::list<int> my1(g_ls.begin(), g_ls.end());
	ft::list<int> my2(g_vc.begin(), g_vc.end());

	std::swap(orig1, orig2);
	ft::swap(my1, my2);

	if (!check_size(orig1, my1))
		return (false);
	if (!check_list(orig1, my1))
		return (false);

	if (!check_size(orig2, my2))
		return (false);
	if (!check_list(orig2, my2))
		return (false);

	return true;
}

void list_start()
{
	std::cout << BOLDCYAN << "|=================================================================================================|" << std::endl;
	std::cout << "|                                        List tests                                               |" << std::endl;
	std::cout << "|=================================================================================================|" << std::endl;

	std::cout << BOLDCYAN << "\n[constructor] \t\t" << ((constructor_list_test()) ? GREEN "OK" : RED "FAIL") << std::endl;
	std::cout << BOLDCYAN << "[operator=] \t\t" << ((assigment_operator_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[begin/end] \t\t" << ((begin_end_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[rbegin/rend] \t\t" << ((rbegin_rend_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[front/back] \t\t" << ((front_back_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[clear] \t\t" << ((clear_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[empty] \t\t" << ((empty_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[assign] \t\t" << ((assign_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[erase] \t\t" << ((erase_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[insert] \t\t" << ((insert_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[max_size] \t\t" << ((max_size_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[merge] \t\t" << ((merge_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[pop_back] \t\t" << ((pop_back_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[pop_front] \t\t" << ((pop_front_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[push_back] \t\t" << ((push_back_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[push_front] \t\t" << ((push_front_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[remove] \t\t" << ((remove_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[remove_if] \t\t" << ((remove_if_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[resize] \t\t" << ((resize_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[reverse] \t\t" << ((reverse_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[size] \t\t\t" << ((size_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[sort] \t\t\t" << ((sort_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[splice] \t\t" << ((splice_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[swap] \t\t\t" << ((swap_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[unique] \t\t" << ((unique_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[relational_operators]\t" << ((relational_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[swap_list] \t\t" << ((swap_list_list_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
}
