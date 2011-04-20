#pragma once

#include "DLNode.h"
#include <cstdlib>  // NULL

using namespace std;

/**
 * DLList
 *
 * A doubly-linked list.  Uses DLNode.
 */
template <class T>
class DLList
{
public:

	// {{{ DLList()
	/**
	 * Construct a new doubly-linked list.
	 */
	DLList() {
		nodeCount = 0;
		head = NULL;
		tail = NULL;
	}
	// }}}

	// {{{ ~DLList()
	~DLList() {
		//clear();
		clearRecursive();
	}
	// }}}

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

			tail = newNode;
		}

		nodeCount++;
	}
	// }}}

	// {{{ popFront()
	/**
	 * Remove (pop) the element from the front list.
	 */
	void popFront() {
		if (0 == nodeCount)
			return;

		DLNode<T>* newHead;

		newHead = head->getNext();
		if (NULL == newHead) {
			// only 1 item in list

			delete head;
			//delete tail;
			// When there is only one item the head and the tail
			// are the same.
			// Don't delete them twice!

			head = tail = NULL;

			nodeCount = 0;
		} else {
			// more than 1 item in list

			newHead->setPrevious(NULL);

			delete head;  // old head

			head = newHead;
		}
	}
	// }}}

	// {{{ popBack()
	/**
	 * Remove (pop) the element from the back of the list.
	 */
	void popBack() {
		// list is empty
		//if (NULL == head || NULL == tail)
		if (0 == nodeCount)
			return;

		DLNode<T>* newTail;

		newTail = tail->getPrevious();
		if (NULL == newTail) {
			// only 1 item in list

			delete head;
			//delete tail;
			// When there is only one item the head and the tail
			// are the same.
			// Don't delete them twice!

			head = tail = NULL;

			nodeCount = 0;
		} else {
			// more than 1 item in list

			newTail->setNext(NULL);

			delete tail;  // old head

			tail = newTail;

			nodeCount--;
		}
	}
	// }}}

	void insert(T); // TODO
	bool remove(T); // TODO

	// {{{ find(T)
	/**
	 * Find whether a data value is present.
	 *
	 * @returns true if yes, false otherwise
	 */
	bool find(T testData) {

		DLNode<T>* cur = head;

		while (cur) {
			if (cur->getData() == testData)
				return true;

			cur = cur->getNext();
		}

		return false;
	}
	// }}}

	// {{{ findRecursive(T)
	/**
	 * Find whether a data value is present (recursively).
	 *
	 * @returns true if yes, false otherwise
	 */
	bool findRecursive(T testData) {
		return _findRecursive(testData, head);
	}

private:
	bool _findRecursive(T &testData, DLNode<T>* dln) {

		if (NULL == dln)
			return false;

		if (dln->getData() == testData)
			return true;

		return _findRecursive(testData, dln->getNext());
	}

public:
	// }}}

	//friend ostream& operator<<(ostream&, const DLList<T>&); // TODO

	// {{{ clear()
	/*
	 * Clear out all elements in the list.
	 *
	 * Normally this would only be used by the destructor.
	 */
	void clear() {
		DLNode<T>* cur;
		DLNode<T>* next;

		cur = head;

		while (cur) {
			next = cur->getNext();	
			delete cur;
			cur = next;
		}

		head = tail = NULL;

		nodeCount = 0;
	}
	// }}}

	// {{{ clear(Recursive)
	/*
	 * Clear out all elements in the list.
	 *
	 * Normally this would only be used by the destructor.
	 */
	void clearRecursive() {
		_clearRecursive(head);
		head = tail = NULL;
		nodeCount = 0;
	}

private:
	void _clearRecursive(DLNode<T>*& dln) {
		if (NULL == dln) {
			// reached the end
		} else {
			_clearRecursive(dln->getNext());
			delete dln;
		}
	}
	// }}}

private:
	unsigned int nodeCount;
	DLNode<T>* head;
	DLNode<T>* tail;

};

