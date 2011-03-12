
#include <string>
#include <sstream>

#include <iostream>

using namespace std;

/**
 *
 * JArray provides a simple dynamic array for storing integers.
 * It includes features such as length validation and dynamic expansion
 * and collapsing.
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
 *  err = a.insert(val, index);
 *  err = a.replace(val, index);

 *  err = a.remove(index);
 *
 *  err = a.push(val);
 *  err = a.pop();
 *
 *  val = a.capacity();
 *  val = a.size();
 *
 *  str = a.describe();
 *  
 *  a.isort(true);   // ascending
 *  a.isort(false);  // descending
 *
 *  a.bsort(true);
 *  a.bsort(false);
 *
 * @endcode
 */
template<class T>
class JArray {
private:
    T* numbers;
    int  _capacity;
    // _capacity cannot be named capacity because it conflicts with capacity()
    int  elements;       // number of elements, next available position
    bool autosize;
    bool autocollapse;

	// {{{ is_valid_val
    /*
     * Is the given value valid?
     */
    bool is_valid_val(const T value) { return true; };
	// }}}

	// {{{ is_assignable_index
    /*
     * Is the requested index valid?
     * Returns true if a value could be retrieved or assigned
     *  to the given index.
     */
    bool is_assignable_index(const int index)
	{
		// negative indexs are invalid
		if (index < 0)
			return false;

		// Cant add an element beyond the last one
		// and there are no valid elements beyond the last one
		if (index > elements)
			return false;

		if (index < elements)
			return true;

		// index == elements

		if (elements == _capacity) {  // were out of room
			if (autosize) {
				// we could make room
				return true;
			} else {
				return false;
			}
		}

		// index == elments && elements < _capacity

		return true;
	}
	// }}}

	// {{{ is_gettable_index
    /*
     * Could a value be retrieved from the given index?
     *
     * @returns true if yes, false otherwise
     */
    bool is_gettable_index(const int index)
	{
    	return (index >= 0 && index < elements);
	}
	// }}}

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
	JArray(int __capacity=5, bool _autosize=false, bool _autocollapse=false)
	{
		if (__capacity < 0)
			_capacity = 0;
		else
			_capacity = __capacity;

		autosize = _autosize;
		autocollapse = _autocollapse;

		elements = 0;

		numbers = new T[_capacity];
	}
	// }}}

    ~JArray() { delete[] numbers; };

	// {{{ get
    /**
     * Retrieves the element at the given index
     * and assigns to the reference val.
     *
     * @returns true on success, false on error
     */
	bool get(const int index, T& val)
	{
		if (! is_gettable_index(index))
			return false;

		val = numbers[index];
		return true; // OK
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
		if (! is_valid_val(val))
			return -1;

		if (! is_assignable_index(index))
			return -1;

		if (elements == _capacity) { // were out of room
			if (autosize) {
				// make some room
				int new_capacity = (_capacity > 0) ? _capacity*2 : 2;

				T* new_numbers = new T[new_capacity];
				_capacity = new_capacity;

				for (int i = 0; i < elements; i++) {
					new_numbers[i] = numbers[i];
				}

				delete[] numbers;

				numbers = new_numbers;
			}
		}

		// we could'nt make any room
		if (index >= _capacity)
			return -1;

		// The end is different depending on whether we have
		// room or if elements are being discarded.
		int end;
		if (_capacity > elements) {
			end = elements;
			elements++;
		} else {
			end = _capacity - 1;
		}

		// shift all previous elements
		for (int j = end; j > index; j--)
			numbers[j] = numbers[j-1];

		numbers[index] = val;

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
		if (! is_assignable_index(index) || ! is_gettable_index(index))
			return -1;

		for (int j = index; j < elements; j++)
			numbers[j] = numbers[j+1];

		elements--;

		/* When there is atleast one elment and the capacity is twice as
		 * large as the number of elements it will be collapsed to the
		 * number of elements.
		 */
		if (autocollapse && (elements > 0) && 0 == (_capacity % elements*2)) {
			T* new_numbers = new T[elements];
			_capacity = elements;

			for (int i = 0; i < elements; i++) {
				new_numbers[i] = numbers[i];
			}

			delete[] numbers;

			numbers = new_numbers;
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
     */
	int replace(const T val, const int index)
	{
		if (! is_valid_val(val))
			return -1;

		if (! is_assignable_index(index))
			return -1;

		numbers[index] = val;

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
    	return insert(val, elements);
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
		return remove((elements - 1));
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
    int size() { return elements; };
	// }}}

	// {{{ describe
    /**
     * @returns a string describing the array
     *
     * Values included are: capacity, number of elements, and all the values.
     */
    string describe()
	{
		static const int chunk = 10;  // values per line

		stringstream ss;

		ss << elements << "/" << _capacity << endl;

		//ss << " ["; // start of array
		for (int i = 0; i < elements; i++) {

			//ss << " " << numbers[i];
			ss << numbers[i];

			// for all but the last element
			if (i != (elements - 1))
				//ss << ",";
				ss << ", ";

			// every chunk'th except at the begining or end
			if ((i + 1) != 0 && 0 == ((i + 1) % chunk) && i != (elements - 1)) {
				ss << endl;
				//ss << "  "; // indent the next line
			}
		}
		//ss << " ]"; // end of array

		return ss.str();
	}
	// }}}

	// {{{ bsort
    /**
     * Performs a bubble sort of the array.
	 *
	 * @args sort ascending (true) else descending(false)
     */
	void bsort(const bool asc_else_desc=true)
	{
		bool swapped;
		int i, key, length;
		length = elements;

		do {
			swapped = false;
			for (i = 1; i < length; i++) {
				key = numbers[i];
				if (asc_else_desc ? (numbers[i-1] > key) : (numbers[i-1] < key)) {
					numbers[i] = numbers[i-1];
					numbers[i-1] = key;
					swapped = true;
				}
			}
		} while (swapped);
	}
	// }}}

	// {{{ isort
    /**
     * Performs an insertion sort of the array.
	 *
	 * @args sort ascending (true) else descending(false)
     */
	void isort(const bool asc_else_desc=true)
	{
		int i, j, key, length;
		length = elements;

		for (i = 1; i < length; i++) {
			key = numbers[i];
			for (j = i-1; j >= 0; j--) {
				if (asc_else_desc ? (numbers[j] < key) : (numbers[j] > key))
					break;

				numbers[j+1] = numbers[j];
			}
			numbers[j+1] = key;
		}
	}
	// }}}
};

// vim:foldmethod=marker
