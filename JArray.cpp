
#include "JArray.h"

// {{{ JArray::JArray
JArray::JArray(int __capacity, bool _autosize, bool _autocollapse)
{
    if (__capacity < 0)
        _capacity = 0;
    else
        _capacity = __capacity;

    autosize = _autosize;
    autocollapse = _autocollapse;

    elements = 0;

    numbers = new int[_capacity];

    chunk_size = 5;
}
// }}}

// {{{ JArray::is_valid_val
bool JArray::is_valid_val(const int val)
{
    if (val >= 0)
        return true;

    return false;
}
// }}}

// {{{ JArray::is_gettable_index
bool JArray::is_gettable_index(int index)
{
    return (index >= 0 && index < elements);
}
// }}}

// {{{ JArray::is_assignable_index
bool JArray::is_assignable_index(const int i)
{
    // negative indexs are invalid
    if (i < 0)
        return false;

    // Cant add an element beyond the last one
    // and there are no valid elements beyond the last one
    if (i > elements)
        return false;

    if (i < elements)
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

// {{{ JArray::get
int JArray::get(const int i)
{
    if (! is_gettable_index(i))
        return -1;

    return numbers[i];
}
// }}}

// {{{ JArray::insert
int JArray::insert(const int val, const int i)
{
    if (! is_valid_val(val))
        return -1;

    if (! is_assignable_index(i))
        return -1;

    if (elements == _capacity) { // were out of room
        if (autosize) {
            // make some room
            int new_capacity = (_capacity > 0) ? _capacity*2 : 2;

            int* new_numbers = new int[new_capacity];
            _capacity = new_capacity;

            for (int i = 0; i < elements; i++) {
                new_numbers[i] = numbers[i];
            }

            delete[] numbers;

            numbers = new_numbers;
        }
    }

    // we could'nt make any room
    if (i >= _capacity)
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
    for (int j = end; j > i; j--)
        numbers[j] = numbers[j-1];

    numbers[i] = val;

    return 0; // OK
}
// }}}

// {{{ JArray::remove
int JArray::remove(const int i)
{
    if (! is_assignable_index(i) || ! is_gettable_index(i))
        return -1;

    for (int j = i; j < elements; j++)
        numbers[j] = numbers[j+1];

    elements--;

    /* When there is atleast one elment and the capacity is twice as
     * large as the number of elements it will be collapsed to the
     * number of elements.
     */
    if (autocollapse && (elements > 0) && 0 == (_capacity % elements*2)) {
        int* new_numbers = new int[elements];
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

// {{{ JArray::replace
int JArray::replace(const int val, const int i)
{
    if (! is_valid_val(val))
        return -1;

    if (! is_assignable_index(i))
        return -1;

    numbers[i] = val;

    return 0; // OK
}
// }}}

// {{{ JArray::push
int JArray::push(const int val)
{
    return insert(val, elements);
}
// }}}

// {{{ JArray::pop
int JArray::pop()
{
    return remove((elements - 1));
}
// }}}

// {{{ JArray::describe
string JArray::describe()
{
    static const int chunk = 10;  // values per line

    stringstream ss;

    ss << elements << "/" << _capacity << endl;

    ss << " ["; // start of array
    for (int i = 0; i < elements; i++) {

        ss << " " << numbers[i];

        // for all but the last element
        if (i != (elements - 1))
            ss << ",";

        // every chunk'th except at the beggining or end
        if ((i + 1) != 0 && 0 == ((i + 1) % chunk) && i != (elements - 1)) {
            ss << endl;
            ss << "  "; // indent the next line
        }
    }
    ss << " ]"; // end of array

    return ss.str();
}
// }}}

// vim:foldmethod=marker
