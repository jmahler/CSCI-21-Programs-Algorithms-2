/**
 * @mainpage
 *
 * A simple dynamic array and a utility to test it using commands from a file.
 *
 * This program was completed for "project 4" of the
 * class CSCI 21 taught by <a href="http://www.foobt.net">Boyd Trolinger</a>
 * at <a href="http://www.butte.edu">Butte College</a> during Spring 2011.
 *
 * Detailed application requirements are available
 * at [<a href="http://foobt.net/csci21/S3513_11/labs/lab4.html">csci21/S3513_11/labs/lab4</a>, <a href="http://foobt.net/csci21/S3513_11/labs/lab3.html">csci21/S3513_11/labs/lab3</a>]
 * and duplicated with this source [lab3.html, lab4.html].
 *
 * @author  Jeremiah Mahler <jmmahler@gmail.com>
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>  // tolower()

#include "JArray.h"

using namespace std;

int main(int argc, char** argv)
{

    // {{{ help (-h) menu
    if (argc >= 2 && "-h" == string(argv[1])) {
        // help/usage
        cout << "USAGE:\n"
             << "  ./main -h                # this help screen\n"
             << "  ./main                   # reads \"lab4input.txt\"\n"
             << "  ./main -                 # reads input from stdin\n"
             << "  ./main <file>            # reads input from <file>\n"
             << "\n"
             << "  # pipe commands from a file\n"
             << "    cat lab4input.txt | ./main -\n"
             << "  # execute commands interactively\n"
             << "   ./main -\n"
             << "\n"
             << "COMMANDS:\n"
             << "  i  <val> <idx>      # replace value at index\n"
             << "  ii <val> <idx>      # insert value at index\n"
             << "  g  <idx>            # get value at index\n"
             << "  a  <val>            # append a value\n"
             << "  r  <idx>            # remove value at index\n"
             << "  c                   # get capacity\n"
             << "  n                   # get size\n"
             << "  p                   # describe the array\n"
             << "  s <type> <order>    # sort\n"
             << "    <type>  := B | I  # Bubble or Insert\n"
             << "    <order> := A | D  # Ascending or Descending\n"
             << "  -1                  # quit\n";

        exit(0);
    }
    // }}}

    // {{{ input stream setup
    string input_file = "lab4input.txt"; // default
    istream *pfrom;  // *pfrom is used to build &from at end

    if (argc == 2)
        input_file = argv[1];

    if (argc > 2) {
        cerr << "This program only takes 1 argument, see -h for usage.\n";
        exit(1);
    }

    ifstream _from(input_file.c_str());
    if (_from.fail()) {
        // The file they specified was invalid,
        // perhaps they meant stdin?
        if ("-" == input_file) {
            pfrom = &cin;
        } else {
            // Whatever they specified, it is incorrect.
            cerr << "Unable to open file named '" << input_file << "'.\n";
            cerr << "Does the file exist and do you have sufficient permissions?\n";
            exit(1);
        }
    } else {
        // assign the valid input file stream
        pfrom = &_from;
    }
    // the stream (from) is used for the rest of the program
    istream &from = (*pfrom);
    // }}}

    // process input ...

    // line #1: array capacity (an int value)
    int capacity;
    {
    string s;
    getline(from, s);
    stringstream ss(s);
    ss >> capacity;
    }
    
    // line #2: fixed size (0) or auto-resize (1)
    bool autosize;
    {
    string s;
    getline(from, s);
    stringstream ss(s);
    ss >> autosize;
    }

    JArray<int> ja(capacity, autosize);

    // all the rest of thie lines
    string line;
    while (getline(from, line)) {

        string cmd;
        stringstream ss (line);
        ss >> cmd;

        // read in subsequent arguments by using
        // ss >> var;

        if (cmd == "i") {
            // replace
            int val, idx, err;

            ss >> val;
            ss >> idx;
        
            err = ja.replace(val, idx);
            if (-1 == err)
                cout << idx << " is an invalid index" << endl;
            else
                cout << val << " inserted at index " << idx << endl;
        } else if (cmd == "ii") {
            // insert
            int val, idx, err;

            ss >> val;
            ss >> idx;
        
            err = ja.insert(val, idx);
            if (-1 == err)
                cout << idx << " is an invalid index" << endl;
            else
                cout << val << " inserted at index " << idx << endl;
        } else if (cmd == "g") {
            // get a value
            int val, idx;
            bool ok;

            ss >> idx;

            ok = ja.get(idx, val);
            if (ok)
                cout << "value at " << idx << ": " << val << endl;
            else
                cout << idx << " is an invalid index" << endl;
        } else if (cmd == "a") {
            // append a value
            int val;

            ss >> val;

            int err = ja.push(val);
            if (-1 == err)
                cout << "array is filled to capacity" << endl;
            else
                cout << val << " added" << endl;
        } else if (cmd == "r") {
            // remove a value
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
			// print
            cout << ja << endl;
        } else if (cmd == "s") {
			// sort

			string type;
			string order;
			bool asc_else_desc; // ascending else descending

            ss >> type;
            ss >> order;
			type[0] = tolower(type[0]);
			order[0] = tolower(order[0]);

			if (order[0] == 'd') {
				asc_else_desc = false;
			} else {
				asc_else_desc = true;
			}

			if (type[0] == 'b') {
				// bubble sort
            	cout << "bubble sorting in " << ((asc_else_desc) ? "ascending" : "descending") << " order" << endl;
				ja.bsort(asc_else_desc);
			} else if (type[0] == 'i') {
				// insertion sort
            	cout << "insertion sorting in " << ((asc_else_desc) ? "ascending" : "descending") << " order" << endl;
				ja.isort(asc_else_desc);
			} else {
            	cout << "unknown sort type '" << type << "'" << endl;
			}
        } else if (cmd == "-1") {
            exit(0); // quit
        }
        // anything else is silently ignored
    }

    _from.close();
}
