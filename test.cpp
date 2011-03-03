
#include "JArray.h"
#include <iostream>

//#define NDEBUG
#include <assert.h>

using namespace std;

int main(int argc, char** argv)
{
    // fixed size tests
    {
    JArray ja0(5, false);
    assert(5 == ja0.capacity());
    assert(0 == ja0.size());

    for (int i = 0; i < 6; i++) {
        ja0.insert(i, i);
    }
    assert(5 == ja0.capacity());
    assert(5 == ja0.size());

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
    assert(-1 == ja0.get(4));
    }

    // autosize test
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

    // autocollapse test
    {
    JArray ja0(5, true, true);

    for (int i = 0; i < 250; i++) {
        ja0.insert(i, i);
    }

    assert(250 <= ja0.capacity());
    assert(250 == ja0.size());

    for (int i = 0; i < 250; i++) {
        ja0.pop();
    }
    assert(5 <= ja0.capacity());
    assert(0 == ja0.size());
    }

    // memory leak test
    /* tested OK 2/23/11
    while(1) {
        JArray jaX(5, true);

        for (int i = 0; i < 21; i++) {
            jaX.insert(i, 0);
        }
    }
    */

    cout << "All tests passed.\n";
}
