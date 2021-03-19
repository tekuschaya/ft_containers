#pragma once

#include "Iterator.hpp"

namespace ft
{

template < class T, class Alloc = std::allocator<T> >
class list
{
	public:
		typedef NodeList<T> node;
		typedef NodeList<T>* node_ptr;
		typedef Alloc allocator_type;
		typedef size_t size_type;
		typedef T value_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef IterList<T> iterator;
		typedef ConstIterList<T> const_iterator;
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef ReverseIterator<const_iterator> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
	private:
		size_type l_size;
		node_ptr l_start;
		node_ptr l_end;
		allocator_type alloc;
		void _init()
		{
			node_ptr tmp = new node();
			this->l_size = 0;
			this->l_start = tmp;
			this->l_end = tmp;
			this->l_start->next = this->l_end;
			this->l_end->prev = this->l_start;
		}
		void _swap_value(node_ptr one, node_ptr two)
		{
			value_type tmp = one->value;
			one->value = two->value;
			two->value = tmp;
		}
		node_ptr partition(node_ptr head, node_ptr tail)
		{
			node_ptr p = head->prev;

			for (node_ptr tmp = head; tmp != tail; tmp = tmp->next)
			{
				if (tmp->value <= tail->value)
				{
					if (p == this->l_end)
						p = head;
					else
						p = p->next;
					//p = (p == this->l_end)? head : p->next;
					this->_swap_value(p, tmp);
				}
			}
			if (p == this->l_end)
				p = head;
			else
				p = p->next;
			
			//p = (p == this->l_end)? head : p->next;
			this->_swap_value(p, tail);
			return p;
		}
		void _quickSort(node_ptr head, node_ptr tail)
		{
			if (tail != this->l_end && head != tail && head != tail->next)
			{
				node_ptr p = partition(head, tail);
				_quickSort(head, p->prev);
				_quickSort(p->next, tail);
			}
		}
	public:
		explicit list(const allocator_type& alloc = allocator_type())
		{
			this->_init();
			this->alloc = alloc;
		}
		explicit list(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			this->_init();
			this->alloc = alloc;
			this->assign(n, val);
		}
		template <class InputIterator>
		list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
		typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			this->_init();
			this->alloc = alloc;
			this->assign(first, last);
		}
		~list()
		{
			this->clear();
			delete this->l_end;
		}
		list(const list& x)
		{
			this->_init();
			*this = x;
		}
		list &operator=(const list& x)
		{
			this->alloc = x.alloc;
			this->assign(x.begin(), x.end());
			return *this;
		}
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
		typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			this->clear();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		void assign(size_type n, const value_type& val)
		{
			this->clear();
			for (size_type i = 0; i < n; i++)
				push_back(val);
		}
		reference back()
		{
			return this->l_end->prev->value;
		}
		const_reference back() const
		{
			return this->l_end->prev->value;
		}
		iterator begin()
		{
			return (iterator(this->l_start));
		}
		const_iterator begin() const
		{
			return (const_iterator(this->l_start));
		}
		void clear()
		{
			if (this->l_size)
				this->erase(this->begin(), this->end());
		}
		bool empty() const
		{
			if (!this->l_size)
				return true;
			return false;
		}
		iterator end()
		{
			return (iterator(this->l_end));
		}
		const_iterator end() const
		{
			return (const_iterator(this->l_end));
		} 
		iterator erase(iterator position)
		{
			if (!this->l_size)
				return this->end();
			node_ptr pos;
			node_ptr tmp;
			pos = position.getNode();
			if (pos == this->l_start)
			{
				this->pop_front();
				return iterator(this->l_start);
			}
			if (pos == this->l_end)
			{
				this->pop_back();
				return iterator(this->l_end);
			}
			tmp = pos->next;
			tmp->prev = pos->prev;
			pos->prev->next = tmp;
			delete pos;
			this->l_size--;
			return (iterator)tmp;
		}
		iterator erase(iterator first, iterator last)
		{
			while (first != last)
			{
				this->erase(first);
				++first;
			}
			return first;
		}
		reference front()
		{
			return this->l_start->value;
		}
		const_reference front() const
		{
			return this->l_start->value;
		}
		iterator insert(iterator position, const value_type& val)
		{
			if (position == this->begin())
			{
				this->push_front(val);
				return (this->begin());
			}
			if (position == --this->end())
			{
				this->push_back(val);
				return (--this->end());
			}
			node_ptr tmp = new node();
			tmp->value = val;
			node_ptr pos = position.getNode();
			pos->prev->next = tmp;
			tmp->prev = pos->prev;
			tmp->next = pos;
			pos->prev = tmp;
			this->l_size++;
			return (iterator)tmp;
		}
		void insert(iterator position, size_type n, const value_type& val)
		{
			for (size_type i = 0; i < n; i++)
				this->insert(position, val);
		}
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
		typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			while (first != last)
			{
				this->insert(position, *first);
				++first;
			}
		}
		size_type max_size() const
		{
			return (std::numeric_limits<size_type>::max() / sizeof(node));
		}
		void merge (list& x)
		{
			if (x == *this)
				return ;
			iterator first1 = this->begin();
			iterator last1 = this->end();
			iterator first2 = x.begin();
			iterator last2 = x.end();
			iterator tmp;
			while (first1 != last1 && first2 != last2)
			{
				while (first1 != last1 && *first1 < *first2)
					++first1;
				tmp = first2;
				++first2;
				this->splice(first1, x, tmp);
			}
			if (first2 != last2)
				this->splice(first1, x, first2, last2);
		}
		template <class Compare>
		void merge (list& x, Compare comp)
		{
			if (x == *this)
				return ;
			iterator first1 = this->begin();
			iterator last1 = this->end();
			iterator first2 = x.begin();
			iterator last2 = x.end();
			iterator tmp;
			while (first1 != last1 && first2 != last2)
			{
				while (first1 != last1 && !comp(*first2, *first1))
				//while (first1 != last1 && comp(*first1, *first2))
					++first1;
				tmp = first2;
				++first2;
				this->splice(first1, x, tmp);
			}
			if (first2 != last2)
				this->splice(first1, x, first2, last2);
		}
		void pop_back()
		{
			node_ptr tmp = this->l_end->prev;
			tmp->prev->next = this->l_end;
			this->l_end->prev = tmp->prev;
			delete tmp;
			this->l_size--;
		}
		void pop_front()
		{
			node_ptr tmp = this->l_start;
			this->l_start = tmp->next;
			this->l_start->prev = this->l_end;
			delete tmp;
			this->l_size--;
		}
		void push_back(const value_type& val)
		{
			node_ptr tmp = new node;
			tmp->value = val;
			if (!this->l_size)
			{
				tmp->next = this->l_end;
				tmp->prev = this->l_end;
				this->l_end->prev = tmp;
				this->l_end->next = tmp;
				this->l_start = tmp;
			}
			else
			{
				tmp->prev = this->l_end->prev;
				tmp->next = this->l_end;
				this->l_end->prev->next = tmp;
				this->l_end->prev = tmp;
			}
			this->l_size++;
		}
		void push_front(const value_type& val)
		{
			node_ptr tmp = new node();
			tmp->value = val;
			if (!this->l_size)
			{
				tmp->next = this->l_end;
				tmp->prev = this->l_end;
				this->l_start = tmp;
				this->l_end->prev = tmp;
				this->l_end->next = tmp;
			}
			else
			{
				tmp->next = this->l_start;
				tmp->prev = this->l_end;
				this->l_start->prev = tmp;
				this->l_start = tmp;
				this->l_end->next = this->l_start;
			}
			this->l_size++;
		}
		reverse_iterator rbegin()
		{
			return (reverse_iterator(this->end()));
		}
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(this->end()));
		}
		void remove(const value_type& val)
		{
			iterator first = this->begin();
			iterator last = this->end();
			while (first != last)
			{
				if (*first == val)
					first = this->erase(first);
				else
					++first;
			}
		}
		template <class Predicate>
		void remove_if(Predicate pred)
		{
			iterator first = this->begin();
			iterator last = this->end();
			while (first != last)
			{
				if (pred(*first))
					first = this->erase(first);
				else
					++first;
			}
		}
		reverse_iterator rend()
		{
			return(reverse_iterator(this->begin()));
		}
		const_reverse_iterator rend() const
		{
			return(const_reverse_iterator(this->begin()));
		}
		void resize (size_type n, value_type val = value_type())
		{
			if (n < this->l_size)
			{
				while (n < this->l_size)
					this->pop_back();
			}
			else
			{
				while (n > this->l_size)
					this->push_back(val);
			}
		}
		void reverse()
		{
			iterator first = this->begin();
			iterator last = --this->end();
			for (size_type i = 0; i < this->l_size / 2; i++)
			{
				_swap_value(first.getNode(), last.getNode());
				++first;
				--last;
			}
		}
		size_type size() const
		{
			return this->l_size;
		}
		void sort()
		{
			if (this->l_size < 2)
				return ;
			this->_quickSort(this->l_start, this->l_end->prev);
		}
		/*void sort()
		{
			if (this->l_size < 2)
				return ;
			iterator it = this->begin();
			iterator ite = this->end();
			iterator tmp = it;
			while (++tmp != ite)
			{
				if (*tmp < *it)
				{
					_swap_value(it.getNode(), tmp.getNode());
					it = this->begin();
					tmp = it;
				}
				else
					++it;
			}
		}*/
		template <class Compare>
		void sort (Compare comp) //переписать quicksort?
		{
			if (this->l_size < 2)
				return ;
			iterator it = this->begin();
			iterator ite = this->end();
			iterator tmp = it;
			while (++tmp != ite)
			{
				if (comp(*tmp, *it))
				{
					_swap_value(it.getNode(), tmp.getNode());
					it = this->begin();
					tmp = it;
				}
				else
					++it;
			}
		}
		void splice (iterator position, list& x)
		{
			this->splice(position, x, x.begin(), x.end());
		}
		void splice (iterator position, list& x, iterator i)
		{
			iterator tmp = i;
			this->splice(position, x, i, ++tmp);
		}
		
		void splice (iterator position, list& x, iterator first, iterator last)
		{
			size_type i = 0;
			node_ptr tmp = position.getNode();
			node_ptr first_elem = first.getNode();
			node_ptr last_elem = last.getNode();
			node_ptr last_tmp = last_elem->prev;
			if (first == x.l_start)
				x.l_start = last_elem;
			first_elem->prev->next = last_elem;
			last_elem->prev = first_elem->prev;
			while (first != last)
			{
				i++;
				++first;
			}
			this->l_size += i;
			x.l_size -= i;
			if (!x.size())
				x.l_start = x.l_end;
			if (position == this->begin())
			{
				this->l_end->next = first_elem;
				first_elem->prev = this->l_end;
				this->l_start = first_elem;
			}
			else
			{
				tmp->prev->next = first_elem;
				first_elem->prev = tmp->prev;
			}
			last_tmp->next = tmp;
			tmp->prev = last_tmp;
		}
		void swap (list& x)
		{
			list tmp = *this;
			*this = x;
			x = tmp;
		}
		void unique()
		{
			iterator it = ++this->begin();
			iterator ite = this->end();
			while (it != ite)
			{
				if (*it == it.getNode()->prev->value)
					it = erase(it);
				else
					++it;
			}
		}
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred)
		{
			iterator it = this->begin();
			iterator ite = this->end();
			iterator tmp = ++this->begin();
			while (tmp != ite)
			{
				if (binary_pred(*it, *tmp))
					tmp = erase(tmp);
				else
				{
					++it;
					++tmp;
				}
			}
		}
};

template <class T, class Alloc>
bool operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	typename ft::list<T, Alloc>::const_iterator first1 = lhs.begin();
	typename ft::list<T, Alloc>::const_iterator last1 = lhs.end();
	typename ft::list<T, Alloc>::const_iterator first2 = rhs.begin();
	typename ft::list<T, Alloc>::const_iterator last2 = rhs.end();
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
bool operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return false;
	return true;
}
template <class T, class Alloc>
bool operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	typename ft::list<T, Alloc>::const_iterator first1 = lhs.begin();
	typename ft::list<T, Alloc>::const_iterator last1 = lhs.end();
	typename ft::list<T, Alloc>::const_iterator first2 = rhs.begin();
	typename ft::list<T, Alloc>::const_iterator last2 = rhs.end();

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
bool operator<=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	if (lhs < rhs || lhs == rhs)
		return true;
	return false;
}	
template <class T, class Alloc>
bool operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	if (lhs <= rhs)
		return false;
	return true;
}
template <class T, class Alloc>
bool operator>=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	if (lhs < rhs)
		return false;
	return true;
}
template <class T, class Alloc>
void swap (list<T,Alloc>& x, list<T,Alloc>& y)
{
	list<T, Alloc> tmp = x;
	x = y;
	y = tmp;
}

}
