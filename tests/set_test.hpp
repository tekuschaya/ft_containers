#pragma once

#include "test.hpp"

template<typename T>
bool check_size(std::set<T> &orig, ft::set<T> &my)
{
	if (orig.size() == my.size())
		return true;
	std::cout << "\nOrig size = " << orig.size() << std::endl;
	std::cout << "My size = " << my.size() << std::endl;
	return false;
}

template<typename T>
bool check_set(std::set<T> &orig, ft::set<T> &my)
{
	typename std::set<T>::iterator orig_begin = orig.begin();
	typename std::set<T>::iterator orig_end = orig.end();
	typename ft::set<T>::iterator my_begin = my.begin();
	typename ft::set<T>::iterator my_end = my.end();

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

	typename std::set<T>::reverse_iterator orig_rbegin = orig.rbegin();
	typename std::set<T>::reverse_iterator orig_rend = orig.rend();
	typename ft::set<T>::reverse_iterator my_rbegin = my.rbegin();
	typename ft::set<T>::reverse_iterator my_rend = my.rend();
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

bool constructor_set_test()
{
	//empty constructor
	std::set<int> orig1;
	ft::set<int> my1;
	if (!check_size(orig1, my1))
		return (false);
	if (!check_set(orig1, my1))
		return (false);

	std::set<std::string> orig2;
	ft::set<std::string> my2;
	if (!check_size(orig2, my2))
		return (false);
	if (!check_set(orig2, my2))
		return (false);

	//range constructor

	std::set<int> orig3(g_vec.begin(), g_vec.end());
	ft::set<int> my3(g_vec.begin(), g_vec.end());
	if (!check_size(orig3, my3))
		return (false);
	if (!check_set(orig3, my3))
		return (false);

	std::set<std::string> orig4(g_str.begin(), g_str.end());
	ft::set<std::string> my4(g_str.begin(), g_str.end());
	if (!check_size(orig4, my4))
		return (false);
	if (!check_set(orig4, my4))
		return (false);

	//copy constructor
	std::set<std::string> orig5(orig4);
	ft::set<std::string> my5(my4);
	if (!check_size(orig5, my5))
		return (false);
	if (!check_set(orig5, my5))
		return (false);

	std::set<int> orig6(orig3);
	ft::set<int> my6(my3);
	if (!check_size(orig6, my6))
		return (false);
	if (!check_set(orig6, my6))
		return (false);
	
	return true;

}
bool assigment_operator_set_test()
{
	std::set<int> orig(g_vec.begin(), g_vec.end());
	ft::set<int> my(g_vec.begin(), g_vec.end());
	std::set<int> orig1 = orig;
	ft::set<int> my1 = my;
	if (!check_size(orig1, my1))
		return (false);
	if (!check_set(orig1, my1))
		return (false);


	std::set<std::string> orig2(g_str.begin(), g_str.end());
	ft::set<std::string> my2(g_str.begin(), g_str.end());
	std::set<std::string> orig3 = orig2;
	ft::set<std::string> my3 = my2;
	if (!check_size(orig3, my3))
		return (false);
	if (!check_set(orig3, my3))
		return (false);

	return true;
}
bool begin_end_set_test()
{
	std::set<int> orig(g_vec.begin(), g_vec.end());
	ft::set<int> my(g_vec.begin(), g_vec.end());
	std::set<int>::iterator it;
	ft::set<int>::iterator my_it;

	it = orig.begin();
	my_it = my.begin();
	if (*it != *my_it)
	{
		std::cout << "\norig elem = " << *it << " my elem = " << *my_it << std::endl;
		return (false);
	}

	it = ++orig.begin();
	my_it = ++my.begin();
	if (*it != *my_it)
	{
		std::cout << "\norig elem = " << *it << " my elem = " << *my_it << std::endl;
		return (false);
	}

	it = orig.begin()++;
	my_it = my.begin()++;
	if (*it != *my_it)
	{
		std::cout << "\norig elem = " << *it << " my elem = " << *my_it << std::endl;
		return (false);
	}

	it = --orig.end();
	my_it = --my.end();
	if (*it != *my_it)
	{
		std::cout << "\norig elem = " << *it << " my elem = " << *my_it << std::endl;
		return (false);
	}

	return true;
}
bool rbegin_rend_set_test()
{
	std::set<int> orig(g_vec.begin(), g_vec.end());
	ft::set<int> my(g_vec.begin(), g_vec.end());
	std::set<int>::reverse_iterator r_it = orig.rbegin();
	ft::set<int>::reverse_iterator my_r_it = my.rbegin();

	if (*r_it != *my_r_it)
	{
		std::cout << "\norig elem = " << *r_it << " my elem = " << *my_r_it << std::endl;
		return (false);
	}

	r_it = ++orig.rbegin();
	my_r_it = ++my.rbegin();
	if (*r_it != *my_r_it)
	{
		std::cout << "\norig elem = " << *r_it << " my elem = " << *my_r_it << std::endl;
		return (false);
	}

	r_it = orig.rbegin()++;
	my_r_it = my.rbegin()++;
	if (*r_it != *my_r_it)
	{
		std::cout << "\norig elem = " << *r_it << " my elem = " << *my_r_it << std::endl;
		return (false);
	}

	r_it = --orig.rend();
	my_r_it = --my.rend();
	if (*r_it != *my_r_it)
	{
		std::cout << "\norig elem = " << *r_it << " my elem = " << *my_r_it << std::endl;
		return (false);
	}

	return true;

}
bool clear_set_test()
{
	std::set<int> orig(g_vec.begin(), g_vec.end());
	ft::set<int> my(g_vec.begin(), g_vec.end());
	if (!check_size(orig, my))
		return (false);
	if (!check_set(orig, my))
		return (false);

	orig.clear();
	my.clear();
	if (!check_size(orig, my))
		return (false);
	if (!check_set(orig, my))
		return (false);

	orig.clear();
	my.clear();
	if (!check_size(orig, my))
		return (false);
	if (!check_set(orig, my))
		return (false);
	
	return true;
}
bool count_set_test()
{
	std::set<int> orig(g_vec.begin(), g_vec.end());
	ft::set<int> my(g_vec.begin(), g_vec.end());

	if (orig.count(16) != orig.count(16))
		return false;
	if (orig.count(-21) != orig.count(-21))
		return false;
	if (orig.count(100) != orig.count(100))
		return false;
	if (orig.count(55) != orig.count(55))
		return false;
	if (orig.count(4) != orig.count(4))
		return false;
	if (orig.count(8) != orig.count(8))
		return false;
	if (orig.count(-200) != orig.count(-200))
		return false;
	if (orig.count(10) != orig.count(10))
		return false;
	if (orig.count(1) != orig.count(1))
		return false;
	
	return true;
}
bool empty_set_test()
{
	std::set<std::string> orig1;
	ft::set<std::string> my1;
	if (orig1.empty() != my1.empty())
	{
		std::cout << "Error empty" << std::endl;
		return false;
	}

	orig1.insert("Friday");
	my1.insert("Friday");
	if (orig1.empty() != my1.empty())
	{
		std::cout << "Error empty" << std::endl;
		return false;
	}
	return true;
}
bool erase_set_test()
{
	//iterator position
	std::set<int> orig(g_vec.begin(), g_vec.end());
	ft::set<int> my(g_vec.begin(), g_vec.end());
			
	orig.erase(orig.begin());
	my.erase(my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_set(orig, my))
		return (false);

	orig.erase(++orig.begin());
	my.erase(++my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_set(orig, my))
		return (false);

	orig.erase(--orig.end());
	my.erase(--my.end());
	if (!check_size(orig, my))
		return (false);
	if (!check_set(orig, my))
		return (false);

	std::set<int>::iterator it = orig.find(14);
	ft::set<int>::iterator my_it = my.find(14);
	orig.erase(it);
	my.erase(my_it);
	if (!check_size(orig, my))
		return (false);
	if (!check_set(orig, my))
		return (false);

	orig.erase(orig.begin());
	my.erase(my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_set(orig, my))
		return (false);

	orig.erase(++orig.begin());
	my.erase(++my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_set(orig, my))
		return (false);

	orig.erase(++orig.begin());
	my.erase(++my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_set(orig, my))
		return (false);
	
	orig.erase(orig.begin());
	my.erase(my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_set(orig, my))
		return (false);


	//const key_type& k
	orig.insert(64);
	my.insert(64);
	orig.erase(64);
	my.erase(64);
	if (!check_size(orig, my))
		return (false);
	if (!check_set(orig, my))
		return (false);

	orig.erase(10000);
	my.erase(10000);
	if (!check_size(orig, my))
		return (false);
	if (!check_set(orig, my))
		return (false);

	std::set<std::string> orig1(g_str.begin(), g_str.end());
	ft::set<std::string> my1(g_str.begin(), g_str.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_set(orig1, my1))
		return (false);

	orig1.erase("seven_1");
	my1.erase("seven_1");
	if (!check_size(orig1, my1))
		return (false);
	if (!check_set(orig1, my1))
		return (false);

	orig1.erase("eleven");
	my1.erase("eleven");
	if (!check_size(orig1, my1))
		return (false);
	if (!check_set(orig1, my1))
		return (false);
	
	orig1.erase("thousand");
	my1.erase("thousand");
	if (!check_size(orig1, my1))
		return (false);
	if (!check_set(orig1, my1))
		return (false);

	//iterator first, iterator last
	std::set<int> orig2(g_vec.begin(), g_vec.end());
	ft::set<int> my2(g_vec.begin(), g_vec.end());

	it = orig2.find(53);
	my_it = my2.find(53);

	orig2.erase(++orig2.begin(), it);
	my2.erase(++my2.begin(), my_it);
	if (!check_size(orig2, my2))
		return (false);
	if (!check_set(orig2, my2))
		return (false);

	orig2.erase(it, --orig2.end());
	my2.erase(my_it, --my2.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_set(orig2, my2))
		return (false);

	orig2.erase(orig2.begin(), orig2.end());
	my2.erase(my2.begin(), my2.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_set(orig2, my2))
		return (false);

	return true;
}
bool equal_range_set_test()
{
	std::set<int> orig(g_vec.begin(), g_vec.end());
	ft::set<int> my(g_vec.begin(), g_vec.end());

	std::pair<std::set<int>::iterator, std::set<int>::iterator> orig_pr;
	std::pair<ft::set<int>::iterator, ft::set<int>::iterator> my_pr;

	orig_pr = orig.equal_range(6);
	my_pr = my.equal_range(6);
	if (*orig_pr.first != *my_pr.first || *orig_pr.second != *my_pr.second)
	{
		std::cout << "\norig first = " << *orig_pr.first << " orig second = " << *orig_pr.second << std::endl;
		std::cout << "\nmy first = " << *my_pr.first << " my second = " << *my_pr.second << std::endl;
		return (false);
	}
	orig_pr = orig.equal_range(1);
	my_pr = my.equal_range(1);
	if (*orig_pr.first != *my_pr.first || *orig_pr.second != *my_pr.second)
	{
		std::cout << "\norig first = " << *orig_pr.first << " orig second = " << *orig_pr.second << std::endl;
		std::cout << "\nmy first = " << *my_pr.first << " my second = " << *my_pr.second << std::endl;
		return (false);
	}
	return true;

}
bool find_set_test()
{
	std::set<int> orig(g_vec.begin(), g_vec.end());
	ft::set<int> my(g_vec.begin(), g_vec.end());

	std::set<int>::iterator it;
	ft::set<int>::iterator my_it;

	it = orig.find(1000);
	my_it = my.find(1000);
	if (it != orig.end() || my_it != my.end())
		return false;

	it = orig.find(30);
	my_it = my.find(30);
	if (*it != *my_it)
	{
		std::cout << "\norig = " << *it << std::endl;
		std::cout << "\nmy = " << *my_it << std::endl;
		return (false);
	}
	
	return true;
}
bool insert_set_test()
{
	//single element
	std::set<int> orig;
	ft::set<int> my;

	orig.insert(10);
	my.insert(10);
	if (!check_size(orig, my))
		return (false);
	if (!check_set(orig, my))
		return (false);
	
	orig.insert(20);
	my.insert(20);
	if (!check_size(orig, my))
		return (false);
	if (!check_set(orig, my))
		return (false);

	orig.insert(10);
	my.insert(10);
	if (!check_size(orig, my))
		return (false);
	if (!check_set(orig, my))
		return (false);

	orig.insert(15);
	my.insert(15);
	if (!check_size(orig, my))
		return (false);
	if (!check_set(orig, my))
		return (false);

	std::set<int> orig1(g_vec.begin(), g_vec.end());
	ft::set<int> my1(g_vec.begin(), g_vec.end());
	std::set<int>::iterator it;
	ft::set<int>::iterator my_it;

	orig1.insert(15);
	my1.insert(15);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_set(orig1, my1))
		return (false);
	
	orig1.insert(33);
	my1.insert(33);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_set(orig1, my1))
		return (false);

	//with hint
	it = orig1.find(27);
	my_it = my1.find(27);
	orig1.insert(it, 20);
	my1.insert(my_it, 20);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_set(orig1, my1))
		return (false);
	
	it = orig1.find(10000);
	my_it = my1.find(10000);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_set(orig1, my1))
		return (false);
	
	//range
	std::set<int> orig2;
	ft::set<int> my2;

	orig2.insert(g_vec.begin(), g_vec.end());
	my2.insert(g_vec.begin(), g_vec.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_set(orig2, my2))
		return (false);

	orig2.insert(g_vec1.begin(), g_vec1.end());
	my2.insert(g_vec1.begin(), g_vec1.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_set(orig2, my2))
		return (false);

	std::set<std::string> orig3;
	ft::set<std::string> my3;
	orig3.insert(g_str.begin(), g_str.end());
	my3.insert(g_str.begin(), g_str.end());
	if (!check_size(orig3, my3))
		return (false);
	if (!check_set(orig3, my3))
		return (false);

	orig3.insert(g_str.rbegin(), g_str.rend());
	my3.insert(g_str.rbegin(), g_str.rend());
	if (!check_size(orig3, my3))
		return (false);
	if (!check_set(orig3, my3))
		return (false);
	
	return true;
}
bool lower_bound_set_test()
{
	std::set<int> orig(g_vec.begin(), g_vec.end());
	ft::set<int> my(g_vec.begin(), g_vec.end());

	std::set<int>::iterator it = orig.lower_bound(2);
	ft::set<int>::iterator my_it = my.lower_bound(2);
	if (*it != *my_it)
	{
		std::cout << "\norig = " << *it << std::endl;
		std::cout << "\nmy = " << *my_it << std::endl;
		return (false);
	}
	it = orig.lower_bound(7);
	my_it = my.lower_bound(7);

	if (*it != *my_it)
	{
		std::cout << "\norig = " << *it << std::endl;
		std::cout << "\nmy = " << *my_it << std::endl;
		return (false);
	}
	return true;
}
bool max_size_set_test()
{
	std::set<int> orig;
	ft::set<int> my;
	orig.insert(10);
	my.insert(10);
	if (orig.max_size() != my.max_size())
	{
		std::cout << "\nOrig max_size = " << orig.max_size() << std::endl;
		std::cout << "My max_size = " << my.max_size() << std::endl;
		return false;
	}
	return true;

}

bool size_set_test()
{
	std::set<int> orig1;
	ft::set<int> my1;
	if (!check_size(orig1, my1))
		return (false);

	std::set<int> orig2(g_vec.begin(), g_vec.end());
	ft::set<int> my2(g_vec.begin(), g_vec.end());
	if (!check_size(orig1, my1))
		return (false);

	return true;

}
bool swap_set_test()
{
	std::set<int> orig1(g_vec.begin(), g_vec.end());
	ft::set<int> my1(g_vec.begin(), g_vec.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_set(orig1, my1))
		return (false);

	std::set<int> orig2(g_vec1.begin(), g_vec1.end());
	ft::set<int> my2(g_vec1.begin(), g_vec1.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_set(orig2, my2))
		return (false);

	orig1.swap(orig2);
	my1.swap(my2);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_set(orig1, my1))
		return (false);

	orig2.swap(orig1);
	my2.swap(my1);
	if (!check_size(orig2, my2))
		return (false);
	if (!check_set(orig2, my2))
		return (false);

	return true;
}
bool upper_bound_set_test()
{
	std::set<int> orig(g_vec.begin(), g_vec.end());
	ft::set<int> my(g_vec.begin(), g_vec.end());

	std::set<int>::iterator it = orig.upper_bound(2);
	ft::set<int>::iterator my_it = my.upper_bound(2);
	if (*it != *my_it)
	{
		std::cout << "\norig = " << *it << std::endl;
		std::cout << "\nmy = " << *my_it << std::endl;
		return (false);
	}
	it = orig.upper_bound(4);
	my_it = my.upper_bound(4);
	if (*it != *my_it)
	{
		std::cout << "\norig = " << *it << std::endl;
		std::cout << "\nmy = " << *my_it << std::endl;
		return (false);
	}
	return true;

}
bool relational_set_test()
{
	std::set<int> orig1(g_vec.begin(), g_vec.end());
	ft::set<int> my1(g_vec.begin(), g_vec.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_set(orig1, my1))
		return (false);

	std::set<int> orig2(g_vec1.begin(), g_vec1.end());
	ft::set<int> my2(g_vec1.begin(), g_vec1.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_set(orig2, my2))
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
		std::cout << "Error operator <=" << std::endl;
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
bool swap_set_set_test()
{
	std::set<int> orig1(g_vec.begin(), g_vec.end());
	ft::set<int> my1(g_vec.begin(), g_vec.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_set(orig1, my1))
		return (false);

	std::set<int> orig2(g_vec1.begin(), g_vec1.end());
	ft::set<int> my2(g_vec1.begin(), g_vec1.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_set(orig2, my2))
		return (false);

	std::swap(orig1, orig2);
	ft::swap(my1, my2);

	if (!check_size(orig1, my1))
		return (false);
	if (!check_set(orig1, my1))
		return (false);

	if (!check_size(orig2, my2))
		return (false);
	if (!check_set(orig2, my2))
		return (false);

	return true;

}

void set_start()
{
	std::cout << BOLDCYAN << "|=================================================================================================|" << std::endl;
	std::cout << "|                                        Set tests                                                |" << std::endl;
	std::cout << "|=================================================================================================|" << std::endl;
	std::cout << BOLDCYAN << "\n[constructor]: \t\t" << ((constructor_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[operator=]: \t\t" << ((assigment_operator_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[begin/end]: \t\t" << ((begin_end_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[rbegin/rend]: \t\t" << ((rbegin_rend_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[clear]: \t\t" << ((clear_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[count]: \t\t" << ((count_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[empty]: \t\t" << ((empty_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[erase]: \t\t" << ((erase_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[equal_range]: \t\t" << ((equal_range_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[find]: \t\t" << ((find_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[insert]: \t\t" << ((insert_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[lower_bound]: \t\t" << ((lower_bound_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[max_size]: \t\t" << ((max_size_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[size]: \t\t" << ((size_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[swap]: \t\t" << ((swap_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[upper_bound]: \t\t" << ((upper_bound_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[relational_operators]\t" << ((relational_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[swap_set] \t\t" << ((swap_set_set_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
}