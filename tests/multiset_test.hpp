#pragma once

#include "test.hpp"

template<typename T>
bool check_size(std::multiset<T> &orig, ft::multiset<T> &my)
{
	if (orig.size() == my.size())
		return true;
	std::cout << "\nOrig size = " << orig.size() << std::endl;
	std::cout << "My size = " << my.size() << std::endl;
	return false;
}

template<typename T>
bool check_multiset(std::multiset<T> &orig, ft::multiset<T> &my)
{
	typename std::multiset<T>::iterator orig_begin = orig.begin();
	typename std::multiset<T>::iterator orig_end = orig.end();
	typename ft::multiset<T>::iterator my_begin = my.begin();
	typename ft::multiset<T>::iterator my_end = my.end();

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

	typename std::multiset<T>::reverse_iterator orig_rbegin = orig.rbegin();
	typename std::multiset<T>::reverse_iterator orig_rend = orig.rend();
	typename ft::multiset<T>::reverse_iterator my_rbegin = my.rbegin();
	typename ft::multiset<T>::reverse_iterator my_rend = my.rend();
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

bool constructor_multiset_test()
{
	//empty constructor
	std::multiset<int> orig1;
	ft::multiset<int> my1;
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multiset(orig1, my1))
		return (false);

	std::multiset<std::string> orig2;
	ft::multiset<std::string> my2;
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multiset(orig2, my2))
		return (false);

	//range constructor

	std::multiset<int> orig3(g_vec1.begin(), g_vec1.end());
	ft::multiset<int> my3(g_vec1.begin(), g_vec1.end());
	if (!check_size(orig3, my3))
		return (false);
	if (!check_multiset(orig3, my3))
		return (false);

	std::multiset<std::string> orig4(g_str.begin(), g_str.end());
	ft::multiset<std::string> my4(g_str.begin(), g_str.end());
	if (!check_size(orig4, my4))
		return (false);
	if (!check_multiset(orig4, my4))
		return (false);

	//copy constructor
	std::multiset<std::string> orig5(orig4);
	ft::multiset<std::string> my5(my4);
	if (!check_size(orig5, my5))
		return (false);
	if (!check_multiset(orig5, my5))
		return (false);

	std::multiset<int> orig6(orig3);
	ft::multiset<int> my6(my3);
	if (!check_size(orig6, my6))
		return (false);
	if (!check_multiset(orig6, my6))
		return (false);
	
	return true;

}
bool assigment_operator_multiset_test()
{
	std::multiset<int> orig(g_vec1.begin(), g_vec1.end());
	ft::multiset<int> my(g_vec1.begin(), g_vec1.end());
	std::multiset<int> orig1 = orig;
	ft::multiset<int> my1 = my;
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multiset(orig1, my1))
		return (false);


	std::multiset<std::string> orig2(g_str.begin(), g_str.end());
	ft::multiset<std::string> my2(g_str.begin(), g_str.end());
	std::multiset<std::string> orig3 = orig2;
	ft::multiset<std::string> my3 = my2;
	if (!check_size(orig3, my3))
		return (false);
	if (!check_multiset(orig3, my3))
		return (false);

	return true;
}
bool begin_end_multiset_test()
{
	std::multiset<int> orig(g_vec1.begin(), g_vec1.end());
	ft::multiset<int> my(g_vec1.begin(), g_vec1.end());
	std::multiset<int>::iterator it;
	ft::multiset<int>::iterator my_it;

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
bool rbegin_rend_multiset_test()
{
	std::multiset<int> orig(g_vec1.begin(), g_vec1.end());
	ft::multiset<int> my(g_vec1.begin(), g_vec1.end());
	std::multiset<int>::reverse_iterator r_it = orig.rbegin();
	ft::multiset<int>::reverse_iterator my_r_it = my.rbegin();

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
bool clear_multiset_test()
{
	std::multiset<int> orig(g_vec1.begin(), g_vec1.end());
	ft::multiset<int> my(g_vec1.begin(), g_vec1.end());
	if (!check_size(orig, my))
		return (false);
	if (!check_multiset(orig, my))
		return (false);

	orig.clear();
	my.clear();
	if (!check_size(orig, my))
		return (false);
	if (!check_multiset(orig, my))
		return (false);

	orig.clear();
	my.clear();
	if (!check_size(orig, my))
		return (false);
	if (!check_multiset(orig, my))
		return (false);
	
	return true;
}
bool count_multiset_test()
{
	std::multiset<int> orig(g_vec1.begin(), g_vec1.end());
	ft::multiset<int> my(g_vec1.begin(), g_vec1.end());
	orig.insert(g_vec1.begin(), g_vec1.end());
	my.insert(g_vec1.begin(), g_vec1.end());

	if (orig.count(14) != orig.count(14))
		return false;
	if (orig.count(-21) != orig.count(-21))
		return false;
	if (orig.count(2) != orig.count(2))
		return false;
	if (orig.count(55) != orig.count(55))
		return false;
	if (orig.count(9) != orig.count(9))
		return false;
	if (orig.count(-32) != orig.count(-32))
		return false;
	if (orig.count(-200) != orig.count(-200))
		return false;
	if (orig.count(10) != orig.count(10))
		return false;
	if (orig.count(1) != orig.count(1))
		return false;
	
	return true;
}
bool empty_multiset_test()
{
	std::multiset<std::string> orig1;
	ft::multiset<std::string> my1;
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
bool erase_multiset_test()
{
	//iterator position
	std::multiset<int> orig(g_vec.begin(), g_vec.end());
	ft::multiset<int> my(g_vec.begin(), g_vec.end());
			
	orig.erase(orig.begin());
	my.erase(my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_multiset(orig, my))
		return (false);

	orig.erase(++orig.begin());
	my.erase(++my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_multiset(orig, my))
		return (false);

	orig.erase(--orig.end());
	my.erase(--my.end());
	if (!check_size(orig, my))
		return (false);
	if (!check_multiset(orig, my))
		return (false);

	std::multiset<int>::iterator it = orig.find(14);
	ft::multiset<int>::iterator my_it = my.find(14);
	orig.erase(it);
	my.erase(my_it);
	if (!check_size(orig, my))
		return (false);
	if (!check_multiset(orig, my))
		return (false);

	orig.erase(orig.begin());
	my.erase(my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_multiset(orig, my))
		return (false);

	orig.erase(++orig.begin());
	my.erase(++my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_multiset(orig, my))
		return (false);

	orig.erase(++orig.begin());
	my.erase(++my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_multiset(orig, my))
		return (false);
	
	orig.erase(orig.begin());
	my.erase(my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_multiset(orig, my))
		return (false);


	//const key_type& k
	orig.insert(64);
	my.insert(64);
	orig.erase(64);
	my.erase(64);
	if (!check_size(orig, my))
		return (false);
	if (!check_multiset(orig, my))
		return (false);

	orig.erase(10000);
	my.erase(10000);
	if (!check_size(orig, my))
		return (false);
	if (!check_multiset(orig, my))
		return (false);

	std::multiset<std::string> orig1(g_str.begin(), g_str.end());
	ft::multiset<std::string> my1(g_str.begin(), g_str.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multiset(orig1, my1))
		return (false);

	orig1.erase("seven_1");
	my1.erase("seven_1");
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multiset(orig1, my1))
		return (false);

	orig1.erase("eleven");
	my1.erase("eleven");
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multiset(orig1, my1))
		return (false);
	
	orig1.erase("thousand");
	my1.erase("thousand");
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multiset(orig1, my1))
		return (false);

	//iterator first, iterator last
	std::multiset<int> orig2(g_vec.begin(), g_vec.end());
	ft::multiset<int> my2(g_vec.begin(), g_vec.end());

	it = orig2.find(9);
	my_it = my2.find(9);

	orig2.erase(++orig2.begin(), it);
	my2.erase(++my2.begin(), my_it);
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multiset(orig2, my2))
		return (false);

	orig2.erase(it, --orig2.end());
	my2.erase(my_it, --my2.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multiset(orig2, my2))
		return (false);

	orig2.erase(orig2.begin(), orig2.end());
	my2.erase(my2.begin(), my2.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multiset(orig2, my2))
		return (false);

	return true;
}
bool equal_range_multiset_test()
{
	std::multiset<int> orig(g_vec1.begin(), g_vec1.end());
	ft::multiset<int> my(g_vec1.begin(), g_vec1.end());

	std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> orig_pr;
	std::pair<ft::multiset<int>::iterator, ft::multiset<int>::iterator> my_pr;

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
bool find_multiset_test()
{
	std::multiset<int> orig(g_vec.begin(), g_vec.end());
	ft::multiset<int> my(g_vec.begin(), g_vec.end());

	std::multiset<int>::iterator it;
	ft::multiset<int>::iterator my_it;

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
bool insert_multiset_test()
{
	//single element
	std::multiset<int> orig;
	ft::multiset<int> my;

	orig.insert(10);
	my.insert(10);
	if (!check_size(orig, my))
		return (false);
	if (!check_multiset(orig, my))
		return (false);
	
	orig.insert(20);
	my.insert(20);
	if (!check_size(orig, my))
		return (false);
	if (!check_multiset(orig, my))
		return (false);

	orig.insert(10);
	my.insert(10);
	if (!check_size(orig, my))
		return (false);
	if (!check_multiset(orig, my))
		return (false);

	orig.insert(15);
	my.insert(15);
	if (!check_size(orig, my))
		return (false);
	if (!check_multiset(orig, my))
		return (false);

	std::multiset<int> orig1(g_vec1.begin(), g_vec1.end());
	ft::multiset<int> my1(g_vec1.begin(), g_vec1.end());
	std::multiset<int>::iterator it;
	ft::multiset<int>::iterator my_it;

	orig1.insert(15);
	my1.insert(15);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multiset(orig1, my1))
		return (false);
	
	orig1.insert(33);
	my1.insert(33);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multiset(orig1, my1))
		return (false);

	//with hint
	it = orig1.find(27);
	my_it = my1.find(27);
	orig1.insert(it, 20);
	my1.insert(my_it, 20);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multiset(orig1, my1))
		return (false);
	
	it = orig1.find(10000);
	my_it = my1.find(10000);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multiset(orig1, my1))
		return (false);
	
	//range
	std::multiset<int> orig2;
	ft::multiset<int> my2;

	orig2.insert(g_vec1.begin(), g_vec1.end());
	my2.insert(g_vec1.begin(), g_vec1.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multiset(orig2, my2))
		return (false);

	orig2.insert(g_vec1.begin(), g_vec1.end());
	my2.insert(g_vec1.begin(), g_vec1.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multiset(orig2, my2))
		return (false);

	std::multiset<std::string> orig3;
	ft::multiset<std::string> my3;
	orig3.insert(g_str.begin(), g_str.end());
	my3.insert(g_str.begin(), g_str.end());
	if (!check_size(orig3, my3))
		return (false);
	if (!check_multiset(orig3, my3))
		return (false);

	orig3.insert(g_str.rbegin(), g_str.rend());
	my3.insert(g_str.rbegin(), g_str.rend());
	if (!check_size(orig3, my3))
		return (false);
	if (!check_multiset(orig3, my3))
		return (false);
	
	return true;
}
bool lower_bound_multiset_test()
{
	std::multiset<int> orig(g_vec1.begin(), g_vec1.end());
	ft::multiset<int> my(g_vec1.begin(), g_vec1.end());

	std::multiset<int>::iterator it = orig.lower_bound(2);
	ft::multiset<int>::iterator my_it = my.lower_bound(2);
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
bool max_size_multiset_test()
{
	std::multiset<int> orig;
	ft::multiset<int> my;
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

bool size_multiset_test()
{
	std::multiset<int> orig1;
	ft::multiset<int> my1;
	if (!check_size(orig1, my1))
		return (false);

	std::multiset<int> orig2(g_vec1.begin(), g_vec1.end());
	ft::multiset<int> my2(g_vec1.begin(), g_vec1.end());
	if (!check_size(orig1, my1))
		return (false);

	return true;

}
bool swap_multiset_test()
{
	std::multiset<int> orig1(g_vec1.begin(), g_vec1.end());
	ft::multiset<int> my1(g_vec1.begin(), g_vec1.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multiset(orig1, my1))
		return (false);

	std::multiset<int> orig2(g_vec1.begin(), g_vec1.end());
	ft::multiset<int> my2(g_vec1.begin(), g_vec1.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multiset(orig2, my2))
		return (false);

	orig1.swap(orig2);
	my1.swap(my2);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multiset(orig1, my1))
		return (false);

	orig2.swap(orig1);
	my2.swap(my1);
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multiset(orig2, my2))
		return (false);

	return true;
}
bool upper_bound_multiset_test()
{
	std::multiset<int> orig(g_vec1.begin(), g_vec1.end());
	ft::multiset<int> my(g_vec1.begin(), g_vec1.end());

	std::multiset<int>::iterator it = orig.upper_bound(2);
	ft::multiset<int>::iterator my_it = my.upper_bound(2);
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
bool relational_multiset_test()
{
	std::multiset<int> orig1(g_vec1.begin(), g_vec1.end());
	ft::multiset<int> my1(g_vec1.begin(), g_vec1.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multiset(orig1, my1))
		return (false);

	std::multiset<int> orig2(g_vec1.begin(), g_vec1.end());
	ft::multiset<int> my2(g_vec1.begin(), g_vec1.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multiset(orig2, my2))
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
bool swap_multiset_multiset_test()
{
	std::multiset<int> orig1(g_vec1.begin(), g_vec1.end());
	ft::multiset<int> my1(g_vec1.begin(), g_vec1.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multiset(orig1, my1))
		return (false);

	std::multiset<int> orig2(g_vec1.begin(), g_vec1.end());
	ft::multiset<int> my2(g_vec1.begin(), g_vec1.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multiset(orig2, my2))
		return (false);

	std::swap(orig1, orig2);
	ft::swap(my1, my2);

	if (!check_size(orig1, my1))
		return (false);
	if (!check_multiset(orig1, my1))
		return (false);

	if (!check_size(orig2, my2))
		return (false);
	if (!check_multiset(orig2, my2))
		return (false);

	return true;

}

void multiset_start()
{
	std::cout << BOLDCYAN << "|=================================================================================================|" << std::endl;
	std::cout << "|                                        Multiset tests                                           |" << std::endl;
	std::cout << "|=================================================================================================|" << std::endl;
	std::cout << BOLDCYAN << "\n[constructor]: \t\t" << ((constructor_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[operator=]: \t\t" << ((assigment_operator_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[begin/end]: \t\t" << ((begin_end_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[rbegin/rend]: \t\t" << ((rbegin_rend_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[clear]: \t\t" << ((clear_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[count]: \t\t" << ((count_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[empty]: \t\t" << ((empty_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[erase]: \t\t" << ((erase_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[equal_range]: \t\t" << ((equal_range_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[find]: \t\t" << ((find_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[insert]: \t\t" << ((insert_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[lower_bound]: \t\t" << ((lower_bound_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[max_size]: \t\t" << ((max_size_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[size]: \t\t" << ((size_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[swap]: \t\t" << ((swap_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[upper_bound]: \t\t" << ((upper_bound_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[relational_operators]\t" << ((relational_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[swap_multiset] \t" << ((swap_multiset_multiset_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
}