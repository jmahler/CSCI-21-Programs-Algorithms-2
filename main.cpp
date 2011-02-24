
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "JArray.h"

using namespace std;

int main(int argc, char** argv)
{
    string input_file = "lab3input.txt";

    if (argc == 2)
        input_file = argv[1];

    ifstream from(input_file.c_str());
    if (!from) {
        cerr << "unable to open file\n";
        exit(1);
    }

    stringstream ss(stringstream::in | stringstream::out);

    int linen = 0; // line numbers

    // line #1: array capacity (an int value)
    int capacity;
    {
    string s;
    getline(from, s);
    linen++;
    stringstream ss(s);
    ss >> capacity;
    }
    
    // line #2: fixed size (0) or auto-resize (1)
    bool autosize;
    {
    string s;
    getline(from, s);
    linen++;
    stringstream ss(s);
    ss >> autosize;
    }

    JArray ja(capacity, autosize);

    string line;
    while (getline(from, line)) {
        linen++;

        string cmd;
        stringstream ss (line);
        ss >> cmd;

        // read in subsequent arguments by using
        // ss >> var;

        if (cmd == "i") {
            int val, idx, err;

            ss >> val;
            ss >> idx;
        
            err = ja.insert(val, idx);
            if (-1 == err)
                cout << val << " inserted at index " << idx << endl;
            else
                cout << idx << " is an invalid index" << endl;

        } else if (cmd == "g") {
            int val, idx;

            ss >> idx;

            val = ja.get(idx);
            if (-1 == val && !ja.is_defined(idx))
                cout << idx << " is an invalid index" << endl;
            else
                cout << "value at " << idx << ": " << val << endl;
        } else if (cmd == "a") {
            int val;

            ss >> val;

            int err = ja.push(val);
            if (-1 == err)
                cout << "array is filled to capacity" << endl;
            else
                cout << val << " added" << endl;

        } else if (cmd == "r") {
            int idx;

            ss >> idx;

            int err = ja.remove(idx);

            if (-1 == err)
                cout << idx << " is an invalid index" << endl;
            else
                cout << "value at " << idx << " removed" << endl;
        } else if (cmd == "c") {
            cout << "array capacity is " << ja.capacity() << endl;
        } else if (cmd == "n") {
            cout << "array has " << ja.size() << " elements" << endl;
        } else if (cmd == "p") {
            cout << ja.describe() << endl;
        }

    }
}
