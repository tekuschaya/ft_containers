#pragma once

#include "Iterator.hpp"

namespace ft
{

template <class T, class Alloc = std::allocator<T> >
class vector
{
	public:
		typedef size_t size_type;
		typedef Alloc allocator_type;
		//typedef allocator_type<value_type> value_type;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		//typedef Alloc::reference;
		//typedef allocator_type::pointer;
		typedef T& reference;
		typedef T const & const_reference;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef IterVector<T> iterator;
		typedef ConstIterVector<T> const_iterator;
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef ReverseIterator<const_iterator> const_reverse_iterator;
	private:
		allocator_type v_alloc;
		size_type v_capacity;
		size_type v_size;
		pointer ptr;

	public:
		explicit vector(const allocator_type& alloc = allocator_type())
		{
			this->v_alloc = alloc;
			this->v_capacity = 0;
			this->v_size = 0;
			this->ptr = NULL;
		}
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			//переделать через аллокатор
			/*this->v_alloc = alloc;
			this->ptr = this->v_alloc.allocate(n * sizeof(value_type)); //переделать value type
			for (size_type i = 0; i < n; i++)
				this->v_alloc.construct(&this->ptr[i], val); */
			/*pointer tmp = this->ptr;
			for (size_type i = 0; i < n; i++)
			{
				this->v_alloc.construct(tmp, val);
				tmp++;
			}*/
			this->v_alloc = alloc;
			this->ptr = new value_type[n];
			for (size_type i = 0; i < n; i++)
				this->ptr[i] = val;
			this->v_size = n;
			this->v_capacity = n;
		}	
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
		typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			this->v_alloc = alloc;
			this->v_size = 0;
			this->v_capacity = 0;
			this->ptr = NULL;
			this->assign(first, last);
			//this->ptr = new value_type[this->v_size];
			//this->ptr = this->v_alloc.allocate(n);
		/*	for (size_type i = 0; i < n; i++)
			{
				this->v_alloc.construct(&this->ptr[i], *first);
			}
		*/
			/*while (first != last)
			{
				this->v_alloc.construct(tmp, *first);
				++tmp;
				++first;
			}*/
			//this->v_size = 0;
			//this->v_capacity = n;
			//this->assign(first, last);
		}
		vector(const vector& x)
		{
			/*this->alloc = alloc;
			this->v_capacity = 0;
			this->ptr = NULL; */
			this->v_alloc = x.v_alloc;
			this->v_size = 0;
			this->v_capacity = 0;
			this->ptr = NULL;
			*this = x;
		}
		vector &operator=(const vector& x)
		{
			this->clear();
			this->v_alloc = x.v_alloc;
			this->assign(x.begin(), x.end());
			return (*this);
		}
		~vector()
		{
			/*if (this->v_size)
			{
				this->v_alloc.destroy(this->ptr); //уничтожает только одно значение?
				//this->v_alloc.destroy(&this->ptr[this->v_size]);
				this->v_alloc.deallocate(this->ptr, this->v_size * sizeof(value_type));
				this->ptr = NULL;
			}*/
			if (this->ptr)
			{
				delete[] this->ptr;
				this->ptr = NULL;
			}
		}
		reference operator[](size_type n)
		{
			return this->ptr[n];
		}
		const_reference operator[] (size_type n) const
		{
			return this->ptr[n];
		}
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
		typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			this->clear();
			/*if (this->ptr)
				this->v_alloc.deallocate(this->ptr, this->v_size * sizeof(value_type));
			this->v_size = 0;
			this->v_capacity = 0;*/
			while (first != last)
			{
				this->push_back(*first);
				++first;
			}
		}
		void assign(size_type n, const value_type& val)
		{
			this->clear();
			/*if (this->ptr)
				this->v_alloc.deallocate(this->ptr, this->v_size * sizeof(value_type));
			this->v_size = 0;
			this->v_capacity = 0;*/
			
			if (n > this->capacity())
			{
				size_type cap = this->capacity();
				if (!cap)
					this->reserve(n);
				else
				{
					while (cap < n)
						cap *= 2;
					this->reserve(cap);
				}
			}
			for (size_type i = 0; i < n; i++)
				this->push_back(val);
		}
		reference at (size_type n)
		{
			if (n >= this->v_size)
				throw std::out_of_range("out of range"); //почитать 
			return this->ptr[n];
		}
		const_reference at (size_type n) const
		{
			if (n >= this->v_size)
				throw std::out_of_range("out of range"); //почитать 
			return this->ptr[n];
		}
		reference back()
		{
			return (this->ptr[this->size() - 1]);
		}
		const_reference back() const
		{
			return (this->ptr[this->size() - 1]);
		}
		iterator begin()
		{
			return iterator(this->ptr);
		}
		const_iterator begin() const
		{
			return const_iterator(this->ptr);
		}
		size_type capacity() const
		{
			return this->v_capacity;
		}
		void clear()
		{
			this->v_size = 0;
			/*while (this->v_size)
			{
				this->v_size--;
				this->v_alloc.destroy(&this->ptr[this->v_size]);
			}*/

			//нужно ли очищать содержимое элементов?
			//delete[] this->ptr; //???
			//this->v_capacity = 0;
		}
		bool empty() const
		{
			if (this->v_size == 0)
				return true;
			return false;
		}
		iterator end()
		{
			return iterator(&this->ptr[this->v_size]);
		}
		const_iterator end() const
		{
			return const_iterator(&this->ptr[this->v_size]);
		}
		iterator erase(iterator position)
		{
			iterator tmp = position;
			return this->erase(position, ++tmp);
		}
		iterator erase(iterator first, iterator last)
		{ //return end if the operation erased the last element in the sequence.
			//iterator tmp = this->begin();
			size_type i = first - this->begin();
			while (last != this->end())
			{
				*first = *last;
				++first;
				++last;
				i++;
			}
			this->v_size -= (last - first);
			return iterator(&this->ptr[i]);
		}
		reference front()
		{
			return (this->ptr[0]);
		}
		const_reference front() const
		{
			return (this->ptr[0]);
		}
		iterator insert(iterator position, const value_type& val)
		{
			size_type pos = position - this->begin();
			this->insert(position, 1, val);
			return (iterator(&this->ptr[pos]));
		}	
    	void insert(iterator position, size_type n, const value_type& val)
		{
			vector tmp(position, this->end());
			if (this->size() + n > this->capacity())
			{
				size_type cap = this->capacity();
				if (!cap)
					this->reserve(n);
				else
				{
					while (cap < this->size() + n)
						cap *= 2;
					this->reserve(cap);
				}
			}
			this->v_size -= tmp.size();
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
    	void insert(iterator position, InputIterator first, InputIterator last,
		typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			vector tmp(position, this->end());
			if (this->size() + (last - first) > this->capacity())
			{
				size_type cap = this->capacity();
				if (!cap)
					this->reserve(last - first);
				else
				{
					while (cap < this->size() + (last - first))
						cap *= 2;
					this->reserve(cap);
				}
			}
			this->v_size -= tmp.size();
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
			//fail char kakogo hera
			return (std::numeric_limits<size_type>::max() / sizeof(value_type));
		}
		void pop_back()
		{
			//удаление содержимого? аллокатор
			if (this->v_size)
			{
				this->v_size--;
				//this->v_alloc.destroy(&(this->ptr[this->v_size]));
			}
		}
		void push_back(const value_type& val)
		{
			if (this->v_size == this->v_capacity)
			{
				if (this->v_capacity)
					this->reserve(this->v_capacity * 2);
				else
					this->reserve(2);
			}
			this->ptr[this->v_size] = val;
			this->v_size++;
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
		/*void reserve(size_type n)
		{
			pointer tmp = this->ptr;
			if (n > this->max_size())
				throw std::length_error("length error");
			if (n > this->capacity())
			{
				if (!(this->ptr = this->v_alloc.allocate(n * sizeof(value_type))))
					throw std::bad_alloc();
				if (this->v_size)
				{
					for (size_type i = 0; i < this->v_size; i++)
					{
						this->v_alloc.construct(&this->ptr[i], tmp[i]);
						//this->v_alloc.destroy(&(this->ptr[i]));
					}
					this->v_alloc.deallocate(tmp, this->v_size * sizeof(value_type));
					tmp = NULL;
				}
				this->v_capacity = n;
			}
		}*/


		void reserve(size_type n)
		{
			pointer tmp;
			if (n > this->max_size())
				throw std::length_error("length error");
			if (n > this->capacity())
			{
				tmp = new value_type[n]; //throw bad alloc
				for (size_type i = 0; i < this->v_size; i++)
					tmp[i] = this->ptr[i];
				if (this->ptr)
					delete[] this->ptr;
				this->ptr = tmp;
				this->v_capacity = n; 
			}
		} 
		void resize(size_type n, value_type val = value_type())
		{
			if (n > this->capacity())
			{
				size_type cap = this->capacity();
				if (!cap)
					this->reserve(n);
				else
				{
					while (cap < n)
						cap *= 2;
					this->reserve(cap);
				}
			}
			if (n > this->size())
			{
				while (this->v_size < n)
					this->push_back(val);
			}
			else
			{
				while (this->v_size > n)
					this->pop_back();
			}
		}
		size_type size() const
		{
			return this->v_size;
		}

		void swap(vector& x)
		{
			vector<T, Alloc> tmp = *this;
			*this = x;
			x = tmp;
		}
};

template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	vector<T, Alloc> tmp = x;
	x = y;
	y = tmp;
}

template <class T, class Alloc>
bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	typename ft::vector<T, Alloc>::const_iterator first1 = lhs.begin();
	typename ft::vector<T, Alloc>::const_iterator last1 = lhs.end();
	typename ft::vector<T, Alloc>::const_iterator first2 = rhs.begin();
	typename ft::vector<T, Alloc>::const_iterator last2 = rhs.end();
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
bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return false;
	return true;
}

template <class T, class Alloc>
bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	typename ft::vector<T, Alloc>::const_iterator first1 = lhs.begin();
	typename ft::vector<T, Alloc>::const_iterator last1 = lhs.end();
	typename ft::vector<T, Alloc>::const_iterator first2 = rhs.begin();
	typename ft::vector<T, Alloc>::const_iterator last2 = rhs.end();
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
bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs == rhs || lhs < rhs)
		return true;
	return false;

}	
template <class T, class Alloc>
bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs <= rhs)
		return false;
	return true;
}
template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs < rhs)
		return false;
	return true;
}
}
