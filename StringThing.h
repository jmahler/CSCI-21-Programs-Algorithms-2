#pragma once

#include "DataThing.h"

using namespace std;

/**
 * StringThing implements the abstract interface of DataThing
 * for a "string" type.
 */
class StringThing : public DataThing<string>
{
private:

public:
	/**
	 * Construct a new StringThing object.
	 */
	StringThing();

	/**
	 * Construct a StringThing object by specifying the new value.
	 *
	 * @arg string
	 */
	StringThing(const string newVal);

	~StringThing();

	/**
	 * Copy constructor for StringThing.
	 *
	 * @arg StringThing
	 */
	StringThing(const StringThing& s);

	/**
	 * Assignment operator for assigning one StringThing to another.
	 *
	 * @arg StringThing
	 *
	 * @returns StringThing
	 */
	StringThing& operator=(const StringThing& s);

};
