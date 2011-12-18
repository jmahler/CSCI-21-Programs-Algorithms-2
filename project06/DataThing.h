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
template <class T>
class DataThing {
private:

	static int setid;

	int id;
	static bool print_id;  // whether to print the id number

protected:

	/**
	 * 'val' is available to child classes in order to
	 * store a value.
	 */
	T val;
	// val is protected so that 'Thing' object can set its value

public:

	/**
	 * Construct a DataThing object.
	 */
	DataThing() {
		id = setid++;
	}

	/**
	 * Copy constructor for a DataThing.
	 */
	DataThing(const DataThing& s) {
		id = s.id;
	}

	virtual ~DataThing() {};

	/**
	 * Get print id status (whether id should be printed or not).
	 *
	 * @returns bool
	 */
	static bool getPrintId() {
		return print_id;
	}

	/**
	 * Set print id status (whether id should be printed or not).
	 *
	 * @returns bool
	 */
	static void setPrintId(const bool newPrintId) {
		print_id = newPrintId;
	}

	/**
	 * Produce a string representation of the DataThing.
	 *
	 * @returns string
	 */
	//virtual string print() const = 0;
	virtual string print() const {
		stringstream ss;

		if (print_id) {
			ss << "id=" << id << ";";
		}

		ss << val;

		return ss.str();
	}

	/**
	 * Assignment operator for assigning one DataThing to another.
	 *
	 * @arg DataThing
	 *
	 * @returns DataThing
	 */
	DataThing<T>& operator=(const DataThing<T>& s) {
		id = s.id;
		val = s.val;
		return *this;
	}

	/**
	 * Set the id of the DataThing.
	 *
	 * @arg id
	 */
	void setId(const int newId) {
		id = newId;
	}

	/**
	 * Get the id of the DataThing.
	 *
	 * @arg DataThing
	 *
	 * @returns id
	 */
	int getId() const {
		return id;
	}

	/**
	 * Set the value.
	 *
	 * @arg T new value
	 */
	void setValue(const T newVal) {
		val = newVal;
	}

	/**
	 * Get the stored value.
	 *
	 * @return T
	 */
	T getValue() const {
		return val;
	}

	/**
	 * DataThing output stream operator.
	 *
	 * @arg ostream
	 *
	 * @arg DataThing
	 *
	 * @returns ostream
	 */
	friend ostream& operator<<(ostream& out, const DataThing<T>& s) {
		out << s.print();

		return out;
	}

	/**
	 * Equivalence operator.
	 *
	 * @arg left hand side DataThing
	 *
	 * @arg right hand side DataThing
	 *
	 * @returns true if id's are the same, false otherwise.
	 */
	friend bool operator==(const DataThing<T>& lhs, const DataThing<T>& rhs) {
		return (lhs.getValue() == rhs.getValue());
	}

	/**
	 * Less than operator.
	 *
	 * @arg left hand side DataThing
	 *
	 * @arg right hand side DataThing
	 *
	 * @returns true if right hand id is greater, false otherwise.
	 */
	friend bool operator<(const DataThing<T>& lhs, const DataThing<T>& rhs) {
		return (lhs.getValue() < rhs.getValue());
	}

	/**
	 * Greater than operator.
	 *
	 * @arg left hand side DataThing
	 *
	 * @arg right hand side DataThing
	 *
	 * @returns true if left hand id is greater, false otherwise.
	 */
	friend bool operator>(const DataThing<T>& lhs, const DataThing<T>& rhs) {
		return (rhs.getValue() < lhs.getValue());
	}

	/**
	 * Greater than or equal to operator.
	 *
	 * @arg left hand side DataThing
	 *
	 * @arg right hand side DataThing
	 *
	 * @returns true if left hand id is greater than or equal, false otherwise.
	 */
	friend bool operator>=(const DataThing<T>& lhs, const DataThing<T>& rhs) {
		return ((lhs > rhs) || (lhs == rhs));
	}

	/**
	 * Less than or equal to operator.
	 *
	 * @arg left hand side DataThing
	 *
	 * @arg right hand side DataThing
	 *
	 * @returns true if left hand id is less than or equal, false otherwise.
	 */
	friend bool operator<=(const DataThing<T>& lhs, const DataThing<T>& rhs) {
		return ((lhs < rhs) || (lhs == rhs));
	}

	/**
	 * Not equal to operator.
	 *
	 * @arg left hand side DataThing
	 *
	 * @arg right hand side DataThing
	 *
	 * @returns true if left is not equal to right, false otherwise.
	 */
	friend bool operator!=(const DataThing<T>& lhs, const DataThing<T>& rhs) {
		return !(lhs == rhs);
	}

};

template <class T>
int DataThing<T>::setid = 1;

/*
 * If you want the object id to be displayed
 * along with the value set print_id to true.
 */
template <class T>
bool DataThing<T>::print_id = false;


