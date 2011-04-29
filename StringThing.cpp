
#include "StringThing.h"

StringThing::StringThing()
{
	val = "";  // default
}

StringThing::StringThing(const string newVal)
{
	val = newVal;
}


StringThing::~StringThing() { }

string StringThing::print() const {
	stringstream ss;

	ss << DataThing::print();

	ss << val;

	return ss.str();
}

void StringThing::setValue(const string newVal) {
	val = newVal;
}


string StringThing::getValue() const {
	return val;
}

StringThing& StringThing::operator=(const StringThing& s) {
	val = s.val;

	return *this;
}

ostream& operator<<(ostream& out, const StringThing& s) {
	out << s.print();

	return out;
}

bool operator==(const StringThing& lhs, const StringThing& rhs) {
	return (lhs.getValue() == rhs.getValue());
}

bool operator<(const StringThing& lhs, const StringThing& rhs) {
	return (lhs.getValue() < rhs.getValue());
}

bool operator<=(const StringThing& lhs, const StringThing& rhs) {
	return (lhs.getValue() <= rhs.getValue());
}

bool operator>(const StringThing& lhs, const StringThing& rhs) {
	return (rhs.getValue() < lhs.getValue());
}

bool operator>=(const StringThing& lhs, const StringThing& rhs) {
	return (rhs.getValue() <= lhs.getValue());
}

bool operator!=(const StringThing& lhs, const StringThing& rhs) {
	return (rhs.getValue() != lhs.getValue());
}

