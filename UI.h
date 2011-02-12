
#include "CommandParser.h"
#include "CinReader.h"
#include "Pet.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class UI {
    string ps1;  // first level command prompt
    string ps2;  // second level command prompt

    CinReader *cinr;

    vector<Pet*> pets;

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
     *  Display the status of the current living pets.
     */
    void displayAlivePets();

    /**
     * Refresh the status of all the Pets.
     * If any of the pets have died the user is prompted to
     * name a new pet.
     */
    void refreshPets();
};

