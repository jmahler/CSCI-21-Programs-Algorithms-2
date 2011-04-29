
#include "IntegerThing.h"

IntegerThing::IntegerThing()
{
	val = 0;  // default
}

IntegerThing::IntegerThing(const int newVal)
{
	val = newVal;
}

IntegerThing::IntegerThing(const string& strVal) {
	stringstream ss(strVal);
	int newVal;

	ss >> newVal;

	val = newVal;
}

IntegerThing::~IntegerThing() { }

string IntegerThing::print() const {
	stringstream ss;

	ss << DataThing::print();

	ss << val;

	return ss.str();
}

void IntegerThing::setValue(int newBVal) {
	val = newBVal;
}


int IntegerThing::getValue() const {
	return val;
}

IntegerThing& IntegerThing::operator=(const IntegerThing& s) {
	val = s.val;

	return *this;
}

ostream& operator<<(ostream& out, const IntegerThing& s) {
	out << s.print();

	return out;
}

bool operator==(const IntegerThing& lhs, const IntegerThing& rhs) {
	return (lhs.getValue() == rhs.getValue());
}

bool operator<(const IntegerThing& lhs, const IntegerThing& rhs) {
	return (lhs.getValue() < rhs.getValue());
}

bool operator<=(const IntegerThing& lhs, const IntegerThing& rhs) {
	return (lhs.getValue() <= rhs.getValue());
}

bool operator>(const IntegerThing& lhs, const IntegerThing& rhs) {
	return (rhs.getValue() < lhs.getValue());
}

bool operator>=(const IntegerThing& lhs, const IntegerThing& rhs) {
	return (rhs.getValue() <= lhs.getValue());
}

bool operator!=(const IntegerThing& lhs, const IntegerThing& rhs) {
	return (rhs.getValue() != lhs.getValue());
}

