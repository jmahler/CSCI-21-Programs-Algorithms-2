/**
 *
 * @mainpage
 *
 * This project provides a simple user interface for displaying
 * detailed information about integers and strings.
 *
 * Detailed application requirements are available
 * at [<a href="http://foobt.net/csci21/S3513_11/labs/lab1.html">csci21/S3513_11/labs/lab1</a>]
 * and duplicated with this source [lab1.html].
 *
 * This program was completed for "project 1" of the
 * class CSCI 21 taught by <a href="http://www.foobt.net">Boyd Trolinger</a>
 * at <a href="http://www.butte.edu">Butte College</a> during Spring 2011.
 *
 * @author  Jeremiah Mahler <jmmahler@gmail.com>
 */

#include <iostream>
#include <string>
#include <stdlib.h>

#include "CinReader.h"
#include "CommandParser.h"
#include "Integer.h"
#include "String.h"

/**
 *
 * The user interface for interrogating strings and integers.
 *
 * <h2>Synopsis</h2>
 *
 * @code
 *
 * #include "UI.h"
 *
 * ui UI();
 *
 * ui.mainMenu();  // go
 *
 * @endcode
 *
 * @author  Jeremiah Mahler <jmmahler@gmail.com>
 * @version 0.01
 *
 */
class UI
{
private:
    CinReader* cin;
    CommandParser* cp;
    string ps1;  // command prompt

public:
    /**
     * Construct an instance of the user interface.
     *
     */
    UI();
    ~UI();

    /**
     *
     * This method initiates the main menu which will interact
     * with the user.
     * Currently it can process integers (i) and strings (s)
     * and display useful information about them.
     *
     * @return when user chooses to quit
     *
     */
    void mainMenu();

private:
    /*
     *
     * This method initiates an interface (similar to mainMenu())
     * except that it is specific to an integer.
     *
     * This is only called by the mainMenu();
     */
    void submenuInt(int i);

    /*
     *
     * This method initiates an interface (similar to mainMenu())
     * except that it is specific to an string.
     *
     * This is only called by the mainMenu();
     */
    void submenuString(string s);

};

