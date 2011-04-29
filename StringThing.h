#pragma once

#include "DataThing.h"

#include <sstream>
#include <iostream>

using namespace std;

/**
 * StringThing implements the abstract interface of DataThing
 * for a "string" type.
 */
class StringThing : public DataThing
{
	private:
		string val;

	public:
		/**
		 * Construct a new StringThing object.
		 */
		StringThing();

		/**
		 * Construct a StringThing object and specify the new value.
		 *
		 * @arg char
		 */
		StringThing(const string newVal);

		~StringThing();

		/**
		 * Convert the StringThing object to a string format.
		 *
		 * @returns string
		 */
		string print() const;

		/**
		 * Set the char value.
		 *
		 * @arg char
		 */
		void setValue (const string newVal);

		/**
		 * Get the stored char value.
		 *
		 * @returns char
		 */
		string getValue() const;

		/**
		 * Assignment operator for assigning one StringThing to another.
		 *
		 * @arg StringThing
		 *
		 * @returns StringThing
		 */
		StringThing& operator=(const StringThing& s);

		/**
		 * StringThing output stream operator.
		 *
		 * @arg ostream
		 *
		 * @arg StringThing
		 *
		 * @returns ostream
		 */
		friend ostream& operator<<(ostream& out, const StringThing& s);

		/**
		 * Equivalence operator.
		 *
		 * @arg left hand side StringThing
		 *
		 * @arg right hand side StringThing
		 *
		 * @returns true if both values are the same, false otherwise.
		 */
		friend bool operator==(const StringThing& lhs, const StringThing& rhs);

		/**
		 * Less than operator.
		 *
		 * @arg left hand side StringThing
		 *
		 * @arg right hand side StringThing
		 *
		 * @returns true if left hand character is less than the right
		 */
		friend bool operator<(const StringThing& lhs, const StringThing& rhs);

		/**
		 * Less than or equal operator.
		 *
		 * @arg left hand side StringThing
		 *
		 * @arg right hand side StringThing
		 *
		 * @returns true if left hand is less than or equal to right, false otherwise.
		 */
		friend bool operator<=(const StringThing& lhs, const StringThing& rhs);

		/**
		 * Greater than operator.
		 *
		 * @arg left hand side StringThing
		 *
		 * @arg right hand side StringThing
		 *
		 * @returns true if left hand is greater than to right, false otherwise.
		 */
		friend bool operator>(const StringThing& lhs, const StringThing& rhs);

		/**
		 * Greater than or equal operator.
		 *
		 * @arg left hand side StringThing
		 *
		 * @arg right hand side StringThing
		 *
		 * @returns true if left hand is greater than or equal to right, false otherwise.
		 */
		friend bool operator>=(const StringThing& lhs, const StringThing& rhs);

		/**
		 * Not equal operator.
		 *
		 * @arg left hand side StringThing
		 *
		 * @arg right hand side StringThing
		 *
		 * @returns true if they are not equal, false otherwise
		 */
		friend bool operator!=(const StringThing& lhs, const StringThing& rhs);

};
