#ifndef STD_STACK_H
#define STD_STACK_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

namespace std
{
template <class T, class Container=deque<T,allocator<T>>>
class stack
{
public:
	boolean empty();

	int size();

	void top();

	void push(T& x);

	void pop();

};

}  // namespace std
#endif
