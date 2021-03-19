#pragma once

#include <memory>
#include "Iterator.hpp"

namespace ft
{

template < class T, class Alloc = std::allocator<T> > 
class deque
{
	public:
		typedef T value_type;	
		typedef Alloc allocator_type;
		typedef size_t size_type;
		typedef T& reference;
		typedef T const & const_reference;
		typedef T* pointer;
		typedef IterVector<T> iterator;
		typedef ConstIterVector<T> const_iterator;
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef ReverseIterator<const_iterator> const_reverse_iterator;
	private:
		allocator_type d_alloc;
		size_type d_size;
		size_type d_cap;
		size_type d_start;
		size_type d_end;
		pointer ptr;
		void _reserve(size_type n)
		{
			pointer tmp = new value_type[n];
			size_type i = this->d_start;
			if (this->d_cap)
				this->d_start = (n - this->d_cap) / 2;
			for (size_type j = this->d_start; i < this->d_end; i++, j++)
				tmp[j] = this->ptr[i];
			if (this->ptr)
			{
				delete[] this->ptr;
				this->ptr = NULL;
			}
			this->ptr = tmp;
			this->d_cap = n;
			this->d_end = this->d_start + this->d_size;
		}
	public:
		explicit deque (const allocator_type& alloc = allocator_type())
		{
			this->d_alloc = alloc;
			this->d_size = 0;
			this->d_start = 0;
			this->d_end = 0;
			this->d_cap = 0;
			this->ptr = NULL;
		}
		explicit deque (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			this->d_alloc = alloc;
			this->d_size = n;
			this->d_cap = n;
			this->d_start = 0;
			this->d_end = n;
			this->ptr = new value_type[n];
			for (size_type i = 0; i < n; i++)
				this->ptr[i] = val;

		}
		template <class InputIterator>
		deque (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
		typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			this->d_alloc = alloc;
			this->d_size = 0;
			this->d_cap = 0;
			this->d_start = 0;
			this->d_end = 0;
			this->ptr = NULL;
			this->assign(first, last);
		}
		deque (const deque& x)
		{
			this->ptr = NULL;
			*this = x;
		}
		~deque()
		{
			if (this->ptr)
			{
				delete[] this->ptr;
				this->ptr = NULL;
			}
		}
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
		typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			this->clear();
			while (first != last)
			{
				this->push_back(*first);
				++first;
			}
		}	
		void assign (size_type n, const value_type& val)
		{
			this->clear();
			this->_reserve(n);
			for (size_type i = 0; i < n; i++)
				this->push_back(val);
		}
		reference at (size_type n)
		{
			if (n >= this->d_size)
				throw std::out_of_range("out of range");
			return this->ptr[this->d_start + n];
		}
		const_reference at (size_type n) const
		{
			if (n >= this->d_size)
				throw std::out_of_range("out of range");
			return this->ptr[this->d_start + n];
		}
		reference back()
		{
			return (this->ptr[this->d_end - 1]);
		}
		const_reference back() const
		{
			return (this->ptr[this->d_end - 1]);
		}
		iterator begin()
		{
			return iterator(&this->ptr[this->d_start]);
		}
		const_iterator begin() const
		{
			return iterator(&this->ptr[this->d_start]);
		}
		void clear()
		{
			this->d_size = 0;
			if (this->ptr)
			{
				delete[] this->ptr;
				this->ptr = NULL;
			}
			this->d_cap = 0;
			this->d_start = 0;
			this->d_end = 0;
		}
		bool empty() const
		{
			if (this->d_size == 0)
				return true;
			return false;
		}
		iterator end()
		{
			return iterator(&this->ptr[this->d_end]);
		}
		const_iterator end() const
		{
			return iterator(&this->ptr[this->d_end]);
		}
		iterator erase (iterator position)
		{
			iterator tmp = position;
			return this->erase(position, ++tmp);
		}
		iterator erase (iterator first, iterator last)
		{
			size_type i = first - this->begin();
			while (last != this->end())
			{
				*first = *last;
				++first;
				++last;
			}
			this->d_size -= (last - first);
			this->d_end -= (last - first);
			return iterator(&this->ptr[this->d_start + i]);
		}
		reference front()
		{
			return (this->ptr[this->d_start]);
		}
		const_reference front() const
		{
			return (this->ptr[this->d_start]);
		}
		iterator insert (iterator position, const value_type& val)
		{
			size_type pos = position - this->begin();
			this->insert(position, 1, val);
			return (iterator(&this->ptr[this->d_start + pos]));
		}
		void insert (iterator position, size_type n, const value_type& val)
		{
			deque tmp(position, this->end());
			if (this->d_size + n > this->d_cap)
			{
				size_type cap = this->d_cap;
				if (!cap)
					this->_reserve(n);
				else
				{
					while (cap < this->size() + n)
						cap *= 2;
					this->_reserve(cap);
				}
			}
			this->d_size -= tmp.size();
			this->d_end -= tmp.size();
			for (size_t i = 0; i < n; i++)
				this->push_back(val);
			iterator it = tmp.begin();
			iterator ite = tmp.end();
			while (it != ite)
			{
				this->push_back(*it);
				++it;
			}
		}
		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last,
		typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			deque tmp(position, this->end());
			if (this->d_cap + (last - first) > this->d_cap)
			{
				size_type cap = this->d_cap;
				if (!cap)
					this->_reserve(last - first);
				else
				{
					while (cap < this->size() + (last - first))
						cap *= 2;
					this->_reserve(cap);
				}
			}
			this->d_size -= tmp.size();
			this->d_end -= tmp.size();
			while (first != last)
			{
				this->push_back(*first);
				++first;
			}
			iterator it = tmp.begin();
			iterator ite = tmp.end();
			while (it != ite)
			{
				this->push_back(*it);
				++it;
			}
		}
		size_type max_size() const
		{
			return (std::numeric_limits<size_type>::max() / sizeof(value_type));
		}
		deque& operator= (const deque& x)
		{
			this->assign(x.begin(), x.end());
			return (*this);
		}
		reference operator[] (size_type n)
		{
			return this->ptr[this->d_start + n];
		}
		const_reference operator[] (size_type n) const
		{
			return this->ptr[this->d_start + n];
		}
		void pop_back()
		{
			if (this->d_size)
			{
				this->d_size--;
				this->d_end--;
			}
		}
		void pop_front()
		{
			if (this->d_size)
			{
				this->d_size--;
				this->d_start++;
			}
		}
		void push_back (const value_type& val)
		{
			if (this->d_end == this->d_cap)
			{
				if (this->d_cap)
					this->_reserve(this->d_cap * 2);
				else
					this->_reserve(2);
			}
			this->ptr[this->d_end] = val;
			this->d_end++;
			this->d_size++;
		}
		void push_front (const value_type& val)
		{
			if (!this->d_start)
			{
				if (this->d_cap)
					this->_reserve((this->d_cap + 1) * 2);
				else
				{
					this->_reserve(2);
				}
			}
			if (this->d_start)
				this->d_start--;
			else
				this->d_end++;
			this->ptr[this->d_start] = val;
			this->d_size++;
		}
		reverse_iterator rbegin()
		{
			return (reverse_iterator(this->end()));
		}
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(this->end()));
		}
		reverse_iterator rend()
		{
			return (reverse_iterator(this->begin()));
		}
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(this->begin()));
		}
		void resize (size_type n, value_type val = value_type())
		{
			if (n > this->d_cap)
				this->_reserve(n);
			if (n > this->size())
			{
				while (this->d_size < n)
					this->push_back(val);
			}
			else
			{
				while (this->d_size > n)
					this->pop_back();
			}

		}
		size_type size() const
		{
			return (this->d_size);
		}
		void swap (deque& x)
		{
			deque tmp = *this;
			*this = x;
			x = tmp;
		}

};
template <class T, class Alloc>
bool operator==(const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)
{
	typename ft::deque<T, Alloc>::const_iterator first1 = lhs.begin();
	typename ft::deque<T, Alloc>::const_iterator last1 = lhs.end();
	typename ft::deque<T, Alloc>::const_iterator first2 = rhs.begin();
	typename ft::deque<T, Alloc>::const_iterator last2 = rhs.end();
	if (lhs.size() == rhs.size())
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}
  	return false;

}
template <class T, class Alloc>
bool operator!=(const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return false;
	return true;
}
template <class T, class Alloc>
bool operator<(const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)
{
	typename ft::deque<T, Alloc>::const_iterator first1 = lhs.begin();
	typename ft::deque<T, Alloc>::const_iterator last1 = lhs.end();
	typename ft::deque<T, Alloc>::const_iterator first2 = rhs.begin();
	typename ft::deque<T, Alloc>::const_iterator last2 = rhs.end();
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1 < *first2)
			return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}
template <class T, class Alloc>
bool operator<=(const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)
{
	if (lhs == rhs || lhs < rhs)
		return true;
	return false;
}
template <class T, class Alloc>
bool operator>(const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)
{
	if (lhs <= rhs)
		return false;
	return true;
}
template <class T, class Alloc>
bool operator>=(const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs)
{
	if (lhs < rhs)
		return false;
	return true;
}
template <class T, class Alloc>
void swap(deque<T,Alloc>& x, deque<T,Alloc>& y)
{
	deque<T,Alloc> tmp = x;
	x = y;
	y = tmp;
}

}