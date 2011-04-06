
#include <vector>

/**
 * A Queue is a container providing FIFO (first in first out) operation.
 *
 * This particular Queue implementation inherits from the standard class 'vector'
 * so all of those operations are available in addition to the additional
 * ones defined here.
 */
template<class T>
class Queue : public std::vector<T> {
private:

public:

	// {{{ Queue() constructor
	/**
	 * Construct an empty Queue object.
	 */
	Queue()
		:std::vector<T>()
	{}
	// }}}

	// {{{ pop_front()
	/**
	 * Remove the element at the FRONT of the queue.
	 */
	void pop_front()
	{
		if (this->size() <= 0)
			return;

		this->erase(this->begin());
	}
	// }}}

	// {{{ to_front
	/**
	 * Move an element to the front of the queue.
	 *
	 * @arg iterator of position to move
	 */
	void to_front(typename Queue<T>::iterator from)
	{
		T x = *from;
		this->erase(from);
		this->insert(this->begin(), x);
	}
	// }}}
};

// vim:foldmethod=marker
