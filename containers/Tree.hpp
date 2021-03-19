#pragma once

#include "Iterator.hpp"

namespace ft
{

template < class T >   
class Tree
{
	public:
		typedef T value_type;
		typedef NodeTree<value_type>* node;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef size_t size_type;
		typedef IterTree<value_type> iterator;
		typedef ConstIterTree<value_type> const_iterator;

		typedef ReverseIterator<iterator> reverse_iterator;
		typedef ReverseIterator<const_iterator> const_reverse_iterator;
	protected:
		size_type m_size;
		node m_node;
		enum color { BLACK, RED };
		node _new_node(value_type value, node parent, int color)
		{
			node tmp = new NodeTree<value_type>();
			tmp->value = value;
			tmp->right = NULL;
			tmp->left = NULL;
			tmp->parent = parent;
			tmp->color = color;
			return tmp;
		}
		void rotate_left(node x)
		{
			node y = x->right;
			if (y)
			{
				x->right = y->left;
				if (y->left)
				{
					y->left->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == this->m_node)
				{
					this->m_node->left = y;
				}
				else if (x == x->parent->left)
				{
					x->parent->left = y;
				}
				else
				{
					x->parent->right = y;
				}
				y->left = x;
				x->parent = y;
			}
		}
		void rotate_right(node x)
		{
			node y = x->left;
			if (y)
			{
				x->left = y->right;
				if (y->right)
				{
					y->right->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == this->m_node)
				{
					this->m_node->left = y;
				}
				else if (x == x->parent->right)
				{
					x->parent->right = y;
				}
				else
				{
					x->parent->left = y;
				}
				y->right = x;
				x->parent = y;
			}
  		}
		node grandparent(node n)
		{
			if (n && n->parent)
				return n->parent->parent;
			else
				return NULL;
		}
		node uncle(node n)
		{
			node g = this->grandparent(n);
			if (!g)
				return NULL;
			if (n->parent == g->left)
				return g->right;
			else
				return g->left;
		}
		void check_node(node n)
		{
			node u = this->uncle(n);
			node g = this->grandparent(n);
			if (n->parent == this->m_node)
				n->color = BLACK;
			else if (n->parent->color == BLACK)
				return ;
			else if (u && u->color == RED)
			{
				n->parent->color = BLACK;
				u->color = BLACK;
				g->color = RED;
				this->check_node(g);
			}
			else if (n == n->parent->right && n->parent == g->left)
			{
				this->rotate_left(n->parent);
				n = n->left;
			}
			else if (n == n->parent->left && n->parent == g->right)
			{
				this->rotate_right(n->parent);
				n = n->right;
			}
			else
			{
				n->parent->color = BLACK;
				g->color = RED;
				if (n == n->parent->left && n->parent == g->left)
					this->rotate_right(g);
				else
					this->rotate_left(g);
			}
		}
		void printHelper(node root, std::string indent, bool last)
		{
			if (root)
			{
				std::cout << indent;
				if (last)
				{
					std::cout << "R----";
					indent += "   ";
				} 
				else
				{
					std::cout << "L----";
					indent += "|  ";
				}
				std::string sColor = root->color ? "RED" : "BLACK";
				std::cout << root->value << "(" << sColor << ")" << std::endl;
				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true); 
   			}
  		}
		template <class K>
		void printHelper(node root, K key, std::string indent, bool last)
		{
			if (root)
			{
				std::cout << indent;
				if (last)
				{
					std::cout << "R----";
					indent += "   ";
				} 
				else
				{
					std::cout << "L----";
					indent += "|  ";
				}
				std::string sColor = root->color ? "RED" : "BLACK";
				std::cout << key << "(" << sColor << ")" << std::endl;
				if (root->left)
					printHelper(root->left, root->left->value.first, indent, false);
				if (root->right)
					printHelper(root->right, root->right->value.first, indent, true);
   			}
  		}
		template <class K>
		node insert_node(node tmp, const value_type& val, K key)
		{
			node new_node;
			if (!this->size())
			{
				this->m_node->left = this->_new_node(val, this->m_node, BLACK);
				this->m_size++;
				return this->m_node->left;
			}
			tmp = this->m_node->left;
			while (true)
			{
				if (key < tmp->value.first)
				{
					if (!tmp->left)
					{
						new_node = this->_new_node(val, tmp, RED);
						tmp->left = new_node;
						break ;
					}
					tmp = tmp->left;
				}
				else
				{
					if (!tmp->right)
					{
						new_node = this->_new_node(val, tmp, RED);
						tmp->right = new_node;
						break ;
					}
					tmp = tmp->right;
				}
			}
			this->check_node(new_node);
			this->m_size++;
			//this->printHelper(this->m_node->left, this->m_node->left->value.first, "", true);
			return new_node;
		}
		node insert_node(node tmp, const value_type& val) 
		{
			node new_node;
			if (!this->size())
			{
				this->m_node->left = this->_new_node(val, this->m_node, BLACK);
				this->m_size++;
				return this->m_node->left;
			}
			tmp = this->m_node->left;
			while (true)
			{
				if (val < tmp->value)
				{
					if (!tmp->left)
					{
						new_node = this->_new_node(val, tmp, RED);
						tmp->left = new_node;
						break ;
					}
					tmp = tmp->left;
				}
				else
				{
					if (!tmp->right)
					{
						new_node = this->_new_node(val, tmp, RED);
						tmp->right = new_node;
						break ;
					}
					tmp = tmp->right;
				}
			}
			this->check_node(new_node);
			this->m_size++;
			//this->printHelper(this->m_node->left, "", true);
			return new_node;
		}
		node min_node(node n)
		{
			while (n->left)
				n = n->left;
			return n;
		}
		void deleteFix(node x)
		{
			node s;
			while (x != this->m_node->left && x->color == BLACK)
			{
				if (x == x->parent->left)
				{
					s = x->parent->right;
					if (s && s->color == RED)
					{
						s->color = BLACK;
						x->parent->color = RED;
						this->rotate_left(x->parent);
						s = x->parent->right;
					}

					if (s && s->left && s->right &&
					s->left->color == BLACK && s->right->color == BLACK)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s && s->right && s->right->color == BLACK)
						{
							if (s->left)
								s->left->color = BLACK;
							s->color = RED;
							this->rotate_right(s);
							s = x->parent->right;
						}
						if (s)
						{
							s->color = x->parent->color;
							if (s->right)
								s->right->color = BLACK;
						}
						x->parent->color = BLACK;
						this->rotate_left(x->parent);
						x = this->m_node->left;
					}
				}
				else
				{
					s = x->parent->left;
					if (s && s->color == RED)
					{
						s->color = BLACK;
						x->parent->color = RED;
						this->rotate_right(x->parent);
						s = x->parent->left;
					}

					if (s && s->right && s->right->color == BLACK)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s && s->left && s->left->color == BLACK)
						{
							if (s->right)
								s->right->color = BLACK;
							s->color = RED;
							this->rotate_left(s);
							s = x->parent->left;
						}
						if (s)
						{
							s->color = x->parent->color;
							if (s->left)
								s->left->color = BLACK;
						}
						x->parent->color = BLACK;
						this->rotate_right(x->parent);
						x = this->m_node->left;
					}
				}
			}
			x->color = BLACK;
		}
		void replace_node(node u, node v)
		{
			if (u->parent == this->m_node)
				this->m_node->left = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			if (v)
				v->parent = u->parent;
		}
		void delete_node(node z)
		{
			node x;
			node y = z;
			if (!z)
				return ;
			int y_original_color = y->color;
			if (!z->left)
			{
				x = z->right;
				this->replace_node(z, z->right);
			}
			else if (!z->right)
			{
				x = z->left;
				this->replace_node(z, z->left);
			} 
			else
			{
				y = this->min_node(z->right);
				y_original_color = y->color;
				x = y->right;
				if (y->parent == z)
				{
					if (x)
						x->parent = y;
				}
				else
				{
					this->replace_node(y, y->right);
					y->right = z->right;
					if (y->right)
						y->right->parent = y;
				}
				this->replace_node(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			delete z;
			this->m_size--;
			if (x && y_original_color == BLACK)
				this->deleteFix(x);
		} 
		
		void free_tree(node tmp)
		{
			if (tmp == NULL)
				return;
			this->free_tree(tmp->left);
			this->free_tree(tmp->right);
			delete tmp;
		}
	public:
		explicit Tree ()
		{
			this->m_size = 0;
			this->m_node = NULL;
		}
		virtual ~Tree() {}
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
		}
		void clear()
		{
			if (this->m_node && this->m_node->left)
			{
				free_tree(this->m_node->left);
				this->m_node->left = NULL;
				this->m_size = 0;
			}
		}
		bool empty() const
		{
			if (!this->m_size)
				return true;
			return false;
		}
		iterator end()
		{
			return (iterator(this->m_node));
		}
		const_iterator end() const
		{
			return (const_iterator(this->m_node));
		}
		std::pair<iterator, bool> insert (const value_type& val)
		{
			iterator tmp = this->find(val.first);
			if (tmp != this->end())
				return (std::make_pair(tmp, false));
			return (std::make_pair(iterator(this->insert_node(this->m_node, val)), RED));
		}
		iterator insert (iterator position, const value_type& val)
		{
			iterator tmp = this->find(val.first);
			if (tmp != this->end())
				return tmp;
			return (iterator(this->insert_node(position.node(), val)));
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
		size_type max_size() const
		{
			return (std::numeric_limits<size_type>::max() / sizeof(NodeTree<value_type>));
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
		size_type size() const
		{
			return (this->m_size);
		}
		void swap (Tree& x)
		{
			Tree tmp = *this;
			*this = x;
			x = tmp;
		}
};

}
