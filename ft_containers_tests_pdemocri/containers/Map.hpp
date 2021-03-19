#pragma once

#include "Tree.hpp"

namespace ft
{

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
class map : public Tree<std::pair<Key, T> >
{
	public:
		typedef Tree<std::pair<Key, T> > tree;
		typedef Alloc allocator_type;
		typedef Compare key_compare;
		typedef T mapped_type;
		typedef Key key_type;
		typedef std::pair<const Key, T> value_type;
		typedef size_t size_type;

		using typename tree::iterator;
		using typename tree::const_iterator;
		using typename tree::reverse_iterator;
		using typename tree::const_reverse_iterator;
		using typename tree::node;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		};
	private:
		key_compare m_comp;
		allocator_type m_alloc;
	public:
		explicit map (const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type())
		{
			this->m_alloc = alloc;
			this->m_comp = comp;
			this->m_size = 0;
			this->m_node = this->_new_node(std::make_pair(key_type(), mapped_type()), 0, false);
		}
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type(),
		typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			this->m_alloc = alloc;
			this->m_comp = comp;
			this->m_size = 0;
			this->m_node = this->_new_node(std::make_pair(key_type(), mapped_type()), 0, false);
			this->insert(first, last);
		}
		map(map const &x)
		{
			*this = x;
		}
		map& operator=(const map& x)
		{
			this->clear();
			if (this->m_node)
				delete this->m_node;
			this->m_alloc = x.m_alloc;
			this->m_comp = x.m_comp;
			this->m_size = 0;
			this->m_node = this->_new_node(std::make_pair(key_type(), mapped_type()), 0, false);
			this->insert(x.begin(), x.end());
			return *this;
		}
		virtual ~map()
		{
			this->free_tree(this->m_node->left);
			delete this->m_node;
			this->m_node = NULL;
		}
		size_type count (const key_type& k) const
		{
			const_iterator tmp = this->find(k);
			if (tmp != this->end())
				return 1;
			return 0;
		}
		std::pair<iterator,iterator> equal_range (const key_type& k)
		{
			return (std::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
		}
		std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return (std::pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
		}
		void erase (iterator position)
		{
			node tmp = position.getNode();
			this->delete_node(tmp);
			//this->printHelper(this->m_node->left, this->m_node->left->value.first, "", true);
		}
		size_type erase (const key_type& k)
		{
			iterator tmp = this->find(k);
			if (tmp != this->end())
			{
				this->erase(tmp);
				return 1;
			}
			return 0;
		}
		void erase (iterator first, iterator last)
		{
			iterator tmp;
			while (first != last)
			{
				tmp = first;
				++first;
				this->erase(tmp);
			}
		}
		std::pair<iterator, bool> insert (const value_type& val)
		{
			iterator tmp = this->find(val.first);
			if (tmp != this->end())
				return (std::make_pair(tmp, false));
			return (std::make_pair(iterator(this->insert_node(this->m_node, val, val.first)), true));
		}
		iterator insert (iterator position, const value_type& val)
		{
			iterator tmp = this->find(val.first);
			if (tmp != this->end())
				return tmp;
			return (iterator(this->insert_node(position.getNode(), val, val.first)));
		}
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last,
		typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			while (first != last)
			{
				this->insert(*first);
				++first;
			}
		}
		iterator find (const key_type& k)
		{
			iterator it = this->begin();
			iterator ite = this->end();
			while (it != ite)
			{
				if (!this->m_comp(it->first, k) && !this->m_comp(k, it->first))
					return (it);
				++it;
			}
			return this->end();
		}
		const_iterator find (const key_type& k) const
		{
			const_iterator it = this->begin();
			const_iterator ite = this->end();
			while (it != ite)
			{
				if (!this->m_comp(it->first, k) && !this->m_comp(k, it->first))
					return (const_iterator(it));
				++it;
			}
			return this->end();
		}
		key_compare key_comp() const
		{
			return this->m_comp;
		}
		iterator lower_bound (const key_type& k)
		{
			iterator it = this->begin();
			iterator ite = this->end();
			while (it != ite)
			{
				if (!this->m_comp(it->first, k))
					return it;
				++it;
			}
			return it;
		}
		const_iterator lower_bound (const key_type& k) const
		{
			const_iterator it = this->begin();
			const_iterator ite = this->end();
			while (it != ite)
			{
				if (!this->m_comp(it->first, k))
					return it;
				++it;
			}
			return it;
		}
		mapped_type& operator[](const key_type& k)
		{
			iterator tmp = this->find(k);
			if (tmp != this->end())
				return tmp->second;
			return ((this->insert(std::make_pair(k, mapped_type()))).first->second);
		}
		iterator upper_bound (const key_type& k)
		{
			iterator it = this->begin();
			iterator ite = this->end();
			while (it != ite)
			{
				if (this->m_comp(k, it->first))
					return it;
				++it;
			}
			return it;
		}
		const_iterator upper_bound (const key_type& k) const
		{
			const_iterator it = this->begin();
			const_iterator ite = this->end();
			while (it != ite)
			{
				if (this->m_comp(k, it->first))
					return it;
				++it;
			}
			return it;
		}
		value_compare value_comp() const
		{
			return (value_compare(this->m_comp));
		}
};

template <class Key, class T, class Compare, class Alloc>
bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
{
	typename map<Key,T,Compare,Alloc>::const_iterator first1 = lhs.begin();
	typename map<Key,T,Compare,Alloc>::const_iterator last1 = lhs.end();
	typename map<Key,T,Compare,Alloc>::const_iterator first2 = rhs.begin();
	typename map<Key,T,Compare,Alloc>::const_iterator last2 = rhs.end();
	while (first1 != last1)
	{
		if (!(*first1 == *first2))
			return false;
		++first1;
		++first2;
	}
	return true;
}
template <class Key, class T, class Compare, class Alloc>
bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
{
	if (lhs == rhs)
		return false;
	return true;
}
template <class Key, class T, class Compare, class Alloc>
bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
{
	typename map<Key,T,Compare,Alloc>::const_iterator first1 = lhs.begin();
	typename map<Key,T,Compare,Alloc>::const_iterator last1 = lhs.end();
	typename map<Key,T,Compare,Alloc>::const_iterator first2 = rhs.begin();
	typename map<Key,T,Compare,Alloc>::const_iterator last2 = rhs.end();
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
template <class Key, class T, class Compare, class Alloc>
bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
{
	if (lhs < rhs || lhs == rhs)
		return true;
	return false;
}
template <class Key, class T, class Compare, class Alloc>
bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
{
	if (lhs <= rhs)
		return false;
	return true;
}
template <class Key, class T, class Compare, class Alloc>
bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
{
	if (lhs < rhs)
		return false;
	return true;
}
template <class Key, class T, class Compare, class Alloc>
void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
{
	map<Key,T,Compare,Alloc> tmp;
	tmp = x;
	x = y;
	y = tmp;
}

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
class multimap : public Tree<std::pair<Key, T> >
{
	public:
		typedef Tree<std::pair<Key, T> > tree;
		typedef Alloc allocator_type;
		typedef Compare key_compare;
		typedef T mapped_type;
		typedef Key key_type;
		typedef std::pair<const Key, T> value_type;
		typedef size_t size_type;

		using typename tree::iterator;
		using typename tree::const_iterator;
		using typename tree::reverse_iterator;
		using typename tree::const_reverse_iterator;
		using typename tree::node;
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class multimap;
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		};
	private:
		key_compare m_comp;
		allocator_type m_alloc;
	public:
		explicit multimap (const key_compare& comp = key_compare(),
                   const allocator_type& alloc = allocator_type())
		{
			this->m_alloc = alloc;
			this->m_comp = comp;
			this->m_size = 0;
			this->m_node = this->_new_node(std::make_pair(key_type(), mapped_type()), 0, false);
		}
		template <class InputIterator>
		multimap (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type(),
		typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			this->m_alloc = alloc;
			this->m_comp = comp;
			this->m_size = 0;
			this->m_node = this->_new_node(std::make_pair(key_type(), mapped_type()), 0, false);
			this->insert(first, last);
		}
		multimap(multimap const &x)
		{
			*this = x;
		}
		multimap& operator=(const multimap& x)
		{
			this->clear();
			if (this->m_node)
				delete this->m_node;
			this->m_size = 0;
			this->m_comp = x.m_comp;
			this->m_node = this->_new_node(std::make_pair(key_type(), mapped_type()), 0, false);
			this->insert(x.begin(), x.end());
			return *this;
		}
		virtual ~multimap() 
		{
			this->free_tree(this->m_node->left);
			delete this->m_node;
			this->m_node = NULL;
		}

		size_type count (const key_type& k) const
		{
			size_type i = 0;
			const_iterator it = this->begin();
			const_iterator ite = this->end();
			while (it != ite)
			{
				if (!this->m_comp(it->first, k) && !this->m_comp(k, it->first))
					i++;
				++it;
			}
			return (i);
		}
		std::pair<iterator,iterator> equal_range(const key_type& k)
		{
			return (std::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
		}
		std::pair<const_iterator,const_iterator> equal_range(const key_type& k) const
		{
			return (std::pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
		}

		void erase(iterator position)
		{
			node tmp = position.getNode();
			this->delete_node(tmp);
			//this->printHelper(this->m_node->left, this->m_node->left->value.first, "", true);
		}

		size_type erase (const key_type& k)
		{
			size_type i = 0;
			iterator tmp = this->find(k);
			while (tmp != this->end())
			{
				erase(tmp);
				i++;
				tmp = this->find(k);
			}
			return i;
		}
		void erase (iterator first, iterator last)
		{
			iterator tmp;
			while (first != last)
			{
				tmp = first;
				++first;
				this->erase(tmp);
			}
		}

		iterator insert (const value_type& val)
		{
			return (iterator(this->insert_node(this->m_node, val, val.first)));
		}
		iterator insert (iterator position, const value_type& val)
		{
			return (iterator(this->insert_node(position.getNode(), val, val.first)));
		}
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last,
		typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			while (first != last)
			{
				this->insert(*first);
				++first;
			}
		}
		iterator find (const key_type& k)
		{
			iterator it = this->begin();
			iterator ite = this->end();
			while (it != ite)
			{
				if (!this->m_comp(it->first, k) && !this->m_comp(k, it->first))
					return (it);
				++it;
			}
			return this->end();
		}
		const_iterator find (const key_type& k) const
		{
			iterator it = this->begin();
			iterator ite = this->end();
			while (it != ite)
			{
				if (!this->m_comp(it->first, k) && !this->m_comp(k, it->first))
					return (const_iterator(it));
				++it;
			}
			return this->end();
		}
		key_compare key_comp() const
		{
			return this->m_comp;
		}
		iterator lower_bound (const key_type& k)
		{
			iterator it = this->begin();
			iterator ite = this->end();
			while (it != ite)
			{
				if (!this->m_comp(it->first, k))
					return it;
				++it;
			}
			return it;
		}
		const_iterator lower_bound (const key_type& k) const
		{
			const_iterator it = this->begin();
			const_iterator ite = this->end();
			while (it != ite)
			{
				if (!this->m_comp(it->first, k))
					return it;
				++it;
			}
			return it;
		}
		mapped_type& operator[](const key_type& k)
		{
			iterator tmp = this->find(k);
			if (tmp != this->end())
				return tmp->second;
			return ((this->insert(std::make_pair(k, mapped_type()))).first->second);
		}
		iterator upper_bound (const key_type& k)
		{
			iterator it = this->begin();
			iterator ite = this->end();
			while (it != ite)
			{
				if (this->m_comp(k, it->first))
					return it;
				++it;
			}
			return it;
		}
		const_iterator upper_bound (const key_type& k) const
		{
			const_iterator it = this->begin();
			const_iterator ite = this->end();
			while (it != ite)
			{
				if (this->m_comp(k, it->first))
					return it;
				++it;
			}
			return it;
		}
		value_compare value_comp() const
		{
			return (value_compare(this->m_comp));
		}
};

template <class Key, class T, class Compare, class Alloc>
bool operator==( const multimap<Key,T,Compare,Alloc>& lhs, const multimap<Key,T,Compare,Alloc>& rhs)
{
	typename multimap<Key,T,Compare,Alloc>::const_iterator first1 = lhs.begin();
	typename multimap<Key,T,Compare,Alloc>::const_iterator last1 = lhs.end();
	typename multimap<Key,T,Compare,Alloc>::const_iterator first2 = rhs.begin();
	typename multimap<Key,T,Compare,Alloc>::const_iterator last2 = rhs.end();
	while (first1 != last1)
	{
		if (!(*first1 == *first2))
			return false;
    	++first1;
		++first2;
	}
	return true;
}
template <class Key, class T, class Compare, class Alloc>
bool operator!= ( const multimap<Key,T,Compare,Alloc>& lhs, const multimap<Key,T,Compare,Alloc>& rhs)
{
	if (lhs == rhs)
		return false;
	return true;
}
template <class Key, class T, class Compare, class Alloc>
bool operator<( const multimap<Key,T,Compare,Alloc>& lhs, const multimap<Key,T,Compare,Alloc>& rhs)
{
	typename multimap<Key,T,Compare,Alloc>::const_iterator first1 = lhs.begin();
	typename multimap<Key,T,Compare,Alloc>::const_iterator last1 = lhs.end();
	typename multimap<Key,T,Compare,Alloc>::const_iterator first2 = rhs.begin();
	typename multimap<Key,T,Compare,Alloc>::const_iterator last2 = rhs.end();
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
template <class Key, class T, class Compare, class Alloc>
bool operator<= ( const multimap<Key,T,Compare,Alloc>& lhs, const multimap<Key,T,Compare,Alloc>& rhs)
{
	if (lhs < rhs || lhs == rhs)
		return true;
	return false;
}
template <class Key, class T, class Compare, class Alloc>
bool operator>  ( const multimap<Key,T,Compare,Alloc>& lhs, const multimap<Key,T,Compare,Alloc>& rhs)
{
	if (lhs <= rhs)
		return false;
	return true;
}
template <class Key, class T, class Compare, class Alloc>
bool operator>= ( const multimap<Key,T,Compare,Alloc>& lhs, const multimap<Key,T,Compare,Alloc>& rhs)
{
	if (lhs < rhs)
		return false;
	return true;
}
template <class Key, class T, class Compare, class Alloc>
void swap (multimap<Key,T,Compare,Alloc>& x, multimap<Key,T,Compare,Alloc>& y)
{
	multimap<Key,T,Compare,Alloc> tmp;
	tmp = x;
	x = y;
	y = tmp;
}

}
