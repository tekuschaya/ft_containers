#pragma once

#include "List.hpp"

namespace ft
{
template <class T, class Container = ft::list<T> >
class queue
{
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;
	protected:
		container_type cont;
	public:
		explicit queue(const container_type& ctnr = container_type()) 
		{
			this->cont = ctnr;
		}
		value_type& back()
		{
			return (this->cont.back());
		}
		const value_type& back() const
		{
			return (this->cont.back());
		}
		bool empty() const
		{
			return (this->cont.empty());
		}
		value_type& front()
		{
			return (this->cont.front());
		}
		const value_type& front() const
		{
			return (this->cont.front());
		}
		void pop()
		{
			this->cont.pop_front();
		}
		void push (const value_type& val)
		{
			this->cont.push_back(val);
		}
		size_type size() const
		{
			return (this->cont.size());
		}
		template <class queue_type, class container_type>
		friend bool operator==(const queue<queue_type, container_type>& lhs, const queue<queue_type, container_type>& rhs)
		{
			return (lhs.cont == rhs.cont);
		}
		template <class queue_type, class container_type>
		friend bool operator!=(const queue<queue_type, container_type>& lhs, const queue<queue_type, container_type>& rhs)
		{
			return (lhs.cont != rhs.cont);
		}
		template <class queue_type, class container_type>
		friend bool operator<(const queue<queue_type, container_type>& lhs, const queue<queue_type, container_type>& rhs)
		{
			return (lhs.cont < rhs.cont);
		}
		template <class queue_type, class container_type>
		friend bool operator<=(const queue<queue_type, container_type>& lhs, const queue<queue_type, container_type>& rhs)
		{
			return (lhs.cont <= rhs.cont);
		}	
		template <class queue_type, class container_type>
		friend bool operator>(const queue<queue_type, container_type>& lhs, const queue<queue_type, container_type>& rhs)
		{
			return (lhs.cont > rhs.cont);
		}
		template <class queue_type, class container_type>
		friend bool operator>=(const queue<queue_type, container_type>& lhs, const queue<queue_type, container_type>& rhs)
		{
			return (lhs.cont >= rhs.cont);
		}
};

}