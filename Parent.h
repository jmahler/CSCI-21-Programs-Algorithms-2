
#include "BirthRecords.h"
#include "CommandParser.h"

#include <errno.h>  // perror
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h> // exit
#include <map>
#include <sys/types.h> // kill()
#include <signal.h>

using namespace std;

class Parent {
    string ps1;  // first level command prompt
    string ps2;  // second level command prompt

    BirthRecords birth_records;

    /*
     * List of the last number to pid mappings
     * displayed by displayAliveChildren().
     */
    map<int, int> last_n_pids;

    void spawn(string name="John Doe");
public:
    /**
     * Create a new Parent object.
     */
    Parent();

    /**
     * Run the main menu which creates an interface for the
     * user to interact with.
     *
     */
    void mainMenu();

    /**
     * Get the BirthRecords object which is a log of the
     * children that have been born and/or died.
     * See BirthRecords() for how to use this object.
     *
     */
    BirthRecords* getBirthRecords() { return &birth_records; };

    /**
     *  Display a list of the children that are still alive.
     *  Each child is denoted by an integer and this integer
     *  can be used as a key to feedChild.
     *
     */
    void displayAliveChildren();

    /**
     * Displays a summary of births, deaths, etc.
     *
     */
    void displayEndSummary();
};

