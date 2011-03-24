
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
    assert(-1 == ja0.replace(0, 1));
    assert(-1 != ja0.insert(0, 1));
    assert(-1 == ja0.replace(1, 2));
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
		assert(i == ja.at(i));
	}
    }
    // }}}

    // {{{ insert(), fixed size
    {
    JArray<int> ja(2, false);
	int val;

	// invalid indexes
    assert(-1 == ja.insert(1, 123));
    assert(-1 == ja.insert(-1, 123));

	for (int i = 0; i < 2; i++) {
    	assert(-1 != ja.insert(i, i));
	}
	for (int i = 0; i < 2; i++) {
		assert(i == ja.at(i));
	}
	for (int i = 2; i < 20; i++) {
		assert(! ja.get(i, val));
	}

    }
    // }}}

    // {{{ erase(), autosize
    {
    JArray<int> ja0(2, true);
	int val;

	assert(0 == ja0.size());

	// can't erase invalid indexes
    assert(-1 == ja0.erase(1));
    assert(-1 == ja0.erase(0));

	// add some, erase some
    assert(-1 != ja0.insert(0, 1));
	assert(1 == ja0.size());

    assert(-1 != ja0.insert(1, 2));
	assert(2 == ja0.size());

	ja0.get(1, val);
	assert(2 == val);

    assert(-1 != ja0.erase(1));
	assert(1 == ja0.size());

	ja0.get(0, val);
	assert(1 == val);

    assert(-1 != ja0.erase(0));
	assert(0 == ja0.size());
    }
    // }}}

    // {{{ empty
    {
    JArray<int> ja(2, true);
	assert(ja.empty());
	ja.push_back(1);
	assert(! ja.empty());
	}
    // }}}

    // {{{ at(index)
    {
    JArray<int> ja(2, true);

    assert(-1 != ja.insert(0, 1));
    assert(-1 != ja.insert(0, 2));

	// [2, 1]
	assert(2 == ja.at(0));
	assert(1 == ja.at(1));

	try {
		ja.at(2);  // invalid index	

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

    ja0.push_back(12);
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

    assert(-1 == ja0.push_back(666));

    for (int i = 0; i < 5; i++) {
        assert(ja0.get(i, val));
        assert(i == val);
    }

    assert(! ja0.get(5, val));

    assert(-1 == ja0.erase(6));
    assert(-1 == ja0.erase(5));
    assert(-1 != ja0.erase(2));

    assert(4 == ja0.size());
    assert(5 == ja0.capacity());

    assert(ja0.get(1, val));
    assert(1 == val);
    assert(ja0.get(2, val));
    assert(3 == val);
    assert(ja0.get(3, val));
    assert(4 == val);

    assert(-1 != ja0.replace(3, 12));
    assert(ja0.get(1, val));
    assert(1 == val);
    assert(ja0.get(2, val));
    assert(3 == val);
    assert(ja0.get(3, val));
    assert(12 == val);

    assert(! ja0.get(4, val));

    for (int i = 0; i < 4; i++) {
		ja0.pop_back();
    }
    ja0.pop_back();

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
    assert(-1 == ja0.push_back(0));
    }

    {
    // fixed size with capacity of 1
    JArray<int> ja0(1, false);
    assert(1 == ja0.capacity());
    assert(0 == ja0.size());
    //assert(-1 != ja0.replace(0, 0));
    assert(-1 != ja0.insert(0, 0));  // discards a value
    ja0.pop_back();
    assert(-1 != ja0.push_back(0));
    }
    // }}}

    // {{{ bounds checks
    {
    JArray<int> ja(5, false);
    
    // cant insert beyond the next available (no gaps)
    assert(-1 == ja.insert(1, 10));
    assert(-1 != ja.insert(0, 10));

    assert(-1 == ja.insert(2, 66));
    assert(-1 != ja.insert(1, 66));

    assert(-1 == ja.insert(3, 12));
    assert(-1 != ja.insert(2, 12));

    // [10,  66,  12]

    assert(-1 != ja.insert(0, 9)); 

    // [9, 10,  66,  12]

    assert(-1 != ja.replace(2, 11));

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

	// out of bounds
    assert(-1 == ja.insert(1, 10));
    assert(-1 == ja.insert(2, 10));
    assert(-1 == ja.insert(3, 10));
    assert(-1 == ja.insert(4, 10));

	// insert one value
    assert(-1 != ja.insert(0, 10));

	// out of bounds
    assert(-1 == ja.insert(2, 10));
    assert(-1 == ja.insert(3, 10));
    assert(-1 == ja.insert(4, 10));

	// insert another value
    assert(-1 != ja.insert(1, 11));

	// out of bounds
    assert(-1 == ja.insert(3, 10));
    assert(-1 == ja.insert(4, 10));
    assert(-1 == ja.insert(5, 10));

	// insert another value
    assert(-1 != ja.insert(2, 12));

    // it should have expanded
    assert(ja.capacity() > 2);

	// out of bounds
    assert(-1 == ja.insert(4, 10));
    assert(-1 == ja.insert(5, 10));
    assert(-1 == ja.insert(6, 10));
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
            assert(-1 != ja0.erase(0));
        } else {
            ja0.pop_back();
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
    assert(-1 != ja0.push_back(0));
    assert(ja0.capacity() > 0);
    assert(ja0.size() > 0);
    }
    // }}}

    // {{{ values
    {
    JArray<int> ja(5, false);

    assert(-1 != ja.insert(0, -1));
    assert(-1 != ja.insert(1, -2));
    assert(-1 != ja.push_back(-3));

    assert(ja.get(0, val));
    assert(-1 == val);
	assert(-1 == ja.at(0));

    assert(ja.get(1, val));
    assert(-2 == val);
	assert(-2 == ja.at(1));

    assert(ja.get(2, val));
    assert(-3 == val);
	assert(-3 == ja.at(2));
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
            jaX.insert(0, i);
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
				jaX.push_back(i);
			}

			for (int i = 0; i < 50; i++) {
				jaX.pop_back();
			}

			for (int i = 0; i < 100; i++) {
				jaX.push_back(i);
			}

			for (int i = 0; i < 200; i++) {
				jaX.pop_back();
			}
		}
	}
	*/
    // }}}

    // {{{ insertion sort, ascending
    {
    JArray<int> ja(5, false);
	// 1 3 5 7
    assert(-1 != ja.insert(0, 7));
    assert(-1 != ja.insert(1, 3));
    assert(-1 != ja.push_back(5));
    assert(-1 != ja.push_back(1));

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
    assert(-1 != ja.insert(0, 7));
    assert(-1 != ja.insert(1, 3));
    assert(-1 != ja.push_back(5));
    assert(-1 != ja.push_back(1));

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
    assert(-1 != ja.insert(0, 7));
    assert(-1 != ja.insert(1, 3));
    assert(-1 != ja.push_back(5));
    assert(-1 != ja.push_back(1));

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
    assert(-1 != ja.insert(0, 7));
    assert(-1 != ja.insert(1, 3));
    assert(-1 != ja.push_back(5));
    assert(-1 != ja.push_back(1));

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

    // {{{ clear
    {
    JArray<int> ja;

    assert(ja.capacity() > 0);
    assert(0 == ja.size());

	ja.push_back(1);
	ja.push_back(2);

    assert(2 == ja.size());

	ja.clear();

    assert(0 == ja.size());
    }
    // }}}

    cout << "All tests passed.\n";
}
