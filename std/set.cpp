#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "set.hpp"

namespace std
{

set::multimap()
{
}

set::~multimap()
{
}

set::operator=()
{
}

iterator set::begin()
{
	return 0;
}

iterator set::end()
{
	return 0;
}

iterator set::rbegin()
{
	return 0;
}

iterator set::rend()
{
	return 0;
}

boolean set::empty() const
{
	return 0;
}

int set::size() const
{
	return 0;
}

int set::max_size() const
{
	return 0;
}

iterator set::insert(iterator position, key& x)
{
	return 0;
}

iterator set::insert(iterator position, int n, key& x)
{
	return 0;
}

void set::erase(iterator position )
{
}

void set::erase(iterator first, iterator last)
{
}

void set::swap(set& vec)
{
}

void set::clear()
{
}

template <class key, class Compare=less<key>, class Allocator=allocator<key>>
 Compare set<key, Compare, Allocator>::key_comp()
{
	return 0;
}

template <class key, class Compare=less<key>, class Allocator=allocator<key>>
 Compare set<key, Compare, Allocator>::value_comp()
{
	return 0;
}

iterator set::find()
{
	return 0;
}

int set::count()
{
	return 0;
}

iterator set::lower_bound()
{
	return 0;
}

iterator set::upper_bound()
{
	return 0;
}

pair<iterator,iterator> set::equal_range()
{
	return 0;
}

allocator set::get_allocator()
{
	return 0;
}
}  // namespace std
