#pragma once

#include <ostream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

/**
 * The abstract class DataThing is a template for deriving
 * more specific data types.
 */
class DataThing {
	private:
		int id;
		static int setid;
		static bool print_id;  // whether to print the id number

	public:

		/**
		 * Construct a new DataThing and allocate a new id.
		 */
		DataThing();

		/**
		 * Copy constructor for a DataThing.
		 */
		DataThing(const DataThing& s);

		/**
		 * Construct a new DataThing by specifying the id.
		 */
		DataThing(const int& newid);

		/**
		 * Construct a new DataThing by giving a generic string which
		 * describes the value.
		 *
		 * @arg string value
		 */
		DataThing(const string& newval);

		virtual ~DataThing();

		/**
		 * Turn on displaying of the id number when the
		 * object is printed.
		 */
		void printIdOn();

		/**
		 * Turn on displaying of the id number when the
		 * object is printed.
		 */
		void printIdOff();

		/**
		 * Produce a string representation of the DataThing.
		 *
		 * @returns string
		 */
		virtual string print() const;
		//virtual string print() const = 0;

		/**
		 * Assignment operator for assigning one DataThing to another.
		 *
		 * @arg DataThing
		 *
		 * @returns DataThing
		 */
		DataThing& operator=(const DataThing& src);

		/**
		 * Get the id of the DataThing.
		 *
		 * @arg DataThing
		 *
		 * @returns id
		 */
		int getId() const;

		/**
		 * DataThing output stream operator.
		 *
		 * @arg ostream
		 *
		 * @arg DataThing
		 *
		 * @returns ostream
		 */
		friend ostream& operator<<(ostream& out, const DataThing& s);

		/**
		 * Equivalence operator.
		 *
		 * @arg left hand side DataThing
		 *
		 * @arg right hand side DataThing
		 *
		 * @returns true if id's are the same, false otherwise.
		 */
		friend bool operator==(const DataThing& lhs, const DataThing& rhs);

		/**
		 * Greater than operator.
		 *
		 * @arg left hand side DataThing
		 *
		 * @arg right hand side DataThing
		 *
		 * @returns true if left hand id is greater, false otherwise.
		 */
		friend bool operator>(const DataThing& lhs, const DataThing& rhs);

		/**
		 * Less than operator.
		 *
		 * @arg left hand side DataThing
		 *
		 * @arg right hand side DataThing
		 *
		 * @returns true if right hand id is greater, false otherwise.
		 */
		friend bool operator<(const DataThing& lhs, const DataThing& rhs);

		/**
		 * Greater than or equal to operator.
		 *
		 * @arg left hand side DataThing
		 *
		 * @arg right hand side DataThing
		 *
		 * @returns true if left hand id is greater than or equal, false otherwise.
		 */
		friend bool operator>=(const DataThing& lhs, const DataThing& rhs);

		/**
		 * Less than or equal to operator.
		 *
		 * @arg left hand side DataThing
		 *
		 * @arg right hand side DataThing
		 *
		 * @returns true if left hand id is less than or equal, false otherwise.
		 */
		friend bool operator<=(const DataThing& lhs, const DataThing& rhs);

		/**
		 * Not equal to operator.
		 *
		 * @arg left hand side DataThing
		 *
		 * @arg right hand side DataThing
		 *
		 * @returns true if left is not equal to right, false otherwise.
		 */
		friend bool operator!=(const DataThing& lhs, const DataThing& rhs);

};

