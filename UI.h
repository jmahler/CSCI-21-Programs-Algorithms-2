/**
 *
 * @mainpage
 *
 * This project is a simple game where you must feed the pets
 * before they starve.
 *
 * This program was completed for "project 2" of the
 * class CSCI 21 taught by <a href="http://www.foobt.net">Boyd Trolinger</a>
 * at <a href="http://www.butte.edu">Butte College</a> during Spring 2011.
 *
 * Detailed application requirements are available
 * at [<a href="http://foobt.net/csci21/S3513_11/labs/lab2.html">csci21/S3513_11/labs/lab2</a>]
 * and duplicated with this source [lab2.html].
 *
 * @author  Jeremiah Mahler <jmmahler@gmail.com>
 */

#include "CommandParser.h"
#include "CinReader.h"
#include "Pet.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/**
 * The UI class is used to creat the interface for interacting with the user.
 *
 * @author  Jeremiah Mahler <jmmahler@gmail.com>
 * @version 0.01
 */
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

