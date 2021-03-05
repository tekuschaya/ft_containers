#ifndef VECTOR_HPP //pragma once
# define VECTOR_HPP

//#include <algorithm> 
#include <memory>


namespace ft
{

//template <typename T>

template <class T, class Alloc = std::allocator<T> > //сделать без аллокатора или писать свой?
class vector
{
	public:
		//class Iterator {};
		typedef size_t size_type;
		typedef Alloc allocator_type;
		typedef T value_type;
		typedef T& reference;
		typedef T const & const_reference;
		typedef T* pointer;
		class iterator
		{
			private:
				pointer iter;
			public:
				iterator() {}
				iterator(pointer iter) {this->iter = iter;}
				~iterator() {}
				//T &operator*() {return *this->iter;}
				/*pointer operator*()
				{
					return this->iter;
				}*/
				reference operator*()
				{
					return *this->iter;
				}
				iterator *getIter() const {return this->iter;} //зачем в векторе?
				/*size_type operator-(iterator const &iter) const
				{
					return (this->iter - iter.iter);
				}*/
				iterator &operator++() //проверить выход за пределы листа?
				{
					iterator tmp = *this;
					//iterator tmp(*this);
					++this->iter;
					return (*this);
					//tmp = this;
					//return tmp; //return this?
				}
				iterator &operator--() //проверить
				{
					iterator tmp = *this;
					--this->iter;
					//tmp = this;
					return tmp;
				}
				bool operator!=(iterator const &iter)
				{
					if (this->iter != iter.iter)
						return true;
					return false;
				}
				bool operator==(iterator const &iter)
				{
					if (this->iter == iter.iter)
						return true;
					return false;
				}
				bool operator<(iterator const &iter)
				{
					if (this->iter < iter.iter)
						return true;
					return false;
				}
				bool operator>(iterator const &iter)
				{
					if (this->iter > iter.iter)
						return true;
					return false;
				}
				size_type operator-(iterator const &iter)
				{
					return (this->iter - iter.iter);
				}
		};
		/*class const_iterator
		{
			private:
				pointer iter;
			public:
				const_iterator() {}
				const_iterator(pointer iter) {this->iter = iter;}
				~const_iterator() {}
				T &operator*() {return *(this->iter);}
				const_iterator *getIter() const {return this->iter;} //зачем в векторе?
				const_iterator &operator++() //проверить выход за пределы листа?
				{
					const_iterator *pos;
					++this->iter;
					pos = this;
					return *pos;
				}
				const_iterator &operator--() //проверить
				{
					const_iterator *pos = this;
					--this->iter;
					//pos = this;
					return *pos;
				}
				bool operator!=(const_iterator const &iter)
				{
					if (this->iter != iter.iter)
						return true;
					return false;
				}
				bool operator==(const_iterator const &iter)
				{
					if (this->iter == iter.iter)
						return true;
					return false;
				}
				bool operator<(const_iterator const &iter)
				{
					if (this->iter < iter.iter)
						return true;
					return false;
				}
				bool operator>(const_iterator const &iter)
				{
					if (this->iter > iter.iter)
						return true;
					return false;
				}
		}; */
		class reverse_iterator
		{
			private:
				pointer iter;
			public:
				reverse_iterator() {}
				reverse_iterator(pointer iter) {this->iter = iter;}
				~reverse_iterator() {}
				T &operator*() {return *(this->iter);}
				reverse_iterator *getIter() const {return this->iter;} //зачем в векторе?
				reverse_iterator &operator++() //проверить выход за пределы вектора?
				{
					reverse_iterator *pos;
					--this->iter;
					pos = this;
					return *pos;
				}
				reverse_iterator &operator--() //проверить
				{
					reverse_iterator *pos = this;
					++this->iter;
					//pos = this;
					return *pos;
				}
				bool operator!=(reverse_iterator const &iter)
				{
					if (this->iter != iter.iter)
						return true;
					return false;
				}
				bool operator==(reverse_iterator const &iter)
				{
					if (this->iter == iter.iter)
						return true;
					return false;
				}
				bool operator<(reverse_iterator const &iter)
				{
					if (this->iter < iter.iter)
						return true;
					return false;
				}
				bool operator>(reverse_iterator const &iter)
				{
					if (this->iter > iter.iter)
						return true;
					return false;
				}
		};
		typedef iterator const_iterator;
		typedef reverse_iterator const_reverse_iterator;
		/*class const_reverse_iterator
		{
			private:
				pointer iter;
			public:
				const_reverse_iterator() {}
				const_reverse_iterator(pointer iter) {this->iter = iter;}
				~const_reverse_iterator() {}
				T &operator*() {return *(this->iter);}
				const_reverse_iterator *getIter() const {return this->iter;} //зачем в векторе?
				const_reverse_iterator &operator++() //проверить выход за пределы листа?
				{
					const_reverse_iterator *pos;
					++this->iter;
					pos = this;
					return *pos;
				}
				const_reverse_iterator &operator--() //проверить
				{
					const_reverse_iterator *pos = this;
					--this->iter;
					//pos = this;
					return *pos;
				}
				bool operator!=(const_reverse_iterator const &iter)
				{
					if (this->iter != iter.iter)
						return true;
					return false;
				}
				bool operator==(const_reverse_iterator const &iter)
				{
					if (this->iter == iter.iter)
						return true;
					return false;
				}
				bool operator<(const_reverse_iterator const &iter)
				{
					if (this->iter < iter.iter)
						return true;
					return false;
				}
				bool operator>(const_reverse_iterator const &iter)
				{
					if (this->iter > iter.iter)
						return true;
					return false;
				}
		}; */
	private:
		allocator_type alloc;
		size_type v_capacity;
		size_type v_size;
		pointer ptr;

	public:
		explicit vector(const allocator_type& alloc = allocator_type())
		{
			this->alloc = alloc;
			this->v_capacity = 0;
			this->v_size = 0;
			this->ptr = nullptr;

		}
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			this->alloc = alloc;
			this->v_size = n;
			this->v_capacity = n;
			this->ptr = new value_type[n];
			for (size_type i = 0; i < n; i++)
				this->ptr[i] = val;
		}	
		//template <class InputIterator>
		//vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		vector(iterator first, iterator last, const allocator_type& alloc = allocator_type())
		{
			this->alloc = alloc;
			this->v_size = last - first;
			this->v_capacity = last - first;
			this->ptr = new value_type[this->v_size];
			this->assign(first, last);
		}
		vector(const vector& x)
		{
			/*this->alloc = alloc;
			this->v_capacity = 0;
			this->v_size = 0;
			this->ptr = NULL; */
			this->v_capacity = 0;
			this->ptr = nullptr;
			*this = x;
		}
		vector &operator=(const vector& x)
		{
			if (this->ptr) //убрать?
				delete this->ptr;
			this->ptr = new value_type[x.capacity()];
			this->v_capacity = x.capacity();
			this->v_size = 0;
			std::cout << *(x.begin()) << " end = " << *(x.end()) << std::endl;
			this->assign(x.begin(), x.end());
			return (*this);
		}
		~vector()
		{

		}

		reference operator[](size_type n)
		{
			return this->ptr[n];
		}
		const_reference operator[] (size_type n) const
		{
			return this->ptr[n];
		}
		//template <class InputIterator>
		//void assign (InputIterator first, InputIterator last);

		void assign(iterator first, iterator last)
		{
			this->clear();
			while (first != last)
			{
				this->push_back(*first);
				//std::cout << "first = " << *first << std::endl;
				++first;
			}
		}
		void assign(size_type n, const value_type& val)
		{
			this->clear();
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

		}
		size_type capacity() const
		{
			return this->v_capacity;
		}
		void clear()
		{
			while (this->v_size) //нужно ли очищать содержимое элементов?
				this->v_size--;
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
			return iterator(&this->ptr[this->v_size]);
		}
		iterator erase(iterator position)
		{
			iterator tmp = position;
			iterator last = position;
			while(position != this->end())
			{
				*position = *(++last);
				++position;
				//++last;
			}
			this->v_size -= 1;
			return tmp;
			/*if (position == --this->end())
			{
				this->pop_back();
				return --this->end();
			}
			else
			{
				//return (this->erase(position, ++position));

				iterator tmp = position;
				return (this->erase(position, ++tmp));
			}*/
			//iterator tmp = position;
			//return (this->erase(position, ++tmp));
		}
		iterator erase(iterator first, iterator last)
		{ //return end if the operation erased the last element in the sequence.
			iterator tmp = last;
			while(last != this->end())
			{
				std::cout << "I AM HERE \n";
				*first = *last;
				++first;
				++last;
			}
			std::cout << "diff = " << last - first << std::endl;
			this->v_size -= (last - first) - 1; //разобраться откуда лишняя единица
			std::cout << "this size = " << this->size() << std::endl;
			return tmp;
		}
		reference front()
		{
			return (this->ptr[0]);
		}
		const_reference front() const
		{
			return (this->ptr[0]);
		}
		allocator_type get_allocator() const
		{

		}
		iterator insert(iterator position, const value_type& val)
		{
			size_type pos = position - this->begin();
			this->insert(position, 1, val);
			//return (iterator(&this->ptr[pos])); //выбрать из двух вариантов
			return (position);
		}	
    	void insert(iterator position, size_type n, const value_type& val)
		{
			//vector<T, Alloc> tmp(position, this->end());
			vector tmp(position, this->end());
			if (this->size() + n > this->capacity())
			{
				size_type cap = this->capacity();
				while(cap < this->size() + n)
					cap *= 2;
				this->reserve(cap);
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
    	void insert(iterator position, iterator first, iterator last)
		{
			//vector<T, Alloc> tmp(position, this->end());
			vector tmp(position, this->end());
			if (this->size() + (last - first) > this->capacity())
			{
				size_type cap = this->capacity();
				while(cap < this->size() + (last - first))
					cap *= 2;
				this->reserve(cap);
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
			return (std::numeric_limits<size_type>::max() / sizeof(value_type));
		}
		void pop_back()
		{
			if (this->v_size)
				this->v_size--;
		}
		void push_back(const value_type& val)
		{ 
			//рассмотреть случай когда больше чем вместимость
			//std::cout << "size = " << this->v_size << " cap = " << this->v_capacity << std::endl;
			if (this->v_size == this->v_capacity)
			{
				if (this->v_capacity)
					this->reserve(this->v_capacity * 2);
				else
				{
					//this->ptr = nullptr;
					this->reserve(2);
				}
			}
			this->ptr[this->v_size] = val;
			this->v_size++;
		}
		reverse_iterator rbegin()
		{
			return (reverse_iterator(&this->ptr[this->v_size - 1]));

		}
		const_reverse_iterator rbegin() const
		{

		}
		reverse_iterator rend()
		{
			return (reverse_iterator(this->ptr - 1));
		}
		const_reverse_iterator rend() const
		{

		}
		void reserve(size_type n)
		{
			//if n > max size then throw length error
			//std::cout << "cap = " << this->v_capacity << std::endl;
			if (n > this->v_capacity)
			{
				pointer tmp = new value_type[n]; //throw bad alloc
				//throw std::bad_alloc();
				for (size_type i = 0; i < this->v_size; i++)
					tmp[i] = this->ptr[i];
				if (this->ptr) //убрать?
					delete this->ptr;
				this->ptr = tmp;
				this->v_capacity = n;
			}
		}
		void resize(size_type n, value_type val = value_type())
		{
			if (n > this->capacity())
				this->reserve(n);
			if (n > this->size())
			{
				//for (size_type i = this->size(); i < n; i++)
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

		void swap(vector& x) //переписать
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
	if (lhs.size() == rhs.size())
	{
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return false;
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
	typename ft::vector<T, Alloc>::iterator first1 = lhs.begin();
	typename ft::vector<T, Alloc>::iterator last1 = lhs.end();
	typename ft::vector<T, Alloc>::iterator first2 = rhs.begin();
	typename ft::vector<T, Alloc>::iterator last2 = rhs.end();
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
/*	if (lhs.size() <= rhs.size())
	{
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return false;
		}
	return false;
*/
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

#endif