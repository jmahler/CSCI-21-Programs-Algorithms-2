
#include "JArray.h"
#include <iostream>

using namespace std;

static int testn = 0;
static int failn = 0;

/**
 * Test an item and keep track of the pass/fail counts.
 */
void ok(bool pass, string desc="") {
    testn++;

    if (pass) {

    } else {
        failn++;
        cout << testn << ": " << (pass ? "ok" : "FAIL") << " " << desc << endl;
    }
}

/**
 * Display a summary of the tests (pass/fail) counts.
 */
void summary() {
    cout << testn << " tests run, " << failn << " failed\n";
}

int main(int argc, char** argv)
{

    // fixed size tests
    {
    JArray ja0(5, false);
    ok(5 == ja0.capacity());
    ok(0 == ja0.size());

    for (int i = 0; i < 6; i++) {
        ja0.insert(i, i);
    }
    ok(5 == ja0.capacity());
    ok(5 == ja0.size());

    for (int i = 0; i < 5; i++) {
        ok(i == ja0.get(i));
    }

    ok(-1 == ja0.get(5));

    ok(-1 == ja0.remove(6));
    ok(-1 == ja0.remove(5));
    ok(-1 != ja0.remove(2));

    ok(4 == ja0.size());
    ok(5 == ja0.capacity());
    ok(1 == ja0.get(1));
    ok(3 == ja0.get(2));
    ok(4 == ja0.get(3));
    ok(-1 == ja0.get(4));
    }

    // autosize test
    {
    JArray ja0(5, true);
    ok(5 == ja0.capacity());
    ok(0 == ja0.size());

    for (int i = 0; i < 121; i++) {
        ja0.insert(i, i);
    }

    ok(121 <= ja0.capacity());
    ok(121 == ja0.size());

    for (int i = 0; i < 121; i++) {
        ok(i == ja0.get(i));
    }

    for (int i = 0; i < 121; i++) {
        if (i % 2) {
            ok(-1 != ja0.remove(0));
        } else {
            ok(-1 != ja0.pop());
        }
    }

    ok(0 == ja0.size());
    }

    // autocollapse test
    {
    JArray ja0(5, true, true);

    for (int i = 0; i < 250; i++) {
        ja0.insert(i, i);
    }

    ok(250 <= ja0.capacity());
    ok(250 == ja0.size());

    for (int i = 0; i < 250; i++) {
        ja0.pop();
    }
    ok(5 <= ja0.capacity());
    ok(0 == ja0.size());
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

    summary();
}

