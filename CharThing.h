#pragma once

#include "DataThing.h"

#include <sstream>
#include <iostream>

using namespace std;

/**
 * CharThing implements the abstract interface of DataThing
 * for a "char" type.
 */
class CharThing : public DataThing
{
	private:
		char val;

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
		CharThing (char newBVal);

		/**
		 * Construct a CharThing object by using a string that
		 * describes the value.
		 *
		 * @arg string character
		 */
		CharThing(const string& newVal);


		~CharThing();

		/**
		 * Convert the CharThing object to a string format.
		 *
		 * @returns string
		 */
		string print() const;

		/**
		 * Set the char value.
		 *
		 * @arg char
		 */
		void setValue (char newBVal);

		/**
		 * Get the stored char value.
		 *
		 * @returns char
		 */
		char getValue() const;

		/**
		 * Assignment operator for assigning one CharThing to another.
		 *
		 * @arg CharThing
		 *
		 * @returns CharThing
		 */
		CharThing& operator=(const CharThing& s);

		/**
		 * CharThing output stream operator.
		 *
		 * @arg ostream
		 *
		 * @arg CharThing
		 *
		 * @returns ostream
		 */
		friend ostream& operator<<(ostream& out, const CharThing& s);

		/**
		 * Equivalence operator.
		 *
		 * @arg left hand side CharThing
		 *
		 * @arg right hand side CharThing
		 *
		 * @returns true if both values are the same, false otherwise.
		 */
		friend bool operator==(const CharThing& lhs, const CharThing& rhs);

		/**
		 * Less than operator.
		 *
		 * @arg left hand side CharThing
		 *
		 * @arg right hand side CharThing
		 *
		 * @returns true if left hand character is less than the right
		 */
		friend bool operator<(const CharThing& lhs, const CharThing& rhs);

		/**
		 * Less than or equal operator.
		 *
		 * @arg left hand side CharThing
		 *
		 * @arg right hand side CharThing
		 *
		 * @returns true if left hand is less than or equal to right, false otherwise.
		 */
		friend bool operator<=(const CharThing& lhs, const CharThing& rhs);

		/**
		 * Greater than operator.
		 *
		 * @arg left hand side CharThing
		 *
		 * @arg right hand side CharThing
		 *
		 * @returns true if left hand is greater than to right, false otherwise.
		 */
		friend bool operator>(const CharThing& lhs, const CharThing& rhs);

		/**
		 * Greater than or equal operator.
		 *
		 * @arg left hand side CharThing
		 *
		 * @arg right hand side CharThing
		 *
		 * @returns true if left hand is greater than or equal to right, false otherwise.
		 */
		friend bool operator>=(const CharThing& lhs, const CharThing& rhs);

		/**
		 * Not equal operator.
		 *
		 * @arg left hand side CharThing
		 *
		 * @arg right hand side CharThing
		 *
		 * @returns true if they are not equal, false otherwise
		 */
		friend bool operator!=(const CharThing& lhs, const CharThing& rhs);


};
