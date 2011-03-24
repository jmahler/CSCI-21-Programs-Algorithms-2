
#include "JArray.h"
#include <iostream>

//#define NDEBUG
#include <cassert>

using namespace std;

int main(int argc, char** argv)
{
    int val;

    // {{{ replace()
    {
    JArray<int> ja0(2, true);
    assert(-1 == ja0.replace(1, 0));
    assert(-1 != ja0.insert(1, 0));
    assert(-1 == ja0.replace(2, 1));
	// replace cannot expand the array
    }
    // }}}

    // {{{ insert(), autosize
    {
    JArray<int> ja(2, true);

	// invalid indexes
    assert(-1 == ja.insert(123,  1));
    assert(-1 == ja.insert(123, -1));

	for (int i = 0; i < 10; i++) {
    	assert(-1 != ja.insert(i, i));
	}
	for (int i = 0; i < 10; i++) {
		assert(i == ja.get(i));
	}
    }
    // }}}

    // {{{ insert(), fixed size
    {
    JArray<int> ja(2, false);
	int val;

	// invalid indexes
    assert(-1 == ja.insert(123,  1));
    assert(-1 == ja.insert(123, -1));

	for (int i = 0; i < 2; i++) {
    	assert(-1 != ja.insert(i, i));
	}
	for (int i = 0; i < 2; i++) {
		assert(i == ja.get(i));
	}
	for (int i = 2; i < 20; i++) {
		assert(! ja.get(i, val));
	}

    }
    // }}}

    // {{{ remove(), autosize
    {
    JArray<int> ja0(2, true);
	int val;

	assert(0 == ja0.size());

	// can't remove invalid indexes
    assert(-1 == ja0.remove(1));
    assert(-1 == ja0.remove(0));

	// add some, remove some
    assert(-1 != ja0.insert(1, 0));
	assert(1 == ja0.size());

    assert(-1 != ja0.insert(2, 1));
	assert(2 == ja0.size());

	ja0.get(1, val);
	assert(2 == val);

    assert(-1 != ja0.remove(1));
	assert(1 == ja0.size());

	ja0.get(0, val);
	assert(1 == val);

    assert(-1 != ja0.remove(0));
	assert(0 == ja0.size());
    }
    // }}}

    // {{{ get(index)
    {
    JArray<int> ja(2, true);

    assert(-1 != ja.insert(1, 0));
    assert(-1 != ja.insert(2, 0));

	// [2, 1]
	assert(2 == ja.get(0));
	assert(1 == ja.get(1));

	try {
		ja.get(2);  // invalid index	

		assert(false); // should never get here
	} catch (InvalidIndexError err) {
		assert(true);
	}

    }
    // }}}

    // {{{ get(index, val)
    {
    JArray<int> ja0(1, false);
    int x;

    assert(! ja0.get(0, x));
    assert(! ja0.get(2, x));

    ja0.push(12);
    assert(ja0.get(0, x));
    assert(12 == x);

    for (int i = 1; i < 10; i++) {
        assert(! ja0.get(i, x));
    }
    }
    // }}}

    // {{{ misc, fixed size
    {
    JArray<int> ja0(5, false);
    assert(5 == ja0.capacity());
    assert(0 == ja0.size());

    for (int i = 0; i < 5; i++) {
        assert(-1 != ja0.insert(i, i));
    }
    assert(5 == ja0.capacity());
    assert(5 == ja0.size());

    assert(-1 == ja0.push(666));

    for (int i = 0; i < 5; i++) {
        assert(ja0.get(i, val));
        assert(i == val);
    }

    assert(! ja0.get(5, val));

    assert(-1 == ja0.remove(6));
    assert(-1 == ja0.remove(5));
    assert(-1 != ja0.remove(2));

    assert(4 == ja0.size());
    assert(5 == ja0.capacity());

    assert(ja0.get(1, val));
    assert(1 == val);
    assert(ja0.get(2, val));
    assert(3 == val);
    assert(ja0.get(3, val));
    assert(4 == val);

    assert(-1 != ja0.replace(12, 3));
    assert(ja0.get(1, val));
    assert(1 == val);
    assert(ja0.get(2, val));
    assert(3 == val);
    assert(ja0.get(3, val));
    assert(12 == val);

    assert(! ja0.get(4, val));

    for (int i = 0; i < 4; i++) {
		ja0.pop();
    }
    ja0.pop();

    assert(0 == ja0.size());
    assert(5 == ja0.capacity());
    }

    {
    // fixed size with capacity of 0
    JArray<int> ja0(0, false);
    assert(0 == ja0.capacity());
    assert(0 == ja0.size());
    assert(-1 == ja0.replace(0, 0));
    assert(-1 == ja0.insert(0, 0));
    assert(-1 == ja0.push(0));
    }

    {
    // fixed size with capacity of 1
    JArray<int> ja0(1, false);
    assert(1 == ja0.capacity());
    assert(0 == ja0.size());
    //assert(-1 != ja0.replace(0, 0));
    assert(-1 != ja0.insert(0, 0));  // discards a value
    ja0.pop();
    assert(-1 != ja0.push(0));
    }
    // }}}

    // {{{ bounds checks
    {
    JArray<int> ja(5, false);
    
    // cant insert beyond the next available (no gaps)
    assert(-1 == ja.insert(10, 1));
    assert(-1 != ja.insert(10, 0));

    assert(-1 == ja.insert(66, 2));
    assert(-1 != ja.insert(66, 1));

    assert(-1 == ja.insert(12, 3));
    assert(-1 != ja.insert(12, 2));

    // [10,  66,  12]

    assert(-1 != ja.insert(9, 0)); 

    // [9, 10,  66,  12]

    assert(-1 != ja.replace(11, 2));

    // [9, 10,  11,  12]

    assert(ja.get(0, val));
    assert(9 == val);
    assert(ja.get(1, val));
    assert(10 == val);
    assert(ja.get(2, val));
    assert(11 == val);
    assert(ja.get(3, val));
    assert(12 == val);
    assert(! ja.get(4, val));
    assert(! ja.get(5, val));

    assert(4 == ja.size());
    }
    // }}}

    // {{{ near autoexpand check
    /* Tests insert bounds when near the point of autoexpansion.
     */
    {
    JArray<int> ja(2, true);
    
    assert(ja.capacity() <= 2);

    assert(-1 == ja.insert(10, 1));
    assert(-1 == ja.insert(10, 2));
    assert(-1 == ja.insert(10, 3));
    assert(-1 == ja.insert(10, 4));

    assert(-1 != ja.insert(10, 0));

    assert(-1 == ja.insert(10, 2));
    assert(-1 == ja.insert(10, 3));
    assert(-1 == ja.insert(10, 4));

    assert(-1 != ja.insert(11, 1));

    assert(-1 == ja.insert(10, 3));
    assert(-1 == ja.insert(10, 4));
    assert(-1 == ja.insert(10, 5));

    assert(-1 != ja.insert(12, 2));

    // it should have expanded

    assert(ja.capacity() > 2);

    assert(-1 == ja.insert(10, 4));
    assert(-1 == ja.insert(10, 5));
    assert(-1 == ja.insert(10, 6));
    }
    // }}}

    // {{{ autosize test
    {
    JArray<int> ja0(5, true);
    assert(5 == ja0.capacity());
    assert(0 == ja0.size());

    for (int i = 0; i < 121; i++) {
        ja0.insert(i, i);
    }

    assert(121 <= ja0.capacity());
    assert(121 == ja0.size());

    for (int i = 0; i < 121; i++) {
        assert(ja0.get(i, val));
        assert(i == val);
    }

    for (int i = 0; i < 121; i++) {
        if (i % 2) {
            assert(-1 != ja0.remove(0));
        } else {
            ja0.pop();
        }
    }

    assert(0 == ja0.size());
    }
    // }}}

    // {{{ autosize with capacity of 0
    {
    JArray<int> ja0(0, true);
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
    JArray<int> ja0(5, true, true);

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
        assert(ja0.get(i, val));
        assert(val == i);
    }

    // has the ccapacity been decreased?
    assert(ja0.capacity() < 200);
    assert((250 - 200) == ja0.size());
    }
    // }}}

    // {{{ values
    {
    JArray<int> ja(5, false);

    assert(-1 != ja.insert(-1, 0));
    assert(-1 != ja.insert(-2, 1));
    assert(-1 != ja.push(-3));

    assert(ja.get(0, val));
    assert(-1 == val);
	assert(-1 == ja.get(0));

    assert(ja.get(1, val));
    assert(-2 == val);
	assert(-2 == ja.get(1));

    assert(ja.get(2, val));
    assert(-3 == val);
	assert(-3 == ja.get(2));
    }
    // }}}

    // {{{ memory leak test #1
    /*
     * This section will create and destroy a large number of objects.
     * A good way to monitor the memory consumption is by using the
	 * program "top"
     */
    // tested OK 3/24/11
    // tested OK 3/8/11
    // tested OK 2/23/11
	// #1
	/*
    while(1) {
        JArray<int> jaX(5, true, true);

        for (int i = 0; i < 21; i++) {
            jaX.insert(i, 0);
        }
    }
	*/
	// }}}

	// {{{ memory leak test #2
	// tested OK 3/24/11
	/*
	{
        JArray<int> jaX(5, true, true);

		while (1) {
			for (int i = 0; i < 150; i++) {
				jaX.push(i);
			}

			for (int i = 0; i < 50; i++) {
				jaX.pop();
			}

			for (int i = 0; i < 100; i++) {
				jaX.push(i);
			}

			for (int i = 0; i < 200; i++) {
				jaX.pop();
			}
		}
	}
	*/
    // }}}

    // {{{ insertion sort, ascending
    {
    JArray<int> ja(5, false);
	// 1 3 5 7
    assert(-1 != ja.insert(7, 0));
    assert(-1 != ja.insert(3, 1));
    assert(-1 != ja.push(5));
    assert(-1 != ja.push(1));

	ja.isort(true); // ascending

    assert(ja.get(0, val));
    assert(1 == val);
    assert(ja.get(1, val));
    assert(3 == val);
    assert(ja.get(2, val));
    assert(5 == val);
    assert(ja.get(3, val));
    assert(7 == val);
    }
	// }}}

	// {{{ insertion sort, descending
    {
    JArray<int> ja(5, false);
	// 1 3 5 7
    assert(-1 != ja.insert(7, 0));
    assert(-1 != ja.insert(3, 1));
    assert(-1 != ja.push(5));
    assert(-1 != ja.push(1));

	ja.isort(false); // descending

    assert(ja.get(0, val));
    assert(7 == val);
    assert(ja.get(1, val));
    assert(5 == val);
    assert(ja.get(2, val));
    assert(3 == val);
    assert(ja.get(3, val));
    assert(1 == val);
    }
	// }}}

	// {{{ bubble sort, ascending
    {
    JArray<int> ja(5, true);
	// 1 3 5 7
    assert(-1 != ja.insert(7, 0));
    assert(-1 != ja.insert(3, 1));
    assert(-1 != ja.push(5));
    assert(-1 != ja.push(1));

	ja.bsort(true); // ascending

    assert(ja.get(0, val));
    assert(1 == val);
    assert(ja.get(1, val));
    assert(3 == val);
    assert(ja.get(2, val));
    assert(5 == val);
    assert(ja.get(3, val));
    assert(7 == val);
    }
	// }}}

	// {{{ bubble sort, descending
    {
    JArray<int> ja(5, false);
	// 1 3 5 7
    assert(-1 != ja.insert(7, 0));
    assert(-1 != ja.insert(3, 1));
    assert(-1 != ja.push(5));
    assert(-1 != ja.push(1));

	ja.bsort(false); // descending

    assert(ja.get(0, val));
    assert(7 == val);
    assert(ja.get(1, val));
    assert(5 == val);
    assert(ja.get(2, val));
    assert(3 == val);
    assert(ja.get(3, val));
    assert(1 == val);
    }
    // }}}

    cout << "All tests passed.\n";
}
