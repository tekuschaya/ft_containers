#ifndef ITERMAP_HPP
#define ITERMAP_HPP

#include <utility>

template <class Key, class T>
struct Node
{
	std::pair<Key, T> pair;
	Node *left;
	Node *right;
	Node *parent;
	bool color;
	//bool end; //нужен ли??
};

//template <class Key, class T, typename pointer, typename reference>
template <class Key, class T>
class IterMap //двунаправленный итератор?
{
	public:
		typedef std::pair<Key, T> value_type;
		/*typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;
		typedef const T* const_pointer; */
		typedef Node<Key, T>* ptr;
		ptr iter;
	/*private:   //protected??
		ptr iter; */
	public:
		IterMap() {this->iter = nullptr;}
		IterMap(const ptr iter) {this->iter = iter;}
		//IterMap(const ptr iter): iter(iter) {}
		~IterMap() {}

		value_type &operator*()
		{
			//return this->ptr->pair;
			return this->iter->pair;
		}
		value_type *operator->()
		{
			//return this->ptr->pair;
			return &this->iter->pair;
		}
		ptr node()
		{
			return this->iter;
		}
		//IterMap *getIter() const {return this->iter;} //зачем в векторе?

		IterMap &operator++() 
		{
			ptr tmp; //если это последняя вершина? return end()
			if (this->iter->right)
			{
				tmp = this->iter->right;
				while (tmp->left)
					tmp = tmp->left;
			}
			else
			{
				tmp = this->iter;
				while(tmp->parent && tmp == tmp->parent->right)
					tmp = tmp->parent;
				tmp = tmp->parent;
				/*if (tmp->parent && tmp == tmp->parent->left)
					tmp = tmp->parent;
				else
				{
					while(tmp->parent && tmp == tmp->parent->right)
						tmp = tmp->parent;
				}*/
				
				/*if (this->iter->parent)
				{
					tmp = this->iter->parent;
					while(tmp->right)
						tmp = tmp->right;
				}*/
				
				//while (tmp->parent && tmp == tmp->parent->right)
				/*while (tmp->parent)
				{
					tmp = tmp->parent;
					if (tmp->parent &&  == tmp->parent->left)
						
				}*/
				
			}
			this->iter = tmp;
			return *this;
		}
		IterMap &operator--()
		{
			ptr tmp;
			if (this->iter->left)
			{
				tmp = this->iter->left;
				while(tmp->right)
					tmp = tmp->right;
			}
			else
			{
				tmp = this->iter;
				while (tmp->parent && tmp == tmp->parent->left) //исправить??
					tmp = tmp->parent;
				if (tmp->parent)
					tmp = tmp->parent;
				//while (this->iter->)
			}
			this->iter = tmp;
			return *this;
		}
		bool operator!=(IterMap const &iter)
		{
			if (this->iter != iter.iter)
				return true;
			return false;
		}
		bool operator==(IterMap const &iter)
		{
			if (this->iter == iter.iter)
				return true;
			return false;
		}
		bool operator<(IterMap const &iter)
		{
			if (this->iter < iter.iter)
				return true;
			return false;
		}
		bool operator>(IterMap const &iter)
		{
			if (this->iter > iter.iter)
				return true;
			return false;
		}
		size_t operator-(IterMap const &iter)
		{
			return (this->iter - iter.iter);
		}
};

template <class Key, class T>
//template <class Key, class T, typename pointer, typename reference>
class ReverseIterMap
{
	public:
		typedef std::pair<Key, T> value_type;
		typedef Node<Key, T>* ptr;
		ptr iter;
	/*private: //protected??
		ptr iter; */
	public:
		ReverseIterMap() {}
		ReverseIterMap(ptr iter) {this->iter = iter;}
		~ReverseIterMap() {}


		value_type &operator*()
		{
			return this->iter->pair;
		}
		value_type *operator->()
		{
			return &this->iter->pair;
		}
		ReverseIterMap &operator++()
		{
			ptr tmp;
			if (this->iter->left)
			{
				tmp = this->iter->left;
				while(tmp->right)
					tmp = tmp->right;
			}
			else
			{
				tmp = this->iter;
				while (tmp->parent && tmp == tmp->parent->left) //исправить??
					tmp = tmp->parent;
				if (tmp->parent)
					tmp = tmp->parent;
				//while (this->iter->)
			}
			this->iter = tmp;
			return *this;
			/*ptr tmp;
			if (this->iter->left)
			{
				tmp = this->iter->left;
				while(tmp->right)
					tmp = tmp->right;
			}
			else
			{
				if (this->iter->parent) //исправить??
					tmp = this->iter->parent;
				//while (this->iter->)
			}
			this->iter = tmp;
			return *this;*/
		}
		ReverseIterMap &operator--() //проверить
		{
			ptr tmp; //если это последняя вершина? return end()
			if (this->iter->right)
			{
				tmp = this->iter->right;
				while (tmp->left)
					tmp = tmp->left;
			}
			else
			{
				tmp = this->iter;
				while(tmp->parent && tmp == tmp->parent->right)
					tmp = tmp->parent;
				tmp = tmp->parent;
			}
			/*ptr tmp; //если это последняя вершина?
			if (this->iter->right)
			{
				tmp = this->iter->right;
				while (tmp->left)
					tmp = tmp->left;
			}
			else
			{
				tmp = this->iter;
				while(tmp->right)
					tmp = tmp->right;
			} */
			this->iter = tmp;
			return *this;
		}
		bool operator!=(ReverseIterMap const &iter)
		{
			if (this->iter != iter.iter)
				return true;
			return false;
		}
		bool operator==(ReverseIterMap const &iter)
		{
			if (this->iter == iter.iter)
				return true;
			return false;
		}
		bool operator<(ReverseIterMap const &iter)
		{
			if (this->iter < iter.iter)
				return true;
			return false;
		}
		bool operator>(ReverseIterMap const &iter)
		{
			if (this->iter > iter.iter)
				return true;
			return false;
		}
		size_t operator-(ReverseIterMap const &iter)
		{
			return (this->iter - iter.iter);
		}

};

#endif