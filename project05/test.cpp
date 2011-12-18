
#include "Queue.h"
#include <iostream>

//#define NDEBUG
#include <cassert>

using namespace std;

int main(int argc, char** argv)
{

	// {{{ Queue

	// {{{ pop_front
	{
	Queue<int> q;
	assert(0 == q.size());

	q.push_back(1);
	q.push_back(2);
	q.push_back(3);

	assert(1 == q.front());

	q.pop_front();

	assert(2 == q.front());
	assert(2 == q.size());
	}
	// }}}

	// {{{ to_front
	{
	Queue<int> q;
	assert(0 == q.size());
	Queue<int>::iterator ic;

	q.push_back(1);
	q.push_back(2);
	q.push_back(3);

	assert(1 == q[0]);
	assert(2 == q[1]);
	assert(3 == q[2]);

	//ic = q.begin();
	//ic += 2;
	ic = q.end() - 1;

	q.to_front(ic);

	assert(3 == q[0]);
	assert(1 == q[1]);
	assert(2 == q[2]);

	ic = q.begin() + 1;

	q.to_front(ic);

	assert(1 == q[0]);
	assert(3 == q[1]);
	assert(2 == q[2]);

	}
	// }}}

	// }}}

    cout << "All tests passed.\n";
}
