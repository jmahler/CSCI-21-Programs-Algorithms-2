
#include <iostream>
#include <string>

using namespace std;

/**
 * InvalidIndexError may be thrown when an invalid index is requested.
 */
struct InvalidIndexError {};

/**
 *
 * JArray provides a simple dynamic array with sorting functions.
 *
 * In general the API tries to be similar to that for vectors in the
 * standard library although it does not support iterators.
 *
 * <h2>Synopsis</h2>
 *
 * @code
 *  #include "JArray.h";
 *
 *  JArray<int> a(5, true);  // (capacity, autosize)
 *  int val, index;
 *  int err;
 *  bool errp;
 *
 *  errp = a.get(index, val);
 *
 *  try {
 *      val = a.at(index);
 *  } catch (InvalidIndexError err) {
 *      // error!
 *  }
 *
 *  err = a.insert(index, val);
 *  err = a.replace(index, val);
 *  err = a.erase(index);
 *  a.clear();
 *
 *  err = a.push_back(val);
 *  a.pop_back();
 *
 *  val = a.capacity();
 *  val = a.size();

 *  if (a.empty()) {
 *      // it IS empty
 *  }
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
    T*   _numbers;
    int  _capacity;     // current capacity, can vary if autosize on
    int  _elements;      // number of elements, next available position
    bool _autosize;      // allow autosizing true/false

public:

	// {{{ JArray
    /**
     * Create a new array object.
     *
     * When autosize is on (true) the capacity of the array
     * will be expanded as needed to accommodate the number of elements.
	 * When off (false) the array will have a fixed maximum capacity.
     *
     */
	JArray(int capacity=5, bool autosize=false)
	{
		if (capacity < 0)
			_capacity = 0;
		else
			_capacity = capacity;

		_autosize = autosize;

		_elements = 0;

		_numbers = new T[_capacity];
	}
	// }}}

    ~JArray() { delete[] _numbers; };

	// {{{ get(index, &val)
    /**
     * Retrieves the element at the given index
     * and assigns it to the reference val.
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

	// {{{ at(index)
    /**
     * Retrieves the element at the given index.
     *
     * @returns value on success, throws InvalidIndexError on error
	 *
	 * @exception InvalidIndexError
     */
	T at(const int index)
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
     * A value cannot be inserted at a position greater than one beyond
     * the last most element (no gaps).
     *
     * See also replace() and push_back().
     */
	int insert(const int index, const T val)
	{
		// If we assume we could autosize if needed (will be checked later)
		// is the requested index valid?
		if (index >= 0 && index <= _elements) {
			// probably OK, autosize will be checked later
		} else {
			return -1;  // error: invalid index
		}

		// Autosize if necessary and possible
		if (_elements == _capacity) { // were out of room
			if (_autosize) {
				int new_capacity = (_capacity > 0) ? _capacity*2 : 2;

				T* new_numbers = new T[new_capacity];

				for (int i = 0; i < _elements; i++) {
					new_numbers[i] = _numbers[i];
				}

				delete[] _numbers;

				_capacity = new_capacity;
				_numbers = new_numbers;
			} else {
				return -1;  // error: can't make more room
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

	// {{{ erase
    /**
     * Remove the element at the given index (0 offset).
     *
     * @returns 0 on success, -1 on error (invalid index)
     */
	int erase(const int index)
	{
		if (index >= 0 && index < _elements) {
			// OK, valid index
		} else {
			return -1;  // error
		}

		for (int j = index; j < _elements; j++)
			_numbers[j] = _numbers[j+1];

		_elements--;

    	return 0; // OK
	}
	// }}}

	// {{{ replace
    /**
     * Replace the value at the given index with the specified value.
	 *
     * @returns 0 on success, -1 on error
	 *
	 * It will not expand the array, it can only replace
	 * elements that are already present.
	 * See insert() if you want to add elements.
     */
	int replace(const int index, const T val)
	{
		if (index >= 0 && index < _elements)
			_numbers[index] = val;
		else
			return -1;  // error

		return 0; // OK
	}
	// }}}

	// {{{ push_back
    /**
     * Adds a value to the back of the array.
	 *
     * @returns 0 on success, -1 on error
	 *
	 * If the array is of fixed size (autosize = false) it
	 * will return an error if there is no room left.
	 *
     * See also (insert()).
     */
	int push_back(const T val)
	{
    	return insert(_elements, val);
	}
	// }}}

	// {{{ pop_back
    /**
     * Removes one value from the back.
	 *
	 * If no values are left nothing is removed and no error is raised.
     */
	void pop_back()
	{
		if (_elements > 0)
			_elements--;
	}
	// }}}

	// {{{ empty
    /**
     * Tests whether the array is empty or not.
	 *
	 * @returns true if empty, false otherwise
     */
	bool empty()
	{
		if (0 == _elements)
			return true;
		// else
			return false;
	}
	// }}}

	// {{{ clear
    /**
     * Clear all values from the array.
     */
	void clear()
	{
		_elements = 0;
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
     * @returns number of elements currently stored in array
     */
    int size() { return _elements; };
	// }}}

	// {{{ bsort
    /**
     * Performs a Bubble Sort of the array.
	 *
	 * Sorts in ascending order if asc_else_desc is true, otherwise
	 * sort in descending order.
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
	 * Sorts in ascending order if asc_else_desc is true, otherwise
	 * it sorts in descending order.
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
	 *
	 * If you would like to output the object to a string see
	 * "string stream" (sstream) in the standard library.
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
