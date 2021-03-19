#pragma once

#include "Tree.hpp"

namespace ft
{

template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
class set : public Tree<T>
{
	public:
		typedef Tree<T> tree;
		typedef Alloc allocator_type;
		typedef Compare key_compare;
		typedef Compare value_compare;
		typedef T value_type;
		typedef T key_type;
		typedef size_t size_type;
		typedef ConstIterTree<T> iterator;
		typedef ConstIterTree<T> const_iterator;
		using typename tree::reverse_iterator;
		using typename tree::const_reverse_iterator;
		using typename tree::node;
		using typename tree::pointer;
	private:
		key_compare s_comp;
		allocator_type s_alloc;
	public:
		explicit set (const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type())
		{
			this->s_alloc = alloc;
			this->s_comp = comp;
			this->m_size = 0;
			this->m_node = this->_new_node(value_type(), 0, 0);
		}
		template <class InputIterator>
		set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type(),
		typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			this->s_alloc = alloc;
			this->s_comp = comp;
			this->m_size = 0;
			this->m_node = this->_new_node(value_type(), 0, 0);
			this->insert(first, last);
		}
		set(set const &x)
		{
			*this = x;
		}
		set& operator=(const set& x)
		{
			this->clear();
			if (this->m_node)
				delete this->m_node;
			this->s_alloc = x.s_alloc;
			this->s_comp = x.s_comp;
			this->m_size = 0;
			this->m_node = this->_new_node(value_type(), 0, 0);
			this->insert(x.begin(), x.end());
			return *this;
		}
		virtual ~set()
		{			
			this->free_tree(this->m_node->left);
			delete this->m_node;
			this->m_node = NULL;
		}
		size_type count (const value_type& val) const
		{
			iterator tmp = this->find(val);
			if (tmp != this->end())
				return 1;
			return 0;
		}
		std::pair<iterator,iterator> equal_range (const value_type& val) const
		{
			return (std::pair<const_iterator, const_iterator>(this->lower_bound(val), this->upper_bound(val)));
		}

		void erase (iterator position)
		{
			node tmp = position.getNode();
			this->delete_node(tmp);
			//this->printHelper(this->m_node->left, "", true);
		}
		size_type erase (const value_type& val)
		{
			iterator tmp = this->find(val);
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
			iterator tmp = this->find(val);
			if (tmp != this->end())
				return (std::make_pair(tmp, false));
			return (std::make_pair(iterator(this->insert_node(this->m_node, val)), true));
		}
		iterator insert (iterator position, const value_type& val)
		{
			iterator tmp = this->find(val);
			if (tmp != this->end())
				return tmp;
			return (iterator(this->insert_node(position.getNode(), val)));
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
		iterator find (const value_type& val) const
		{
			iterator it = this->begin();
			iterator ite = this->end();
			while (it != ite)
			{
				if (!this->s_comp(*it, val) && !this->s_comp(val, *it))
					return (it);
				++it;
			}
			return this->end();
		}
		key_compare key_comp() const
		{
			return this->s_comp;
		}
		iterator lower_bound (const value_type& val)
		{
			iterator it = this->begin();
			iterator ite = this->end();
			while (it != ite)
			{
				if (!this->s_comp(*it, val))
					return it;
				++it;
			}
			return it;
		}
		const_iterator lower_bound (const value_type& val) const
		{
			const_iterator it = this->begin();
			const_iterator ite = this->end();
			while (it != ite)
			{
				if (!this->s_comp(*it, val))
					return it;
				++it;
			}
			return it;
		}
		size_type max_size() const
		{
			return (std::numeric_limits<size_type>::max() / (sizeof(NodeTree<value_type>) - sizeof(pointer)));
		}
		iterator upper_bound (const value_type& val)
		{
			iterator it = this->begin();
			iterator ite = this->end();
			while (it != ite)
			{
				if (this->s_comp(val, *it))
					return it;
				++it;
			}
			return it;
		}
		const_iterator upper_bound (const value_type& val) const
		{
			const_iterator it = this->begin();
			const_iterator ite = this->end();
			while (it != ite)
			{
				if (this->s_comp(val, *it))
					return it;
				++it;
			}
			return it;
		}
		value_compare value_comp() const
		{
			return (this->s_comp);
		}
};

template <class T, class Compare, class Alloc>
bool operator==( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs)
{
	typename set<T,Compare,Alloc>::const_iterator first1 = lhs.begin();
	typename set<T,Compare,Alloc>::const_iterator last1 = lhs.end();
	typename set<T,Compare,Alloc>::const_iterator first2 = rhs.begin();
	typename set<T,Compare,Alloc>::const_iterator last2 = rhs.end();
	while (first1 != last1)
	{
		if (!(*first1 == *first2))
			return false;
    	++first1;
		++first2;
	}
	return true;
}
template <class T, class Compare, class Alloc>
bool operator!= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs)
{
	if (lhs == rhs)
		return false;
	return true;
}
template <class T, class Compare, class Alloc>
bool operator<( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs)
{
	typename set<T,Compare,Alloc>::const_iterator first1 = lhs.begin();
	typename set<T,Compare,Alloc>::const_iterator last1 = lhs.end();
	typename set<T,Compare,Alloc>::const_iterator first2 = rhs.begin();
	typename set<T,Compare,Alloc>::const_iterator last2 = rhs.end();
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
template <class T, class Compare, class Alloc>
bool operator<= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs)
{
	if (lhs < rhs || lhs == rhs)
		return true;
	return false;
}
template <class T, class Compare, class Alloc>
bool operator>  ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs)
{
	if (lhs <= rhs)
		return false;
	return true;
}
template <class T, class Compare, class Alloc>
bool operator>= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs)
{
	if (lhs < rhs)
		return false;
	return true;
}
template <class T, class Compare, class Alloc>
void swap (set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y)
{
	set<T,Compare,Alloc> tmp;
	tmp = x;
	x = y;
	y = tmp;
}

template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
class multiset : public Tree<T>
{
	public:
		typedef Tree<T> tree;
		typedef Alloc allocator_type;
		typedef Compare key_compare;
		typedef Compare value_compare;
		typedef T value_type;
		typedef T key_type;
		typedef size_t size_type;
		typedef ConstIterTree<T> iterator;
		typedef ConstIterTree<T> const_iterator;
		using typename tree::reverse_iterator;
		using typename tree::const_reverse_iterator;
		using typename tree::node;
		using typename tree::pointer;

	private:
		key_compare ms_comp;
		allocator_type ms_alloc;
	public:
		explicit multiset (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			this->ms_alloc = alloc;
			this->ms_comp = comp;
			this->m_size = 0;
			this->m_node = this->_new_node(value_type(), 0, 0);
		}
		template <class InputIterator>
		multiset (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
       	const allocator_type& alloc = allocator_type(),
		typename std::enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type* = 0)
		{
			this->ms_alloc = alloc;
			this->ms_comp = comp;
			this->m_size = 0;
			this->m_node = this->_new_node(value_type(), 0, 0);
			this->insert(first, last);
		}
		multiset(multiset const &x)
		{
			*this = x;
		}
		multiset& operator=(const multiset& x)
		{
			this->clear();
			if (this->m_node)
				delete this->m_node;
			this->ms_alloc = x.ms_alloc;
			this->ms_comp = x.ms_comp;
			this->m_size = 0;
			this->m_node = this->_new_node(value_type(), 0, 0);
			this->insert(x.begin(), x.end());
			return *this;
		}
		virtual ~multiset()
		{
			this->free_tree(this->m_node->left);
			delete this->m_node;
			this->m_node = NULL;
		}

		size_type count (const value_type& val) const
		{
			size_type i = 0;
			iterator it = this->begin();
			iterator ite = this->end();
			while (it != ite)
			{
				if (!this->ms_comp(*it, val) && !this->ms_comp(val, *it))
					i++;
				++it;
			}
			return (i);
		}
		std::pair<iterator,iterator> equal_range (const value_type& val) const
		{
			return (std::pair<const_iterator, const_iterator>(this->lower_bound(val), this->upper_bound(val)));
		}

		void erase (iterator position)
		{
			node tmp = position.getNode();
			this->delete_node(tmp);
			//this->printHelper(this->m_node->left, "", true);
		}

		size_type erase (const value_type& val)
		{
			size_type i = 0;
			iterator tmp = this->find(val);
			while (tmp != this->end())
			{
				erase(tmp);
				i++;
				tmp = this->find(val);
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
			return (iterator(this->insert_node(this->m_node, val)));

		}
		iterator insert (iterator position, const value_type& val)
		{
			return (iterator(this->insert_node(position.getNode(), val)));
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
		iterator find (const value_type& val) const
		{
			iterator it = this->begin();
			iterator ite = this->end();
			while (it != ite)
			{
				if (!this->ms_comp(*it, val) && !this->ms_comp(val, *it))
					return (it);
				++it;
			}
			return this->end();
		}
		key_compare key_comp() const
		{
			return this->ms_comp;
		}
		iterator lower_bound (const value_type& val)
		{
			iterator it = this->begin();
			iterator ite = this->end();
			while (it != ite)
			{
				if (!this->ms_comp(*it, val))
					return it;
				++it;
			}
			return it;
		}
		const_iterator lower_bound (const value_type& val) const
		{
			const_iterator it = this->begin();
			const_iterator ite = this->end();
			while (it != ite)
			{
				if (!this->ms_comp(*it, val))
					return it;
				++it;
			}
			return it;
		}
		size_type max_size() const
		{
			return (std::numeric_limits<size_type>::max() / (sizeof(NodeTree<value_type>) - sizeof(pointer)));
		}
		iterator upper_bound (const value_type& val)
		{
			iterator it = this->begin();
			iterator ite = this->end();
			while (it != ite)
			{
				if (this->ms_comp(val, *it))
					return it;
				++it;
			}
			return it;
		}
		const_iterator upper_bound (const value_type& val) const
		{
			const_iterator it = this->begin();
			const_iterator ite = this->end();
			while (it != ite)
			{
				if (this->ms_comp(val, *it))
					return it;
				++it;
			}
			return it;
		}
		value_compare value_comp() const
		{
			return (this->ms_comp);
		}
};

template <class T, class Compare, class Alloc>
bool operator==( const multiset<T,Compare,Alloc>& lhs, const multiset<T,Compare,Alloc>& rhs)
{
	typename multiset<T,Compare,Alloc>::const_iterator first1 = lhs.begin();
	typename multiset<T,Compare,Alloc>::const_iterator last1 = lhs.end();
	typename multiset<T,Compare,Alloc>::const_iterator first2 = rhs.begin();
	typename multiset<T,Compare,Alloc>::const_iterator last2 = rhs.end();
	while (first1 != last1)
	{
		if (!(*first1 == *first2))
			return false;
    	++first1;
		++first2;
	}
	return true;
}
template <class T, class Compare, class Alloc>
bool operator!= ( const multiset<T,Compare,Alloc>& lhs, const multiset<T,Compare,Alloc>& rhs)
{
	if (lhs == rhs)
		return false;
	return true;
}
template <class T, class Compare, class Alloc>
bool operator<( const multiset<T,Compare,Alloc>& lhs, const multiset<T,Compare,Alloc>& rhs)
{
	typename multiset<T,Compare,Alloc>::const_iterator first1 = lhs.begin();
	typename multiset<T,Compare,Alloc>::const_iterator last1 = lhs.end();
	typename multiset<T,Compare,Alloc>::const_iterator first2 = rhs.begin();
	typename multiset<T,Compare,Alloc>::const_iterator last2 = rhs.end();
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
template <class T, class Compare, class Alloc>
bool operator<= ( const multiset<T,Compare,Alloc>& lhs, const multiset<T,Compare,Alloc>& rhs)
{
	if (lhs < rhs || lhs == rhs)
		return true;
	return false;
}
template <class T, class Compare, class Alloc>
bool operator>  ( const multiset<T,Compare,Alloc>& lhs, const multiset<T,Compare,Alloc>& rhs)
{
	if (lhs <= rhs)
		return false;
	return true;
}
template <class T, class Compare, class Alloc>
bool operator>= ( const multiset<T,Compare,Alloc>& lhs, const multiset<T,Compare,Alloc>& rhs)
{
	if (lhs < rhs)
		return false;
	return true;
}
template <class T, class Compare, class Alloc>
void swap (multiset<T,Compare,Alloc>& x, multiset<T,Compare,Alloc>& y)
{
	multiset<T,Compare,Alloc> tmp;
	tmp = x;
	x = y;
	y = tmp;
}

}