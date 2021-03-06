/**
 * @mainpage
 *
 * Doubly linked list operations and a utility to test it using commands from a file.
 *
 * This program was completed for "project 6" of the
 * class CSCI 21 taught by <a href="http://www.foobt.net">Boyd Trolinger</a>
 * at <a href="http://www.butte.edu">Butte College</a> during Spring 2011.
 *
 * Detailed application requirements are available
 * at [<a href="http://foobt.net/csci21/S3513_11/labs/lab6.html">csci21/S3513_11/labs/lab6</a>]
 * and duplicated with this source [lab6.html].
 *
 * @author  Jeremiah Mahler <jmmahler@gmail.com>
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

#include "DLList.h"

#include "DataThing.h"

#include "BoolThing.h"
#include "CharThing.h"
#include "DoubleThing.h"
#include "IntegerThing.h"
#include "StringThing.h"

using namespace std;

// {{{ (sub) _main processing loop
template <class T>
void _main(DLList<T> dl, istream& from) {
//void _main(DataThing dl, istream& from) {

    string line;
    while (getline(from, line)) {

        string cmd;
        stringstream ss (line);
        ss >> cmd;

        // read in subsequent arguments by using
        // ss >> var;

		// See the help display for the command descriptions
		if (cmd == "n") {
            cout << "node count is " << dl.getNodeCount() << endl;
        } else if (cmd == "puf") {
            string val;

            ss >> val;
        
			dl.pushFront(val);

			cout << "pushed " << val << " on to front of list" << endl;
        } else if (cmd == "pub") {
            string val;

            ss >> val;
        
			dl.pushBack(val);

			cout << "pushed " << val << " on to the back of list" << endl;
        } else if (cmd == "pof") {
			dl.popFront();
			cout << "popped one from the front of list" << endl;
        } else if (cmd == "pob") {
			dl.popBack();
			cout << "popped one from the back of list" << endl;
		} else if (cmd == "i") {
            string val;

            ss >> val;
        
			dl.insert(val);

			cout << "inserted: " << val << endl;
        } else if (cmd == "r") {
            string val;

            ss >> val;
        
			dl.remove(val, true);

			cout << "removed: " << val << endl;
        } else if (cmd == "rd") {
            string val;

            ss >> val;
        
			dl.remove(val, false);

			cout << val << "and its duplicates removed" << endl;
        } else if (cmd == "f") {
            string val;

            ss >> val;
        
			if (dl.find(val)) {
				cout << val << " found" << endl;
			} else {
				cout << val << " not found" << endl;
			}
        } else if (cmd == "fr") {
            string val;

            ss >> val;
        
			if (dl.findRecursive(val)) {
				cout << val << " found (recursive)" << endl;
			} else {
				cout << val << " not found (recursive)" << endl;
			}
        } else if (cmd == "d") {
            cout << dl << endl;
        } else if (cmd == "c") {
			dl.clear();
            cout << "all values cleared" << endl;
        } else if (cmd == "cr") {
			dl.clearRecursive();
            cout << "all values cleared (recursive)" << endl;
        } else if (cmd == "-1") {
            exit(0); // quit
        }
        // anything else is silently ignored
	}
}
// }}}

int main(int argc, char** argv)
{

    // {{{ help (-h) menu
    if (argc >= 2 && "-h" == string(argv[1])) {
        // help/usage
        cout << "USAGE:\n"
             << "  ./main -h                # this help screen\n"
             << "  ./main                   # reads \"input-int.txt\"\n"
             << "  ./main -                 # reads input from stdin\n"
             << "  ./main <file>            # reads input from <file>\n"
             << "\n"
             << "  # pipe commands from a file\n"
             << "    cat input.txt | ./main -\n"
             << "  # execute commands interactively\n"
             << "   ./main -\n"
             << "\n"
             << "COMMANDS:\n"
             << "  <type>  (FIRST LINE) # set type on first line of file\n"
             << "                       # integer, bool, char, double, string\n"
             << "  n                    # get the node count\n"
             << "  puf <val>            # push a value to the FRONT\n"
             << "  pub <val>            # push a value to the BACK\n"
             << "  pof                  # pop a value from the FRONT\n"
             << "  pob                  # pop a value from the BACK\n"
             << "  i   <val>            # insert value and keep sorted\n"
             << "  r   <val>            # remove a value\n"
             << "  rd  <val>            # remove a value and its duplicates\n"
             << "  f   <val>            # find a value\n"
             << "  fr  <val>            # find a value (recusive)\n"
             << "  d                    # display the array\n"
             << "  c                    # clear all values\n"
             << "  cr                   # clear all values (recursive)\n"
             << "  -1                   # quit\n";

        exit(0);
    }
    // }}}

    // {{{ input stream setup
    string input_file = "input-int.txt"; // default
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

    // line #1: data type
    string type;
    {
    string s;
    getline(from, s);
    stringstream ss(s);
    ss >> type;
    }

	// dispatch to the type specific main loop
	if (type == "int" || type == "integer") {
    	DLList<IntegerThing> dl;
		_main(dl, from);
	} else if (type == "bool") {
    	DLList<BoolThing> dl;
		_main(dl, from);
	} else if (type == "char") {
    	DLList<CharThing> dl;
		_main(dl, from);
	} else if (type == "double") {
    	DLList<DoubleThing> dl;
		_main(dl, from);
	} else if (type == "string") {
    	DLList<StringThing> dl;
		_main(dl, from);
	}

    _from.close();

	return 0;
}


