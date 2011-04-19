#pragma once

/**
 * DLList
 *
 * A doubly-linked list.  Uses DLNode.
 */
#include "DLNode.h"
#include <cstdlib>

using namespace std;

template <class T>
class DLList
{
public:

	DLList() {
		nodeCount = 0;
		head = NULL;
		tail = NULL;
	}
	~DLList();

	// {{{ getNodeCount()
	/**
	 * Get the number of nodes currently stored.
	 *
	 * @return node count
	 */
	unsigned int getNodeCount() {
		return nodeCount;
	}
	// }}}

	// {{{ pushFront()
	/**
	 * Add data to the front of the list.
	 *
	 * @arg new data
	 */
	void pushFront(T newData) {
		DLNode<T>* newNode = new DLNode<T>(newData);

		//if (NULL == head && NULL == tail) {
		if (0 == nodeCount) {
			head = newNode;
			tail = newNode;
		} else {
			head->setPrevious(newNode);
			newNode->setNext(head);

			head = newNode;
		}

		nodeCount++;
	}
	// }}}

	// {{{ pushBack()
	/**
	 * Add data to the back of the list.
	 *
	 * @arg new data
	 */
	void pushBack(T newData) {
		DLNode<T>* newNode = new DLNode<T>(newData);

		//if (NULL == head && NULL == tail) {
		if (0 == nodeCount) {
			head = newNode;
			tail = newNode;
		} else {
			tail->setNext(newNode);
			newNode->setPrevious(tail);

			head = newNode;
		}

		nodeCount++;
	}
	// }}}

private:
	unsigned int nodeCount;
	DLNode<T>* head;
	DLNode<T>* tail;

	void clear();
	void clearRecursive();
};

