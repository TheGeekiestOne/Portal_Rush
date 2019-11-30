#ifndef STD_MAP_H
#define STD_MAP_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "std/iterator.hpp"
#include "std/pair.hpp"
#include "std/allocator.hpp"

namespace std
{
template <class key, class T, class Compare=less<key>, class Allocator=allocator<pair<key,T>>>
class map
{
public:
	map();

	~map();

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

	boolean empty() const;

	int size() const;

	int max_size() const;

	void operator[]();

	iterator insert(iterator position, key& x);

	iterator insert(iterator position, int n, key& x);

	void erase(iterator position );

	void erase(iterator first, iterator last);

	void swap(map& vec);

	void clear();

	Compare key_comp();

	Compare value_comp();

	iterator find();

	int count();

	iterator lower_bound();

	iterator upper_bound();

	pair<iterator,iterator> equal_range();

	allocator get_allocator();

};

}  // namespace std
#endif
