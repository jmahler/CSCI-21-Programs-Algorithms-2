
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
	cout << bst1.print();  // debug

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

	cout << "All tests passed.\n";

	return 0; // OK
}
