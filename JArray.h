
#include <string>
#include <sstream>

using namespace std;

/**
 *
 * JArray is a class which improves the standard array([])
 * with features such as length validation and dynamic resizing.
 *
*
 * <h2>Synopsis</h2>
 *
 * @code
 *  #include "JArray.h";
 *
 *  JArray a(5, true);
 *  int x;
 *
 *  a.capacity();
 *
 *  x = a.get(2);
 *
 *  a.insert(3, 0);
 *
 *  a.get_stats();
 * @endcode
 */
class JArray {

    int* numbers;
    int _capacity;
    int elements;       // number of elements, next available position
    bool autosize;
    bool autocollapse;
    int chunk_size;     // size of chunks to use during realloc

public:
    /**
     * Create a new array object.
     *
     * @arg initial capacity, default 5
     * @arg autosize?, default true
     * @arg autocollapse?, default false
     *
     * When autosize is on the capacity of the array
     * expanded as needed to accomadate the number of elements.
     *
     * When autocollapse is on the array will be collapsed as needed.
     *
     */
    JArray(int capacity=5, bool autosize=true, bool autocollapse=false);

    ~JArray() { delete[] numbers; };

    /**
     * Retrieves the element at the given index.
     *
     * @returns value at index,
     *      -1 on error (index out of bounds, or value undefined)
     *
     * <h2 style="color: red; text-decoration: blink;">Warning</h2>
     *
     * Currently the value -1 is used to indicate an out of bounds error
     * as per the project specifications.
     * But if the value stored is -1 this makes it impossible to detect
     * if an error occured.
     * One workaround is to use the function is_defined() to check
     * whether that position is defined.
     *
     * @code
     *
     * int err;
     * index i = 3;
     * Jarray ja();
     *
     * err = ja.get(i);
     * if (-1 == err and ja.is_defined(i)) {
     *     // we got an error
     * }
     * // else we got a valid value, that is possibly -1
     *
     * @endcode
     */
    int get(const int index);

    /**
     * Insert a value at the given index (0 offset).
     *
     * @returns -1 on error (index out of bounds)
     */
    int insert(const int val, const int index);

    /**
     * Inserts a value in the next available slot.
     *
     * @returns -1 on error
     */
    int push(const int val);

    /**
     * Remove the element at the given index (0 offset).
     *
     * @returns -1 on error (index out of bounds)
     */
    int remove(const int index);

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

    /**
     * Is a value defined at the given index?
     */
    bool is_defined(int index) { return (index >= 0 && index < elements); };
};

