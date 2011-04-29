#pragma once

#include "DataThing.h"

#include <sstream>
#include <iostream>

using namespace std;

/**
 * BoolThing implements the abstract interface of DataThing
 * for a "bool" type.
 */
class BoolThing : public DataThing
{
	private:
		bool val;

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
		BoolThing (bool newBVal);

		/**
		 * Construct a BoolThing object by using a string that
		 * describes the value.
		 *
		 * @arg string "true" otherwise it is "false"
		 */
		BoolThing(const string& newVal);


		~BoolThing();

		/**
		 * Convert the BoolThing object to a string format.
		 *
		 * @returns string
		 */
		string print() const;

		/**
		 * Set the boolean value.
		 *
		 * @arg bool
		 */
		void setValue (bool newBVal);

		/**
		 * Get the stored boolean value.
		 *
		 * @returns bool
		 */
		bool getValue() const;

		/**
		 * Assignment operator for assigning one BoolThing to another.
		 *
		 * @arg BoolThing
		 *
		 * @returns BoolThing
		 */
		BoolThing& operator=(const BoolThing& s);

		/**
		 * BoolThing output stream operator.
		 *
		 * @arg ostream
		 *
		 * @arg BoolThing
		 *
		 * @returns ostream
		 */
		friend ostream& operator<<(ostream& out, const BoolThing& s);

		/**
		 * Equivalence operator.
		 *
		 * @arg left hand side BoolThing
		 *
		 * @arg right hand side BoolThing
		 *
		 * @returns true if both values are the same, false otherwise.
		 */
		friend bool operator==(const BoolThing& lhs, const BoolThing& rhs);

		/**
		 * Less than operator.
		 *
		 * @arg left hand side BoolThing
		 *
		 * @arg right hand side BoolThing
		 *
		 * @returns true if left hand is false and rhs is true, false otherwise.
		 */
		friend bool operator<(const BoolThing& lhs, const BoolThing& rhs);

		/**
		 * Less than or equal operator.
		 *
		 * @arg left hand side BoolThing
		 *
		 * @arg right hand side BoolThing
		 *
		 * @returns true if left hand is less than or equal to right, false otherwise.
		 */
		friend bool operator<=(const BoolThing& lhs, const BoolThing& rhs);

		/**
		 * Greater than operator.
		 *
		 * @arg left hand side BoolThing
		 *
		 * @arg right hand side BoolThing
		 *
		 * @returns true if left hand is greater than to right, false otherwise.
		 */
		friend bool operator>(const BoolThing& lhs, const BoolThing& rhs);

		/**
		 * Greater than or equal operator.
		 *
		 * @arg left hand side BoolThing
		 *
		 * @arg right hand side BoolThing
		 *
		 * @returns true if left hand is greater than or equal to right, false otherwise.
		 */
		friend bool operator>=(const BoolThing& lhs, const BoolThing& rhs);

		/**
		 * Not equal operator.
		 *
		 * @arg left hand side BoolThing
		 *
		 * @arg right hand side BoolThing
		 *
		 * @returns true if they are not equal, false otherwise
		 */
		friend bool operator!=(const BoolThing& lhs, const BoolThing& rhs);
};
