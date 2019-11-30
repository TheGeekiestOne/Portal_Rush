#ifndef STD_PRIORITY_QUEUE_H
#define STD_PRIORITY_QUEUE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

namespace std
{
template <class T, class Container, class Compare>
class priority_queue
{
public:
	boolean empty();

	int size();

	T front();

	T back();

	T top();

	void push(T& x);

	void pop();

};

}  // namespace std
#endif
