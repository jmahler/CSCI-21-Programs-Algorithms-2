
#include "JArray.h"
#include <iostream>

//#define NDEBUG
#include <cassert>

using namespace std;

int main(int argc, char** argv)
{
    // {{{ fixed size tests
    {
    JArray ja0(5, false);
    assert(5 == ja0.capacity());
    assert(0 == ja0.size());

    // invalid value, valid index
    assert(-1 == ja0.insert(-1, 0));
    assert(-1 == ja0.insert(-1000, 0));

    for (int i = 0; i < 5; i++) {
        assert(-1 != ja0.insert(i, i));
    }
    assert(5 == ja0.capacity());
    assert(5 == ja0.size());

    assert(-1 == ja0.push(666));

    for (int i = 0; i < 5; i++) {
        assert(i == ja0.get(i));
    }

    assert(-1 == ja0.get(5));

    assert(-1 == ja0.remove(6));
    assert(-1 == ja0.remove(5));
    assert(-1 != ja0.remove(2));

    assert(4 == ja0.size());
    assert(5 == ja0.capacity());

    assert(1 == ja0.get(1));
    assert(3 == ja0.get(2));
    assert(4 == ja0.get(3));
    assert(-1 != ja0.replace(12, 3));
    assert(1 == ja0.get(1));
    assert(3 == ja0.get(2));
    assert(12 == ja0.get(3));

    assert(-1 == ja0.get(4));

    for (int i = 0; i < 4; i++) {
        assert(ja0.pop() > -1);
    }
    assert(-1 == ja0.pop());

    assert(0 == ja0.size());
    assert(5 == ja0.capacity());
    }

    {
    // fixed size with capacity of 0
    JArray ja0(0, false);
    assert(0 == ja0.capacity());
    assert(0 == ja0.size());
    assert(-1 == ja0.replace(0, 0));
    assert(-1 == ja0.insert(0, 0));
    assert(-1 == ja0.push(0));
    }

    {
    // fixed size with capacity of 1
    JArray ja0(1, false);
    assert(1 == ja0.capacity());
    assert(0 == ja0.size());
    assert(-1 != ja0.replace(0, 0));
    assert(-1 != ja0.insert(0, 0));  // discards a value
    assert(-1 != ja0.pop());
    assert(-1 != ja0.push(0));
    }


    // }}}

    // {{{ autosize test
    {
    JArray ja0(5, true);
    assert(5 == ja0.capacity());
    assert(0 == ja0.size());

    for (int i = 0; i < 121; i++) {
        ja0.insert(i, i);
    }

    assert(121 <= ja0.capacity());
    assert(121 == ja0.size());

    for (int i = 0; i < 121; i++) {
        assert(i == ja0.get(i));
    }

    for (int i = 0; i < 121; i++) {
        if (i % 2) {
            assert(-1 != ja0.remove(0));
        } else {
            assert(-1 != ja0.pop());
        }
    }

    assert(0 == ja0.size());
    }

    {
    // autosize with capacity of 0
    JArray ja0(0, true);
    assert(0 == ja0.capacity());
    assert(0 == ja0.size());
    //assert(-1 != ja0.insert(0, 0));
    assert(-1 != ja0.push(0));
    assert(ja0.capacity() > 0);
    assert(ja0.size() > 0);
    }
    // }}}

    // {{{ autocollapse test
    {
    JArray ja0(5, true, true);

    // add a bunch of values
    for (int i = 0; i < 250; i++) {
        ja0.insert(i, i);
    }

    assert(250 <= ja0.capacity());
    assert(250 == ja0.size());

    // remove atleast half the elements
    for (int i = 0; i < 200; i++) {
        ja0.pop();
    }

    // all the previously stored values should be the same
    for (int i = 0; i < (250 - 200); i++) {
        assert(i == ja0.get(i));
    }

    // has the ccapacity been decreased?
    assert(ja0.capacity() < 200);
    assert((250 - 200) == ja0.size());
    }
    // }}}

    // {{{ memory leak test
    /*
     * This section will create and destroy a large number of objects.
     * A good way to monitor the memory consumption will this is running
     * is by using "top".
     */
    // tested OK 2/23/11
    // tested OK 3/8/11
    /*
    while(1) {
        JArray jaX(5, true);

        for (int i = 0; i < 21; i++) {
            jaX.insert(i, 0);
        }
    }
    */
    // }}}

    cout << "All tests passed.\n";
}
