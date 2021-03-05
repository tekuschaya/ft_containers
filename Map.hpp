#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include "IterMap.hpp"

namespace ft
{

template < class Key,                                     				// map::key_type
           class T,                                       				// map::mapped_type
           class Compare = std::less<Key>,                     			// map::key_compare
           class Alloc = std::allocator<std::pair<const Key,T> > >		// map::allocator_type
class map
{
	public:
		typedef std::pair<const Key, T> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef T mapped_type;
		typedef Key key_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef size_t size_type;
		typedef IterMap <key_type, mapped_type> iterator;
		//typedef IterMap <key_type, mapped_type, pointer, reference> const const_iterator;
		//typedef IterMap <key_type const, mapped_type const, pointer, reference> const_iterator;
		typedef const IterMap <key_type, mapped_type> const_iterator;
		//typedef IterMap <key_type, mapped_type, const_pointer, const_reference> const_iterator;
		typedef ReverseIterMap <key_type, mapped_type> reverse_iterator;
		//typedef ReverseIterMap <key_type const, mapped_type const, pointer, reference> const_reverse_iterator;
		typedef const ReverseIterMap <key_type, mapped_type> const_reverse_iterator;
		//typedef ReverseIterMap <key_type, mapped_type, const_pointer, const_reference> const_reverse_iterator;
		typedef Node<key_type, mapped_type>* node;
		//template <class Key, class T, class Compare, class Alloc>
		class value_compare : public std::binary_function<value_type, value_type, bool>
		//class map<Key,T,Compare,Alloc>::value_compare
		{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			friend class map;
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
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
		size_type m_size;
		node m_node;
		//node m_end;
		allocator_type m_alloc;
		key_compare m_comp;
		node _new_node(key_type key, mapped_type value, node parent, bool color = false)
		{
			//node tmp = new node();
			node tmp = new Node<key_type, mapped_type>();
			tmp->pair = std::make_pair(key, value); //почитать
			tmp->right = nullptr; //почему 0
			tmp->left = nullptr;
			tmp->parent = parent;
			//проверить цвет у родителя?
			tmp->color = color;
			//tmp->end = end; //зачем?
			return tmp;
		}
		void _init()
		{

		}
		/* node insert_node(node tmp, const value_type& val) //сделать ее итератором? 
		{
			//std::cout << "tmp val first = " << tmp->pair.first << " tmp val second = " << tmp->pair.second << std::endl;
			if (!this->size())
			{
				//tmp->left = _new_node(val.first, val.second, tmp, true);
				this->m_node->left = _new_node(val.first, val.second, this->m_node, true);
				this->m_size++;
				return this->m_node->left;
			}
			if (tmp == this->m_node)
				tmp = tmp->left;
			//начальная нода инициализируется парой 0:0?? что будет если придет ключ 0?
			//std::cout << "tmp pair first = " << tmp->pair.first << " second = " << tmp->pair.second << std::endl;
			if (val.first > tmp->pair.first)
			{
				//std::cout << "val = " << val.first << " tmp val first = " << tmp->pair.first << " tmp val second = " << tmp->pair.second << std::endl;

				if (!tmp->right)
				{
					tmp->right = _new_node(val.first, val.second, tmp, true);
					this->m_size++;
					return tmp->right;
				}
				insert_node(tmp->right, val);
			}
			else
			{
				if (!tmp->left)
				{
					tmp->left = _new_node(val.first, val.second, tmp, true);
					this->m_size++;
					return tmp->left;
				}
				insert_node(tmp->left, val);
			}
		} */
		node insert_node(node tmp, const value_type& val) //сделать ее итератором? 
		{
			//std::cout << "tmp val first = " << tmp->pair.first << " tmp val second = " << tmp->pair.second << std::endl;
			if (!this->size())
			{
				//tmp->left = _new_node(val.first, val.second, tmp, true);
				this->m_node->left = _new_node(val.first, val.second, this->m_node, false);
				this->m_size++;
				return this->m_node->left;
			}
			if (tmp == this->m_node)
				tmp = tmp->left;
			while (true)
			{
				if (val.first > tmp->pair.first)
				{
					if (!tmp->right)
					{
						tmp->right = _new_node(val.first, val.second, tmp, true);
						this->m_size++;
						return tmp->right;
					}
					tmp = tmp->right;
				}
				else
				{
					if (!tmp->left)
					{
						tmp->left = _new_node(val.first, val.second, tmp, true);
						this->m_size++;
						return tmp->left;
					}
					tmp = tmp->left;
				}
			}
		}
		void free_tree(node tmp)
		{
			if (tmp->right)
				free_tree(tmp->right);
			if (tmp->left)
				free_tree(tmp->left);
			delete tmp;
		}
	public:
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			this->m_comp = comp;
			this->m_alloc = alloc;
			this->m_size = 0;
			this->m_node = _new_node(key_type(), mapped_type(), 0);
			//this->m_node->right = _new_node(key_type(), mapped_type(), this->m_node, true);
		}
		map (iterator first, iterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			this->m_alloc = alloc;
			this->m_comp = comp;
			this->m_size = 0;
			this->m_node = _new_node(key_type(), mapped_type(), 0);
			//this->m_node->right = _new_node(key_type(), mapped_type(), this->m_node, true);
			this->insert(first, last);
		}
		map (const map& x)
		{
			*this = x;
		}
		~map()
		{
			free_tree(this->m_node);
		}
		iterator begin()
		{
			node tmp = this->m_node;
			while (tmp->left)
				tmp = tmp->left;
			return (iterator(tmp));
		}
		const_iterator begin() const
		{
			node tmp = this->m_node;
			while (tmp->left)
				tmp = tmp->left;
			return (const_iterator(tmp));
			//return (const_iterator(this->m_node));
		}
		void clear()
		{
			//if (this->size()) //убрать этот костыль
			//	this->erase(this->begin(), this->end());
			if (this->m_node && this->m_node->left)
			//if (this->m_node)
			{
				free_tree(this->m_node->left);
				this->m_node->left = nullptr;
				//this->m_node = nullptr;
				this->m_size = 0;
			}


			/*iterator it = this->begin();
			iterator tmp;
			iterator ite = this->end();
			while (it != ite)
			{
				tmp = it;
				++it;
				delete tmp.node();
			}
			this->m_size = 0; */
			//delete ite.node();
		}
		size_type count (const key_type& k) const
		{
			iterator tmp = this->find(k);
			if (tmp != this->end())
				return 1;
			return 0;
		}

		bool empty() const
		{
			if (!this->m_size)
				return true;
			return false;
		}
		iterator end()
		{
			/*node tmp = this->m_node;
			while(tmp->right)
			{
				tmp = tmp->right;
			}
			return (iterator(tmp));*/
			//return (iterator(this->m_node->right)); //идти до самого правого элемента?
			return (iterator(this->m_node)); //идти до самого правого элемента?
		}
		const_iterator end() const
		{
			return (const_iterator(this->m_node));
		}
		std::pair<const_iterator, const_iterator> equal_range (const key_type& k) const
		{
			return (std::pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
		}
		std::pair<iterator, iterator> equal_range (const key_type& k)
		{
			return (std::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
		}
		void erase (iterator position)
		{
			node tmp = position.node();
			node parent = tmp->parent;
			if (!tmp->left && !tmp->right)
			{
				if (parent->left == tmp)
					parent->left = nullptr;
				else
					parent->right = nullptr;
				delete tmp;
			}
			else if (tmp->left && !tmp->right)
			{
				if (parent->left == tmp)
					parent->left = tmp->left;
				else
					parent->right = tmp->left;
				tmp->left->parent = parent;
				delete tmp;
				this->m_size--;
			}
			else if (!tmp->left && tmp->right)
			{
				if (parent->left == tmp)
					parent->left = tmp->right;
				else
					parent->right = tmp->right;
				tmp->right->parent = parent;
				delete tmp;
				this->m_size--;
			}

			//ПЕРЕДЕЛАТЬ
			else
			{
				node next = (++iterator(tmp)).node();
				if (!next)
					next = (--iterator(tmp)).node();
				std::pair<Key, T> new_pair = next->pair;
				next->pair = tmp->pair;
				tmp->pair = new_pair;
				//swap(next->pair, tmp->pair);
				erase(iterator(next));
				//_delete_node(next);
			}
		}
		size_type erase (const key_type& k)
		{
			iterator tmp = this->find(k);
			if (tmp == this->end())
				return 0;
			erase(tmp);
			return 1;
		}
    	void erase (iterator first, iterator last)
		{
			iterator tmp;
			while (first != last)
			{
				tmp = first;
				++first;
				erase(tmp);
			}
		}
		iterator find (const key_type& k)
		{
			iterator it = this->begin();
			iterator ite = this->end();
			while (it != ite)
			{
				if (it->first == k)
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
				if (it->first == k)
					return (const_iterator(it));
				++it;
			}
			return (const_iterator(it));
			//return this->end();
		}
		allocator_type get_allocator() const
		{
			return (this->m_alloc);
		}
		std::pair<iterator, bool> insert (const value_type& val)
		{
			//std::cout << "first = " << val.first << " second = " << val.second << std::endl;
			iterator tmp = this->find(val.first);
			if (tmp != this->end())
				return (std::make_pair(tmp, false));
			//this->m_size++;
			// иначе вставляем ноду
			//return (std::make_pair(iterator(this->insert_node(tmp.node(), val)), true));
			return (std::make_pair(iterator(this->insert_node(this->m_node, val)), true));

		}
		iterator insert (iterator position, const value_type& val)
		{
			iterator tmp = this->find(val.first);
			if (tmp != this->end())
				return tmp;
			//node pos = position.node();
			//this->m_size++;
			return (iterator(this->insert_node(position.node(), val)));
			//if (val.first > )
		}
		void insert (iterator first, iterator last)
		{
			while (first != last)
			{
				//this->insert(first.node()->pair);
				this->insert(*first);
				++first;
			}
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
		size_type max_size() const
		{
			return (std::numeric_limits<size_type>::max() / sizeof(Node<key_type, mapped_type>));
		}
		map& operator=(const map& x)
		{
			this->clear();
			//if (this->m_node)
			//	delete m_node;
			this->m_size = 0;
			this->m_alloc = x.m_alloc;
			this->m_comp = x.m_comp;
			//this->m_node = _new_node(x.m_node->pair.first, x.m_node->pair.second, 0, false);
			this->m_node = _new_node(key_type(), mapped_type(), 0);
			//std::cout << "1 \n";
			/*iterator it = iterator(x.begin().node());
			iterator ite = iterator(x.end().node());
			this->insert(it, ite);*/
			this->insert(x.begin(), x.end());
			return *this;
		}
		mapped_type& operator[](const key_type& k)
		{
			iterator tmp = this->find(k);
			if (tmp != this->end())
				return tmp->second;
			//value_type test = std::make_pair(k, mapped_type());
			//std::cout << "pair 1 = " << test.first << " pair 2 = " << test.second << std::endl;
			//std::cout << "mapped type = " << mapped_type() << std::endl;
			//return (*((this->insert(make_pair(k,mapped_type()))).first)).second;
			//iterator ret = (this->insert(std::make_pair(k, mapped_type()))).first;
			//return ret->second;
			return ((this->insert(std::make_pair(k, mapped_type()))).first->second);
		}
		reverse_iterator rbegin()
		{
			node tmp = this->m_node;
			if (tmp->left)
				tmp = tmp->left;
			while(tmp->right)
				tmp = tmp->right;
			return (reverse_iterator(tmp));
			/*iterator tmp = this->end();
			--tmp;
			return reverse_iterator(tmp.iter); //tmp->iter ?? */
		}
		const_reverse_iterator rbegin() const
		{
			node tmp = this->m_node;
			if (tmp->left)
			{
				tmp = tmp->left;
				while(tmp->right)
					tmp = tmp->right;
			}
			return (const_reverse_iterator(tmp));
			/*iterator tmp = this->end();
			--tmp;
			return const_reverse_iterator(tmp.iter); // tmp->iter */
		}
		reverse_iterator rend()
		{
			/*node tmp = this->m_node;
			while(tmp->left)
				tmp = tmp->left;
			return (reverse_iterator(tmp));*/
			//node tmp = this->m_node;
			//найти самый маленький элемент??
			return (reverse_iterator(this->m_node));
		}
		const_reverse_iterator rend() const
		{
			/*node tmp = this->m_node;
			while(tmp->left)
				tmp = tmp->left;
			return (const_reverse_iterator(tmp));*/
			return (const_reverse_iterator(this->m_node));
		}
		size_type size() const
		{
			return (this->m_size);
		}
		void swap (map& x)
		{
			//map tmp = *this; //СЕГА при очистке несозданной мапы
			map tmp;
			tmp = *this;
			*this = x;
			x = tmp;
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
		value_compare value_comp() const //написать вложенный класс value compare?
		{
			return (value_compare(this->m_comp));
		}
};

template <class Key, class T, class Compare, class Alloc>
bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
{
	typename map<Key,T,Compare,Alloc>::iterator first1 = lhs.begin();
	typename map<Key,T,Compare,Alloc>::iterator last1 = lhs.end();
	typename map<Key,T,Compare,Alloc>::iterator first2 = rhs.begin();
	typename map<Key,T,Compare,Alloc>::iterator last2 = rhs.end();
	while (first1 != last1)
	{
		if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
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
	typename map<Key,T,Compare,Alloc>::iterator first1 = lhs.begin();
	typename map<Key,T,Compare,Alloc>::iterator last1 = lhs.end();
	typename map<Key,T,Compare,Alloc>::iterator first2 = rhs.begin();
	typename map<Key,T,Compare,Alloc>::iterator last2 = rhs.end();
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

}

#endif