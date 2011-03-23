
#include <iostream>
#include <string>

using namespace std;

/**
 * InvalidIndexError is thrown by some functions when an invalid
 * index is requested.
 */
struct InvalidIndexError {};

/**
 *
 * JArray provides a simple dynamic array with sorting functions
 * and a utility to test it using commands from a file.
 *
 * <h2>Synopsis</h2>
 *
 * @code
 *  #include "JArray.h";
 *
 *  JArray<int> a(5, true);  // (capacity, autosize)
 *  int val, index;
 *  int err;
 *  string str;
 *  bool errp;
 *
 *  errp = a.get(index, val);
 *
 *  try {
 *      val a.get(index);
 *  } catch (InvalidIndexError err) {
 *		// error!
 *  }
 *
 *  err = a.insert(val, index);
 *  err = a.replace(val, index);
 *
 *  err = a.remove(index);
 *
 *  err = a.push(val);
 *  err = a.pop();
 *
 *  val = a.capacity();
 *  val = a.size();
 *
 *  // Insertion Sort
 *  a.isort(true);   // ascending
 *  a.isort(false);  // descending
 *
 *  // Bubble Sort
 *  a.bsort(true);
 *  a.bsort(false);
 *
 *  cout << a;
 *
 * @endcode
 */
template<class T>
class JArray {
private:
    T* _numbers;
    int  _capacity;     // current capacity, can vary if autosize on
    int  _elements;      // number of elements, next available position
    bool _autosize;      // allow autosizing true/false
    bool _autocollapse;  // allow autocollapsing true/false

public:

	// {{{ JArray
    /**
     * Create a new array object.
     *
     * When autosize is on the capacity of the array
     * expanded as needed to accommodate the number of elements.
     *
     * When autocollapse is on the array will be collapsed as needed.
     */
	JArray(int capacity=5, bool autosize=false, bool autocollapse=false)
	{
		if (capacity < 0)
			_capacity = 0;
		else
			_capacity = capacity;

		_autosize = autosize;
		_autocollapse = autocollapse;

		_elements = 0;

		_numbers = new T[_capacity];
	}
	// }}}

    ~JArray() { delete[] _numbers; };

	// {{{ get(index, &val)
    /**
     * Retrieves the element at the given index
     * and assigns to the reference val.
     *
     * @returns true on success, false on error
     */
	bool get(const int index, T& val)
	{
		if (index >= 0 && index < _elements) {
			val = _numbers[index];
			return true;  // OK
		}

		return false; // error: invalid index
	}
	// }}}

	// {{{ get(index)
    /**
     * Retrieves the element at the given index.
     *
     * @returns value on success, throws InvalidIndexError on error
	 *
	 * @exception InvalidIndexError
     */
	T get(const int index)
	{
		if (index >= 0 && index < _elements) {
			return _numbers[index];
		}

		throw InvalidIndexError();
	}
	// }}}

	// {{{ insert
    /**
     * Inserts a value at the given index (0 offset).
     *
     * @returns -1 on error
     *
     * All the values above will be shifted to accommodate the new value.
     * If the array is full and is of fixed size (autosize = false)
     * the value at the end will be discarded.
     * A value cannot be inserted at a position greater than 1 beyond
     * the last most element (no gaps).
     *
     * See also replace() and push().
     */
	int insert(const T val, const int index)
	{
		// Assuming we could autosize if needed (will be checked later)
		//  is the requested index valid?
		if (index >= 0 && index <= _elements) {
			// probably OK, autosize will be checked later
		} else {
			return -1;  // error: invalid index
		}

		// Autosize if necessary and possible
		if (_elements == _capacity) { // were out of room
			if (_autosize) {
				// make some room
				int new_capacity = (_capacity > 0) ? _capacity*2 : 2;

				T* new_numbers = new T[new_capacity];
				_capacity = new_capacity;

				for (int i = 0; i < _elements; i++) {
					new_numbers[i] = _numbers[i];
				}

				delete[] _numbers;

				_numbers = new_numbers;
			} else {
				return -1;  // error: no more room
			}
		}

		// we could not make any room
		if (index >= _capacity)
			return -1;  // error

		// The end is different depending on whether we have
		// room or if elements are being discarded.
		int end;
		if (_capacity > _elements) {
			// no elements will be discarded
			end = _elements;
			_elements++;
		} else {
			// an element will be discarded (over written)
			end = _capacity - 1;
		}

		// shift all previous elements
		for (int j = end; j > index; j--)
			_numbers[j] = _numbers[j-1];

		// finally assign the val
		_numbers[index] = val;

		return 0; // OK
	}
	// }}}

	// {{{ remove
    /**
     * Remove the element at the given index (0 offset).
     *
     * @returns -1 on error
     */
	int remove(const int index)
	{
		if (index >= 0 && index < _elements) {
			// OK, valid index
		} else {
			return -1;  // error
		}

		for (int j = index; j < _elements; j++)
			_numbers[j] = _numbers[j+1];

		_elements--;

		/* When there is atleast one elment and the capacity is twice as
		 * large as the number of elements it will be collapsed to the
		 * number of elements.
		 */
		if (_autocollapse && (_elements > 0) && 0 == (_capacity % _elements*2)) {
			T* new_numbers = new T[_elements];
			_capacity = _elements;

			for (int i = 0; i < _elements; i++) {
				new_numbers[i] = _numbers[i];
			}

			delete[] _numbers;

			_numbers = new_numbers;
		}

    	return 0; // OK
	}
	// }}}

	// {{{ replace
    /**
     *
     * Replace the value at the given index with the specified value.
	 *
     * @returns -1 on error
	 *
	 * It will not expand the array create new elements it can only
	 * replace already present elements.
	 * See insert() if you want to add elements.
     */
	int replace(const T val, const int index)
	{
		if (index >= 0 && index < _elements)
			_numbers[index] = val;
		else
			return -1;  // error

		return 0; // OK
	}
	// }}}

	// {{{ push
    /**
     * Inserts a value in the next available slot.
     * See also (insert()).
     *
     * @returns -1 on error
     */
	int push(const T val)
	{
    	return insert(val, _elements);
	}
	// }}}

	// {{{ pop
    /**
     * Removes the value at the last slot.
     *
     * @returns -1 on error
     */
	int pop()
	{
		return remove((_elements - 1));
	}
	// }}}

	// {{{ capacity
    /**
     * @returns the capacity of the array
     *
     * The capacity is the maximum number of elements that can
     * be stored in this array.
     *
     * If the array has autosize enabled the capacity will be automatically
     * expanded as needed.
     */
    int capacity() { return _capacity; };
	// }}}

	// {{{ size
    /**
     * @returns number of elements in array
     */
    int size() { return _elements; };
	// }}}

	// {{{ bsort
    /**
     * Performs a Bubble Sort of the array.
	 *
	 * @arg sort ascending (true) else descending(false)
     */
	void bsort(const bool asc_else_desc=true)
	{
		bool swapped;
		int i, key, length;
		length = _elements;

		do {
			swapped = false;
			for (i = 1; i < length; i++) {
				key = _numbers[i];
				if (asc_else_desc ? (_numbers[i-1] > key) : (_numbers[i-1] < key)) {
					_numbers[i] = _numbers[i-1];
					_numbers[i-1] = key;
					swapped = true;
				}
			}
		} while (swapped);
	}
	// }}}

	// {{{ isort
    /**
     * Performs an Insertion Sort of the array.
	 *
	 * @arg sort ascending (true) else descending(false)
     */
	void isort(const bool asc_else_desc=true)
	{
		int i, j, key, length;
		length = _elements;

		for (i = 1; i < length; i++) {
			key = _numbers[i];
			for (j = i-1; j >= 0; j--) {
				if (asc_else_desc ? (_numbers[j] < key) : (_numbers[j] > key))
					break;

				_numbers[j+1] = _numbers[j];
			}
			_numbers[j+1] = key;
		}
	}
	// }}}

	// {{{ operator<<(JArray<T>)
	/**
	 * Output operator for JArray<T> object.
	 */
	friend ostream& operator<<(ostream& out, const JArray<T>& ja) {
		static const int chunk = 10;  // number of values per line

		out << ja._elements << "/" << ja._capacity << endl;

		//out << " ["; // start of array
		for (int i = 0; i < ja._elements; i++) {

			//out << " " << numbers[i];
			out << ja._numbers[i];

			// for all but the last element
			if (i != (ja._elements - 1))
				//out << ",";
				out << ", ";

			// every chunk'th except at the begining or end
			if ((i + 1) != 0 && 0 == ((i + 1) % chunk) && i != (ja._elements - 1)) {
				out << endl;
				//out << "  "; // indent the next line
			}
		}
		//out << " ]"; // end of array

		return out;
	}
	// }}}

};


// vim:foldmethod=marker
