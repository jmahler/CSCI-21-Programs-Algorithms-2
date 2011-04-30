
#include <iostream>

#include <cassert>
//#define NDEBUG

#include "DLNode.h"
#include "DLList.h"

#include "DataThing.h"

#include "BoolThing.h"
#include "CharThing.h"
#include "IntegerThing.h"
#include "StringThing.h"
#include "DoubleThing.h"

using namespace std;

// used as a function pointer by process()
int total = 0;
void _sum(int x) {
	total += x;
}

int main(int argc, char** argv)
{
	assert(true);

	// {{{ DLNode, int
	{
		//DLNode<int> n1;  // should fail, private
		DLNode<int> n1(10);

		assert(10 == n1.getData());
		assert(11 != n1.getData());
	}
	// }}}

	// {{{ BoolThing
	{
		BoolThing bl1;

		bl1.print();

		BoolThing bl2(false);
		BoolThing bl3(true);
		BoolThing bl4 = bl3;

		bl1.setValue(true);

		assert(bl1 != bl2);

		assert(bl1.getId() != bl2.getId());

		assert(bl1 == bl3);

		assert(bl1.getId() != bl3.getId());
		assert(bl4.getId() == bl3.getId());

		bl1 = bl2;  // assignment operator
		assert(bl1.getId() != bl2.getId());
		assert(bl1 == bl2);

		assert(bl2 < bl3);

		//cout << bl1 << endl;
		//cout << bl2 << endl;
		//cout << bl3 << endl;
	}
	// }}}

	// {{{ IntegerThing
	{
		IntegerThing t1(10);
		IntegerThing t2(20);

		assert(10 == t1.getValue());
		assert(20 == t2.getValue());

		t1.setValue(13);
		assert(13 == t1.getValue());

		assert(!(t1 == t2));
		assert((t1 < t2));
	}
	// }}}

	// {{{ CharThing
	{
		CharThing t1('A');
		CharThing t2('B');

		assert('A' == t1.getValue());
		assert('B' == t2.getValue());

		t1.setValue('C');
		assert('C' == t1.getValue());
		assert('A' != t1.getValue());

		assert(!(t1 == t2));
	}
	// }}}

	// {{{ StringThing
	{
		StringThing t1("abc");
		StringThing t2("DeF");

		assert("abc" == t1.getValue());
		assert("DeF" == t2.getValue());

		t1.setValue("ghi");
		assert("ghi" == t1.getValue());
		assert("abc" != t1.getValue());

		assert(!(t1 == t2));
	}
	// }}}

	// {{{ DoubleThing
	{
		DoubleThing t1(1.124);
		DoubleThing t2(-10.5);

		assert(1.124 == t1.getValue());
		assert(-10.5 == t2.getValue());

		t1.setValue(3.14159);
		assert(3.14159 == t1.getValue());

		assert(!(t1 == t2));
		assert((t1 > t2));
	}
	// }}}

	// {{{ DLNode, IntegerThing
	{
		DLNode<IntegerThing> a(1);
		DLNode<IntegerThing> b(3);

		assert(1 == a.getData().getValue());
		assert(3 == b.getData().getValue());

		assert(a.getData() < b.getData());
		assert(b.getData() > a.getData());
		assert(b.getData() >= a.getData());
		assert(a.getData() <= b.getData());
		assert(a.getData() != b.getData());
		assert(! (a.getData() >= b.getData()));
		assert(! (a.getData() > b.getData()));
	}
	// }}}

	// {{{ DLNode, BoolThing
	{
		DLNode<BoolThing> x(true);

		assert(true == x.getData().getValue());

		x.setData(false);

		assert(! x.getData().getValue());
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

	// {{{ DLList, insert [DISABLED]
	{
		DLList<int> dl1;

		for (int i = 99; i >= 0; i--) {
			dl1.insert(i);
		}

		assert(dl1.find(99));
		assert(dl1.find(50));
	}
	// }}}

	// {{{ DLList, remove()
	{
	DLList<int> dl1;

	for (int i = 0; i < 10; i++) {
		dl1.insert(i);
	}

	dl1.remove(0, true); // one_or_all=true

	dl1.remove(1);
	dl1.remove(2);

	assert(!dl1.find(0));
	assert(!dl1.find(1));
	assert(!dl1.find(2));
	assert(dl1.find(3));
	assert(dl1.find(4));
	}
	// }}}

	// {{{ DLList, remove()
	{
	DLList<int> dl1;

	// 0 1 2
	for (int i = 0; i < 3; i++) {
		dl1.insert(i);
	}

	assert(dl1.find(0));
	assert(dl1.find(1));
	assert(dl1.find(2));

	dl1.remove(2);
	assert(dl1.find(0));
	assert(dl1.find(1));
	assert(!dl1.find(2));

	dl1.remove(0);
	assert(!dl1.find(0));
	assert(dl1.find(1));
	assert(!dl1.find(2));
	}
	// }}}

	// {{{ DLList, remove() with duplicates
	{
	DLList<int> dl1;

	for (int i = 0; i < 5; i++) {
		dl1.insert(i);
		dl1.insert(i);
	}

	dl1.remove(0, false); // all_or_one=false
	dl1.remove(1, false);
	dl1.remove(2, false);

	assert(dl1.find(0));
	assert(dl1.find(1));
	assert(dl1.find(2));
	assert(dl1.find(3));
	assert(dl1.find(4));
	}
	// }}}

	// {{{ DLList, remove() with duplicates, all_or_one=true
	{
	DLList<int> dl1;

	for (int i = 0; i < 5; i++) {
		dl1.insert(i);
		dl1.insert(i);
	}

	dl1.remove(0, true); // all_or_one=true
	dl1.remove(1, true);
	dl1.remove(2, true);

	assert(!dl1.find(1));
	assert(!dl1.find(2));
	assert(!dl1.find(0));
	assert(dl1.find(3));
	assert(dl1.find(4));
	}
	// }}}

	// {{{ DLList, process
	{
		DLList<int> dl1;

		total = 0;

		dl1.insert(1);
		dl1.insert(2);
		dl1.insert(3);

		dl1.process(_sum);

		assert(6 == total);
	}
	// }}}

	// {{{ DLList, BoolThing
	{
		DLList<BoolThing> dl;
		assert(0 == dl.getNodeCount());

		dl.pushFront(true);

		assert(1 == dl.getNodeCount());
	}
	// }}}

	// {{{ DLList, IntegerThing comparison
	{
	DLNode<IntegerThing> a(1);
	DLNode<IntegerThing> b(3);

	assert(0 <= (a.getData()).getValue());
	assert(2 >= (a.getData()).getValue());

	//assert(1 == dl.getNodeCount());
	}
	// }}}

	// {{{ memory leak test [DISABLED]
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

	// {{{ memory leak test, IntegerThing [DISABLED]
	// 4/29/2011 tested OK
	/*
	{
		DLList<IntegerThing> dl1;

		while (1) {
			DLList<IntegerThing> dl2;

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
