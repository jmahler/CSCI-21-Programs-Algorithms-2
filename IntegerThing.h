#pragma once

#include "DataThing.h"

#include <sstream>
#include <iostream>

using namespace std;

/**
 * IntegerThing implements the abstract interface of DataThing
 * for a integer type.
 */
class IntegerThing : public DataThing
{
	private:
		int val;

	public:
		/**
		 * Construct a new IntegerThing object.
		 */
		IntegerThing();

		/**
		 * Construct a IntegerThing object and specify the new value.
		 *
		 * @arg int
		 */
		IntegerThing (const int newBVal);

		/**
		 * Construct a IntegerThing object by using a string that
		 * describes the value.
		 *
		 * @arg string of an integer value
		 */
		IntegerThing(const string& newVal);

		~IntegerThing();

		/**
		 * Convert the IntegerThing object to a string format.
		 *
		 * @returns string
		 */
		string print() const;

		/**
		 * Set the value.
		 *
		 * @arg int
		 */
		void setValue (int newBVal);

		/**
		 * Get the stored value.
		 *
		 * @returns int
		 */
		int getValue() const;

		/**
		 * Assignment operator for assigning one IntegerThing to another.
		 *
		 * @arg IntegerThing
		 *
		 * @returns IntegerThing
		 */
		IntegerThing& operator=(const IntegerThing& s);

		/**
		 * IntegerThing output stream operator.
		 *
		 * @arg ostream
		 *
		 * @arg IntegerThing
		 *
		 * @returns ostream
		 */
		friend ostream& operator<<(ostream& out, const IntegerThing& s);

		/**
		 * Equivalence operator.
		 *
		 * @arg left hand side IntegerThing
		 *
		 * @arg right hand side IntegerThing
		 *
		 * @returns true if both values are the same, false otherwise.
		 */
		friend bool operator==(const IntegerThing& lhs, const IntegerThing& rhs);

		/**
		 * Less than operator.
		 *
		 * @arg left hand side IntegerThing
		 *
		 * @arg right hand side IntegerThing
		 *
		 * @returns true if left hand is false and rhs is true, false otherwise.
		 */
		friend bool operator<(const IntegerThing& lhs, const IntegerThing& rhs);

		/**
		 * Less than or equal operator.
		 *
		 * @arg left hand side IntegerThing
		 *
		 * @arg right hand side IntegerThing
		 *
		 * @returns true if left hand is less than or equal to right, false otherwise.
		 */
		friend bool operator<=(const IntegerThing& lhs, const IntegerThing& rhs);

		/**
		 * Greater than operator.
		 *
		 * @arg left hand side IntegerThing
		 *
		 * @arg right hand side IntegerThing
		 *
		 * @returns true if left hand is greater than to right, false otherwise.
		 */
		friend bool operator>(const IntegerThing& lhs, const IntegerThing& rhs);

		/**
		 * Greater than or equal operator.
		 *
		 * @arg left hand side IntegerThing
		 *
		 * @arg right hand side IntegerThing
		 *
		 * @returns true if left hand is greater than or equal to right, false otherwise.
		 */
		friend bool operator>=(const IntegerThing& lhs, const IntegerThing& rhs);

		/**
		 * Not equal operator.
		 *
		 * @arg left hand side IntegerThing
		 *
		 * @arg right hand side IntegerThing
		 *
		 * @returns true if they are not equal, false otherwise
		 */
		friend bool operator!=(const IntegerThing& lhs, const IntegerThing& rhs);

};
