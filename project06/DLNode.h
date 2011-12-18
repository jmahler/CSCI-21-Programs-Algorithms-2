#pragma once

#include <cstdlib>  // NULL

/**
 * DLNode
 *
 * Represents a node in a doubly-linked list.
 */
template<class T>
class DLNode
{
private:

	T* data;
	DLNode* next;
	DLNode* previous;

	// {{{ DLNode()  (default constructor)
	/*
	 * The default constructor should never be used because
	 * the value would be undefined.
	 */
	DLNode() { }
	// }}}

public:

	// {{{ DLNode(T data)  (constructor)
	/**
	 * Construct a new DLNode.
	 *
	 * @arg initial value
	 */
	DLNode(const T &newData) {
		data = new T(newData);
		next = NULL;
		previous = NULL;
	}
	// }}}

	// {{{ ~DLNode()  (destructor)
	~DLNode() {
		delete data;
	}
	// }}}

	// {{{ setData()
	/**
	 * Set the data currently stored.
	 */
	void setData(const T &newData) {
		*data = newData;
	}
	// }}}

	// {{{ getData()
	/**
	 * Get the data currently stored.
	 *
	 * @return data stored
	 */
	T getData() const {
		return (*data);
	}
	// }}}

	// {{{ setNext(DLNode*)
	/**
	 * Assign the next node.
	 *
	 * @arg new next node
	 */
	void setNext(DLNode* newNext) {
		next = newNext;
	}
	// }}}

	// {{{ setPrevious(DLNode*)
	/**
	 * Assign the previous node.
	 *
	 * @arg new previous node
	 */
	void setPrevious(DLNode* newPrevious) {
		previous = newPrevious;
	}
	// }}}

	// {{{ getNext() const
	/**
	 * Get the next node.
	 *
	 * @return next node
	 */
	DLNode* getNext() const {
		return next;
	}
	// }}}

	// {{{ getNext()
	/**
	 * Get the next node.
	 *
	 * @return next node
	 */
	DLNode*& getNext() {
		return next;
	}
	// }}}

	// {{{ getPrevious()
	/**
	 * Get the previous node.
	 *
	 * @return previous node
	 */
	DLNode* getPrevious() {
		return previous;
	}
	// }}}

};

// vim:foldmethod=marker
