#include <array>
#include <iostream>
#include <vector>
#include <list>
#include <map>

#include <set>
#include <deque>

#include "containers/Vector.hpp"
#include "containers/Map.hpp"
#include "containers/List.hpp"



int main()
{
  /*std::array<int, 3> arr = { 1, 2, 3 };
 
  // Данный цикл работает аналогично циклу, приведенному выше
  for (int i : arr)
  {
    std::cout << i << ' ';
  }
  std::cout << '\n'; */

  /*std::vector<int> tmp1 = {1, 2, 3, 4};
  std::vector<int> tmp2 = {1, 2, 5, 1, 1};

  if (tmp1 < tmp2)
  	std::cout << "true 1" << std::endl;

  std::vector<int> tmp3 = {1, 2, 3, 4};
  std::vector<int> tmp4 = {1, 2, 3, 1, 1};

  if (tmp3 < tmp4)
  	std::cout << "true 2" << std::endl; */

	//int *tmp;
	//delete tmp;
	/*std::vector<int> tmp = {1, 2, 3, 4};
	std::vector<int> tmp1 = {5, 6, 7, 8};
	//tmp.erase(tmp.end()); //сега
	tmp1.erase(tmp1.begin(), --tmp1.end()); //сега
	std::cout << tmp1[0] << std::endl; */

	//std::string str = std::string(0);
	//std::cout << str << std::endl;

	/*std::list<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	std::cout << *test.end() << std::endl;
	std::cout << *(++test.end()) << std::endl;*/
	//std::list<int> test1;
	/*test.unique();

	std::deque<int> test2;
	std::cout << test2.back() << std::endl;

	std::multimap<int, std::string> test3;*/
	//test3.insert(4, std::string("4"));


	//ft::vector<const int> test222(size_t(5), 5);
	std::vector<const int> test111(5, 5); //РАЗОБРАТЬСЯ!!!
	std::vector<int> test333(5, 5);
	std::vector<int>::iterator start = test333.begin();
	std::map<int, int> test444;
	std::map<int, int>::iterator start1 = test444.begin();

	std::set<int> test555;
	//std::set<int>::const_iterator
	
	

	std::vector<int>::const_iterator or_begin = test333.begin();
	std::vector<int>::const_iterator or_end = test333.end();
	std::cout << "diff = " << or_end - or_begin << std::endl;
	ft::vector<int> test222(5, 5);
	//ft::vector<int>::const_iterator no_begin = test222.begin();
	//ft::vector<int>::const_iterator no_end = test222.end();

	/* CONST ITERATOR FOR LIST */
	std::list<int> list_or(5, 4);
	ft::list<int> list_no(5, 4);
	std::list<int>::iterator or_list1 = list_or.begin();
	std::list<int>::const_iterator or_list = list_or.begin();
	ft::list<int>::const_iterator no_list = list_no.begin();

	std::cout << "or begin = " << *or_list << std::endl;
	std::cout << "++ or begin = " << *(++or_list) << std::endl;
	std::cout << "no begin = " << *no_list << std::endl;
	std::cout << "++ no begin = " << *(++no_list) << std::endl;


	ft::list<int> uniq;
	uniq.unique();
	ft::list<int>::iterator it1 = ++uniq.begin();
	ft::list<int>::iterator ite1 = uniq.end();
	if (it1 == ite1)
		std::cout << "!@# \n";



	/*std::set<int> test;
	test.insert(1);
	test.insert(2);
	test.erase(1);
	test.erase(1);*/


	//const int a;
	//test222.push_back(5);
	


	/*for (int i = 1; i < 5; i++)
		test.push_back(i);
	for (int i = 5; i < 10; i++)
		test1.push_back(i);
	test.splice(++test.begin(), test1);
	std::cout << "first = " << *test.begin() << std::endl;*/
	//test.pop_back();
	/*test.push_back(1);
	test.push_back(2);
	std::cout << *(--test.end()) << std::endl;
	std::cout << *(test.end()) << std::endl;*/

    /*std::map<char,char> m;
    m['a'] = 'a';
    m['b'] = 'b';
    std::map<char,char>::iterator it1 = m.end();
    std::cout << (++it1)->first << std::endl;
    std::cout << (++it1)->first << std::endl;
    std::cout << (++it1)->first << std::endl;
    std::cout << (++it1)->first << std::endl;
    std::cout << (--it1)->first << std::endl;
    std::cout << (--it1)->first << std::endl;
    std::cout << (--it1)->first << std::endl;
    std::cout << (--it1)->first << std::endl;
    std::cout << (--it1)->first << std::endl;
    std::cout << (--it1)->first << std::endl; */
    // std::cout << (it1--)->first << std::endl;
    // std::cout << (it1--)->first << std::endl;
    // std::cout << (it1--)->first << std::endl;
    // std::cout << (it1--)->first << std::endl;
    // std::cout << (it1--)->first << std::endl;
    // std::cout << (it1++)->first << std::endl;
    // std::cout << (it1++)->first << std::endl;
    // std::cout << (it1++)->first << std::endl;
    // std::cout << (it1++)->first << std::endl;
    // std::cout << (it1++)->first << std::endl;
    // std::cout << (it1++)->first << std::endl;


	/*ft::map<int, std::string> mymap;
	mymap[4] = "40";

	mymap.insert(std::make_pair(1, "10"));
	mymap.insert(std::make_pair(2, "20"));
	mymap.insert(std::make_pair(3, "30"));
	std::cout << mymap.size() << std::endl;
	std::cout << mymap.begin()->first << std::endl;
	std::cout << (--mymap.end())->first << std::endl;

	std::pair<int, std::string> tmp1 = std::make_pair(1, "10");
	std::pair<int, std::string> tmp2 = std::make_pair(1, "10");
	if (tmp1 < tmp2)
		std::cout << "tmp1 < tmp2" << std::endl;
	if (tmp1 == tmp2)
		std::cout << "tmp1 = tmp2" << std::endl;
	if (tmp1 > tmp2)
		std::cout << "tmp1 > tmp2" << std::endl; */

	std::pair<int, int> tmp_pair(2, 5);
	std::vector<int> cap;
	std::cout << "cap 0 = " << cap.capacity() << std::endl;
	//cap.push_back(1);
	cap.assign(1, 1);
	std::cout << "cap 1 = " << cap.capacity() << std::endl;
	//std::cout << tmp_pair << std::endl;
 
  return 0;
}