
#include "JArray.h"

// {{{ JArray::JArray
JArray::JArray(int __capacity, bool _autosize)
{
    if (__capacity < 0)
        _capacity = 0;
    else
        _capacity = __capacity;

    autosize = _autosize;

    elements = 0;

    numbers = new int[_capacity];
}
// }}}

// {{{ JArray::get
int JArray::get(const int i)
{
    if (is_defined(i))
        return numbers[i];
    else
        return -1;
}
// }}}

// {{{ JArray::insert
int JArray::insert(int val, int i)
{
    if (i < 0)
        return -1;

    // cant add an element beyond the last one
    if (i > elements)
        return -1;

    // Make sure there is room, or make some room.
    if (elements == _capacity) {
        // no room left
        if (autosize) {
            //expand();
        } else {
            return -1;  // sorry, no room left
        }
    }

    // a simple append
    if (i == elements) {
        numbers[i] = val;
        elements++;

        return 0; // OK
    }

    // shift all previous elements
    for (int j = elements; j > i; j--)
        numbers[j] = numbers[j-1];

    elements++;
    numbers[i] = val;

    return 0; // OK
}
// }}}


// vim:foldmethod=marker
