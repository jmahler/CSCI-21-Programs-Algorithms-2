#pragma once

#include "DataThing.h"

#include <sstream>
#include <iostream>

using namespace std;

/**
 * DoubleThing implements the abstract interface of DataThing
 * for a "double" type.
 */
class DoubleThing : public DataThing
{
	private:
		double val;

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
		DoubleThing (double newVal);

		/**
		 * Construct a DoubleThing object by using a string that
		 * describes the value.
		 *
		 * @arg string value
		 */
		DoubleThing(const string& newVal);

		~DoubleThing();

		/**
		 * Convert the DoubleThing object to a string format.
		 *
		 * @returns string
		 */
		string print() const;

		/**
		 * Set the double value.
		 *
		 * @arg double
		 */
		void setValue (double newVal);

		/**
		 * Get the stored double value.
		 *
		 * @returns double
		 */
		double getValue() const;

		/**
		 * Assignment operator for assigning one DoubleThing to another.
		 *
		 * @arg DoubleThing
		 *
		 * @returns DoubleThing
		 */
		DoubleThing& operator=(const DoubleThing& s);

		/**
		 * DoubleThing output stream operator.
		 *
		 * @arg ostream
		 *
		 * @arg DoubleThing
		 *
		 * @returns ostream
		 */
		friend ostream& operator<<(ostream& out, const DoubleThing& s);

		/**
		 * Equivalence operator.
		 *
		 * @arg left hand side DoubleThing
		 *
		 * @arg right hand side DoubleThing
		 *
		 * @returns true if both values are the same, false otherwise.
		 */
		friend bool operator==(const DoubleThing& lhs, const DoubleThing& rhs);

		/**
		 * Less than operator.
		 *
		 * @arg left hand side DoubleThing
		 *
		 * @arg right hand side DoubleThing
		 *
		 * @returns true if left hand is less than the right
		 */
		friend bool operator<(const DoubleThing& lhs, const DoubleThing& rhs);

		/**
		 * Less than or equal operator.
		 *
		 * @arg left hand side DoubleThing
		 *
		 * @arg right hand side DoubleThing
		 *
		 * @returns true if left hand is less than or equal to right, false otherwise.
		 */
		friend bool operator<=(const DoubleThing& lhs, const DoubleThing& rhs);

		/**
		 * Greater than operator.
		 *
		 * @arg left hand side DoubleThing
		 *
		 * @arg right hand side DoubleThing
		 *
		 * @returns true if left hand is greater than to right, false otherwise.
		 */
		friend bool operator>(const DoubleThing& lhs, const DoubleThing& rhs);

		/**
		 * Greater than or equal operator.
		 *
		 * @arg left hand side DoubleThing
		 *
		 * @arg right hand side DoubleThing
		 *
		 * @returns true if left hand is greater than or equal to right, false otherwise.
		 */
		friend bool operator>=(const DoubleThing& lhs, const DoubleThing& rhs);

		/**
		 * Not equal operator.
		 *
		 * @arg left hand side DoubleThing
		 *
		 * @arg right hand side DoubleThing
		 *
		 * @returns true if they are not equal, false otherwise
		 */
		friend bool operator!=(const DoubleThing& lhs, const DoubleThing& rhs);


};
