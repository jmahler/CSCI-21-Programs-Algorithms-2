#pragma once

#include "DataThing.h"

/**
 * CharThing implements the abstract interface of DataThing
 * for a "char" type.
 */
class CharThing : public DataThing<char>
{
private:

public:
	/**
	 * Construct a new CharThing object.
	 */
	CharThing();

	/**
	 * Construct a CharThing object and specify the new value.
	 *
	 * @arg char
	 */
	CharThing (const char newVal);

	/**
	 * Construct a CharThing object by using a string that
	 * describes the value.
	 *
	 * @arg string character
	 */
	CharThing(const string& newVal);

	~CharThing();

	/**
	 * Copy constructor for CharThing.
	 *
	 * @arg CharThing
	 */
	CharThing(const CharThing& s);

	/**
	 * Assignment operator for assigning one CharThing to another.
	 *
	 * @arg CharThing
	 *
	 * @returns CharThing
	 */
	CharThing& operator=(const CharThing& s);

};

