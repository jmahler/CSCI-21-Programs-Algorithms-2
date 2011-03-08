
#include <string>
#include <sstream>

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
 *  JArray a(5, true);  // (capacity, autosize)
 *  int val, err, index;
 *  bool torf;
 *
 *  val = a.get(index);
 *  torf = a.get(index, val);
 *
 *  err = a.insert(val, index);
 *  err = a.remove(index);
 *  err = a.replace(val, index);
 *
 *  err = a.push(val);
 *  err = a.pop();
 *
 *  val = a.capacity();
 *  val = a.size();
 *
 *  a.describe();
 *
 * @endcode
 */
class JArray {
private:
    int* numbers;
    int  _capacity;
    // _capacity cannot be named capacity because it conflicts with capacity()
    int  elements;       // number of elements, next available position
    bool autosize;
    bool autocollapse;
    int  chunk_size;     // size of chunks to use during realloc

    /*
     * Is the given value valid?
     */
    bool is_valid_val(int value);

    /*
     * Is the requested index valid?
     * Returns true if a value could be retrieved or assigned
     *  to the given index.
     */
    bool is_assignable_index(int index);

    /*
     * Could a value be retrieved from the given index?
     *
     * @returns true if yes, false otherwise
     */
    bool is_gettable_index(int index);

public:
    /**
     * Create a new array object.
     *
     * @arg initial capacity, default 5
     * @arg autosize?, default true
     * @arg autocollapse?, default false
     *
     * When autosize is on the capacity of the array
     * expanded as needed to accommodate the number of elements.
     *
     * When autocollapse is on the array will be collapsed as needed.
     */
    JArray(int capacity=5, bool autosize=true, bool autocollapse=false);

    ~JArray() { delete[] numbers; };

    /**
     * Retrieves the element at the given index.
     *
     * @returns value at index,
     *      -1 on error
     */
    int get(const int index);

    /**
     * Retrieves the element at the given index
     * and assigns to the reference val.
     *
     * @returns true on success, false on error
     */
    bool get(const int index, int& val);

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
     */
    int insert(const int val, const int index);

    /**
     * Remove the element at the given index (0 offset).
     *
     * @returns -1 on error
     */
    int remove(const int index);

    /**
     *
     * Replace the value at the given index with the specified value.
     *
     * @returns -1 on error
     */
    int replace(const int val, const int index);

    /**
     * Inserts a value in the next available slot.
     * See also (insert()).
     *
     * @returns -1 on error
     */
    int push(const int val);

    /**
     * Removes the value at the last slot.
     *
     * @returns -1 on error
     */
    int pop();

    /**
     * The capacity is the maximum number of elements that can
     * be stored in this array.
     *
     * If the array has autosize enabled the capacity will be automatically
     * expanded as needed.
     *
     */
    int capacity() { return _capacity; };

    /**
     * @returns number of elements in array
     */
    int size() { return elements; };

    /**
     * @returns a string describing the array
     *
     * Values included are: capacity, number of elements, and all the values.
     */
    string describe();

};
