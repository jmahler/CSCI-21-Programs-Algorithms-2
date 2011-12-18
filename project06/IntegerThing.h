#pragma once

#include "DataThing.h"

/**
 * IntegerThing implements the abstract interface of DataThing
 * for a integer type.
 */
class IntegerThing : public DataThing<int>
{
private:

public:
	/**
	 * Construct a new IntegerThing object.
	 */
	IntegerThing();

	/**
	 * Construct a IntegerThing and initialize it with a new value.
	 *
	 * @arg int
	 */
	IntegerThing(const int newVal);

	/**
	 * Construct a IntegerThing object by using a string that
	 * describes the value.
	 *
	 * @arg string of an integer value
	 */
	IntegerThing(const string& newVal);

	~IntegerThing();

	/**
	 * Copy constructor for IntegerThing.
	 *
	 * @arg IntegerThing
	 */
	IntegerThing(const IntegerThing& s);

	/**
	 * Assignment operator for assigning one IntegerThing to another.
	 *
	 * @arg IntegerThing
	 *
	 * @returns IntegerThing
	 */
	IntegerThing& operator=(const IntegerThing& s);

};

