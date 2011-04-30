#pragma once

#include "DataThing.h"

#include <sstream>
#include <iostream>

using namespace std;

/**
 * DoubleThing implements the abstract interface of DataThing
 * for a "double" type.
 */
class DoubleThing : public DataThing<double>
{
private:

public:
	/**
	 * Construct a new DoubleThing object.
	 */
	DoubleThing();

	/**
	 * Construct a DoubleThing object and specify the new value.
	 *
	 * @arg double
	 */
	DoubleThing(const double newVal);

	/**
	 * Construct a DoubleThing object by using a string that
	 * describes the value.
	 *
	 * @arg string value
	 */
	DoubleThing(const string& newVal);

	~DoubleThing();

	/**
	 * Copy constructor for DoubleThing.
	 *
	 * @arg DoubleThing
	 */
	DoubleThing(const DoubleThing& s);

	/**
	 * Assignment operator for assigning one DoubleThing to another.
	 *
	 * @arg DoubleThing
	 *
	 * @returns DoubleThing
	 */
	DoubleThing& operator=(const DoubleThing& s);

};

