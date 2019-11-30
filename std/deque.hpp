#ifndef STD_DEQUE_H
#define STD_DEQUE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "std/iterator.hpp"
#include "std/InputIterator.hpp"
#include "std/allocator.hpp"

namespace std
{
template <class T, class Allocator=allocator<T>>
class deque
{
public:
	deque();

	~deque();

	operator==();

	operator<();

	operator!=();

	operator>();

	operator>=();

	operator<=();

	operator=();

	iterator begin();

	iterator end();

	iterator rbegin();

	iterator rend();

	int size() const;

	int max_size() const;

	void resize(int sz, T c) const;

	boolean empty() const;

	void at();

	void front();

	void back();

	void assign(int n, int& u);

	void assign(InputIterator first, InputIterator last);

	void push_front();

	void pop_front();

	void push_back(T& x);

	void pop_back();

	iterator insert(iterator position, T& x);

	iterator insert(iterator position, int n, T& x);

	void erase(iterator position );

	void erase(iterator first, iterator last);

	void swap(deque& vec);

	void clear();

	allocator get_allocator();

};

}  // namespace std
#endif
