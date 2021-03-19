#pragma once

#include "test.hpp" //убрать

template<typename T>
bool check_size(std::vector<T> &orig, ft::vector<T> &my)
{
	if (orig.size() == my.size())
		return true;
    std::cout << "\nOrig size = " << orig.size() << std::endl;
    std::cout << "My size = " << my.size() << std::endl;
	return false;
}
template<typename T>
bool check_capacity(std::vector<T> &orig, ft::vector<T> &my)
{
	if (orig.capacity() != my.capacity())
	{
		std::cout << "\nOrig capacity = " << orig.capacity() << std::endl;
		std::cout << "My capacity = " << my.capacity() << std::endl;
		return false;
	}
	return true;
}

template<typename T>
bool check_vector(std::vector<T> &orig, ft::vector<T> &my)
{
    typename std::vector<T>::iterator orig_begin = orig.begin();
    typename std::vector<T>::iterator orig_end = orig.end();
    typename ft::vector<T>::iterator my_begin = my.begin();
    typename ft::vector<T>::iterator my_end = my.end();

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

    typename std::vector<T>::reverse_iterator orig_rbegin = orig.rbegin();
    typename std::vector<T>::reverse_iterator orig_rend = orig.rend();
    typename ft::vector<T>::reverse_iterator my_rbegin = my.rbegin();
    typename ft::vector<T>::reverse_iterator my_rend = my.rend();
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

bool constructor_vector_test()
{
	//default constructor
	std::vector<int> orig;
	ft::vector<int> my;
	if (!check_size(orig, my))
		return (false);
	if (!check_vector(orig, my))
		return (false);

	//fill constructor
	std::vector<int> orig1(10, 15);
	ft::vector<int> my1(10, 15);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);

	std::vector<char> orig2(15, 'A');
	ft::vector<char> my2(15, 'A');
	if (!check_size(orig2, my2))
		return (false);
	if (!check_vector(orig2, my2))
		return (false);

	std::vector<std::string> orig3(10, "Hello!");
	ft::vector<std::string> my3(10, "Hello!");
	if (!check_size(orig3, my3))
		return (false);
	if (!check_vector(orig3, my3))
		return (false);

	//range constructor 
	//from std::list
	std::vector<int> orig4(g_ls.begin(), g_ls.end());
	ft::vector<int> my4(g_ls.begin(), g_ls.end());
	if (!check_size(orig4, my4))
		return (false);
	if (!check_vector(orig4, my4))
		return (false);

	//from std::vector
	std::vector<int> orig5(g_vec.begin(), g_vec.end());
	ft::vector<int> my5(g_vec.begin(), g_vec.end());		
	if (!check_size(orig5, my5))
		return (false);
	if (!check_vector(orig5, my5))
		return (false);

	//copy constructor
	std::vector<int> orig6(orig4);
	ft::vector<int> my6(my4);
	if (!check_size(orig6, my6))
		return (false);
	if (!check_vector(orig6, my6))
		return (false);

	return true;
}

bool assigment_operator_vector_test()
{
	std::vector<char> orig1(15, 'A');
	ft::vector<char> my1(15, 'A');

	std::vector<std::string> orig2(10, "Hello!");
	ft::vector<std::string> my2(10, "Hello!");

	std::vector<int> orig3(10, 15);
	ft::vector<int> my3(10, 15);

	std::vector<char> orig4 = orig1;
	ft::vector<char> my4 = my1;
	if (!check_size(orig4, my4))
		return (false);
	if (!check_vector(orig4, my4))
		return (false);

	std::vector<std::string> orig5 = orig2;
	ft::vector<std::string> my5 = my2;
	if (!check_size(orig5, my5))
		return (false);
	if (!check_vector(orig5, my5))
		return (false);

	std::vector<int> orig6 = orig3;
	ft::vector<int> my6 = my3;
	if (!check_size(orig6, my6))
		return (false);
	if (!check_vector(orig6, my6))
		return (false);

	std::vector<int> orig7(5, 10);
	ft::vector<int> my7(5, 10);
	orig7 = orig6;
	my7 = my6;
	if (!check_size(orig7, my7))
		return (false);
	if (!check_vector(orig7, my7))
		return (false);

	return true;
}
bool begin_end_vector_test()
{
	std::vector<int> orig(g_vec.begin(), g_vec.end());
	ft::vector<int> my(g_vec.begin(), g_vec.end());
	if (!check_size(orig, my))
		return (false);
	if (!check_vector(orig, my))
		return (false);

	std::vector<int>::iterator it = orig.begin();
	std::vector<int>::iterator ite = orig.end();
	ft::vector<int>::iterator myit = my.begin();
	ft::vector<int>::iterator myite = my.end();
	*it = 123;
	*myit = 123;
	*(--ite) = 321;
	*(--myite) = 321;
	if (!check_vector(orig, my))
		return (false);

	return true;
}
bool rbegin_rend_vector_test()
{
	std::vector<int> orig(g_vec.begin(), g_vec.end());
	ft::vector<int> my(g_vec.begin(), g_vec.end());
	if (!check_size(orig, my))
		return (false);
	if (!check_vector(orig, my))
		return (false);

	std::vector<int>::reverse_iterator it = orig.rbegin();
	std::vector<int>::reverse_iterator ite = --orig.rend();
	ft::vector<int>::reverse_iterator myit = my.rbegin();
	ft::vector<int>::reverse_iterator myite = --my.rend();
	*it = 123;
	*myit = 123;
	*ite = 321;
	*myite = 321;
	if (!check_vector(orig, my))
		return (false);

	return true;
}
bool front_back_vector_test()
{
	std::vector<int> orig;
	ft::vector<int> my;
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
bool clear_vector_test()
{
	std::vector<int> orig(g_vec.begin(), g_vec.end());
	ft::vector<int> my(g_vec.begin(), g_vec.end());
	if (!check_size(orig, my))
		return (false);
	if (!check_vector(orig, my))
		return (false);

	orig.clear();
	my.clear();
	if (!check_size(orig, my))
		return (false);
	if (!check_vector(orig, my))
		return (false);

	orig.clear();
	my.clear();
	if (!check_size(orig, my))
		return (false);
	if (!check_vector(orig, my))
		return (false);

	return true;
}
bool empty_vector_test()
{
	std::vector<int> orig1;
	ft::vector<int> my1;

	if (orig1.empty() != my1.empty())
	{
		std::cout << "Error empty" << std::endl;
		return false;
	}

	std::vector<int> orig2(5, 5);
	ft::vector<int> my2(5, 5);

	if (orig2.empty() != my2.empty())
	{
		std::cout << "Error empty" << std::endl;
		return false;
	}
	
	return true;
}
bool assign_vector_test()
{
	//assign range
	std::vector<int> orig;
	ft::vector<int> my;
	orig.assign(g_vec.begin(), g_vec.end());
	my.assign(g_vec.begin(), g_vec.end());
	if (!check_size(orig, my))
		return (false);
	if (!check_vector(orig, my))
		return (false);

	orig.assign(g_vec.begin(), g_vec.end());
	my.assign(g_vec.begin(), g_vec.end());
	if (!check_size(orig, my))
		return (false);
	if (!check_vector(orig, my))
		return (false);

	//assign fill
	std::vector<int> orig1;
	ft::vector<int> my1;
	orig1.assign(15, 90);
	my1.assign(15, 90);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);

	std::vector<double> orig2;
	ft::vector<double> my2;
	orig2.assign(20, 100.);
	my2.assign(20, 100.);
	if (!check_size(orig2, my2))
		return (false);
	if (!check_vector(orig2, my2))
		return (false);

	std::vector<std::string> orig3;
	orig3.assign(5, "Hello!");
	ft::vector<std::string> my3;
	my3.assign(5, "Hello!");
	if (!check_size(orig3, my3))
		return (false);
	if (!check_vector(orig3, my3))
		return (false);
	return true;
}
bool at_vector_test()
{
	std::vector<int> orig1;
	ft::vector<int> my1;

	int count_orig = 0;
	int count_my = 0;
	try { orig1.at(0); } 
	catch (std::out_of_range& ex) { count_orig++; }
	try { my1.at(0); } 
	catch (std::out_of_range& ex) { count_my++; }

	orig1.assign(g_vec.begin(), g_vec.end());
	my1.assign(g_vec.begin(), g_vec.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);

	try { orig1.at(8); } 
	catch (std::out_of_range& ex) { count_orig++; }
	try { my1.at(8); } 
	catch (std::out_of_range& ex) { count_my++; }

	if (orig1.at(8) != my1.at(8))
	{
		std::cout << "Error at" << std::endl;
		return false;
	}

	try { orig1.at(26); } 
	catch (std::out_of_range& ex) { count_orig++; }
	try { my1.at(26); } 
	catch (std::out_of_range& ex) { count_my++; }
	
	if (count_orig != count_my)
	{
		std::cout << "Error at" << std::endl;
		return false;
	}

	return true;

}
bool operator_brackets_vector_test()
{
	std::vector<int> orig1;
	ft::vector<int> my1;

	int count_orig = 0;
	int count_my = 0;
	try { orig1[0]; } 
	catch (std::out_of_range& ex) { count_orig++; }
	try { my1[0]; } 
	catch (std::out_of_range& ex) { count_my++; }

	orig1.assign(g_vec.begin(), g_vec.end());
	my1.assign(g_vec.begin(), g_vec.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);

	try { orig1[18]; } 
	catch (std::out_of_range& ex) { count_orig++; }
	try { my1[18]; } 
	catch (std::out_of_range& ex) { count_my++; }

	if (orig1[8] != my1[8])
	{
		std::cout << "Error []" << std::endl;
		return false;
	}

	try { orig1[26]; } 
	catch (std::out_of_range& ex) { count_orig++; }
	try { my1[26]; } 
	catch (std::out_of_range& ex) { count_my++; }
	
	if (count_orig != count_my)
	{
		std::cout << "Error []" << std::endl;
		return false;
	}

	return true;

}
bool erase_vector_test()
{
	std::vector<int> orig1(g_vec.begin(), g_vec.end());
	ft::vector<int> my1(g_vec.begin(), g_vec.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);

	orig1.erase(++(orig1.begin()));
	my1.erase(++(my1.begin()));
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);

	orig1.erase(--(orig1.end()));
	my1.erase(--(my1.end()));
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);

	orig1.erase(++(orig1.begin()), orig1.end());
	my1.erase(++(my1.begin()), my1.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);
	return true;
}
bool insert_vector_test()
{
	std::vector<int> orig1(g_vec.begin(), g_vec.end());
	ft::vector<int> my1(g_vec.begin(), g_vec.end());

	// insert (iterator position, const value_type& val)
	orig1.insert(++(orig1.begin()), 100);
	my1.insert(++(my1.begin()), 100);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);

	// insert (iterator position, size_type n, const value_type& val)
	orig1.insert(++(orig1.begin()), 18, 35);
	my1.insert(++(my1.begin()), 18, 35);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);

	// insert (iterator position, InputIterator first, InputIterator last)
	orig1.insert(orig1.begin(), g_vec.begin(), g_vec.end());
	my1.insert(my1.begin(), g_vec.begin(), g_vec.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);
	
	return true;

}
bool max_size_vector_test()
{
	std::vector<int> orig(5, 10);
	ft::vector<int> my(5, 10);
	if (orig.max_size() != my.max_size())
	{
		std::cout << "Error max_size" << std::endl;
		return false;
	}
	return true;
}

bool pop_back_vector_test()
{
	std::vector<int> orig1(g_vec.begin(), g_vec.end());
	ft::vector<int> my1(g_vec.begin(), g_vec.end());

	orig1.pop_back();
	my1.pop_back();
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);

	orig1.pop_back();
	my1.pop_back();
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);

	return true;
}

bool push_back_vector_test()
{
	std::vector<int> orig1(g_ls.begin(), g_ls.end());
	ft::vector<int> my1(g_ls.begin(), g_ls.end());

	orig1.push_back(5);
	my1.push_back(5);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);

	orig1.push_back(1000);
	my1.push_back(1000);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);
	
	return true;

}
bool reserve_vector_test()
{
	std::vector<int> orig1;
	ft::vector<int> my1;
	if (!check_size(orig1, my1))
		return (false);
	if (orig1.capacity() != my1.capacity())
	{
		std::cout << "\nOrig capacity = " << orig1.capacity() << std::endl;
		std::cout << "\nMy capacity = " << my1.capacity() << std::endl;
		return false;
	}
	orig1.reserve(2);
	my1.reserve(2);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_capacity(orig1, my1))
		return (false);
	if (!check_capacity(orig1, my1))
		return (false);

	orig1.reserve(16);
	my1.reserve(16);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_capacity(orig1, my1))
		return (false);

	orig1.assign(16, 5);
	my1.assign(16, 5);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);

	orig1.reserve(5);
	my1.reserve(5);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);
	if (!check_capacity(orig1, my1))
		return (false);

	return true;

}
bool resize_vector_test()
{
	std::vector<int> orig1;
	ft::vector<int> my1;

	orig1.resize(15, 1);
	my1.resize(15, 1);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);
	if (!check_capacity(orig1, my1))
		return (false);

	orig1.resize(17, 100);
	my1.resize(17, 100);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);
	if (!check_capacity(orig1, my1))
		return (false);

	orig1.resize(8, 5);
	my1.resize(8, 5);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);
	if (!check_capacity(orig1, my1))
		return (false);

	return true;
}

bool size_vector_test()
{
	std::vector<int> orig1;
	ft::vector<int> my1;
	if (!check_size(orig1, my1))
		return (false);

	std::vector<int> orig2(15, 20);
	ft::vector<int> my2(15, 20);
	if (!check_size(orig1, my1))
		return (false);

	return true;
}

bool swap_vector_test()
{
	std::vector<int> orig1(g_vec.begin(), g_vec.end());
	std::vector<int> orig2(g_vec1.begin(), g_vec1.end());
	ft::vector<int> my1(g_vec.begin(), g_vec.end());
	ft::vector<int> my2(g_vec1.begin(), g_vec1.end());

	orig1.swap(orig2);
	my1.swap(my2);
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);

	if (!check_size(orig2, my2))
		return (false);
	if (!check_vector(orig2, my2))
		return (false);

	return true;
}
bool relational_vector_test()
{
	std::vector<int> vec1;
	std::vector<int> vec2;
	for (int i = 0; i < 20; i++)
	{
		g_vec1.push_back(rand() % 100);
		vec2.push_back(rand() % 100);
	}
	std::vector<int> orig1(g_vec1.begin(), g_vec1.end());
	std::vector<int> orig2(vec2.begin(), vec2.end());
	ft::vector<int> my1(g_vec1.begin(), g_vec1.end());
	ft::vector<int> my2(vec2.begin(), vec2.end());
	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);
	if (!check_size(orig2, my2))
		return (false);
	if (!check_vector(orig2, my2))
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
bool swap_vector_vector_test()
{
	std::vector<int> orig1(g_vec1.begin(), g_vec1.end());
	std::vector<int> orig2(g_vec.begin(), g_vec.end());
	ft::vector<int> my1(g_vec1.begin(), g_vec1.end());
	ft::vector<int> my2(g_vec.begin(), g_vec.end());

	std::swap(orig1, orig2);
	ft::swap(my1, my2);

	if (!check_size(orig1, my1))
		return (false);
	if (!check_vector(orig1, my1))
		return (false);

	if (!check_size(orig2, my2))
		return (false);
	if (!check_vector(orig2, my2))
		return (false);

	return true;
}

void vector_start()
{
	std::cout << BOLDCYAN << "|=================================================================================================|" << std::endl;
	std::cout << "|                                        Vector tests                                             |" << std::endl;
	std::cout << "|=================================================================================================|" << std::endl;

	std::cout << BOLDCYAN << "\n[constructor] \t\t" << ((constructor_vector_test()) ? GREEN "OK" : RED "FAIL") << std::endl;
	std::cout << BOLDCYAN << "[operator=] \t\t" << ((assigment_operator_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[assign] \t\t" << ((assign_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[at] \t\t\t" << ((at_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[operator[] ] \t\t" << ((operator_brackets_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[begin/end] \t\t" << ((begin_end_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[rbegin/rend] \t\t" << ((rbegin_rend_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[front/back] \t\t" << ((front_back_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[clear] \t\t" << ((clear_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[empty] \t\t" << ((empty_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[erase] \t\t" << ((erase_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[insert] \t\t" << ((insert_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[max_size] \t\t" << ((max_size_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[pop_back] \t\t" << ((pop_back_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[push_back] \t\t" << ((push_back_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[reserve] \t\t" << ((reserve_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[resize] \t\t" << ((resize_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[size] \t\t\t" << ((size_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[swap] \t\t\t" << ((swap_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[relational_operators]\t" << ((relational_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
	std::cout << BOLDCYAN << "[swap_vector] \t\t" << ((swap_vector_vector_test()) ? GREEN"OK" : RED"FAIL") << std::endl;
}
