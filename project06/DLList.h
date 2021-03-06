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
private:
	unsigned int nodeCount;
	DLNode<T>* head;
	DLNode<T>* tail;

public:

// {{{ operator<<
/**
 * Output operator.
 */
template <class _T>
friend ostream& operator<<(ostream& out, const DLList<_T>& dll);
// }}}

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

	// {{{ insert(T)
private:
	// The first node must never be NULL !
	void _insert(T newData, DLNode<T>*& dln, DLNode<T>*& newNode) {

		DLNode<T>* nextNode = dln->getNext();

		// insert here
		if (NULL == nextNode) {
			// at tail

			newNode->setPrevious(dln);
			dln->setNext(newNode);

			tail = newNode;
		} else if (newData >= dln->getData() && newData <= nextNode->getData()) {
			// between two defined nodes

			newNode->setPrevious(dln);
			newNode->setNext(nextNode);

			dln->setNext(newNode);
			nextNode->setPrevious(newNode);
		} else {
			_insert(newData, dln->getNext(), newNode);
		}
	}

public:
	/**
	 * Insert data in to the list in ascending order.
	 * 
	 * @arg data
	 *
	 * If the the list is unsorted its behaviour is undefined.
	 * Comparison operators for the data type must be defined.
	 */
	void insert(T newData) {

		DLNode<T>* newNode = new DLNode<T>(newData);

		if (0 == nodeCount) {
			head = tail = newNode;
		} else if (newNode->getData() <= head->getData()) {
			// at beginning

			newNode->setNext(head);
			head->setPrevious(newNode);

			head = newNode;
		} else {
			// somewhere between head and tail
			_insert(newData, head, newNode);
		}

		nodeCount++;
	}
	// }}}

	// {{{ remove(T)
	/**
	 * Remove a data element from the list.
	 *
	 * @arg data to be removed
	 * @arg if there are duplicates, remove all or one
	 */
	void remove(T testData, bool all_or_one=true) {
		DLNode<T>* cur;

		cur = head;

		while (cur) {
			if (testData == cur->getData()) {
				// remove this element

				DLNode<T>* nextNode = cur->getNext();
				DLNode<T>* previousNode = cur->getPrevious();

				if (nextNode != NULL)
					nextNode->setPrevious(previousNode);

				if (previousNode != NULL)
					previousNode->setNext(nextNode);

				if (cur == head)
					head = nextNode;

				delete cur;

				nodeCount--;
				if (0 == nodeCount)
					head = tail = NULL;

				if (!all_or_one)
					break;
			}

			cur = cur->getNext();
		}
	}
	// }}}

	// {{{ process
	/**
	 * Process the list by performing a function on every
	 * data item in the list.  The function will be called
	 * with a single value, the data value of the element.
	 *
	 * @arg pointer to function
	 */
	void process(void (*fn)(T)) {
		DLNode<T>* cur;

		cur = head;

		while (cur) {

			(*fn)(cur->getData());

			cur = cur->getNext();
		}
	}
	// }}}

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

private:
	bool _findRecursive(T &testData, DLNode<T>* dln) {

		if (NULL == dln)
			return false;

		if (dln->getData() == testData)
			return true;

		return _findRecursive(testData, dln->getNext());
	}

public:
	/**
	 * Find whether a data value is present (recursively).
	 *
	 * @returns true if yes, false otherwise
	 */
	bool findRecursive(T testData) {
		return _findRecursive(testData, head);
	}
	// }}}

	// {{{ clear()
	/**
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

	// {{{ clearRecursive()
private:
	void _clearRecursive(DLNode<T>*& dln) {
		if (NULL != dln) {
			_clearRecursive(dln->getNext());
			delete dln;
		}
	}

public:
	/**
	 * Clear out all elements in the list.
	 *
	 * Normally this would only be used by the destructor.
	 */
	void clearRecursive() {
		_clearRecursive(head);
		head = tail = NULL;
		nodeCount = 0;
	}
	// }}}

};

// {{{ operator<<
/**
 * Output operator.
 */
template<class T>
ostream& operator<<(ostream& out, const DLList<T>& dll)
{
	int n = 0;
	DLNode<T>* cur = dll.head;

	out << "( ";
	while (cur) {
		n++;

		// wrap every 10 elements
		if (0 == (n % 10))
			out << endl << "  ";

		out << cur->getData() << " ";

		cur = cur->getNext();
	}
	out << ")";
	return out;
}
// }}}

// vim:foldmethod=marker
