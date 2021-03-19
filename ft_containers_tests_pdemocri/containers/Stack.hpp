#pragma once

#include "List.hpp"

namespace ft
{

template <class T, class Container = ft::list<T> >
class stack
{
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;
	protected:
		container_type cont;
	public:
		explicit stack (const container_type& ctnr = container_type())
		{
			this->cont = ctnr;
		}
		bool empty() const
		{
			return (this->cont.empty());
		}
		void pop()
		{
			this->cont.pop_back();
		}
		void push (const value_type& val)
		{
			this->cont.push_back(val);
		}
		size_type size() const
		{
			return (this->cont.size());
		}
		value_type& top()
		{
			return (this->cont.back());
		}
		const value_type& top() const
		{
			return (this->cont.back());
		}
		template <class stack_type, class container_type>
		friend bool operator==(const stack<stack_type, container_type>& lhs, const stack<stack_type,container_type>& rhs)
		{
			return (lhs.cont == rhs.cont);
		}
		template <class stack_type, class container_type>
		friend bool operator!=(const stack<stack_type, container_type>& lhs, const stack<stack_type,container_type>& rhs)
		{
			return (lhs.cont != rhs.cont);
		}
		template <class stack_type, class container_type>
		friend bool operator<(const stack<stack_type, container_type>& lhs, const stack<stack_type,container_type>& rhs)
		{
			return (lhs.cont < rhs.cont);
		}
		template <class stack_type, class container_type>
		friend bool operator<=(const stack<stack_type, container_type>& lhs, const stack<stack_type,container_type>& rhs)
		{
			return (lhs.cont <= rhs.cont);
		}	
		template <class stack_type, class container_type>
		friend bool operator>(const stack<stack_type, container_type>& lhs, const stack<stack_type,container_type>& rhs)
		{
			return (lhs.cont > rhs.cont);
		}
		template <class stack_type, class container_type>
		friend bool operator>=(const stack<stack_type, container_type>& lhs, const stack<stack_type,container_type>& rhs)
		{
			return (lhs.cont >= rhs.cont);
		}
};

}