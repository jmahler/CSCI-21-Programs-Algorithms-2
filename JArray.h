
#include <string>

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
    int elements; // number of elements, next available position
    bool autosize;

public:
    /**
     * Create a new array object.
     *
     * @arg initial capacity, default 5
     * @arg autosize?, default true
     *
     * When autosize is on the capacity of the array
     * expanded as needed to accomadate the number of elements.
     *
     */
    JArray(int capacity=5, bool autosize=true);

    ~JArray() { delete[] numbers; };

    /**
     * Get the element at the given index.
     *
     * @returns value at index,
     *      -1 on error (index out of bounds, or value undefined)
     *
     * <h2 style="color: red; text-decoration: blink;">Warning</h2>
     *
     * Currently the value -1 is used to indicate an out of bounds error
     * as per the project specifications.
     * But if the value stored is a -1 this makes it impossible to detect
     * if an error occured with functions such as get() which return a value.
     */
    int get(const int index);

    /**
     * Insert a value at the given index (0 offset).
     *
     * @returns -1 on error (index out of bounds)
     */
    int insert(int val, int index);

    /**
     * Remove the element at the given index (0 offset).
     *
     * @returns -1 on error (index out of bounds)
     */
    int remove(int index);

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
    string get_stats();

    /**
     * Is a value defined at the given index?
     */
    bool is_defined(int index) { return (index >= 0 and index < elements); };
};

