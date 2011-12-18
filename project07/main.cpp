/**
 * @mainpage
 *
 * A Binary Search Tree structure and a utility to test it
 * using commands from a file.
 *
 * This program was completed for "project 7" of the
 * class CSCI 21 taught by <a href="http://www.foobt.net">Boyd Trolinger</a>
 * at <a href="http://www.butte.edu">Butte College</a> during Spring 2011.
 *
 * Detailed application requirements are available
 * at [<a href="http://foobt.net/csci21/S3513_11/labs/lab7.html">csci21/S3513_11/labs/lab7</a>]
 * and duplicated with this source [lab7.html].
 *
 * @author  Jeremiah Mahler <jmmahler@gmail.com>
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>


#include "BSTree.h"

using namespace std;


int main(int argc, char** argv)
{

    // {{{ help (-h) menu
    if (argc >= 2 && "-h" == string(argv[1])) {
        // help/usage
        cout << "USAGE:\n"
             << "  ./main -h                # this help screen\n"
             << "  ./main                   # reads \"input.txt\"\n"
             << "  ./main -                 # reads input from stdin\n"
             << "  ./main <file>            # reads input from <file>\n"
             << "\n"
             << "  # pipe commands from a file\n"
             << "    cat input.txt | ./main -\n"
             << "  # execute commands interactively\n"
             << "   ./main -\n"
             << "\n"
             << "COMMANDS:\n"
             << "  x                    # destroy the current object and\n"
             << "                       #   create a new one.\n"
             << "  n                    # get the node count\n"
             << "  i   <val>            # insert value\n"
             << "  r   <val>            # remove a value\n"
             << "  f   <val>            # find a value\n"
             << "  min                  # minium value\n"
             << "  max                  # maximum value\n"
             << "  p                    # print in sorted order\n"
             << "  pe                   # print in post-order\n"
             << "  pp                   # print in pre-order\n"
             << "  pr                   # print in reverse order\n"
             << "  c                    # clear all values\n"
             << "  -1                   # quit\n";

        exit(0);
    }
    // }}}

    // {{{ input stream setup
    string input_file = "input.txt"; // default
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

	// {{{ _main processing loop

	bool quit = false;
	while (! quit) {

		cout << "creating new object\n";
		BSTree<int> bst;

		string line;
		while (getline(from, line)) {

			string cmd;
			stringstream ss (line);
			ss >> cmd;

			// read in subsequent arguments by using
			// ss >> var;

			// See the help display for the command descriptions
			if ("-1" == cmd) {
				quit = true;
				break;
			} else if (cmd == "x") {
				// destroy old object and create a new one
				cout << "destroying old object...\n";
				break;
			} else if (cmd == "n") {
				cout << "node count is " << bst.getNodeCount() << endl;
			} else if (cmd == "i") {
				int val;

				ss >> val;

				bst.insert(val);

				cout << "inserted: " << val << endl;
			} else if (cmd == "r") {
				int val;

				ss >> val;
			
				bst.remove(val);

				cout << "removed: " << val << endl;
			} else if (cmd == "f") {
				int val;

				ss >> val;
			
				if (bst.find(val)) {
					cout << val << " found" << endl;
				} else {
					cout << val << " not found" << endl;
				}
			} else if (cmd == "min") {
				int val;
				try {
					val = bst.min();	
					cout << "minimum value is: " << val << "\n";
				} catch (EmptyTreeError) {
					cout << "minimum value of an empty list is undefined\n";
				}
			} else if (cmd == "max") {
				int val;
				try {
					val = bst.max();	
					cout << "maximum value is: " << val << "\n";
				} catch (EmptyTreeError) {
					cout << "maximum value of an empty list is undefined\n";
				}
			} else if (cmd == "p") {
				cout << "sorted-order:  " << bst.print() << endl;
			} else if (cmd == "pe") {
				cout << "post-order:    " << bst.printe() << endl;
			} else if (cmd == "pp") {
				cout << "pre-order:     " << bst.printp() << endl;
			} else if (cmd == "pr") {
				cout << "reverse-order: " << bst.printr() << endl;
			} else if (cmd == "c") {
				bst.clear();
				cout << "all values cleared" << endl;
			}
			// anything else is silently ignored
		}
	}
	// }}}

    _from.close();

	return 0;
}

