
#include <iostream>

#include <cassert>
//#define NDEBUG

#include "DLNode.h"
#include "DLList.h"

using namespace std;

int main(int argc, char** argv)
{
	assert(true);

	// {{{ test DLNode
	{
		//DLNode<int> n1;  // should fail, private
		DLNode<int> n1(10);

		assert(10 == n1.getData());
	}


	// }}}

	// {{{ DLList, push pop
	{
		DLList<int> dl1;

		assert(0 == dl1.getNodeCount());

		for (int i = 0; i < 10; i++) {
			dl1.pushFront(i);
			dl1.pushBack(i+20);
		}
		assert(20 == dl1.getNodeCount());

		for (int i = 0; i < 10; i++) {
			dl1.popBack();
			dl1.popFront();
		}
		assert(0 == dl1.getNodeCount());

		// Nothing should happen when popping an empty list.
		for (int i = 0; i < 10; i++) {
			dl1.popBack();
			dl1.popFront();
		}
		assert(0 == dl1.getNodeCount());

	}
	// }}}

	// {{{ DLList, clear
	{
		DLList<int> dl1;

		assert(0 == dl1.getNodeCount());

		for (int i = 0; i < 10; i++) {
			dl1.pushFront(i);
			dl1.pushBack(i+20);
		}
		assert(20 == dl1.getNodeCount());

		//dl1.clearRecursive();
		dl1.clear();
		assert(0 == dl1.getNodeCount());
	}
	// }}}

	// {{{ DLList, clearRecursive
	{
		DLList<int> dl1;

		assert(0 == dl1.getNodeCount());

		for (int i = 0; i < 100; i++) {
			dl1.pushFront(i);
		}
		assert(100 == dl1.getNodeCount());

		dl1.clearRecursive();
		assert(0 == dl1.getNodeCount());

		for (int j = 0; j < 20; j++) {
			for (int i = 0; i < 10; i++) {
				dl1.pushFront(i);
			}
			dl1.popBack();
			dl1.popFront();
		}
		assert(0 < dl1.getNodeCount());
		dl1.clearRecursive();
		assert(0 == dl1.getNodeCount());
	}
	// }}}

	// {{{ DLList, find
	{
		DLList<int> dl1;

		for (int i = 0; i < 100; i++) {
			dl1.pushFront(i);
		}

		assert(dl1.find(99));
		assert(dl1.find(50));

		for (int i = 0; i < 5; i++) {
			dl1.popBack();
			dl1.popFront();
		}

		assert(dl1.find(65));
		assert(dl1.find(52));

		assert(!dl1.find(100));
		assert(!dl1.find(99));
		assert(!dl1.find(0));
		assert(!dl1.find(1));

	}
	// }}}

	// {{{ DLList, findRecursive
	{
		DLList<int> dl1;

		for (int i = 0; i < 100; i++) {
			dl1.pushFront(i);
		}

		assert(dl1.findRecursive(99));
		assert(dl1.findRecursive(50));

		for (int i = 0; i < 5; i++) {
			dl1.popBack();
			dl1.popFront();
		}

		assert(dl1.findRecursive(65));
		assert(dl1.findRecursive(52));

		assert(!dl1.findRecursive(100));
		assert(!dl1.findRecursive(99));
		assert(!dl1.findRecursive(0));
		assert(!dl1.findRecursive(1));

	}
	// }}}

	// {{{ memory leak test
	// 4/19/2011 tested OK
	/*
	{
		DLList<int> dl1;

		while (1) {
			DLList<int> dl2;

			assert(0 == dl1.getNodeCount());
			assert(0 == dl2.getNodeCount());

			for (int i = 0; i < 100; i++) {
				dl1.pushFront(i);
				dl1.pushBack(i);
			}

			for (int i = 0; i < 100; i++) {
				dl2.pushFront(i);
				dl2.pushBack(i);
			}

			//dl2.clearRecursive();
			dl1.clear();
		}
	}
	*/
	// }}}

	cout << "All tests passed.\n";
}

// vim:foldmethod=marker
