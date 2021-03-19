#pragma once

#include "test.hpp"

template<typename Key, typename T>
bool check_size(std::multimap<Key, T> &orig, ft::multimap<Key, T> &my)
{
	if (orig.size() == my.size())
		return true;
	std::cout << "\nOrig size = " << orig.size() << std::endl;
	std::cout << "My size = " << my.size() << std::endl;
	return false;
}

template<typename Key, typename T>
bool check_multimap(std::multimap<Key, T> &orig, ft::multimap<Key, T> &my)
{
	typename std::multimap<Key, T>::iterator orig_begin = orig.begin();
	typename std::multimap<Key, T>::iterator orig_end = orig.end();
	typename ft::multimap<Key, T>::iterator my_begin = my.begin();
	typename ft::multimap<Key, T>::iterator my_end = my.end();

	while (orig_begin != orig_end)
	{
		if (orig_begin->first != my_begin->first || orig_begin->second != my_begin->second)
		{
			std::cout << "\norig first = " << orig_begin->first << " orig second = " << orig_begin->second << std::endl;
			std::cout << "\nmy first = " << my_begin->first << " my second = " << my_begin->second << std::endl;
			return (false);
		}
		++orig_begin;
		++my_begin;
	}

	typename std::multimap<Key, T>::reverse_iterator orig_rbegin = orig.rbegin();
	typename std::multimap<Key, T>::reverse_iterator orig_rend = orig.rend();
	typename ft::multimap<Key, T>::reverse_iterator my_rbegin = my.rbegin();
	typename ft::multimap<Key, T>::reverse_iterator my_rend = my.rend();
	while (orig_rbegin != orig_rend)
	{
		if (orig_rbegin->first != my_rbegin->first || orig_rbegin->second != my_rbegin->second)
		{
			std::cout << "\norig first = " << orig_rbegin->first << " orig second = " << orig_rbegin->second << std::endl;
			std::cout << "\nmy first = " << my_rbegin->first << " my second = " << my_rbegin->second << std::endl;
			return (false);
		}
		++orig_rbegin;
		++my_rbegin;
	}
	return (true);
}

bool constructor_multimap_test()
{
	//empty constructor
	std::multimap<int, int> orig1;
	ft::multimap<int, int> my1;
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multimap(orig1, my1))
		return (false);

	std::multimap<std::string, double> orig2;
	ft::multimap<std::string, double> my2;
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multimap(orig2, my2))
		return (false);

	//range constructor

	std::multimap<int, int> orig3(g_map1.begin(), g_map1.end());
	ft::multimap<int, int> my3(g_map1.begin(), g_map1.end());
	if (!check_size(orig3, my3))
		return (false);
	if (!check_multimap(orig3, my3))
		return (false);

	std::multimap<std::string, int> orig4(g_map3.begin(), g_map3.end());
	ft::multimap<std::string, int> my4(g_map3.begin(), g_map3.end());
	if (!check_size(orig4, my4))
		return (false);
	if (!check_multimap(orig4, my4))
		return (false);

	//copy constructor
	std::multimap<std::string, int> orig5(orig4);
	ft::multimap<std::string, int> my5(my4);
	if (!check_size(orig5, my5))
		return (false);
	if (!check_multimap(orig5, my5))
		return (false);

	std::multimap<int, int> orig6(orig3);
	ft::multimap<int, int> my6(my3);
	if (!check_size(orig6, my6))
		return (false);
	if (!check_multimap(orig6, my6))
		return (false);
	
	return true;

}
bool assigment_operator_multimap_test()
{
	std::multimap<int, int> orig(g_map1.begin(), g_map1.end());
	ft::multimap<int, int> my(g_map1.begin(), g_map1.end());
	std::multimap<int, int> orig1 = orig;
	ft::multimap<int, int> my1 = my;
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multimap(orig1, my1))
		return (false);


	std::multimap<std::string, int> orig2(g_map3.begin(), g_map3.end());
	ft::multimap<std::string, int> my2(g_map3.begin(), g_map3.end());
	std::multimap<std::string, int> orig3 = orig2;
	ft::multimap<std::string, int> my3 = my2;
	if (!check_size(orig3, my3))
		return (false);
	if (!check_multimap(orig3, my3))
		return (false);

	return true;
}
bool begin_end_multimap_test()
{
	std::multimap<int, int> orig(g_map1.begin(), g_map1.end());
	ft::multimap<int, int> my(g_map1.begin(), g_map1.end());
	std::multimap<int, int>::iterator it;
	ft::multimap<int, int>::iterator my_it;

	it = orig.begin();
	my_it = my.begin();
	if (it->first != my_it->first || it->second != my_it->second)
	{
		std::cout << "\norig first = " << it->first << " orig second = " << it->second << std::endl;
		std::cout << "\nmy first = " << my_it->first << " my second = " << my_it->second << std::endl;
		return (false);
	}

	it = ++orig.begin();
	my_it = ++my.begin();
	if (it->first != my_it->first || it->second != my_it->second)
	{
		std::cout << "\norig first = " << it->first << " orig second = " << it->second << std::endl;
		std::cout << "\nmy first = " << my_it->first << " my second = " << my_it->second << std::endl;
		return (false);
	}

	it = orig.begin()++;
	my_it = my.begin()++;
	if (it->first != my_it->first || it->second != my_it->second)
	{
		std::cout << "\norig first = " << it->first << " orig second = " << it->second << std::endl;
		std::cout << "\nmy first = " << my_it->first << " my second = " << my_it->second << std::endl;
		return (false);
	}

	it = --orig.end();
	my_it = --my.end();
	if (it->first != my_it->first || it->second != my_it->second)
	{
		std::cout << "\norig first = " << it->first << " orig second = " << it->second << std::endl;
		std::cout << "\nmy first = " << my_it->first << " my second = " << my_it->second << std::endl;
		return (false);
	}

	return true;
}
bool rbegin_rend_multimap_test()
{
	std::multimap<int, int> orig(g_map1.begin(), g_map1.end());
	ft::multimap<int, int> my(g_map1.begin(), g_map1.end());
	std::multimap<int, int>::reverse_iterator r_it = orig.rbegin();
	ft::multimap<int, int>::reverse_iterator my_r_it = my.rbegin();

	if (r_it->first != my_r_it->first || r_it->second != my_r_it->second)
	{
		std::cout << "\norig first = " << r_it->first << " orig second = " << r_it->second << std::endl;
		std::cout << "\nmy first = " << my_r_it->first << " my second = " << my_r_it->second << std::endl;
		return (false);
	}

	r_it = ++orig.rbegin();
	my_r_it = ++my.rbegin();
	if (r_it->first != my_r_it->first || r_it->second != my_r_it->second)
	{
		std::cout << "\norig first = " << r_it->first << " orig second = " << r_it->second << std::endl;
		std::cout << "\nmy first = " << my_r_it->first << " my second = " << my_r_it->second << std::endl;
		return (false);
	}

	r_it = orig.rbegin()++;
	my_r_it = my.rbegin()++;
	if (r_it->first != my_r_it->first || r_it->second != my_r_it->second)
	{
		std::cout << "\norig first = " << r_it->first << " orig second = " << r_it->second << std::endl;
		std::cout << "\nmy first = " << my_r_it->first << " my second = " << my_r_it->second << std::endl;
		return (false);
	}

	r_it = --orig.rend();
	my_r_it = --my.rend();
	if (r_it->first != my_r_it->first || r_it->second != my_r_it->second)
	{
		std::cout << "\norig first = " << r_it->first << " orig second = " << r_it->second << std::endl;
		std::cout << "\nmy first = " << my_r_it->first << " my second = " << my_r_it->second << std::endl;
		return (false);
	}

	return true;

}
bool clear_multimap_test()
{
	std::multimap<int, int> orig(g_map1.begin(), g_map1.end());
	ft::multimap<int, int> my(g_map1.begin(), g_map1.end());
	if (!check_size(orig, my))
		return (false);
	if (!check_multimap(orig, my))
		return (false);

	orig.clear();
	my.clear();
	if (!check_size(orig, my))
		return (false);
	if (!check_multimap(orig, my))
		return (false);

	orig.clear();
	my.clear();
	if (!check_size(orig, my))
		return (false);
	if (!check_multimap(orig, my))
		return (false);
	
	return true;
}
bool count_multimap_test()
{
	std::multimap<int, int> orig(g_map1.begin(), g_map1.end());
	ft::multimap<int, int> my(g_map1.begin(), g_map1.end());

	orig.insert(g_map1.begin(), g_map1.end());
	my.insert(g_map1.begin(), g_map1.end());

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
bool empty_multimap_test()
{
	std::multimap<int, std::string> orig1;
	ft::multimap<int, std::string> my1;
	if (orig1.empty() != my1.empty())
	{
		std::cout << "Error empty" << std::endl;
		return false;
	}

	orig1.insert(std::make_pair(1, "one"));
	my1.insert(std::make_pair(1, "one"));

	if (orig1.empty() != my1.empty())
	{
		std::cout << "Error empty" << std::endl;
		return false;
	}
	return true;
}
bool erase_multimap_test()
{
	//iterator position
	std::multimap<int, int> orig(g_map1.begin(), g_map1.end());
	ft::multimap<int, int> my(g_map1.begin(), g_map1.end());
			
	orig.erase(orig.begin());
	my.erase(my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_multimap(orig, my))
		return (false);

	orig.erase(++orig.begin());
	my.erase(++my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_multimap(orig, my))
		return (false);

	orig.erase(--orig.end());
	my.erase(--my.end());
	if (!check_size(orig, my))
		return (false);
	if (!check_multimap(orig, my))
		return (false);

	std::multimap<int, int>::iterator it = orig.find(11);
	ft::multimap<int, int>::iterator my_it = my.find(11);
	orig.erase(it);
	my.erase(my_it);
	if (!check_size(orig, my))
		return (false);
	if (!check_multimap(orig, my))
		return (false);

	orig.erase(orig.begin());
	my.erase(my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_multimap(orig, my))
		return (false);

	orig.erase(++orig.begin());
	my.erase(++my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_multimap(orig, my))
		return (false);

	orig.erase(++orig.begin());
	my.erase(++my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_multimap(orig, my))
		return (false);
	
	orig.erase(orig.begin());
	my.erase(my.begin());
	if (!check_size(orig, my))
		return (false);
	if (!check_multimap(orig, my))
		return (false);


	//const key_type& k
	orig.insert(std::make_pair(64, 1));
	my.insert(std::make_pair(64, 1));
	orig.erase(64);
	my.erase(64);
	if (!check_size(orig, my))
		return (false);
	if (!check_multimap(orig, my))
		return (false);

	orig.erase(10000);
	my.erase(10000);
	if (!check_size(orig, my))
		return (false);
	if (!check_multimap(orig, my))
		return (false);

	std::multimap<std::string, int> orig1(g_map3.begin(), g_map3.end());
	ft::multimap<std::string, int> my1(g_map3.begin(), g_map3.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multimap(orig1, my1))
		return (false);

	orig1.erase("seven");
	my1.erase("seven");
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multimap(orig1, my1))
		return (false);

	orig1.erase("eleven");
	my1.erase("eleven");
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multimap(orig1, my1))
		return (false);
	
	orig1.erase("thousand");
	my1.erase("thousand");
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multimap(orig1, my1))
		return (false);

	//iterator first, iterator last
	std::multimap<int, int> orig2(g_map1.begin(), g_map1.end());
	ft::multimap<int, int> my2(g_map1.begin(), g_map1.end());

	it = orig2.find(60);
	my_it = my2.find(60);

	orig2.erase(++orig2.begin(), it);
	my2.erase(++my2.begin(), my_it);
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multimap(orig2, my2))
		return (false);

	orig2.erase(it, --orig2.end());
	my2.erase(my_it, --my2.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multimap(orig2, my2))
		return (false);

	orig2.erase(orig2.begin(), orig2.end());
	my2.erase(my2.begin(), my2.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multimap(orig2, my2))
		return (false);

	return true;
}
bool equal_range_multimap_test()
{
	std::multimap<int, int> orig(g_map1.begin(), g_map1.end());
	ft::multimap<int, int> my(g_map1.begin(), g_map1.end());

	std::pair<std::multimap<int, int>::iterator, std::multimap<int, int>::iterator> orig_pr;
	std::pair<ft::multimap<int, int>::iterator, ft::multimap<int, int>::iterator> my_pr;

	orig_pr = orig.equal_range(12);
	my_pr = my.equal_range(12);
	if (orig_pr.first->first != my_pr.first->first || orig_pr.first->second != my_pr.first->second ||
	orig_pr.second->first != my_pr.second->first || orig_pr.second->second != my_pr.second->second)
	{
		std::cout << "\norig first = " << orig_pr.first->first << " orig second = " << orig_pr.first->second << std::endl;
		std::cout << "\norig first = " << orig_pr.second->first << " orig second = " << orig_pr.second->second << std::endl;
		std::cout << "\nmy first = " <<  my_pr.first->first << " my second = " <<  my_pr.first->second << std::endl;
		std::cout << "\nmy first = " <<  my_pr.second->first << " my second = " <<  my_pr.second->second << std::endl;
		return (false);
	}
	orig_pr = orig.equal_range(7);
	my_pr = my.equal_range(7);
	if (orig_pr.first->first != my_pr.first->first || orig_pr.first->second != my_pr.first->second ||
	orig_pr.second->first != my_pr.second->first || orig_pr.second->second != my_pr.second->second)
	{
		std::cout << "\norig first = " << orig_pr.first->first << " orig second = " << orig_pr.first->second << std::endl;
		std::cout << "\norig first = " << orig_pr.second->first << " orig second = " << orig_pr.second->second << std::endl;
		std::cout << "\nmy first = " <<  my_pr.first->first << " my second = " <<  my_pr.first->second << std::endl;
		std::cout << "\nmy first = " <<  my_pr.second->first << " my second = " <<  my_pr.second->second << std::endl;
		return (false);
	}
	return true;

}
bool find_multimap_test()
{
	std::multimap<int, int> orig(g_map1.begin(), g_map1.end());
	ft::multimap<int, int> my(g_map1.begin(), g_map1.end());

	std::multimap<int, int>::iterator it;
	ft::multimap<int, int>::iterator my_it;

	it = orig.find(1000);
	my_it = my.find(1000);
	if (it != orig.end() || my_it != my.end())
		return false;

	it = orig.find(11);
	my_it = my.find(11);
	if ((it->first != my_it->first) || (it->second != my_it->second))
		return false;
	
	return true;
}
bool insert_multimap_test()
{
	//single element
	std::multimap<int, int> orig;
	ft::multimap<int, int> my;

	orig.insert(std::make_pair(10, 5));
	my.insert(std::make_pair(10, 5));
	if (!check_size(orig, my))
		return (false);
	if (!check_multimap(orig, my))
		return (false);
	
	orig.insert(std::make_pair(20, 25));
	my.insert(std::make_pair(20, 25));
	if (!check_size(orig, my))
		return (false);
	if (!check_multimap(orig, my))
		return (false);

	orig.insert(std::make_pair(10, 15));
	my.insert(std::make_pair(10, 15));
	if (!check_size(orig, my))
		return (false);
	if (!check_multimap(orig, my))
		return (false);

	orig.insert(std::make_pair(15, 15));
	my.insert(std::make_pair(15, 15));
	if (!check_size(orig, my))
		return (false);
	if (!check_multimap(orig, my))
		return (false);

	std::multimap<int, int> orig1(g_map1.begin(), g_map1.end());
	ft::multimap<int, int> my1(g_map1.begin(), g_map1.end());
	std::multimap<int, int>::iterator it;
	ft::multimap<int, int>::iterator my_it;

	orig1.insert(std::make_pair(15, 15));
	my1.insert(std::make_pair(15, 15));
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multimap(orig1, my1))
		return (false);
	
	orig1.insert(std::make_pair(33, -5));
	my1.insert(std::make_pair(33, -5));
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multimap(orig1, my1))
		return (false);


	//with hint
	it = orig1.find(27);
	my_it = my1.find(27);
	orig1.insert(it, std::make_pair(20, 10));
	my1.insert(my_it, std::make_pair(20, 10));
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multimap(orig1, my1))
		return (false);
	
	it = orig1.find(10000);
	my_it = my1.find(10000);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multimap(orig1, my1))
		return (false);
	
	//range
	std::multimap<int, int> orig2;
	ft::multimap<int, int> my2;

	orig2.insert(g_map1.begin(), g_map1.end());
	my2.insert(g_map1.begin(), g_map1.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multimap(orig2, my2))
		return (false);

	orig2.insert(g_map2.begin(), g_map2.end());
	my2.insert(g_map2.begin(), g_map2.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multimap(orig2, my2))
		return (false);

	std::multimap<std::string, int> orig3;
	ft::multimap<std::string, int> my3;
	orig3.insert(g_map3.begin(), g_map3.end());
	my3.insert(g_map3.begin(), g_map3.end());
	if (!check_size(orig3, my3))
		return (false);
	if (!check_multimap(orig3, my3))
		return (false);

	orig3.insert(g_map3.rbegin(), g_map3.rend());
	my3.insert(g_map3.rbegin(), g_map3.rend());
	if (!check_size(orig3, my3))
		return (false);
	if (!check_multimap(orig3, my3))
		return (false);
	
	return true;
}
bool lower_bound_multimap_test()
{
	std::multimap<int, int> orig(g_map1.begin(), g_map1.end());
	ft::multimap<int, int> my(g_map1.begin(), g_map1.end());

	std::multimap<int, int>::iterator it = orig.lower_bound(12);
	ft::multimap<int, int>::iterator my_it = my.lower_bound(12);
	if (it->first != my_it->first || it->second != my_it->second)
	{
		std::cout << "\norig first = " << it->first << " orig second = " << it->second << std::endl;
		std::cout << "\nmy first = " << my_it->first << " my second = " << my_it->second << std::endl;
		return (false);
	}
	it = orig.lower_bound(40);
	my_it = my.lower_bound(40);

	if (it->first != my_it->first || it->second != my_it->second)
	{
		std::cout << "\norig first = " << it->first << " orig second = " << it->second << std::endl;
		std::cout << "\nmy first = " << my_it->first << " my second = " << my_it->second << std::endl;
		return (false);
	}
	return true;
}
bool max_size_multimap_test()
{
	std::multimap<int, int> orig;
	ft::multimap<int, int> my;
	orig.insert(std::make_pair(5, 10));
	my.insert(std::make_pair(5, 10));
	if (orig.max_size() != my.max_size())
	{
		std::cout << "\nOrig max_size = " << orig.max_size() << std::endl;
		std::cout << "My max_size = " << my.max_size() << std::endl;
		return false;
	}
	return true;

}
bool size_multimap_test()
{
	std::multimap<int, int> orig1;
	ft::multimap<int, int> my1;
	if (!check_size(orig1, my1))
		return (false);

	std::multimap<int, int> orig2(g_map1.begin(), g_map1.end());
	ft::multimap<int, int> my2(g_map1.begin(), g_map1.end());
	if (!check_size(orig1, my1))
		return (false);

	return true;

}
bool swap_multimap_test()
{
	std::multimap<int, int> orig1(g_map1.begin(), g_map1.end());
	ft::multimap<int, int> my1(g_map1.begin(), g_map1.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multimap(orig1, my1))
		return (false);

	std::multimap<int, int> orig2(g_map2.begin(), g_map2.end());
	ft::multimap<int, int> my2(g_map2.begin(), g_map2.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multimap(orig2, my2))
		return (false);

	orig1.swap(orig2);
	my1.swap(my2);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multimap(orig1, my1))
		return (false);

	orig2.swap(orig1);
	my2.swap(my1);
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multimap(orig2, my2))
		return (false);

	return true;
}
bool upper_bound_multimap_test()
{
	std::multimap<int, int> orig(g_map1.begin(), g_map1.end());
	ft::multimap<int, int> my(g_map1.begin(), g_map1.end());

	std::multimap<int, int>::iterator it = orig.upper_bound(12);
	ft::multimap<int, int>::iterator my_it = my.upper_bound(12);
	if (it->first != my_it->first || it->second != my_it->second)
	{
		std::cout << "\norig first = " << it->first << " orig second = " << it->second << std::endl;
		std::cout << "\nmy first = " << my_it->first << " my second = " << my_it->second << std::endl;
		return (false);
	}
	it = orig.upper_bound(40);
	my_it = my.upper_bound(40);

	if (it->first != my_it->first || it->second != my_it->second)
	{
		std::cout << "\norig first = " << it->first << " orig second = " << it->second << std::endl;
		std::cout << "\nmy first = " << my_it->first << " my second = " << my_it->second << std::endl;
		return (false);
	}
	return true;

}
bool relational_multimap_test()
{
	std::multimap<int, int> orig1(g_map1.begin(), g_map1.end());
	ft::multimap<int, int> my1(g_map1.begin(), g_map1.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multimap(orig1, my1))
		return (false);

	std::multimap<int, int> orig2(g_map2.begin(), g_map2.end());
	ft::multimap<int, int> my2(g_map2.begin(), g_map2.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multimap(orig2, my2))
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
bool swap_multimap_multimap_test()
{
	std::multimap<int, int> orig1(g_map1.begin(), g_map1.end());
	ft::multimap<int, int> my1(g_map1.begin(), g_map1.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_multimap(orig1, my1))
		return (false);

	std::multimap<int, int> orig2(g_map2.begin(), g_map2.end());
	ft::multimap<int, int> my2(g_map2.begin(), g_map2.end());
	if (!check_size(orig2, my2))
		return (false);
	if (!check_multimap(orig2, my2))
		return (false);

	std::swap(orig1, orig2);
	ft::swap(my1, my2);

	if (!check_size(orig1, my1))
		return (false);
	if (!check_multimap(orig1, my1))
		return (false);

	if (!check_size(orig2, my2))
		return (false);
	if (!check_multimap(orig2, my2))
		return (false);

	return true;

}


void multimap_start()
{
	std::cout << BOLDCYAN << "|=================================================================================================|" << std::endl;
	std::cout << "|                                        Multimap tests                                           |" << std::endl;
	std::cout << "|=================================================================================================|" << std::endl;
	std::cout << BOLDCYAN << "\n[constructor]: \t\t" << ((constructor_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[operator=]: \t\t" << ((assigment_operator_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[begin/end]: \t\t" << ((begin_end_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[rbegin/rend]: \t\t" << ((rbegin_rend_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[clear]: \t\t" << ((clear_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[count]: \t\t" << ((count_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[empty]: \t\t" << ((empty_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[erase]: \t\t" << ((erase_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[equal_range]: \t\t" << ((equal_range_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[find]: \t\t" << ((find_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[insert]: \t\t" << ((insert_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[lower_bound]: \t\t" << ((lower_bound_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[max_size]: \t\t" << ((max_size_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[size]: \t\t" << ((size_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[swap]: \t\t" << ((swap_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[upper_bound]: \t\t" << ((upper_bound_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[relational_operators]\t" << ((relational_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[swap_multimap] \t" << ((swap_multimap_multimap_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
}