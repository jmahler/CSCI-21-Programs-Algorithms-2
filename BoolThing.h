#pragma once

#include "DataThing.h"

#include <sstream>

using namespace std;

/**
 * BoolThing implements the abstract interface of DataThing
 * for a "bool" type.
 */
class BoolThing : public DataThing<bool>
{
private:

public:
	/**
	 * Construct a new BoolThing object.
	 */
	BoolThing();

	/**
	 * Construct a BoolThing object and specify the new value.
	 *
	 * @arg bool
	 */
	BoolThing (bool newVal);

	/**
	 * Construct a BoolThing object by using a string that
	 * describes the value.
	 *
	 * @arg string "true" means true otherwise it is false
	 */
	BoolThing(const string& newVal);

	~BoolThing();

	/**
	 * Copy constructor for BoolThing.
	 *
	 * @arg BoolThing
	 */
	BoolThing(const BoolThing& s);

	/**
	 * Assignment operator for assigning one BoolThing to another.
	 *
	 * @arg BoolThing
	 *
	 * @returns BoolThing
	 */
	BoolThing& operator=(const BoolThing& s);

	/**
	 * Convert BoolThing to a string representation.
	 *
	 * @returns string
	 *
	 * This operation overloads the inherited DataThing:print
	 * in order to output true/false as the string "true"/"false"
	 * instead of the value 1/0.
	 */
	string print() const;
};

