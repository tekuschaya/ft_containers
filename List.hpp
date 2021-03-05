#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"

namespace ft
{

template <typename T>
class list
{
	public:
		typedef size_t size_type;
		typedef T value_type;
		class iterator
		{
			private:
				Node<T> *iter;
				//T *iter;
			public:
				iterator() {}
				iterator(Node<T> *iter) {this->iter = iter;}
				~iterator() {}
				T &operator*() {return this->iter->value;}
				Node<T> *getIter() const {return this->iter;}
				iterator &operator++() //проверить выход за пределы листа?
				{
					iterator *pos;
					this->iter = this->iter->next;
					pos = this;
					return *pos;
				}
				iterator &operator--()
				{
					iterator *pos;
					this->iter = this->iter->prev;
					pos = this;
					return *pos;
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
		};
	private:
		size_type list_size;
		Node<T> *list_start;
		Node<T> *list_end;
	public:
		list() {this->list_size = 0; this->list_start = nullptr; this->list_end = nullptr;}
		list(size_type size) //выделение памяти?
		{
			for (size_type i = 0; i < size; i++)
				push_back(0);
			/*this->list_size = size;
			this->list_start = nullptr;
			this->list_end = nullptr;*/
		}
		~list() {} //очистка листа?
		list(list const &) {}
		list &operator=(list const &list)
		{
			this->clear();
			this->assign(list.begin(), list.end());
			return *this;
			//this->list_size = list.list_size;
		}
		size_type size() const {return this->list_size;}
		iterator begin() {return (iterator(this->list_start));}
		iterator end() const //если список пустой?
		{
			if (this->list_size)
				return (iterator)this->list_end->next;
			return (this->list_end);
		} 
		void assign(iterator first, iterator last)
		{
			iterator tmp = this->begin();
			this->insert(tmp, first, last);
			this->erase(tmp, this->end());
		}
		void assign(size_type n, T value)
		{
			this->clear();
			for (size_type i = 0; i < n; i++)
				push_back(value);
		}
		void assign(T *il) //список инициализации??
		{

		}
		void insert(iterator position, size_type n, const value_type& val)
		{
			for (size_type i = 0; i < n; i++)
				this->insert(position, val);
		}
		//template <class InputIterator> написать!!
		void insert(iterator position, iterator first, iterator last)
		{
			while (first != last)
			{
				this->insert(position, *first);
				++first;
			}
		}
		iterator insert(iterator position, const value_type& val)
		{
			if (position == this->begin())
			{
				this->push_front(val);
				return (this->begin());
			}
			if (position == this->end())
			{
				this->push_back(val);
				return (this->end());
			}
			Node<T> *tmp = new Node<T>(val);
			Node<T> *pos = position.getIter();
			pos->prev->next = tmp;
			pos->prev = tmp;
			tmp->prev = pos->prev;
			tmp->next = pos;
			return (iterator)tmp;

		}
		iterator erase(iterator position)
		{
			if (!this->list_size)
				return this->end();
			Node<T> *pos;
			Node<T> *tmp;
			pos = position.getIter();
			if (pos == this->list_start)
			{
				this->pop_front();
				return this->list_start;
			}
			if (pos == this->list_end)
			{
				this->pop_back();
				return this->list_end; //list->next?
			}
			tmp = pos->next;
			tmp->prev = pos->prev;
			pos->prev->next = tmp;
			delete pos;
			this->list_size--;
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
		void clear()
		{
			if (this->list_size)
				this->erase(this->begin(), this->end());
			//this->list_start = nullptr;
			//this->list_end = nullptr;
		}
		void push_back(T value)
		{
			Node<T> *pos = new Node<T>(value);
			if (!this->list_size)
			{
				this->list_start = pos;
				this->list_end = pos;
			}
			else
			{
				pos->prev = this->list_end;
				this->list_end->next = pos;
				this->list_end = pos;
			}
			this->list_size++;
		}
		void push_front(T value)
		{
			Node<T> *pos = new Node<T>(value);
			if (!this->list_size)
			{
				this->list_start = pos;
				this->list_end = pos;
			}
			else
			{
				pos->next = this->list_start;
				this->list_start->prev = pos;
				this->list_start = pos;
			}
			this->list_size++;
		}
		void pop_back() //проверка на пустой лист?
		{
			Node<T> *pos;
			//pos->next = nullptr; //оставить?
			pos = this->list_end->prev;
			delete this->list_end;
			this->list_end = pos;
			this->list_size--;
		}
		void pop_front()
		{
			Node<T> *pos;
			//pos->prev = nullptr;
			pos = this->list_start->next;
			//pos->prev = nullptr;
			delete this->list_start;
			this->list_start = pos;
			this->list_size--;
		}
		void front() const
		{
			return this->list_start;
		}
		void back() const
		{
			return this->list_end;
		}
		bool empty()
		{
			if (!this->list_size)
				return true;
			return false;
		}
		void reverse()
		{
			T tmp;
			iterator first = this->begin();
			iterator last = this->list_end; //последний элемент выделить память
			/*while (first != this->end())
			{
				this->push_front(*first);
				++first;
			}*/
			for (size_type i = 0; i < this->list_size / 2; i++)
			{
				tmp = *first;
				*first = *last;
				*last = tmp;
				++first;
				--last;
			}
		}
		//void swap()
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
		template<typename Predicate>
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
};

}

#endif