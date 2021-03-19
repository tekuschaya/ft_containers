#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <set>

#include "../containers/Map.hpp"
#include "../containers/List.hpp"
#include "../containers/Vector.hpp"
#include "../containers/Queue.hpp"
#include "../containers/Stack.hpp"
#include "../containers/Deque.hpp"
#include "../containers/Set.hpp"


#define RED			"\033[1;31m"
#define GREEN		"\033[32m"
#define BOLDGREEN   "\033[1m\033[32m" 
#define BOLDCYAN    "\033[1m\033[36m"

int arr1[15] = {1, -12, 53, 14, -5, 30, 77, 2, 9, 0, 11, -32, 43, 111, 35};
int arr2[15] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377};
std::vector<int> g_vec(arr1, arr1 + 14);
std::vector<int> g_vec1(arr2, arr2 + 14);

//static int arr_int[16] = {1,2,3,4,5,6,7,8,9,0,1,2,3,1,3,-1};
//static int arr_int2[16] = {1,2,3,1,2,2,1,4,0,0,1,2,3,1,3,-1};
char arr_str[][16] =
{"one", "two", "three", "four", "five",
"six", "seven", "eight", "nine", "zero",
"one", "two", "one", "two", "three", ""};

static std::pair<int, int> vect_map1[20] = 
{std::make_pair(50, 1), std::make_pair(25, 2), 
std::make_pair(-8, 6), std::make_pair(35, 4),
std::make_pair(1, 5), std::make_pair(12, -36),
std::make_pair(300, 7), std::make_pair(40, 8),
std::make_pair(11, -9), std::make_pair(60, 10),
std::make_pair(90, 11), std::make_pair(-21, 3), 
std::make_pair(55, 12), std::make_pair(70, 13),
std::make_pair(27, 1), std::make_pair(100, 15),
std::make_pair(8, 3), std::make_pair(35, 4),
std::make_pair(8, 3), std::make_pair(4, 4)};

static std::pair<int, int> vect_map2[20] =
{ std::make_pair(1, 1), std::make_pair(8, 2), std::make_pair(12, 3),
std::make_pair(25, 4), std::make_pair(30, 5), std::make_pair(35, 6),
std::make_pair(40, 7), std::make_pair(50, 8), std::make_pair(55, 9),
std::make_pair(40, 7), std::make_pair(50, 8), std::make_pair(55, 9),
std::make_pair(60, 10), std::make_pair(70, 11), std::make_pair(75, 12),
std::make_pair(60, 10), std::make_pair(70, 11), std::make_pair(80, 13),
std::make_pair(90, 14), std::make_pair(100, 15) };

static std::pair<std::string, int> vect_map3[20] =
{ std::make_pair("one", 1), std::make_pair("two", 2), std::make_pair("three", 3),
std::make_pair("four", 4), std::make_pair("five", 5), std::make_pair("six", 6),
std::make_pair("seven", 71), std::make_pair("eight", 81), std::make_pair("nine", 91),
std::make_pair("seven", 72), std::make_pair("eight", 82), std::make_pair("nine", 92),
std::make_pair("ten", 101), std::make_pair("eleven", 111), std::make_pair("twelve", 12),
std::make_pair("ten", 102), std::make_pair("eleven", 112), std::make_pair("thirteen", 13),
std::make_pair("fourteen", 14), std::make_pair("fifteen", 15) };

static std::list<int> g_ls(arr1, arr1 + 15);
static std::vector<int> g_vc(arr1, arr1 + 15);
static std::vector<int> g_vc2(arr2, arr2 + 15);
//static std::deque<int> g_dq(arr1, arr1 + 15);
static std::vector<std::string> g_str(arr_str, arr_str + 15);
static std::vector<std::pair<int, int> > g_map1(vect_map1, vect_map1 + 20);
static std::vector<std::pair<int, int> > g_map2(vect_map2, vect_map2 + 20);
static std::vector<std::pair<std::string, int> > g_map3(vect_map3, vect_map3 + 20);