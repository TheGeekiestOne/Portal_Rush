#ifndef STD_VECTOR_H
#define STD_VECTOR_H

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
class vector
{
public:
	vector();

	~vector();

	operator==();

	operator<();

	operator!=();

	operator>();

	operator>=();

	operator<=();

	operation[](int n);

	iterator begin();

	iterator end();

	iterator rbegin();

	iterator rend();

	int size() const;

	int max_size() const;

	void resize(int sz, int c) const;

	int capacity() const;

	boolean empty() const;

	void reserve() const;

	void at(int size_type);

	void front();

	void back();

	void assign(InputIterator first, InputIterator last);

	void assign(int n, int& u);

	void push_back(T& x);

	void pop_back();

	iterator insert(iterator position, T& x);

	iterator insert(iterator position, int n, T& x);

	void insert(iterator position, InputIterator first, InputIterator last);

	void erase(iterator position );

	void erase(iterator first, iterator last);

	void swap(vector& vec);

	void clear();

	allocator get_allocator();

};

}  // namespace std
#endif
