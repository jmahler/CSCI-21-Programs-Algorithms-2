
/**
 * Test file for the BSTree.h and BSTNode.h files.
 *
 * To use this simply compile it and run it.
 * If all the tests passed it will display "All tests passed"
 * otherwise it will indicate where an error occured.
 */

#include <cassert>
#include <iostream>

#include "BSTNode.h"
#include "BSTree.h"

using namespace std;

// Both of these functions assign a value,
// but only the one that is passed by reference
// will actually mutate the value.
void fn_by_val(int someInt) { someInt = 1; }
void fn_by_ref(int& someInt) { someInt = 1; }

int main() {

	// {{{ BSTNode, ref, val
	{
	BSTNode<int> n1(10);
	assert(10 == n1.getData());
	fn_by_val(n1.getData());
	assert(10 == n1.getData());
	fn_by_ref(n1.getData());
	assert(1 == n1.getData());
	}
	// }}}

	// {{{ BSTNode
	{
	BSTNode<int> bst1(10);

	assert(NULL == bst1.getLeft());
	assert(NULL == bst1.getRight());
	}
	// }}}

	// {{{ BSTree
	{
	BSTree<int> bst1;

	assert(0 == bst1.getNodeCount());

	bst1.insert(12);
	bst1.insert(14);
	bst1.insert(1);
	bst1.insert(13);
	bst1.insert(-4);
	bst1.insert(20);

	bst1.print();
	// The values were inserted out of order
	// but they should be printed in order.
	//cout << bst1.print();  // debug

	assert(6 == bst1.getNodeCount());
	}
	// }}}

	// {{{ BSTree, clear()
	{
	BSTree<int> bst1;

	for (int i = 0; i < 100; i++) {
		assert(0 == bst1.getNodeCount());

		bst1.insert(12);
		bst1.insert(14);
		bst1.insert(1);
		bst1.insert(13);
		bst1.insert(-4);
		bst1.insert(20);

		assert(6 == bst1.getNodeCount());

		bst1.clear();
		assert(0 == bst1.getNodeCount());
	}

	}
	// }}}

	// {{{ BSTree, find()
	{
	BSTree<int> bst1;

	bst1.insert(12);
	bst1.insert(14);
	bst1.insert(1);
	bst1.insert(13);
	bst1.insert(-4);
	bst1.insert(20);

	assert(! bst1.find(666));
	assert(! bst1.find(-3));
	assert(bst1.find(-4));
	assert(bst1.find(1));
	assert(! bst1.find(2));
	assert(! bst1.find(3));
	assert(! bst1.find(4));
	assert(! bst1.find(11));
	assert(bst1.find(12));
	assert(bst1.find(13));
	assert(bst1.find(14));
	assert(! bst1.find(19));
	assert(bst1.find(20));
	assert(! bst1.find(21));

	}
	// }}}

	// {{{ BSTree, remove()
	{
	BSTree<int> bst1;

	bst1.insert(12);
	bst1.insert(14);
	bst1.insert(1);
	bst1.insert(13);
	bst1.insert(-4);
	bst1.insert(20);

	/* 
	 * Remove each item one by one and make sure
	 * everything is correct at each step.
	 */
	assert(6 == bst1.getNodeCount());

	// try to remove a non-existent node
	assert(! bst1.remove(666));

	assert(bst1.remove(-4));
	assert(5 == bst1.getNodeCount());
	assert(! bst1.find(-4));
	assert(bst1.find(1));
	assert(bst1.find(12));
	assert(bst1.find(14));
	assert(bst1.find(13));
	assert(bst1.find(20));

	assert(bst1.remove(1));
	assert(4 == bst1.getNodeCount());
	assert(! bst1.find(-4));
	assert(! bst1.find(1));
	assert(bst1.find(12));
	assert(bst1.find(14));
	assert(bst1.find(13));
	assert(bst1.find(20));

	assert(bst1.remove(20));
	assert(3 == bst1.getNodeCount());
	assert(! bst1.find(-4));
	assert(! bst1.find(1));
	assert(bst1.find(12));
	assert(bst1.find(14));
	assert(bst1.find(13));
	assert(! bst1.find(20));

	assert(bst1.remove(13));
	assert(2 == bst1.getNodeCount());
	assert(! bst1.find(-4));
	assert(! bst1.find(1));
	assert(bst1.find(12));
	assert(bst1.find(14));
	assert(! bst1.find(13));
	assert(! bst1.find(20));

	assert(bst1.remove(14));
	assert(1 == bst1.getNodeCount());
	assert(! bst1.find(-4));
	assert(! bst1.find(1));
	assert(bst1.find(12));
	assert(! bst1.find(14));
	assert(! bst1.find(13));
	assert(! bst1.find(20));

	assert(bst1.remove(12));
	assert(0 == bst1.getNodeCount());
	assert(! bst1.find(-4));
	assert(! bst1.find(1));
	assert(! bst1.find(12));
	assert(! bst1.find(14));
	assert(! bst1.find(13));
	assert(! bst1.find(20));

	// everything should fail on an empty list
	assert(! bst1.remove(12));
	assert(! bst1.remove(13));
	assert(! bst1.remove(14));
	assert(! bst1.remove(-10));
	assert(! bst1.find(12));
	assert(! bst1.find(13));
	assert(! bst1.find(14));
	assert(! bst1.find(-10));
	assert(! bst1.find(3));

	}
	// }}}

	// {{{ BSTree, remove()
	{
	BSTree<int> bst1;

	/* Set up the following tree then
	 * try and remove 3 (a doubly connected node).
	 *
	 *        5
	 *      /   \
	 *     3    10
	 *    / \
	 *   2   4
	 */
	bst1.insert(5);
	bst1.insert(3);
	bst1.insert(10);
	bst1.insert(2);
	bst1.insert(4);

	assert(bst1.find(2));
	assert(bst1.find(3));
	assert(bst1.find(4));

	assert(bst1.remove(3));
	assert(4 == bst1.getNodeCount());

	assert(! bst1.find(3));
	assert(bst1.find(2));
	assert(bst1.find(4));
	}
	// }}}

	// {{{ BSTree, remove()
	{
	BSTree<int> bst1;

	/* Set up the following tree then
	 * try and remove 3 (a doubly connected node).
	 *
	 *        5
	 *      /   \
	 *     3    10
	 *    / \
	 *   2   4
	 */
	bst1.insert(5);
	bst1.insert(3);
	bst1.insert(10);
	bst1.insert(2);
	bst1.insert(4);

	assert(bst1.remove(5));

	assert(bst1.find(2));
	assert(bst1.find(3));
	assert(bst1.find(4));
	assert(! bst1.find(5));
	assert(bst1.find(10));
	}
	// }}}

	// {{{ BSTree, remove()
	// A good way to test this program for memory leaks is
	// to uncomment this section and then run this program
	// while monitoring memory usage using the 'top' command.
	//
	// tested OK: 5/5/2011
	{
	BSTree<int> bst1;
		/*
		 *    4
		 *     \
		 *      6
		 */
		bst1.insert(4);
		bst1.insert(6);

		assert(bst1.find(4));
		assert(bst1.find(6));

		assert(bst1.remove(4));
		assert(! bst1.find(4));
		assert(bst1.find(6));

	}
	// }}}

	// {{{ BSTree, remove()
	// test for bug found by Boyd
	{
	BSTree<int> bst1;

	bst1.insert(50);
	bst1.insert(25);
	bst1.insert(75);
	bst1.insert(60);
	bst1.insert(80);
	bst1.insert(65);

	assert(6 == bst1.getNodeCount());

	assert(bst1.remove(60));
	assert(bst1.remove(75));

	assert(4 == bst1.getNodeCount());

	// the value 50 should be missing if the bug is present
	assert(bst1.find(50));

	assert(! bst1.find(60));
	assert(! bst1.find(75));

	assert(4 == bst1.getNodeCount());
	}
	// }}}

	// {{{ BSTree, getData()
	{
	BSTree<int> bst1;

	bst1.insert(12);
	bst1.insert(14);
	bst1.insert(1);
	bst1.insert(13);
	bst1.insert(-4);
	bst1.insert(20);

	assert(NULL == bst1.getData(666));
	assert(NULL == bst1.getData(-3));
	assert(-4 == *(bst1.getData(-4)));
	assert(1 == *(bst1.getData(1)));
	assert(NULL == bst1.getData(2));
	assert(12 == *(bst1.getData(12)));
	assert(13 == *(bst1.getData(13)));
	assert(14 == *(bst1.getData(14)));
	assert(20 == *(bst1.getData(20)));
	assert(NULL == bst1.getData(21));

	}
	// }}}

	// {{{ BSTree, print(), printr()
	{
	BSTree<int> bst1;

	bst1.insert(12);
	bst1.insert(14);
	bst1.insert(1);
	bst1.insert(13);
	bst1.insert(-4);
	bst1.insert(20);

	// in order traversal
	bst1.print();

	// reverse order traversal
	bst1.printr();
	//cout << bst1.printr() << endl;

	bst1.printp();
	//cout << bst1.printp() << endl;

	bst1.printe();
	//cout << bst1.printe() << endl;

	}
	// }}}

	// {{{ BSTree, min(), max()
	{
	BSTree<int> bst1;
		/*
		 *      5
		 *     /  \
		 *    3    6
		 *     \
		 *      4
		 */
		bst1.insert(5);
		bst1.insert(6);
		bst1.insert(3);
		bst1.insert(4);

		assert(3 == bst1.min());
		assert(6 == bst1.max());
	}
	// }}}

	// {{{ BSTree, memeory leak test [DISABLED]
	// A good way to test this program for memory leaks is
	// to uncomment this section and then run this program
	// while monitoring memory usage using the 'top' command.
	//
	// tested OK: 5/6/2011
	{
	BSTree<int> bst1;

	/*
	 *     3
	 *    / 
	 *   1   
	 *    \
	 *     2
	 */
	bst1.insert(3);
	bst1.insert(1);
	bst1.insert(2);

	//while (1) {
	//for (int i = 0; i < 100; i++) {

	/*
	 *      3
	 *     /  \
	 *    /    \
	 *   1      7
	 *    \    / \
	 *     2  5   8
	 *     ...
	 */

		bst1.insert(7);
		bst1.insert(5);
		bst1.insert(8);
		bst1.insert(4);
		bst1.insert(6);

		assert(8 == bst1.getNodeCount());

		assert(bst1.find(6));

		assert(bst1.remove(7));

		assert(bst1.find(1));
		assert(bst1.find(2));
		assert(bst1.find(3));
		assert(bst1.find(4));
		assert(bst1.find(5));
		assert(bst1.find(6));
		assert(! bst1.find(7));
		assert(bst1.find(8));

		assert(bst1.remove(2));

		assert(bst1.find(1));
		assert(! bst1.find(2));
		assert(bst1.find(3));
		assert(bst1.find(4));
		assert(bst1.find(5));
		assert(bst1.find(6));
		assert(! bst1.find(7));
		assert(bst1.find(8));

		assert(bst1.remove(3));

		assert(bst1.find(1));
		assert(! bst1.find(2));
		assert(! bst1.find(3));
		assert(bst1.find(4));
		assert(bst1.find(5));
		assert(bst1.find(6));
		assert(! bst1.find(7));
		assert(bst1.find(8));

		assert(bst1.remove(5));

		assert(bst1.find(1));
		assert(! bst1.find(2));
		assert(! bst1.find(3));
		assert(bst1.find(4));
		assert(! bst1.find(5));
		assert(bst1.find(6));
		assert(! bst1.find(7));
		assert(bst1.find(8));

		assert(bst1.remove(4));

		assert(bst1.find(1));
		assert(! bst1.find(2));
		assert(! bst1.find(3));
		assert(! bst1.find(4));
		assert(! bst1.find(5));
		assert(bst1.find(6));
		assert(! bst1.find(7));
		assert(bst1.find(8));

		assert(bst1.remove(6));
		assert(bst1.remove(8));

		assert(1 == bst1.getNodeCount());

		bst1.insert(2);
		bst1.insert(3);

	//}

	}
	// }}}

	cout << "All tests passed.\n";

	return 0; // OK
}
