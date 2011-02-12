
#include "CommandParser.h"
#include "CinReader.h"
#include "Pet.h"

#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

class UI {
    string ps1;  // first level command prompt
    string ps2;  // second level command prompt

    CinReader *cinr;

    list<Pet*> pets;

public:
    /**
     * Create a new UI object.
     */
    UI();
    ~UI();

    /**
     * Run the main menu which creates an interface for the
     * user to interact with.
     */
    void go();

    /**
     *  Display a list of the children that are still alive.
     *  Each child is denoted by an integer and this integer
     *  can be used as a key to feedChild.
     *
     */
    void displayAlivePets();

    /**
     * Refresh the status of all the Pets.
     */
    void refreshPets();
};

