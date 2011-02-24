
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

    chunk_size = 5;
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
int JArray::insert(const int val, const int i)
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
            int* new_numbers = new int[_capacity + chunk_size];
            _capacity += chunk_size;

            for (int i = 0; i < elements; i++) {
                new_numbers[i] = numbers[i];
            }

            delete[] numbers;

            numbers = new_numbers;
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

// {{{ JArray::push
int JArray::push(const int val)
{
    return insert(val, elements);
}
// }}}

// {{{ JArray::remove
int JArray::remove(const int i)
{
    if (i < 0)
        return -1;

    if (! is_defined(i))
        return -1;

    // cant add an element beyond the last one
    if (i > elements)
        return -1;

    for (int j = i; j < elements; j++)
        numbers[j] = numbers[j+1];

    elements--;

    // collapse the size of the array if needed
    if (autosize && (elements > 0) && 0 == (elements % chunk_size)) {
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

    ss << " ["; // start of first line
    for (int i = 0; i < elements; i++) {

        ss << " " << numbers[i] ;

        if (i != (elements - 1))
            ss << ",";

        if ((i + 1) != 0 && 0 == ((i + 1) % chunk)) {
            ss << endl;
            ss << "  ";
        }
    }
    ss << " ] ";
    //ss << endl << " ] ";  // if you want ] on its own line

    return ss.str();
}
// }}}

// vim:foldmethod=marker
