#ifndef NODE_HPP
#define NODE_HPP

#include <iostream> //for nullptr

namespace ft //нужно или нет?
{

template <typename T>
class Node
{
	//private:
	public:  //как получить доступ из push back без public? friend?
		Node<T> *prev;
		Node<T> *next;
		T value;
		
	public:
		Node(T value)
		{
			this->value = value;
			this->prev = nullptr;
			this->next = nullptr;
		}
		~Node() {}
		T getValue() const {return this->value;}
};

}

#endif