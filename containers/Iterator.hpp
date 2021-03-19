#pragma once

#include <memory>
#include <iostream>
#include <limits>
#include <utility>
#include <functional>

namespace ft
{

template <bool B, class T = void>
struct enable_if;

template <typename T>
struct NodeList
{
	NodeList *prev;
	NodeList *next;
	T value;
};


template <typename T>
class IterList
{
	public:
		typedef T value_type;
		typedef NodeList<T>* ptr;
		typedef T* pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef const T* const_pointer;
		typedef ptrdiff_t difference_type;
	protected:
		ptr iter;
	public:
		IterList(): iter(NULL) {}
		IterList(ptr iter): iter(iter) {}
		IterList(IterList const &other): iter(other.iter) {}
		~IterList() {}
		IterList operator=(IterList const &other)
		{
			this->iter = other.iter;
			return *this;
		}
		reference operator*()
		{
			return this->iter->value;
		}
		pointer operator->()
		{
			return &this->iter->value;
		}
		IterList &operator++()
		{
			this->iter = this->iter->next;
			return *this;
		}
		IterList &operator--()
		{
			this->iter = this->iter->prev;
			return *this;
		}
		IterList operator++(int)
		{
			IterList tmp = *this;
			++(*this);
			return tmp;
		}
		IterList operator--(int)
		{
			IterList tmp = *this;
			--(*this);
			return tmp;
		}
		
		bool operator!=(IterList const &iter)
		{
			if (this->iter != iter.iter)
				return true;
			return false;
		}
		bool operator==(IterList const &iter)
		{
			if (this->iter == iter.iter)
				return true;
			return false;
		}
		ptr getNode() const
		{
			return this->iter;
		}
};

template <class T>
class ConstIterList
{
	public:
		typedef T value_type;
		typedef NodeList<T>* ptr;
		typedef IterList<T> iterator;
		typedef T* pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef const T* const_pointer;
	protected:
		ptr iter;
	public:
		ConstIterList() {}
		ConstIterList(const ptr iter): iter(iter) {}
		ConstIterList(const ConstIterList &other): iter(other.iter) {}
		ConstIterList(const iterator &other): iter(other.getNode()) {}
		~ConstIterList() {}

		ConstIterList &operator=(const ConstIterList &other)
		{
			this->iter = other.iter;
			return (*this);
		}
		ConstIterList &operator=(const iterator &other)
		{
			this->iter = other.getNode();
			return (*this);
		}
		reference operator*() const
		{
			return (this->iter->value);
		}
		pointer operator->() const
		{
			return (&this->iter->value);
		}

		ConstIterList &operator++()
		{
			this->iter = this->iter->next;
			return *this;
		}
		ConstIterList &operator--()
		{
			this->iter = this->iter->prev;
			return *this;
		}
		ConstIterList operator++(int)
		{
			ConstIterList tmp = *this;
			++(*this);
			return tmp;
		}
		ConstIterList operator--(int)
		{
			ConstIterList tmp = *this;
			--(*this);
			return tmp;
		}

		bool operator!=(ConstIterList const &iter)
		{
			if (this->iter != iter.iter)
				return true;
			return false;
		}
		bool operator==(ConstIterList const &iter)
		{
			if (this->iter == iter.iter)
				return true;
			return false;
		}
		const ptr getNode() const
		{
			return this->iter;
		}
};

template <class T>
struct NodeTree
{
	T value;
	NodeTree *left;
	NodeTree *right;
	NodeTree *parent;
	int color;
};

template <class T>
class IterTree
{
	public:
		typedef NodeTree<T>* ptr;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef const T& const_reference;
		typedef const T* const_pointer;
	protected:
		ptr iter;
	public:
		IterTree(): iter(NULL) {}
		IterTree(ptr iter): iter(iter) {}
		IterTree(IterTree const &other): iter(other.iter) {}
		~IterTree() {}
		IterTree operator=(IterTree const &other)
		{
			this->iter = other.iter;
			return *this;
		}
		reference operator*()
		{
			return this->iter->value;
		}
		pointer operator->()
		{
			return &this->iter->value;
		}
		ptr getNode() const
		{
			return this->iter;
		}
		IterTree &operator++() 
		{
			ptr tmp;
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
			this->iter = tmp;
			return *this;
		}
		IterTree &operator--()
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
				while (tmp->parent && tmp == tmp->parent->left)
					tmp = tmp->parent;
				if (tmp->parent)
					tmp = tmp->parent;
			}
			this->iter = tmp;
			return *this;
		}
		IterTree operator++(int)
		{
			IterTree tmp = *this;
			++(*this);
			return tmp;
		}
		IterTree operator--(int)
		{
			IterTree tmp = *this;
			--(*this);
			return tmp;
		}
		bool operator!=(IterTree const &other)
		{
			if (this->iter != other.iter)
				return true;
			return false;
		}
		bool operator==(IterTree const &other)
		{
			if (this->iter == other.iter)
				return true;
			return false;
		}
		bool operator<(IterTree const &other)
		{
			if (this->iter < other.iter)
				return true;
			return false;
		}
		bool operator>(IterTree const &other)
		{
			if (this->iter > other.iter)
				return true;
			return false;
		}
};

template <class T>
class ConstIterTree
{
	public:
		typedef NodeTree<T>* ptr;
		typedef IterTree<T> iterator;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef const T& const_reference;
		typedef const T* const_pointer;
	protected:
		ptr iter;
	public:
		ConstIterTree(): iter(NULL) {}
		ConstIterTree(ptr iter): iter(iter) {}
		ConstIterTree(const ConstIterTree &other): iter(other.iter) {}
		ConstIterTree(const iterator &other): iter(other.getNode()) {}
		~ConstIterTree() {}
		ConstIterTree operator=(const ConstIterTree &other)
		{
			this->iter = other.getNode();
			return *this;
		}
		ConstIterTree &operator=(const iterator &other)
		{
			this->iter = other.getNode();
			return (*this);
		}
		reference operator*() const
		{
			return this->iter->value;
		}
		pointer operator->() const
		{
			return &this->iter->value;
		}
		ptr getNode() const
		{
			return this->iter;
		}
		ConstIterTree &operator++()
		{
			ptr tmp;
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
			this->iter = tmp;
			return *this;
		}
		ConstIterTree &operator--()
		{
			ptr tmp;
			if (this->iter->left)
			{
				tmp = this->iter->left;
				while (tmp->right)
					tmp = tmp->right;
			}
			else
			{
				tmp = this->iter;
				while (tmp->parent && tmp == tmp->parent->left)
					tmp = tmp->parent;
				if (tmp->parent)
					tmp = tmp->parent;
			}
			this->iter = tmp;
			return *this;
		}
		ConstIterTree operator++(int)
		{
			ConstIterTree tmp = *this;
			++(*this);
			return tmp;
		}
		ConstIterTree operator--(int)
		{
			ConstIterTree tmp = *this;
			--(*this);
			return tmp;
		}

		bool operator!=(ConstIterTree const &other)
		{
			if (this->iter != other.iter)
				return true;
			return false;
		}
		bool operator==(ConstIterTree const &other)
		{
			if (this->iter == other.iter)
				return true;
			return false;
		}
		bool operator<(ConstIterTree const &other)
		{
			if (this->iter < other.iter)
				return true;
			return false;
		}
		bool operator>(ConstIterTree const &other)
		{
			if (this->iter > other.iter)
				return true;
			return false;
		}
};

template <typename T>
class IterVector
{
	public:
		typedef T value_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
	protected:
		pointer iter;
	public:
		IterVector() {}
		IterVector(pointer iter): iter(iter) {}
		IterVector(const IterVector &other): iter(other.iter) {}
		~IterVector() {}
		IterVector operator=(const IterVector &other)
		{
			this->iter = other.iter;
			return *this;
		}
		pointer operator->()
		{
			return this->iter;
		}
		reference operator*()
		{
			return *this->iter;
		}
		reference operator[](difference_type n)
		{
			return this->iter[n];
		}
		IterVector &operator++()
		{
			++this->iter;
			return *this;
		}
		IterVector &operator--()
		{
			--this->iter;
			return *this;
		}
		IterVector operator++(int)
		{
			IterVector tmp = *this;
			++(*this);
			return tmp;
		}
		IterVector operator--(int)
		{
			IterVector tmp = *this;
			--(*this);
			return tmp;
		}
		IterVector operator+(difference_type n) const
		{
			return IterVector(this->iter + n);
		}
		IterVector operator-(difference_type n) const
		{
			return IterVector(this->iter - n);
		}
			IterVector operator+=(difference_type n) const
		{
			this->iter += n;
			return *this;
		}
		IterVector operator-=(difference_type n) const
		{
			this->iter -= n;
			return *this;
		}
		bool operator!=(IterVector const &iter)
		{
			if (this->iter != iter.iter)
				return true;
			return false;
		}
		bool operator==(IterVector const &iter)
		{
			if (this->iter == iter.iter)
				return true;
			return false;
		}
		bool operator<(IterVector const &iter)
		{
			if (this->iter < iter.iter)
				return true;
			return false;
		}
		bool operator>(IterVector const &iter)
		{
			if (this->iter > iter.iter)
				return true;
			return false;
		}
		pointer base() const
		{
			return this->iter;
		}
		difference_type operator-(IterVector const &other)
		{
			return (this->iter - other.iter);
		}
};

template <typename T>
class ConstIterVector
{
	public:
		typedef T* pointer;
		typedef T& reference;
		typedef const T* const_pointer;
		typedef const T& const_reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef IterVector<T> iterator;
	protected:
		pointer iter;
	public:
		ConstIterVector() {}
		ConstIterVector(const pointer iter): iter(iter) {}
		ConstIterVector(const iterator &other): iter(other.base()) {}
		ConstIterVector(const ConstIterVector &other): iter(other.iter) {}
		~ConstIterVector() {}
		ConstIterVector operator=(const ConstIterVector &other)
		{
			this->iter = other.iter;
			return *this;
		}
		ConstIterVector operator=(const iterator &other)
		{
			this->iter = other.base();
			return *this;
		}
		pointer operator->() const
		{
			return this->iter;
		}
		reference operator*() const
		{
			return *this->iter;
		}
		reference operator[](difference_type n)
		{
			return this->iter[n];
		}
		ConstIterVector &operator++()
		{
			++this->iter;
			return *this;
		}
		ConstIterVector &operator--()
		{
			--this->iter;
			return *this;
		}
		ConstIterVector operator++(int)
		{
			ConstIterVector tmp = *this;
			++(*this);
			return tmp;
		}
		ConstIterVector operator--(int)
		{
			ConstIterVector tmp = *this;
			--(*this);
			return tmp;
		}
		ConstIterVector operator+(difference_type n) const
		{
			return ConstIterVector(this->iter + n);
		}
		ConstIterVector operator-(difference_type n) const
		{
			return ConstIterVector(this->iter - n);
		}
			ConstIterVector operator+=(difference_type n) const
		{
			this->iter += n;
			return *this;
		}
		ConstIterVector operator-=(difference_type n) const
		{
			this->iter -= n;
			return *this;
		}
		bool operator!=(ConstIterVector const &iter)
		{
			if (this->iter != iter.iter)
				return true;
			return false;
		}
		bool operator==(ConstIterVector const &iter)
		{
			if (this->iter == iter.iter)
				return true;
			return false;
		}
		bool operator<(ConstIterVector const &iter)
		{
			if (this->iter < iter.iter)
				return true;
			return false;
		}
		bool operator>(ConstIterVector const &iter)
		{
			if (this->iter > iter.iter)
				return true;
			return false;
		}
		pointer base() const
		{
			return this->iter;
		}
		difference_type operator-(ConstIterVector const &other)
		{
			return (this->iter - other.iter);
		}
};

template<typename It>
class ReverseIterator: public It
{
public:
    using typename It::pointer;
    using typename It::const_pointer;
    using typename It::reference;
    using typename It::const_reference;
	ReverseIterator(): It() {}
	ReverseIterator(It const &it): It(it) {}
	ReverseIterator(ReverseIterator const &other): It(other.iter) {}
	ReverseIterator &operator=(ReverseIterator const &other)
	{
		this->iter = other.iter;
		return (*this);
	}
	reference operator*()
	{
		It tmp(*this);
		return (*--tmp);
	}
	const_reference operator*() const
	{
		It tmp(*this);
		return (*--tmp);
	}
	pointer operator->()
	{
		It tmp(*this);
		return (&*--tmp);
	}
	const_pointer operator->() const
	{
		It tmp(*this);
		return (&*--tmp);
	}
	ReverseIterator operator++(int)
	{
		ReverseIterator tmp(*this);
		operator++();
		return (tmp);
	}
	It &operator++()
	{
		return (this->It::operator--());
	}
	ReverseIterator operator--(int)
	{
		ReverseIterator tmp(*this);
		operator--();
		return (tmp);
	}
	It &operator--()
	{
		return (this->It::operator++());
	}
};

}
