
#include "JArray.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{

    JArray ja0(5, false);
    JArray ja1(5, true);
    JArray ja2(0, true);

    for (int i = 0; i < 100; i++) {
        ja0.insert(i, 0);
    }

    cout << "ja0: " << ja0.describe() << endl;

    for (int i = 0; i < 15; i++) {
        ja1.insert(i, 0);
    }
    
    cout << "ja1: " << ja1.describe() << endl;

    for (int j = 0; j < 100; j++) {
        for (int i = 0; i < 21; i++) {
            //ja2.insert(i, 0);
            ja2.push(i);
        }

        for (int i = 0; i < 11; i++) {
            ja2.remove(0);
        }

        for (int i = 0; i < 10; i++) {
            ja2.insert(i, 0);
        }

        for (int i = 0; i < 21; i++) {
            ja2.remove(0);
            ja2.pop();
        }
    }
    cout << "ja2: " << ja2.describe() << endl;

    // memory leak test
    /* tested OK 2/23/11
    while(1) {
        JArray jaX(5, true);

        for (int i = 0; i < 21; i++) {
            jaX.insert(i, 0);
        }
    }
    */
}

/*
void ok(bool test) {

}
*/
