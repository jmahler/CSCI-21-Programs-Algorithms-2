
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "JArray.h"
#include "CommandParser.h"

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
    string str_capacity;
    getline(from, str_capacity);
    linen++;
    
    int capacity;
    ss << str_capacity;
    ss >> capacity;

    // line #2: fixed size (0) or auto-resize (1)
    string str_autosize;
    getline(from, str_autosize);
    linen++;


    int iautosize;
    bool autosize;
    ss << str_autosize;
    ss >> iautosize;
    if (1 == iautosize)
        autosize = true;
    else
        autosize = false;

    JArray ja(capacity, autosize);

    string line;
    while (getline(from, line)) {
        linen++;

        CommandParser cp(line);

        string cmd = cp.getCommand();
        string arg = cp.getArgument();

        if (cmd == "i") {
            // TODO
        
        } else if (cmd == "g") {
            int val, idx;

            stringstream ss(arg);
            ss >> idx;

            val = ja.get(idx);
            if (-1 == val && !ja.is_defined(idx))
                cout << idx << " is an invalid index" << endl;
            else
                cout << "value at " << idx << ": " << val << endl;
        } else if (cmd == "a") {
            int val;

            stringstream ss(arg);
            ss >> val;

            int err = ja.push(val);
            if (-1 == err)
                cout << "array is filled to capacity" << endl;
            else
                cout << val << " added" << endl;

        } else if (cmd == "r") {
            int indx;

            stringstream ss(arg);
            ss >> indx;

            int err = ja.remove(indx);

            if (-1 == err)
                cout << indx << " is an invalid index" << endl;
            else
                cout << "value at " << indx << " removed" << endl;
        } else if (cmd == "c") {
            cout << "array capacity is " << ja.capacity() << endl;
        } else if (cmd == "n") {
            cout << "array has " << ja.size() << " elements" << endl;
        } else if (cmd == "p") {
            cout << ja.describe() << endl;
        }

    }
}
