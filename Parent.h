
#include "BirthRecords.h"
#include "CommandParser.h"

#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <errno.h>  // perror
#include <stdlib.h> // exit

using namespace std;

class Parent {
    string ps1; // prompt
    string ps2; // prompt
    BirthRecords birth_records;

public:
    Parent();

    void mainMenu();

    void spawn(string name="John Doe");

    BirthRecords* getBirthRecords() { return &birth_records; };
};

